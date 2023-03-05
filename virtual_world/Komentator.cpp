#include "Komentator.h"

Komentator::Komentator() {
	informacje = "";
	for (int i = 0; i < LICZBA_ROZNYCH_ROSLIN; i++)
		czyRoslinaSieje[i] = false;
	for (int i = 0; i < LICZBA_ROZNYCH_ZWIERZAT; i++)
		czyZwierzeRozmnaza[i] = false;
}

void Komentator::zapiszAtak(const Organizm& atakujacy, const Organizm& atakowany) {
	string walka = atakujacy.getNazwa() + " atakuje " + atakowany.getNazwa() + ". ";
	informacje += walka;
}

void Komentator::zapiszWygrana(const Organizm& wygrany) {
	string wygrana = wygrany.getNazwa() + " wygrywa walke.\n";
	informacje += wygrana;
}

void Komentator::zapiszUnik(const Organizm& atakowany) {
	string unik = atakowany.getNazwa() + " robi unik.\n";
	informacje += unik;
}

void Komentator::zapiszOdbicie(const Organizm& atakowany) {
	string odbicie = atakowany.getNazwa() + " odbil atak.\n";
	informacje += odbicie;
}

void Komentator::zapiszRozmnazanie(const Organizm& rodzic) {
	if (rodzic.getNazwa() == "Antylopa")
		czyZwierzeRozmnaza[ANTYLOPA] = true;
	else if (rodzic.getNazwa() == "Lis")
		czyZwierzeRozmnaza[LIS] = true;
	else if (rodzic.getNazwa() == "Owca")
		czyZwierzeRozmnaza[OWCA] = true;
	else if (rodzic.getNazwa() == "Wilk")
		czyZwierzeRozmnaza[WILK] = true;
	else
		czyZwierzeRozmnaza[ZOLW] = true;
}

void Komentator::zapiszRuchCzlowieka(const unsigned& kierunek) {
	string ruch = "Czlowiek poruszyl sie w ";
	if (kierunek ==	GORA)
		ruch += "gore.\n";
	else if (kierunek == DOL)
		ruch += "dol\n";
	else if (kierunek == LEWO)
		ruch += "lewo\n";
	else
		ruch += "prawo\n";
	informacje += ruch;
}


void Komentator::zapiszSianie(const Organizm& rodzic) {
	if (rodzic.getNazwa() == "BarszczSosnowskiego")
		czyRoslinaSieje[BARSZCZ] = true;
	else if (rodzic.getNazwa() == "Guarana")
		czyRoslinaSieje[GUARANA] = true;
	else if (rodzic.getNazwa() == "Mlecz")
		czyRoslinaSieje[MLECZ] = true;
	else if (rodzic.getNazwa() == "Trawa")
		czyRoslinaSieje[TRAWA] = true;
	else 
		czyRoslinaSieje[JAGODY] = true;
}

void Komentator::zapiszJedzenie(const Organizm& atakujacy, const Organizm& zjedzony) {
	string jedzenie = atakujacy.getNazwa() + " zjadl " + zjedzony.getNazwa() + ".\n";
	informacje += jedzenie;
}

void Komentator::zapiszWzmocnienie(const Organizm& atakujacy, const Organizm& zjedzony) {
	string wzmocnienie = zjedzony.getNazwa() + " dodaje sily " + atakujacy.getNazwa() + ".\n";
	informacje += wzmocnienie;
}

void Komentator::zapiszTrucizne(const Organizm& atakujacy, const Organizm& zjedzony) {
	string trucizna = zjedzony.getNazwa() + " zatrul " + atakujacy.getNazwa() + ".\n";
	informacje += trucizna;
}

void Komentator::podsumujSianie() {
	if (czyRoslinaSieje[BARSZCZ])
		informacje += "BarszczSosnowskiego sie rozprzestrzenil.\n";
	if (czyRoslinaSieje[GUARANA])
		informacje += "Guarana sie rozprzestrzenila.\n";
	if (czyRoslinaSieje[MLECZ])
		informacje += "Mlecz sie rozprzestrzenil.\n";
	if (czyRoslinaSieje[TRAWA])
		informacje += "Trawa sie rozprzestrzenila.\n";
	if (czyRoslinaSieje[JAGODY])
		informacje += "WilczeJagody sie rozprzestrzenily.\n";
	for (unsigned i = 0; i < LICZBA_ROZNYCH_ROSLIN; i++)
		czyRoslinaSieje[i] = false;
}

void Komentator::podsumujRozmnazanie() {
	if (czyZwierzeRozmnaza[ANTYLOPA])
		informacje += "Antylopy sie rozmnozyly.\n";
	if (czyZwierzeRozmnaza[LIS])
		informacje += "Lisy sie rozmnozyly.\n";
	if (czyZwierzeRozmnaza[OWCA])
		informacje += "Owce sie rozmnozyly.\n";
	if (czyZwierzeRozmnaza[WILK])
		informacje += "Wilki sie rozmnozyly.\n";
	if (czyZwierzeRozmnaza[ZOLW])
		informacje += "Zolwie sie rozmnozyly.\n";
	for (unsigned i = 0; i < LICZBA_ROZNYCH_ZWIERZAT; i++)
		czyZwierzeRozmnaza[i] = false;
}

void Komentator::wypiszWyniki() {
	podsumujSianie();
	podsumujRozmnazanie();
	cout << "PODSUMOWANIE TURY:\n";
	cout << "=============================================\n";
	if (informacje.empty())
		cout << "Nie wykryto zadnych zdarzen.\n";
	else
		cout << informacje;
	cout << "=============================================\n";
	informacje.clear();
}

Komentator::~Komentator() {};