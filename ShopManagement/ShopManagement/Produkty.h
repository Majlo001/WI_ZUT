#pragma once

#include <iostream>
#include <locale>
#include <cstdlib>
#include <vector>
#include "Utilities.h"

using namespace std;

class Produkt {
    const int id;
    const string sku;
    string nazwa;
    double cena;
    size_t ilosc;
    string producent;
    string jednostka;
public:
    virtual void dodajIloscProduktu() = 0;

    Produkt();
    Produkt(string, double, size_t, string);
    virtual ~Produkt();

    int getID();
    string getSKU();
    string getNazwa();
    string getProducent();
    double getCena();
    size_t getIlosc();
    string getJednostka();
    void setNazwa(string);
    void setCena(double);
    void setIlosc(size_t);
    void setProducent(string);
    void setJednostka(string);
};

class ProduktNaWage : public Produkt {
public:
    ProduktNaWage() {
        setJednostka("kg");
    }
    ProduktNaWage(string nazwa, double cena, size_t ilosc, string producent) : Produkt(nazwa, cena, ilosc, producent) {
        this->setJednostka("kg");
    };
    virtual ~ProduktNaWage() {}
    virtual void dodajIloscProduktu() {
        size_t ilosc = getIlosc();
        size_t dodanaIlosc;
        cout << "Podaj ilość do dodania do " << getNazwa() << ": "; cin >> dodanaIlosc;
        logbook("Dodano " + to_string(dodanaIlosc) + " kilogramów produktu " + getNazwa());
        setIlosc(dodanaIlosc + ilosc);
    }
};
class ProduktNaSztuki : public Produkt {
public:
    ProduktNaSztuki() {
        setJednostka("szt");
    }
    ProduktNaSztuki(string nazwa, double cena, size_t ilosc, string producent) : Produkt(nazwa, cena, ilosc, producent) {
        setJednostka("szt");
    };
    virtual ~ProduktNaSztuki() {}
    virtual void dodajIloscProduktu() {
        size_t ilosc = getIlosc();
        size_t dodanaIlosc;
        cout << "Podaj ilość do dodania do " << getNazwa() << ": "; cin >> dodanaIlosc;
        logbook("Dodano " + to_string(dodanaIlosc) + " sztuk produktu " + getNazwa());
        setIlosc(dodanaIlosc + ilosc);
    }

};
class ProduktNaObjetosc : public Produkt {
public:
    ProduktNaObjetosc() {
        setJednostka("l");
    }
    ProduktNaObjetosc(string nazwa, double cena, size_t ilosc, string producent) : Produkt(nazwa, cena, ilosc, producent) {
        setJednostka("l");
    };
    virtual ~ProduktNaObjetosc() {}
    virtual void dodajIloscProduktu() {
        size_t ilosc = getIlosc();
        size_t dodanaIlosc;
        cout << "Podaj ilość do dodania do " << getNazwa() << ": "; cin >> dodanaIlosc;
        logbook("Dodano " + to_string(dodanaIlosc) + " litrów produktu " + getNazwa());
        setIlosc(dodanaIlosc + ilosc);
    }
};


inline int Produkt::getID() { return id; }
inline string Produkt::getSKU() { return sku; }
inline string Produkt::getNazwa() { return nazwa; }
inline string Produkt::getProducent() { return producent; }
inline double Produkt::getCena() { return cena; }
inline size_t Produkt::getIlosc() { return ilosc; }
inline string Produkt::getJednostka() { return jednostka; }

inline void Produkt::setNazwa(string n) { nazwa = n; }
inline void Produkt::setCena(double c) { cena = c; }
inline void Produkt::setIlosc(size_t i) { ilosc = i; }
inline void Produkt::setProducent(string p) { producent = p; }
inline void Produkt::setJednostka(string j) { jednostka = j; }



void stworz(vector<Produkt*>& produkty);
void dodaj(vector<Produkt*>& produkty);
void print(vector<Produkt*>& produkty);

void usun(vector<Produkt*>& produkty);
void usun(vector<Produkt*>& produkty, size_t index);
void zmianaCeny(vector<Produkt*>& produkty);


int idProduktu();
