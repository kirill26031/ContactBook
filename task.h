#ifndef TASK_H
#define TASK_H

#include <QtCore>
#include "ContactBook.h"

class Task : public QObject
{
    Q_OBJECT
public:
    Task(QObject *parent = 0);

public slots:
    void run();

signals:
    void finished();
private:
QTextStream qout;
QTextStream qin;
std::string greeting;
ContactBook* book;
Contact* current;
void help(const QStringList list);
void contact(const QStringList list);
void phone(const QStringList list);
void search(const QStringList list);
void showAll();
std::string getName(std::string name);
};
#endif // TASK_H
