// Laby3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <stdio.h>/*Wczytywanie i wypisywanie danych*/
#include <math.h>/*Funkcje matematyczne*/
/*Deklaracja bibliotek*/
const double e = 2.718281828459;/*Deklaracja zmiennej stalej*/
int main()
{
	double x, y, z;/*Deklaracja: 3 Dane,*/
	printf("Podaj 1, 2 i 3 zmienna: ");/*Wyświetlenie prośby o podanie danych z klawiatury*/
	scanf_s("%lf %lf %lf", &x, &y, &z);/*Wpisywanie danych z klawiatury przez użytkownika*/
	double w1, w2, w3, pom1, J3, pot, S;/* 3 czesci skladowe dzialania,3 zmienne pomocnicze,1 wynik dzialania*/
	pom1 = fabs(x - y);/*Zmienna pomocnicza-wartosc bezwgledna*/
	J3 = 1 / 3;/*Zmienna pomocnicza*/
	pot = pow(x, 6);/*Potega 6-pomocnicza*/
	w1 = pow(e, pom1)*pow(pom1, x + y);/*Liczenie 1 skladowej dzialania*/
	w2 = atan(x) + atan(z);/*Liczenie 2 skladowej dzialania*/
	w3 = pow(pot + log2(y), J3);/*Liczenie 3 skladniowej dzialania*/
	S = (w1 / w2) + w3;/*Suma dzialania*/
	printf("Wynik to: %.4f\n", S); /*Polecenie wyswietlenia wyniku dzialania, do 4 miejsc po przecinku*/
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
