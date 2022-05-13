#pragma once
#include "Osoba.h"
#include "Marketing.h"
#include "Sprzet.h"
#include "Film.h"
#include "Dod_funk.h"

class Budzet
{
	Sprzet sprz;
	Marketing mar;
	Wplyw_M wply;
	//Osoba* os;
	double finanse;//Suma pieniêedzy w bud¿ecie, podawana w tysiacach
	//int stala;//Sta³e wydatki
public:
	
	//Zwracanie wartosci bud¿etu
	double get_finanse()const;
	// Bud¿et dla potentata
	void set_finanse();
	// Bud¿et dla ma³ej wytwórni
	void set_finanse2();
	//Poddawanie nowej wartosci bud¿etu
	void nowy_finanse(int i);
	Budzet(double Finanse);
	//Budzet(const Budzet& d);
	Budzet();
//	void Sprawdzam2(Budzet bud);
	~Budzet();
	int zmiana_marketingowa(Marketing bek, int bud);
	int zmiana_sprzetowa(Sprzet sp, int bud);
	int zmiana_sprzetowa(Sprzet sp, int bud,int c);
	//Osoba os;
//	friend void Sprawdzajka(Osoba  os, Budzet bud);
//	Budzet(double Finanse);







};

