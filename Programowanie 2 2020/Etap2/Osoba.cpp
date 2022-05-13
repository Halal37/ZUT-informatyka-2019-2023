#include "Osoba.h"
#include <string>
#include <time.h>
#include <iostream>
#define Z 40
using namespace std;
void Osoba::set_rep(int s) {rep = s; }
void Osoba::set_gat(int s) { gat = s; }
void Osoba::set_pen(int s) { pen = s; }
void Osoba::set_roz(int s) { roz = s; }
void Osoba::set_prof(int s) { prof = s; }
void Osoba::set_imie(string s) { imie = s; }
void Osoba::set_nazwisko(string s) { nazwisko = s; }



void Nadaj_pamiec(Osoba**& rezyser, size_t &ilosc) {
	Osoba** temp = new Osoba * [ilosc + 1];
	if (ilosc == 0) {
		temp[ilosc] = new Osoba;
		//Osoba2** pacjenci;
	}
	else {
		for (size_t i = 0; i < ilosc; ++i) {
			temp[i] = rezyser[i];
		}
		temp[ilosc] = new Osoba;
		delete[] rezyser;
	}
	++ilosc;
	rezyser = temp;
}
void Nadaj_pamiec(Osoba***& rezyser, size_t& ilosc,size_t &kontr) {
	Osoba***tyr = new Osoba * *[kontr + 1];
	
	if (kontr == 0) {
		tyr[kontr]  = new Osoba * [ilosc + 1];
		if (ilosc == 0) {
			tyr[kontr][ilosc] = new Osoba;
		}
		else {
			for (size_t i = 0; i < ilosc; ++i) {
				tyr[kontr][ilosc]=rezyser[kontr][ilosc];
			}
			tyr[kontr][ilosc] = new Osoba;
			delete[] rezyser[kontr];
			delete[] rezyser;
		}
		++ilosc;
		rezyser =tyr ;
		
	}
}
/*void wymysl_nazwe(Osoba** rezyser, size_t ilosc) {
	for (size_t i = 0; i < ilosc; ++i) {
		rezyser[i]->set_gat(i * i);
		rezyser[i]->set_rep(i * i);
		rezyser[i]->set_pen(i * i);
		rezyser[i]->set_roz(i * i);
		rezyser[i]->set_prof(i * i);
		cout << "Narodowosc: " << "\t" << "Amerikanin" << endl;
		cout << "Nr." << i << ": " << endl;
		cout << rezyser[i]->get_gat() << "\t";
		cout << endl;
		cout << "Uznanie krytykow: " << rezyser[i]->get_rep() << "\t";
		cout << endl;
		cout << "Pobierana pensja w tysiacach: " << rezyser[i]->get_pen() << "\t";
		cout << endl;
		cout << "Rozpoznawalnosc: " << rezyser[i]->get_roz() << "\t";
		cout << endl;
		cout << "Profesjonalizm: " << rezyser[i]->get_prof() << "\t";
		cout << endl;
	}
}*/
void Wypisz_narodowosc(Osoba*const* rezyser, size_t ilosc) {
	int c;
	string Tabela[19]{ "Polak","Wloch","Rosjanin","Francuz","Kanadyjczyk","Australijczyk","Czech","Nowo Zelandczyk","Meksykanin","Hiszpan","Wegier","Ukrainiec","Niemiec","Slowak","Litwin","Holender","Bialorusin","Belg" };
	cout << "=========================================================" << endl;
	for (size_t i = 0; i < ilosc; ++i) {
		if (rezyser[i]->get_narod() == 1) {
			rezyser[i]->set_gat(i * i);
			rezyser[i]->set_rep(i * i);
			rezyser[i]->set_pen(i * i);
			rezyser[i]->set_roz(i * i);
			rezyser[i]->set_prof(i * i);
			cout << "Narodowosc: " << "\t" << "Amerikanin" << endl;
			cout << "Nr." << i << ": " << endl;
			cout << rezyser[i]->get_gat() << "\t";
			cout << endl;
			cout << "Uznanie krytykow: " << rezyser[i]->get_rep() << "\t";
			cout << endl;
			cout << "Pobierana pensja w tysiacach: " << rezyser[i]->get_pen() << "\t";
			cout << endl;
			cout << "Rozpoznawalnosc: " << rezyser[i]->get_roz() << "\t";
			cout << endl;
			cout << "Profesjonalizm: " << rezyser[i]->get_prof() << "\t";
			cout << endl;
		}
		else {
			c = rand()%19;
			rezyser[i]->set_gat(i * i);
			rezyser[i]->set_rep(i * i);
			rezyser[i]->set_pen(i * i);
			rezyser[i]->set_roz(i * i);
			rezyser[i]->set_prof(i * i);
			cout << "Narodowosc: " << "\t" << Tabela[c] << endl;
			cout << "Nr." << i << ": " << endl;
			cout << rezyser[i]->get_gat() << "\t";
			cout << endl;
			cout << "Uznanie krytykow: " << rezyser[i]->get_rep() << "\t";
			cout << endl;
			cout << "Pobierana pensja w tysiacach: " << rezyser[i]->get_pen() << "\t";
			cout << endl;
			cout << "Rozpoznawalnosc: " << rezyser[i]->get_roz() << "\t";
			cout << endl;
			cout << "Profesjonalizm: " << rezyser[i]->get_prof() << "\t";
			cout << endl;

		}
	}
}

