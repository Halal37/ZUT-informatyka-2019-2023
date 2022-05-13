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

Budzet::Budzet(Marketing* b, Wplyw_M* m, Sprzet* z,double fin)
{
	finanse = fin;
	mar = new Marketing(b->kupno,b->sniad,b->plakaty,b->trailer,b->bilb,b->internet);
	wply = new Wplyw_M(m->zwie,m->zmie);
	sprz = new Sprzet(z->jakosc);
}

Budzet::Budzet(double Finanse)
{
	finanse = Finanse;
}
void Budzet::Budzet_pofilmie()
{
	int k = 0, z = 0, i = 0, sum = 0, g = 0,zaz=0,obliczeniowka=0;
	if ((mar->bilb == 0) && (mar->internet == 0) && (mar->kupno == 0) && (mar->sniad == 0) && (mar->trailer == 0) && (mar->plakaty == 0))cout << "Wplyw marketingu to: " << sum << endl;
	else {
		k = ((mar->bilb + 1) * (mar->internet + 1) * (mar->kupno + 1) * (mar->plakaty + 1) * (mar->sniad + 1) * (mar->trailer + 1)) / 6;
		cout << "Bilbord: " << mar->bilb << endl << "Internet: " << mar->internet << endl << "Kupno: " << mar->kupno << endl << "Plakaty: " << mar->plakaty << endl << "Sniad: " << mar->sniad << endl << "Trailer: " << mar->trailer << endl;
		z = k * wply->zwie / 100;
		cout << "Dodanie do wplywu: " << z << endl;
		i = k * wply->zmie / 100;
		cout << "Odjecie od wplywu: " << i << endl;
		sum = k + z - i;
		cout << "Suma: " << sum << endl;
		if (sum < 0) sum = 0;
		cout << "Wplyw marketingu to: " << sum << endl;
		zaz = 200 - finanse;
		g = sprz->jakosc * 15;
		obliczeniowka = ((zaz * 200000) + (g * 150000) + sum)/100000;
		cout << "Obliczeniowka to: " << obliczeniowka << endl;
		finanse = finanse +obliczeniowka;
	}
}
int Budzet::Odjecie_wplywow(Budzet& d)
{
	int k = 0, z = 0, i = 0, sum = 0;
	if ((d.mar->bilb == 0) && (d.mar->internet == 0) && (d.mar->kupno == 0) && (d.mar->sniad == 0) && (d.mar->trailer == 0) && (d.mar->plakaty == 0))cout << "Wplyw marketingu to: " << sum << endl;
	else {
		k = ((d.mar->bilb + 1) * (d.mar->internet + 1) * (d.mar->kupno + 1) * (d.mar->plakaty + 1) * (d.mar->sniad + 1) * (d.mar->trailer + 1)) / 6;
		cout << "Bilbord: " << d.mar->bilb << endl << "Internet: " << d.mar->internet << endl << "Kupno: " << d.mar->kupno << endl << "Plakaty: " << d.mar->plakaty << endl << "Sniad: " << d.mar->sniad << endl << "Trailer: " << d.mar->trailer << endl;
		z = k * d.wply->zwie / 100;
		cout << "Dodanie do wplywu: " << z << endl;
		i = k * d.wply->zmie / 100;
		cout << "Odjecie od wplywu: " << i << endl;
		sum = k + z - i;
		cout << "Suma: " << sum << endl;
		if (sum < 0) sum = 0;
		cout << "Wplyw marketingu to: " << sum << endl;
	}
		return sum;
	
}
int Budzet::Odjecie_wplywow()
{
	int g = 0;
	
		g=mar->kupno + mar->bilb + mar->internet + mar->plakaty + mar->sniad + mar->trailer;
		finanse = finanse - g;
	
	return g;

}
/*Budzet::Budzet(const Budzet& d):wply(new Wplyw_M(d.wply->zwie)),mar(new Marketing (d.mar->kupno)),sprz(new Sprzet(d.sprz->jakosc))
{
	int k = 0;
	k = d.mar->kupno + d.mar->bilb + d.mar->internet + d.mar->plakaty + d.mar->sniad + d.mar->trailer;
}*/
Budzet::Budzet()
{
	finanse = 200;
	mar = new Marketing();
	wply = new Wplyw_M();
	sprz = new Sprzet();

}
Budzet::Budzet(const Budzet& d):mar(new Marketing(d.mar->kupno,d.mar->sniad,d.mar->plakaty,d.mar->trailer,d.mar->bilb,d.mar->internet)),
wply(new Wplyw_M(d.wply->zwie,d.wply->zmie)),
sprz(new Sprzet(d.sprz->jakosc)),
finanse(d.finanse)
{
	int k = 0;
	k = d.mar->kupno + d.mar->bilb + d.mar->internet + d.mar->plakaty + d.mar->sniad + d.mar->trailer;
	int jako = 0;
	jako = d.sprz->jakosc;
	int wplywik = 0;
	//d.wply->zwie = d.wply->zwie - d.wply->zmie;
	wplywik = d.wply->zwie - d.wply->zmie;
	d.get_finanse();
	int budzet = d.finanse;
	cout << "Budzet to: " << budzet << endl << "Wplyw marketingowy to: " << d.wply->zwie <<endl<<"Zabawa math: "<< wplywik << endl << "Suma budzetu marketingowego: " << k << endl << "Jakosc sprzetu: " <<jako<< endl;
}
//void Budzet::Sprawdzam2(Budzet bud) {
//	if (bud.finanse > 0)cout << "Ugabugafinansowe" << endl;
//}

Budzet::~Budzet()
{
	delete wply;
	delete mar;
	delete sprz;
	cout << "Usunelo jest git: dobrze robia" << endl;
}

