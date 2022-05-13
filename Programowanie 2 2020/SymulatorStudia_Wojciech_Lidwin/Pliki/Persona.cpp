#include "Persona.h"
Baza* Persona::getbaze() {
	if (!baza) {
		baza = new Baza;
	}
	return baza;
}

Baza* Persona::baza = Persona::getbaze();
//Zwraca zmienna int o nazwie gat
int Persona::get_gat() const
{
	return gat;
}

void Persona::set_gat(int s)
{
}
//Zwraca zmienna int o nazwie rep
int Persona::get_rep() const
{
	return rep;
}

void Persona::set_rep(int s)
{
}
//Zwraca zmienna int o nazwie pen
int Persona::get_pen() const
{
	return pen;
}

void Persona::set_pen(int s)
{
}
//Zwraca zmienna int o nazwie roz
int Persona::get_roz() const
{
	return roz;
}

void Persona::set_roz(int s)
{
}
//Zwraca zmienna int o nazwie prof
int Persona::get_prof() const
{
	return prof;
}

void Persona::set_prof(int s)
{
}
//Zwraca zmienna string o nazwie imie
string Persona::get_imie() const
{
	return imie;
}

void Persona::set_imie(string s)
{
}
//Zwraca zmienna string o nazwie nazwisko
string Persona::get_nazwisko() const
{
	
	return nazwisko;
	
}
//Wyswietla kandydata o podanym numerze
void Persona::Wyswietl(int z) {
	cout << "Oferowany kandydat:" << endl;
	cout << "Nr." << z << ": " << endl;
	cout << get_gat() << "\t";
	cout << endl;
	cout << "Uznanie krytykow: " << get_rep() << "\t";
	cout << endl;
	cout << "Pobierana pensja w tysiacach: " << get_pen() << "\t";
	cout << endl;
	cout << "Rozpoznawalnosc: " << get_roz() << "\t";
	cout << endl;
	cout << "Profesjonalizm: " << get_prof() << "\t";
	cout << endl;
	cout << "Imie: " << get_imie() << "\t";
	cout << endl;
	cout << "Nazwisko: " << get_nazwisko() << "\t";
	cout << endl;
}

