#include "manager.h"

Manager::Manager()
{

}

Manager::~Manager()
{

}

int Manager::getCoefSalary() const
{
    return  m_coefSalary;
}

void Manager::setCoefSalary(int coefSalary)
{
    m_coefSalary = coefSalary;
}

void Manager::outputEmployee()
{
    Employee::outputEmployee();
    cout << m_coefSalary << " ||"<< endl ;
}
