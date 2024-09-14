#include "PokerCards.h"

#include <QDebug>
#include <QRandomGenerator>
#include <algorithm> // 包含 std::shuffle
#include <iostream>

PokerCards::PokerCards(QObject *parent) : QObject(parent)
{
    initRandomList();
    initCardList();
}

PokerCards::~PokerCards()
{
    clearCardList();
}

void PokerCards::initCardList()
{
    m_list = new QVector<PokerCard*>;

    int index = 0;
    for(int i = Suit::Suit_MIN + 1; i < Suit::Suit_MAX; i++)
    {
        Suit suit = (Suit)i;
//        qInfo() << "suit =" << suit;
        for(int j = CardValue::CardValue_MIN + 1; j < CardValue::CardValue_MAX; j++)
        {
            CardValue value = (CardValue)j;
//            qInfo() << "CardValue =" << value;

            PokerCard * card = new PokerCard(index, value, suit);
            m_list->insert(index, card);
//            qInfo() << "index =" << index;
            if(index == CARD_MAX_NUM)
            {
                qWarning() << "index out of " << CARD_MAX_NUM;
            }
            index ++;
        }
    }
//    qInfo() << m_list->size() << "***" << *m_list;
}


void PokerCards::clearCardList()
{
    if(m_list == nullptr)
    {
        qWarning() << "m_list is nullptr";
        return;
    }
    for(int i = 0; i < m_list->size(); i++)
    {
        PokerCard* card = m_list->at(i);
        if(card != nullptr)
        {
            delete card;
        }
    }
    m_list->clear();
    delete m_list;
}

void PokerCards::initRandomList()
{
    for(int i = 0; i < CARD_MAX_NUM; i++)
    {
        m_randomList.append(i);
    }
}

QVector<PokerCard *> *PokerCards::getList()
{
    return m_list;
}

PokerCard *PokerCards::getRandomCard()
{
    int randomNumber = QRandomGenerator::global()->bounded(52);

    return m_list->at(randomNumber);
}

struct QRandomGeneratorAdapter {
    using result_type = quint32; // 定义 result_type

    result_type operator()() {
        return QRandomGenerator::global()->generate();
    }

    static constexpr result_type min() {
        return std::numeric_limits<result_type>::min();
    }

    static constexpr result_type max() {
        return std::numeric_limits<result_type>::max();
    }
};

void PokerCards::shuffleCards()
{
    qInfo() << "begin *** " << m_randomList;
    std::shuffle(m_randomList.begin(), m_randomList.end(), QRandomGeneratorAdapter());
    qInfo() << "end = " << m_randomList;
}
