#include "book.h"
#include "ui_book.h"

Book::Book(QWidget *parent)
    : QMainWindow(parent), contacts(std::set<Contact*>())
    , ui(new Ui::Book)
{
    ui->setupUi(this);

}

Book::~Book()
{
    delete ui;
}

bool Book::addContact(std::string s)
{
    try {
        Name name(s);
        Contact* contact = new Contact(name,ui->scrollAreaWidgetContents);
        QObject::connect(contact, &Contact::deleteContact_signal,
                         this, &Book::delContact);
        ui->scrollLayout->addWidget(contact);
        contacts.insert(contact);
    }
    catch (const Contact::BadName& error) {
        return false;
    }
    return true;
}

bool Book::delContact(Contact* contact)
{
    std::cout<<"And Here";
    ui->scrollLayout->removeWidget(contact);
    auto i = contacts.find(contact);
    if (i == contacts.end()) return false;
    (*i)->deleteUsage();
    contacts.erase(i);
    return true;
}

void Book::searchName(std::string name)
{
//    for (Contact* c : contacts) {
//        if (c->getName().print() != name) c->hide();
//    }
}

void Book::searchPhone(std::string phone)
{
//    auto found = Contact::phone_owner.find(Phone(phone));
//    if(found == Contact::phone_owner.end())	return Contact::empty;

}

void Book::on_actionAddContact_triggered()
{

}

void Book::on_actionSearchMode_Name_triggered()
{

}
