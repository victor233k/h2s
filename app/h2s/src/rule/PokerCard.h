#ifndef POKERCARD_H
#define POKERCARD_H

#include <QObject>

//#include "src/rule/Rule.h"

typedef enum {
    Suit_MIN = 1,

    SPADES,
    HEARTS,
    DIAMONDS,
    CLUBS,

    Suit_MAX
} Suit;

typedef enum {
    CardValue_MIN = 1,

    C2,
    C3,
    C4,
    C5,
    C6,
    C7,
    C8,
    C9,
    C10,
    CJ,
    CQ,
    CK,
    CA,

    CardValue_MAX
} CardValue;

class PokerCard
{
public:
//    PokerCard(int index, CardValue value, Suit suit, QString name, QString image);
    PokerCard(int index, CardValue value, Suit suit);

    int getIndex();
    Suit getSuit();
    CardValue getValue();

    QString getName();
    void setName(QString val);
    QString getImage();
    void setImage(QString val);

    bool getIsInCards();
    void setIsInCards(bool val);

    //多种不同值的转换
//    static CardValue getValueByString(QString val);
//    static Suit getSuitByString(QString val);
private:
    int m_index;
    CardValue m_value;
    Suit m_suit;

    QString m_name;
    QString m_image;
    bool isInCards = true;//是否在池里
};

#endif // POKERCARD_H
