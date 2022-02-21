#ifndef MANAGER_H
#define MANAGER_H

#include<employee.h>
#include <string>

class Manager : public Employee
{
public:
    Manager();
    Manager(string type, string acc, string name, string birthday, string add, int coefSalary)
        : Employee(type, acc, name, birthday, add) , m_coefSalary{coefSalary}
    {

    }
    ~Manager();

    void outputEmployee();

    int getCoefSalary() const;
    void setCoefSalary(int coefSalary);
private:
    int m_coefSalary;
};

#endif // MANAGER_H
