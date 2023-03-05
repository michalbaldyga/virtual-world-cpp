#include <iostream>
#include <windows.h>
#include "Swiat.h"
#include "Organizmy.h"

#define NIEPOPRAWNE_DANE -1

using namespace std;

int main()
{
    srand(time(NULL));

    int szerokosc, wysokosc;
    cout << "Podaj szerokosc swiata: ";
    cin >> szerokosc;
    if (std::cin.fail() || szerokosc <= 0) {
        cout << "Niepoprawne dane\n";
        return NIEPOPRAWNE_DANE;
    }

    cout << "Podaj wysokosc swiata: ";
    cin >> wysokosc;
    if (std::cin.fail() || wysokosc <= 0) {
        cout << "Niepoprawne dane\n";
        return NIEPOPRAWNE_DANE;
    }

    Swiat s(szerokosc, wysokosc);
    s.inicjalizujSwiat();
    s.generujOrganizmy();
    s.rysujSwiat();

    bool wyjscie = false;
    while (!wyjscie) {
        cout << "Wybierz opcje: ";
        char z;
        cin >> z;
        if (z == 'Z' || z == 'z')
            s.wykonajTure();
        else if (z == 'S' || z == 's') {
            s.zapiszStan();
            cout << "Stan gry zostal zapisany.\n";
        }
        else if (z == 'L' || z == 'l') {
            system("CLS");
            s.wczytajStan();
            s.rysujSwiat();
            cout << "Stan gry zostal wczytany.\n";
        }
        else if (z == 'Q' || z == 'q') {
            system("CLS");
            cout << "Koniec gry\n";
            wyjscie = true;
        }
        else {
            cout << "Nieznane polecenie\n";
        }
    }

    return 0;
}