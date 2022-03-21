#include <iostream>
#include <locale>
#include <cstdlib>
#include <algorithm>
#include <vector>

using namespace std;

struct Pracownik {
    string imie;
    string nazwisko;
    double wynagrodzenie;
    string stanowisko;
};

double randWynagrodzenie(int max, int var) {
    return rand() % max + var;
}


void stworz(Pracownik*& pracownik) {
    pracownik = new Pracownik;
}
void stworz(Pracownik**& pracownik) {
    pracownik = new Pracownik*;
}
void stworz(Pracownik*& pracownik, const size_t rozmiar) {
    pracownik = new Pracownik[rozmiar];
}
void stworz(Pracownik**& pracownicy, const size_t rozmiar) {
    pracownicy = new Pracownik * [rozmiar];
    for (size_t ind = 0; ind < rozmiar; ind++)
        pracownicy[ind] = new Pracownik;
}


void ini(Pracownik*& pracownik) {
    cout << "Wprowadź imie pracownika: ";
    cin >> pracownik->imie;
    cout << "Wprowadź nazwisko pracownika: ";
    cin >> pracownik->nazwisko;
    cout << "Wprowadź wynagrodzenie pracownika: ";
    cin >> pracownik->wynagrodzenie;
}
void ini(Pracownik& mPracownik) {
    cout << "Wprowadź imie pracownika: ";
    cin >> mPracownik.imie;
    cout << "Wprowadź nazwisko pracownika: ";
    cin >> mPracownik.nazwisko;
    cout << "Wprowadź wynagrodzenie pracownika: ";
    cin >> mPracownik.wynagrodzenie;
}
void ini(Pracownik* pracownik, const size_t rozmiar) {
    for (size_t ind = 0; ind < rozmiar; ind++) {
        pracownik[ind].wynagrodzenie = randWynagrodzenie(5000, 3000);

        cout << "Wprowadź imie pracownika: ";
        cin >> pracownik[ind].imie;
        cout << "Wprowadź nazwisko pracownika: ";
        cin >> pracownik[ind].nazwisko;
        cout << "Wprowadź stanowisko pracownika: ";
        cin >> pracownik[ind].stanowisko;
    }
}
void ini(Pracownik** pracownicy, const size_t rozmiar) {
    for (size_t ind = 0; ind < rozmiar; ind++) {
        pracownicy[ind]->wynagrodzenie = randWynagrodzenie(5000, 3000);
        cout << "Wprowadź imie pracownika: ";
        cin >> pracownicy[ind]->imie;
        cout << "Wprowadź nazwisko pracownika: ";
        cin >> pracownicy[ind]->nazwisko;
        cout << "Wprowadź stanowisko pracownika: ";
        cin >> pracownicy[ind]->stanowisko;
    }
}


void dodaj(Pracownik**& pracownicyAll, size_t& size) {
    Pracownik** temp = new Pracownik* [size + 1];
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

    pracownicyAll[size]->wynagrodzenie = randWynagrodzenie(5000, 3000);
    cout << "Wprowadź imie pracownika: ";
    cin >> pracownicyAll[size]->imie;
    cout << "Wprowadź nazwisko pracownika: ";
    cin >> pracownicyAll[size]->nazwisko;
    cout << "Wprowadź stanowisko pracownika: ";
    cin >> pracownicyAll[size]->stanowisko;

    size++;
}
void dodaj(Pracownik*& pracownicyAll, size_t& size) {
    Pracownik* temp = new Pracownik[size + 1];

    for (size_t i = 0; i < size; ++i)
        temp[i] = pracownicyAll[i];
    delete[] pracownicyAll;
    pracownicyAll = temp;

    pracownicyAll[size].wynagrodzenie = randWynagrodzenie(5000, 3000);
    cout << "Wprowadź imie pracownika: ";
    cin >> pracownicyAll[size].imie;
    cout << "Wprowadź nazwisko pracownika: ";
    cin >> pracownicyAll[size].nazwisko;
    cout << "Wprowadź stanowisko pracownika: ";
    cin >> pracownicyAll[size].stanowisko;

    size++;
}


