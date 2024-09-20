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


    static QVector<Card*> findBestHand(const QVector<Card*>& list, QVector<Card*> &outlist);

    static bool isStraightFlush(const QVector<Card*>& list, QVector<Card*> &outlist);
    static bool isFourOfAKind(const QVector<Card*>& list, QVector<Card*> &outlist);
    static bool isFullHouse(const QVector<Card*>& list, QVector<Card*> &outlist);
    static bool isFlush(const QVector<Card*>& list, QVector<Card*> &outlist);
    static bool isStraight(const QVector<Card*>& list, QVector<Card*> &outlist);
    static bool isThreeOfAKind(const QVector<Card*>& list, QVector<Card*> &outlist);
    static bool isTwoPairs(const QVector<Card*>& list, QVector<Card*> &outlist);
    static bool isOnePair(const QVector<Card*>& list, QVector<Card*> &outlist);

    static void shortCardList(QVector<Card*>& list);

    static QString printList(const QVector<Card*>& list, QString str = "");

private:
    QVector<Card*> *m_list = nullptr;
    QVector<int> m_randomList;

    void initCardList();
    void clearCardList();

    void initRandomList();

signals:

};

#endif // POKER_H
