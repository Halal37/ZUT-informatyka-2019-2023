#pragma once
#include "Persona.h"
class Dzwiekowiec :
	public Persona
{
public:
	Dzwiekowiec() = default;
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
};

