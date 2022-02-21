#ifndef NAILTECHNICIAN_H
#define NAILTECHNICIAN_H
\
#include <employee.h>

class NailTechnician : public Employee
{
public:
    NailTechnician();
    NailTechnician(string type, string acc, string name, string birthday, string add)
        : Employee(type, acc, name, birthday, add)
    {

    }
    ~ NailTechnician();
    void outputEmployee();

private:

};

#endif // NAILTECHNICIAN_H
