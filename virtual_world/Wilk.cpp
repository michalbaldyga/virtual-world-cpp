#include "Wilk.h"

Wilk::Wilk(const Polozenie& polozenie, Swiat& swiat)
	: Zwierze(SYMBOL_WILKA, SILA_WILKA, INICJATYWA_WILKA, polozenie, swiat) {}

Organizm* Wilk::stworzPotomka(const Polozenie& polozenie, Swiat& swiat) {
	return new Wilk(polozenie, swiat);
}

string Wilk::getNazwa() const {
	return "Wilk";
}