#ifndef BIZCOMMAND_H
#define BIZCOMMAND_H

#include <QObject>
#include <QUrl>
#include <QJsonArray>
#include <QJsonObject>

#include "src/rule/PublicCardModel.h"

class BIZCommand : public QObject
{
    Q_OBJECT
public:
    explicit BIZCommand(QObject *parent = nullptr);

    Q_PROPERTY(QUrl appDir READ getAppDir CONSTANT)
    Q_PROPERTY(QString logTest READ getLogTest CONSTANT)

//    Q_PROPERTY(QJsonArray publicCardList READ getPublicCardList WRITE setPublicCardList NOTIFY publicCardListChanged)

public:
    QUrl getAppDir();

    QString getLogTest();

    Q_INVOKABLE void choiceCard(int index);
    Q_INVOKABLE QUrl getCardImage(int index);

    Q_INVOKABLE void appQuit(int val);

//    QJsonArray getPublicCardList();
//    void setPublicCardList(QJsonArray val);
    PublicCardModel *getPublicCardModel();
private:
    PublicCardModel *publicCardModel;


signals:
//    void publicCardListChanged();
};

#endif // BIZCOMMAND_H
