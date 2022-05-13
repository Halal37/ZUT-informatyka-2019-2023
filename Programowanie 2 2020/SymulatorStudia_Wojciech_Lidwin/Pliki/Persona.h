#pragma once
#include "Baza.h"
#include <iostream>
using namespace std;
class Baza;
class Persona
{
	static Baza* baza;
protected:
	int rep; //Reputacja osoby
	int gat{}; //Umiejetnosc w konkretnych gatunkach
	int pen;//Pensja
	int roz;//Rozpoznawalnosc 
	int prof;//Profesjonalizm
	string imie;
	string nazwisko;
public:
	static Baza* getbaze();
	Persona()=default;
	// Zwracanie wartosci gatunek
	int get_gat() const;
	// Podawanie wartosci gatunek
	virtual void set_gat(int s)=0;
	// Zwracanie wartosci reputacji
	int get_rep() const;
	// Podawanie wartosci reputacji
	virtual void set_rep(int s)=0;
	// Zwracanie wartosci pensja
	int get_pen() const;
	// Podawanie wartosci pensji
	virtual void set_pen(int s)=0;
	// Zwracanie wartosci rozpoznawalnosci
	int get_roz() const;
	// Podawanie wartosci rozpoznawalnosc
	virtual void set_roz(int s)=0;
	// Zwracanie wartosci profesjnalizm
	int get_prof() const;
	// Podawanie wartosci profesjonalizm
	virtual void set_prof(int s)=0;
	// Zwracanie wartosci imie
	string get_imie() const;
	// Podawanie wartosci imie
	virtual void set_imie(string s)=0;
	// Zwracanie wartosci nazwisko
	string get_nazwisko()const;
	virtual void set_nazwisko(string s) = 0;
	virtual void stworz(int z) = 0;
	//Wyswietla kandydata o podanym numerze
    void Wyswietl(int z) ;
	virtual ~Persona(){}

};
