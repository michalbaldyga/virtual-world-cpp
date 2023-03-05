#include "Guarana.h"

Guarana::Guarana(const Polozenie& polozenie, Swiat& swiat)
	: Roslina(SYMBOL_GUARANY, SILA_GUARANY, INICJATYWA_ROSLIN, polozenie, swiat) {}

Organizm* Guarana::stworzPotomka(const Polozenie& polozenie, Swiat& swiat) {
	return new Guarana(polozenie, swiat);
}

void Guarana::kolizja(Organizm& atakujacy) {
	atakujacy.setSila(atakujacy.getSila() + WZMOCNIENIE_GUARANY);
	dynamic_cast<Zwierze*>(&atakujacy)->zmienPolozenie(this->polozenie);
	swiat.dodajDoUsuniecia(this);

	swiat.getKomentator()->zapiszJedzenie(atakujacy, *this);
	swiat.getKomentator()->zapiszWzmocnienie(atakujacy, *this);
}

string Guarana::getNazwa() const {
	return "Guarana";
}