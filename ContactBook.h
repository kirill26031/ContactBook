#include "Contact.h"
class ContactBook
{
public:
	ContactBook();
	~ContactBook();
    std::set<Contact*> contacts;
	bool addContact(std::string name);
	bool delContact(std::string name);
    void addContact(Contact* contact);
    bool delContact(Contact* contact);
    Contact* searchName(std::string name);
    Contact* searchPhone(std::string phone);
private:
	ContactBook(const ContactBook&);
	ContactBook& operator=(const ContactBook&);
};

