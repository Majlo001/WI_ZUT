#include <iostream>
#include <locale>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <cassert>
#include <map>
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

    this->listaZadan.swap(listaZadan);
}





//void stworz(Pracownik*& pracownik) {
//    pracownik = new Pracownik;
//}
//void stworz(Pracownik**& pracownik) {
//    pracownik = new Pracownik*;
//}
//void stworz(Pracownik*& pracownik, const size_t rozmiar) {
//    pracownik = new Pracownik[rozmiar];
//}
void stworz(Pracownik**& pracownicy, const size_t rozmiar) {
    pracownicy = new Pracownik * [rozmiar];
    for (size_t ind = 0; ind < rozmiar; ind++)
        pracownicy[ind] = new Pracownik;
}


void ini(Pracownik*& pracownik) {
    string s;
    cout << "Wprowadź imie pracownika: ";
    cin >> s;
    pracownik->setImie(s);
    cout << "Wprowadź nazwisko pracownika: ";
    cin >> s;
    pracownik->setNazwisko(s);
    cout << "Wprowadź stanowisko pracownika: ";
    cin >> s;
    pracownik->setStanowisko(s);
    pracownik->setWynagrodzenie(randWynagrodzenie(5000, 3000));
}
void ini(Pracownik& pracownik) {
    string s;
    cout << "Wprowadź imie pracownika: ";
    cin >> s;
    pracownik.setImie(s);
    cout << "Wprowadź nazwisko pracownika: ";
    cin >> s;
    pracownik.setNazwisko(s);
    cout << "Wprowadź stanowisko pracownika: ";
    cin >> s;
    pracownik.setStanowisko(s);
    pracownik.setWynagrodzenie(randWynagrodzenie(5000, 3000));
}
void ini(Pracownik* pracownik, const size_t rozmiar) {
    string s;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        pracownik[ind].setWynagrodzenie(randWynagrodzenie(5000, 3000));

        cout << "Wprowadź imie pracownika: ";
        cin >> s;
        pracownik[ind].setImie(s);
        cout << "Wprowadź nazwisko pracownika: ";
        cin >> s;
        pracownik[ind].setNazwisko(s);
        cout << "Wprowadź stanowisko pracownika: ";
        cin >> s;
        pracownik[ind].setStanowisko(s);
    }
}
void ini(Pracownik** pracownicy, const size_t rozmiar) {
    string s;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        pracownicy[ind]->setWynagrodzenie(randWynagrodzenie(5000, 3000));

        cout << "Wprowadź imie pracownika: ";
        cin >> s;
        pracownicy[ind]->setImie(s);
        cout << "Wprowadź nazwisko pracownika: ";
        cin >> s;
        pracownicy[ind]->setNazwisko(s);
        cout << "Wprowadź stanowisko pracownika: ";
        cin >> s;
        pracownicy[ind]->setStanowisko(s);
    }
}


void dodaj(Pracownik**& pracownicyAll, size_t& size) {
    string s;
    Pracownik** temp = new Pracownik * [size + 1];
    if (size == 0) {
        temp[size] = new Pracownik;
    }
    else {
        for (size_t i = 0; i < size; ++i)
            temp[i] = pracownicyAll[i];
        temp[size] = new Pracownik;
        delete[] pracownicyAll;
    }
    pracownicyAll = temp;

    pracownicyAll[size]->setWynagrodzenie(randWynagrodzenie(5000, 3000));
    cout << "Wprowadź imie pracownika: ";
    cin >> s;
    pracownicyAll[size]->setImie(s);
    cout << "Wprowadź nazwisko pracownika: ";
    cin >> s;
    pracownicyAll[size]->setNazwisko(s);
    cout << "Wprowadź stanowisko pracownika: ";
    cin >> s;
    pracownicyAll[size]->setStanowisko(s);

    size++;
}
void dodaj(Pracownik*& pracownicyAll, size_t& size) {
    string s;
    Pracownik* temp = new Pracownik[size + 1];

    for (size_t i = 0; i < size; ++i)
        temp[i] = pracownicyAll[i];
    delete[] pracownicyAll;
    pracownicyAll = temp;

    pracownicyAll[size].setWynagrodzenie(randWynagrodzenie(5000, 3000));
    cout << "Wprowadź imie pracownika: ";
    cin >> s;
    pracownicyAll[size].setImie(s);
    cout << "Wprowadź nazwisko pracownika: ";
    cin >> s;
    pracownicyAll[size].setNazwisko(s);
    cout << "Wprowadź stanowisko pracownika: ";
    cin >> s;
    pracownicyAll[size].setStanowisko(s);

    size++;
}


