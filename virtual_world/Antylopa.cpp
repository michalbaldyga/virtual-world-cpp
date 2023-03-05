#include "Antylopa.h"

Antylopa::Antylopa(Polozenie polozenie, Swiat& swiat)
	: Zwierze(SYMBOL_ANTYLOPY, SILA_ANTYLOPY, INICJATYWA_ANTYLOPY, polozenie, swiat) {}

Organizm* Antylopa::stworzPotomka(const Polozenie& polozenie, Swiat &swiat) {
	return new Antylopa(polozenie, swiat);
}

bool Antylopa::czyZrobilUnik(const Organizm& atakujacy) const{
	unsigned szansa = rand() % 100;
	if (szansa < SZANSA_NA_UNIK_ANTYLOPY) {
		swiat.getKomentator()->zapiszUnik(*this);
		return true;
	}
	else
		return false;
}

void Antylopa::akcja() {
	vector<Polozenie> mozliwosci = znajdzSasiedniePola(ZASIEG_ANTYLOPY);
	Polozenie nowePolozenie = (mozliwosci.empty() ? polozenie : mozliwosci[rand() % mozliwosci.size()]);
	sprobujWykonacRuch(nowePolozenie);
}

string Antylopa::getNazwa() const {
	return "Antylopa";
}