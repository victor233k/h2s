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

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QApplication app(argc, argv);

    qInstallMessageHandler(QLogger::_LoggerHandler);
    qInfo() << "*** app starts, main threadId:" << QThread::currentThreadId();

    QSharedPointer<QQmlApplicationEngine> engine(new QQmlApplicationEngine);
    qmlRegisterType<BIZCommand>("utility", 1, 0, "BIZCommand");

    QScopedPointer<Utility> utility(Utility::getInstance());
    utility->initUtility(engine);


    qInfo() << "Try load *Api.qml: ";
    QQmlComponent component0(engine.data(), QUrl(QStringLiteral("qrc:/api/BizApi.qml")));
    BIZCommand *bizCommand = qobject_cast<BIZCommand *>(component0.create());

    qInfo() << "Try setContextProperty";
    engine->rootContext()->setContextProperty("bizCommand", bizCommand);

    engine->load(QUrl(QStringLiteral("qrc:/main.qml")));

    QList<QObject *> rootObjects = engine->rootObjects();
    if (rootObjects.isEmpty())
    {
        return -1;
    }
    return app.exec();
}
