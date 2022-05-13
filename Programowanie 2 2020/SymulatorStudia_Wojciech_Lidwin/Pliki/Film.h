#pragma once
#include <iostream>
#include <string>
#define M 50
using namespace std;
class Film
{
	int gat{};//Gatunek
	double bud;//Budzet
	double time;
public:
	string tyt;//Tytul 
	
	//Wybor gatunku przez uzytkownika
	int Wybor_gatunku();
	//Ustalenie budzetu przez uzytkownika
	double Ustal_budzet(int budzet);
	//Zmiana wartosci bud na wprowadzona 
	void Nowy_budzet(double i);
	//Ustalenie czasu trwania seansu
	double M_time();
	//Wprowadzenie przez uztkownika nazwy produkcji
	string set_tyt();
	// Zwracanie wartosci gatunek
	int get_gat() const {
		cout << gat << endl;
		return gat;
	};
	// Zwracanie wartosci budzetu
	double get_bud() const {
		cout << bud << endl;
		return bud;
	};
	// Zwracanie wartosci czas
	double get_time() const {
		cout << time << endl;
		return time;
	};
	// Zwracanie wartosci tytulu
	string get_tyt() const {
		cout << tyt << endl;
		return tyt;
	};
	Film( int b, int g, int t, string ty);
	Film();
	friend class Budzet;
	
};