void print(Pracownik* mPracownik) {
    cout << endl << "Pracownik: " << mPracownik->getImie() << " " << mPracownik->getNazwisko();
    cout << endl << "Wynagrodznie: " << mPracownik->getWynagrodzenie();
    cout << endl << "Stanowisko: " << mPracownik->getStanowisko();
}
void print(Pracownik* pracownik, const size_t rozmiar) {
    std::cout << "<======= Pracownicy =======>" << std::endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        cout << pracownik[ind].getID() << "\t" << pracownik[ind].getImie() << "\t" << pracownik[ind].getNazwisko() << "\t" << pracownik[ind].getWynagrodzenie() << "\t" << pracownik[ind].getStanowisko() << endl;
    }
}
void print(Pracownik** pracownicy, const size_t rozmiar) {
    cout << "<======= Pracownicy =======>" << endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        cout << pracownicy[ind]->getID() << "\t" << pracownicy[ind]->getImie() << "\t" << pracownicy[ind]->getNazwisko() << "\t" << pracownicy[ind]->getWynagrodzenie() << "\t" << pracownicy[ind]->getStanowisko() << endl;
    }
}


void usun(Pracownik*& pracownik) {
    delete[] pracownik;
    pracownik = nullptr;
}
void usun(Pracownik*& pracownik, size_t& rozmiar) {
    delete[] pracownik;
    pracownik = nullptr;
    rozmiar = 0;
}
void usun(Pracownik**& pracownicy, size_t& rozmiar) {
    for (size_t ind = 0; ind < rozmiar; ind++)
        delete pracownicy[ind];
    delete[] pracownicy;
    pracownicy = nullptr;
    rozmiar = 0;
}

void usun(Pracownik*& pracownicyAll, size_t& size, size_t index) {
    if (index < size) {
        Pracownik* temp = new Pracownik[size - 1];
        short int j{ -1 };
        for (size_t i = 0; i < size; ++i)
            if (i != index) {
                ++j;
                temp[j] = pracownicyAll[i];
            }
        delete[] pracownicyAll;
        pracownicyAll = temp;
        --size;
    }
    else
        cout << "ERROR: Index jest nieprawidłowy ! " << endl;
}
void usun(Pracownik**& pracownicyAll, size_t& size, size_t index) {
    if (index < size) {
        Pracownik** temp = new Pracownik * [size - 1];
        short int j{ -1 };
        for (size_t i = 0; i < size; ++i)
            if (i != index) {
                ++j;
                temp[j] = pracownicyAll[i];
            }
        delete[] pracownicyAll;
        pracownicyAll = temp;
        --size;
    }
    else
        cout << "ERROR: Index jest nieprawidłowy ! " << endl;
}


