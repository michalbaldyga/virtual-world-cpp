#include "Owca.h"

Owca::Owca(const Polozenie& polozenie, Swiat& swiat)
	: Zwierze(SYMBOL_OWCY, SILA_OWCY, INICJATYWA_OWCY, polozenie, swiat) {}

Organizm* Owca::stworzPotomka(const Polozenie& polozenie, Swiat& swiat) {
	return new Owca(polozenie, swiat);
}

string Owca::getNazwa() const {
	return "Owca";
}