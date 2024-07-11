// There are 3 types of access modifiers in C++ : 1. Private(Default) 2. Public & 3. Protected
// There are 4 principles/pillars of OOPS : 1. Encapsulation 2. Abstraction 3. Inheritance & 4. Polymorphism
// Classes have properties(variables) & methods(functions)
// Encapsulation deals with making getter & setter class methods
// Abstraction means hiding complex details from the user
// The most common use of polymorphism is when a parent class reference is used to refer to a child class object
#include <iostream>
#include <string>
// #include <bits/stdc++.h>    // includes everything
using namespace std;

class AbstractEmployee
{
    // virtual void askForPromotion() = 0;
    virtual void askForPromotion()
    {
        cout << "This function is related to promotion of the employee\n";
    }
    // Any class which signs contract with this AbstractEmployee class has to implement askForPromotion function
};

class Employee : AbstractEmployee
{
    // Any variables/properties inside protected access modifier can be accessed from derived class or child class of Employee
protected:
    string name;

private:
    string company;
    int age;
    void introduceYourself()
    {
        cout << "Name: " << name << endl;
        cout << "Company: " << company << endl;
        cout << "Age: " << age << endl;
    }

public:
    void setName(string aName)
    {
        name = aName;
    }
    string getName()
    {
        return name;
    }
    void setCompany(string aCompany)
    {
        company = aCompany;
    }
    string getCompany()
    {
        return company;
    }
    void setAge(int aAge)
    {
        if (aAge >= 18) // employee age cannot be less than 18
            age = aAge;
    }
    int getAge()
    {
        return age;
    }
    // void introduceYourself()
    // {
    //     cout << "Name: " << name << endl;
    //     cout << "Company: " << company << endl;
    //     cout << "Age: " << age << endl;
    // }
    Employee(string aName, string aCompany, int aAge)
    {
        name = aName;
        company = aCompany;
        age = aAge;
        introduceYourself();
    }
    void askForPromotion()
    {
        if (age > 30)
        {
            cout << name << " got promoted!" << endl;
        }
        else
        {
            cout << name << ", sorry NO promotion for you!" << endl;
        }
    }
    virtual void work() // virtual specifies that check the definition for work function in derived class & execute that if it exists
    {
        cout << name << " is checking emails, task backlog, performing tasks..." << endl;
    }
};

class Developer : public Employee // Developer:Employee inheritance is private by default so use Developer: public Employee
{
private:
    string favPL;

public:
    void setPL(string pl)
    {
        favPL = pl;
    }
    string getPL()
    {
        return favPL;
    }
    Developer(string aName, string aCompany, int aAge, string PL) : Employee(aName, aCompany, aAge)
    // Since the Employee constructor already knows to create name, company & age we call it using the syntax as shown above
    {
        favPL = PL;
    }
    void fixBug()
    {
        cout << name << " fixed bug in " << getCompany() << " using " << getPL() << endl;
    }
    void work()
    {
        cout << name << " is writing code & performing automation tasks!" << endl;
    }
};

class Teacher : public Employee
{
    string subject; // by default subject variable becomes private

public:
    void prepareLesson()
    {
        cout << name << " is preparing " << subject << " lesson" << endl;
    }
    Teacher(string aName, string aCompany, int aAge, string aSubject) : Employee(aName, aCompany, aAge)
    {
        subject = aSubject;
    }
    void work()
    {
        cout << name << " is teaching " << subject << " to students!" << endl;
    }
};
int main()
{
    Employee e1("Naman", "K1 Technologies", 23);
    Employee e2 = Employee("Jignesh", "Pushti Sanitaryware", 54);
    Developer e3 = Developer("Prashin", "Google", 20, "Python");
    Teacher e4 = Teacher("Neeta", "Pushti Ceramics", 54, "English");

    // As introduceYourself() is a private method it is not accessible from the object
    // e2.introduceYourself();
    // Below will not change the age as employee age cannot be less than 18
    // e1.setAge(12);
    // cout << e1.getAge() << endl;

    // e1.introduceYourself();

    // e1.askForPromotion();
    // e2.askForPromotion();
    // e3.fixBug();
    // e3.askForPromotion();
    // e4.prepareLesson();
    // e4.askForPromotion();
    // e3.work();
    // e4.work();

    // Employee *d = &e3;
    // Employee *t = &e4;
    // d->work();
    // t->work();

    // Below given are reference variables
    Employee &d = e3;
    // Employee &t = e4;
    // // When you want to access members of a class using a pointer then instead of '.' use '->'
    // d.work();
    // t.askForPromotion();
    // t.setName("Neeta Parikh");
    // cout << t.getAge() << endl;
    // cout << t.getName() << endl;
    // cout << t.getCompany() << endl;
    // // t.introduceYourself();
    d.setName("Prashin Jignesh Parikh");

    // e3.introduceYourself();
    return 0;
}