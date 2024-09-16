#include "bizcommand.h"

#include <QDebug>

#include "src/utility/Test.h"

#include "src/rule/Poker.h"


BIZCommand::BIZCommand(QObject *parent) : QObject(parent)
{
    qInfo() << "BIZCommand init";

    Test test;
}
