#include "Film.h"
#include "Budzet.h"
#include <iostream>
#include <string>
using namespace std;
Film Karamba;
int Film::Wybor_gatunku()
{
	int en = 1;
	do {
		int i = 0;
		cout << "Jaki gatunek ma miec produkcja?" << endl;
		cout << "1. Dramat" << endl;
		cout << "2. Komedia" << endl;
		cout << "3. Gangsterski" << endl;
		cout << "4. Western" << endl;
		cout << "5. Kryminal" << endl;
		cout << "6. Horror" << endl;
		cout << "7. Thriller" << endl;
		cout << "8. Wojenny" << endl;
		cout << "9. Dokumentalny" << endl;
		cout << "10. Sci-fi" << endl;
		cout << "11. Melodramat" << endl;
		cout << "12. Historyczny" << endl;
		cout << "13. Musical" << endl;
		cout << "14. Przygodowy" << endl;
		cout << "15. Animowany" << endl;
		cout << "16. Familijny" << endl;
		cout << "17. Sensacyjny" << endl;
		while (true) {
			cin >> i;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Zly typ" << endl;
			}
			break;
		}
		system("cls");
		if (i < 1 || i>17) {
			cout << "Nie ma takiego gatunku" << endl;
			
		}
		else {
			cout << "Poprawnie wprowadzono gatunek" << endl;
			gat = i;
			en = 0;
		}
		
	} while (en != 0);
	return gat;
}
double Film::Ustal_budzet(int budzet) {
	int i = 0,pomocnicza=1;
	
	do {
		cout << "Jaki budzet ma miec produkcja?" << endl;
		i = 0;
		while (true) {
			cin >> i;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Zly typ" << endl;
			}
			break;
		}
		if ((i > 0) && (i <= budzet)) {
			pomocnicza = 0;
		}
		else {
			cout << "Budzet nie moze byc wiekszy niz oszczednosci studia lub mniejszy/rowny zero" << endl;
		}

	} while (pomocnicza != 0);
	system("cls");
	bud = i;
	return bud;

}
void Film::Nowy_budzet(double i) {
	bud = i;
}
double Film::M_time() {
	int i = 0,pomocnicza=1;
	do {
		cout << "Ile minut ma trwac seans?" << endl;
		while (true) {
			cin >> i;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Zly typ" << endl;
			}
			break;
		}
		if (i > 0) {
			pomocnicza = 0;
		}
		else {
			cout << "Film nie moze trwac zer minut lub krocej" << endl;
		}
	} while (pomocnicza != 0);
	system("cls");
	time = i;
	return time;
}
string Film::set_tyt() {
	//char s[M];
	cout << "Jaki tytul ma nosic produkcja?" << endl;
	cin.ignore();
	getline(cin,tyt);
	cout << tyt << endl;
	//bool blad=cin.fail();
	//cin.clear();
	//cin.ignore(10);
	//tyt = s;
	return tyt;

}
Film::Film(int b, int g, int t, string ty):bud(b),gat(g),time(t),tyt(ty)
{

}
Film::Film()
{
}
/*Film::Film(int b, int g, int t):Film(b,g,t,0){}
Film::Film(int b, int g) : Film(b, g, 0) {}
Film::Film(int b) : Film(b, 0) {}
Film::Film() : Film(0) {}
*/