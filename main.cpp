#include "book.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Book w;
    w.addContact("Kyrylo");
    w.addContact("Kyryl");
    w.addContact("Kyry");
    w.addContact("Kyr");
    w.addContact("Ky");
    w.addContact("Bingo!");
    w.show();
    return a.exec();
}
