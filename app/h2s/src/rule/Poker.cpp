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

QVector<Card > Poker::dealCard(int num)
{
    if(num > CARD_MAX_NUM) {
        num = CARD_MAX_NUM;
        qWarning() << "deal card num > " << CARD_MAX_NUM << ", just return 52 card!";
    }
    QVector<Card > list;
    for(int i = 0; i < num; i++)
    {
        int index = m_randomList.last();
        m_randomList.pop_back();
        list.append(m_list->at(index));
    }
    return list;
}

//int Poker::findBestHand(const QString &list, QString &outlist)
//{

//}

int Poker::findBestHand(const QVector<Card >& list, QVector<Card > &outlist)
{
    QVector<Card > bestHand;
    QVector<Card > sortList = list;
    int score = 0;
    sortCardList(sortList);

    if(isStraightFlush(sortList, outlist))
    {
        qInfo() << "Find Straight Flush!";
        score = calculateHandScore(ShapeValue::StraightFlush, outlist);
        return score;
    }

    if(isFourOfAKind(sortList, outlist))
    {
        qInfo() << "Find Four Of A Kind!";
        score = calculateHandScore(ShapeValue::FourofaKind, outlist);
        return score;
    }

    if(isFullHouse(sortList, outlist))
    {
        qInfo() << "Find FullHouse!";
        score = calculateHandScore(ShapeValue::Fullhouse, outlist);
        return score;
    }

    if(isFlush(sortList, outlist))
    {
        qInfo() << "Find Flush!";
        score = calculateHandScore(ShapeValue::Flush, outlist);
        return score;
    }

    if(isStraight(sortList, outlist))
    {
        qInfo() << "Find Straight!";
        score = calculateHandScore(ShapeValue::Straight, outlist);
        return score;
    }

    if(isThreeOfAKind(sortList, outlist))
    {
        qInfo() << "Find Three Of A Kind!";
        score = calculateHandScore(ShapeValue::Threeofakind, outlist);
        return score;
    }

    if(isTwoPairs(sortList, outlist))
    {
        qInfo() << "Find Two Pairs!";
        score = calculateHandScore(ShapeValue::TwoPairs, outlist);
        return score;
    }

    if(isOnePair(sortList, outlist))
    {
        qInfo() << "Find One Pair!";
        score = calculateHandScore(ShapeValue::OnePair, outlist);
        return score;
    }

    for(int i = 0; i < sortList.size(); i++)
    {
        if(i < 5) {
            outlist.append(sortList.at(i));
        } else {
            qInfo() << "Find High Card!";
            score = calculateHandScore(ShapeValue::NoPair, outlist);
            return score;
        }
    }
    qInfo() << "Find High Card!";
    score = calculateHandScore(ShapeValue::NoPair, outlist);
    return score;

    return 0;
}

bool Poker::isStraightFlush(const QVector<Card >& list, QVector<Card > &outlist)
{
    bool haveSuit = false;
    QString suit;
    QMap<QString, int> suitCount;
    QVector<Card > sortList = list;

    sortCardList(sortList);

    for(int i = 0; i < sortList.size(); i++)
    {
        suitCount[sortList[i].getSuit()]++;
        if(suitCount[sortList[i].getSuit()] >= 5)
        {
            suit = sortList[i].getSuit();
            haveSuit = true;
        }
    }
    if(!haveSuit)
    {
        outlist.clear();
        return false;
    }

    QVector<Card > suitList;
    for(int i = 0; i < sortList.size(); i++)
    {
        if(sortList[i].getSuit() == suit)
        {
            suitList.append(sortList.at(i));
        }
    }

    if(isStraight(suitList, outlist))
    {
        return true;
    }
    outlist.clear();
    return false;
}

bool Poker::isFourOfAKind(const QVector<Card > &list, QVector<Card > &outlist)
{
    QVector<Card > sortList = list;
    sortCardList(sortList);
    int count = 0;

    for(int i = 0; i < sortList.size(); i++)
    {
        if(i > 0) {
            int prevValue = sortList[i-1].getRankValue();
            int currentValue = sortList[i].getRankValue();

            if(prevValue == currentValue)
            {
                outlist.append(sortList.at(i-1));
                count++;
                if(count == 3)
                {
                     outlist.append(sortList.at(i));

                     if(sortList[0].getRankValue() != sortList[i-1].getRankValue())
                     {
                         //A K K K K 3 2
                         outlist.append(sortList.at(0));
                     } else {
                         //K K K K Q 3 2
                         outlist.append(sortList.at(4));
                     }
                     return true;
                }
            } else {
                count= 0;
                outlist.clear();
            }
        }
    }
    outlist.clear();
    return false;
}

