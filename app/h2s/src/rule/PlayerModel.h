#ifndef PLAYERS_H
#define PLAYERS_H

#include <QObject>
#include <QAbstractListModel>

#include "src/rule/Player.h"


class PlayerModel : public QAbstractListModel
{
    Q_OBJECT
public:
    explicit PlayerModel(QObject *parent = nullptr);

public:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role);
    QHash<int, QByteArray> roleNames() const;


    void clearList();
    void removePlayer(int index);
    void insertPlayer(int index, Player* player);
    void swapPlayer(int s1, int s2);
    void movePlayer(int m1, int m2);
private:

    QList<Player*> m_list;

signals:

};

#endif // PLAYERS_H
