#pragma once
#include "Film.h"
#include "Budzet.h"
#include "Sprzet.h"
#include "Marketing.h"
#include "Persona.h"
#include "Rezyser.h"
#include "Baza.h"
#include "Scenarzysta.h"
#include "Operator.h"
#include "Kompozytor.h"
#include "Monatzysta.h"
#include "Scenograf.h"
#include "Kostiumograf.h"
#include "Dzwiekowiec.h"
#include <vector>
#include <Windows.h>
#include <ctime>
namespace Funkcje {
	//Glowna funkcja, pierwsze menu
	void Glowne_menu();
	//Drugie menu, wybieramy rozpoczecie gry, lub wyswietlenie listy tworcow, lub zakonczenie pracy programu
	void Menu_pierwszy_wybor_uzytkownika();
	//Funckja realizowana, gdy wybierzemy rozpoczecie gry
	void Pod_menu();
	//Przeciazenie Pod_menu. Funckja realizowana, dla kolejnych iteracji
	void Pod_menu(int bud, vector<int>& Magazyn, Budzet &Pierwszy);
	//Funkcja, pozwalajaca na odczekanie podanej wartosci czasu w sekundach do nastepnego polecenia
	void wait(int seconds);
	//Funkcja realizujaca wybor ekipy do realizowanej produkcji
	int Wybor_ekipy(int budzet, vector<int>& Tablica_wartosci);
	//Funckja zwracajaca nowa wartosc budzetu, po dokonaniu przez uzytkownika wyboru czlonka ekipy
	int korekcja_budzetu(int budzet, string s, int& zupka);
	//Przecziazenie funkcji korekcja_budzetu dla klasy Rezyserow
	int korekcja_budzetu(int budzet, string s, int& zupka, Rezyser ha);
	//Przeciazenie funkcji korekcja_budzetu dla klasy Scenarzysta
	int korekcja_budzetu(int budzet, string s, int& zupka, Scenarzysta ha);
	//Wybor przez uzytkownika sprzetow do produkcji filmowych
	int Wybor_sprzetu(int z, string s, vector<int>& Tab, int rodzaj, vector<int>& Zapis_wyborow);
}
