#pragma once
class Sprzet
{
	int kupno;//cena kupna sprzetu
	int wynajem;//cena za wynajem
	int jakosc;//Jakos jaka mozna uzyskac danym sprzetem 
	public:
		// Zwracanie wartosci kupna
	int get_kupno() {
		return kupno;
	};
	//Przydziela wartosc ceny kupna
	void set_kupno(int s);
	// Zwracanie wartosci wynajem
	int get_wynajem() {
		return wynajem;
	};
	//Przydziela wartosc ceny wynajmu
	void set_wynajem(int s);
	// Zwracanie wartosci jakosci
	int get_jakosc() {
		return jakosc;
	};
	//Przydziela wartosc jakosci
	void set_jakosc(int s);
	// Tworzy tablice sprzetow
	void Sprzecior_gigant();
	//Zwracanie kupna lub wynajmu
	int Sprawdzam(Sprzet&Rezyser,int k, int m);
	//Zwracanie jakosc
	int Sprawdzam(Sprzet& Rezyser, int k);
};


