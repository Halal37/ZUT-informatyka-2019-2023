//ALGO2 IS1 223A LAB08
//Wojciech Lidwin
//lw46577@zut.edu.pl


#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
int liczba_bez_kompresji_z_rangami = 0;
int liczba_z_kompresja_z_rangami = 0;
int liczba_bez_kompresji_bez_rang = 0;
int liczba_z_kompresja_bez_rang = 0;
using namespace std;
template<typename T>
class Obiekt {
public:
    Obiekt<T>* nastepny;
    T dane;
    Obiekt<T>(T b);
};
template<typename T>
class Lista {
public:
    T* poczatek;
    T* koniec;
    int rozmiar;
    Lista();
    T* dodaj_do_listy(T* tym);
    void sortowanie_listy();
};
class Wezel {
public:
    double x;
    double y;
    Wezel();
};
class Krawedz {
public:
    int index_x;
    int index_y;
    double waga;
    Krawedz();
};
class Graf {
public:
    int liczba_wierzcholkow;
    int liczba_krawedzi;
    Krawedz* krawedzie;
    Graf(int a, int b, Krawedz *temp);
};
class Union_Find {
public:
    int* rodzice;
    double* rangi;
    int find_z_kompresja(int temp);
    int find_z_kompresja_2(int temp);
    int find_bez_kompresji(int temp);
    int find_bez_kompresji_2(int temp);
    void union_by_rank_z_kompresja(int x,int y);
    void union_by_rank_bez_kompresji(int x, int y);
    void zwykla_unia_z_kompresja(int x, int y);
    void zwykla_unia_bez_kompresji(int x, int y);
    Union_Find(int dana);
};

