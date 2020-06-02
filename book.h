#ifndef BOOK_H
#define BOOK_H
#include "Contact.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class Book; }
QT_END_NAMESPACE

class Book : public QMainWindow
{
    Q_OBJECT

public:
    Book(QWidget *parent = nullptr);
    ~Book();
    bool addContact(std::string name);
    void searchName(std::string name);
    void searchPhone(std::string phone);

public slots:	bool delContact(const Contact& contact);

private:
    std::set<Contact> contacts;
    Ui::Book *ui;

};
#endif // BOOK_H
