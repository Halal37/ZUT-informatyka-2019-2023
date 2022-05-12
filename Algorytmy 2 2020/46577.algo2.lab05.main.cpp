//ALGO2 IS1 223A LAB05
//Wojciech Lidwin
//lw46577@zut.edu.pl

#include <iostream>
#include <time.h>
#include <cmath>
#include <string>
using namespace std;
const double stala = 0.75;
template<typename T>
class Obiekt {
public:
	Obiekt<T>* nastepny;
	string klucz;
	T dane;
	Obiekt<T>(string a, T b);
};
template<typename T>
class Lista {
public:
	Obiekt<int>* poczatek;
	Obiekt<int>* koniec;
	int rozmiar;
	Lista();
	Obiekt<int>* dodaj_do_listy(Obiekt<int>* tym);
};
template<typename T>
class Tablica_Mieszajaca {
public:
	int size;
	int max_size;
	Lista<Obiekt<T>>* tablica_dane;
	Tablica_Mieszajaca<T>();
	void zwieksz_size();
	void zwieksz_max();
	int dodawanie_elementu(Obiekt<T>* tym);
	void czyszczenie();
	int napis_mieszanie(Obiekt<T>* tym);
	int umieszczenie_w_tablicy(Obiekt<T>* tym);
	string zwroc_napis();
	Obiekt<T>* szukaj(Obiekt<T>* tym);
	Obiekt<T>* usun_konkretny(Obiekt<T>* tym);
	string dane_listy();
};
string klucz() {
	string s="";
	for (int i = 0; i < 6; i++) {
    s+=rand() % 26 + 97;
	}
	return s;
}
template<typename T>
Obiekt<T>* kopia(Obiekt<T>* dana) {
	return new Obiekt<T>(*dana);
}
int main()
{
	srand(time(NULL));
   string napis;
   Tablica_Mieszajaca<int>* tablica = new Tablica_Mieszajaca<int>();
   clock_t t1 = clock();
   for (int i = 0; i < 10000; i++) {
	   napis = klucz();
	   Obiekt<int>* do_dodania = new Obiekt<int>(napis, i);
	   tablica->dodawanie_elementu(do_dodania);
   }
   clock_t t2 = clock();
   cout << "Czas dodawania obiektow: " << t2 - t1 << endl;
   int trafienia = 0;
   t1 = clock();
   for (int i = 0; i < 10000; i++) {
	   napis = klucz();
	   Obiekt<int>* do_dodania = new Obiekt<int>(napis, i);
	   if ((tablica->szukaj(do_dodania) != NULL)) {
		   trafienia++;
	   }
   }
   t2 = clock();
   cout << "Ilosc trafien: " << trafienia << endl;
   cout << "Czas szukania trafien: " << t2 - t1 << endl;
  cout<< tablica->zwroc_napis();
   tablica->czyszczenie();
   delete tablica;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > dodaj_do_listy nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > dodaj_do_listy istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
template<typename T>
Tablica_Mieszajaca<T>::Tablica_Mieszajaca()
{
	size = 0;
	max_size = 1;
	Lista<Obiekt<T>>* temp = new Lista<Obiekt<T>>[max_size];
	delete[] tablica_dane;
	tablica_dane = temp;

}

template<typename T>
void Tablica_Mieszajaca<T>::zwieksz_size()
{
	size = size + 1;
}

template<typename T>
void Tablica_Mieszajaca<T>::zwieksz_max()
{
	max_size = max_size * 2;
}
template<typename T>
int Tablica_Mieszajaca<T>::dodawanie_elementu(Obiekt<T>* tym)
{
	if (size <= stala*max_size) {
		int sprawdzanie_duplikatu=umieszczenie_w_tablicy(tym);
		if (sprawdzanie_duplikatu == 1) {
			zwieksz_size();
			return 1;
		}
		return 0;
	}else
	{
		int do_petli = max_size;
		zwieksz_max();
		Lista<Obiekt<T>>* temp = new Lista<Obiekt<T>>[max_size];
		for (int i = 0; i < do_petli; i++) {
			temp[i] = tablica_dane[i];
		}
		Lista<Obiekt<T>>* temp_2 = new Lista<Obiekt<T>>[max_size];
		delete[] tablica_dane;
		tablica_dane = temp_2;
		for (int i = 0; i < do_petli; i++) {
			if (temp[i].poczatek != NULL) {
				Obiekt<T>* tymczasowy = temp[i].poczatek;
				Obiekt<T>* tymczasowy_twardy = kopia(temp[i].poczatek);
				while (tymczasowy_twardy != NULL) {
					tymczasowy = kopia(tymczasowy_twardy);
					int sprawdzanie_duplikatu = umieszczenie_w_tablicy(tymczasowy);
					tymczasowy_twardy = tymczasowy_twardy->nastepny;
				}
			}
		}

		int sprawdzanie_duplikatu = umieszczenie_w_tablicy(tym);
		if (sprawdzanie_duplikatu == 1) {
			zwieksz_size();
			return 1;
		}
		return 0;
	}

}
template<typename T>
void Tablica_Mieszajaca<T>::czyszczenie()
{
	delete[] tablica_dane;
	size = 0;
	max_size = 1;

}

template<typename T>
int Tablica_Mieszajaca<T>::napis_mieszanie(Obiekt<T>* tym)
{
	int zwrot = 0;
	for (int i = 0; i < tym->klucz.length(); i++) {
		zwrot = zwrot + tym->klucz[i] * pow(31, tym->klucz.length() - (1 + i));
	}
	return abs(zwrot % max_size);
}

template<typename T>
int Tablica_Mieszajaca<T>::umieszczenie_w_tablicy(Obiekt<T>* tym)
{
	int temp = napis_mieszanie(tym);
	if (tablica_dane[temp].poczatek == NULL) {
		tablica_dane[temp].dodaj_do_listy(tym);
		return 1;
	}
	else {
		Obiekt<T> *tymczasowy = tablica_dane[temp].poczatek;
		while (tymczasowy != NULL) {
			if (tymczasowy->klucz == tym->klucz) {
				tymczasowy->dane = tym->dane;
				return 2;
			}
			tymczasowy = tymczasowy->nastepny;
		}
		tablica_dane[temp].dodaj_do_listy(tym);
	}
	return 1;
}

template<typename T>
string Tablica_Mieszajaca<T>::zwroc_napis()
{
	string do_wypisania="";
	for (int i = 0; i < max_size; i++) {
		if ((i < 10) || i > max_size - 11) {
			if (tablica_dane[i].poczatek != NULL) {
				Obiekt<T>* tymczasowy = tablica_dane[i].poczatek;
				do_wypisania = do_wypisania +to_string(i) + " ";
				while (tymczasowy != NULL) {
					do_wypisania = do_wypisania + tymczasowy->klucz + "---> " + to_string(tymczasowy->dane) + " ";
					tymczasowy = tymczasowy->nastepny;
				}
				do_wypisania = do_wypisania + '\n';
			}
			else {
				do_wypisania = do_wypisania + to_string(i) + '\n';
			}
		}
	}
	do_wypisania = do_wypisania + dane_listy();
	do_wypisania = do_wypisania + "Rozmiar: " + to_string(size) + '\n';
	do_wypisania = do_wypisania + "Max Rozmiar: " + to_string(max_size) + '\n';
	return do_wypisania;
}

template<typename T>
Obiekt<T>* Tablica_Mieszajaca<T>::szukaj(Obiekt<T>* tym)
{
	int temp = napis_mieszanie(tym);
	Obiekt<T>* tymczasowy = tablica_dane[temp].poczatek;
	while (tymczasowy != NULL) {
		if (tymczasowy->klucz == tym->klucz) {
			return tymczasowy;
		}
		tymczasowy = tymczasowy->nastepny;
	}
	return NULL;
}

template<typename T>
Obiekt<T>* Tablica_Mieszajaca<T>::usun_konkretny(Obiekt<T>* tym)
{
	int temp = napis_mieszanie(tym);
	Obiekt<T>* tymczasowy = tablica_dane[temp].poczatek;
	Obiekt<T>* poprzedni=tymczasowy;
	while (tymczasowy != NULL) {
		if (tymczasowy->klucz == tym->klucz) {
			if ((tymczasowy == tablica_dane[temp].poczatek) && (tymczasowy == tablica_dane[temp].koniec)) {
				tablica_dane[temp].poczatek = NULL;
				tablica_dane[temp].koniec = NULL;
				size = size - 1;
				return NULL;
			}
			else if((tymczasowy == tablica_dane[temp].poczatek)) {
				tablica_dane[temp].poczatek = tymczasowy->nastepny;
				delete tymczasowy;
				size = size - 1;
				return NULL;
			}
			else {
				poprzedni->nastepny = tymczasowy->nastepny;
				delete tymczasowy;
				size = size - 1;
				return NULL;
			}
		}
		poprzedni = tymczasowy;
		tymczasowy = tymczasowy->nastepny;
	}
	return tym;
}

template<typename T>
string Tablica_Mieszajaca<T>::dane_listy()
{
	string do_wypisania;
	int nie_puste=0;
	int maks=0;
	int min=0;
	double srednia = 0;
	int rozmiar = 0;
	for (int i = 0; i < max_size; i++) {
		if (tablica_dane[i].poczatek != NULL) {
			nie_puste += 1;
			min = 1;
			Obiekt<T>* tymczasowy = tablica_dane[i].poczatek;
			while (tymczasowy != NULL) {
				rozmiar += 1;
				tymczasowy = tymczasowy->nastepny;
			}
			srednia += rozmiar;
				if (maks < rozmiar) {
					maks = rozmiar;
				}
		}
		rozmiar = 0;
	}
	srednia = srednia / nie_puste;
	do_wypisania= "Nie puste " + to_string(nie_puste) + '\n';
	do_wypisania=do_wypisania+ "Sredni rozmiar " + to_string(srednia) + '\n';
	do_wypisania= do_wypisania+ "MAX " + to_string(maks) + '\n';
	do_wypisania= do_wypisania+ "MIN " + to_string(min) + '\n';
	return do_wypisania;
}

template<typename T>
Obiekt<int>* Lista<T>::dodaj_do_listy(Obiekt<int>* tym)
{
	if (koniec != NULL) koniec->nastepny = tym;
	tym->nastepny = NULL;
	koniec = tym;
	if (poczatek == NULL) poczatek = koniec;
	rozmiar++;
	return koniec;
}

template<typename T>
Obiekt<T>::Obiekt(string a, T b)
{
	klucz = a;
	dane = b;
	nastepny = NULL;
}
template<typename T>
Lista<T>::Lista()
{
	poczatek = NULL;
	koniec = NULL;
	rozmiar = 0;
}
