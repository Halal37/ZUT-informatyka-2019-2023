#pragma once
#include <iostream>
#include <string>
#define M 50
using namespace std;
class Film
{
	int gat{};//Gatunek
	double bud;//Budzet
	double time;//Czas
public:
	string tyt;//Tytul 
	
	//void Tworz_produkcje();
	int Wybor_gatunku();
	double Ustal_budzet();
	void Nowy_budzet(double i);
	double M_time();//Czas trwania seansu
	string set_tyt();
	// Zwracanie warcosci gatunek
	int get_gat() const {
		cout << gat << endl;
		return gat;
	};
	// Zwracanie warcosci bud¿etu
	double get_bud() const {
		cout << bud << endl;
		return bud;
	};
	// Zwracanie warcosci czas
	double get_time() const {
		cout << time << endl;
		return time;
	};
	// Zwracanie warcosci tytu³u
	string get_tyt() const {
		cout << tyt << endl;
		return tyt;
	};
	
};
