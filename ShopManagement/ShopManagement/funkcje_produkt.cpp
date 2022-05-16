#include <iostream>
#include <locale>
#include <cstdlib>
#include <vector>
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


void stworz(vector<Produkt*>& produkty) {
    string nazwa, producent;
    size_t ilosc = randIlosc();
    double cena = randCena();
    int tmp = rand() % 3 + 1;

    cout << "Wprowadź nazwę produktu: ";
    cin >> nazwa;
    cout << "Wprowadź nazwę producenta: ";
    cin >> producent;

    if (tmp == 1) {
        produkty.push_back(new ProduktNaWage(nazwa, cena, ilosc, producent));
    }
    else if (tmp == 2) {
        produkty.push_back(new ProduktNaSztuki(nazwa, cena, ilosc, producent));
    }
    else {
        produkty.push_back(new ProduktNaObjetosc(nazwa, cena, ilosc, producent));
    }
}
void dodaj(vector<Produkt*>& produkty) {
    string nazwa, producent, s;
    size_t ilosc = randIlosc();
    double cena = randCena();
    int tmp = rand() % 3 + 1;

    cout << "Wprowadź nazwę produktu: ";
    cin >> nazwa;
    cout << "Wprowadź nazwę producenta: ";
    cin >> producent;
    cout << "Wprowadź jednostkę produktu: ";
    cin >> s;

    if (s == "kg")
        produkty.push_back(new ProduktNaWage(nazwa, cena, ilosc, producent));
    else if (s == "szt")
        produkty.push_back(new ProduktNaSztuki(nazwa, cena, ilosc, producent));
    else
        produkty.push_back(new ProduktNaObjetosc(nazwa, cena, ilosc, producent));
}
void print(vector<Produkt*>& produkty) {
    setlocale(LC_CTYPE, "Polish");
    cout << "<======= Produkty =======>" << endl;
    for (size_t ind = 0; ind < produkty.size(); ind++) {
        cout << produkty[ind]->getID() << "\t" << produkty[ind]->getSKU() << "\t" << produkty[ind]->getNazwa() << "\t" << produkty[ind]->getProducent() << "\t" << produkty[ind]->getCena() << "\t" << produkty[ind]->getIlosc() << produkty[ind]->getJednostka() << endl;
    }
}
void usun(vector<Produkt*>& produkty) {
    produkty.erase(produkty.begin(), produkty.end());
}
void usun(vector<Produkt*>& produkty, size_t index) {
    if (index < produkty.size()) {
        produkty.erase(produkty.begin() + index);
    }
    else
        cout << "ERROR: Index jest nieprawidłowy ! " << endl;
}
void zmianaCeny(vector<Produkt*>& produkty) {
    int index;
    double cena = 0;

    cout << "Indeks pracownika do zmiany ceny: ";
    cin >> index;

    cout << endl << "Produkt: " << produkty[index]->getSKU() << " " << produkty[index]->getNazwa() << endl;
    cout << "Cena: " << produkty[index]->getCena() << endl << endl;

    cout << "Wprowadź nową cenę: "; cin >> cena;
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
