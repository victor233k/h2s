#include "Test.h"

#include <QDebug>


Test::Test(QObject *parent) : QObject(parent)
{
    initCardList();

    testDealCard();
    testIsStraightFlush();
    testIsFourOfAKind();
    //    testFindBestHand();
}

Test::~Test()
{
    clearCardList();
}

void Test::testDealCard()
{
    qInfo() << __func__;
    Poker cards;
    cards.shuffleCards();
    auto list = cards.dealCard(7);
    qInfo() << __func__ << Poker::printList(list);
}

void Test::testFindBestHand()
{
    qInfo() << __func__;
    Poker cards;
    cards.shuffleCards();
    auto list = cards.dealCard(7);
    QVector<Card*> bestHand;
    cards.findBestHand(list, bestHand);
    qInfo() << __func__ << Poker::printList(list,    "in  list : ");
    qInfo() << __func__ << Poker::printList(bestHand,"out list : ");
}

void Test::testIsStraightFlush()
{
    qInfo() << __func__;
    QVector<Card*> list0;
    QVector<Card*> outlist;
    list0 = getFourOfAKindList();
    Poker::isStraightFlush(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");

    outlist.clear();

    list0 = getStraightFlushList();
    Poker::isStraightFlush(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");
}

void Test::testIsFourOfAKind()
{
    qInfo() << __func__;
    QVector<Card*> list0;
    QVector<Card*> outlist;

    list0 = getStraightFlushList();
    Poker::isFourOfAKind(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");

    outlist.clear();

    list0 = getFourOfAKindList();
    Poker::isFourOfAKind(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");
}

void Test::testIsFullHouse()
{
    qInfo() << __func__;
    QVector<Card*> list0;
    QVector<Card*> outlist;
    list0 = getTwoPairsList();
    Poker::isFullHouse(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");

    outlist.clear();

    list0 = getFullHouseList();
    Poker::isFullHouse(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");
}

void Test::initCardList()
{
    m_list = new QVector<Card*>;
    for(int i = 0; i < CARD_MAX_NUM; i++)
    {
        Card * card = new Card(i);
        m_list->append(card);
    }
}

QVector<Card *> Test::getCustomList(QString val)
{
    QVector<Card *> list;

    for(int i = 0; i < val.size() - 1; i = i + 2)
    {
        QString str;
        str.append(val.at(i)).append(val.at(i+1));
        Card * card = m_list->at(Card::getIdByCardString(str));
        list.append(card);
    }
    return list;
}

//TODO:Randomly provide a matching list
QVector<Card *> Test::getStraightFlushList()
{
    return getCustomList("DJD3DTD5DKDADQ");
}

QVector<Card *> Test::getFourOfAKindList()
{
    return getCustomList("HKHQH3CQCADQSQ");
}

QVector<Card *> Test::getFullHouseList()
{
    return getCustomList("HKHQH3CQCADQS3");
}

QVector<Card *> Test::getFlushList()
{
    return getCustomList("SJH3STS5SKCASQ");
}

QVector<Card *> Test::getStraightList()
{
    return getCustomList("SJD3DTD5SKCAHQ");
}

QVector<Card *> Test::getThreeOfAKindList()
{
    return getCustomList("SJD3DTDJSKCJHQ");
}

QVector<Card *> Test::getTwoPairsList()
{
    return getCustomList("SJD3DTDKSKCJHQ");
}

QVector<Card *> Test::getOnePairList()
{
    return getCustomList("SJD3DTDKSKC2HQ");
}

void Test::clearCardList()
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
