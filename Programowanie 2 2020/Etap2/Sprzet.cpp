#include "Sprzet.h"
#include <iostream>
using namespace std;
void Sprzet::set_kupno(int s)
{
	kupno = s;
}

void Sprzet::set_wynajem(int s)
{
	wynajem = s;
}

void Sprzet::set_jakosc(int s)
{
	jakosc = s;
}

void Sprzet::Sprzecior_gigant()
{
	Sprzet Golem[5];
	for (int i = 0; i < 5; i++) {
		Golem[i].set_kupno((i+1) * 5);
		Golem[i].set_wynajem(i * 5);
		Golem[i].set_jakosc(i * 5);
	}
	for (int i = 0; i < 5; i++) {
		cout<<"Cena kupna: "<<Golem[i].get_kupno() << endl;
		cout<<"Koszt wynajmu: " << Golem[i].get_wynajem() << endl;
		cout<<"Stan jakosci: " << Golem[i].get_jakosc() << endl;
	}
}
int Sprzet::Sprawdzam(Sprzet &Rezyser,int k,int m)
{
	int i;
	//Sprzet Rezyser;
	if (m == 1) {
		Rezyser.set_wynajem(5 * k);
		i = Rezyser.get_wynajem();
	}
	else {
		Rezyser.set_kupno(5 * (k + 1));
		i = Rezyser.get_kupno();
	}
	return i;
}
int Sprzet::Sprawdzam(Sprzet &Rezyser,int k) {
	int i;
	Rezyser.set_jakosc(5 * (k + 1));
	i = Rezyser.get_kupno();
	return i;

}