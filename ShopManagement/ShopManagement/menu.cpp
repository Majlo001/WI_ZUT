#include <iostream>
#include <locale>
#include <cstdlib>
#include "Pracownik.h"
#include "Produkty.h"

using namespace std;


void listaZadanPracownicyMenu(Pracownik*& pracownik, size_t& rozmiar, size_t index) {
    setlocale(LC_CTYPE, "Polish");

    int programExit = 1;

    do {
        int choice;
        int indexZad;

        cout << "<======= MENU LISTA ZADA� PRACOWNIK�W =======>" << endl << endl;
        cout << "Pracownik: " << pracownik[index].getID() << " " << pracownik[index].getImie() << " " << pracownik[index].getNazwisko() << endl << endl;
        cout << "1. Poka� list� zada�" << endl;
        cout << "2. Dodaj do listy zada�" << endl;
        cout << "3. Usu� z listy zada� po indeksie" << endl;
        cout << "4. Usu� ca�� list� zada�" << endl;
        cout << "0. Wr�� do g��wnego menu" << endl << endl;
        cout << "<============================================>" << endl << endl;
        cout << "Wybierz funkcj�: ";
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
            cout << "B��d, co� posz�o nie tak" << endl;
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
        cout << "3. Lista pracownik�w" << endl;
        cout << "4. Dodaj nowego pracownika" << endl;
        cout << "5. Statystyki pracownik�w" << endl;
        cout << "6. Zmaina wynagrodzenia pracownika" << endl;
        cout << "7. Lista zada� pracownika" << endl;
        cout << "0. Wr�� do g��wnego menu" << endl << endl;
        cout << "<===============================>" << endl << endl;
        cout << "Wybierz funkcj�: ";
        cin >> choice;


        switch (choice) {
        case(1):
            stworz(pracownicy, rozmiar);
            ini(pracownicy, rozmiar);
            break;
        case(2):
            cout << "Indeks pracownika do usuni�cia: ";
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
                cout << "Brak pracownik�w" << endl;
            }
            break;
        case(6):
            if (pracownicy != nullptr) {
                zmianaWynagordzenia(pracownicy);
            }
            else {
                cout << "Brak pracownik�w" << endl;
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
            cout << "B��d, co� posz�o nie tak" << endl;
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
        cout << "2. Usuwanie produkt�w" << endl;
        cout << "3. Lista produkt�w" << endl;
        cout << "4. Dodaj nowy produkt" << endl;
        //cout << "5. Statystyki produkt�w" << endl;
        cout << "6. Zmiana ceny produktu" << endl;
        cout << "7. Dodawanie ilo�ci produktu" << endl;
        cout << "0. Wr�� do g��wnego menu" << endl << endl;
        cout << "<=============================>" << endl << endl;
        cout << "Wybierz funkcj�: ";
        cin >> choice;


        switch (choice) {
        case(1):
            stworz(produkty, rozmiarProd);
            ini(produkty, rozmiarProd);
            break;
        case(2):
            cout << "Indeks produktu do usuni�cia: ";
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
                cout << "Brak produkt�w" << endl;
            }
            break;
        case(7):
            if (produkty != nullptr) {
                cout << "Podaj indeks produktu: "; cin >> index;
                produkty[index]->dodajIloscProduktu();
            }
            else {
                cout << "Brak produkt�w" << endl;
            }
            break;
        case(0):
            //usun(produkty, rozmiarProd);
            programExit = 0;
            break;
        default:
            cout << "B��d, co� posz�o nie tak" << endl;
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
        cout << "1. Zarz�dzanie pracownikami" << endl;
        cout << "2. Zarz�dzanie produktami" << endl;
        cout << "0. Wyjscie z programu" << endl << endl;
        cout << "<===========================>" << endl << endl;
        cout << "Wybierz funkcj�: ";
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
            cout << "B��d, co� posz�o nie tak" << endl;
            break;
        }
        cout << endl;

        if (programExit != 0) {
            system("pause");
            system("cls");
        }
    } while (programExit != 0);
}