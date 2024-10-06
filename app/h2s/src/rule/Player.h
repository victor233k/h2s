#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

#include "src/rule/Card.h"
#include "src/rule/Definitions.h"

struct PlayerInfo {
    QString uuid;
    QString tagPlay;//how to play card//use list?
    QString tagDescribe;//appearance, Character relationships//use list?
    QString name;//nickname
    QString rname;//real name

    //Current table
    int tableIndex;
    int chip;//{4000}
    QVector<int> buyin;//eg: {1,1,2,4}
    int buyinSum;


    //Current hand
    QString position;//sb bb utg utg+1 ... co btn
    QVector<Card> handList;
    QVector<Card> currentBestHand;
    //data
//    double vpip;//Temporary calculation something // 20% or 20.2
    //....

};

enum PlayerRoles {
    uuid = Qt::UserRole + 1,
    tagPlay,
    tagDescribe,
    name,
    rname,
    tableIndex,
    chip,
    buyin,
    buyinSum,
    position,
    hand1,
    hand2,
    currentBestHand
};

class Player : public QObject
{
    Q_OBJECT
public:
    explicit Player(QObject *parent = nullptr);


    PlayerInfo info;
private:

signals:

};

#endif // PLAYER_H
