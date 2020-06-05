#include "ContactBook.h"

ContactBook::ContactBook():contacts(std::set<Contact*>())
{
}

ContactBook::~ContactBook()
{
}

bool ContactBook::addContact(std::string s)
{
	try {
		Name name(s);
        Contact* contact(new Contact(name));
		contacts.insert(contact);
	}
	catch (const Contact::BadName& error) {
		return false;
	}
	return true;
}

bool ContactBook::delContact(std::string name)
{
    for (Contact* c : contacts) {
        if (c->getName().print() == name) {
            c->deleteUsage();
			contacts.erase(c);
			return true;
		}
	}
	return false;
}

void ContactBook::addContact(Contact* contact)
{
	contacts.insert(contact);
}

bool ContactBook::delContact(Contact* contact)
{
	auto i = contacts.find(contact);
	if (i == contacts.end()) return false;
    (*i)->deleteUsage();
	contacts.erase(i);
	return true;
}

Contact * ContactBook::searchName(std::string name)
{
    for (Contact* c : contacts) {
        if (c->getName().print() == name) return c;
	}
    return 0;
}

Contact* ContactBook::searchPhone(std::string phone)
{
    auto found = Contact::phone_owner.find(new Phone(phone));
    if(found == Contact::phone_owner.end())	return 0;
    return (*found).second;
}

