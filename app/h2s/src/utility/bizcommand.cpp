#include "Bizcommand.h"

#include <QDebug>
#include <QGuiApplication>
#include <QApplication>

#include "src/utility/Test.h"

#include "src/rule/Poker.h"

static const QString QML_FILE = "file:///";

BIZCommand::BIZCommand(QObject *parent) : QObject(parent)
{
    qInfo() << "BIZCommand init";
#ifdef QT_DEBUG
    Test test;
#endif

    publicCardModel = new PublicCardModel;

}

QUrl BIZCommand::getAppDir()
{
    QString str;
    str.append(QML_FILE)
       .append(QGuiApplication::applicationDirPath());

    return QUrl(str);
}

QString BIZCommand::getLogTest()
{
    return QString("android debug ~~~~~~~~~");
}

void BIZCommand::choiceCard(int index)
{
    qInfo() << "test index : " << index;
}

QUrl BIZCommand::getCardImage(int index)
{
    QString str = Card::getCardImageById(index);

    return QUrl(str);
}

void BIZCommand::appQuit(int val)
{
    QApplication::exit(val);
//    QApplication::quit();
}

PublicCardModel *BIZCommand::getPublicCardModel()
{
    return publicCardModel;
}

//QJsonArray BIZCommand::getPublicCardList()
//{
//    QJsonArray array;
//    for(int i = 0; i < 5; i++)
//    {
//        QJsonObject obj;
//        obj[]
//    }
//    return array;
//}

//void BIZCommand::setPublicCardList(QJsonArray val)
//{

//}
