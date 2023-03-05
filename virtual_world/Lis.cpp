#include "Lis.h"

Lis::Lis(const Polozenie& polozenie, Swiat& swiat)
	: Zwierze(SYMBOL_LISA, SILA_LISA, INICJATYWA_LISA, polozenie, swiat) {}

Organizm* Lis::stworzPotomka(const Polozenie& polozenie, Swiat& swiat) {
	return new Lis(polozenie, swiat);
}

void Lis::akcja() {
	vector<Polozenie> mozliwosci = znajdzSasiedniePola(ZASIEG_RUCHU);
	Polozenie nowePolozenie;

	if (mozliwosci.empty())
		nowePolozenie = polozenie;
	else {
		vector<Polozenie> bezpiecznePola;
		for (Polozenie p : mozliwosci) {
			Organizm* atakowany = swiat.getOrganizm(p);
			if (atakowany == NULL)
				bezpiecznePola.push_back(p);
			else {
				if (czySilniejszy(*atakowany))
					bezpiecznePola.push_back(p);
			}
		}
		if (bezpiecznePola.empty())
			nowePolozenie = polozenie;
		else
			nowePolozenie = bezpiecznePola[rand() % bezpiecznePola.size()];
	}

	sprobujWykonacRuch(nowePolozenie);
}

string Lis::getNazwa() const{
	return "Lis";
}