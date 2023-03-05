#include "Zwierze.h"

Zwierze::Zwierze(const char& symbol, const unsigned& sila, const int& inicjatywa, const Polozenie& polozenie, Swiat& swiat)
	: Organizm(symbol, sila, inicjatywa, polozenie, swiat) {
}

void Zwierze::akcja() {
	vector<Polozenie> mozliwosci = znajdzSasiedniePola(ZASIEG_RUCHU);
	Polozenie nowePolozenie = (mozliwosci.empty() ? polozenie : mozliwosci[rand() % mozliwosci.size()]);
	sprobujWykonacRuch(nowePolozenie);
}

void Zwierze::kolizja(Organizm& atakujacy) {
	if (atakujacy.getSymbol() == this->symbol) //je�eli organizmy s� tego samego gatunku
		rozmnoz(atakujacy);
	else
		walcz(atakujacy);
}

void Zwierze::zmienPolozenie(const Polozenie& nowePolozenie) {
	swiat.setOrganizm(polozenie, NULL);
	polozenie = nowePolozenie;
	swiat.setOrganizm(polozenie, this);
}

void Zwierze::sprobujWykonacRuch(const Polozenie& nowePolozenie) {
	Organizm* org = swiat.getOrganizm(nowePolozenie); //zmienna pomocnicza, dzi�ki kt�rej sprawdzimy, czy na nowym polu jest jaki� organizm
	if ((nowePolozenie.x == polozenie.x) && (nowePolozenie.y == polozenie.y)) //je�eli nie mo�emy si� ruszy�
		return;
	else if (org != NULL) //je�eli pole, na kt�re chcemy si� ruszy� jest zaj�te
		swiat.getOrganizm(nowePolozenie)->kolizja(*this); //nast�puje kolizja
	else {
		zmienPolozenie(nowePolozenie);
	}
}

void Zwierze::rozmnoz(const Organizm& partner) {
	vector<Polozenie> mozliwosci = znajdzWolnePola(*this);
	if (mozliwosci.empty())
		mozliwosci = znajdzWolnePola(partner);
	if (mozliwosci.empty())
		return;
	else {
		Polozenie pole = mozliwosci[rand() % mozliwosci.size()];
		Organizm* potomek = stworzPotomka(pole, swiat);
		swiat.dodajOrganizm(potomek);
		swiat.getKomentator()->zapiszRozmnazanie(*this);
	}
}

void Zwierze::walcz(Organizm& atakujacy) {
	swiat.getKomentator()->zapiszAtak(atakujacy, *this);
	if (atakujacy.getSila() >= this->getSila()) { //jezeli atakowany jest slabszy
		if (czyOdbilAtak(atakujacy))
			return;
		else if (czyZrobilUnik(atakujacy)) {
			Polozenie tmp = polozenie;
			this->zrobUnik(atakujacy);
			dynamic_cast<Zwierze*>(&atakujacy)->zmienPolozenie(tmp);
		}
		else { //je�eli atakowany nie odbi� ataku i nie zrobi� uniku
			swiat.dodajDoUsuniecia(this); //atakowany zostanie usuni�ty
			dynamic_cast<Zwierze*>(&atakujacy)->zmienPolozenie(this->polozenie); //atakujacy wejdzie w jego miejsce
			swiat.getKomentator()->zapiszWygrana(atakujacy);
		}
	}
	else { //jezeli atakuj�cy jest s�abszy
		swiat.dodajDoUsuniecia(&atakujacy); //to zostanie usuni�ty
		swiat.setOrganizm(atakujacy.getPolozenie(), NULL); //i jego miejsce si� zwolni
		swiat.getKomentator()->zapiszWygrana(*this);
	}
}

void Zwierze::zrobUnik(const Organizm& atakujacy) {
	vector<Polozenie> mozliwosci = znajdzWolnePola(*this);
	if (mozliwosci.empty())
		zmienPolozenie(atakujacy.getPolozenie());
	else
		zmienPolozenie(mozliwosci[rand() % mozliwosci.size()]);
}

Zwierze::~Zwierze() {

}