#include "Trawa.h"

Trawa::Trawa(const Polozenie& polozenie, Swiat& swiat)
	: Roslina(SYMBOL_TRAWY, SILA_TRAWY, INICJATYWA_ROSLIN, polozenie, swiat) {}

Organizm* Trawa::stworzPotomka(const Polozenie& polozenie, Swiat& swiat) {
	return new Trawa(polozenie, swiat);
}

string Trawa::getNazwa() const {
	return "Trawa";
}