#include "Roslina.h"

Roslina::Roslina(const char& symbol, const unsigned& sila, const unsigned& inicjatywa, const Polozenie& polozenie, Swiat& swiat)
	: Organizm(symbol, sila, inicjatywa, polozenie, swiat) {}

void Roslina::akcja() {
	zasiej();
}

void Roslina::zasiej() {
	if (czySieje()) {
		vector<Polozenie> mozliwosci = znajdzWolnePola(*this);
		if (mozliwosci.empty())
			return;
		else {
			Polozenie pole = mozliwosci[rand() % mozliwosci.size()];
			Organizm* potomek = stworzPotomka(pole, swiat);
			swiat.dodajOrganizm(potomek);
			swiat.getKomentator()->zapiszSianie(*this);
		}
	}
}

void Roslina::kolizja(Organizm& atakujacy) {
	dynamic_cast<Zwierze*>(&atakujacy)->zmienPolozenie(this->getPolozenie());
	swiat.dodajDoUsuniecia(this);
	swiat.getKomentator()->zapiszJedzenie(atakujacy, *this);
}

bool Roslina::czySieje() const {
	int x = rand() % 100;
	if (x < SZANSA_NA_ZASIANIE)
		return true;
	else
		return false;
}

Roslina::~Roslina() {

}