#include "management.h"
#include <iostream>
#include <date.h>
#include <string>
#include <cstring>
#include <ctime>
#include <unistd.h>

using namespace std;

Management::Management()
{

}

Management::~Management()
{

}

void Management::Init()
{
    listEmploy = new list<Employee*>;
}

void Management::addNewEmp()
{
   // system("clear");
    system("cls");
    cout << "**************ADD NEW EMPLOYEE**************" << endl;
    Employee *emp ;
    int check = 2;
    string type;
    cin.ignore();
    do
    {
        cout << "Enter Employee Type (0:Nail Technician, 1: Manager): "; getline(cin, type);
        if (type == "0"){
            check = 0;
        }else if(type == "1") {
            check = 1;
        } else{
            check =2;
        }
    }while(check == 2);

    switch (check) {
    case 1:
        emp=newManager();
        if(emp == nullptr){
            break;
        }else{

            listEmploy->push_back(emp);
        }
        break;
    case 0:
        emp=newNailTechinician();
        if(emp == nullptr){
            break;
        }else{

            listEmploy->push_back(emp);
        }
        break;
    }
}

void Management::printInfor()
{

    cout << "DANH SACH NHAN VIEN" << endl;
    cout << "|| ID || Full Name || Address || Brithday || Type ||" << endl;

    for (Employee *emp : *listEmploy)
    {
        cout << "|| " << emp->getAccount()
             << " || " << emp->getFullname()
             << " || " << emp->getAddress()
             << " || " << emp->getBirthday()
             << " || " << emp->getType() << " ||" <<endl;
    }
}

Manager *Management::newManager()
{
    int check, salary;
    string  name, add, birth, id;
    string flag;
    Manager *tempNV = new Manager();
    //cin.ignore();
    tempNV->setType("Manager");

    //---------------------------------------------------

    do
    {

        cout << "Enter id: "; getline(cin, id);
        check = searchEmp(id);
        if (check == 0){
            do
            {

                cout << "Continude (1); Back to Employee Menu (0) "; getline(cin,flag);

            }while(flag !="1"
                   && flag != "0");
        }

        if (flag == "0") {
            return nullptr;
        }
    }while(flag == "1" && check ==0 );

    tempNV->setAcccount(id);

    //----------------------------------------------------

    cout << "Enter Employee Name: "; getline(cin, name);
    tempNV->setFullname(name);

    //----------------------------------------------------

    cout << "Enter Employee Address: "; getline(cin, add);
    tempNV->setAddress(add);

    //----------------------------------------------------


    tempNV->setBirthday(setDate());

    //----------------------------------------------------

    do{
        cout << "Enter Salary per hour (unit $): ";
        cin >> salary;
    }while(cin.fail() !=0 );

    tempNV->setCoefSalary(salary);

    //----------------------------------------------------

    return tempNV;
}

NailTechnician *Management::newNailTechinician()
{
    int check;
    string  name, add, birth, id;
    string flag;
    NailTechnician *tempNV = new NailTechnician();
    //cin.ignore();
    tempNV->setType("Nail Technician");

    //---------------------------------------------------

    do
    {

        cout << "Enter id: "; getline(cin, id);
        check = searchEmp(id);
        if (check == 0){
            do
            {

                cout << "Continude (1); Back to Employee Menu (0) "; getline(cin,flag);

            }while(flag !="1"
                   && flag != "0");
        }

        if (flag == "0") {
            return nullptr;
        }
    }while(flag == "1" && check ==0 );

    tempNV->setAcccount(id);

    //----------------------------------------------------

    cout << "Enter Employee Name: "; getline(cin, name);
    tempNV->setFullname(name);

    //----------------------------------------------------

    cout << "Enter Employee Address: "; getline(cin, add);
    tempNV->setAddress(add);

    //----------------------------------------------------


    tempNV->setBirthday(setDate());

    //----------------------------------------------------pp

    return tempNV;
}

