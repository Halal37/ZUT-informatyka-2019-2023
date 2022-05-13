#include "Budzet.h"
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
	zmienna=100000,
	zmienna2=150000,
	dzwiescie = 200,
	zmienna3= 200000,
	finanse_pot= 4000000
};
// Bud¿et dla potentata
void Budzet::set_finanse() {
	finanse = finanse_pot;
}
// Bud¿et dla ma³ej wytwórni
void Budzet::set_finanse2() {
	finanse = dzwiescie;
}
//Zwracanie zmiennej typu double o nazwie finanse
double Budzet::get_finanse() const {
	cout << finanse << endl;
		return finanse;
}
//Zmiana wartosci zmiennej typu doble o nazwie finanse
void Budzet::nowy_finanse(int i) {
	finanse = i;
}
//Zmiana wartosci zmiennej typu doble o nazwie finanse
void Budzet::nowy_finanse_2(int i) {
	finanse2 = i;
}
int Budzet::get_finanse2() const {
	cout << finanse2 << endl;
	return finanse2;
}

Budzet::Budzet(Marketing* b, Wplyw_M* m, Sprzet* z,double fin, int s_gat, int s_rep, int s_prof, int s_roz)
{
	finanse = fin;
	mar = new Marketing(b->kupno,b->sniad,b->plakaty,b->trailer,b->bilb,b->internet);
	wply = new Wplyw_M(m->zwie,m->zmie);
	sprz = new Sprzet(z->jakosc);
	suma_gat = s_gat;
	suma_rep = s_rep;
	suma_prof = s_prof;
	suma_roz = s_roz;
}

Budzet::Budzet(double Finanse)
{
	finanse = Finanse;
}
Budzet Budzet::operator()(Budzet& s)
{
	int k = zero, z = zero, i = zero, sum = zero, g = zero, zaz = zero, obliczeniowka = zero;
	if ((mar->bilb == zero) && (mar->internet == zero) && (mar->kupno == zero) && (mar->sniad == zero) && (mar->trailer == zero) && (mar->plakaty == zero))cout << "Wplyw marketingu to: " << sum << endl;
	else {
		k = ((mar->bilb + jeden) * (mar->internet + jeden) * (mar->kupno + jeden) * (mar->plakaty + jeden) * (mar->sniad + jeden) * (mar->trailer + jeden)) / szesc;
		cout << "Bilbord: " << mar->bilb << endl << "Internet: " << mar->internet << endl << "Kupno: " << mar->kupno << endl << "Plakaty: " << mar->plakaty << endl << "Sniad: " << mar->sniad << endl << "Trailer: " << mar->trailer << endl;
		z = k * wply->zwie / sto;
		cout << "Dodanie do wplywu: " << z << endl;
		i = k * wply->zmie / sto;
		cout << "Odjecie od wplywu: " << i << endl;
		sum = k + z - i;
		cout << "Suma: " << sum << endl;
		if (sum < zero) sum = zero;
		cout << "Wplyw marketingu to: " << sum << endl;
		//zaz = finanse2 - finanse;
		;
		auto reputacja = (suma_rep* rand() % piec)/ rand() % ten;
		auto gatunki = suma_gat - czterdziesci;
		if (gatunki < zero)
			gatunki = zero;
		auto profesjonalizm = ((suma_prof * suma_prof) / rand() % cztery) - rand() % dwadziescie;
		if (profesjonalizm < zero)
			profesjonalizm = zero;
		auto rozpoznawalnosc =suma_roz/suma_gat;
		zaz = reputacja + gatunki + profesjonalizm + rozpoznawalnosc;
		g = sprz->jakosc;
		obliczeniowka = ((zaz * zmienna3) + (g * zmienna2) + sum) / zmienna;
		cout << "Obliczeniowka to: " << obliczeniowka << endl;
		finanse = finanse + obliczeniowka;
		return Budzet();
	}
}
Budzet Budzet::operator[](Budzet& s)
{
	int a = zero;
	cout << "Poczatkowe saldo studia: " << finanse2 << endl;
	a = finanse - finanse2;
	cout << "Taki zysk z produkcji: "<<a << endl;
	return Budzet();
}
//Konstruktor Budzetu
Budzet::Budzet()
{
	finanse = dzwiescie;
	mar = new Marketing();
	wply = new Wplyw_M();
	sprz = new Sprzet();

}
Budzet::Budzet(const Budzet& d):mar(new Marketing(d.mar->kupno,d.mar->sniad,d.mar->plakaty,d.mar->trailer,d.mar->bilb,d.mar->internet)),
wply(new Wplyw_M(d.wply->zwie,d.wply->zmie)),
sprz(new Sprzet(d.sprz->jakosc)),
finanse(d.finanse),
 suma_gat (d.suma_gat),
suma_rep	 (d.suma_rep),
suma_prof	 (d.suma_prof),
suma_roz	 (d.suma_roz)
{
	int k = zero;
	k = d.mar->kupno + d.mar->bilb + d.mar->internet + d.mar->plakaty + d.mar->sniad + d.mar->trailer;
	int jako = zero;
	jako = d.sprz->jakosc;
	int wplywik = zero;
	//d.wply->zwie = d.wply->zwie - d.wply->zmie;
	wplywik = d.wply->zwie - d.wply->zmie;
	d.get_finanse();
	int budzet = d.finanse;
	cout << "Budzet to: " << budzet << endl << "Wplyw marketingowy to: " << d.wply->zwie <<endl<<"Zabawa math: "<< wplywik << endl << "Suma budzetu marketingowego: " << k << endl << "Jakosc sprzetu: " <<jako<< endl;
}

//Dekonstruktor klasy budzet
Budzet::~Budzet()
{
}

ostream& operator<< (ostream& wyjscie, const Budzet& s) {
	return wyjscie << "Stan finansow:" << s.finanse << endl << "Jakosc: " << s.sprz->get_jakosc() << endl << "Zwiekszenie wplywow: " << s.wply->get_zwie() << endl <<
		"Zmieniesze wplywow: " << s.wply->get_zmie() << endl << "Kupno: " << s.mar->get_kupno() << endl << "Bilbordy: " << s.mar->get_bilb() << endl
		<< "Internet: " << s.mar->get_internet() << endl<<"Plakaty: "<<s.mar->get_plakaty()<<endl<<"Sniadaniowki: "<<s.mar->get_sniad()<<endl<<
		"Trailery: "<<s.mar->get_trailer()<<endl;
}
ostream& operator>> (ostream& wyjscie, Budzet& s) {
	int g = zero;

	g = s.mar->get_kupno() + s.mar->get_bilb() + s.mar->get_internet() + s.mar->get_plakaty() + s.mar->get_sniad() + s.mar->get_trailer();
	s.finanse = s.finanse - g;
	 return wyjscie;
}
Budzet Budzet:: operator=(Budzet const& d) {
	if (&d != this) {
		delete wply;
		delete mar;
		delete sprz;
		wply = d.wply;
		mar = d.mar;
		sprz = d.sprz;
		finanse = d.finanse;
		finanse2 = d.finanse2;
		suma_gat = d.suma_gat;
		suma_rep = d.suma_rep;
		suma_prof = d.suma_prof;
			suma_roz = d.suma_roz;
	}
	return *this;
}