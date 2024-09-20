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
    Card(QString str);

    int getId();
    QString getSuit();
    int getSuitIndex();
    QString getRank();
    int getRankValue();
    QString getCardString();


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
private:
    static int getSuitIndex(QString val) {
        val = val.toUpper();
        static const QMap<QString, int> map = {
            {"C", 0 },
            {"D", 1 },
            {"H", 2 },
            {"S", 3 },
        };
        assert(map.contains(val));
        return map.value(val);
    };

    static QString getCardStringById(int index) {

        static const QString list[52] = {
//           0     1     2     3     4     5     6     7     8     9     10    11    12
            "C2", "C3", "C4", "C5", "C6", "C7", "C8", "C9", "CT", "CJ", "CQ", "CK", "CA",
//           13    14    15    16    17    18    19    20    21    22    23    24    25
            "D2", "D3", "D4", "D5", "D6", "D7", "D8", "D9", "DT", "DJ", "DQ", "DK", "DA",
//           26    27    28    29    30    31    32    33    34    35    36    37    38
            "H2", "H3", "H4", "H5", "H6", "H7", "H8", "H9", "HT", "HJ", "HQ", "HK", "HA",
//           39    40    41    42    43    44    45    46    47    48    49    50    51
            "S2", "S3", "S4", "S5", "S6", "S7", "S8", "S9", "ST", "SJ", "SQ", "SK", "SA"
        };
        assert(index >= 0 && index < 52);
        return list[index];
    }

    static int getIdByCardString(QString val) {
        static const QMap<QString, int> map = {
            {"C2", 0}, {"C3", 1}, {"C4", 2}, {"C5", 3}, {"C6", 4}, {"C7", 5}, {"C8", 6}, {"C9", 7}, {"CT", 8}, {"CJ", 9}, {"CQ",10}, {"CK",11}, {"CA",12},
            {"D2",13}, {"D3",14}, {"D4",15}, {"D5",16}, {"D6",17}, {"D7",18}, {"D8",19}, {"D9",20}, {"DT",21}, {"DJ",22}, {"DQ",23}, {"DK",24}, {"DA",25},
            {"H2",26}, {"H3",27}, {"H4",28}, {"H5",29}, {"H6",30}, {"H7",31}, {"H8",32}, {"H9",33}, {"HT",34}, {"HJ",35}, {"HQ",36}, {"HK",37}, {"HA",38},
            {"S2",39}, {"S3",40}, {"S4",41}, {"S5",42}, {"S6",43}, {"S7",44}, {"S8",45}, {"S9",46}, {"ST",47}, {"SJ",48}, {"SQ",49}, {"SK",50}, {"SA",51}
        };
        assert(map.contains(val));
        return map.value(val);
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
    int suitIndex;
};

#endif // CARD_H
