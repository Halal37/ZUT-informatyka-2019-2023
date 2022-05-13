#pragma once
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
	void informacje_marketingowe() const;
	void jakas_funkcja_marketing_etap3r(int bud);
	friend int Sedzia(Marketing mar, Wplyw_M m);
	friend class Budzet;
};

class Wplyw_M {
	int zwie;
	int zmie;
public:
	Wplyw_M(int Zwie, int Zmie);
	Wplyw_M(int Zwie);
	Wplyw_M();
	friend int Sedzia(Marketing mar, Wplyw_M m);
	~Wplyw_M();
	friend class Agregacja;
	friend class Budzet;
};
int Sedzia(Marketing mar, Wplyw_M m);