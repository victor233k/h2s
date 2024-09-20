#ifndef TEST_H
#define TEST_H

#include <QObject>
#include "src/rule/Poker.h"

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);
    ~Test();

    void testDealCard();
    void testFindBestHand();

    void testIsStraightFlush();
    void testIsFourOfAKind();
    void testIsFullHouse();



private:
    QVector<Card*> *m_list = nullptr;

    void initCardList();
    void clearCardList();


    QVector<Card*> getCustomList(QString val);
    QVector<Card*> getStraightFlushList();
    QVector<Card*> getFourOfAKindList();
    QVector<Card*> getFullHouseList();
    QVector<Card*> getFlushList();
    QVector<Card*> getStraightList();
    QVector<Card*> getThreeOfAKindList();
    QVector<Card*> getTwoPairsList();
    QVector<Card*> getOnePairList();
signals:

};

#endif // TEST_H
