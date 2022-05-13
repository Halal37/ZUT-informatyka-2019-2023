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
	const size_t nar;//Narodowoœæ
	string imie;
	string nazwisko;
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
	Osoba() :nar{ static_cast<size_t>(rand()%2) } {  }
	size_t get_narod() const { return nar; }
	// Podawanie wartosci nazwisko
	void set_nazwisko(string s);
	// Stwarza tablice osob
	void Rez(); 
	// Zwraca wartosc pensji podanej osoby
	int Sprawdzam(int &i);
};
//Rezerwuje pamiec dla podwojnego wskaznika
void Nadaj_pamiec(Osoba**& rezyser, size_t &ilosc);
//Nadaje wartosci i wyswietla je dla podwojnego wskaznika
void Wypisz_narodowosc(Osoba * const* rezyser, size_t ilosc);
//Usuwa wskazana osobe
void usun_wybranego(Osoba**& rezyser, size_t& ilosc, size_t zmienna_ilosc);
//Zwalnia pamiec dla podwojnego wskaznika
void Usun(Osoba**& rezyser, size_t& ilosc);
//Rezerwuje pamiec dla potrojnego wskaznika
void Nadaj_pamiec(Osoba***& rezyser, size_t& ilosc, size_t &kontr);
//Nadaje wartosci i wyswietla je dla potrojnego wskaznika
void Wypisz_narodowosc(Osoba*const*const* rezyser, size_t* ilosc, size_t* kontr);
//void Usun(Osoba***& rezyser, size_t& ilosc, size_t& kontr);
//void Dodaj(Osoba**& rezyser, size_t& ilosc);