string kruskal_z_kompresja_z_rangami(Graf* temp);
string kruskal_bez_kompresji_z_rangami(Graf* temp);
string kruskal_z_kompresja_bez_rang(Graf* temp);
string kruskal_bez_kompresji_bez_rang(Graf* temp);
void sortowanie_kubelkowe(Graf* tablica);
int main()
{
    ifstream odczyt("g2.txt");
    if (odczyt.is_open()) {
        char liczba[10];
        char dana[10];
        odczyt.getline(liczba, 10);
        int zmienna = stoi(liczba);
        Wezel* wez = new Wezel[zmienna];
        for (int i = 0; i < zmienna; i++) {
            odczyt >> wez[i].x>> wez[i].y;
        }
        odczyt >> dana;
        int zmienna2 = stoi(dana);
        Krawedz* kra = new Krawedz[zmienna2];
        cout << endl;
        for (int i = 0; i < zmienna2; i++) {
            odczyt >> kra[i].index_x >>kra[i].index_y>>kra[i].waga;
        }
        Graf do_zadania(zmienna, zmienna2, kra);
        Graf do_zadania1(zmienna, zmienna2, kra);
        Graf do_zadania2(zmienna, zmienna2, kra);
        Graf do_zadania3(zmienna, zmienna2, kra);
        cout << "Wynik 1: " << endl;
        string wynik1 =kruskal_z_kompresja_z_rangami(&do_zadania);
        cout << wynik1;
        cout << endl;
        cout << "Wynik 2: " << endl;
        string wynik2= kruskal_bez_kompresji_z_rangami(&do_zadania1);
        cout<< wynik2;
        cout << endl;
        cout << "Wynik 3: " << endl;
        string wynik3=kruskal_z_kompresja_bez_rang(&do_zadania2);
        cout<< wynik3;
        cout << endl;
        cout << "Wynik 4: " << endl;
        string wynik4=kruskal_bez_kompresji_bez_rang(&do_zadania3);
        cout<< wynik4;
        cout << endl;
    }
    else {
        cout << "Plik sie nie otworzyl" << endl;
    }

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

Krawedz::Krawedz()
{
   index_x=0;
   index_y=0;
   waga=0;
}

Wezel::Wezel()
{
    x=0;
    y=0;
}

int Union_Find::find_z_kompresja(int temp)
{
    liczba_z_kompresja_bez_rang++;
    if (rodzice[temp] != temp) {
        rodzice[temp] = find_z_kompresja(rodzice[temp]);
    }


        return rodzice[temp];

}

int Union_Find::find_z_kompresja_2(int temp)
{
    liczba_z_kompresja_z_rangami++;
    if (rodzice[temp] != temp) {
        rodzice[temp] = find_z_kompresja(rodzice[temp]);
    }


    return rodzice[temp];
}

int Union_Find::find_bez_kompresji(int temp)
{
    liczba_bez_kompresji_bez_rang++;
    if(rodzice[temp] != temp){

    return find_bez_kompresji(rodzice[temp]);
    }
    return temp;
}

int Union_Find::find_bez_kompresji_2(int temp)
{
    liczba_bez_kompresji_z_rangami++;
    if (rodzice[temp] != temp) {

        return find_bez_kompresji(rodzice[temp]);
    }
    return temp;
}

void Union_Find::union_by_rank_z_kompresja(int x, int y)
{
    int korzen_x = find_z_kompresja_2(x);
    int korzen_y = find_z_kompresja_2(y);
    if (rangi[korzen_x] < rangi[korzen_y]) {
        rodzice[korzen_x] = korzen_y;
    }
    else if (rangi[korzen_x] > rangi[korzen_y]) {
        rodzice[korzen_y] = korzen_x;
    }
    else {
        rodzice[korzen_y] = korzen_x;
        rangi[korzen_x] = rangi[korzen_x] + 1;
    }
}

void Union_Find::union_by_rank_bez_kompresji(int x, int y)
{
    int korzen_x = find_bez_kompresji_2(x);
    int korzen_y = find_bez_kompresji_2(y);
    if (rangi[korzen_x] < rangi[korzen_y]) {
        rodzice[korzen_x] = korzen_y;
    }
    else if (rangi[korzen_x] > rangi[korzen_y]) {
        rodzice[korzen_y] = korzen_x;
    }
    else {
        rodzice[korzen_y] = korzen_x;
        rangi[korzen_x] = rangi[korzen_x] + 1;
    }
}

void Union_Find::zwykla_unia_z_kompresja(int x, int y)
{
    int korzen_x = find_z_kompresja(x);
    int korzen_y = find_z_kompresja(y);
    if (korzen_x != korzen_y) {
        rodzice[korzen_x] = korzen_y;
    }
}

void Union_Find::zwykla_unia_bez_kompresji(int x, int y)
{
    int korzen_x = find_bez_kompresji(x);
    int korzen_y = find_bez_kompresji(y);
    if (korzen_x != korzen_y) {
        rodzice[korzen_x] = korzen_y;
    }
}

Union_Find::Union_Find(int dana)
{
    rangi = new double[dana]();
    rodzice = new int[dana];
    for (int i = 0; i < dana; i++) {
        rodzice[i] = i;
    }
}

Graf::Graf(int a, int b, Krawedz* temp)
{
    liczba_wierzcholkow=a;
    liczba_krawedzi=b;
    krawedzie = temp;
}

string kruskal_z_kompresja_z_rangami(Graf* temp)
{
    string wypis;
    clock_t poczatek_1 = clock();
    sortowanie_kubelkowe(temp);
    clock_t koniec_1 = clock();
    clock_t czas_1 = koniec_1 - poczatek_1;
    Krawedz* wynik = new Krawedz[temp->liczba_wierzcholkow];
    int posortowane = 0;
    int sprawdzone_krawedzie = 0;
    Union_Find do_zmiany_nazwa(temp->liczba_wierzcholkow);
    clock_t poczatek_2=clock();

    while (posortowane < temp->liczba_wierzcholkow - 1) {

        Krawedz tymczasowa = temp->krawedzie[sprawdzone_krawedzie++];
        int x = do_zmiany_nazwa.find_z_kompresja_2(tymczasowa.index_x);
        int y = do_zmiany_nazwa.find_z_kompresja_2(tymczasowa.index_y);

        if (x != y) {
            wynik[posortowane++] = tymczasowa;
            do_zmiany_nazwa.union_by_rank_z_kompresja(x, y);
        }
    }
    clock_t koniec_2=clock();
    double droga=0;
    for (int i = 0; i < posortowane; i++) {
        droga += wynik[i].waga;
    }
    wypis= "Liczba krawedzi: " + to_string(temp->liczba_wierzcholkow - 1) + " Najkrotsza droga drzewa: " + to_string(droga) + " Krok sortujacy: " + to_string((double)(koniec_1 - poczatek_1) / CLOCKS_PER_SEC) + " Czas glownej petli: " + to_string((double)(koniec_2 - poczatek_2) / CLOCKS_PER_SEC) + " Liczba find: "+ to_string( liczba_z_kompresja_z_rangami) + " \n";
    return wypis;
}

string kruskal_bez_kompresji_z_rangami(Graf* temp)
{
    string wypis;
    clock_t poczatek_1 = clock();
    sortowanie_kubelkowe(temp);
    clock_t koniec_1 = clock();
    clock_t czas_1 = koniec_1 - poczatek_1;
    Krawedz* wynik = new Krawedz[temp->liczba_wierzcholkow];
    int posortowane = 0;
    int sprawdzone_krawedzie = 0;
    Union_Find do_zmiany_nazwa(temp->liczba_wierzcholkow);
    clock_t poczatek_2 = clock();

    while (posortowane < temp->liczba_wierzcholkow - 1 ) {

        Krawedz tymczasowa = temp->krawedzie[sprawdzone_krawedzie++];
        int x = do_zmiany_nazwa.find_bez_kompresji_2(tymczasowa.index_x);
        int y = do_zmiany_nazwa.find_bez_kompresji_2(tymczasowa.index_y);

        if (x != y) {
            wynik[posortowane++] = tymczasowa;
            do_zmiany_nazwa.union_by_rank_bez_kompresji(x, y);
        }
    }

    clock_t koniec_2 = clock();
    clock_t czas_2 = koniec_2 - poczatek_2;
    double droga = 0;
    for (int i = 0; i < posortowane; i++) {
        droga += wynik[i].waga;
    }
    wypis = "Liczba krawedzi: " + to_string(temp->liczba_wierzcholkow - 1) + " Najkrotsza droga drzewa: " + to_string(droga) + " Krok sortujacy: " + to_string((double)(koniec_1 - poczatek_1) / CLOCKS_PER_SEC) + " Czas glownej petli: " + to_string((double)(koniec_2 - poczatek_2) / CLOCKS_PER_SEC) + " Liczba find: " + to_string(liczba_bez_kompresji_z_rangami) + " \n";
    return wypis;
}

string kruskal_z_kompresja_bez_rang(Graf* temp)
{
    string wypis;
    clock_t poczatek_1 = clock();
    sortowanie_kubelkowe(temp);
    clock_t koniec_1 = clock();
    clock_t czas_1 = koniec_1 - poczatek_1;
    Krawedz* wynik = new Krawedz[temp->liczba_wierzcholkow];
    int posortowane = 0;
    int sprawdzone_krawedzie = 0;
    Union_Find do_zmiany_nazwa(temp->liczba_wierzcholkow);
    clock_t poczatek_2 = clock();

    while (posortowane < temp->liczba_wierzcholkow - 1 ) {

        Krawedz tymczasowa = temp->krawedzie[sprawdzone_krawedzie++];
        int x = do_zmiany_nazwa.find_z_kompresja(tymczasowa.index_x);
        int y = do_zmiany_nazwa.find_z_kompresja(tymczasowa.index_y);

        if (x != y) {
            wynik[posortowane++] = tymczasowa;
            do_zmiany_nazwa.zwykla_unia_z_kompresja(x,y);
        }
    }
    clock_t koniec_2 = clock();
    clock_t czas_2 = koniec_2 - poczatek_2;
    double droga = 0;
    for (int i = 0; i < posortowane; i++) {
        droga += wynik[i].waga;
    }
    wypis = "Liczba krawedzi: " + to_string(temp->liczba_wierzcholkow - 1) + " Najkrotsza droga drzewa: " + to_string(droga) + " Krok sortujacy: " + to_string((double)(koniec_1 - poczatek_1) / CLOCKS_PER_SEC) + " Czas glownej petli: " + to_string((double)(koniec_2 - poczatek_2) / CLOCKS_PER_SEC) + " Liczba find: " + to_string(liczba_z_kompresja_bez_rang) + " \n";
    return wypis;
}

string kruskal_bez_kompresji_bez_rang(Graf* temp)
{
    string wypis;
    clock_t poczatek_1 = clock();
    sortowanie_kubelkowe(temp);
    clock_t koniec_1 = clock();
    clock_t czas_1 = koniec_1 - poczatek_1;
    Krawedz* wynik = new Krawedz[temp->liczba_wierzcholkow];
    int posortowane = 0;
    int sprawdzone_krawedzie = 0;
    Union_Find do_zmiany_nazwa(temp->liczba_wierzcholkow);
    clock_t poczatek_2 = clock();

    while (posortowane < temp->liczba_wierzcholkow - 1 ) {

        Krawedz tymczasowa = temp->krawedzie[sprawdzone_krawedzie++];
        int x = do_zmiany_nazwa.find_bez_kompresji(tymczasowa.index_x);
        int y = do_zmiany_nazwa.find_bez_kompresji(tymczasowa.index_y);

        if (x != y) {
            wynik[posortowane++] = tymczasowa;
            do_zmiany_nazwa.zwykla_unia_bez_kompresji(x, y);
        }
    }
    clock_t koniec_2 = clock();
    clock_t czas_2 = koniec_2 - poczatek_2;
    double droga = 0;
    for (int i = 0; i < posortowane; i++) {
        droga += wynik[i].waga;
    }
    wypis = "Liczba krawedzi: " + to_string(temp->liczba_wierzcholkow - 1) + " Najkrotsza droga drzewa: " + to_string(droga) + " Krok sortujacy: " + to_string((double)(koniec_1 - poczatek_1) / CLOCKS_PER_SEC) + " Czas glownej petli: " + to_string((double)(koniec_2 - poczatek_2) / CLOCKS_PER_SEC) + " Liczba find: " + to_string(liczba_bez_kompresji_bez_rang) + " \n";
    return wypis;
}

template<typename T>
Obiekt<T>::Obiekt(T b)
{
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

template<typename T>
T* Lista<T>::dodaj_do_listy(T* tym)
{
    if (koniec != NULL) koniec->nastepny = tym;
    tym->nastepny = NULL;
    koniec = tym;
    if (poczatek == NULL) poczatek = koniec;
    rozmiar++;
    return koniec;
}
template<typename T>
void Lista<T>::sortowanie_listy()
{
    int zamiana;

    if (poczatek != NULL) {
        do {
            zamiana = 0;
            T* tymczasowy = poczatek;
            while (tymczasowy != NULL) {
                if (tymczasowy->nastepny != NULL) {
                    if (tymczasowy->dane.waga > tymczasowy->nastepny->dane.waga) {
                        swap(tymczasowy->dane, tymczasowy->nastepny->dane);
                        zamiana = 1;
                    }
                }
                tymczasowy = tymczasowy->nastepny;
            }
        } while (zamiana);
    }
}


void sortowanie_kubelkowe(Graf* tablica)
{
    int rozmiar = tablica->liczba_krawedzi;
    double min = tablica->krawedzie[0].waga;
    double m = tablica->krawedzie[0].waga;
    for (int i = 1; i < rozmiar; i++) {
        if (min > tablica->krawedzie[i].waga) {
            min = tablica->krawedzie[i].waga;
        }
    }
    for (int i = 1; i < rozmiar; i++) {
        if (m < tablica->krawedzie[i].waga) {
            m = tablica->krawedzie[i].waga;
        }
    }
    double kubelki = m - min + 1;
    Lista<Obiekt<Krawedz>>* lista_tablica = new Lista<Obiekt<Krawedz>>[rozmiar]();
    for (int i = 0; i < rozmiar; i++) {

        Obiekt<Krawedz>* tymczasowy_obiekt = new Obiekt<Krawedz>(tablica->krawedzie[i]);
        lista_tablica[int(tablica->krawedzie[i].waga / kubelki)].dodaj_do_listy(tymczasowy_obiekt);
    }
    lista_tablica;
    for (int i = 0; i < rozmiar; i++) {
        lista_tablica[i].sortowanie_listy();
    }
    int temp_index = 0;

    for (int i = 0; i < rozmiar; i++) {
        if (lista_tablica[i].poczatek != NULL) {
            Obiekt<Krawedz>* tymczasowy = lista_tablica[i].poczatek;
            while (tymczasowy != NULL) {
                tablica->krawedzie[temp_index++] = tymczasowy->dane;
                tymczasowy = tymczasowy->nastepny;
            }
        }
    }
}
