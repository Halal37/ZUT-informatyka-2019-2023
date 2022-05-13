// Test3laby.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include "pch.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main()
{/*3.1*/
	int wybor,k;
	int n=1;
	double budzet, procent = 0.03, suma = 0, pozyczka = 0, spodnie = 129.99, skarpety = 10.99, kaszkiet = 45.99, koszula = 89.99, rekawiczki = 27.99, buty = 178.99;
	srand(time(NULL));
	budzet = rand() % 1500 + 1;
	printf("Twoj budzet to: %f\n", budzet);
	do {
		printf("Wypierz produkt, lub zakoncz zakupy\n");
		printf("1. Zakup spodnie\n Cena: %f\n",spodnie);
		printf("2. Zakup skarpety\n Cena: %f\n",skarpety);
		printf("3. Zakup towaru\n Cena: %f\n",kaszkiet);
		printf("4. Zakup towaru\n Cena: %f\n",koszula);
		printf("5. Zakup towaru\n Cena: %f\n",rekawiczki);
		printf("6. Zakup towaru\n Cena: %f\n",buty);
		printf("7. Zakoncz zakupy\n");
		scanf_s("%d", &wybor);
		system("cls");
		switch (wybor) {
		case 1: {if (budzet < spodnie) {
			printf("Czy chcesz wziasc pozyczke\n");
			printf("1. Biore pozyczke\n");
			printf("2. Nie biore pozyczki koncze zakupy\n");
			scanf_s("%d", &k);
			system("cls");
			switch (k) {
			case 1: {pozyczka = pozyczka + (spodnie*procent)+spodnie-budzet;
				budzet =0;
				printf("Obecny budzet: %f\n", budzet);
				suma += spodnie;
				printf("Obecna suma: %f\n", suma);
				break;
			}
			case 2: {n = 0;

			}break;
			default: {
				printf("Podana zla wartosc\n");
				break;
			}
			}
		}
				else {
			budzet -= spodnie;
			printf("Obecny budzet: %f\n", budzet);
			suma += spodnie;
			printf("Obecna suma: %f\n", suma);
		}
			break;
		}
		case 2: {if (budzet < skarpety) {
			printf("Czy chcesz wziasc pozyczke\n");
			printf("1. Biore pozyczke\n");
			printf("2. Nie biore pozyczki koncze zakupy\n");
			scanf_s("%d", &k);
			system("cls");
			switch (k) {
			case 1: {pozyczka = pozyczka + (skarpety *procent)+skarpety - budzet;
				budzet = 0;
				printf("Obecny budzet: %f\n", budzet);
				suma += skarpety;
				printf("Obecna suma: %f\n", suma);
				break;
			}
			case 2: {n = 0;

			}break;
			default: {
				printf("Podana zla wartosc\n");
				break;
			}
			}
		}
				else {
			budzet -= skarpety;
			printf("Obecny budzet: %f\n", budzet);
			suma += skarpety;
			printf("Obecna suma: %f\n", suma);
		}
			break;

		}
		case 3: {if (budzet < kaszkiet) {
			printf("Czy chcesz wziasc pozyczke\n");
			printf("1. Biore pozyczke\n");
			printf("2. Nie biore pozyczki koncze zakupy\n");
			scanf_s("%d", &k);
			system("cls");
			switch (k) {
			case 1: {pozyczka = pozyczka + (kaszkiet*procent) + kaszkiet - budzet;
				budzet = 0;
				printf("Obecny budzet: %f\n", budzet);
				suma += kaszkiet;
				printf("Obecna suma: %f\n", suma);
				break;
			}
			case 2: {n = 0;

			}break;
			default: {
				printf("Podana zla wartosc\n");
				break;
			}
			}
		}
				else {
			budzet -= kaszkiet;
			printf("Obecny budzet: %f\n", budzet);
			suma += kaszkiet;
			printf("Obecna suma: %f\n", suma);
		}
			break;

		}
		case 4: {if (budzet < koszula) {
			printf("Czy chcesz wziasc pozyczke\n");
			printf("1. Biore pozyczke\n");
			printf("2. Nie biore pozyczki koncze zakupy\n");
			scanf_s("%d", &k);
			system("cls");
			switch (k) {
			case 1: {pozyczka = pozyczka + (koszula*procent) + koszula - budzet;
				budzet = 0;
				printf("Obecny budzet: %f\n", budzet);
				suma += koszula;
				printf("Obecna suma: %f\n", suma);
				break;
			}
			case 2: {n = 0;

			}break;
			default: {
				printf("Podana zla wartosc\n");
				break;
			}
			}
		}
				else {
			budzet -= koszula;
			printf("Obecny budzet: %f\n", budzet);
			suma += koszula;
			printf("Obecna suma: %f\n", suma);
		}
			break;

		}
		case 5: {if (budzet < rekawiczki) {
			printf("Czy chcesz wziasc pozyczke\n");
			printf("1. Biore pozyczke\n");
			printf("2. Nie biore pozyczki koncze zakupy\n");
			scanf_s("%d", &k);
			system("cls");
			switch (k) {
			case 1: {pozyczka = pozyczka + (rekawiczki*procent) + rekawiczki - budzet;
				budzet = 0;
				printf("Obecny budzet: %f\n", budzet);
				suma += rekawiczki;
				printf("Obecna suma: %f\n", suma);
				break;
			}
			case 2: {n = 0;

			}break;
			default: {
				printf("Podana zla wartosc\n");
				break;
			}
			}
		}
				else {
			budzet -= rekawiczki;
			printf("Obecny budzet: %f\n", budzet);
			suma += rekawiczki;
			printf("Obecna suma: %f\n", suma);
		}
			break;

		}
		case 6: {if (budzet < buty) {
			printf("Czy chcesz wziasc pozyczke\n");
			printf("1. Biore pozyczke\n");
			printf("2. Nie biore pozyczki koncze zakupy\n");
			scanf_s("%d", &k);
			system("cls");
			switch (k) {
			case 1: {pozyczka = pozyczka + (buty*procent) + buty - budzet;
				budzet = 0;
				printf("Obecny budzet: %f\n", budzet);
				suma += buty;
				printf("Obecna suma: %f\n", suma);
				break;
			}
			case 2: {n = 0;

			}break;
			default: {
				printf("Podana zla wartosc\n");
				break;
			}
			}
		}
				else {
			budzet -= buty;
			printf("Obecny budzet: %f\n", budzet);
			suma += buty;
			printf("Obecna suma: %f\n", suma);
		}
			break;

		}
		case 7: {
			n = 0; }
			break;
		
		default: {
			printf("Podana zla wartosc\n");
			break;
		}
		}
	} while (n==1);

    printf("Suma wydatkow to: %0.2f\n",suma); 
	printf("Saldo budzetu to: %0.2f\n", budzet);
	printf("Koszty zwiazane ze zwrotem pozyczki: %0.2f\n", pozyczka);
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
