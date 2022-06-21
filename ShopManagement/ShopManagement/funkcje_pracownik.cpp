#include <iostream>
#include <locale>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <map>
#include <memory>
#include "Pracownik.h"
#include "Utilities.h"

using namespace std;


Pracownik& Pracownik::operator=(const Pracownik& pracownik) {
    usun();
    imie = pracownik.imie;
    nazwisko = pracownik.nazwisko;
    stanowisko = pracownik.stanowisko;
    wynagrodzenie = pracownik.wynagrodzenie;
    iloscZadan = pracownik.iloscZadan;

    /*stworz(listaZadan, iloscZadan);
    if (iloscZadan > 0) {
        for (size_t i = 0; i < iloscZadan; i++) {
            listaZadan[i]->setOpis(listaZadan[i]->getOpis());
            listaZadan[i]->setZrobione(listaZadan[i]->getZrobione());
        }
    }*/

    return *this;
}
ostream& operator<<(ostream& out, const Pracownik& pracownik) {
    out << pracownik.id << "/t" << pracownik.imie << "/t" << pracownik.nazwisko << "/t" << pracownik.wynagrodzenie << endl;
    return out;
}
auto& Pracownik::operator[](int index) {
    assert(0 <= index && index <= iloscZadan);
    return listaZadan[index];
}

Pracownik::Pracownik() : id{ idPracownika() } {};
Pracownik::Pracownik(string imie, string nazwisko, string stanowisko, double wynagrodzenie) : id{ idPracownika() } {
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->stanowisko = stanowisko;
    this->wynagrodzenie = wynagrodzenie;
    //stworz(this->listaZadan, this->iloscZadan);
}

Pracownik::Zadania::Zadania() {}
Pracownik::Zadania::Zadania(string opis, bool zrobione) {
    this->opis = opis;
    this->zrobione = zrobione;
}
ostream& operator<<(ostream& out, Pracownik::Zadania& zadania) {
    out << zadania.getOpis() << "/t" << zadania.getZrobione() << endl;
    return out;
}

Pracownik::~Pracownik() {
    usun();
}
Pracownik::Pracownik(const Pracownik& pracownik) : id{ pracownik.id } {
    this->imie = pracownik.imie;
    this->nazwisko = pracownik.nazwisko;
    this->stanowisko = pracownik.stanowisko;
    this->wynagrodzenie = pracownik.wynagrodzenie;
    this->iloscZadan = pracownik.iloscZadan;

    /*stworz(this->listaZadan, this->iloscZadan);
    if (iloscZadan > 0) {
        for (size_t i = 0; i < iloscZadan; i++) {
            listaZadan[i]->setOpis(listaZadan[i]->getOpis());
            listaZadan[i]->setZrobione(listaZadan[i]->getZrobione());
        }
    }*/
    copy(pracownik.listaZadan.begin(), pracownik.listaZadan.end(), inserter(this->listaZadan, this->listaZadan.end()));
}






void stworz(vector<shared_ptr<Pracownik>>& pracownicy, const size_t rozmiar) {
    string imie, nazw, stan;
    for (size_t ind = 0; ind < rozmiar; ind++) {

        cout << "Wprowadź imie pracownika: ";
        cin >> imie;
        cout << "Wprowadź nazwisko pracownika: ";
        cin >> nazw;
        cout << "Wprowadź stanowisko pracownika: ";
        cin >> stan;

        pracownicy.push_back(make_shared<Pracownik>(imie, nazw, stan, randWynagrodzenie(5000, 3000)));
    }
}


void dodaj(vector<shared_ptr<Pracownik>>& pracownicy, size_t& size) {
    string imie, nazw, stan;

    cout << "Wprowadź imie pracownika: ";
    cin >> imie;
    cout << "Wprowadź nazwisko pracownika: ";
    cin >> nazw;
    cout << "Wprowadź stanowisko pracownika: ";
    cin >> stan;

    pracownicy.push_back(make_shared<Pracownik>(imie, nazw, stan, randWynagrodzenie(5000, 3000)));

    size++;
}

void print(vector<shared_ptr<Pracownik>> pracownicy, const size_t rozmiar) {
    cout << "<======= Pracownicy =======>" << endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        cout << pracownicy[ind]->getID() << "\t" << pracownicy[ind]->getImie() << "\t" << pracownicy[ind]->getNazwisko() << "\t" << pracownicy[ind]->getWynagrodzenie() << "\t" << pracownicy[ind]->getStanowisko() << endl;
    }
}

void usun(vector<shared_ptr<Pracownik>>& pracownicy, size_t& rozmiar) {
    pracownicy.erase(pracownicy.begin(), pracownicy.end());
    rozmiar = 0;
}
void usun(vector<shared_ptr<Pracownik>>& pracownicy, size_t& size, size_t index) {
    pracownicy.erase(pracownicy.begin() + index);
    size--;
}

