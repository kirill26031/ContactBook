#include "Contact.h"
class ContactBook
{
public:
	ContactBook();
	~ContactBook();
	std::set<Contact> contacts;
	bool addContact(std::string name);
	bool delContact(std::string name);
	void addContact(Contact& contact);
	bool delContact(const Contact& contact);
	const Contact& searchName(std::string name);
	const Contact& searchPhone(std::string phone);
private:
	ContactBook(const ContactBook&);
	ContactBook& operator=(const ContactBook&);
};

