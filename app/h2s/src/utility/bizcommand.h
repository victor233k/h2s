#ifndef BIZCOMMAND_H
#define BIZCOMMAND_H

#include <QObject>
#include <QUrl>

class BIZCommand : public QObject
{
    Q_OBJECT
public:
    explicit BIZCommand(QObject *parent = nullptr);

    Q_PROPERTY(QUrl appDir READ getAppDir CONSTANT)
    Q_PROPERTY(QString logTest READ getLogTest CONSTANT)

public:
    QUrl getAppDir();

    QString getLogTest();
signals:

};

#endif // BIZCOMMAND_H
