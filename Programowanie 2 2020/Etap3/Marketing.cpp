#include "Marketing.h"
#include <iostream>
using namespace std;
Marketing::Marketing(int Kupno, int Sniad, int Plakaty, int Trailer, int Bilb, int Internet) :
	kupno(Kupno),
	sniad(Sniad),
plakaty(Plakaty),
trailer(Trailer),
bilb(Bilb),
internet(Internet){
	if (kupno < 0)cout<<"Blad kupno";
	if (sniad < 0)cout << "Blad sniad";
	if (plakaty < 0)cout << "Blad plakaty";
	if (trailer < 0)cout << "Blad trailer";
	if (bilb< 0)cout << "Blad bilb";
	if (internet < 0)cout << "Blad internet";
}
Marketing::Marketing(int Kupno, int Sniad, int Plakaty, int Trailer, int Bilb):Marketing(Kupno,Sniad,Plakaty,Trailer,Bilb,0){}
Marketing::Marketing(int Kupno, int Sniad, int Plakaty, int Trailer) : Marketing(Kupno, Sniad, Plakaty, Trailer,0) {}
Marketing::Marketing(int Kupno, int Sniad, int Plakaty) : Marketing(Kupno, Sniad, Plakaty, 0) {}
Marketing::Marketing(int Kupno, int Sniad) : Marketing(Kupno, Sniad, 0) {}
Marketing::Marketing(int Kupno) : Marketing(Kupno,0) {}
Marketing::Marketing() : Marketing(0) {}
Marketing::~Marketing()
{
}
void Marketing::informacje_marketingowe() const
{
	cout << "Kupno recenzji: "<<kupno<<endl;
	cout << "Sniadaniowki: "<<sniad<<endl;
	cout<<"Plakaty: "<<plakaty<<endl;
	cout<<"Trailer: "<<trailer<<endl;
	cout << "Bilbordy: " << bilb << endl;
	cout<<"Internet: "<< internet<<endl;
}

Wplyw_M::Wplyw_M(int Zwie, int Zmie):zwie(Zwie),zmie(Zmie)
{
	if (zwie < 0)cout<<"Blad zwie "<<endl;
	if (zmie < 0)cout<<"Blad zmie "<<endl;
}
Wplyw_M::Wplyw_M(int Zwie) : Wplyw_M(Zwie,0){
}
Wplyw_M::Wplyw_M() : Wplyw_M(0){}

Wplyw_M::~Wplyw_M()
{
}

int Sedzia(Marketing mar, Wplyw_M m)
{
	int k = 0,z=0,i=0,sum=0;
	if ((mar.bilb == 0) && (mar.internet == 0) && (mar.kupno == 0) && (mar.sniad == 0) && (mar.trailer == 0) && (mar.plakaty == 0))cout << "Wplyw marketingu to: " << sum << endl;
	else {
		k = ((mar.bilb + 1) * (mar.internet + 1) * (mar.kupno + 1) * (mar.plakaty + 1) * (mar.sniad + 1) * (mar.trailer + 1)) / 6;
		z = k * m.zwie / 100;
		cout << "Dodanie do wplywu: " << z << endl;
		i = k * m.zmie / 100;
		cout << "Odjecie od wplywu: " << i << endl;
		sum = k + z - i;
		cout << "Suma: " << sum << endl;
		if (sum < 0) sum = 0;
		cout << "Wplyw marketingu to: " << sum << endl;
		return sum;
	}
	
}
