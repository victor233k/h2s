#ifndef TEST_H
#define TEST_H

#include <QObject>

class Test : public QObject
{
    Q_OBJECT
public:
    explicit Test(QObject *parent = nullptr);

    void testDealCard();
    void testFindBestHand();

    void testIsStraightFlush();
signals:

};

#endif // TEST_H
