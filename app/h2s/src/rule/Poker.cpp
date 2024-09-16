#include "Poker.h"

#include <QRandomGenerator>

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

Poker::Poker(QObject *parent) : QObject(parent)
{
    initCardList();
}

Poker::~Poker()
{
    clearCardList();
}

void Poker::shuffleCards()
{
    initRandomList();
//    qInfo() << "begin *** " << m_randomList;
    std::shuffle(m_randomList.begin(), m_randomList.end(), QRandomGeneratorAdapter());
//    qInfo() << "end = " << m_randomList;
}

QVector<Card *> Poker::dealCard(int num)
{
    if(num > CARD_MAX_NUM) {
        num = CARD_MAX_NUM;
        qWarning() << "deal card num > " << CARD_MAX_NUM << ", just return 52 card!";
    }
    QVector<Card *> list;
    for(int i = 0; i < num; i++)
    {
        int index = m_randomList.last();
        m_randomList.pop_back();
        list.append(m_list->at(index));
    }
    return list;
}

void Poker::initCardList()
{
    m_list = new QVector<Card*>;
    for(int i = 0; i < CARD_MAX_NUM; i++)
    {
        Card * card = new Card(i);
        m_list->append(card);
    }
}

void Poker::clearCardList()
{
    if(m_list == nullptr)
    {
        qWarning() << "m_list is nullptr";
        return;
    }
    for(int i = 0; i < m_list->size(); i++)
    {
        Card* card = m_list->at(i);
        if(card != nullptr)
        {
            delete card;
        }
    }
    m_list->clear();
    delete m_list;
}

void Poker::initRandomList()
{
    m_randomList.clear();
    for(int i = 0; i < CARD_MAX_NUM; i++)
    {
        m_randomList.append(i);
    }
}
