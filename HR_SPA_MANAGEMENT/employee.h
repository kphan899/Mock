#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <date.h>

using namespace std;

class Employee
{
public:

    string getAccount() const ;
    string getFullname() const;
    string getBirthday() const;
    string getAddress() const;
    string getType() const;
    int getSalary() const;

    void setAcccount(string param_account);
    void setFullname(string param_fullname);
    void setBirthday(string param_birthday);
    void setAddress(string param_address);
    void setType(string param_type);
    void setSalary(int param_salary);

    virtual void outputEmployee();

    Employee();
    Employee(string type, string acc, string name, string birthday, string add)
        : m_type{type}, m_account{acc}, m_fullName{name}, m_birthday{birthday}, m_address{add}{ }
    ~Employee();
protected:
    string m_type;
    string m_account;
    string m_fullName;
    string m_birthday;
    string m_address;
    int m_salary;

};

#endif // EMPLOYEE_H
