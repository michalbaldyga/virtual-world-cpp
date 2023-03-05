#include "WilczeJagody.h"

WilczeJagody::WilczeJagody(const Polozenie& polozenie, Swiat& swiat)
	: Roslina(SYMBOL_JAGOD, SILA_JAGOD, INICJATYWA_ROSLIN, polozenie, swiat) {}

Organizm* WilczeJagody::stworzPotomka(const Polozenie& polozenie, Swiat& swiat) {
	return new WilczeJagody(polozenie, swiat);
}

void WilczeJagody::kolizja(Organizm& atakujacy) {
	//czyœcimy pola, na których by³o zwierzê oraz roœlina
	swiat.setOrganizm(atakujacy.getPolozenie(), NULL);
	swiat.setOrganizm(this->getPolozenie(), NULL);
	//usuwamy organizmy
	swiat.dodajDoUsuniecia(&atakujacy);
	swiat.dodajDoUsuniecia(this);
	//komentator
	swiat.getKomentator()->zapiszJedzenie(atakujacy, *this);
	swiat.getKomentator()->zapiszTrucizne(atakujacy, *this);
}

string WilczeJagody::getNazwa() const {
	return "WilczeJagody";
}