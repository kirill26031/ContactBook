#include "book.h"

#include <QApplication>

void setupConnections(){

}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Book w;
    setupConnections();
    w.addContact("Kyrylo");
    w.addContact("Kyryl");
    w.addContact("Kyry");
    w.addContact("Kyr");
    w.addContact("Ky");
    w.addContact("Bingo!");
    w.addContact(QApplication::applicationDirPath().toStdString());
    w.show();
    return a.exec();
}
