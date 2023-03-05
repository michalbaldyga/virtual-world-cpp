#pragma once
#include "Organizm.h"

class Zwierze : public Organizm {
protected:
	void sprobujWykonacRuch(const Polozenie& nowePolozenie);
	void rozmnoz(const Organizm& partner);
	void walcz(Organizm& atakujacy);
	void zrobUnik(const Organizm& atakujacy);

public:
	Zwierze(const char& symbol, const unsigned& sila, const int& inicjatywa, const Polozenie& polozenie, Swiat& swiat);
	void akcja() override;
	void kolizja(Organizm& atakujacy) override;
	void zmienPolozenie(const Polozenie& nowePolozenie);
	~Zwierze();
};