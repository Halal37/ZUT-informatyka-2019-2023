#include "Film.h"
#include "Budzet.h"
#include <iostream>
#include <string>
using namespace std;
Film Karamba;
int Film::Wybor_gatunku()
{
	int i=0;
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
	cin >> i;
	system("cls");
	if (i < 1 || i>17) {
		cout << "Nie ma takiego gatunku" << endl;
	}
	else {
		cout << "Poprawnie wprowadzono gatunek" << endl;
		gat = i;
		return gat;
	}
	}
double Film::Ustal_budzet() {
	cout << "Jaki budzet ma miec produkcja?" << endl;
	int i = 0;
	cin >> i;
	system("cls");
	bud = i;
	return bud;

}
void Film::Nowy_budzet(double i) {
	bud = i;
}
double Film::M_time() {
	cout << "Ile minut ma trwac seans?" << endl;
	int i = 0;
	cin >> i; 
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
/*void Film::Tworz_produkcje()
{
	//string tekst;
	
	Karamba.Wybor_gatunku();
	Karamba.Ustal_budzet();
	Karamba.M_time();
	Karamba.set_tyt();
	Karamba.get_gat();
	Karamba.get_bud();
	Karamba.get_time();
	Karamba.get_tyt();
	
}*/