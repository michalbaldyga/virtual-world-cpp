#include "BarszczSosnowskiego.h"

BarszczSosnowskiego::BarszczSosnowskiego(const Polozenie& polozenie, Swiat& swiat)
	: Roslina(SYMBOL_BARSZCZU, SILA_BARSZCZU, INICJATYWA_ROSLIN, polozenie, swiat) {}

Organizm* BarszczSosnowskiego::stworzPotomka(const Polozenie& polozenie, Swiat& swiat) {
	return new BarszczSosnowskiego(polozenie, swiat);
}

void BarszczSosnowskiego::kolizja(Organizm& atakujacy) {
	swiat.getKomentator()->zapiszJedzenie(atakujacy, *this);
	swiat.getKomentator()->zapiszTrucizne(atakujacy, *this);
	//czyœcimy pola, na których by³o zwierzê oraz roœlina
	swiat.setOrganizm(atakujacy.getPolozenie(), NULL);
	swiat.setOrganizm(this->getPolozenie(), NULL);
	//usuwamy organizmy
	swiat.dodajDoUsuniecia(&atakujacy);
	swiat.dodajDoUsuniecia(this);
}

void BarszczSosnowskiego::akcja() {
	vector<Polozenie> sasiedniePola = znajdzSasiedniePola(ZASIEG_RUCHU);
	for (Polozenie p : sasiedniePola) {
		Organizm* org = swiat.getOrganizm(p);
		if (dynamic_cast<Zwierze*>(org) != NULL) {
			swiat.getKomentator()->zapiszTrucizne(*org, *this);
			swiat.dodajDoUsuniecia(org);
			swiat.setOrganizm(p, NULL);
		}
	}
	zasiej();
}

string BarszczSosnowskiego::getNazwa() const {
	return "BarszczSosnowskiego";
}