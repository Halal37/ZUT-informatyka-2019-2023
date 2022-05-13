#include <stdio.h>
#include <stdlib.h>
#include <time.h>
const int wymiar = 10;
void generuj(const int m,float tab[]);
float suma(const int m, float tab[]);
void generowanie2(int tablica[][], int  m, int  e);
void wyswielt(int tablica[][],int  m, int  e);
void zamiana(int tablica[][],int m, int e, int k1, int k2);

int main()
{ srand(time(NULL));
	int wybor, petla = 0, wiersz, kolumna;
	float tablica[wymiar],ostateczny=0;

	do {
		printf("1. Suma ujemnych z 1.1\n");
		printf("2. Program 1.2 \n");
		printf("3. Koniec programu\n");
		scanf("%d", &wybor);
		system("cls");
		switch (wybor) {
		case 1: {generuj(wymiar, tablica);
			ostateczny = sumauj(wymiar, tablica);
			printf("WYNIK %f\n",ostateczny);
break;
		}
		case 2: {printf("Podaj ilosc wierszy\n");
		scanf("%d", &wiersz);
		printf("Podaj ilosc kolumn\n");
		scanf("%d", &kolumna);
		int tabelka[wiersz][kolumna];
		generowanie2(tabelka,wiersz,kolumna);
wyswietl(tabelka,wiersz,kolumna);
			break;
		}
		case 3: { petla = 1;

		}break;
		default: {printf("Zla wartosc\n");
			break;
		}
		}
	} while (petla == 0);
}
void generuj(const int m,float tab[]) {
	float p;
	for (int i = 0; i < m; i++) {
		printf("Podaj wartosc %d elementu", i+1);
		scanf("%f",&p);
		tab[i] = p;
		printf("%f/n", tab[i]);
	}
}float suma(const int m, float tab[]) {
	float wynik=0,suma=0;
	for (int i = 0; i < m; i++) {
		suma=suma + tab[i];}

	return suma;

}void generuj2(int tablica[][], int maks, int min) {
	for (int i = 0; i < m; i++) {
		for (int  j= 0; j < e; j++) {
			tablica[i][j] = (rand() % 10) + 1;
		}
	}
}

void wyswielt(int tablica[][],int m, int e) {
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < e; j++) {
			printf("%d ", tablica[i][j]);
		}
		printf("\n");
	}
}

void zamiena(int tablica[][],int m,int e,int k1,int k2) {


}
