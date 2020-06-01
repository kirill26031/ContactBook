#ifndef BOOK_H
#define BOOK_H

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

private:
    Ui::Book *ui;
};
#endif // BOOK_H
