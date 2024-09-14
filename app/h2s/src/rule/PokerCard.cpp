#include "PokerCard.h"

//PokerCard::PokerCard(int index, CardValue value, Suit suit, QString name, QString image)
//{

//}

PokerCard::PokerCard(int index, CardValue value, Suit suit):
    m_index(index),m_value(value),m_suit(suit)
{

}

int PokerCard::getIndex()
{
    return m_index;
}

Suit PokerCard::getSuit()
{
    return m_suit;
}

CardValue PokerCard::getValue()
{
    return m_value;
}


