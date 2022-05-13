#pragma once
class Sprzet
{
	int kupno;//cena kupna sprzetu
	int wynajem;//cena za wynajem
	int jakosc;//Jakos jaka mozna uzyskac danym sprzetem 
	public:
		// Zwracanie warcosci kupna
	int get_kupno() const {
		return kupno;
	};
	//Przydziela wartoœæ ceny kupna
	void set_kupno(int s);
	// Zwracanie warcosci wynajem
	int get_wynajem()const {
		return wynajem;
	};
	//Przydziela wartoœæ ceny wynajmu
	void set_wynajem(int s);
	// Zwracanie warcosci jakosci
	int get_jakosc()const {
		return jakosc;
	};
	//Przydziela wartoœæ jakoœci
	void set_jakosc(int s);
	// Tworzy tablice sprzetów
	void Sprzecior_gigant();
	//Zwracanie kupna lub wynajmu
	int Sprawdzam(Sprzet&Rezyser,int k, int m);
	//Zwracanie jakosc
	int Sprawdzam(Sprzet& Rezyser, int k);
};


