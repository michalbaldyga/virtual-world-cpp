#include "Zolw.h"

Zolw::Zolw(const Polozenie& polozenie, Swiat& swiat)
	: Zwierze(SYMBOL_ZOLWIA, SILA_ZOLWIA, INICJATYWA_ZOLWIA, polozenie, swiat) {}

void Zolw::akcja() {
	unsigned szansa = rand() % 100;
	if (szansa < SZANSA_NA_RUCH_ZOLWIA)
		Zwierze::akcja();
	else
		return;
}

bool Zolw::czyOdbilAtak(const Organizm& atakujacy) const {
	if (atakujacy.getSila() < 5) {
		swiat.getKomentator()->zapiszOdbicie(*this);
		return true;
	}
	else
		return false;
}

Organizm* Zolw::stworzPotomka(const Polozenie& polozenie, Swiat& swiat) {
	return new Zolw(polozenie, swiat);
}

string Zolw::getNazwa() const {
	return "Zolw";
}