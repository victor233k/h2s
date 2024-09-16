#include "Card.h"

Card::Card(int id):
    id(id)
{
    QString strRank = getRank();
    rankValue = getRankValue(strRank);
}

int Card::getId()
{
    return id;
}

QString Card::getSuit()
{
    QString card = getCardString();
    return card.at(0);
}

QString Card::getRank()
{
    QString card = getCardString();
    return card.at(1);
}

int Card::getRankValue()
{
    return rankValue;
}

QString Card::getCardString()
{
    return getCardStringById(getId());
}
