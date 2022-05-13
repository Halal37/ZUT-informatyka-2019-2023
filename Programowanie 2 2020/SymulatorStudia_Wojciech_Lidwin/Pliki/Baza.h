#pragma once
#include <iostream>
#include <array>
#include "Persona.h"
#include <assert.h>
//#include "Lista.h"
using namespace std;
class Persona;
class Lista
{
	Persona* osoba;
public:
	Lista() = default;
	Lista(Persona* per) :osoba(per) {}
	//Zwraca zmienna string o nazwie imie
	string get_imie() const;
	//Zwraca zmienna string o nazwie nazwisko
	string get_nazwisko() const;
	//Zwraca zmienna int o nazwie gat
	int get_gat() const;
	//Zwraca zmienna int o nazwie pen
	int get_pen() const;
	//Zwraca zmienna int o nazwie prof
	int get_prof() const;
	//Zwraca zmienna int o nazwie rep
	int get_rep() const;
	//Zwraca zmienna int o nazwie roz
	int get_roz() const;
};
class Baza
{
	
	Lista** lista_osob{ nullptr};
	size_t ilosc_osob{ 0 };
	//size_t ilosc_kolumn{ 0 };
public:
	//Wyswietlenie pojedynczej osoby
	void wyswietl();
	//Wyswietlenie konkretnej pojedynczej osoby
	void wyswietl(int i);
	//Wyswietlenie calej listy osob
	void wyswietl_all();
	//Zwracanie wartosci rep, dla konkretnej osoby z listy
	int get_rep(int i);
	//Zwracanie wartosci gat, dla konkretnej osoby z listy
	int get_gat(int i);
	//Zwracanie wartosci roz, dla konkretnej osoby z listy
	int get_roz(int i);
	//Zwracanie wartosci prof, dla konkretnej osoby z listy
	int get_prof(int i);
	//Tworzy lub zwieksza baze osob, rezerwuje pamiec
	void stworz(Persona* osoba);
	//Usuniecie calej listy osob
	void usun();
	//Usuniecie konkretnej osoby
	void usun(int z);
	Baza()=default;
	~Baza();
	//Baza(Baza const&) = delete;
	Baza operator=(Baza const& d);
};

