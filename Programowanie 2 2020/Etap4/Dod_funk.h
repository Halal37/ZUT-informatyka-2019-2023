#pragma once
#include "Osoba.h"
#include "Film.h"
#include "Budzet.h"
#include "Sprzet.h"
#include "Marketing.h"
#include "Agregacja.h"
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
#include <ctime>
//Pierwsze menu
//void Menu();
// 1 rozwidlenie menu
//void Wybor_opcji1();
// 2 rozwidlenie menu
//void Wybor_opcji1_a();
//Przykladowa dynamiczna tablica
int* Dynamiczna_tablica(int* tablica, int& ilosc);
//Zmiana bud¿etu po wyborze sprzêtu
//int jakas_funkcja2(int z, string s);
//Zmiana bud¿etu po wyborze obsady
//int jakas_funkcja(int z, string s);
//void sprawdzacz(Budzet bud, Osoba os);
void Menuetap3();
void Wybor_opcji1etap3();
void Wybor_opcji1_aetap2();
int jakas_funkcja2etap3(int z, string s);
int jakas_funkcja_marketing_etap3(int bud);
int do_marketingu(int bud);
int do_marketing(int bud, string p);
int zmiana_budzetowa(int bud, int zm);
void wait(int seconds);
int Wybor_ekipy(int budzet);

