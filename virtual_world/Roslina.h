#pragma once
#include "Organizm.h"
#include "Zwierze.h"

#define SZANSA_NA_ZASIANIE 5 //5% szans
#define INICJATYWA_ROSLIN 0

class Roslina : public Organizm {
protected:
	bool czySieje() const;
	void zasiej();

public:
	Roslina(const char& symbol, const unsigned& sila, const unsigned& inicjatywa, const Polozenie& polozenie, Swiat& swiat);
	void akcja() override;
	void kolizja(Organizm& atakujacy) override;
	~Roslina();
};