#pragma once
class Sprzet
{
	int jakosc;//Jakos jaka mozna uzyskac danym sprzetem 
	class Opcja {
		int kupno;//cena kupna sprzetu
		int wynajem;//cena za wynajem
	public:
		Opcja(int Kupno, int Wynajem):kupno(Kupno),wynajem(Wynajem){}
		void pokaz();
	};
	Opcja set() { return Opcja(44 * jakosc, jakosc); }
public:
	Sprzet(int Jakosc);
	Sprzet();
	~Sprzet();
	void pokaz() { set().pokaz(); }
	// Zwracanie wartosci jakosci
	int get_jakosc();
	//Przydziela wartosc jakosci
	void set_jakosc(int s);
	friend class Budzet;
};


