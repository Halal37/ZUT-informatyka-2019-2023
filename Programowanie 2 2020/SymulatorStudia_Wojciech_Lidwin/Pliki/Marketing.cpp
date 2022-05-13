#include "Marketing.h"
#include <iostream>
using namespace std;
enum {
	zero = 0,
	jeden = 1,
	dwa = 2,
	trzy = 3,
	cztery = 4,
	piec = 5,
	szesc = 6,
	siedem = 7,
	dziewiec = 9,
	ten = 10,
	trzynascie = 13,
	czternascie = 14,
	pietnascie = 15,
	szescnascie = 16,
	dziewietnascie = 19,
	dwadziescie = 20,
	trzydziesci = 30,
	trzydziesci_dziewiec = 39,
	czterdziesci = 40,
	czterdziesci_dziewiec = 49,
	piecdziesiat = 50,
	piecdziesiat_dziewiec = 59,
	szescdziesiat = 60,
	szescdziesiat_dziewiec = 69,
	siedemdziesiat = 70,
	siedemdziesiat_dziewiec = 79,
	osiem = 8,
	stala = 29,
	osiemdziesiat = 80,
	sto=100,
	dzwiescie = 200
};
Marketing::Marketing(int Kupno, int Sniad, int Plakaty, int Trailer, int Bilb, int Internet) :
	kupno(Kupno),
	sniad(Sniad),
plakaty(Plakaty),
trailer(Trailer),
bilb(Bilb),
internet(Internet){
	if (kupno < zero)cout<<"Blad kupno";
	if (sniad < zero)cout << "Blad sniad";
	if (plakaty < zero)cout << "Blad plakaty";
	if (trailer < zero)cout << "Blad trailer";
	if (bilb< zero)cout << "Blad bilb";
	if (internet < zero)cout << "Blad internet";
}
Marketing::Marketing(int Kupno, int Sniad, int Plakaty, int Trailer, int Bilb):Marketing(Kupno,Sniad,Plakaty,Trailer,Bilb,zero){}
Marketing::Marketing(int Kupno, int Sniad, int Plakaty, int Trailer) : Marketing(Kupno, Sniad, Plakaty, Trailer,zero) {}
Marketing::Marketing(int Kupno, int Sniad, int Plakaty) : Marketing(Kupno, Sniad, Plakaty, zero) {}
Marketing::Marketing(int Kupno, int Sniad) : Marketing(Kupno, Sniad, zero) {}
Marketing::Marketing(int Kupno) : Marketing(Kupno,zero) {}
Marketing::Marketing() : Marketing(zero) {}
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
	if (zwie < zero)cout<<"Blad zwie "<<endl;
	if (zmie < zero)cout<<"Blad zmie "<<endl;
}
Wplyw_M::Wplyw_M(int Zwie) : Wplyw_M(Zwie,zero){
}
Wplyw_M::Wplyw_M() : Wplyw_M(zero){}

Wplyw_M::~Wplyw_M()
{
}

int Wplyw_M::get_zwie()const
{
	return zwie;
}

int Wplyw_M::get_zmie()const
{
	return zmie;
}


int Sedzia(Marketing mar, Wplyw_M m)
{
	int k = zero,z=zero,i=zero,sum=zero;
	if ((mar.bilb == zero) && (mar.internet == zero) && (mar.kupno == zero) && (mar.sniad == zero) && (mar.trailer == zero) && (mar.plakaty == zero))cout << "Wplyw marketingu to: " << sum << endl;
	else {
		k = ((mar.bilb + jeden) * (mar.internet + jeden) * (mar.kupno + jeden) * (mar.plakaty + jeden) * (mar.sniad + jeden) * (mar.trailer + jeden)) / szesc;
		z = k * m.zwie / sto;
		cout << "Dodanie do wplywu: " << z << endl;
		i = k * m.zmie / sto;
		cout << "Odjecie od wplywu: " << i << endl;
		sum = k + z - i;
		cout << "Suma: " << sum << endl;
		if (sum < zero) sum = zero;
		cout << "Wplyw marketingu to: " << sum << endl;
	}
		return sum;
	
	}
//Sprawdzanie czy mozna przeznaczyc dana sume pieniedzy na budzet marketingowy
int do_marketingu(int bud) {
	int h = jeden, era = zero;
	do {
		cout << "Budzet marketingowy: " << endl;
		while (true) {
			cin >> era;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Zly typ" << endl;
			}
			break;
		}
		if ((bud < era) || era < zero)cout << "Zla wartosc" << endl;
		else h = zero;
	} while (h != zero);
	return era;
}
//Sprawdzanie czy mozna przeznaczyc dana sume pieniedzy na poszczegolna forme marketingowa
int do_marketing(int bud, string p) {
	int z = jeden, rec = zero;
	do {
		if (bud == zero) {
			rec = zero;
			z = zero;
		}
		else {
			cout << p << endl;
			cout << endl;
			while (true) {
				cin >> rec;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Zly typ" << endl;
				}
				break;
			}
			if ((bud < rec) || (rec < zero))cout << "Zla wartosc" << endl;
			else {
				bud -= rec;
				z = zero;
			}
		}
	} while (z != zero);
	cout << rec << " :Taka wartosc" << endl;
	return rec;
}
int zmiana_budzetowa(int bud, int zm) {
	bud -= zm;
	return bud;
}

void Marketing::Rozdzial_budzetu_marketingowego(int bud) {
	int era = zero, rec = zero, sna = zero, pl = zero, tra = zero, bil = zero, inte = zero;
	array<string, szesc> Tabela{ "Kupno recenzji: ","Reklamy na sniadaniowkach: ","Plakaty: ", "Trailery: ", "Bilb: ", "Kampania internetowa: " };
	int h = jeden, z = jeden, k = jeden, nas = jeden, kar = jeden, pol = jeden, per = jeden; //kontrolki 
	cout << "Zostalo tyle w budzetcie studia: " << endl;
	cout << bud << endl;
	era = do_marketingu(bud);
	rec = do_marketing(era, Tabela[zero]);
	era = zmiana_budzetowa(era, rec);
	kupno = rec;
	sna = do_marketing(era, Tabela[jeden]);
	era = zmiana_budzetowa(era, sna);
	sniad = sna;
	pl = do_marketing(era, Tabela[dwa]);
	era = zmiana_budzetowa(era, pl);
	plakaty = pl;
	tra = do_marketing(era, Tabela[trzy]);
	era = zmiana_budzetowa(era, tra);
	trailer = tra;
	bil = do_marketing(era, Tabela[cztery]);
	era = zmiana_budzetowa(era, bil);
	bilb = bil;
	inte = do_marketing(era, Tabela[piec]);
	era = zmiana_budzetowa(era, inte);
	internet = inte;

}

int Marketing::get_kupno()const
{
	return kupno;
}

int Marketing::get_sniad()const
{
	return sniad;
}

int Marketing::get_plakaty()const
{
	return plakaty;
}

int Marketing::get_trailer()const
{
	return trailer;
}

int Marketing::get_bilb()const
{
	return bilb;
}

int Marketing::get_internet()const
{ 
	return internet;
}

