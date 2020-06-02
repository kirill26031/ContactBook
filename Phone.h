#ifndef PHONE_H
#define PHONE_H

#ifndef STRING
#include <string>
#include <iostream>
#define STRING
#endif

#ifndef SET
#include <set>
#define SET
#endif

class Phone
{
public:
	Phone(std::string s);
	~Phone();
	Phone(const Phone&);
	bool operator< (const Phone& e) const;
	std::string print() const { return record; }
	/*class BadPhone {
	public:
		BadPhone(std::string _record, int _reason) :record(_record), reason(_reason){}
		~BadPhone() {}
		std::string record;
		int reason;
		std::string show();
	private:
		BadPhone(const BadPhone&);
		BadPhone& operator=(const BadPhone&);
	};*/
	static bool used(std::string s);
	static bool correct(std::string number);
	static void addUsage(std::string s);
	static void deleteUsage(std::string s);
private:
	std::string record;
	static std::set<std::string> used_phones;
	Phone& operator=(const Phone&);
	
};

#endif
