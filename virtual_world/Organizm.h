#pragma once
#include "Swiat.h"
#include <stdlib.h>
#include <string>
#include <vector>

#define ORGANIZM_ZGINAL -1
#define ZASIEG_RUCHU 1

using namespace std;

struct Polozenie {
	unsigned x;
	unsigned y;
};

class Swiat;

class Organizm {
protected:
	char symbol;
	unsigned sila;
	int inicjatywa;
	Polozenie polozenie;
	Swiat &swiat;

	virtual bool czyOdbilAtak(const Organizm& atakujacy) const;
	virtual bool czyZrobilUnik(const Organizm& atakujacy) const;
	bool czySilniejszy(const Organizm& atakowany) const;
	bool czyPoleWolne(const Polozenie& p) const;

	vector<Polozenie> znajdzWolnePola(const Organizm& o);
	vector<Polozenie> znajdzSasiedniePola(const unsigned& zasieg);

	virtual Organizm* stworzPotomka(const Polozenie& polozenie, Swiat& swiat) = 0;

public:
	Organizm(const char& symbol, const unsigned& sila, const int& inicjatywa, const Polozenie& polozenie, Swiat &swiat);

	virtual void akcja() = 0;
	virtual void kolizja(Organizm& atakujacy) = 0;
	virtual string przygotujDoZapisu();
	void rysowanie();

	unsigned getX() const;
	unsigned getY() const;
	int getInicjatywa() const;
	unsigned getSila() const;
	char getSymbol() const;
	Polozenie getPolozenie() const;
	virtual string getNazwa() const = 0;

	void setPolozenie(const Polozenie& nowePolozenie);
	void setInicjatywa(const int& inicjatywa);
	void setSila(const unsigned& sila);

	~Organizm();
};