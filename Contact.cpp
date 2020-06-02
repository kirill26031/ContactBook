#include "Contact.h"
#include "ui_contact.h"

std::map<Phone, Contact> Contact::phone_owner;

Contact::Contact(const Name& _name, QWidget *parent):QWidget(parent),
    name(_name),phones(std::set<Phone>()), ui(new Ui::Contact)
{
	if (Name::used(name.print())) throw Contact::BadName(name.print());
	if(_name.print()!=Name::default_name) Name::addUsage(name.print());
   setupUI();
}

Contact::Contact(const Contact & contact):
    name(contact.getName()), phones(contact.getPhones()), ui(contact.getUI())
{}

Contact & Contact::operator=(const Contact &other)
{
	name=other.getName();
	phones = other.getPhones();
	return *this;
}

Contact::~Contact()
{
    delete ui;
}


void Contact::deleteUsage() const
{
	Name::deleteUsage(name.print());
	for (const Phone& p : phones) Phone::deleteUsage(p.print());
}

bool Contact::addPhone(const Phone& phone)
{
	if (Phone::used(phone.print()) || !Phone::correct(phone.print())) return false;
	Phone::addUsage(phone.print());
	phones.insert(phone);
	Contact::phone_owner.insert(std::pair<Phone, Contact>(phone, *this));
	return true;
}

bool Contact::delPhone(const Phone& phone)
{
	if (phones.find(phone) == phones.end()) return false;
	phones.erase(phone);
	Phone::deleteUsage(phone.print());
	Contact::phone_owner.erase(phone);
	return true;
}

bool Contact::operator<(const Contact & contact) const
{
    return name < contact.getName();
}

void Contact::setupUI()
{
    ui->setupUi(this);
    ui->name->setText(QString(name.print().data()));

}
