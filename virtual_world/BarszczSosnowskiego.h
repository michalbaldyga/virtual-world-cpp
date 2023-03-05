#pragma once
#include "Roslina.h"

#define SILA_BARSZCZU 10
#define SYMBOL_BARSZCZU 'B'

class BarszczSosnowskiego : public Roslina {
public:
	BarszczSosnowskiego(const Polozenie& polozenie, Swiat& swiat);
	Organizm* stworzPotomka(const Polozenie& polozenie, Swiat& swiat) override;
	void kolizja(Organizm& atakujacy) override;
	void akcja() override;
	string getNazwa() const override;
};