#ifndef POKER_H
#define POKER_H

#include <QObject>
#include "src/rule/Card.h"

typedef enum {
    ShapeValue_MIN = 0,

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

class Poker : public QObject
{
    Q_OBJECT
public:
    explicit Poker(QObject *parent = nullptr);
    ~Poker();

    void shuffleCards();
    QVector<Card*> dealCard(int num);

    QVector<Card*> findBestHand(const QVector<Card*>& list, QVector<Card*> &outlist);

    bool isStraightFlush(const QVector<Card*>& list, QVector<Card*> &outlist);

    bool isFourOfAKind();
    bool isFullHouse();
    bool isFlush();
    bool isStraight(const QVector<Card*>& list, QVector<Card*> &outlist);
    bool isThreeOfAKind();
    bool isTwoPairs();
    bool isOnePair();


    QString printList(const QVector<Card*>& list, QString str = "print card list : ");

private:
    QVector<Card*> *m_list = nullptr;
    QVector<int> m_randomList;

    void initCardList();
    void clearCardList();

    void initRandomList();

signals:

};

#endif // POKER_H
