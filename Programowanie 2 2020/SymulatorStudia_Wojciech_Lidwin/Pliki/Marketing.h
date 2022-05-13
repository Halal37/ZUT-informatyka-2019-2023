#pragma once
#include <array>
class Wplyw_M;

class Marketing
{
//public:
	int kupno;//Kupienie pozytywnych recenzji
    int sniad;//Reklamy na œniadaniówkach
	int plakaty;//Reklamy plakaty
	int trailer;//Reklamy trailery
	int bilb;//Reklamy bilbordy
	int internet;//Kampania internetowa
public:
	Marketing(int Kupno, int Sniad, int Plakaty,int Trailer, int Bilb, int Internet);
	//Wypisanie informacji marketingowych
	Marketing(int Kupno, int Sniad, int Plakaty, int Trailer, int Bilb);
	Marketing(int Kupno, int Sniad, int Plakaty, int Trailer);
	Marketing(int Kupno, int Sniad, int Plakaty);
	Marketing(int Kupno, int Sniad);
	Marketing(int Kupno);
	Marketing();
	~Marketing();
	//Wypisanie wszystkich wartosci na ekranie
	void informacje_marketingowe() const;
	//Wyznaczanie i podzial budzetu marketingowego
	void Rozdzial_budzetu_marketingowego(int bud);
	friend int Sedzia(Marketing mar, Wplyw_M m);
	friend class Budzet;
	// Zwracanie wartosci kupno
	int get_kupno() const;
	// Zwracanie wartosci sniad
	int get_sniad() const;
	// Zwracanie wartosci plakaty
	int get_plakaty() const;
	// Zwracanie wartosci trailer
	int get_trailer() const;
	// Zwracanie wartosci bilb
	int get_bilb() const;
	// Zwracanie wartosci internet
	int get_internet() const;

};

class Wplyw_M {
	//Zwiekszenie wplywu
	int zwie;
	//Pomniejszenie wplywu
	int zmie;
public:
	Wplyw_M(int Zwie, int Zmie);
	Wplyw_M(int Zwie);
	Wplyw_M();
	friend int Sedzia(Marketing mar, Wplyw_M m);
	~Wplyw_M();
	friend class Agregacja;
	friend class Budzet;
	// Zwracanie wartosci zwie
	int get_zwie() const;
	// Zwracanie wartosci zmie
	int get_zmie() const;
};
//Porownanie marketingu z wplywami
int Sedzia(Marketing mar, Wplyw_M m);




 