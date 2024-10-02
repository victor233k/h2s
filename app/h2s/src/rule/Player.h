#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>

#include "src/rule/Card.h"

struct PlayerInfo {
    QString uuid;
    QString tagPlay;//how to play card//use list?
    QString tagDescribe;//appearance, Character relationships//use list?
    QString name;//nickname
    QString rname;//real name

    //Current table
    int index;
    int chip;//{4000}
    QVector<int> buyin;//eg: {1,1,2,4}


    //Current hand
    QString position;//sb bb utg utg+1 ... co btn
    QVector<Card*> hand;//TODO:just 2 long

    //data
//    double vpip;//Temporary calculation something // 20% or 20.2
    //....

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
