#pragma once
#include "Roslina.h"

#define SILA_TRAWY 0
#define SYMBOL_TRAWY 'T'

class Trawa : public Roslina {
public:
	Trawa(const Polozenie& polozenie, Swiat& swiat);
	Organizm* stworzPotomka(const Polozenie& polozenie, Swiat& swiat) override;
	string getNazwa() const override;
};