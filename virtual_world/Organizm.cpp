#include "Organizm.h"
#include <iostream>

Organizm::Organizm(const char& symbol, const unsigned& sila, const int& inicjatywa, const Polozenie& polozenie, Swiat& swiat) : swiat(swiat) {
	this->symbol = symbol;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->polozenie = polozenie;
}


void Organizm::rysowanie() {
	std::cout << symbol;
}


bool Organizm::czyOdbilAtak(const Organizm& atakujacy) const {
	return false;
}

bool Organizm::czyZrobilUnik(const Organizm& atakujacy) const {
	return false;
}

bool Organizm::czyPoleWolne(const Polozenie& p) const {
	if (swiat.getOrganizm(p) == NULL)
		return true;
	else
		return false;
}

bool Organizm::czySilniejszy(const Organizm& atakowany) const {
	if (this->sila > atakowany.getSila())
		return true;
	else
		return false;
}


vector<Polozenie> Organizm::znajdzSasiedniePola(const unsigned& zasieg) {
	vector<Polozenie> mozliwosci;
	if (polozenie.x >= zasieg) //góra
		for (unsigned i = ZASIEG_RUCHU; i <= zasieg; i++)
			mozliwosci.push_back({ polozenie.x - i, polozenie.y });
	if (polozenie.x < swiat.getWysokosc() - zasieg) //dó³
		for (unsigned i = ZASIEG_RUCHU; i <= zasieg; i++)
			mozliwosci.push_back({ polozenie.x + i, polozenie.y });
	if (polozenie.y >= zasieg) //lewo
		for (unsigned i = ZASIEG_RUCHU; i <= zasieg; i++)
			mozliwosci.push_back({ polozenie.x, polozenie.y - i });
	if (polozenie.y < swiat.getSzerokosc() - zasieg) //prawo
		for (unsigned i = ZASIEG_RUCHU; i <= zasieg; i++)
			mozliwosci.push_back({ polozenie.x, polozenie.y + i });
	return mozliwosci;
}

vector<Polozenie> Organizm::znajdzWolnePola(const Organizm& o) {
	vector<Polozenie> mozliwosci = znajdzSasiedniePola(ZASIEG_RUCHU);
	vector<Polozenie> wolnePola;
	for (Polozenie p : mozliwosci) {
		if (czyPoleWolne(p))
			wolnePola.push_back(p);
	}
	return wolnePola;
}


unsigned Organizm::getX() const {
	return polozenie.x;
}

unsigned Organizm::getY() const {
	return polozenie.y;
}

int Organizm::getInicjatywa() const {
	return inicjatywa;
}

unsigned Organizm::getSila() const {
	return sila;
}

char Organizm::getSymbol() const {
	return symbol;
}

Polozenie Organizm::getPolozenie() const {
	return polozenie;
}


void Organizm::setPolozenie(const Polozenie& nowePolozenie) {
	this->polozenie = nowePolozenie;
}

void Organizm::setInicjatywa(const int& inicjatywa) {
	this->inicjatywa = inicjatywa;
}

void Organizm::setSila(const unsigned& sila) {
	this->sila = sila;
}


string Organizm::przygotujDoZapisu() {
	string organizm;
	organizm += getSymbol();
	organizm += ";" + to_string(getPolozenie().x);
	organizm += ";" + to_string(getPolozenie().y);
	organizm += ";" + to_string(getSila()) + "\n";
	return organizm;
}


Organizm::~Organizm() {

}