#ifndef POKERCARDS_H
#define POKERCARDS_H

#include <QObject>

#include <QMap>
#include <QVector>

#include "src/rule/PokerCard.h"
#include "src/rule/Rule.h"

#define CARD_MAX_NUM 52



class PokerCards : public QObject
{
    Q_OBJECT
public:
    explicit PokerCards(QObject *parent = nullptr);
    ~PokerCards();

    QVector<PokerCard*> * getList();
    PokerCard* getRandomCard();

    void shuffleCards();
private:
    QVector<PokerCard*> *m_list = nullptr;
    QVector<int> m_randomList;

    void initCardList();
    void clearCardList();

    void initRandomList();
signals:

};

#endif // POKERCARDS_H
