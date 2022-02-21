#ifndef DATE_H
#define DATE_H

#include <string>
#include <sstream>
#include <iostream>

using namespace std;

class Date
{
public:
    Date();
    ~Date();

    void convertDate(int date, int mon, int year );
    int inputDate();
    void convertStrDateToInt( string strDate);

    int getDay() const;
    int getMon() const;
    int getYear() const;
    string getStrDate() const;

    void setDay(int param_d);
    void setMon(int param_m);
    void setYear(int param_y);
private:
    int d ;
    int m ;
    int y ;
    string dateFomat;

};

#endif // DATE_H
