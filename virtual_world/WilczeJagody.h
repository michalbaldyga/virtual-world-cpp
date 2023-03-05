#pragma once
#include "Roslina.h"

#define SILA_JAGOD 99
#define SYMBOL_JAGOD 'J'

class WilczeJagody : public Roslina {
public:
	WilczeJagody(const Polozenie& polozenie, Swiat& swiat);
	Organizm* stworzPotomka(const Polozenie& polozenie, Swiat& swiat) override;
	void kolizja(Organizm& atakujacy) override;
	string getNazwa() const override;
};