#include "Test.h"

#include <QDebug>

#include "src/rule/Poker.h"



Test::Test(QObject *parent) : QObject(parent)
{
//    testDealCard();
    testIsStraightFlush();
//    testFindBestHand();
}

void Test::testDealCard()
{
    Poker cards;
    cards.shuffleCards();

    auto list = cards.dealCard(7);

    qInfo() << cards.printList(list, "test dealCard : ");
}

void Test::testFindBestHand()
{
    Poker cards;
    cards.shuffleCards();

    auto list = cards.dealCard(7);
    QVector<Card*> bestHand;
    cards.findBestHand(list, bestHand);

    qInfo() << cards.printList(bestHand, "test best hand is : ");
}

void Test::testIsStraightFlush()
{
    Poker cards;

    QVector<Card*> sfList, outlist;
    Card c0(0),c1(1),c2(2),c3(3),c4(4),c5(5),c6(6),c7(7),c8(8),c12(12);
    Card d2("DJ"),d3("D3"),d4("DT"),d5("D5"),s2("DK"),da("DA"),h3("DQ");
    sfList.append(&d2);
    sfList.append(&d3);
    sfList.append(&d4);
    sfList.append(&d5);
    sfList.append(&s2);
    sfList.append(&da);
    sfList.append(&h3);

    qInfo() << " ";
    qInfo() << "test  StraightFlush" << cards.printList(sfList);
    if(cards.isStraightFlush(sfList,outlist))
    {
        qInfo() << cards.printList(sfList);
        qInfo() << "StraightFlush : " << cards.printList(outlist);
    }
    qInfo() << " ";

    outlist.clear();
    sfList.clear();

    sfList.append(&c0);
    sfList.append(&c1);
    sfList.append(&c2);
    sfList.append(&c3);
    sfList.append(&c5);
    sfList.append(&c6);
    sfList.append(&c12);

    qInfo() << " ";
    qInfo() << "test StraightFlush 54321" << cards.printList(sfList);
    if(cards.isStraightFlush(sfList,outlist))
    {
        qInfo() << cards.printList(sfList);
        qInfo() << "StraightFlush : " << cards.printList(outlist);
    }
    qInfo() << " ";
}
