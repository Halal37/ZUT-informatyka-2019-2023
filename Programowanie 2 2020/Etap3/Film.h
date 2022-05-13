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
	
	//void Tworz_produkcje();
	int Wybor_gatunku();
	double Ustal_budzet();
	void Nowy_budzet(double i);
	double M_time();//Czas trwania seansu
	string set_tyt();
	// void set_gat(int s);
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
	//Film(int b, int g, int t);
	//Film(int b, int g);
	//Film(int b);
	Film();
	friend class Budzet;
	
};
