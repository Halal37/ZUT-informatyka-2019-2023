#pragma once
#include <iostream>
#include "Budzet.h"
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
/*public:
	class Statystyki {
		int rep; //Reputacja osoby
		int gat{}; //Umiejetnosc w konkretnych gatunkach
		int pen;//Pensja
		int roz;//Rozpoznawalnosc 
		int prof;//Profesjonalizm
	public:
		Statystyki(int Rep, int Gat, int Pen, int Roz, int Prof) :rep(Rep), gat(Gat), pen(Pen), roz(Roz), prof(Prof) {}
		void wyswietl_statystyki();
		

	};*/
public:
	// Zwracanie wartosci gatunek
	int get_gat() const {
		return gat;
	};
	// Podawanie wartosci gatunek
	void set_gat(int s);
	// Zwracanie wartosci reputacji
	int get_rep() const {
		return rep;
	};
	// Podawanie wartosci reputacji
	void set_rep(int s);
	// Zwracanie wartosci pensja
	int get_pen() {
		return pen;
	};
	// Podawanie wartosci pensji
	void set_pen(int s);
	// Zwracanie wartosci rozpoznawalnosci
	int get_roz() const {
		return roz;
	};
	// Podawanie wartosci rozpoznawalnosc
	void set_roz(int s);
	// Zwracanie wartosci profesjnalizm
	int get_prof() const {
		return prof;
	};
	// Podawanie wartosci profesjonalizm
	void set_prof(int s);
	// Zwracanie wartosci imie
	string get_imie() const {
		return imie;
	};
	// Podawanie wartosci imie
	void set_imie(string s);
	// Zwracanie wartosci nazwisko
	string get_nazwisko()const {
		return nazwisko;
	};
	//Osoba() = default;
	Osoba(string ="Jakis",string ="Stazysta",int=0,int=0,int=0,int=0,int=0);
	//Osoba(string im, string naz, int jed, int dwa, int trzy, int cztery, int piec);
	Osoba(const Osoba& os);
	~Osoba();
	//friend void Sprawdzajka(Osoba os, Budzet bud);
	//Osoba() :nar{ static_cast<size_t>(rand()%2) } {  }
	// size_t get_narod() const { return nar; }
	// Podawanie wartosci nazwisko
	void set_nazwisko(string s);
	// Stwarza tablice osob
	void Rez(); 
	// Zwraca wartosc pensji podanej osoby
	int Sprawdzam(int &i);
	friend class Budzet;
};




