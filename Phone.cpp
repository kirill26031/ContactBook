#include "Phone.h"

std::set<std::string> Phone::used_phones;

Phone::Phone(std::string s) :record(s)
{
}

Phone::~Phone()
{
}

Phone::Phone(const Phone & name) :record(name.print())
{
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

bool Phone::operator==(const Phone &phone)
{
    return record==phone.print();
}
