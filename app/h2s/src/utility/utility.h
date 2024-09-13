#ifndef UTILITY_H
#define UTILITY_H

#include <QObject>
#include <QPointer>
#include <QSharedPointer>
#include <QDebug>
#include <QQmlContext>
#include <QQmlApplicationEngine>

class UtilityEx : public QObject
{
    Q_OBJECT
};

class Utility : public QObject
{
    Q_OBJECT
public:
    static Utility *getInstance();

private:
    explicit Utility(QObject *parent = nullptr);

    QSharedPointer<QQmlApplicationEngine> qmlEngine;

public:
    QSharedPointer<QQmlApplicationEngine> getQmlEngine()
    {
        return qmlEngine;
    }

    QVariantMap mergeVariantMaps(const QVariantMap &map1, const QVariantMap &map2);

signals:

public slots:
    void initUtility(QSharedPointer<QQmlApplicationEngine> qmlEngine);
};

#endif // UTILITY_H
