#ifndef MANAGEMENT_H
#define MANAGEMENT_H

#include<iostream>
#include<employee.h>
#include<nailtechnician.h>
#include<manager.h>
#include<list>
#include <vector>
using namespace std;
enum{
    Mana = 0,
    NailTech = 1
};
class Management
{
public:
    Management();
    ~Management();

    void Init();
    void addNewEmp();
    void printInfor();
    void removeEmp(string strId);
    bool searchEmp(string strId);
    void serchPrintEmp(string strId);
    void updateInfo(string strId, int check);
    int payrollInput();

    Employee *getEmploy(int index);


    Manager *newManager();
    NailTechnician *newNailTechinician();

    string setDate();

private:
    list<Employee*> *listEmploy;

};

#endif // MANAGEMENT_H
