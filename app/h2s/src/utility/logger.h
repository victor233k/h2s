#ifndef LOGGER_H
#define LOGGER_H

#include <QtDebug>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QFileInfo>
#include <QDateTime>
#include <QStandardPaths>
#include <QCoreApplication>

#define LOG_FILE_KEEP_NUM 2

class QLogger
{
public:
    static QString getConfigFolder()
    {

        QString folder = QCoreApplication::applicationDirPath() + "/log";
        if (!QDir(folder).exists())
        {
            QDir().mkdir(folder);
        }

        return folder;
    }

    static void _LoggerHandler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
    {
        QString logs = getConfigFolder();
//        qInfo() << "log path = " << logs;
        QDir dir(logs);

        QString currentDate = QDateTime::currentDateTime().toString("yyyyMMdd");
        QString logName = "/log-" + currentDate + ".log";
        QString logFileName = logs + logName;

        // #3 Keep a journal for the last one week.
        if (!QFile::exists(logFileName))
        {
            QFileInfoList fileList = dir.entryInfoList(QStringList() << "loginapp-*.log", QDir::NoFilter, QDir::Time);
            if (fileList.size() >= LOG_FILE_KEEP_NUM)
            {
                int i = 1;
                foreach (QFileInfo fileInfo, fileList)
                {
                    if (i >= LOG_FILE_KEEP_NUM)
                    {
                        QString fileName = fileInfo.absoluteFilePath();
                        QFile::remove(fileName);
                    }
                    i++;
                }
            }
        }

        QFile file(logFileName);
        QIODevice::OpenMode flag;
#ifdef QT_DEBUG
        flag = (QIODevice::WriteOnly | QIODevice::Append | QIODevice::Unbuffered);
#else
        flag = (QIODevice::WriteOnly | QIODevice::Append);
#endif
        if (!file.open(flag))
        {
            file.close();
            return;
        }

        QByteArray localMsg(msg.toLocal8Bit()); //<-- not a char* any more!
        switch (type)
        {
        case QtDebugMsg:
            fprintf(stderr, "%s DEBUG [%s:%u] %s\n", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz").toLocal8Bit().constData(), fileShort(context.file), context.line, localMsg.constData());
            break;
        case QtInfoMsg:
            fprintf(stderr, "%s INFO [%s:%u] %s\n", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz").toLocal8Bit().constData(), fileShort(context.file), context.line, localMsg.constData());
            break;
        case QtWarningMsg:
            fprintf(stderr, "%s WARN [%s:%u] %s\n", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz").toLocal8Bit().constData(), fileShort(context.file), context.line, localMsg.constData());
            break;
        case QtCriticalMsg:
            fprintf(stderr, "%s CRITICAL [%s:%u] %s\n", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz").toLocal8Bit().constData(), fileShort(context.file), context.line, localMsg.constData());
            break;
        case QtFatalMsg:
            fprintf(stderr, "%s FATAL [%s:%u] %s\n", QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz").toLocal8Bit().constData(), fileShort(context.file), context.line, localMsg.constData());
            break;
        }

        // #4 joint string
        QString currentDateTime = QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss.zzz");
        QString logMsg;

        switch (type)
        {
        case QtDebugMsg:
            logMsg = QString("%1 DEBUG [%2:%3] %4\n").arg(currentDateTime).arg(fileShort(context.file)).arg(context.line).arg(msg);
            break;
        case QtInfoMsg:
            logMsg = QString("%1 INFO [%2:%3] %4\n").arg(currentDateTime).arg(fileShort(context.file)).arg(context.line).arg(msg);
            break;
        case QtWarningMsg:
            logMsg = QString("%1 WARN [%2:%3] %4\n").arg(currentDateTime).arg(fileShort(context.file)).arg(context.line).arg(msg);
            break;
        case QtCriticalMsg:
            logMsg = QString("%1 CRITICAL [%2:%3] %4\n").arg(currentDateTime).arg(fileShort(context.file)).arg(context.line).arg(msg);
            break;
        case QtFatalMsg:
            logMsg = QString("%1 FATAL [%2:%3] %4\n").arg(currentDateTime).arg(fileShort(context.file)).arg(context.line).arg(msg);
            abort();
            break;
        default:
            break;
        }

        // #5 log message out to file
        QTextStream ts(&file);
        ts << logMsg;
#ifdef QT_DEBUG
        ts.flush();
#endif

        file.close();
    }

    static inline char *fileShort(const char *file)
    {
        char *name = NULL;
        char *ptr = (char *)file;
        if (file == NULL)
            return NULL;
        while (*ptr != '\0')
        {
            if (*ptr == '/')
                name = ptr;
            ptr++;
        }
        return name == NULL ? (char *)file : (name + 1);
    }
};


#endif // LOGGER_H
