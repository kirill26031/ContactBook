#include "task.h"

Task::Task(QObject* parent) : QObject(parent), qout(stdout), qin(stdin),
greeting("Input your command\nFor help, type: 'help'"), book(new ContactBook), current(0)
{
    Contact* K(new Contact(Name("Kyrylo")));
    K->addPhone(new Phone("03331"));
    K->addPhone(new Phone("0231"));
    K->addPhone(new Phone("11"));
    Contact* S(new Contact(Name("Sam")));
    S->addPhone(new Phone("1111"));
    book->addContact(K);
    book->addContact(S);
}

void Task::run()
{
    qout<<greeting.data()<<endl;
    if(current==0) greeting.clear();
    std::string input;
    std::getline(std::cin, input, '\n');
    QStringList qls(QString(input.data()).split(' '));
    if(!qls.isEmpty()){
    if(qls.at(0)=="help") help(qls);
    else if(qls.at(0)=="contact") contact(qls);
    else if(qls.at(0)=="phone") phone(qls);
    else if(qls.at(0)=="search") search(qls);
    else if(input=="stop") emit finished();
    else{
        qout<<"Your input is incorrect: \""<<input.data()<<'\"'<<endl;
    }
    }
    if(input!="stop") run();
}

void Task::help(const QStringList list)
{

}

void Task::contact(const QStringList list)
{
    bool correct=true;
    if(list.size()>1){
        if(list.size()>2){
            std::string name = list.at(2).toStdString();
            if(name.at(0)=='\"' && name.at(name.size()-1)=='\"'){
                name=name.substr(1,name.size()-2);
            }
            if(list.at(1)=="add"){
                try {
                    Contact* new_c(new Contact(Name(name)));
                    book->addContact(new_c);
                    for(int i=3;i<list.size();++i){
                        Phone* phone(new Phone(list.at(i).toStdString()));
                        new_c->addPhone(phone);
                    }
                    current=new_c;
                    qout<<"\nAdded contact:";
                } catch (const Contact::BadName& error) {
                    qout<<error.show().data();
                }
            }
            else if(list.at(1)=="delete"){
                if(book->delContact(name)){
                    qout<<"\nContact "<<name.data()<<" deleted.";
                }
                else qout<<"\nContact "<<name.data()<<" not found!";
            }
            else if(list.at(1)=="go"){
                current=book->searchName(name);
                if(current!=0){
                    greeting=current->print();
                }
                else{
                    qout<<"We don't have contact with name: "<<name.data()<<endl;
                }
            }
            else correct=false;
        }
        else if(list.at(1)=="all"){
            for(Contact* contact : book->contacts){
                qout<<contact->getName().print().data()<<endl;
            }
        }
        else correct=false;
    }
    if(list.size()==1 || !correct){
        qout<<"To show all used contact names, type 'contact all'"<<
           "\nTo add new contact, type 'contact add <name> [<phone1> <phone2> ...]'"<<
           "\nTo delete contact type 'contact delete <name>'"<<
           "\nTo navigate yourself to contact type 'contact go <name>'"<<
           "\nIf your <name> has ' ', use braces \"\""<<endl;
    }
}

void Task::phone(const QStringList list)
{

}

void Task::search(const QStringList list)
{

}

void Task::showAll()
{
    for(Contact* contact : book->contacts){
        qout<<contact->print().data()<<endl;
    }
}
