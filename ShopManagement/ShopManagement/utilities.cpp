#include <iostream>
#include <locale>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <fstream>
#include <ctime>
#include "Utilities.h"



double randWynagrodzenie(int max, int var) {
    return rand() % max + var;
}
double randCena() {
    return ((rand() % 5000 + 4500) / 100) * 1.0;
}
size_t randIlosc() {
    return (rand() % 20000 + 199);
}


string randSKU() {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string sku;
    sku.reserve(8);

    for (int i = 0; i < 8; ++i) {
        sku += alphanum[rand() % (sizeof(alphanum) - 1)];
    }

    return sku;
}



void logbook(string s) {
    string filename("logbook.txt");
    ofstream logbook;

    logbook.open(filename, std::ios_base::app);

    if (logbook.is_open()) {
        struct tm now;
        time_t t = time(0);
        localtime_s(&now, &t);

        logbook << (1900 + now.tm_year) << '/' << (now.tm_mon + 1) << '/' << now.tm_mday << " " <<  now.tm_hour << ":" << now.tm_min << ":" << now.tm_sec <<  " \t|\t" << s << endl;
        logbook.close();
    } else {
        cout << "Nie można otworzyć pliku" << endl;
    }
}