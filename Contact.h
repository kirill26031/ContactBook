#include  "Name.h"
#include "Phone.h"

#include <map>

class Contact
{
public:
	Contact(const Name& name);
	Contact(const Contact& contact);
	Contact& operator=(const Contact&);
	~Contact();
	class BadName {
	public:
		BadName(std::string _record) :record(_record) {}
		~BadName() {}
		BadName(const BadName& bad_name) :record(bad_name.record){}
		std::string record;
        std::string show() const { return std::string("\nName " + record + " already used!"); }
	private:
		
		BadName& operator=(const BadName&);
	};
	Name getName() const { return name; }
	void deleteUsage() const;
    const std::set<Phone*>& getPhones() const { return phones; }
    bool addPhone(Phone* phone);
    bool delPhone(Phone* phone);
    bool delPhone(std::string phone);
    bool operator< (const Contact& contact) const;
    static std::map<Phone, Contact*> phone_owner;
    std::string print();
private:
	Name name;
    std::set<Phone*> phones;
};

