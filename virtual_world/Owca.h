#pragma once
#include "Zwierze.h"

#define SILA_OWCY 4
#define INICJATYWA_OWCY 4
#define SYMBOL_OWCY 'O'

class Owca : public Zwierze {
public:
	Owca(const Polozenie& polozenie, Swiat& swiat);
	Organizm* stworzPotomka(const Polozenie& polozenie, Swiat& swiat) override;
	string getNazwa() const override;
};