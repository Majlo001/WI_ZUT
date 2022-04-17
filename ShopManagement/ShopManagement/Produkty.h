#pragma once

#include <iostream>
#include <locale>
#include <cstdlib>

using namespace std;

class Produkt {
    const int id;
    const string sku;
    string nazwa;
    double cena;
    size_t ilosc;
    string producent; //docelowo Producent producent;
public:
    Produkt();
    Produkt(string, double, size_t, string);
    int getID();
    string getSKU();
    string getNazwa();
    string getProducent();
    double getCena();
    size_t getIlosc();
    void setNazwa(string);
    void setCena(double);
    void setIlosc(size_t);
    void setProducent(string);
};


inline int Produkt::getID() { return id; }
inline string Produkt::getSKU() { return sku; }
inline string Produkt::getNazwa() { return nazwa; }
inline string Produkt::getProducent() { return producent; }
inline double Produkt::getCena() { return cena; }
inline size_t Produkt::getIlosc() { return ilosc; }

inline void Produkt::setNazwa(string n) { nazwa = n; }
inline void Produkt::setCena(double c) { cena = c; }
inline void Produkt::setIlosc(size_t i) { ilosc = i; }
inline void Produkt::setProducent(string p) { producent = p; }



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