void stanowiskaPracy(Pracownik* pracownik, const size_t rozmiar) {
    vector <string> stanowiska;

    for (size_t i = 0; i < rozmiar; i++) {
        stanowiska.push_back(pracownik[i].getStanowisko());
    }

    sort(stanowiska.begin(), stanowiska.end());
    stanowiska.erase(unique(stanowiska.begin(), stanowiska.end()), stanowiska.end());

    cout << endl << "Stanowiska pracy, ilość pracowników i ich średnie wynagrodzenie: " << endl;
    for (size_t i = 0; i < stanowiska.size(); i++) {
        int count = 0;
        double srednia = 0;

        for (size_t j = 0; j < rozmiar; j++) {
            if (stanowiska[i] == pracownik[j].getStanowisko()) {
                count++;
                srednia += pracownik[j].getWynagrodzenie();
            }
        }
        cout << stanowiska[i] << ":\t" << count << "\t" << (srednia / count) << endl;
    }
}
void stanowiskaPracy(Pracownik** pracownik, const size_t rozmiar) {
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
void wyplaty(Pracownik* pracownik, const size_t rozmiar) {
    double wyplaty = 0;
    for (size_t i = 0; i < rozmiar; i++) {
        wyplaty += pracownik[i].getWynagrodzenie();
    }
    cout << "Wydatki na wypłaty: " << wyplaty << endl;
}
void wyplaty(Pracownik** pracownik, const size_t rozmiar) {
    double wyplaty = 0;
    for (size_t i = 0; i < rozmiar; i++) {
        wyplaty += pracownik[i]->getWynagrodzenie();
    }
    cout << "Wydatki na wypłaty: " << wyplaty << endl;
}
void sredniaZarobkow(Pracownik* pracownik, const size_t rozmiar) {
    double sredniaZar = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        sredniaZar += pracownik[i].getWynagrodzenie();
    }
    cout << endl;
    cout << "Średnia zarobków pracowników: " << (sredniaZar / rozmiar) << endl;
}
void sredniaZarobkow(Pracownik** pracownik, const size_t rozmiar) {
    double sredniaZar = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        sredniaZar += pracownik[i]->getWynagrodzenie();
    }
    cout << endl;
    cout << "Średnia zarobków pracowników: " << (sredniaZar / rozmiar) << endl;
}
void maxZarobki(Pracownik* pracownik, const size_t rozmiar) {
    int index = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        /*if (pracownik[i].getWynagrodzenie() > pracownik[index].getWynagrodzenie()) {
            index = i;
        }*/
        if (pracownik[i].getWynagrodzenie() == max(pracownik[i].getWynagrodzenie(),pracownik[index].getWynagrodzenie())) {
            index = i;
        }
    }
    cout << endl << "Najwyższe zarobki: " << pracownik[index].getImie() << " " << pracownik[index].getNazwisko() << " " << pracownik[index].getWynagrodzenie() << " " << pracownik[index].getStanowisko() << endl;
}
void maxZarobki(Pracownik** pracownik, const size_t rozmiar) {
    int index = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        if (pracownik[i]->getWynagrodzenie() > pracownik[index]->getWynagrodzenie()) {
            index = i;
        }
    }
    cout << endl << "Najwyższe zarobki: " << pracownik[index]->getImie() << " " << pracownik[index]->getNazwisko() << " " << pracownik[index]->getWynagrodzenie() << " " << pracownik[index]->getStanowisko() << endl;
}
void minZarobki(Pracownik* pracownik, const size_t rozmiar) {
    int index = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        if (pracownik[i].getWynagrodzenie() < pracownik[index].getWynagrodzenie()) {
            index = i;
        }
    }
    cout << "Najniższe zarobki: " << pracownik[index].getImie() << " " << pracownik[index].getNazwisko() << " " << pracownik[index].getWynagrodzenie() << " " << pracownik[index].getStanowisko() << endl;
}
void minZarobki(Pracownik** pracownik, const size_t rozmiar) {
    int index = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        if (pracownik[i]->getWynagrodzenie() < pracownik[index]->getWynagrodzenie()) {
            index = i;
        }
    }
    cout << "Najniższe zarobki: " << pracownik[index]->getImie() << " " << pracownik[index]->getNazwisko() << " " << pracownik[index]->getWynagrodzenie() << " " << pracownik[index]->getStanowisko() << endl;
}
void statystykiPracownikow(Pracownik* pracownik, const size_t rozmiar) {
    cout << endl << "<======= Statystyki pracowników =======>" << endl << endl;

    if (pracownik != nullptr) {
        cout << "Ilość pracowników: " << rozmiar;
    }

    sredniaZarobkow(pracownik, rozmiar);
    wyplaty(pracownik, rozmiar);
    maxZarobki(pracownik, rozmiar);
    minZarobki(pracownik, rozmiar);
    stanowiskaPracy(pracownik, rozmiar);
}
void statystykiPracownikow(Pracownik** pracownik, const size_t rozmiar) {
    cout << endl << "<======= Statystyki pracowników =======>" << endl << endl;

    if (pracownik != nullptr) {
        cout << "Ilość pracowników: " << rozmiar;
    }
    sredniaZarobkow(pracownik, rozmiar);
    wyplaty(pracownik, rozmiar);
    maxZarobki(pracownik, rozmiar);
    minZarobki(pracownik, rozmiar);
    stanowiskaPracy(pracownik, rozmiar);
}


void zmianaWynagordzenia(Pracownik** pracownik) {
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
void zmianaWynagordzenia(Pracownik* pracownik) {
    int index, choice;
    double kwota = 0;

    cout << "Indeks pracownika do zmiany wynagrodzenia: ";
    cin >> index;

    cout << endl << "Pracownik: " << pracownik[index].getImie() << " " << pracownik[index].getNazwisko() << endl;
    cout << "Stanowisko: " << pracownik[index].getStanowisko() << endl;
    cout << "Wynagrodzenie: " << pracownik[index].getWynagrodzenie() << endl << endl;

    cout << "Zmniejszyć, czy zwiekszyć wynagrodzenie? " << endl;
    cout << "Zmniejszyć - 0 " << endl;
    cout << "Zwiększyć - 1 " << endl;
    cout << "Twój wybór: ";
    cin >> choice;

    switch (choice) {
    case(0):
        cout << endl << "O jaką kwotę zmniejszyć wynagrodzenie: ";
        cin >> kwota;
        pracownik[index].setWynagrodzenie(pracownik[index].getWynagrodzenie() - kwota);
        break;
    case(1):
        cout << endl << "O jaką kwotę zwiększyć wynagrodzenie: ";
        cin >> kwota;
        pracownik[index].setWynagrodzenie(pracownik[index].getWynagrodzenie() + kwota);
        break;
    default:
        cout << endl << "Coś poszło nie tak, spróbuj ponownie." << endl;
        break;
    }

    if (kwota != 0) {
        cout << endl << "Informacje po zmianie: " << endl;
        cout << "Pracownik: " << pracownik[index].getImie() << " " << pracownik[index].getNazwisko() << endl;
        cout << "Stanowisko: " << pracownik[index].getStanowisko() << endl;
        cout << "Wynagrodzenie: " << pracownik[index].getWynagrodzenie() << endl;
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