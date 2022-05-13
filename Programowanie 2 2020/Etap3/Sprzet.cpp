#include "Sprzet.h"
#include <iostream>
using namespace std;
void Sprzet::Opcja :: pokaz() {
	cout << "Koszt kupna: " << kupno << endl << "Koszt wynajmu: " << wynajem << endl;
}
Sprzet::Sprzet(int Jakosc) :jakosc(Jakosc) {}
Sprzet::Sprzet() : Sprzet(0) {}
Sprzet::~Sprzet()
{
}
/*int Sprzet:: zwroc_kupno(Osoba os)
{
	return os.kupno;
}
int Sprzet:: zwroc_wynajem(Osoba os)
{
	return os.wynajem;
}*/
/*void Sprzet::set_kupno(int s)
{
	kupno = s;
}

void Sprzet::set_wynajem(int s)
{
	wynajem = s;
}
*/
void Sprzet::set_jakosc(int s)
{
	jakosc = s;
}





