#include <iostream>
#include <locale>
#include <cstdlib>
#include "Pracownik.h"
#include "Produkty.h"
#include "Utilities.h"

using namespace std;


void listaZadanPracownicyMenu(Pracownik*& pracownik, size_t& rozmiar, size_t index) {
    setlocale(LC_CTYPE, "Polish");

    int programExit = 1;

    do {
        int choice;
        int indexZad;

        cout << "<======= MENU LISTA ZADAŃ PRACOWNIKÓW =======>" << endl << endl;
        cout << "Pracownik: " << pracownik[index].getID() << " " << pracownik[index].getImie() << " " << pracownik[index].getNazwisko() << endl << endl;
        cout << "1. Pokaż listę zadań" << endl;
        cout << "2. Dodaj do listy zadań" << endl;
        cout << "3. Usuń z listy zadań po indeksie" << endl;
        cout << "4. Usuń całą listę zadań" << endl;
        cout << "0. Wróć do głównego menu" << endl << endl;
        cout << "<============================================>" << endl << endl;
        cout << "Wybierz funkcję: ";
        cin >> choice;


        switch (choice) {
        case(1):
            pracownik[index].print();
            break;
        case(2):
            pracownik[index].dodaj();
            break;
        case(3):
            cout << "Podaj indeks zadania: ";
            cin >> indexZad;
            pracownik[index].usun(indexZad);
            break;
        case(4):
            pracownik[index].usun();
            break;
        case(0):
            programExit = 0;
            break;
        default:
            cout << "Błąd, coś poszło nie tak" << endl;
            break;
        }
        cout << endl;

        if (programExit != 0) {
            system("pause");
            system("cls");
        }


    } while (programExit != 0);
}

void pracownicyMenu(Pracownik*& pracownicy, size_t& rozmiar) {
    setlocale(LC_CTYPE, "Polish");

    int programExit = 1;

    do {
        int choice;
        int index;

        cout << "<======= MENU PRACOWNICY =======>" << endl << endl;
        cout << "1. Tworzenie bazy pracownika" << endl;
        cout << "2. Usuwanie pracownika" << endl;
        cout << "3. Lista pracowników" << endl;
        cout << "4. Dodaj nowego pracownika" << endl;
        cout << "5. Statystyki pracowników" << endl;
        cout << "6. Zmaina wynagrodzenia pracownika" << endl;
        cout << "7. Lista zadań pracownika" << endl;
        cout << "0. Wróć do głównego menu" << endl << endl;
        cout << "<===============================>" << endl << endl;
        cout << "Wybierz funkcję: ";
        cin >> choice;


        switch (choice) {
        case(1):
            stworz(pracownicy, rozmiar);
            ini(pracownicy, rozmiar);
            //bubbleSort<Pracownik>(pracownicy, rozmiar);
            break;
        case(2):
            cout << "Indeks pracownika do usunięcia: ";
            cin >> index;
            usun(pracownicy, rozmiar, index);
            break;
        case(3):
            print(pracownicy, rozmiar);
            break;
        case(4):
            dodaj(pracownicy, rozmiar);
            break;
        case(5):
            if (pracownicy != nullptr) {
                statystykiPracownikow(pracownicy, rozmiar);
            }
            else {
                cout << "Brak pracowników" << endl;
            }
            break;
        case(6):
            if (pracownicy != nullptr) {
                zmianaWynagordzenia(pracownicy);
            }
            else {
                cout << "Brak pracowników" << endl;
            }
            break;
        case(7):
            cout << "Indeks pracownika: ";
            cin >> index;

            system("cls");
            listaZadanPracownicyMenu(pracownicy, rozmiar, index);
            break;
        case(0):
            //usun(pracownicy, rozmiar);
            programExit = 0;
            break;
        default:
            cout << "Błąd, coś poszło nie tak" << endl;
            break;
        }
        cout << endl;

        if (programExit != 0) {
            system("pause");
            system("cls");
        }


    } while (programExit != 0);
}
void produktyMenu(Produkt**& produkty, size_t& rozmiarProd) {
    setlocale(LC_CTYPE, "Polish");

    int programExit = 1;

    do {
        int choice;
        int index;

        cout << "<======= MENU Produkty =======>" << endl << endl;
        cout << "1. Tworzenie bazy produkt�w" << endl;
        cout << "2. Usuwanie produktów" << endl;
        cout << "3. Lista produktów" << endl;
        cout << "4. Dodaj nowy produkt" << endl;
        //cout << "5. Statystyki produkt�w" << endl;
        cout << "6. Zmiana ceny produktu" << endl;
        cout << "7. Dodawanie ilości produktu" << endl;
        cout << "0. Wróć do głównego menu" << endl << endl;
        cout << "<=============================>" << endl << endl;
        cout << "Wybierz funkcję: ";
        cin >> choice;


        switch (choice) {
        case(1):
            stworz(produkty, rozmiarProd);
            ini(produkty, rozmiarProd);
            break;
        case(2):
            cout << "Indeks produktu do usunięcia: ";
            cin >> index;
            usun(produkty, rozmiarProd, index);
            break;
        case(3):
            print(produkty, rozmiarProd);
            break;
        case(4):
            dodaj(produkty, rozmiarProd);
            break;
            /*case(5):
                if (produkty != nullptr) {
                    statystykiPracownikow(produkty, rozmiarProd);
                }
                else {
                    cout << "Brak produkt�w" << endl;
                }
                break;*/
        case(6):
            if (produkty != nullptr) {
                zmianaCeny(produkty);
            }
            else {
                cout << "Brak produktów" << endl;
            }
            break;
        case(7):
            if (produkty != nullptr) {
                cout << "Podaj indeks produktu: "; cin >> index;
                produkty[index]->dodajIloscProduktu();
            }
            else {
                cout << "Brak produktów" << endl;
            }
            break;
        case(0):
            //usun(produkty, rozmiarProd);
            programExit = 0;
            break;
        default:
            cout << "Błąd, coś poszło nie tak" << endl;
            break;
        }
        cout << endl;

        if (programExit != 0) {
            system("pause");
            system("cls");
        }


    } while (programExit != 0);
}

void mainMenu() {
    setlocale(LC_CTYPE, "Polish");

    int programExit = 1;
    Pracownik* pracownicy = nullptr;
    Produkt** produkty = nullptr;

    size_t rozmiarPrac = 3;
    size_t rozmiarProd = 3;



    do {
        int choice;

        cout << "<======= MENU SKLEPU =======>" << endl << endl;
        cout << "1. Zarządzanie pracownikami" << endl;
        cout << "2. Zarządzanie produktami" << endl;
        cout << "3. Dziennik logów" << endl;
        cout << "0. Wyjscie z programu" << endl << endl;
        cout << "<===========================>" << endl << endl;
        cout << "Wybierz funkcję: ";
        cin >> choice;


        switch (choice) {
        case(1):
            system("cls");
            pracownicyMenu(pracownicy, rozmiarPrac);
            break;
        case(2):
            system("cls");
            produktyMenu(produkty, rozmiarProd);
            break;
        case(0):
            usun(pracownicy, rozmiarPrac);
            usun(produkty, rozmiarProd);
            programExit = 0;
            break;
        default:
            cout << "Błąd, coś poszło nie tak" << endl;
            break;
        }
        cout << endl;

        if (programExit != 0) {
            system("pause");
            system("cls");
        }
    } while (programExit != 0);
}