void print(Pracownik* mPracownik) {
    cout << endl << "Pracownik: " << mPracownik->imie << " " << mPracownik->nazwisko;
    cout << endl << "Wynagrodznie: " << mPracownik->wynagrodzenie;
    cout << endl << "Stanowisko: " << mPracownik->stanowisko;
}
void print(Pracownik* pracownik, const size_t rozmiar) {
    std::cout << "<======= Pracownicy =======>" << std::endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        cout << pracownik[ind].imie << "\t" << pracownik[ind].nazwisko << "\t" << pracownik[ind].wynagrodzenie << "\t" << pracownik[ind].stanowisko << endl;
    }
}
void print(Pracownik** pracownicy, const size_t rozmiar) {
    cout << "<======= Pracownicy =======>" << endl;
    for (size_t ind = 0; ind < rozmiar; ind++) {
        cout << pracownicy[ind]->imie << "\t" << pracownicy[ind]->nazwisko << "\t" << pracownicy[ind]->wynagrodzenie << "\t" << pracownicy[ind]->stanowisko << endl;
    }
}


void usun(Pracownik* pracownik) {
    delete pracownik;
    pracownik = nullptr;
    cout << endl << "Pracownik usuniety!";
}
void usun(Pracownik*& pracownik) {
    delete pracownik;
    pracownik = nullptr;
    cout << endl << "Pracownik usuniety!";
}
void usun(Pracownik** pracownik) {
    delete* pracownik;
    *pracownik = nullptr;
    cout << endl << "Pracownik usuniety!";
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
        stanowiska.push_back(pracownik[i].stanowisko);
    }

    sort(stanowiska.begin(), stanowiska.end());
    stanowiska.erase(unique(stanowiska.begin(), stanowiska.end()), stanowiska.end());

    cout << endl << "Stanowiska pracy, ilość pracowników i ich średnie wynagrodzenie: " << endl;
    for (size_t i = 0; i < stanowiska.size(); i++) {
        int count = 0;
        double srednia = 0;

        for (size_t j = 0; j < rozmiar; j++) {
            if (stanowiska[i] == pracownik[j].stanowisko) {
                count++;
                srednia += pracownik[j].wynagrodzenie;
            }
        }
        cout << stanowiska[i] << ":\t" << count << "\t" << (srednia/count) << endl;
    }
}
void stanowiskaPracy(Pracownik** pracownik, const size_t rozmiar) {
    vector <string> stanowiska;

    for (size_t i = 0; i < rozmiar; i++) {
        stanowiska.push_back(pracownik[i]->stanowisko);
    }

    sort(stanowiska.begin(), stanowiska.end());
    stanowiska.erase(unique(stanowiska.begin(), stanowiska.end()), stanowiska.end());

    cout << endl << "Stanowiska pracy, ilość pracowników i ich średnie wynagrodzenie: " << endl;
    for (size_t i = 0; i < stanowiska.size(); i++) {
        int count = 0;
        double srednia = 0;

        for (size_t j = 0; j < rozmiar; j++) {
            if (stanowiska[i] == pracownik[j]->stanowisko) {
                count++;
                srednia += pracownik[j]->wynagrodzenie;
            }
        }
        cout << stanowiska[i] << ":\t" << count << "\t" << (srednia/count) << endl;
    }
}
void wyplaty(Pracownik* pracownik, const size_t rozmiar) {
    double wyplaty = 0;
    for (size_t i = 0; i < rozmiar; i++) {
        wyplaty += pracownik[i].wynagrodzenie;
    }
    cout << "Wydatki na wypłaty: " << wyplaty << endl;
}
void wyplaty(Pracownik** pracownik, const size_t rozmiar) {
    double wyplaty = 0;
    for (size_t i = 0; i < rozmiar; i++) {
        wyplaty += pracownik[i]->wynagrodzenie;
    }
    cout << "Wydatki na wypłaty: " << wyplaty << endl;
}
void sredniaZarobkow(Pracownik* pracownik, const size_t rozmiar) {
    double sredniaZar = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        sredniaZar += pracownik[i].wynagrodzenie;
    }
    cout << endl;
    cout << "Średnia zarobków pracowników: " << (sredniaZar / rozmiar) << endl;
}
void sredniaZarobkow(Pracownik** pracownik, const size_t rozmiar) {
    double sredniaZar = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        sredniaZar += pracownik[i]->wynagrodzenie;
    }
    cout << endl;
    cout << "Średnia zarobków pracowników: " << (sredniaZar / rozmiar) << endl;
}
void maxZarobki(Pracownik* pracownik, const size_t rozmiar) {
    int index = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        if (pracownik[i].wynagrodzenie > pracownik[index].wynagrodzenie){
            index = i;
        }
    }
    cout << endl << "Najwyższe zarobki: " << pracownik[index].imie << " " << pracownik[index].nazwisko << " " << pracownik[index].wynagrodzenie << " " << pracownik[index].stanowisko << endl;
}
void maxZarobki(Pracownik** pracownik, const size_t rozmiar) {
    int index = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        if (pracownik[i]->wynagrodzenie > pracownik[index]->wynagrodzenie) {
            index = i;
        }
    }
    cout << endl << "Najwyższe zarobki: " << pracownik[index]->imie << " " << pracownik[index]->nazwisko << " " << pracownik[index]->wynagrodzenie << " " << pracownik[index]->stanowisko << endl;
}
void minZarobki(Pracownik* pracownik, const size_t rozmiar) {
    int index = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        if (pracownik[i].wynagrodzenie < pracownik[index].wynagrodzenie) {
            index = i;
        }
    }
    cout << "Najniższe zarobki: " << pracownik[index].imie << " " << pracownik[index].nazwisko << " " << pracownik[index].wynagrodzenie << " " << pracownik[index].stanowisko << endl;
}
void minZarobki(Pracownik** pracownik, const size_t rozmiar) {
    int index = 0;

    for (size_t i = 0; i < rozmiar; i++) {
        if (pracownik[i]->wynagrodzenie < pracownik[index]->wynagrodzenie) {
            index = i;
        }
    }
    cout << "Najniższe zarobki: " << pracownik[index]->imie << " " << pracownik[index]->nazwisko << " " << pracownik[index]->wynagrodzenie << " " << pracownik[index]->stanowisko << endl;
}
void statystykiPracownikow(Pracownik* pracownik, const size_t rozmiar) {
    cout << endl <<"<======= Statystyki pracowników =======>" << endl << endl;

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

    cout << endl << "Pracownik: " << pracownik[index]->imie << " " << pracownik[index]->nazwisko << endl;
    cout << "Stanowisko: " << pracownik[index]->stanowisko << endl;
    cout << "Wynagrodzenie: " << pracownik[index]->wynagrodzenie << endl << endl;

    cout << "Zmniejszyć, czy zwiekszyć wynagrodzenie? " << endl;
    cout << "Zmniejszyć - 0 " << endl;
    cout << "Zwiększyć - 1 " << endl;
    cout << "Twój wybór: ";
    cin >> choice;

    switch (choice) {
    case(0):
        cout << endl << "O jaką kwotę zmniejszyć wynagrodzenie: ";
        cin >> kwota;
        pracownik[index]->wynagrodzenie = pracownik[index]->wynagrodzenie - kwota;
        break;
    case(1):
        cout << endl << "O jaką kwotę zwiększyć wynagrodzenie: ";
        cin >> kwota;
        pracownik[index]->wynagrodzenie = pracownik[index]->wynagrodzenie + kwota;
        break;
    default:
        cout << endl << "Coś poszło nie tak, spróbuj ponownie." << endl;
        break;
    }

    if (kwota != 0) {
        cout << endl << "Informacje po zmianie: " << endl;
        cout << "Pracownik: " << pracownik[index]->imie << " " << pracownik[index]->nazwisko << endl;
        cout << "Stanowisko: " << pracownik[index]->stanowisko << endl;
        cout << "Wynagrodzenie: " << pracownik[index]->wynagrodzenie << endl;
    }
}
void zmianaWynagordzenia(Pracownik* pracownik) {
    int index, choice;
    double kwota = 0;

    cout << "Indeks pracownika do zmiany wynagrodzenia: ";
    cin >> index;

    cout << endl << "Pracownik: " << pracownik[index].imie << " " << pracownik[index].nazwisko << endl;
    cout << "Stanowisko: " << pracownik[index].stanowisko << endl;
    cout << "Wynagrodzenie: " << pracownik[index].wynagrodzenie << endl << endl;

    cout << "Zmniejszyć, czy zwiekszyć wynagrodzenie? " << endl;
    cout << "Zmniejszyć - 0 " << endl;
    cout << "Zwiększyć - 1 " << endl;
    cout << "Twój wybór: ";
    cin >> choice;

    switch (choice) {
    case(0):
        cout << endl << "O jaką kwotę zmniejszyć wynagrodzenie: ";
        cin >> kwota;
        pracownik[index].wynagrodzenie = pracownik[index].wynagrodzenie - kwota;
        break;
    case(1):
        cout << endl << "O jaką kwotę zwiększyć wynagrodzenie: ";
        cin >> kwota;
        pracownik[index].wynagrodzenie = pracownik[index].wynagrodzenie + kwota;
        break;
    default:
        cout << endl << "Coś poszło nie tak, spróbuj ponownie." << endl;
        break;
    }

    if (kwota != 0) {
        cout << endl << "Informacje po zmianie: " << endl;
        cout << "Pracownik: " << pracownik[index].imie << " " << pracownik[index].nazwisko << endl;
        cout << "Stanowisko: " << pracownik[index].stanowisko << endl;
        cout << "Wynagrodzenie: " << pracownik[index].wynagrodzenie << endl;
    }
}


