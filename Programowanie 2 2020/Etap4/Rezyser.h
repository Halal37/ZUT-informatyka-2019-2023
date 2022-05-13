#pragma once
#include "Persona.h"
#include<ctime>
class Zmiana_wplywow {
	int a{ 0 };
public: int get_a() { return a; }
	  void set_a() { 
		  int c = 0;
		  c = rand() % 9000;
		  if((c>8000)||(c<250))
		  a = (a+1)*(a+1); }

};
class Rezyser :
	public Persona
{
	static Zmiana_wplywow* wplywy;
public:
	Rezyser() = default;
	void set_gat(int s);
	// Podawanie wartosci reputacji
	void set_rep(int s);
	// Podawanie wartosci pensji
	void set_pen(int s);
	// Podawanie wartosci rozpoznawalnosc
	void set_roz(int s);
	// Podawanie wartosci profesjonalizm
	void set_prof(int s);
	// Podawanie wartosci imie
	void set_imie(string s);
	//
	void set_nazwisko(string s);
	void stworz(int z);
	static int get_wplyw() { return wplywy->get_a(); }
	static void set_wplyw() { wplywy->set_a(); }
		static void zarezerwuj() { wplywy = new Zmiana_wplywow; }
	static void zwolnij() { delete wplywy; }

};

