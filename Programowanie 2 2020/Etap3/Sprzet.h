#pragma once
class Sprzet
{
	//int kupno;//cena kupna sprzetu
	//int wynajem;//cena za wynajem
	int jakosc;//Jakos jaka mozna uzyskac danym sprzetem 
	class Opcja {
		int kupno;//cena kupna sprzetu
		int wynajem;//cena za wynajem
	public:
		Opcja(int Kupno, int Wynajem):kupno(Kupno),wynajem(Wynajem){}
		void pokaz();
	};
	Opcja set() { return Opcja(5 * jakosc, jakosc); }
public:
	Sprzet(int Jakosc);
	Sprzet();
	~Sprzet();
	void pokaz() { set().pokaz(); }
	// Zwracanie wartosci jakosci
	int get_jakosc() {
		return jakosc;
	};
	//Przydziela wartosc jakosci
	void set_jakosc(int s);
	friend class Budzet;
	//int zwroc_kupno(Opcja os);
//	int zwroc_wynajem(Opcja os);
	//void Sprzet::Opcja : pokaz();
	/*public:
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
	
	// Tworzy tablice sprzetow
	void Sprzecior_gigant();
	//Zwracanie kupna lub wynajmu
	int Sprawdzam(Sprzet&Rezyser,int k, int m);
	//Zwracanie jakosc
	int Sprawdzam(Sprzet& Rezyser, int k);*/
};


