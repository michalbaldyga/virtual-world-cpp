#pragma once
#pragma warning(disable:4996)
#include "Komentator.h"
#include "Organizm.h"

#include <list>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <iostream>
#include <fstream>

#define POCZATKOWA_ILOSC_ORGANIZMOW 2

using namespace std;

struct Polozenie;
class Komentator;
class Organizm;

class Swiat {
private:
	unsigned wysokosc;
	unsigned szerokosc;
	Komentator *komentator;
	Organizm* **organizmy; //tablica 2d z organizmami
	list<Organizm*> kolejka; //kolejka wed³ug której organizmy bêd¹ wykonywaæ akcjê
	list<Organizm*> martweOrganizmy; //organizmy które trzeba usunaæ z kolejki po skoñczonej turze

	void inicjalizujOrganizmy();
	void sortujKolejke();
	void rysujMenu();

	Organizm* znajdzCzlowieka();
	vector<Polozenie> znajdzPolaGenerowania();

	void wczytajOrganizm(string& dane);
	void stworzOrganizm(const char& symbol, const Polozenie& p, const unsigned& sila);
	void stworzOrganizm(const char& symbol, const Polozenie& p, const unsigned& sila, const unsigned& umiejetnosc, const unsigned& cooldown);
	void setWymiary(const string& dane);

public:
	Swiat(unsigned x, unsigned y);

	void inicjalizujSwiat();
	void rysujSwiat();
	void wykonajTure();
	void wyczyscSwiat();

	void generujOrganizmy();
	void dodajOrganizm(Organizm* o);
	void dodajDoUsuniecia(Organizm* o);
	void usunOrganizmy();

	void zapiszStan();
	void wczytajStan();

	unsigned getWysokosc() const;
	unsigned getSzerokosc() const;
	Organizm*** getOrganizmy() const;
	list<Organizm*> getKolejka() const;
	Organizm* getOrganizm(const Polozenie& p) const;
	Komentator* getKomentator() const;

	void setOrganizm(const Polozenie& p, Organizm* o);

	~Swiat();
};