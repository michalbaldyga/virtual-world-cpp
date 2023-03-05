#pragma once
#include "Swiat.h"
#include <vector>
#include <iostream>
#include <string>

#define LICZBA_ROZNYCH_ROSLIN 5
enum rosliny {
	BARSZCZ,
	GUARANA,
	MLECZ,
	TRAWA,
	JAGODY
};

#define LICZBA_ROZNYCH_ZWIERZAT 5
enum zwierzeta{
	ANTYLOPA,
	LIS,
	OWCA,
	WILK,
	ZOLW
};

enum kierunki {
	GORA = 1,
	DOL,
	LEWO,
	PRAWO
};

using namespace std;

class Organizm;

class Komentator {
private:
	string informacje;
	bool czyRoslinaSieje[LICZBA_ROZNYCH_ROSLIN];
	bool czyZwierzeRozmnaza[LICZBA_ROZNYCH_ZWIERZAT];
public:
	Komentator();

	//Zwierzeta
	void zapiszAtak(const Organizm& atakujacy, const Organizm& atakowany);
	void zapiszWygrana(const Organizm& wygrany);
	void zapiszUnik(const Organizm& atakowany);
	void zapiszOdbicie(const Organizm& atakowany);
	void zapiszRozmnazanie(const Organizm& rodzic);
	void zapiszRuchCzlowieka(const unsigned& kierunek);

	//Rosliny
	void zapiszSianie(const Organizm& rodzic);
	void zapiszJedzenie(const Organizm& atakujacy, const Organizm& zjedzony);
	void zapiszWzmocnienie(const Organizm& atakujacy, const Organizm& zjedzony);
	void zapiszTrucizne(const Organizm& atakujacy, const Organizm& zjedzony);

	void podsumujSianie();
	void podsumujRozmnazanie();
	void wypiszWyniki();

	~Komentator();
};