#include <iostream>
#include <loginmanagement.h>
#include <display.h>
#include <management.h>
#include <unistd.h>
#include <string>

using namespace std;

Display dp;
Management *management;

int checkOptions(string param_choice);
void welcomeMenu();
void loginMenu();
void MainMenu();
void EmpManaMenu();
void PayrollManaMenu();
void updateEmployMenu(string str);


int main()
{

    management = new Management();
    management->Init();

    welcomeMenu();


    return 0;
}

int checkOptions(string param_choice)
{
    if ( param_choice == "1" ){
        return 1;
    }else if ( param_choice == "0" ){
        return 0;
    }else if ( param_choice == "2" ){
        return 2;
    }else if ( param_choice == "3" ){
        return 3;
    }else if ( param_choice == "4" ){
        return 4;
    }else if ( param_choice == "5" ){
        return 5;
    }

    return 6;
}

void welcomeMenu()
{
    string choice;

    do
    {
        system("clear");
        system ("cls");
        dp.loginMenu();
        cin >> choice;

    }while ( checkOptions(choice)!=1
             && checkOptions(choice)!=0);


    switch (checkOptions(choice)) {
    case 1:
        loginMenu();
        break;
    case 0:
        break;
    };

}

void loginMenu(){
    string username;
    string password;

    system("clear");
    system ("cls");
    cout << "***********LOGIN MENU**********" << endl;
    cout << "Username: "; cin>> username;
    cout << "Password: "; cin>> password;

    LoginManagement lg;
    lg.setUsername(username);
    lg.setPassword(password);
    if( !lg.isLogin()){
        welcomeMenu();
    }else{
        MainMenu();
    }

}

void MainMenu(){
    string choice;

    do{
        system("clear");
        system ("cls");
        dp.mainMenu();
        cin >> choice;
    }while (checkOptions(choice)!=1
            && checkOptions(choice)!=2
            && checkOptions(choice)!=3
            && checkOptions(choice)!=0) ;

    switch (checkOptions(choice)) {
    case 1: // Go to Employee Management
       // system("clear");
        system ("cls");
        EmpManaMenu();
        break;
    case 2: //  Go to Payroll Management
       // system("clear");
        system ("cls");
        PayrollManaMenu();
        break;
    case 3: // Change password.

        break;
    case 0: // Exit.
       // system("clear");
        system ("cls");
        loginMenu();
        break;
    default:
        MainMenu();
    }

}


void EmpManaMenu()
{
    string choice;
    string strID;
    do{


        dp.empManaMenu();
        cin >> choice;

    }while (checkOptions(choice)!=1
            && checkOptions(choice)!=2
            && checkOptions(choice)!=3
            && checkOptions(choice)!=4
            && checkOptions(choice)!=5
            && checkOptions(choice)!=0) ;

    switch (checkOptions(choice)) {
    case 1: // Print all employee's information
        // Gọi hàm quanly->printInfo()
        system ("cls");
        management->printInfor();
        do{
            cout << "Enter 0 to exit";
            cin >> choice;
        }while (checkOptions(choice)!=0);
        //system("clear");
        system ("cls");
        EmpManaMenu();
        break;
    case 2: //  Add new employ.
        // Gọi hàm quanly->addNewEmp()
        management->addNewEmp();
        cout << " Wait a second!" << endl;
        sleep(2);
        //system("clear");
        system ("cls");
        EmpManaMenu();
        break;
    case 3: // Remove an employ by id
        // Gọi hàm quanly->removeEmpById()
        cout << "*************Remove employee menu**********" << endl;
        cout << " Enter ID: "; cin >> strID;

        if(management->searchEmp(strID) == 0){
            management->removeEmp(strID);
            cout << "Remove Successfully!"<< endl;
            cout << " Wait a second!" << endl;
            sleep(2);
            //system("clear");
            system ("cls");
        }else{
            cout << "System dosen't include this id, remove failed!" << endl;
            cout << " Wait a second!" << endl;
            //system("clear");
            system ("cls");
        }
        //system("clear");
        system ("cls");
        EmpManaMenu();
        break;
    case 4: // Update information an employ by id
        // Gọi hàm quanly->updateEmpById()
        cout << " Enter ID: "; cin >> strID;

        if(management->searchEmp(strID) == 0){
            updateEmployMenu(strID);
        }else{
            cout << "System dosen't include this id!" << endl;
            cout << "Wait a second!" << endl;
            sleep(2);
        }
        //system("clear");
        system ("cls");
        EmpManaMenu();
        break;
    case 5: // Search information employee by id
        //Gọi hàm quanly->searchEmpById()
        //system("clear");
        system ("cls");
        cout << " Enter ID: "; cin >> strID;

        if(management->searchEmp(strID) == 0){
                    management->serchPrintEmp(strID);
                    do{
                        cout << "Enter 0 to exit";
                        cin >> choice;
                    }while (checkOptions(choice)!=0);

        }else{
            cout << "System dosen't include this id!" << endl;
            cout << "Wait a second!" << endl;
            sleep(2);
        }
        EmpManaMenu();
        break;
    case 0: // Exit.
        //system("clear");
        system ("cls");
        MainMenu();
        break;
    default:
        MainMenu();
    }
}

void PayrollManaMenu() // Payroll management menu
{
    string choice;

    do{

        dp.payrollManage();
        cin >> choice;

    }while (checkOptions(choice)!=1
            && checkOptions(choice)!=2
            && checkOptions(choice)!=0);

    switch (checkOptions(choice)) {
    case 1://Input payroll for employee
        //Gọi hàm quanly->payrollInput()
        //system("clear");
        system ("cls");
            management->payrollInput();
            sleep(3);
            PayrollManaMenu();
        break;
    case 0: // Back to Mainmenu
        MainMenu();
        break;
    case 2:// Calculate salary and profit
        //Gọi làm quanly-> calcuSalary();
        break;
    default:
        PayrollManaMenu();

    }

}

void updateEmployMenu(string str)
{
    string choice;

    do{
        do{

            //system ("cls");
            dp.updateEmpMenu();
            cin >> choice;

        }while (checkOptions(choice)!=1
                && checkOptions(choice)!=2
                && checkOptions(choice)!=3
                && checkOptions(choice)!=0);

        switch (checkOptions(choice)) {
        case 1: // Go to Employee Management
            management->updateInfo(str , 1);
            break;
        case 2: //  Go to Payroll Management
            management->updateInfo(str, 2);
            break;
        case 3: // Change password.
            management->updateInfo(str, 3);
            break;
        case 0: // Exit.
            EmpManaMenu();
            break;
        default:
            EmpManaMenu();
        }
    }while(checkOptions(choice)!=0);

}
