#include "Osoba.h"
#include <string>
#include <time.h>
#include <iostream>
#define Z 40
using namespace std;
void Osoba::set_rep(int s) { rep = s; }
void Osoba::set_gat(int s) { gat = s; }
void Osoba::set_pen(int s) { pen = s; }
void Osoba::set_roz(int s) { roz = s; }
void Osoba::set_prof(int s) { prof = s; }
void Osoba::set_imie(string s) { imie = s; }
void Osoba::set_nazwisko(string s) { nazwisko = s; }

void Osoba::Rez() {
	srand(time(NULL));
	int c = 0, g = 0;
	Osoba Rezyser[10];
	string imiona[29] { "Martin","Steven","Quentin","Christopher","David","Wesley","Mel","Paolo","Xavier","James","John","Peter","Damien","Denis","Wojciech","Tim","Paul","Clint","Anthony","Taika","Robert","Jim","Guy","Sam","Darren","Alfonso","Terry","Edgar","Ridley" };
	string nazwiska[29]{ "Scorsese","Spilberg","Tarantino","Nolan","Fincher","Anderson","Lynch","Gibson","Sorrentino","Dolan","Cameron","Jackson","Chazelle","Villeneuve","Smarzowski","Burton","Eastwood","Russo","Zemeckis","Waititi","Jarmusch","Ritchie","Mendes","Cuaron","Aronofsky","Gilliam","Wright","Scott","Coen" };
	for (int i = 0; i < 10; i++) {
		Rezyser[i].set_gat(i * i);
		Rezyser[i].set_rep(i * i);
		Rezyser[i].set_pen(i * i);
		Rezyser[i].set_roz(i * i);
		Rezyser[i].set_prof(i * i);
		if (i == 0) {
			Rezyser[i].set_imie("Stazysta");
			Rezyser[i].set_nazwisko("Stazysta");
		}
		else {
			c = rand() % 29;
			g = rand() % 29;
			Rezyser[i].set_imie(imiona[c]);
			Rezyser[i].set_nazwisko(nazwiska[g]);
		}
	}
	cout << "Oferowany kandydat:" << endl;
	for (int i = 0; i < 10; i++) {
		cout << "Nr."<<i<<": " << endl;
		cout << Rezyser[i].get_gat() << "\t";
		cout << endl;
		cout <<"Uznanie krytykow: "<< Rezyser[i].get_rep() << "\t";
		cout << endl;
		cout <<"Pobierana pensja w tysiacach: "<< Rezyser[i].get_pen() << "\t";
		cout << endl;
		cout <<"Rozpoznawalnosc: "<< Rezyser[i].get_roz() << "\t";
		cout << endl;
		cout <<"Profesjonalizm: "<< Rezyser[i].get_prof() << "\t";
		cout << endl;
		cout <<"Imie: "<< Rezyser[i].get_imie() << "\t";
		cout << endl;
		cout <<"Nazwisko: "<< Rezyser[i].get_nazwisko() << "\t";
		cout << endl;
	}
}
int Osoba::Sprawdzam(int &i) {
	Osoba Rezyser;
	Rezyser.set_pen(i * i);
	i=Rezyser.get_pen();
	return i;
}
