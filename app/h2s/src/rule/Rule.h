#ifndef RULE_H
#define RULE_H

#include <QObject>
#include <QList>


#include "src/rule/PokerCard.h"
#include "src/rule/PokerCards.h"

/************
//黑桃（Spades）   S
//红心（Hearts）   H
//方块（Diamonds)  D
//梅花（Clubs）    C
*/



typedef enum {
    ShapeValue_MIN = 1,

    NoPair,
    TwoPairs ,
    Threeofakind ,
    Straight ,
    Flush ,
    Fullhouse ,
    FourofaKind ,
    StraightFlush,

    ShapeValue_MAX
} ShapeValue;


//可接受的类型

//struct Card {
//    CardValue cardValue;
//    Suit cardSuit;
//};

struct Hands{

};

class Rule : public QObject
{
    Q_OBJECT
public:
    explicit Rule(QObject *parent = nullptr);


//    void getBigest(QList<PokerCard*> &list);

//    void sort(QList<PokerCard*> &list);

//    bool checkStraightFlush(QList<PokerCard*> &list);
//    bool checkFourofaKind(QList<Card> &list);
//    bool checkFullhouse(QList<Card> &list);
//    bool checkFlush(QList<Card> &list);
//    bool checkStraight(QList<Card> &list);
//    bool checkThreeofakind(QList<Card> &list);
//    bool checkTwoPairs(QList<Card> &list);

signals:

};

#endif // RULE_H
