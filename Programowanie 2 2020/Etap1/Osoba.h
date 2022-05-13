#pragma once
#include <iostream>
using namespace std;
class Osoba
{
	int rep; //Reputacja osoby
	int gat{}; //Umiejetnosc w konkretnych gatunkach
	int pen;//Pensja
	int roz;//Rozpoznawalnosc 
	int prof;//Profesjonalizm
	string imie;
	string nazwisko;
public:
	// Zwracanie warcosci gatunek
	int get_gat()const {
		return gat;
	};
	// Podawanie wartosci gatunek
	void set_gat(int s);
	// Zwracanie warcosci reputacji
	int get_rep()const {
		return rep;
	};
	// Podawanie wartosci reputacji
	void set_rep(int s);
	// Zwracanie warcosci pensja
	int get_pen() const {
		return pen;
	};
	// Podawanie wartosci pensji
	void set_pen(int s);
	// Zwracanie warcosci rozpoznawalnosci
	int get_roz() {
		return roz;
	};
	// Podawanie wartosci rozpoznawalnosc
	void set_roz(int s);
	// Zwracanie warcosci profesjnalizm
	int get_prof() const {
		return prof;
	};
	// Podawanie wartosci profesjonalizm
	void set_prof(int s);
	// Zwracanie warcosci imie
	string get_imie()const {
		return imie;
	};
	// Podawanie wartosci imie
	void set_imie(string s);
	// Zwracanie warcosci nazwisko
	string get_nazwisko()const {
		return nazwisko;
	};
	// Podawanie wartosci nazwisko
	void set_nazwisko(string s);
	// Stwarza tablice osób
	void Rez(); 
	// Zwraca wartosc pensji podanej osoby
	int Sprawdzam(int &i);
};