bool Poker::isFullHouse(const QVector<Card > &list, QVector<Card > &outlist)
{
    QVector<Card > sortList = list;
    sortCardList(sortList);
    int count = 0;
    int TreeOfKindValue;
    bool haveThreeOfAKind = false;

    //find best TreeOfKind
    for(int i = 0; i < sortList.size(); i++)
    {
        if(i > 0) {
            int prevValue = sortList[i-1].getRankValue();
            int currentValue = sortList[i].getRankValue();

            if(prevValue == currentValue)
            {
                outlist.append(sortList.at(i-1));
                count++;
                if(count == 2)
                {
                     outlist.append(sortList.at(i));
                     TreeOfKindValue = currentValue;
                     haveThreeOfAKind = true;
                     break;
                }
            } else {
                count= 0;
                outlist.clear();
            }
        }
    }
    if(haveThreeOfAKind)
    {
        //find best one pair
        for(int i = 0; i < sortList.size(); i++)
        {
            if(i > 0) {
                int prevValue = sortList[i-1].getRankValue();
                int currentValue = sortList[i].getRankValue();

                if(currentValue == TreeOfKindValue)
                    continue;

                if(prevValue == currentValue)
                {
                    outlist.append(sortList.at(i-1));
                    outlist.append(sortList.at(i));
                    return true;
                }

            }
        }
    }
    outlist.clear();
    return false;
}

bool Poker::isFlush(const QVector<Card > &list, QVector<Card > &outlist)
{
    bool haveSuit = false;
    QString suit;
    QMap<QString, int> suitCount;
    QVector<Card > sortList = list;

    sortCardList(sortList);

    for(int i = 0; i < sortList.size(); i++)
    {
        suitCount[sortList[i].getSuit()]++;
        if(suitCount[sortList[i].getSuit()] >= 5)
        {
            suit = sortList[i].getSuit();
            haveSuit = true;
        }
    }
    if(!haveSuit)
    {
        outlist.clear();
        return false;
    }

    QVector<Card > suitList;
    for(int i = 0; i < sortList.size(); i++)
    {
        if(sortList[i].getSuit() == suit)
        {
            outlist.append(sortList.at(i));
            if(outlist.size() == 5)
            {
                return true;
            }
        }
    }
    outlist.clear();
    return false;
}

bool Poker::isStraight(const QVector<Card >& list, QVector<Card > &outlist)
{
    if(list.empty())
    {
        return false;
    }

    int count = 0;
    QVector<Card > sortList = list;

    sortCardList(sortList);

    if(sortList[0].getRankValue() == Card::getRankValue("A"))
    {
        sortList.append(sortList.at(0));
    }

    for(int i = 0; i < sortList.size(); i++)
    {
        if(i > 0) {
            if(sortList[i-1].getRankValue() == (sortList[i].getRankValue() + 1) ||
                    (sortList[i-1].getRankValue() == Card::getRankValue("2") &&
                     sortList[0].getRankValue() ==  Card::getRankValue("A")) )
            {
                outlist.append(sortList.at(i-1));
                count++;
                if(count == 4)
                {
                    outlist.append(sortList.at(i));
                    return true;
                }
            } else {
                count = 0;
                outlist.clear();
            }
        }
    }
    outlist.clear();
    return false;
}

bool Poker::isThreeOfAKind(const QVector<Card > &list, QVector<Card > &outlist)
{
    QVector<Card > sortList = list;
    sortCardList(sortList);
    int count = 0;

    for(int i = 0; i < sortList.size(); i++)
    {
        if(i > 0) {
            int prevValue = sortList[i-1].getRankValue();
            int currentValue = sortList[i].getRankValue();

            if(prevValue == currentValue)
            {
                outlist.append(sortList.at(i-1));
                count++;
                if(count == 2)
                {
                     outlist.append(sortList.at(i));
                     int highCardcount = 0;
                     for(int j = 0; j < sortList.size(); j++)
                     {
                         if(sortList[j].getRankValue() != currentValue)
                         {
                             outlist.append(sortList.at(j));
                             highCardcount++;
                             if(highCardcount == 2)
                             {
                                 return true;
                             }
                         }
                     }
                }
            } else {
                count= 0;
                outlist.clear();
            }
        }
    }
    outlist.clear();
    return false;
}

