#ifndef CONTACT_H
#define CONTACT_H

#include  "Name.h"
#include "Phone.h"

#include <map>
#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Contact; }
QT_END_NAMESPACE

class Contact: public QWidget
{
    Q_OBJECT

public:
    Contact(const Name& name, QWidget *parent = nullptr);
	Contact(const Contact& contact);
	Contact& operator=(const Contact&);
	~Contact();
	class BadName {
	public:
		BadName(std::string _record) :record(_record) {}
		~BadName() {}
		BadName(const BadName& bad_name) :record(bad_name.record){}
		std::string record;
		std::string show() const { return std::string("Name " + record + " already used!"); }
	private:
		
		BadName& operator=(const BadName&);
	};
	Name getName() const { return name; }
	void deleteUsage() const;
	const std::set<Phone>& getPhones() const { return phones; }
	bool addPhone(const Phone& phone);
	bool delPhone(const Phone& phone);
    bool operator< (const Contact& contact) const;
    static std::map<Phone, Contact> phone_owner;
    Ui::Contact* getUI() const {return ui;}
signals:
    void deleteContact_signal(Contact* contact);
private slots:
    void on_actionaddPhone_triggered();
    void on_actionDeleteContact_triggered();

private:
    void setupUI();
	Name name;
	std::set<Phone> phones;
    Ui::Contact *ui;
};

#endif
