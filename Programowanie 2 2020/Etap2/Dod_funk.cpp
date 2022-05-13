#include "Dod_funk.h"
#include "Film.h"
#include "Budzet.h"
#include "Osoba.h"
#include "Sprzet.h"
#include <iostream>
using namespace std;
Film Prod;
Budzet Gra;
Osoba Tablica_rez;
Sprzet Do_produkcji;
//void Nadaj_pamiec(Osoba**& rezyser, size_t ilosc);
//void Wypisz_narodowosc(Osoba** rezyser, size_t ilosc);
//void Usun(Osoba**& rezyser, size_t& ilosc);
static void menuwyp() {
	cout << "Menu" << endl;
}
static void powrot() {
	cout << "Powrot" << endl;
}
static void punkt1() {
	cout << "1.Zacznij gre" << endl;
}
static void punkt1_a(){//Rozwidlenie a punktu 1 
	cout << "Wybierz punkt startowy" << endl;
}
static void punkt1_a_a(){//Rozwidlenie a rozwidlenia a punktu 1 
	cout << "1.Poczatkujace studio" << endl;
}
static void punkt1_a_b(){//Rozwidlenie b rozwidlenia a punktu 1 
	cout << "2.Swiatowy potentant" << endl;
}
static void wyjscie() {
	cout << "0.Wyjdz z gry" << endl;
}
static void tworcy() {
	cout << "3.Tworcy" << endl;
}
static void punkt2() {
	cout << "2.Wczytaj gre" << endl;
}
static void ja() {
	cout << "Ja" << endl;
}
static void zm_budzet() {
	cout << "Za maly budzet;" << endl;
}
static void zatrudnij_obsade() {
	cout << "Zatrudnij obsade" << endl;
}
static void ogarnij_sprzet2() {
	cout << "Ogarnij sprzet" << endl;
}
void obecny_budzet(int z) {
	cout << "Obecny budzet: " << z << endl;
}
int jakas_funkcja(int z,string s) {
	char ch;
	int k = 0, ort = 0, Rezy = 1;
	do {
		system("cls");
		Tablica_rez.Rez();
		obecny_budzet(z);
		cout << "Ktorego "<<s<<" chcesz zatrudnic?" << endl;
		cin >> k;
		ch = getchar();
		k = Tablica_rez.Sprawdzam(k);
		if (z < k)
			zm_budzet();
		else {
			ort = z - k;
			cout << ort << endl;
			Prod.Nowy_budzet(ort);
			Prod.get_bud();
			z = ort;
			Rezy = 0;
		}
	} while (Rezy != 0);
	return z;
}//Rezysera
int jakas_funkcja2(int z,string s) {
	int k = 0,ort=0,zmienna=0,kamera=1,n=0;
	char ch,zn;
	do {
		system("cls");
		Do_produkcji.Sprzecior_gigant();
		obecny_budzet(z);
		cout << s<< endl;
		cout << "Jaki jest twoj wybor" << endl;
		cin >> k;
		ch = getchar();
		cout << "Chcesz wynajac, czy kupic?" << endl;
		cin >> zmienna;
		zn = getchar();
		n = k;
		k = Do_produkcji.Sprawdzam(Do_produkcji, k, zmienna);
		n = Do_produkcji.Sprawdzam(Do_produkcji, n);
		cout << n << endl;
		if (z < k)
			zm_budzet();
		else {
			ort = z - k;
			cout << ort << endl;
			Prod.Nowy_budzet(ort);
			Prod.get_bud();
			z = ort;
			kamera = 0;
		}
	} while (kamera != 0);
	return z;
}
void Wybor_opcji1_a() {
	int n = 1,p=1, wybor = 0,z,k=0,h=1;
	string Tabelka[8]{ "Rezysera","Scenarzyste","Operatora","Kompozytora","Montazyste","Scenografa","Kostiumografa","Dzwiekowca" };
	string Tabelka2[3]{ "Kamera","Mikrofon","Efekty specjalne" };
	float a;
	char ch;
	do {
		punkt1_a_a();
		punkt1_a_b();
		cout << "3."; powrot();
		cin >> wybor;
		ch = getchar();
		system("cls");
		switch (wybor) {
		case 1:		
			do {
				system("cls");
				Gra.set_finanse2();
				Gra.get_finanse();
				a = Gra.get_finanse();
				Prod.Wybor_gatunku();
				do {
					z = Prod.Ustal_budzet();
					cout << a << endl;
					cout << z << endl;
					if (a < z)
						zm_budzet();
					else {
						Gra.nowy_finanse(a - z);
						Prod.M_time();
						Prod.set_tyt();
						Prod.get_tyt();
						h = 0;
					}
				} while (h!=0);
				h = 1;
				zatrudnij_obsade();
					
				for (int j = 0; j < 8; j++) {
					z = jakas_funkcja(z, Tabelka[j]);
				}
			
                         ogarnij_sprzet2();
						 for (int g = 0; g < 3; g++) {
							 z = jakas_funkcja2(z, Tabelka2[g]);
						 }
						 p = 0;
			

				} while (p != 0);
				n = 0;
			
			break;
		case 2:
			Gra.set_finanse();
			Gra.get_finanse();
			do{
				system("cls");
			a = Gra.get_finanse();
			Prod.Wybor_gatunku();
			do{
			z = Prod.Ustal_budzet();
			cout << a << endl;
			cout << z << endl;
			if (a < z)
				zm_budzet();
			else {
				Prod.M_time();
				Prod.set_tyt();
				Prod.get_gat();
		
				h = 0;
			}
			} while (h != 0);
			
			zatrudnij_obsade();
			for (int j = 0; j < 8; j++) {
				z = jakas_funkcja(z, Tabelka[j]);
			}
		

ogarnij_sprzet2();
for (int g = 0; g < 3; g++) {
	z = jakas_funkcja2(z, Tabelka2[g]);
}
p = 0;

			} while (p != 0);
			n = 0;
			break;
		case 3:
			
			Wybor_opcji1();
			n = 0;
			break;
		default:
			n = 0;
			break;
		}
	
	} while (n != 0);
}

void Wybor_opcji1() {
	int n=1, wybor = 0;
	char ch;
	do {
		
		menuwyp();
		punkt1();
		punkt2();
		tworcy();
		wyjscie();
		
		cin >> wybor;
		ch = getchar();
		system("cls");
		switch (wybor) {
		case 1:
			punkt1_a();
			Wybor_opcji1_a();
			n = 0;
			
			break;
		case 2:
			//Na razie nic nie robi
			n = 0;
			break;
		case 3:
			ja();
			n = 0;
			break;
		case 0:
			n = 0;
			break;
		default:
			cout << "Podana zla wartosc" << endl;
			menuwyp();
			punkt1();
			punkt2();
			tworcy();
			wyjscie();
			while ((ch = getchar()) != '\n');
			break;
		}
		
	} while (n != 0);
}
int* Dynamiczna_tablica(int* tablica, int& ilosc)
{
	ilosc++;

	int* temp = new int[ilosc ];

	for (int i = 0; i < ilosc ; i++)
	{
		temp[i] = tablica[i];
	}

	delete[]tablica;

	return temp;
}


void Menu() {
	/*menuwyp();
	punkt1();
	punkt2();
	tworcy();
	wyjscie();*/
	Wybor_opcji1();
}