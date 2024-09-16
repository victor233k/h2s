#include "bizcommand.h"

#include <QDebug>

#include "src/rule/Poker.h"

BIZCommand::BIZCommand(QObject *parent) : QObject(parent)
{
    qInfo() << "BIZCommand init";

    Poker cards;
    cards.shuffleCards();

    auto list = cards.dealCard(7);

    for(int i = 0; i < list.size(); i++)
    {
        qInfo() << i << "--"  << list.at(i)->getCardString();
    }

}
