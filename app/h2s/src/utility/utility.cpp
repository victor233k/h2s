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

QVariantMap Utility::mergeVariantMaps(const QVariantMap &map1, const QVariantMap &map2)
{
    QVariantMap result = map1; // 以第一个映射作为基础

    // 遍历第二个映射的键，并合并到结果映射中
    for (const QString &key : map2.keys()) {
        if (result.contains(key)) {
            // 如果键已存在，根据需要更新值或合并值
            // 这里我们简单地覆盖第一个映射中的值
            result[key] = map2[key];
        } else {
            // 如果键不存在，添加到结果映射中
            result.insert(key, map2[key]);
        }
    }

    return result;
}

void Utility::initUtility(QSharedPointer<QQmlApplicationEngine> qmlEngine)
{
    this->qmlEngine = qmlEngine;
    if (this->qmlEngine)
    {
        this->qmlEngine->rootContext()->setContextProperty("utility", this);
    }
}
