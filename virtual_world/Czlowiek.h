#pragma once
#include "Zwierze.h"
#include <conio.h> 

#define STRZALKA 224
#define STRZALKA_W_GORE 72
#define STRZALKA_W_DOL 80
#define STRZALKA_W_LEWO 75
#define STRZALKA_W_PRAWO 77

#define GORA 1
#define DOL 2
#define LEWO 3
#define PRAWO 4

#define SILA_CZLOWIEKA 5
#define INICJATYWA_CZLOWIEKA 4
#define SYMBOL_CZLOWIEKA 'C'
#define CZAS_TRWANIA_UMIEJETNOSCI 5
#define CZAS_LADOWANIA_UMIEJETNOSCI 5

using namespace std;

class Czlowiek : public Zwierze {
private:
	unsigned pozostalyCzasUmiejetnosci;
	unsigned pozostalyCzasLadowania;
	unsigned kierunekRuchu;
public:
	Czlowiek(const Polozenie& polozenie, Swiat& swiat);

	void akcja() override;
	void kolizja(Organizm& atakujacy) override;
	Organizm* stworzPotomka(const Polozenie& polozenie, Swiat& swiat) override;

	void sprawdzZdarzenie();
	void aktywujUmiejetnosc();
	void aktualizujUmiejetnosc();
	bool czyOdbilAtak(const Organizm& atakujacy) const override;

	unsigned getPozostalyCzasUmiejetnosci();
	unsigned getPozostalyCzasLadowania();
	string getNazwa() const override;

	void setPozostalyCzasUmiejetnosci(unsigned czas);
	void setPozostalyCzasLadowania(unsigned czas);

	string przygotujDoZapisu() override;
};