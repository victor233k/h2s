#ifndef POKER_H
#define POKER_H

#include <QObject>
#include "src/rule/Card.h"
#include "src/rule/Definitions.h"


class Poker : public QObject
{
    Q_OBJECT
public:
    explicit Poker(QObject *parent = nullptr);
    ~Poker();

    void shuffleCards();
    QVector<Card > dealCard(int num);

    static int findBestHand(const QString& list, QString &outlist);
    static int findBestHand(const QVector<Card >& list, QVector<Card > &outlist);

    static bool isStraightFlush(const QVector<Card >& list, QVector<Card > &outlist);
    static bool isFourOfAKind(const QVector<Card >& list, QVector<Card > &outlist);
    static bool isFullHouse(const QVector<Card >& list, QVector<Card > &outlist);
    static bool isFlush(const QVector<Card >& list, QVector<Card > &outlist);
    static bool isStraight(const QVector<Card >& list, QVector<Card > &outlist);
    static bool isThreeOfAKind(const QVector<Card >& list, QVector<Card > &outlist);
    static bool isTwoPairs(const QVector<Card >& list, QVector<Card > &outlist);
    static bool isOnePair(const QVector<Card >& list, QVector<Card > &outlist);

    static int calculateHandScore(int shapeValue, const QVector<Card > &hand);
    static void sortCardList(QVector<Card >& list);

    //
    static int compareHands(QVector<Card > &hand1,QVector<Card > &hand2, QVector<Card > &pubList);//[0=] [1>] [2<]

    static QString printList(const QVector<Card >& list, QString str = "");

private:
    QVector<Card > *m_list = nullptr;
    QVector<int> m_randomList;

    void initCardList();
    void clearCardList();

    void initRandomList();

signals:

};

#endif // POKER_H
