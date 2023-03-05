#include "Swiat.h"
#include "Organizmy.h"

Swiat::Swiat(unsigned x, unsigned y) {
	szerokosc = x;
	wysokosc = y;
	komentator = new Komentator();
	inicjalizujOrganizmy();
}


void Swiat::wykonajTure() {
	sortujKolejke();
	if (znajdzCzlowieka() != NULL) {
		Czlowiek* c = dynamic_cast<Czlowiek*>(znajdzCzlowieka());
		if (c->getInicjatywa() != ORGANIZM_ZGINAL) {
			c->aktualizujUmiejetnosc();
			c->sprawdzZdarzenie();
		}
	}

	for (Organizm* org : getKolejka())
		if (org->getInicjatywa() != ORGANIZM_ZGINAL)
			org->akcja();

	usunOrganizmy();
	system("CLS");
	rysujSwiat();
	getKomentator()->wypiszWyniki();
}

void Swiat::rysujSwiat() {
	rysujMenu();

	for (unsigned i = 0; i < szerokosc+2; i++)
		cout << "=";
	cout << endl;

	for (unsigned i = 0; i < wysokosc; i++) {
		cout << "|";
		for (unsigned j = 0; j < szerokosc; j++) {
			if (organizmy[i][j] == NULL)
				cout << ' ';
			else
				organizmy[i][j]->rysowanie();
		}
		cout << "|" << endl;
	}

	for (unsigned i = 0; i < szerokosc + 2; i++)
		cout << "=";
	cout << endl;
}

void Swiat::inicjalizujSwiat() {
	for (unsigned i = 0; i < wysokosc; i++)
		for (unsigned j = 0; j < szerokosc; j++)
			organizmy[i][j] = NULL;
}

void Swiat::inicjalizujOrganizmy() {
	organizmy = new Organizm* *[wysokosc];
	for (unsigned i = 0; i < wysokosc; i++)
		organizmy[i] = new Organizm* [szerokosc];
}


void Swiat::dodajOrganizm(Organizm* o) {
	organizmy[o->getX()][o->getY()] = o;
	kolejka.push_back(o);
}

void Swiat::usunOrganizmy() {
	if (!martweOrganizmy.empty()) {
		for (Organizm* org : martweOrganizmy) {
			kolejka.remove(org);
		}
		martweOrganizmy.clear();
	}
}

void Swiat::dodajDoUsuniecia(Organizm* o) {
	martweOrganizmy.push_back(o);
	o->setInicjatywa(ORGANIZM_ZGINAL);
}

void Swiat::sortujKolejke() {
	kolejka.sort([](const Organizm* a, const Organizm* b) {return a->getInicjatywa() > b->getInicjatywa(); });
}

void Swiat::rysujMenu() {
	cout << "Michal Baldyga 184523:\n";
	cout << "---------------------------------------------------------------------\n";
	cout << "| Z - wykonaj ture | S - zapisz gre | L - wczytaj gre | Q - wyjscie |\n";
	cout << "---------------------------------------------------------------------\n";
}


void Swiat::generujOrganizmy() {
	vector<Polozenie> pola = znajdzPolaGenerowania();
	if (!pola.empty()) {
		dodajOrganizm(new Czlowiek({ pola[pola.size() - 1] }, *this));
		pola.pop_back();
	}
	else
		return;
	if (!pola.empty()) {
		for (int i = 1; i <= POCZATKOWA_ILOSC_ORGANIZMOW; i++) {
			if (!pola.empty()) {
				dodajOrganizm(new Antylopa({ pola[pola.size() - 1] }, *this));
				pola.pop_back();
			}
			if (!pola.empty()) {
				dodajOrganizm(new BarszczSosnowskiego({ pola[pola.size() - 1] }, *this));
				pola.pop_back();
			}
			if (!pola.empty()) {
				dodajOrganizm(new Guarana({ pola[pola.size() - 1] }, *this));
				pola.pop_back();
			}
			if (!pola.empty()) {
				dodajOrganizm(new Lis({ pola[pola.size() - 1] }, *this));
				pola.pop_back();
			}
			if (!pola.empty()) {
				dodajOrganizm(new Mlecz({ pola[pola.size() - 1] }, *this));
				pola.pop_back();
			}
			if (!pola.empty()) {
				dodajOrganizm(new Owca({ pola[pola.size() - 1] }, *this));
				pola.pop_back();
			}
			if (!pola.empty()) {
				dodajOrganizm(new Trawa({ pola[pola.size() - 1] }, *this));
				pola.pop_back();
			}
			if (!pola.empty()) {
				dodajOrganizm(new WilczeJagody({ pola[pola.size() - 1] }, *this));
				pola.pop_back();
			}
			if (!pola.empty()) {
				dodajOrganizm(new Wilk({ pola[pola.size() - 1] }, *this));
				pola.pop_back();
			}
			if (!pola.empty()) {
				dodajOrganizm(new Zolw({ pola[pola.size() - 1] }, *this));
				pola.pop_back();
			}
		}
		sortujKolejke();
		pola.clear();
		pola.shrink_to_fit();
	}
	else
		return;
}

