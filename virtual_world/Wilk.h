#pragma once
#include "Zwierze.h"

#define SILA_WILKA 9
#define INICJATYWA_WILKA 5
#define SYMBOL_WILKA 'W'

class Wilk : public Zwierze {
public:
	Wilk(const Polozenie& polozenie, Swiat& swiat);
	Organizm* stworzPotomka(const Polozenie& polozenie, Swiat& swiat) override;
	string getNazwa() const override;
};