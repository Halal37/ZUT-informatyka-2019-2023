#pragma once
#include <iostream>
#include "Lista.h"
using namespace std;
class Baza
{
	Lista** lista_osob;
	size_t ilosc_osob{ 0 };
public:
	void stworz(Persona* osoba);
	void usun();
};

