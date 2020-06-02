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

public slots:	bool delContact(Contact* contact);

private slots:
    void on_actionAddContact_triggered();

    void on_actionSearchMode_Name_triggered();

private:
    std::set<Contact*> contacts;
    Ui::Book *ui;

};
#endif // BOOK_H
