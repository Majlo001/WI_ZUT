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

Produkt::~Produkt() {}


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
    delVec(produkty);
    produkty.erase(produkty.begin(), produkty.end());
}
void usun(vector<Produkt*>& produkty, size_t index) {
    if (index < produkty.size()) {
        delete produkty[index];
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

void statystykiProduktow(vector<Produkt*> produkty) {
    if (!produkty.empty()) {
        int maxCid = maxCenaProd(produkty);
        int minCid = minCenaProd(produkty);
        int maxLid = maxIlProd(produkty);
        int minLid = minIlProd(produkty);

        cout << "Maksymalna cena produktu to " << produkty[maxCid]->getCena() << " PLN za " << produkty[maxCid]->getNazwa() << " " << produkty[maxCid]->getSKU() << endl;
        cout << "Minimalna cena produktu to " << produkty[minCid]->getCena() << " PLN za " << produkty[minCid]->getNazwa() << " " << produkty[minCid]->getSKU() << endl;
        cout << endl;
        cout << "Maksymalna ilość produktów to " << produkty[maxLid]->getIlosc() << " za " << produkty[maxLid]->getNazwa() << " " << produkty[maxLid]->getSKU() << endl;
        cout << "Minimalna ilość produktów to " << produkty[minLid]->getIlosc() << " za " << produkty[minLid]->getNazwa() << " " << produkty[minLid]->getSKU() << endl;
    } else {
        cout << "Brak produktów" << endl;
    }
}
int maxCenaProd(vector<Produkt*> produkty) {
    size_t max = produkty[0]->getCena();
    int index = 1;
    for_each(produkty.begin(), produkty.end(), [&max, &index](Produkt* produkty){
        if (produkty->getCena() > max){
            max = produkty->getCena();
            index = produkty->getID();
        }
        });
    return index - 1;
}
int minCenaProd(vector<Produkt*> produkty) {
    size_t min = produkty[0]->getCena();
    int index = 1;
    for_each(produkty.begin(), produkty.end(), [&min, &index](Produkt* produkty) {
        if (produkty->getCena() < min) {
            min = produkty->getCena();
            index = produkty->getID();
        }
    });
    return index-1;
}
int maxIlProd(vector<Produkt*> produkty){
    size_t max = produkty[0]->getIlosc();
    int index = 1;
    for_each(produkty.begin(), produkty.end(), [&max, &index](Produkt* produkty) {
        if (produkty->getIlosc() > max) {
            max = produkty->getIlosc();
            index = produkty->getID();
        }
        });
    return index - 1;
}
int minIlProd(vector<Produkt*> produkty){
    size_t min = produkty[0]->getIlosc();
    int index = 1;
    for_each(produkty.begin(), produkty.end(), [&min, &index](Produkt* produkty) {
        if (produkty->getIlosc() < min) {
            min = produkty->getIlosc();
            index = produkty->getID();
        }
        });
    return index - 1;
}


int idProduktu() {
    static int id = 0;
    id++;
    return id;
}
