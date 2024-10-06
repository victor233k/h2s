#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QThread>
#include <QQmlComponent>
#include <QThread>
#include <QLockFile>
#include <QTranslator>
#include <QDir>
#include <QCryptographicHash>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QProcess>
#include <QApplication>

#include "src/utility/Utility.h"
#include "src/utility/Logger.h"
#include "src/utility/Bizcommand.h"
#include "src/rule/PublicCardModel.h"
#include "src/rule/PlayerModel.h"


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    qInstallMessageHandler(QLogger::_LoggerHandler);
    qInfo() << "*** app starts, main threadId:" << QThread::currentThreadId();

    QSharedPointer<QQmlApplicationEngine> engine(new QQmlApplicationEngine);
    qmlRegisterType<BIZCommand>("utility", 1, 0, "BIZCommand");
    qmlRegisterType<PublicCardModel>("utility", 1, 0, "PublicCardModel");
    qmlRegisterType<PlayerModel>("utility", 1, 0, "PlayerModel");

    QScopedPointer<Utility> utility(Utility::getInstance());
    utility->initUtility(engine);


    qInfo() << "load *Api.qml: ";
    QQmlComponent component0(engine.data(), QUrl(QStringLiteral("qrc:/api/BizApi.qml")));
    BIZCommand *bizCommand = qobject_cast<BIZCommand *>(component0.create());

    QQmlComponent component1(engine.data(), QUrl(QStringLiteral("qrc:/api/PublicCardModelApi.qml")));
    PublicCardModel *publicCardModel = qobject_cast<PublicCardModel *>(component1.create());

    QQmlComponent component2(engine.data(), QUrl(QStringLiteral("qrc:/api/PlayerModelApi.qml")));
    PlayerModel *playerModel = qobject_cast<PlayerModel *>(component2.create());

    qInfo() << "setContextProperty";
    engine->rootContext()->setContextProperty("bizCommand", bizCommand);
    engine->rootContext()->setContextProperty("publicCardModel", publicCardModel);
    engine->rootContext()->setContextProperty("playerModel", playerModel);


    qInfo() << "load main.qml: ";
    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));
    QList<QObject *> rootObjects = engine->rootObjects();
    if (rootObjects.isEmpty())
    {
        return -1;
    }

    return app.exec();
}