bool Poker::isTwoPairs(const QVector<Card > &list, QVector<Card > &outlist)
{
    QVector<Card > sortList = list;
    sortCardList(sortList);

    int pairValue1 = -1;
    int pairValue2 = -1;
    for(int i = 0; i < sortList.size(); i++)
    {
        if(i > 0)
        {
            int prevValue = sortList[i-1].getRankValue();
            int currentValue = sortList[i].getRankValue();
            if(prevValue == currentValue)
            {
                if(pairValue1 == -1)
                {
                    pairValue1 = sortList[i].getRankValue();
                } else if (pairValue2 == -1) {
                    pairValue2 = sortList[i].getRankValue();
                } else {
                    break;
                }

                outlist.append(sortList.at(i-1));
                outlist.append(sortList.at(i));
            }
        }

    }


    if(pairValue1 != -1 && pairValue2 != -1)
    {
        for(int i = 0; i < sortList.size(); i++)
        {
            if(sortList[i].getRankValue() != pairValue1 &&
               sortList[i].getRankValue() != pairValue2)
            {
                outlist.append(sortList.at(i));
                break;
            }
        }
        return true;
    }

    outlist.clear();
    return false;
}

bool Poker::isOnePair(const QVector<Card > &list, QVector<Card > &outlist)
{
    QVector<Card > sortList = list;
    sortCardList(sortList);

    int pairValue = -1;

    for(int i = 0; i < sortList.size(); i++)
    {
        if(i > 0)
        {
            int prevValue = sortList[i-1].getRankValue();
            int currentValue = sortList[i].getRankValue();
            if(prevValue == currentValue)
            {
                pairValue = currentValue;
                outlist.append(sortList.at(i-1));
                outlist.append(sortList.at(i));
                break;
            }
        }
    }
    if(pairValue != -1)
    {
        for(int i = 0; i < sortList.size(); i++)
        {
            if(sortList[i].getRankValue() != pairValue)
            {
                if(outlist.size() != 5) {
                    outlist.append(sortList.at(i));
                    if(outlist.size() == 5)
                        return true;
                }
            }
        }
    }

    outlist.clear();
    return false;
}

int Poker::calculateHandScore(int shapeValue, const QVector<Card > &hand)
{
    int score = 1000000 * shapeValue;
    for (int i = 0; i < hand.size(); ++i) {
        Card card = hand.at(i);
        int cardValue = card.getRankValue();
        //13  4  3 2 1   130000 +  4000 +  300 + 20 + 1 134321
        //12 11 10 9 8   120000 + 11000 + 1000 + 90 + 8 132098

        //13  2  1    130000 +  2000 +  100  = 132100
        //12 11 10    120000 + 11000 + 1000  = 132000
        score += cardValue * (10000 >> i); // 2^(4-i) for i from 0 to 4
    }
    return score;
}

void Poker::sortCardList(QVector<Card > &list)
{
    std::sort(list.begin(), list.end(), [](const Card a, const Card b) {
        return a > b;
    });
}

int Poker::compareHands(QVector<Card > &hand1,QVector<Card > &hand2, QVector<Card > &pubList)
{

    QVector<Card > hand1tmp,out1;
    QVector<Card > hand2tmp,out2;
    hand1tmp << hand1 << pubList;
    hand2tmp << hand2 << pubList;

    int score1 = findBestHand(hand1tmp, out1);
    int score2 = findBestHand(hand2tmp, out2);

    qInfo() << "best hand1 : " << printList(out1) << " score 1 : " << score1;
    qInfo() << "best hand2 : " << printList(out2) << " score 2 : " << score2;
    if(score1 > score2){
        return Greater;
    } else if(score1 < score2){
        return Less;
    } else {
        return Equal;
    }
}

QString Poker::printList(const QVector<Card > &list, QString str)
{
    for(int i = 0; i < list.size(); i++)
    {
        Card card = list.at(i);
        str.append(card.getCardString()).append(" ");
    }
    return str;
}


void Poker::initCardList()
{
    m_list = new QVector<Card >;
    for(int i = 0; i < CARD_MAX_NUM; i++)
    {
//        Card  card = new Card(i);
        m_list->append(Card(i));
    }
}

void Poker::clearCardList()
{
    if(m_list == nullptr)
    {
        qWarning() << "m_list is nullptr";
        return;
    }
//    for(int i = 0; i < m_list->size(); i++)
//    {
//        Card  card = m_list->at(i);
//        if(card != nullptr)
//        {
//            delete card;
//        }
//    }
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
