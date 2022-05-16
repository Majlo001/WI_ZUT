#pragma once
#include <iostream>
#include <locale>
#include <cstdlib>

using namespace std;




class Pracownik {
    class Zadania {
        friend class Pracownik;

        string opis{ "Przykładowy opis" };
        bool zrobione{ false };
    public:
        string getOpis();
        bool getZrobione();
        void setOpis(string);
        void setZrobione(bool);
    };

    const int id;
    string imie;
    string nazwisko;
    string stanowisko;
    double wynagrodzenie;
    size_t iloscZadan{ 0 };
    Zadania** listaZadan;
public:
    Pracownik();
    Pracownik(string, string, string, double);
    ~Pracownik();
    Pracownik(const Pracownik&);
    int getID();
    string getImie();
    string getNazwisko();
    string getStanowisko();
    double getWynagrodzenie();
    int getIloscZadan();
    void setImie(string);
    void setNazwisko(string);
    void setStanowisko(string);
    void setWynagrodzenie(double);
    void setIloscZadan(size_t);

    //Przeładowanie operatorów
    Pracownik& operator=(const Pracownik& pracownik);
    friend ostream& operator<<(ostream& out, const Pracownik& pracownik);
    auto& operator[](int index);

    void stworz(Zadania**& listaZadan, const size_t rozmiar);
    void usun();
    void usun(size_t index);
    void dodaj();
    void print();
};


template <class T> void stworz(T*& obj, const size_t n) {
    obj = new T[n];
    cout << "Działa";
}

template <class T> void bubbleSort(T a[], size_t n) {
    for (size_t i = 0; i < n - 1; i++)
        for (size_t j = n - 1; i < j; j--)
            if (a[j].getNazwisko() < a[j - 1].getNazwisko()) {
                T tmp = a[j];
                a[j] = a[j - 1];
                a[j - 1] = tmp;
            }
}
template <class T> T max(T& a, T& b) {
    return(a > b) ? a : b;
}




inline int Pracownik::getID() { return id; }
inline string Pracownik::getImie() { return imie; }
inline string Pracownik::getNazwisko() { return nazwisko; }
inline string Pracownik::getStanowisko() { return stanowisko; }
inline double Pracownik::getWynagrodzenie() { return wynagrodzenie; }
inline int Pracownik::getIloscZadan() { return iloscZadan; }

inline void Pracownik::setImie(string i) { imie = i; }
inline void Pracownik::setNazwisko(string n) { nazwisko = n; }
inline void Pracownik::setStanowisko(string s) { stanowisko = s; }
inline void Pracownik::setWynagrodzenie(double w) { wynagrodzenie = w; }
inline void Pracownik::setIloscZadan(size_t i) { iloscZadan = i; }


inline string Pracownik::Zadania::getOpis() { return opis; }
inline bool Pracownik::Zadania::getZrobione() { return zrobione; }
inline void Pracownik::Zadania::setOpis(string o) { opis = o; }
inline void Pracownik::Zadania::setZrobione(bool z) { zrobione = z; }


int idPracownika();


void stworz(Pracownik*& pracownik);
void stworz(Pracownik**& pracownik);
//void stworz(Pracownik*& pracownik, const size_t rozmiar);
void stworz(Pracownik**& pracownicy, const size_t rozmiar);
//void stworz(Zadania**& listaZadan, const size_t rozmiar);

void ini(Pracownik*& pracownik);
void ini(Pracownik& pracownik);
void ini(Pracownik* pracownik, const size_t rozmiar);
void ini(Pracownik** pracownicy, const size_t rozmiar);
void dodaj(Pracownik**& pracownicyAll, size_t& size);
void dodaj(Pracownik*& pracownicyAll, size_t& size);
void print(Pracownik* mPracownik);
void print(Pracownik* pracownik, const size_t rozmiar);
void print(Pracownik** pracownicy, const size_t rozmiar);
void usun(Pracownik*& pracownik);
void usun(Pracownik*& pracownik, size_t& rozmiar);
void usun(Pracownik**& pracownicy, size_t& rozmiar);
void usun(Pracownik*& pracownicyAll, size_t& size, size_t index);
void usun(Pracownik**& pracownicyAll, size_t& size, size_t index);
//void usun(Zadania**& listaZadan, size_t& rozmiar);

void stanowiskaPracy(Pracownik* pracownik, const size_t rozmiar);
void stanowiskaPracy(Pracownik** pracownik, const size_t rozmiar);
void wyplaty(Pracownik* pracownik, const size_t rozmiar);
void wyplaty(Pracownik** pracownik, const size_t rozmiar);
void sredniaZarobkow(Pracownik* pracownik, const size_t rozmiar);
void sredniaZarobkow(Pracownik** pracownik, const size_t rozmiar);
void maxZarobki(Pracownik* pracownik, const size_t rozmiar);
void maxZarobki(Pracownik** pracownik, const size_t rozmiar);
void minZarobki(Pracownik* pracownik, const size_t rozmiar);
void minZarobki(Pracownik** pracownik, const size_t rozmiar);
void statystykiPracownikow(Pracownik* pracownik, const size_t rozmiar);
void statystykiPracownikow(Pracownik** pracownik, const size_t rozmiar);
void zmianaWynagordzenia(Pracownik** pracownik);
void zmianaWynagordzenia(Pracownik* pracownik);


void mainMenu();