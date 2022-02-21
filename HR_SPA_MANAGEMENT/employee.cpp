#include "employee.h"
#include <string>
#include <iostream>

using namespace std;

Employee::Employee()
{

}

Employee::~Employee()
{

}

string Employee::getAccount() const
{
    return m_account;
}

string Employee::getFullname() const
{
    return m_fullName;
}

string Employee::getBirthday() const
{
    return m_birthday;
}

string Employee::getAddress() const
{
    return m_address;
}

string Employee::getType() const
{
    return m_type;
}

int Employee::getSalary() const
{
    return m_salary;
}

void Employee::setType(string param_type)
{
    m_type = param_type;
}

void Employee::setAcccount(string param_account)
{
    m_account = param_account;
}

void Employee::setFullname(string param_fullname)
{
    m_fullName = param_fullname;
}

void Employee::setBirthday(string param_birthday)
{
    m_birthday = param_birthday;
}

void Employee::setAddress(string param_address)
{
    m_address = param_address;
}

void Employee::setSalary(int param_salary)
{
    m_salary = param_salary;
}

void Employee::outputEmployee()
{
   cout << "|| " << getAccount()  << " || " << getFullname()   << " || " << getAddress()    << " || " << getBirthday()   << " || " << getType()<< " || " ;

}
