#include "loginmanagement.h"
#include <iostream>
#include <string>
#include<fstream>
#include <sstream>

using namespace std;

string LoginManagement::getUsername() const
{
    return m_username;
}

string LoginManagement::getPassword() const
{
    return m_password;
}

void LoginManagement::setUsername(string f_username)
{
    m_username = f_username;

}

void LoginManagement::setPassword(string f_password)
{
    m_password = f_password;
}

void LoginManagement::loginMenu()
{

}

bool LoginManagement::isLogin()
{
    string str;
    string f_username;
    string f_password;
    stringstream ss;
/*E:\\Fresher\\conver_mock\\HR_SPA_MOCK\\ */
    ifstream fileLogin("login.txt");

    if(!fileLogin.is_open()){
        cout << "Loi file vui long kiem tra duong dan" << endl;
        return false;
    }else{

        getline(fileLogin, str);
        ss << str;
        ss >> f_username >> f_password;
        fileLogin.close();
    }

    if( (getUsername() == f_username) && (getPassword() == f_password) )
    {
        return true;
    }else{
        return false;
    }

}
