#pragma once
#include "Roslina.h"

#define SILA_MLECZA 0
#define SYMBOL_MLECZA 'M'
#define LICZBA_PROB_ZASIANIA_MLECZA 3

class Mlecz : public Roslina {
public:
	Mlecz(const Polozenie& polozenie, Swiat& swiat);
	Organizm* stworzPotomka(const Polozenie& polozenie, Swiat& swiat) override;
	void akcja() override;
	string getNazwa() const override;
};