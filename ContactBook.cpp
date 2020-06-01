#include "ContactBook.h"

ContactBook::ContactBook():contacts(std::set<Contact>())
{
}

ContactBook::~ContactBook()
{
}

bool ContactBook::addContact(std::string s)
{
	try {
		Name name(s);
		Contact contact(name);
		contacts.insert(contact);
	}
	catch (const Contact::BadName& error) {
		return false;
	}
	return true;
}

bool ContactBook::delContact(std::string name)
{
	for (const Contact& c : contacts) {
		if (c.getName().print() == name) {
			c.deleteUsage();
			contacts.erase(c);
			return true;
		}
	}
	return false;
}

void ContactBook::addContact(Contact& contact)
{
	contacts.insert(contact);
}

bool ContactBook::delContact(const Contact & contact)
{
	auto i = contacts.find(contact);
	if (i == contacts.end()) return false;
	i->deleteUsage();
	contacts.erase(i);
	return true;
}

const Contact & ContactBook::searchName(std::string name)
{
	for (const Contact& c : contacts) {
		if (c.getName().print() == name) return c;
	}
	return Contact::empty;
}

const Contact & ContactBook::searchPhone(std::string phone)
{
	auto found = Contact::phone_owner.find(Phone(phone));
	if(found == Contact::phone_owner.end())	return Contact::empty;
	return found->second;
}
