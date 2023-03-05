#pragma once
#include "Zwierze.h"

#define SILA_ANTYLOPY 4
#define INICJATYWA_ANTYLOPY 4
#define SYMBOL_ANTYLOPY 'A'
#define ZASIEG_ANTYLOPY 2
#define SZANSA_NA_UNIK_ANTYLOPY 50 //50%

class Antylopa : public Zwierze {
public:
	Antylopa(Polozenie polozenie, Swiat& swiat);
	Organizm* stworzPotomka(const Polozenie& polozenie, Swiat &swiat) override;
	bool czyZrobilUnik(const Organizm& atakujacy) const override;
	void akcja() override;
	string getNazwa() const override;
};