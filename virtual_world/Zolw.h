#pragma once
#include "Zwierze.h"

#define SILA_ZOLWIA 2
#define INICJATYWA_ZOLWIA 1
#define SYMBOL_ZOLWIA 'Z'
#define SZANSA_NA_RUCH_ZOLWIA 25 //25%

class Zolw : public Zwierze {
public:
	Zolw(const Polozenie& polozenie, Swiat& swiat);
	void akcja() override;
	bool czyOdbilAtak(const Organizm& atakujacy) const override;
	Organizm* stworzPotomka(const Polozenie& polozenie, Swiat& swiat) override;
	string getNazwa() const override;
};