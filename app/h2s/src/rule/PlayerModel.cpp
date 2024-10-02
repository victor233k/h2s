#include "PlayerModel.h"

PlayerModel::PlayerModel(QObject *parent) : QAbstractListModel (parent)
{

}

int PlayerModel::rowCount(const QModelIndex &parent) const
{

}

QVariant PlayerModel::data(const QModelIndex &index, int role) const
{

}

bool PlayerModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}

QHash<int, QByteArray> PlayerModel::roleNames() const
{

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
