#include "Test.h"

#include <QDebug>

#include "src/rule/Poker.h"

Test::Test(QObject *parent) : QObject(parent)
{
    testDealCard();
}

void Test::testDealCard()
{
    Poker cards;
    cards.shuffleCards();

    auto list = cards.dealCard(7);
    QString str;
    for(int i = 0; i < list.size(); i++)
    {
        str.append(list.at(i)->getCardString()).append(" ");
    }
    qInfo() <<"test deal card :" << str;
}
