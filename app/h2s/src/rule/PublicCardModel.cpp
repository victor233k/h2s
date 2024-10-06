#include "PublicCardModel.h"

PublicCardModel::PublicCardModel(QObject *parent) : QAbstractListModel (parent)
{
    initFackData();
}

//void PublicCardModel::onPublicCardClicked(int pubIndex)
//{
//    pubCardChoice
//}

int PublicCardModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return m_list.count();
}

QVariant PublicCardModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) {
        return QVariant();
    }

    if(index.row() >= m_list.count()) {
        return QVariant();
    }

    PublicCard info = m_list.at(index.row());
    switch (role) {
    case cardId:
        return info.cardId;
        break;
    case flip:
        return info.flip;
        break;
    case image:
        return info.image;
        break;
    default:
        return QVariant();
        break;
    }
}

bool PublicCardModel::setData(const QModelIndex &index, const QVariant &value, int role)
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

QHash<int, QByteArray> PublicCardModel::roleNames() const
{
    QHash<int, QByteArray> r =QAbstractListModel::roleNames();
    r[cardId]="cardId";
    r[flip]="flip";
    r[image]="image";
    return r;
}

void PublicCardModel::onCardChosen(int index, int caller)
{
//    PublicCard& card = m_list[caller];
    m_list[caller].cardId = index;
    m_list[caller].flip = true;
    m_list[caller].image = QUrl(Card::getCardImageById(m_list[caller].cardId));
    emit dataChanged(createIndex(caller, 0), createIndex(caller, 0));
}

void PublicCardModel::onBackClicked(int caller)
{
    m_list[caller].cardId = -1;
    m_list[caller].flip = false;
    m_list[caller].image = QUrl(Card::getCardImageById(m_list[caller].cardId));
    emit dataChanged(createIndex(caller, 0), createIndex(caller, 0));

}

void PublicCardModel::onCancelClicked(int caller)
{
    m_list[caller].cardId = -1;
    m_list[caller].flip = false;
    m_list[caller].image = QUrl(Card::getCardImageById(m_list[caller].cardId));
    emit dataChanged(createIndex(caller, 0), createIndex(caller, 0));
}

void PublicCardModel::initFackData()
{
    for(int i = 0; i < 5; i++)
    {
        PublicCard card;
        card.cardId = i;
        card.image = QUrl(QString("qrc:/c120/back.png"));
        card.flip = false;
        m_list.append(card);
    }
//    emit dataChanged()
//    beginResetModel();
//    endResetModel();
}
