#include <iostream>
#include <string>

using namespace std;

class Person
{
private:
    string id;
    string name;
    string lastName;
    string birthDay;
    string gender;
    string phone;
    string secure;
    Person *next;

public:
    Person();
    Person(string id, string name, string lastName, string birthDay, string gender, string phone, string secure);
    void setId(string id);
    void setName(string name);
    void setLastName(string lastName);
    void setBirthDay(string birthDay);
    void setGender(string gender);
    void setPhone(string phone);
    void setSecure(string secure);
    void setNext(Person *next);
    string getId();
    string getName();
    string getLastName();
    string getBirthDay();
    string getGender();
    string getPhone();
    string getSecure();
    Person *getNext();
    void insertPacients(Person *&Pacient, string id, string name, string lastName, string birthDay, string getGender, string phone, string secure);
    void printPacients();
};

Person ::Person() {}

Person ::Person(string id, string name, string lastName, string birthDay, string gender, string phone, string secure)
{
    this->id = id;
    this->name = name;
    this->lastName = lastName;
    this->birthDay = birthDay;
    this->gender = gender;
    this->phone = phone;
    this->secure = secure;
}

Person *Person ::getNext()
{
    return next;
}

void Person ::setId(string id)
{
    this->id = id;
}

void Person ::setName(string name)
{
    this->name = name;
}

void Person ::setLastName(string lastName)
{
    this->lastName = lastName;
}

void Person ::setBirthDay(string birthDay)
{
    this->birthDay = birthDay;
}

void Person ::setGender(string gender)
{
    this->gender = gender;
}

void Person ::setPhone(string phone)
{
    this->phone = phone;
}

void Person ::setSecure(string secure)
{
    this->secure = secure;
}

void Person ::setNext(Person *next)
{
    this->next = next;
}

string Person ::getId()
{
    return id;
}

string Person ::getName()
{
    return name;
}

string Person ::getLastName()
{
    return lastName;
}

string Person ::getBirthDay()
{
    return birthDay;
}

string Person ::getGender()
{
    return gender;
}

string Person ::getPhone()
{
    return phone;
}

string Person ::getSecure()
{
    return secure;
}

void Person ::insertPacients(Person *&Pacient, string id, string name, string lastName, string birthDay, string gender, string phone, string secure)
{
    Person *newNode = new Person();
    newNode->id = id;
    newNode->name = name;
    newNode->lastName = lastName;
    newNode->birthDay = birthDay;
    newNode->gender = gender;
    newNode->phone = phone;
    newNode->secure = secure;
    newNode->next = nullptr;

    if (Pacient == nullptr || Pacient->name > name)
    {
        newNode->next = Pacient;
        Pacient = newNode;
    }
    else
    {
        Person *current = Pacient;
        while (current->next != nullptr && current->next->name < name)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void Person :: printPacients(){

    Person *current = list;

    if(current == nullptr){
        cout << "There's no pacients in the hospital" << endl;
    }else{
        while(current != nullptr){
            cout << "ID: " << current->id << endl;
            cout << "Name: " << current->name << endl;
            cout << "Last Name: " << current->lastName << endl;
            cout << "Birth Day: " << current->birthDay << endl;
            cout << "Gender: " << current
        }
    }
}

