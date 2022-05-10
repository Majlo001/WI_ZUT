#include <iostream>
#include <locale>
#include <cstdlib>
#include <algorithm>
#include "Produkty.h"
#include "Utilities.h"

using namespace std;




Produkt::Produkt() : id{ idProduktu() }, sku{ randSKU() } {};
Produkt::Produkt(string nazwa, double cena, size_t ilosc, string producent) : id{ idProduktu() }, sku{ randSKU() } {
    this->nazwa = nazwa;
    this->cena = cena;
    this->ilosc = ilosc;
    this->producent = producent;
}

Produkt::~Produkt() {
    delete this;
}


void stworz(Produkt**& produkty) {
    produkty = new Produkt*;
}
void stworz(Produkt**& produkty, const size_t rozmiar) {
    produkty = new Produkt * [rozmiar];
    for (size_t ind = 0; ind < rozmiar; ind++) {
        int tmp = rand() % 3 + 1;

        if (tmp == 1) {
            produkty[ind] = new ProduktNaWage;
        }
        else if (tmp == 2) {
            produkty[ind] = new ProduktNaSztuki;
        }
        else {
            produkty[ind] = new ProduktNaObjetosc;
        }
    }
}
void ini(Produkt** produkty, const size_t rozmiar) {
    string s;
    size_t ilosc;
    double cena;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        cout << "Wprowad� nazw� produktu: ";
        cin >> s;
        produkty[ind]->setNazwa(s);
        cout << "Wprowad� nazw� producenta: ";
        cin >> s;
        produkty[ind]->setProducent(s);
        cout << "Wprowad� cen� produktu: ";
        cin >> cena;
        produkty[ind]->setCena(cena);
        cout << "Wprowad� ilo�� produkt�w: ";
        cin >> ilosc;
        produkty[ind]->setIlosc(ilosc);
    }
}
void dodaj(Produkt**& produkty, size_t& size) {
    string s;
    size_t ilosc;
    double cena;
    Produkt** temp = new Produkt * [size + 1];


    cout << "Wprowad� jednostk� produktu: ";
    cin >> s;

    if (size == 0) {
        if (s == "kg")
            temp[size] = new ProduktNaWage;
        else if (s == "szt")
            temp[size] = new ProduktNaSztuki;
        else
            temp[size] = new ProduktNaObjetosc;
    }
    else {
        for (size_t i = 0; i < size; ++i)
            temp[i] = produkty[i];
        if (s == "kg")
            temp[size] = new ProduktNaWage;
        else if (s == "szt")
            temp[size] = new ProduktNaSztuki;
        else
            temp[size] = new ProduktNaObjetosc;
        delete[] produkty;
    }
    produkty = temp;


    cout << "Wprowad� nazw� produktu: ";
    cin >> s;
    produkty[size]->setNazwa(s);
    cout << "Wprowad� nazw� producenta: ";
    cin >> s;
    produkty[size]->setProducent(s);
    cout << "Wprowad� cen� produktu: ";
    cin >> cena;
    produkty[size]->setCena(cena);
    cout << "Wprowad� ilo�� produkt�w: ";
    cin >> ilosc;
    produkty[size]->setIlosc(ilosc);

    size++;
}
void print(Produkt** produkty, const size_t rozmiar) {
    cout << "<======= Produkty =======>" << endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        cout << produkty[ind]->getID() << "\t" << produkty[ind]->getSKU() << "\t" << produkty[ind]->getNazwa() << "\t" << produkty[ind]->getProducent() << "\t" << produkty[ind]->getCena() << "\t" << produkty[ind]->getIlosc() << produkty[ind]->getJednostka() << endl;
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
        cout << "ERROR: Index jest nieprawid�owy ! " << endl;
}
void zmianaCeny(Produkt**& produkty) {
    int index;
    double cena = 0;

    cout << "Indeks pracownika do zmiany ceny: ";
    cin >> index;

    cout << endl << "Produkt: " << produkty[index]->getSKU() << " " << produkty[index]->getNazwa() << endl;
    cout << "Cena: " << produkty[index]->getCena() << endl << endl;

    cout << "Wprowad� now� cen�: "; cin >> cena;
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
