#include "date.h"
#include<iostream>
#include <sstream>

using namespace std;

Date::Date()
{

}

Date::~Date()
{

}

int Date::inputDate()
{
    int d, m, y;
    cin >> y;
    if(cin.get() != '-')
    {
        cout << "expected -" << endl;
        return 1;
    }
    cin >> m;
    if(cin.get() != '-')
    {
        cout << "expected -" << endl;
        return 1;
    }
    cin >> d;

    if( (d < 1) || (d > 31))
    {
        cout << "invalid day!" << endl;
        return 1;
    }

    if( (m < 1) || (m > 12))
    {
        cout << "invalid month!" << endl;
        return 1;
    }

    if( (y < 1000 ) || (y > 9999))
    {
        cout << "invalid year!" << endl;
        return 1;
    }

    if((y == 2) && ((d ==30) || (d==31)))
    {
        cout << "invalid month" << endl;
        return 1;
    }

    setDay(d);
    setMon(m);
    setYear(y);

    convertDate(d,m,y);

    return 0;
}

void Date::convertDate(int date, int mon, int year)
{
    stringstream ss;
    ss << year << "-" << mon << "-" << date;
    ss >> dateFomat;

}

int Date::getDay() const
{
    return  d;
}

int Date::getMon() const
{
    return m;
}

int Date::getYear() const
{
    return y;
}

string Date::getStrDate() const
{
    return dateFomat;
}

void Date::convertStrDateToInt(string strDate)
{
    stringstream ss;
    ss << strDate;
    string s;

    int i =0;
    while(getline(ss,s,'-'))
    {
        i++;

        if(i == 1){
            y = stoi(s);
        }

        if(i == 2){
            m = stoi(s);
        }

        if(i == 3)
        {
            d = stoi(s);

        }
    }
}

void Date::setDay(int param_d){
    d= param_d;
}

void Date::setMon(int param_m){
    m = param_m;
}

void Date::setYear(int param_y){
    y = param_y;
}


