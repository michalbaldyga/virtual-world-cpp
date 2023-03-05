#pragma once
#include "Zwierze.h"

#define SILA_LISA 3
#define INICJATYWA_LISA 7
#define SYMBOL_LISA 'L'

class Lis : public Zwierze {
public:
	Lis(const Polozenie& polozenie, Swiat& swiat);
	Organizm* stworzPotomka(const Polozenie& polozenie, Swiat& swiat) override;
	void akcja() override;
	string getNazwa() const override;
};