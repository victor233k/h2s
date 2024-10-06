#ifndef DEFINITIONS_H
#define DEFINITIONS_H


#include <QObject>
/**************
 * 梅花（Clubs）    C
 * 方块（Diamonds)  D
 * 红心（Hearts）   H
 * 黑桃（Spades）   S
 **************/

//1. 能获取花色(suit
//2. 能获取牌值(rank

#define SUIT "CDHS"
#define RANK "023456789TJQKA"
#define CARD_MAX_NUM 52

typedef enum {
    ShapeValue_MIN = 0,

    NoPair,//1
    OnePair,//2
    TwoPairs ,//3
    Threeofakind ,//4
    Straight ,//5
    Flush ,//6
    Fullhouse ,//7
    FourofaKind ,//8
    StraightFlush,//9

    ShapeValue_MAX
} ShapeValue;

typedef enum {
    CARD2 = 1,
    CARD3,
    CARD4,
    CARD5,
    CARD6,
    CARD7,
    CARD8,
    CARD9,
    CARDT,
    CARDJ,
    CARDQ,
    CARDK,
    CARDA
} CardValue;

typedef enum {
    Equal,
    Greater,
    Less
} Operator;

#endif // DEFINITIONS_H
