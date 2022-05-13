// Test6.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int const rozmiar = 10;
void ini(int *tablica, int pam);
void dane(int *tablica, int pam);
void czyszczenie(int *tablica);
float program21a(int *tablica, int pam);
float program21b(int *tablica, int pam);
float program21c(int *tablica, int pam);
float program21d(int *tablica, int pam);
float program21e(int *tablica, int pam);
float program21f(int *tablica, int pam);
void ini2(int **tablica, int pam);
void inipod(int *tablica, int pam);
void czyszczenie2(int **tablica);
void program22generujdane(int **tablica, int pam);
void zamiana(int **tablica, int pam);
int main()
{
	srand(time(NULL));
	int *tab,**tabela;
	int wybor, n = 1,rozmiardrug,normal;
	float pom;
	
	do {
		printf("1. Program 2.1\n");
		printf("2. Program 2.2\n");
		printf("3. Koniec programu\n");
		printf("Podaj zadanie\n");
		scanf_s("%d\n", &wybor);
		system("cls");
		switch (wybor) {
		case 1:

		{printf("1. Podpunkt 1\n");
		printf("2. Podpunkt 2\n");
		printf("3. Podpunkt 3\n");
		printf("4. Podpunkt 4\n");
		printf("1. Podpunkt 5\n");
		printf("2. Podpunkt 6\n");
			printf("Podaj zadanie\n");
		scanf_s("%d\n", &normal);
		switch (normal) {
		case 1: {
			ini(tab, rozmiar);
			dane(tab, rozmiar);
			pom = program21a(tab, rozmiar);

			printf("%f", &pom);
			czyszczenie(tab);

			}
		case 2: {
			ini(tab, rozmiar);
			dane(tab, rozmiar);
			pom = program21b(tab, rozmiar);

			printf("%f", &pom);
			czyszczenie(tab);

		}
		case 3: {
			ini(tab, rozmiar);
			dane(tab, rozmiar);
			pom = program21c(tab, rozmiar);

			printf("%f", &pom);
			czyszczenie(tab);

		}
		case 4: {
			ini(tab, rozmiar);
			dane(tab, rozmiar);
			pom = program21d(tab, rozmiar);

			printf("%f", &pom);
			czyszczenie(tab);

		}
		case 5: {
			ini(tab, rozmiar);
			dane(tab, rozmiar);
			pom = program21e(tab, rozmiar);

			printf("%f", &pom);
			czyszczenie(tab);

		}
		case 6: {
			ini(tab, rozmiar);
			dane(tab, rozmiar);
			pom = program21f(tab, rozmiar);

			printf("%f", &pom);
			czyszczenie(tab);

		}
			}		
		}
		case 2: {
			printf("Podaj wielkosc tablicy\n");
			scanf_s("%d\n",&rozmiardrug);
			 ini2(tabela,rozmiardrug);
			 inipod(*tabela,rozmiardrug);
			 program22generujdane(tabela, rozmiardrug);
			 zamiana(**tabela, rozmiardrug);
			 czyszczenie(*tabela);
			 czyszczenie2(tabela);
		}
		case 3: {
			n = 0;
		}
		default: {printf("Zle dane\n");

		}
		}
	} while (n == 1);
	//tab= (int*)malloc(rozmiar*sizeof(int));
	//free(tab);

  
}



void ini(int *tablica,int pam) {
	tablica =(int*) malloc(pam * sizeof(int));
}
void dane(int *tablica, int pam) {
	int g = 0;
	for (int i = 0; i < pam; i++) {
		scanf_s("%d", g);
		tablica = &g;
		tablica++;
		printf("%d", *tablica + i);
	}
}
	float program21a(int *tablica,int pam) {
		int suma = 1;
		for (int i = 0; i < pam; i++) {
			suma*= *(tablica + i);
		}
		return suma;
	}
	float program21b(int *tablica, int pam) {
		int suma = 1;
		for (int i = 0; i < pam; i++) {
			if (*(tablica + 1) % 2) {
				suma *= *(tablica + i);
			}
		}
		return suma;
	}
	float program21c(int *tablica, int pam) {
		int suma = 1;
		for (int i = 0; i < pam; i++) {
			if (*(tablica + 1) % 2) {
			}
			else {
				suma *= *(tablica + i);
			}
		}
		return suma;
	}
	float program21d(int *tablica, int pam) {
		int suma = 1;
		for (int i = 0; i < pam; i++) {
			if (*(tablica + 1) > 0) {


				suma *= *(tablica + i);
			}
			
		}
		return suma;
	}
	float program21e(int *tablica, int pam) {
		int suma = 1;
		for (int i = 0; i < pam; i++) {
			if (*(tablica + 1) < 0) {


				suma *= *(tablica + i);
			}

		}
		return suma;
	}
	float program21f(int *tablica, int pam) {
		int k;
		printf("Podaj liczbe porownawcza");
		scanf_s("%d", &k);
		int suma = 1;
		for (int i = 0; i < pam; i++) {
			if (*(tablica + 1) > k) {


				suma *= *(tablica + i);
			}

		}
		return suma;
	}
	void czyszczenie(int *tablica){
		free(tablica);
	}
	void czyszczenie2(int **tablica) {
		free(tablica);
	}
	void ini2(int **tablica, int pam) {
		tablica =(int**)malloc(pam * sizeof(int*));

	}
	void inipod(int *tablica, int pam) {
		for (int i = 0; i < pam; i++) {
			tablica[i] =(int*)malloc(pam * sizeof(int));
		}
	}
	void program22generujdane(int **tablica, int pam) {
		for (int i = 0; i < pam; i++) {
			for (int j = 0; j < pam; j++) {
				*tablica[i][j] = rand() %10  +1;
			}
		}
	}
	void zamiana(int **tablica,int pam) {
		int pomoc;
		for (int i = 0; i < pam; i++) {		
				tablica[i][i]=pomoc;
				tablica[pam-i][pam-i] = tablica[i][i];
				pomoc = tablica[pam - i][pam - i];
		
		}
	}


// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie
// inicjuje działa, kasuje
// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
