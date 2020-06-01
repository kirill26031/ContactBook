#ifndef STRING
#include <string>
#include <iostream>
#define STRING
#endif

#ifndef SET
#include <set>
#define SET
#endif

class Name
{
public:
	Name(std::string s);
	~Name();
	Name(const Name&);
	Name& operator=(const Name&);
	bool operator==(const Name& other) const;
	bool operator< (const Name& e) const;
	std::string print() const { return record; }
	static void addUsage(std::string s);
	static void deleteUsage(std::string s);
	static bool used(std::string s);
	static std::string default_name;
private:
	std::string record;
	static std::set<std::string> used_names;
};

