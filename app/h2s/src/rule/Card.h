#ifndef CARD_H
#define CARD_H

#include <QObject>
#include <QMap>
#include <QDebug>

#include "src/rule/Definitions.h"

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
            {"2", 1 },
            {"3", 2 },
            {"4", 3 },
            {"5", 4 },
            {"6", 5 },
            {"7", 6 },
            {"8", 7 },
            {"9", 8 },
            {"T", 9 },
            {"J", 10},
            {"Q", 11},
            {"K", 12},
            {"A", 13}
        };
        assert(map.contains(val));
        return map.value(val);
    }

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
    static QString getCardImageById(int index) {

        static const QString list[52] = {
            "qrc:/c120/C2.png", "qrc:/c120/C3.png", "qrc:/c120/C4.png", "qrc:/c120/C5.png", "qrc:/c120/C6.png",
            "qrc:/c120/C7.png", "qrc:/c120/C8.png", "qrc:/c120/C9.png", "qrc:/c120/CT.png", "qrc:/c120/CJ.png",
            "qrc:/c120/CQ.png", "qrc:/c120/CK.png", "qrc:/c120/CA.png",
            "qrc:/c120/D2.png", "qrc:/c120/D3.png", "qrc:/c120/D4.png", "qrc:/c120/D5.png", "qrc:/c120/D6.png",
            "qrc:/c120/D7.png", "qrc:/c120/D8.png", "qrc:/c120/D9.png", "qrc:/c120/DT.png", "qrc:/c120/DJ.png",
            "qrc:/c120/DQ.png", "qrc:/c120/DK.png", "qrc:/c120/DA.png",
            "qrc:/c120/H2.png", "qrc:/c120/H3.png", "qrc:/c120/H4.png", "qrc:/c120/H5.png", "qrc:/c120/H6.png",
            "qrc:/c120/H7.png", "qrc:/c120/H8.png", "qrc:/c120/H9.png", "qrc:/c120/HT.png", "qrc:/c120/HJ.png",
            "qrc:/c120/HQ.png", "qrc:/c120/HK.png", "qrc:/c120/HA.png",
            "qrc:/c120/S2.png", "qrc:/c120/S3.png", "qrc:/c120/S4.png", "qrc:/c120/S5.png", "qrc:/c120/S6.png",
            "qrc:/c120/S7.png", "qrc:/c120/S8.png", "qrc:/c120/S9.png", "qrc:/c120/ST.png", "qrc:/c120/SJ.png",
            "qrc:/c120/SQ.png", "qrc:/c120/SK.png", "qrc:/c120/SA.png"
        };
//        assert(index >= 0 && index < 52);

        if(index < 0 || index >= 52)
        {
            return QString("qrc:/c120/back.png");
        }
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
    bool operator < (const Card& other) const {
        return rankValue < other.rankValue;
    }

    // 重载大于运算符
    bool operator > (const Card& other) const {
        return rankValue > other.rankValue;
    }

    // 重载等于运算符
    bool operator == (const Card& other) const {
        return rankValue == other.rankValue;
    }

    // 重载小于等于运算符
    bool operator <= (const Card& other) const {
        return rankValue <= other.rankValue;
    }

    // 重载大于等于运算符
    bool operator >= (const Card& other) const {
        return rankValue >= other.rankValue;
    }

//    bool operator * (const Card& other) const {
//        return rankValue * other.rankValue;
//    }

    bool operator * (const int& other) const {
        return rankValue * other;
    }
private:
    int id;//52
    int rankValue;
    int suitIndex;
};

#endif // CARD_H
