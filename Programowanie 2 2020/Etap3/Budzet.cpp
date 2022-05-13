#include "Budzet.h"
#include <iostream>
using namespace std;
void Budzet::set_finanse() {
	finanse = 4000000;
}
void Budzet::set_finanse2() {
	finanse = 200;
}
double Budzet::get_finanse() const {
	cout << finanse << endl;
		return finanse;
}
void Budzet::nowy_finanse(int i) {
	finanse = i;
}

Budzet::Budzet(double Finanse)
{
	finanse = Finanse;
}
/*Budzet::Budzet(const Budzet& d):wply(new Wplyw_M(d.wply->zwie)),mar(new Marketing (d.mar->kupno)),sprz(new Sprzet(d.sprz->jakosc))
{
	int k = 0;
	k = d.mar->kupno + d.mar->bilb + d.mar->internet + d.mar->plakaty + d.mar->sniad + d.mar->trailer;
}*/
Budzet::Budzet()
{
}
//void Budzet::Sprawdzam2(Budzet bud) {
//	if (bud.finanse > 0)cout << "Ugabugafinansowe" << endl;
//}

Budzet::~Budzet()
{
	/*delete wply;
	delete mar;
	delete sprz;*/
}

int Budzet::zmiana_marketingowa(Marketing bek, int bud)
{
	mar = bek;
	int k = 0;
	k = mar.bilb+mar.internet+mar.kupno+mar.plakaty+mar.sniad+mar.trailer;
	bud -= k;
	return bud;
}

int Budzet::zmiana_sprzetowa(Sprzet sp, int bud)
{
	sprz = sp;
	int k = 0;
	k = sprz.jakosc;
	bud -= k;
	return bud;
}

int Budzet::zmiana_sprzetowa(Sprzet sp, int bud, int c)
{
	sprz = sp;
	int k = 0;
	k = sprz.jakosc*5;
	bud -= k;
	return bud;
}

