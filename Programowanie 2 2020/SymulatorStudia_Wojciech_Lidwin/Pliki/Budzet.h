#pragma once
#include "Marketing.h"
#include "Sprzet.h"
#include "Film.h"
#include "Dod_funk.h"
#include "Baza.h"

class Budzet
{
	Sprzet *sprz;
	Marketing *mar;
	Wplyw_M *wply;

	int finanse;//Suma pieniedzy w bud¿ecie, podawana w tysiacach
	int suma_gat;//Suma  gat ekipy
	int suma_rep;//Suma  rep ekipy
	int suma_prof;//Suma  prof ekipy
	int suma_roz;//Suma  roz ekipy
	int finanse2;//Zmienna do porownania zysku/straty
public:
	
	//Zwracanie zmiennej typu double o nazwie finanse
	double get_finanse()const;
	// Bud¿et dla potentata
	void set_finanse();
	// Bud¿et dla ma³ej wytwórni
	void set_finanse2();
	//Zmiana wartosci zmiennej typu doble o nazwie finanse
	void nowy_finanse(int i);
	//Zmiana wartosci zmiennej typu doble o nazwie finanse
	void nowy_finanse_2(int i);
	int get_finanse2() const;
	Budzet(Marketing* b,Wplyw_M * m,Sprzet*z, double fin,int s_gat,int s_rep,int s_prof,int s_roz);
	Budzet(const Budzet& d);
	Budzet(double Finanse);
	//Przeciazenie operatora wypisanie skladowych Budzet
	friend ostream& operator<< (ostream& wyjscie, const Budzet& s);
	//Przeciazenie operatora obliczanie finansow po odjeciu pieniedzy przeznaczonych na marketing
	friend ostream& operator>> (ostream& wyjscie,  Budzet& s);
	//Przeciazenie operatora, obliczanie wynikow finansowych produkcji
    Budzet operator() (Budzet& s);
	//Przeciazenie operatora, ukazujace, czy produkcja przyniosla zysk/strate
	Budzet operator[](Budzet& s);
	Budzet();
	//Przeciazenie operatora przypisania
	Budzet operator=(Budzet const& d);
	//	Destruktor klasy budzet
	~Budzet();
	






};
//Przeciazenie operatora wypisanie skladowych
ostream& operator<< (ostream& wyjscie, const Budzet& s);
//Przeciazenie operatora, nowe finanse po odjeciu wydatkow marketingowych
ostream& operator>> (ostream& wyjscie, Budzet& s);