void menu() {
    setlocale(LC_CTYPE, "Polish");

    int programExit = 1;
    //Pracownik pracownicy;
    //Pracownik* pracownicy = nullptr;
    Pracownik** pracownicy = nullptr;

    size_t rozmiar = 3;

    do {
        int choice;
        int index;

        cout << "<======= MENU =======>" << endl << endl;
        cout << "1. Tworzenie bazy pracownika" << endl;
        cout << "2. Usuwanie pracownika" << endl;
        cout << "3. Lista pracowników" << endl;
        cout << "4. Dodaj nowego pracownika" << endl;
        cout << "5. Statystyki pracowników" << endl;
        cout << "6. Zmaina wynagrodzenia pracownika" << endl;
        cout << "0. Wyjscie z programu" << endl << endl;
        cout << "<====================>" << endl << endl;
        cout << "Wybierz funkcję: ";
        cin >> choice;


        switch (choice) {
        case(1):
            stworz(pracownicy, rozmiar);
            ini(pracownicy, rozmiar);
            break;
        case(2):
            cout << "Indeks pracownika do usunięcia: ";
            cin >> index;
            //usun(pracownicy, rozmiar);
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
            } else {
                cout << "Brak pracowników" << endl;
            }
            break;
        case(6):
            if (pracownicy != nullptr) {
                zmianaWynagordzenia(pracownicy);
            } else {
                cout << "Brak pracowników" << endl;
            }
            break;
        case(0):
            usun(pracownicy, rozmiar);
            programExit = 0;
            break;
        default:
            cout << "Bląd, coś poszło nie tak" << endl;
            break;
        }
        cout << endl;

        if (programExit != 0) {
            system("pause");
            system("cls");
        }


    } while (programExit != 0);
}

int main() {
    menu();
}
