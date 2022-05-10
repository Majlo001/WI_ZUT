#pragma once
#include <iostream>
#include <locale>
#include <cstdlib>
#include <string>

using namespace std;

class Date {
private:
    size_t day;
    size_t month;
    size_t year;
public:
    Date() {
        day = month = year = 0;
    }
    Date(int day, int month, int year) {
        this->day = day;
        this->month = month;
        this->year = year;
    }

    void print_date() {
        cout << day << "/" << month << "/" << year << endl;
    }
    size_t get_day() {return day;}
    size_t get_month() {return month;}
    size_t get_year() { return year; }

};



double randWynagrodzenie(int max, int var);
string randSKU();


void logbook(string s);
