#include "bizcommand.h"

#include <QDebug>

#include "src/rule/PokerCards.h"
#include "src/rule/Rule.h"
//#include "src/rule/PokerCard.h"
class PokerCard;

BIZCommand::BIZCommand(QObject *parent) : QObject(parent)
{
    qInfo() << "BIZCommand init";
//    Rule rule;
    PokerCards cards;
    cards.shuffleCards();


}
