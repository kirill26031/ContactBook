#include "Contact.h"

std::map<Phone, Contact*> Contact::phone_owner;

Contact::Contact(const Name& _name):name(_name),phones(std::set<Phone*>())
{
	if (Name::used(name.print())) throw Contact::BadName(name.print());
    Name::addUsage(name.print());
}

Contact::Contact(const Contact & contact):name(contact.getName()), phones(contact.getPhones())
{

}

Contact & Contact::operator=(const Contact &other)
{
	name=other.getName();
	phones = other.getPhones();
	return *this;
}

Contact::~Contact()
{
	//Name::deleteUsage(name.print());
}


void Contact::deleteUsage() const
{
	Name::deleteUsage(name.print());
    for (Phone* p : phones) Phone::deleteUsage(p->print());
}

bool Contact::addPhone(Phone* phone)
{
    if (Phone::used(phone->print()) || !Phone::correct(phone->print())) return false;
    Phone::addUsage(phone->print());
    phones.insert(phone);
    Contact::phone_owner.insert(std::pair<Phone, Contact*>(*phone, this));
	return true;
}

bool Contact::delPhone(Phone* phone)
{
	if (phones.find(phone) == phones.end()) return false;
	phones.erase(phone);
    Phone::deleteUsage(phone->print());
	Contact::phone_owner.erase(*phone);
    return true;
}

bool Contact::delPhone(std::string phone)
{
    for(Phone* i : phones){
        if(i->print()==phone){
            return delPhone(i);
        }
    }
    return false;
}

bool Contact::operator<(const Contact & contact) const
{
    return name < contact.getName();
}

std::string Contact::print()
{
    std::string res("Name: "+name.print());
    for(Phone* phone : phones){
        res+="\n\t"+phone->print();
    }
    return res;
}
