#ifndef PUBLICCARDMODEL_H
#define PUBLICCARDMODEL_H

#include <QObject>
#include <QAbstractListModel>
#include <QUrl>

#include "src/rule/Card.h"

struct PublicCard {
    int cardId = -1;//id为-1 说明牌还没发出来
    bool flip = false;
    QUrl image;
};

enum PublicCardRoles {
    cardId = Qt::UserRole + 1,
    flip,
    image
};

class PublicCardModel : public QAbstractListModel
{
    Q_OBJECT
    Q_ENUMS(PublicCardRoles)
public:
    explicit PublicCardModel(QObject *parent = nullptr);


public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QHash<int, QByteArray> roleNames() const;

public:
    //public card
//    Q_INVOKABLE void onPublicCardClicked(int pubIndex);

    //all card
    Q_INVOKABLE void onCardChosen(int index, int caller);
    Q_INVOKABLE void onBackClicked(int caller);
    Q_INVOKABLE void onCancelClicked(int caller);

private:
    QVector<PublicCard> m_list;

    void initFackData();

signals:

    void pubCardChoice(int pubIndex);
};

#endif // PUBLICCARDMODEL_H