void stanowiskaPracy(vector<shared_ptr<Pracownik>> pracownik, const size_t rozmiar) {
    vector <string> stanowiska;

    for (size_t i = 0; i < rozmiar; i++) {
        stanowiska.push_back(pracownik[i]->getStanowisko());
    }

    sort(stanowiska.begin(), stanowiska.end());
    stanowiska.erase(unique(stanowiska.begin(), stanowiska.end()), stanowiska.end());

    cout << endl << "Stanowiska pracy, ilość pracowników i ich średnie wynagrodzenie: " << endl;
    for (size_t i = 0; i < stanowiska.size(); i++) {
        int count = 0;
        double srednia = 0;

        for (size_t j = 0; j < rozmiar; j++) {
            if (stanowiska[i] == pracownik[j]->getStanowisko()) {
                count++;
                srednia += pracownik[j]->getWynagrodzenie();
            }
        }
        cout << stanowiska[i] << ":\t" << count << "\t" << (srednia / count) << endl;
    }
}
void wyplaty(vector<shared_ptr<Pracownik>> pracownik, const size_t rozmiar) {
    double wyplaty = 0;
    for (size_t i = 0; i < rozmiar; i++) {
        wyplaty += pracownik[i]->getWynagrodzenie();
    }
    cout << "Wydatki na wypłaty: " << wyplaty << endl;
}
void sredniaZarobkow(vector<shared_ptr<Pracownik>>pracownik, const size_t rozmiar) {
    double sredniaZar = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        sredniaZar += pracownik[i]->getWynagrodzenie();
    }
    cout << endl;
    cout << "Średnia zarobków pracowników: " << (sredniaZar / rozmiar) << endl;
}
void maxZarobki(vector<shared_ptr<Pracownik>> pracownik, const size_t rozmiar) {
    int index = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        if (pracownik[i]->getWynagrodzenie() > pracownik[index]->getWynagrodzenie()) {
            index = i;
        }
    }
    cout << endl << "Najwyższe zarobki: " << pracownik[index]->getImie() << " " << pracownik[index]->getNazwisko() << " " << pracownik[index]->getWynagrodzenie() << " " << pracownik[index]->getStanowisko() << endl;
}
void minZarobki(vector<shared_ptr<Pracownik>> pracownik, const size_t rozmiar) {
    int index = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        if (pracownik[i]->getWynagrodzenie() < pracownik[index]->getWynagrodzenie()) {
            index = i;
        }
    }
    cout << "Najniższe zarobki: " << pracownik[index]->getImie() << " " << pracownik[index]->getNazwisko() << " " << pracownik[index]->getWynagrodzenie() << " " << pracownik[index]->getStanowisko() << endl;
}
void statystykiPracownikow(vector<shared_ptr<Pracownik>> pracownik, const size_t rozmiar) {
    cout << endl << "<======= Statystyki pracowników =======>" << endl << endl;

    if (!pracownik.empty()) {
        cout << "Ilość pracowników: " << rozmiar;
    }
    sredniaZarobkow(pracownik, rozmiar);
    wyplaty(pracownik, rozmiar);
    maxZarobki(pracownik, rozmiar);
    minZarobki(pracownik, rozmiar);
    stanowiskaPracy(pracownik, rozmiar);
}


void zmianaWynagordzenia(vector<shared_ptr<Pracownik>> pracownik) {
    int index, choice;
    double kwota = 0;

    cout << "Indeks pracownika do zmiany wynagrodzenia: ";
    cin >> index;

    cout << endl << "Pracownik: " << pracownik[index]->getImie() << " " << pracownik[index]->getNazwisko() << endl;
    cout << "Stanowisko: " << pracownik[index]->getStanowisko() << endl;
    cout << "Wynagrodzenie: " << pracownik[index]->getWynagrodzenie() << endl << endl;

    cout << "Zmniejszyć, czy zwiekszyć wynagrodzenie? " << endl;
    cout << "Zmniejszyć - 0 " << endl;
    cout << "Zwiększyć - 1 " << endl;
    cout << "Twój wybór: ";
    cin >> choice;

    switch (choice) {
    case(0):
        cout << endl << "O jaką kwotę zmniejszyć wynagrodzenie: ";
        cin >> kwota;
        pracownik[index]->setWynagrodzenie(pracownik[index]->getWynagrodzenie() - kwota);
        break;
    case(1):
        cout << endl << "O jaką kwotę zwiększyć wynagrodzenie: ";
        cin >> kwota;
        pracownik[index]->setWynagrodzenie(pracownik[index]->getWynagrodzenie() + kwota);
        break;
    default:
        cout << endl << "Coś poszło nie tak, spróbuj ponownie." << endl;
        break;
    }

    if (kwota != 0) {
        cout << endl << "Informacje po zmianie: " << endl;
        cout << "Pracownik: " << pracownik[index]->getImie() << " " << pracownik[index]->getNazwisko() << endl;
        cout << "Stanowisko: " << pracownik[index]->getStanowisko() << endl;
        cout << "Wynagrodzenie: " << pracownik[index]->getWynagrodzenie() << endl;
    }
}


int idPracownika() {
    static int id = 0;
    id++;
    return id;
}


//void Pracownik::stworz(set<Zadania*>& listaZadan, const size_t rozmiar) {
//    //listaZadan = new Zadania * [rozmiar];
//    listaZadan.insert(new Zadania);
//    for (size_t ind = 0; ind < rozmiar; ind++)
//        listaZadan.insert(new Zadania);
//}
void Pracownik::dodaj() {
    setlocale(LC_CTYPE, "Polish");
    string s;
    cin.ignore();
    cout << "Wprowadź opis zadania: ";
    getline(cin, s, '\n');

    listaZadan.insert({zadanieID(), new Zadania(s, false) });

    iloscZadan++;
}
void Pracownik::print() {
    setlocale(LC_CTYPE, "Polish");
    cout << "<======= Lista Zadań =======>" << endl;
    if (iloscZadan == 0) {
        cout << "Brak rekordów" << endl;
    }
    for (auto i : listaZadan){
        cout << i.first << "\t" << *i.second << endl;
    }
    /*for (size_t ind = 0; ind < iloscZadan; ind++) {
        cout << listaZadan[ind]->getZrobione() << "\t" << listaZadan[ind]->getOpis() << endl;
    }*/
}
void Pracownik::usun() {
    listaZadan.clear();
    iloscZadan = 0;
}
void Pracownik::usun(size_t index) {
    listaZadan.erase(index);
}

size_t zadanieID(){
    static size_t next_id = 0;
    next_id++;
    return next_id;
}