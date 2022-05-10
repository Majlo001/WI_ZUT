#pragma once

#include <iostream>
#include <locale>
#include <cstdlib>
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

class ProduktNaWage : public Produkt{
public:
    ProduktNaWage() {
        setJednostka("kg");
    }
    virtual ~ProduktNaWage() {}
    virtual void dodajIloscProduktu() {
        size_t ilosc = getIlosc();
        size_t dodanaIlosc;
        cout << "Podaj ilo�� do dodania do " << getNazwa() << ": "; cin >> dodanaIlosc;
        logbook("Dodano " + to_string(dodanaIlosc) + " kilogram�w produktu " + getNazwa());
        setIlosc(dodanaIlosc + ilosc);
    }
};
class ProduktNaSztuki : public Produkt {
public:
    ProduktNaSztuki() {
        setJednostka("szt");
    }
    virtual ~ProduktNaSztuki() {}
    virtual void dodajIloscProduktu() {
        size_t ilosc = getIlosc();
        size_t dodanaIlosc;
        cout << "Podaj ilo�� do dodania do " << getNazwa() << ": "; cin >> dodanaIlosc;
        logbook("Dodano " + to_string(dodanaIlosc) + " sztuk produktu " + getNazwa());
        setIlosc(dodanaIlosc + ilosc);
    }

};
class ProduktNaObjetosc : public Produkt {
public:
    ProduktNaObjetosc() {
        setJednostka("l");
    }
    virtual ~ProduktNaObjetosc() {}
    virtual void dodajIloscProduktu() {
        size_t ilosc = getIlosc();
        size_t dodanaIlosc;
        cout << "Podaj ilo�� do dodania do " << getNazwa() << ": "; cin >> dodanaIlosc;
        logbook("Dodano "+ to_string(dodanaIlosc) +" litr�w produktu "+getNazwa());
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



void stworz(Produkt**& produkty);
void stworz(Produkt**& produkty, const size_t rozmiar);
void ini(Produkt** produkty, const size_t rozmiar);
void dodaj(Produkt**& produkty, size_t& size);
void print(Produkt** produkty, const size_t rozmiar);
//void usun(Produkt**& produkty);
void usun(Produkt**& produkty, size_t& rozmiar);
void usun(Produkt**& produkty, size_t& size, size_t index);
void zmianaCeny(Produkt**& produkty);


int idProduktu();
