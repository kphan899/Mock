#include "display.h"
#include <iostream>

using namespace std;

Display::Display()
{

}

void Display::loginMenu()
{

    cout << "WELCOME SPA MANAGEMENT SYSTEM MENU !" << endl;
    cout << "Menu:" << endl;
    cout << "[1] Login." << endl;
    cout << "[0] Exit." << endl;
    cout << "Enter your choice (integer): " ;
}

void Display::mainMenu()
{
    cout << "**********MAIN MENU**********" << endl;
    cout << "[1]: Go to Employee Mangement." << endl;
    cout << "[2]: Go to Payroll Mangement." << endl;
    cout << "[3]: Change password." << endl;
    cout << "[0]: Exit." << endl;
    cout << "Enter your choice (integer): " ;
}

void Display::empManaMenu()
{
    cout << "**********EMPLOYEE MANAGEMENT MENU**********" << endl;
    cout << "[1]: Print all employee’s information." << endl;
    cout << "[2]: Add new employee." << endl;
    cout << "[3]: Remove an employee by id." << endl;
    cout << "[4]: Update information an employee by id." << endl;
    cout << "[5]: Search information an employee by id." << endl;
    cout << "[0]: Exit." << endl;
    cout << "Enter your choice (integer): " ;
}

void Display::payrollManage()
{
    cout << "**********PAYROLL MANAGEMENT MENU**********" << endl;
    cout << "[1]: Input payroll for employee." << endl;
    cout << "[2]: Calculate salary and profit." << endl;
    cout << "[0]: Exit." << endl;
    cout << "Enter your choice (integer): " ;
}

void Display::updateEmpMenu()
{
    cout << "**********UPDATE EMPLOYEE MENU**********" << endl;
    cout << "[1]: Update Name." << endl;
    cout << "[2]: Update Address." << endl;
    cout << "[3]: Update Day of Birth." << endl;
    cout << "[0]: Exit." << endl;
    cout << "Enter your choice (integer): " ;
}
