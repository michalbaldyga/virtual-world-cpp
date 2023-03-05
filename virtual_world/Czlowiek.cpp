#include "Czlowiek.h"

Czlowiek::Czlowiek(const Polozenie& polozenie, Swiat& swiat)
	: Zwierze(SYMBOL_CZLOWIEKA, SILA_CZLOWIEKA, INICJATYWA_CZLOWIEKA, polozenie, swiat) {
    pozostalyCzasUmiejetnosci = 0;
    pozostalyCzasLadowania = 0;
    kierunekRuchu = NULL;
}


void Czlowiek::akcja() {
    if (kierunekRuchu != NULL) {
        if (kierunekRuchu == GORA)
            sprobujWykonacRuch({ polozenie.x - 1, polozenie.y });
        else if (kierunekRuchu == DOL)
            sprobujWykonacRuch({ polozenie.x + 1, polozenie.y });
        else if (kierunekRuchu == LEWO)
            sprobujWykonacRuch({ polozenie.x, polozenie.y - 1 });
        else
            sprobujWykonacRuch({ polozenie.x, polozenie.y + 1 });
        swiat.getKomentator()->zapiszRuchCzlowieka(kierunekRuchu);
    }
    else
        return;
}

void Czlowiek::kolizja(Organizm& atakujacy) {
    if (czyOdbilAtak(atakujacy)) {
        swiat.getKomentator()->zapiszAtak(atakujacy, *this);
        swiat.getKomentator()->zapiszOdbicie(*this);
        vector<Polozenie> wolnePola = znajdzWolnePola(*this);
        if (wolnePola.empty())
            return;
        else
            dynamic_cast<Zwierze*>(&atakujacy)->zmienPolozenie(wolnePola[rand() % wolnePola.size()]);
    }
    else
        walcz(atakujacy);
}

Organizm* Czlowiek::stworzPotomka(const Polozenie& polozenie, Swiat& swiat) {
    return NULL;
}


void Czlowiek::sprawdzZdarzenie() {
    bool czyPoprawnyRuch = false;
    while (czyPoprawnyRuch != true) {
        if (pozostalyCzasLadowania == 0 && pozostalyCzasUmiejetnosci == 0)
            cout << "Wybierz kierunek ruchu czlowieka (strzalki) lub aktywuj jego umiejetnosc (X): ";
        else
            cout << "Wybierz kierunek ruchu czlowieka (strzalki): ";
        unsigned char ch1 = _getch();
        if (ch1 == STRZALKA)
        {
            unsigned char ch2 = _getch();
            if (ch2 == STRZALKA_W_GORE) {
                if (polozenie.x >= ZASIEG_RUCHU) {
                    kierunekRuchu = GORA;
                    czyPoprawnyRuch = true;
                }
                else
                    cout << "Czlowiek nie moze sie poruszyc w tym kierunku!" << endl;
            }
            else if (ch2 == STRZALKA_W_DOL) {
                if (polozenie.x < swiat.getWysokosc() - ZASIEG_RUCHU) {
                    kierunekRuchu = DOL;
                    czyPoprawnyRuch = true;
                }
                else
                    cout << "Czlowiek nie moze sie poruszyc w tym kierunku!" << endl;
            }
            else if (ch2 == STRZALKA_W_LEWO) {
                if (polozenie.y >= ZASIEG_RUCHU) {
                    kierunekRuchu = LEWO;
                    czyPoprawnyRuch = true;
                }
                else
                    cout << "Czlowiek nie moze sie poruszyc w tym kierunku!" << endl;
            }
            else if (ch2 == STRZALKA_W_PRAWO) {
                if (polozenie.y < swiat.getSzerokosc() - ZASIEG_RUCHU) {
                    kierunekRuchu = PRAWO;
                    czyPoprawnyRuch = true;
                }
                else
                    cout << "Czlowiek nie moze sie poruszyc w tym kierunku!" << endl;
            }
        }
        else if (ch1 == 'X' || ch1 == 'x') {
            aktywujUmiejetnosc();
            
        }
        else
            cout << "Nierozpoznany klawisz\n";
    }
}

void Czlowiek::aktywujUmiejetnosc() {
    if (pozostalyCzasLadowania == 0 && pozostalyCzasUmiejetnosci == 0) {
        pozostalyCzasUmiejetnosci = CZAS_TRWANIA_UMIEJETNOSCI;
        pozostalyCzasLadowania = CZAS_LADOWANIA_UMIEJETNOSCI;
        cout << "Specjalna umiejetnosc czlowieka zostala aktywowana.\n";
    }
    else if (pozostalyCzasUmiejetnosci > 0)
        cout << "Umiejetnosc jest juz aktywna\n";
    else
        cout << "Muisz odczekac " + to_string(pozostalyCzasLadowania) + " tur aby ponownie aktywowac.\n";
}

void Czlowiek::aktualizujUmiejetnosc() {
    if (pozostalyCzasUmiejetnosci > 0)
        pozostalyCzasUmiejetnosci--;
    else if (pozostalyCzasLadowania > 0)
        pozostalyCzasLadowania--;
}

bool Czlowiek::czyOdbilAtak(const Organizm& atakujacy) const {
    if (pozostalyCzasUmiejetnosci > 0)
        return true;
    else
        return false;
}


unsigned Czlowiek::getPozostalyCzasUmiejetnosci() {
    return pozostalyCzasUmiejetnosci;
}

unsigned Czlowiek::getPozostalyCzasLadowania() {
    return pozostalyCzasLadowania;
}

string Czlowiek::getNazwa() const {
    return "Czlowiek";
}


void Czlowiek::setPozostalyCzasUmiejetnosci(unsigned czas) {
    pozostalyCzasUmiejetnosci = czas;
}

void Czlowiek::setPozostalyCzasLadowania(unsigned czas) {
    pozostalyCzasLadowania = czas;
}


string Czlowiek::przygotujDoZapisu() {
    string organizm;
    organizm += getSymbol();
    organizm += ";" + to_string(getPolozenie().x);
    organizm += ";" + to_string(getPolozenie().y);
    organizm += ";" + to_string(getSila());
    organizm += ";" + to_string(getPozostalyCzasUmiejetnosci());
    organizm += ";" + to_string(getPozostalyCzasLadowania()) + "\n";
    return organizm;
}