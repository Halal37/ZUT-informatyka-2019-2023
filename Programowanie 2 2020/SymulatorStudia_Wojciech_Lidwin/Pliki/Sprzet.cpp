#include "Sprzet.h"
#include <iostream>
using namespace std;
void Sprzet::Opcja :: pokaz() {
	cout << "0.Koszt kupna: " << kupno << endl << "1.Koszt wynajmu: " << wynajem << endl;
	cout << endl;
}
Sprzet::Sprzet(int Jakosc) :jakosc(Jakosc) {}
Sprzet::Sprzet() : Sprzet(0) {}
Sprzet::~Sprzet()
{
}
int Sprzet::get_jakosc()
{
	cout << "Jakosc sprzetu: " << jakosc << endl;
	return jakosc;
};
void Sprzet::set_jakosc(int s)
{
	jakosc = s;
}




