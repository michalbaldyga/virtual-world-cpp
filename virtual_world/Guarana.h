#pragma once
#include "Roslina.h"

#define SILA_GUARANY 0
#define SYMBOL_GUARANY 'G'
#define WZMOCNIENIE_GUARANY 3

class Guarana : public Roslina {
public:
	Guarana(const Polozenie& polozenie, Swiat& swiat);
	Organizm* stworzPotomka(const Polozenie& polozenie, Swiat& swiat) override;
	void kolizja(Organizm& atakujacy) override;
	string getNazwa() const override;
};