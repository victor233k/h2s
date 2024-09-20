#include "bizcommand.h"

#include <QDebug>
#include <QGuiApplication>

#include "src/utility/Test.h"

#include "src/rule/Poker.h"

static const QString QML_FILE = "file:///";

BIZCommand::BIZCommand(QObject *parent) : QObject(parent)
{
    qInfo() << "BIZCommand init";

    Test test;
}

QUrl BIZCommand::getAppDir()
{
    QString str;
    str.append(QML_FILE)
       .append(QGuiApplication::applicationDirPath());

    return QUrl(str);
}
