#include "Poker.h"

#include <QRandomGenerator>

struct QRandomGeneratorAdapter {
    using result_type = quint32; // define result_type

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
    std::shuffle(m_randomList.begin(), m_randomList.end(), QRandomGeneratorAdapter());
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

QVector<Card *> Poker::findBestHand(const QVector<Card*>& list, QVector<Card*> &outlist)
{
    QVector<Card *> bestHand;
    QVector<Card *> sortList = list;
    qInfo() << printList(list);
    std::sort(sortList.begin(), sortList.end(), [](const Card *a, const Card *b) {
        return *a > *b;
    });
    qInfo() << printList(sortList);


    if(isStraightFlush(sortList, outlist))
    {
        return outlist;
    }


    return bestHand;
}

bool Poker::isStraightFlush(const QVector<Card*>& list, QVector<Card*> &outlist)
{
    bool haveSuit = false;
    QString suit;
    QMap<QString, int> suitCount;
    QVector<Card *> sortList = list;

    std::sort(sortList.begin(), sortList.end(), [](const Card *a, const Card *b) {
        return *a > *b;
    });

    for(int i = 0; i < sortList.size(); i++)
    {
        suitCount[sortList.at(i)->getSuit()]++;
        if(suitCount[sortList.at(i)->getSuit()] >= 5)
        {
            suit = sortList.at(i)->getSuit();
            haveSuit = true;
        }
    }
    if(!haveSuit)
    {
        return false;
    }

    QVector<Card *> suitList;
    for(int i = 0; i < sortList.size(); i++)
    {
        if(sortList.at(i)->getSuit() == suit)
        {
            suitList.append(sortList.at(i));
        }
    }


    if(isStraight(suitList, outlist))
    {
        return true;
    }

    return false;
}

bool Poker::isStraight(const QVector<Card*>& list, QVector<Card*> &outlist)
{
    if(list.empty())
    {
        return false;
    }

    int count = 0;
    QVector<Card*> tmpList = list;
    std::sort(tmpList.begin(), tmpList.end(), [](const Card *a, const Card *b) {
        return *a > *b;
    });

    qInfo() << printList(tmpList);

    if(tmpList.at(0)->getRankValue() == Card::getRankValue("A"))
    {
        tmpList.append(tmpList.at(0));
    }
    qInfo() << printList(tmpList);

    for(int i = 0; i < tmpList.size(); i++)
    {
        if(i > 0) {
            if(tmpList.at(i-1)->getRankValue() == (tmpList.at(i)->getRankValue() + 1) ||
                    (tmpList.at(i-1)->getRankValue() == Card::getRankValue("2") &&
                     tmpList.at(0)->getRankValue() ==  Card::getRankValue("A")) )
            {
                outlist.append(tmpList.at(i-1));
                count++;
                if(count == 4)
                {
                    outlist.append(tmpList.at(i));
                    return true;
                }
            } else {
                count = 0;
                outlist.clear();
            }
        }
    }

    return false;
}

QString Poker::printList(const QVector<Card *> &list, QString str)
{
    for(int i = 0; i < list.size(); i++)
    {
        str.append(list.at(i)->getCardString()).append(" ");
    }
    return str;
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
