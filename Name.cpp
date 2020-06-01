#include "Name.h"

std::set<std::string> Name::used_names;
std::string Name::default_name("");
Name::Name(std::string s):record(s)
{
	/*if (used(s)) throw new Name::BadName(s);
	Name::used_names.insert(std::pair<std::string, unsigned int>(s, 1));*/
	std::cout << "\nCreated Name: " << record;
}

Name::~Name()
{
	/*unsigned int used_amount = used_names.find(record)->second;
	used_names.erase(record);
	if (used_amount != 1) Name::used_names.insert(std::pair<std::string, unsigned int>(record, used_amount - 1));*/
	std::cout << "\nDeleted Name: " << record;
}

Name::Name(const Name & name):record(name.print())
{
	/*unsigned int used_amount = used_names.find(record)->second;
	used_names.erase(record);
	if (used_amount != 1) Name::used_names.insert(std::pair<std::string, unsigned int>(record, used_amount + 1));*/
	std::cout << "\nCopied Name: " << record;
}

Name & Name::operator=(const Name &other)
{
	record = other.print();
	std::cout << "\nCopied= Name: " << record;
	return *this;
}

bool Name::operator==(const Name & other) const
{
	return record == other.print();
}

bool Name::operator<(const Name & e) const
{
	return record.compare(e.print()) < 0;
}

void Name::addUsage(std::string s)
{
	used_names.insert(s);
}

void Name::deleteUsage(std::string s)
{
	used_names.erase(s);
}

bool Name::used(std::string s)
{
	if (used_names.size() == 0) return false;
	return !(used_names.find(s) == used_names.end());
}
