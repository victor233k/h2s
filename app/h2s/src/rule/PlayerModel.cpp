#include "PlayerModel.h"

PlayerModel::PlayerModel(QObject *parent) : QAbstractListModel (parent)
{
    initFackData();
}

PlayerModel::~PlayerModel()
{
    clearList();
}

int PlayerModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_list.count();
}

QVariant PlayerModel::data(const QModelIndex &index, int role) const
{
    //    int test = index.row();
        if (!index.isValid()) {
            return QVariant();
        }

        if(index.row() >= m_list.count()) {
            return QVariant();
        }

        PlayerInfo info = m_list.at(index.row())->info;
        switch (role) {
        case uuid:
            return info.uuid;
            break;

        case tagPlay:
            return info.tagPlay;
            break;

        case tagDescribe:
            return info.tagDescribe;
            break;

        case name:
            return info.name;
            break;

        case rname:
            return info.rname;
            break;
        case tableIndex:
            return info.tableIndex;
            break;

        case chip:
            return info.chip;
            break;
        case buyinSum:
            return info.buyinSum;
            break;
        case position:
            return info.position;
            break;

        case hand1:
            if(info.handList.size() >= 1)
            {
                return -1;
            } else {
                return info.handList[0].getId();
            }
            break;
        case hand2:
            if(info.handList.size() >= 2)
            {
                return -1;
            } else {
                return info.handList[1].getId();
            }

            break;
//        case currentBestHand:
//            return info.currentBestHand;
//            break;
        default:
            return QVariant();
            break;
        }
}

bool PlayerModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (index.row() < 0 || index.row() >= rowCount()) {
        return false;
    }

    QMap<int, QVariant> map;
    map.insert(role,value);

    bool ok = setItemData(index, map);
    if (ok) {
        emit dataChanged(index, index, QVector<int>() << role);
    }
    return true;
}

QHash<int, QByteArray> PlayerModel::roleNames() const
{
    QHash<int, QByteArray> r =QAbstractListModel::roleNames();
    r[uuid]="uuid";
    r[name]="name";

    return r;
}

void PlayerModel::clearList()
{
    if(!m_list.empty())
    {
        for(Player * item: m_list)
        {
            delete item;
        }
        m_list.clear();
    }
}

void PlayerModel::removePlayer(int index)
{
    if(!m_list.empty())
    {
        if(index < m_list.size())
        {
            Player* p = m_list[index];
            delete p;
            m_list.removeAt(index);
        } else {
            qWarning() << "index out of m_list";
        }
    }
}

void PlayerModel::insertPlayer(int index, Player *player)
{
    m_list.insert(index, player);//out list auto insert end
}

void PlayerModel::swapPlayer(int s1, int s2)
{
    m_list.swapItemsAt(s1,s2);
}

void PlayerModel::movePlayer(int m1, int m2)
{
    m_list.move(m1, m2);
}

void PlayerModel::initFackData()
{
    for(int i = 0; i < 9; i++)
    {
        Player * player = new Player;
        player->info.name = QString("player ").append(QString::number(i));
        insertPlayer(i, player);
    }
}