vector<Polozenie> Swiat::znajdzPolaGenerowania() {
	vector<Polozenie> pola;
	for (unsigned i = 0; i < wysokosc; i++) {
		for (unsigned j = 0; j < szerokosc; j++)
			if (getOrganizm({i, j}) == NULL)
				pola.push_back({ i, j });
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	auto rng = std::default_random_engine{ seed };
	std::shuffle(std::begin(pola), std::end(pola), rng);

	return pola;
}

Organizm* Swiat::znajdzCzlowieka() {
	bool sukces = false;
	for (Organizm* org : getKolejka())
		if (org->getSymbol() == 'C') {
			sukces = true;
			return org;
		}
	if (!sukces)
		return NULL;
}


void Swiat::zapiszStan() {
	fstream plik;
	plik.open("zapis.txt", ios::out);
	if (plik.good())
	{
		//zapisujemy wymiary œwiata
		plik << to_string(szerokosc) + ";" + to_string(wysokosc) + "\n";

		//zapisujemy informacje o wszystkich organizmach na œwiecie
		for (Organizm* org : getKolejka())
			plik << org->przygotujDoZapisu();

		plik.close();
	}
	else 
		cout << "Blad! Nie udalo otworzyc sie pliku!" << endl;
}

void Swiat::wczytajStan() {
    wyczyscSwiat();
	fstream plik;
	plik.open("zapis.txt", ios::in);
	if (plik.good())
	{
		string linia;
		int nr_linii = 1;

		while (getline(plik, linia))
		{
			if (nr_linii == 1) { //parametry œwiata
				setWymiary(linia);
				inicjalizujOrganizmy();
				inicjalizujSwiat();
			}
			else //parametry organizmów
				wczytajOrganizm(linia);
			nr_linii++;
		}
		plik.close();
	}
	else {
		cout << "Blad! Nie udalo otworzyc sie pliku!" << endl;
		exit(-1);
	}
}

void Swiat::wyczyscSwiat() {
	for (unsigned i = 0; i < wysokosc; i++)
		delete[] organizmy[i];
	delete[] organizmy;

	kolejka.clear();
	martweOrganizmy.clear();
}

void Swiat::wczytajOrganizm(string& dane) {
	//wy³uskujemy z ci¹gu danych cechy organizmów

	int liczba_cech = (dane[0] == 'C' ? 6 : 4); //cz³owiek ma 2 cechy wiêcej
	string* cechy = new string[liczba_cech];
	const char* separator = ";";
	char* token = strtok(&dane[0], separator);
	int i = 0;

	while (token != NULL)
	{
		cechy[i++] = token;
		token = strtok(NULL, separator);
	}
	
	char symbol = cechy[0][0];
	Polozenie pole = { atoi(cechy[1].c_str()) , atoi(cechy[2].c_str()) };
	unsigned sila = atoi(cechy[3].c_str());
	if (dane[0] == 'C') {
		unsigned umiejetnosc = atoi(cechy[4].c_str());
		unsigned cooldown = atoi(cechy[5].c_str());
		stworzOrganizm(symbol, pole, sila, umiejetnosc, cooldown);
	}
	else 
		stworzOrganizm(symbol, pole, sila);
}

void Swiat::stworzOrganizm(const char& symbol, const Polozenie& p, const unsigned& sila) {
	Organizm* org;
	if (symbol == 'A')
		org = new Antylopa(p, *this);
	else if (symbol == 'B')
		org = new BarszczSosnowskiego(p, *this);
	else if (symbol == 'G')
		org = new Guarana(p, *this);
	else if (symbol == 'L')
		org = new Lis(p, *this);
	else if (symbol == 'M')
		org = new Mlecz(p, *this);
	else if (symbol == 'O')
		org = new Owca(p, *this);
	else if (symbol == 'T')
		org = new Trawa(p, *this);
	else if (symbol == 'J')
		org = new WilczeJagody(p, *this);
	else if (symbol == 'W')
		org = new Wilk(p, *this);
	else
		org = new Zolw(p, *this);

	org->setSila(sila);
	dodajOrganizm(org);
}

void Swiat::stworzOrganizm(const char& symbol, const Polozenie& p, const unsigned& sila, const unsigned& umiejetnosc, const unsigned& cooldown) {
	Czlowiek* c = new Czlowiek(p, *this);
	c->setSila(sila);
	c->setPozostalyCzasUmiejetnosci(umiejetnosc);
	c->setPozostalyCzasLadowania(cooldown);
	dodajOrganizm(c);
}


unsigned Swiat::getWysokosc() const {
	return wysokosc;
}

unsigned Swiat::getSzerokosc() const {
	return szerokosc;
}

Organizm*** Swiat::getOrganizmy() const {
	return organizmy;
}

Organizm* Swiat::getOrganizm(const Polozenie& p) const {
	return organizmy[p.x][p.y];
}

list<Organizm*> Swiat::getKolejka() const {
	return kolejka;
}

Komentator* Swiat::getKomentator() const {
	return komentator;
}


void Swiat::setOrganizm(const Polozenie& p, Organizm* o) {
	organizmy[p.x][p.y] = o;
}

void Swiat::setWymiary(const string& dane) {
	string width, height;
	unsigned i = 0;
	for (; i < dane.size(); i++) {
		if (dane[i] != ';')
			width += dane[i];
		else {
			i++;
			break;
		}
	}
	for (; i < dane.size(); i++)
		height += dane[i];
	szerokosc = atoi(width.c_str());
	wysokosc = atoi(height.c_str());
}


Swiat::~Swiat() {
	for (unsigned i = 0; i < wysokosc; i++)
		delete[] organizmy[i];
	delete[] organizmy;

	kolejka.clear();
	martweOrganizmy.clear();
}