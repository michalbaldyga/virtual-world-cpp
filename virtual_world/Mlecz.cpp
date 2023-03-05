#include "Mlecz.h"

Mlecz::Mlecz(const Polozenie& polozenie, Swiat& swiat)
	: Roslina(SYMBOL_MLECZA, SILA_MLECZA, INICJATYWA_ROSLIN, polozenie, swiat) {}

Organizm* Mlecz::stworzPotomka(const Polozenie& polozenie, Swiat& swiat) {
	return new Mlecz(polozenie, swiat);
}

void Mlecz::akcja() {
	for (int i = 0; i < LICZBA_PROB_ZASIANIA_MLECZA; i++)
		zasiej();
}

string Mlecz::getNazwa() const{
	return "Mlecz";
}