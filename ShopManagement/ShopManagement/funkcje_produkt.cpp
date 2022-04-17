#include <iostream>
#include <locale>
#include <cstdlib>
#include <algorithm>
#include "Produkty.h"

using namespace std;



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

Produkt::Produkt() : id{ idProduktu() }, sku{ randSKU() } {};
Produkt::Produkt(string nazwa, double cena, size_t ilosc, string producent) : id{ idProduktu() }, sku{ randSKU() } {
    this->nazwa = nazwa;
    this->cena = cena;
    this->ilosc = ilosc;
    this->producent = producent;
}



void stworz(Produkt**& produkty) {
    produkty = new Produkt*;
}
void stworz(Produkt**& produkty, const size_t rozmiar) {
    produkty = new Produkt * [rozmiar];
    for (size_t ind = 0; ind < rozmiar; ind++)
        produkty[ind] = new Produkt;
}
void ini(Produkt** produkty, const size_t rozmiar) {
    string s;
    size_t ilosc;
    double cena;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        cout << "WprowadŸ nazwê produktu: ";
        cin >> s;
        produkty[ind]->setNazwa(s);
        cout << "WprowadŸ nazwê producenta: ";
        cin >> s;
        produkty[ind]->setProducent(s);
        cout << "WprowadŸ cenê produktu: ";
        cin >> cena;
        produkty[ind]->setCena(cena);
        cout << "WprowadŸ iloœæ produktów: ";
        cin >> ilosc;
        produkty[ind]->setIlosc(ilosc);
    }
}
void dodaj(Produkt**& produkty, size_t& size) {
    string s;
    size_t ilosc;
    double cena;
    Produkt** temp = new Produkt * [size + 1];
    if (size == 0) {
        temp[size] = new Produkt;
    }
    else {
        for (size_t i = 0; i < size; ++i)
            temp[i] = produkty[i];
        temp[size] = new Produkt;
        delete[] produkty;
    }
    produkty = temp;

    cout << "WprowadŸ nazwê produktu: ";
    cin >> s;
    produkty[size]->setNazwa(s);
    cout << "WprowadŸ nazwê producenta: ";
    cin >> s;
    produkty[size]->setProducent(s);
    cout << "WprowadŸ cenê produktu: ";
    cin >> cena;
    produkty[size]->setCena(cena);
    cout << "WprowadŸ iloœæ produktów: ";
    cin >> ilosc;
    produkty[size]->setIlosc(ilosc);

    size++;
}
void print(Produkt** produkty, const size_t rozmiar) {
    cout << "<======= Produkty =======>" << endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        cout << produkty[ind]->getID() << "\t" << produkty[ind]->getSKU() << "\t" << produkty[ind]->getNazwa() << "\t" << produkty[ind]->getProducent() << "\t" << produkty[ind]->getCena() << "\t" << produkty[ind]->getIlosc() << endl;
    }
}
void usun(Produkt**& produkty, size_t& rozmiar) {
    for (size_t ind = 0; ind < rozmiar; ind++)
        delete produkty[ind];
    delete[] produkty;
    produkty = nullptr;
    rozmiar = 0;
}
void usun(Produkt**& produkty, size_t& size, size_t index) {
    if (index < size) {
        Produkt** temp = new Produkt * [size - 1];
        short int j{ -1 };
        for (size_t i = 0; i < size; ++i)
            if (i != index) {
                ++j;
                temp[j] = produkty[i];
            }
        delete[] produkty;
        produkty = temp;
        --size;
    }
    else
        cout << "ERROR: Index jest nieprawid³owy ! " << endl;
}
void zmianaCeny(Produkt**& produkty) {
    int index, choice;
    double cena = 0;

    cout << "Indeks pracownika do zmiany wynagrodzenia: ";
    cin >> index;

    cout << endl << "Produkt: " << produkty[index]->getSKU() << " " << produkty[index]->getNazwa() << endl;
    cout << "Cena: " << produkty[index]->getCena() << endl << endl;

    cout << "WprowadŸ now¹ cenê: "; cin >> cena;
    produkty[index]->setCena(cena);

    if (cena != 0) {
        cout << endl << "Informacje po zmianie: " << endl;
        cout << endl << "Produkt: " << produkty[index]->getSKU() << " " << produkty[index]->getNazwa() << endl;
        cout << "Cena: " << produkty[index]->getCena() << endl << endl;
    }
}


int idProduktu() {
    static int id = 0;
    id++;
    return id;
}