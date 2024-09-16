#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QMap>
#include <QDebug>

/**************
 * 梅花（Clubs）    C
 * 方块（Diamonds)  D
 * 红心（Hearts）   H
 * 黑桃（Spades）   S
 **************/

//1. 能获取花色(suit
//2. 能获取牌值(rank

#define SUIT "CDHS"
#define RANK "23456789TJQKA"
#define CARD_MAX_NUM 52

class Card
{
public:
    Card(int id);

    int getId();
    QString getSuit();
    QString getRank();
    int getRankValue();
    QString getCardString();
public:

    static int getRankValue(QString val) {
        static const QMap<QString, int> map = {
            {"2", 0 },
            {"3", 1 },
            {"4", 2 },
            {"5", 3 },
            {"6", 4 },
            {"7", 5 },
            {"8", 6 },
            {"9", 7 },
            {"T", 8 },
            {"J", 9 },
            {"Q", 10},
            {"K", 11},
            {"A", 12}
        };
        assert(map.contains(val));
        return map.value(val);
    }

    static QString getCardStringById(int index) {
        static const QString list[52] = {
            "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CT", "CJ", "CQ", "CK", "CA",
            "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DT", "DJ", "DQ", "DK", "DA",
            "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "HT", "HJ", "HQ", "HK", "HA",
            "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "ST", "SJ", "SQ", "SK", "SA"
        };
        assert(index >= 0 && index < 52);
        return list[index];
    }

public:
    // 重载小于运算符
    bool operator<(const Card& other) const {
        return rankValue < other.rankValue;
    }

    // 重载大于运算符
    bool operator>(const Card& other) const {
        return rankValue > other.rankValue;
    }

    // 重载等于运算符
    bool operator==(const Card& other) const {
        return rankValue == other.rankValue;
    }

    // 重载小于等于运算符
    bool operator<=(const Card& other) const {
        return rankValue <= other.rankValue;
    }

    // 重载大于等于运算符
    bool operator>=(const Card& other) const {
        return rankValue >= other.rankValue;
    }
private:
    int id;
    int rankValue;
};

#endif // CARD_H
