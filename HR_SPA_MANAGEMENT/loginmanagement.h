#ifndef LOGINMANAGEMENT_H
#define LOGINMANAGEMENT_H

#include <string>

using namespace std;

class LoginManagement
{
private:
    string m_username;
    string m_password;
public:
    LoginManagement(string f_username = "\0", string f_password = "\0") : m_username(f_username), m_password(f_password){}

    string getUsername() const ;
    string getPassword() const ;
    void setUsername(string f_username);
    void setPassword(string f_password);

    void loginMenu();
    bool isLogin();


};

#endif // LOGINMANAGEMENT_H