void Management::updateInfo(string strId, int check )
{
    int position = 0;
    string strUpdate;
    for (Employee *emp : *listEmploy)
    {
        position ++ ;
        if(emp->getAccount() == strId){
            cin.ignore();
            if (check == 1){
                cout << "Enter Employee Name: "; getline(cin, strUpdate);
                emp->setFullname(strUpdate);
            }else if(check == 2) {
                cout << "Enter Employee Address: "; getline(cin, strUpdate);
                emp->setAddress(strUpdate);
            }else if (check == 3){

                emp->setBirthday(setDate());
            }
            break;
        }
    }

}

void Management::removeEmp(string strId)
{


    for (Employee *emp : *listEmploy)
    {

        if(emp->getAccount() == strId){
            listEmploy->remove(emp);
            break;
        }
    }


}

void Management::serchPrintEmp(string strId)
{

    for (Employee *emp : *listEmploy)
    {

        if(emp->getAccount() == strId){

            cout << "|| ID || Full Name || Address || Brithday || Type || ";
            if (emp->getType() == "Manager"){
                cout << " Salary ||" << endl;
            }else{
                cout << endl;
            }
            emp->outputEmployee();

            break;
        }
    }


}

bool Management::searchEmp(string strId)
{
    for (Employee *emp : *listEmploy)
    {
        if(emp->getAccount() == strId){
            return 0;
        }
    }
    return 1;
}

Employee *Management::getEmploy(int index)
{
    int count =1;
    for (list<Employee*>::iterator emp = listEmploy->begin(); emp != listEmploy->end(); emp++) {
        if(count == index)
            return *emp;
    }
    return  nullptr;
}

int Management::payrollInput()
{
    int check;
    Date inpDate;
    string strID;
    int salary;
    cout << "*************Payroll input Manager Menu*****" << endl;
    cout << "Enter Date (Fomat yyyy-mm-dd:) ";
    check = inpDate.inputDate();
    if( check == 1){
        cout <<"Invalid date!" << endl;
        return 0;
    }
    cin.ignore();
    cout << "Enter Employee id:"; getline(cin, strID);


    for (Employee *emp : *listEmploy)
    {

        if(emp->getAccount() == strID){

          if(emp->getType() == "Manager"){

              Manager *d = dynamic_cast<Manager *>(emp);

              system("clear");
              system ("cls");

              cout << "*************Payroll input Manager Menu*****" << endl;
              do{
                  cout << "Enter Salary per hour (unit $): ";
                  cin >> salary;
              }while(cin.fail() !=0 );

              emp->setSalary(d->getCoefSalary()*salary);
              cout << emp->getSalary();

              return 1;

          }else if(emp->getType() == "Nail Technician"){

              int totalBill =0;
              int totalTip =0;
              int bill, tip;

              NailTechnician *d = dynamic_cast<NailTechnician *>(emp);

              system("clear");
              system ("cls");

              cout << "*************Payroll input Manager Menu*****" << endl;
              cout << "Enter money (spilit + by each reeceipt,unit $), no space between words: ";
              do{
                  cin >> bill;
                  totalBill += bill;
                  if(cin.get() != '+')
                   {
                      cout << "invalid input!" << endl;
                      return 0;
                   }
              }while(1 );

              cout << "Enter tips (spilit + by each reeceipt,unit $), no space between words: ";
              do{
                  cin >> tip;
                  totalTip += tip;
                  if(cin.get() != '+')
                   {
                      cout << "invalid input!" << endl;
                      return 0;
                   }
              }while(1 );

              cout << emp->getSalary();
              return 1;
          }


        }
    }
 return 1;

}


string Management::setDate()
{
    int check;
    Date inpDate;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    do
    {
        cout << "Enter Employee birth(yyyy-mm-dd): ";

        check = inpDate.inputDate();
        int age = (1900 + ltm->tm_year) - inpDate.getYear();
        if(( age < 18) || (age > 55 ) ){
            check = 1;
            cout << "Invalid Age!" << endl;
        }
    }while(check == 1);

    return inpDate.getStrDate();
}
