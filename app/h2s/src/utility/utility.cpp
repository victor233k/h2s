#include "Utility.h"
#include <QThread>

static Utility *pInstance = Q_NULLPTR;
Utility *Utility::getInstance()
{
    if (Q_NULLPTR == pInstance)
    {
        pInstance = new Utility;
    }

    return pInstance;
}

Utility::Utility(QObject *parent) : QObject(parent)
{
    qmlRegisterType<UtilityEx>("utility", 1, 0, "Utility");
}

void Utility::initUtility(QSharedPointer<QQmlApplicationEngine> qmlEngine)
{
    this->qmlEngine = qmlEngine;
    if (this->qmlEngine)
    {
        this->qmlEngine->rootContext()->setContextProperty("utility", this);
    }
}
