#include "Test.h"

#include <QDebug>


Test::Test(QObject *parent) : QObject(parent)
{

    initCardList();

//    testDealCard();
//    testIsStraightFlush();
//    testIsFourOfAKind();
//    testIsFullHouse();
//    testIsFlush();
//    testIsStraight();
//    testIsThreeOfAKind();
//    testIsTwoPairs();
//    testIsOnePair();

//    testFindBestHand();
    testCompareHands();
}

Test::~Test()
{
    clearCardList();
}

void Test::testDealCard()
{
    Poker cards;
    cards.shuffleCards();
    auto list = cards.dealCard(7);
    qInfo() << __func__ << Poker::printList(list);
}

void Test::testFindBestHand()
{
    Poker cards;
    cards.shuffleCards();
    auto list = cards.dealCard(7);
//    auto list = getCustomList("CKCTCQC5C7H5HJ");q
    QVector<Card > bestHand;
    qInfo() << __func__ << "score :" << Poker::findBestHand(list, bestHand);
    qInfo() << __func__ << Poker::printList(list,    "in  list : ");
    qInfo() << __func__ << Poker::printList(bestHand,"out list : ");
}

void Test::testCompareHands()
{
    QVector<Card > h1;
    QVector<Card > h2;
    QVector<Card > pc;
    int op;
    h1 = getCustomList("SKS5");
    h2 = getCustomList("HAH2");
    pc = getCustomList("CKCTCQ");
    op = Poker::compareHands(h1, h2, pc);
    if(op == Greater){
        qInfo() << __func__ << "Greater";
    } else if (op == Less) {
        qInfo() << __func__ << "Less";
    } else if (op == Equal) {
        qInfo() << __func__ << "Equal";
    }

    h1 = getCustomList("C6C5");
    h2 = getCustomList("CAC2");
    pc = getCustomList("CKCTCQ");
    op = Poker::compareHands(h1, h2, pc);
    if(op == Greater){
        qInfo() << __func__ << "Greater";
    } else if (op == Less) {
        qInfo() << __func__ << "Less";
    } else if (op == Equal) {
        qInfo() << __func__ << "Equal";
    }

    h1 = getCustomList("C6C5");
    h2 = getCustomList("HKHQ");
    pc = getCustomList("CKSKCQ");
    op = Poker::compareHands(h1, h2, pc);
    if(op == Greater){
        qInfo() << __func__ << "Greater";
    } else if (op == Less) {
        qInfo() << __func__ << "Less";
    } else if (op == Equal) {
        qInfo() << __func__ << "Equal";
    }

}

void Test::testIsStraightFlush()
{
    QVector<Card > list0;
    QVector<Card > outlist;
    list0 = getFourOfAKindList();
    qInfo() << __func__ << Poker::isStraightFlush(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");

    outlist.clear();

    list0 = getStraightFlushList();
    qInfo() << __func__ << Poker::isStraightFlush(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");
}

void Test::testIsFourOfAKind()
{
    QVector<Card > list0;
    QVector<Card > outlist;

    list0 = getStraightFlushList();
    qInfo() << __func__ << Poker::isFourOfAKind(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");

    outlist.clear();

    list0 = getFourOfAKindList();
    qInfo() << __func__ << Poker::isFourOfAKind(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");
}

void Test::testIsFullHouse()
{
    QVector<Card > list0;
    QVector<Card > outlist;
//    list0 = getTwoPairsList();
    list0 = getFlushList();
    qInfo() << __func__ << Poker::isFullHouse(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");

    outlist.clear();

    list0 = getFullHouseList();
    qInfo() << __func__ << Poker::isFullHouse(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");
}

void Test::testIsFlush()
{
    QVector<Card > list0;
    QVector<Card > outlist;
    list0 = getTwoPairsList();
    qInfo() << __func__ << Poker::isFlush(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");

    outlist.clear();

    list0 = getFlushList();
    qInfo() << __func__ << Poker::isFlush(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");
}

void Test::testIsStraight()
{
    QVector<Card > list0;
    QVector<Card > outlist;
    list0 = getTwoPairsList();
    qInfo() << __func__ << Poker::isStraight(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");

    outlist.clear();

    list0 = getStraightList();
    qInfo() << __func__ << Poker::isStraight(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");
}

void Test::testIsThreeOfAKind()
{
    QVector<Card > list0;
    QVector<Card > outlist;
    list0 = getTwoPairsList();
    qInfo() << __func__ << Poker::isThreeOfAKind(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");

    outlist.clear();

    list0 = getThreeOfAKindList();
    qInfo() << __func__ << Poker::isThreeOfAKind(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");
}

void Test::testIsTwoPairs()
{
    QVector<Card > list0;
    QVector<Card > outlist;
    list0 = getOnePairList();
    qInfo() << __func__ << Poker::isTwoPairs(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");

    outlist.clear();

    list0 = getTwoPairsList();
    qInfo() << __func__ << Poker::isTwoPairs(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");
}

void Test::testIsOnePair()
{
    QVector<Card > list0;
    QVector<Card > outlist;
    list0 = getStraightList();
    qInfo() << __func__ << Poker::isOnePair(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");

    outlist.clear();

    list0 = getOnePairList();
    qInfo() << __func__ << Poker::isOnePair(list0, outlist);
    qInfo() << __func__ << Poker::printList(list0,  "in  list : ");
    qInfo() << __func__ << Poker::printList(outlist,"out list : ");
}


void Test::initCardList()
{
    m_list = new QVector<Card >;
    for(int i = 0; i < CARD_MAX_NUM; i++)
    {
        m_list->append(Card(i));
    }
}

QVector<Card > Test::getCustomList(QString val)
{
    QVector<Card > list;

    for(int i = 0; i < val.size() - 1; i = i + 2)
    {
        QString str;
        str.append(val.at(i)).append(val.at(i+1));
        Card  card = m_list->at(Card::getIdByCardString(str));
        list.append(card);
    }
    return list;
}

//TODO:Randomly provide a matching list
QVector<Card > Test::getStraightFlushList()
{
    return getCustomList("DJD3DTD5DKDADQ");
}

QVector<Card > Test::getFourOfAKindList()
{
    return getCustomList("HKHQH3CQCADQSQ");
}

QVector<Card > Test::getFullHouseList()
{
    return getCustomList("HKHQH3CQCADQS3");
}

QVector<Card > Test::getFlushList()
{

    return getCustomList("CKCTCQC5C7H5HJ");
    return getCustomList("SJS3STS5SKCASQ");
}

QVector<Card > Test::getStraightList()
{
    return getCustomList("SJD3DTD5SKCAHQ");
}

QVector<Card > Test::getThreeOfAKindList()
{
    return getCustomList("SJD3DTDJSKCJHQ");
}

QVector<Card > Test::getTwoPairsList()
{
    return getCustomList("SJD3DTDKSKCJHQ");
}

QVector<Card > Test::getOnePairList()
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
