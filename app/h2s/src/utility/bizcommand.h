#ifndef BIZCOMMAND_H
#define BIZCOMMAND_H

#include <QObject>

class BIZCommand : public QObject
{
    Q_OBJECT
public:
    explicit BIZCommand(QObject *parent = nullptr);

signals:

};

#endif // BIZCOMMAND_H
