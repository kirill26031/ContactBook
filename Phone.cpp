#include "Phone.h"

std::set<std::string> Phone::used_phones;

Phone::Phone(std::string s) :record(s)
{
	//if (!correct(s)) throw new Phone::BadPhone(s, 1);
	//Phone::used_phones.insert(std::pair<std::string, unsigned int>(s, 1));
//	std::cout << "\nCreated Phone: " << record;
}

Phone::~Phone()
{
	/*unsigned int used_amount = used_phones.find(record)->second;
	used_phones.erase(record);
	if (used_amount != 1) Phone::used_phones.insert(std::pair<std::string, unsigned int>(record, used_amount - 1));*/
//	std::cout << "\nDeleted Phone: " << record;
}

Phone::Phone(const Phone & name) :record(name.print())
{
	/*unsigned int used_amount = used_phones.find(record)->second;
	used_phones.erase(record);
	if (used_amount != 1) Phone::used_phones.insert(std::pair<std::string, unsigned int>(record, used_amount + 1));*/
//	std::cout << "\nCopied Phone: " << record;
}

bool Phone::operator<(const Phone & e) const
{
	return record.compare(e.print()) < 0;
}

bool Phone::used(std::string s)
{
	return !(used_phones.find(s) == used_phones.end());
}

bool Phone::correct(std::string number)
{
	for (char & c : number) {
		if (c<'0' || c>'9') return false;
	}
	return true;
}

void Phone::addUsage(std::string s)
{
	used_phones.insert(s);
}

void Phone::deleteUsage(std::string s)
{
	used_phones.erase(s);
}