void Wypisz_narodowosc(Osoba*const*const* rezyser, size_t* ilosc,size_t* kontr) {
	int c;
	string Tabela[19]{ "Polak","Wloch","Rosjanin","Francuz","Kanadyjczyk","Australijczyk","Czech","Nowo Zelandczyk","Meksykanin","Hiszpan","Wegier","Ukrainiec","Niemiec","Slowak","Litwin","Holender","Bialorusin","Belg" };
	cout << "=========================================================" << endl;
	for (size_t i = 0; i < *ilosc; ++i) {
		if (rezyser[*kontr][i]->get_narod() == 1) {
			rezyser[*kontr][i]->set_gat(i * i);
			rezyser[*kontr][i]->set_rep(i * i);
			rezyser[*kontr][i]->set_pen(i * i);
			rezyser[*kontr][i]->set_roz(i * i);
			rezyser[*kontr][i]->set_prof(i * i);
			cout << "Narodowosc: " << "\t" << "Amerikanin" << endl;
			cout << "Nr." << i << ": " << endl;
			cout << rezyser[*kontr][i]->get_gat() << "\t";
			cout << endl;
			cout << "Uznanie krytykow: " << rezyser[*kontr][i]->get_rep() << "\t";
			cout << endl;
			cout << "Pobierana pensja w tysiacach: " << rezyser[*kontr][i]->get_pen() << "\t";
			cout << endl;
			cout << "Rozpoznawalnosc: " << rezyser[*kontr][i]->get_roz() << "\t";
			cout << endl;
			cout << "Profesjonalizm: " << rezyser[*kontr][i]->get_prof() << "\t";
			cout << endl;
		}
		else {
			c = rand() % 19;
			rezyser[*kontr][i]->set_gat(i * i);
			rezyser[*kontr][i]->set_rep(i * i);
			rezyser[*kontr][i]->set_pen(i * i);
			rezyser[*kontr][i]->set_roz(i * i);
			rezyser[*kontr][i]->set_prof(i * i);
			cout << "Narodowosc: " << "\t" << Tabela[c] << endl;
			cout << "Nr." << i << ": " << endl;
			cout << rezyser[*kontr][i]->get_gat() << "\t";
			cout << endl;
			cout << "Uznanie krytykow: " << rezyser[*kontr][i]->get_rep() << "\t";
			cout << endl;
			cout << "Pobierana pensja w tysiacach: " << rezyser[*kontr][i]->get_pen() << "\t";
			cout << endl;
			cout << "Rozpoznawalnosc: " << rezyser[*kontr][i]->get_roz() << "\t";
			cout << endl;
			cout << "Profesjonalizm: " << rezyser[*kontr][i]->get_prof() << "\t";
			cout << endl;

		}
	}
}


void Usun(Osoba**& rezyser, size_t& ilosc) {
	for (size_t i = 0; i < ilosc; ++i)
		delete rezyser[i];
	delete[] rezyser;
	rezyser = nullptr;
	ilosc = 0;
}
/*void Usun(Osoba***& rezyser, size_t& ilosc,size_t &kontr) {
	for (size_t i = 0; i < ilosc; ++i)
		delete rezyser[kontr][i];
//	delete[] rezyser[kontr];
	delete[] rezyser;
	rezyser = nullptr;
	ilosc = 0;
	kontr = 0;
	

}*/


void usun_wybranego(Osoba**& rezyser, size_t& ilosc, size_t zmienna_ilosc) {
	if (zmienna_ilosc < ilosc) {
		Osoba** temp = new Osoba * [ilosc - 1];
		short int j{ -1 };
		for (size_t i = 0; i < ilosc; ++i)
			if (i != zmienna_ilosc) {
				++j;
				temp[j] = rezyser[i];
			}
		delete[] rezyser;
		--ilosc;
		rezyser = temp;
	}
	else
		cout << "Index jest nieprawid³owy !" << endl;
}
/*void Dodaj(Osoba**& rezyser, size_t& ilosc) {
//	if (zmienna_ilosc + ilosc > ilosc) {
	ilosc++;
		Osoba** temp = new Osoba * [ilosc];
		for (size_t i = 0; i < ilosc;i++) {
			temp[i] = rezyser[i];
		}
		delete[] rezyser;
		++ilosc;
		rezyser = temp;

	//}
	//else
	cout << "Zla wartosc" << endl;
}*/
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
