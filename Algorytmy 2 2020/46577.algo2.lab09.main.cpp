//ALGO2 IS1 223A LAB09
//Wojciech Lidwin
//lw46577@zut.edu.pl


#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
using namespace std;
class Punkt {
public:
    double x;
    double y;
    int indeks;
    Punkt();
    Punkt(double jeden, double dwa);
};
template<typename T>
struct Object {
    T punkt;
    Object* poprzedni;
    Object* nastepny;
    Object();
    Object(Punkt temp);
};
template <typename T>
class Lista {
public:
    T* pierwszy;
    T* ostatni;
    int rozmiar;
    Lista<T>();
    void dodaj_do_listy(T* tym);
    void usun_z_listy();
    void usun_z_listy_pierwszy();
    void set_rozmiar();
};
double dystans(Punkt a, Punkt b);
void sortowanie(Punkt* tablica, int n, Punkt poczatkowy);
int pozycja(Punkt do_porownania, Punkt a, Punkt b);
string graham(Punkt* punkt, int liczba_punktow);
int main()
{
    ifstream odczyt("points1.txt");
    if (odczyt.is_open()) {
        char liczba[10];
        odczyt.getline(liczba, 10);
        int zmienna = stoi(liczba);
        Punkt* punkt = new Punkt[zmienna];
        for (int i = 0; i < zmienna; i++) {
            odczyt >> punkt[i].x >> punkt[i].y;
            punkt[i].indeks = i;
        }
        string wynik= graham(punkt, zmienna);
        cout << wynik;
    }

    ifstream odczyt2("points2.txt");
    if (odczyt2.is_open()) {
        char liczba[10];
        odczyt2.getline(liczba, 10);
        int zmienna = stoi(liczba);
        Punkt* punkt = new Punkt[zmienna];
        for (int i = 0; i < zmienna; i++) {
            odczyt2 >> punkt[i].x >> punkt[i].y;
            punkt[i].indeks = i;
        }
        string wynik=graham(punkt, zmienna);
        cout << wynik;
    }

    ifstream odczyt3("points3.txt");
    if (odczyt3.is_open()) {
        char liczba[10];
        odczyt3.getline(liczba, 10);
        int zmienna = stoi(liczba);
        Punkt* punkt = new Punkt[zmienna];
        for (int i = 0; i < zmienna; i++) {
            odczyt3 >> punkt[i].x >> punkt[i].y;
            punkt[i].indeks = i;
        }
        string wynik=graham(punkt, zmienna);
        cout << wynik;
    }

    ifstream odczyt4("points4.txt");
    if (odczyt4.is_open()) {
        char liczba[10];
        odczyt4.getline(liczba, 10);
        int zmienna = stoi(liczba);
        Punkt* punkt = new Punkt[zmienna];
        for (int i = 0; i < zmienna; i++) {
            odczyt4 >> punkt[i].x >> punkt[i].y;
            punkt[i].indeks = i;
        }
        string wynik=graham(punkt, zmienna);
        cout << wynik;
    }

    ifstream odczyt5("points5.txt");
    if (odczyt5.is_open()) {
        char liczba[10];
        odczyt5.getline(liczba, 10);
        int zmienna = stoi(liczba);
        Punkt* punkt = new Punkt[zmienna];
        for (int i = 0; i < zmienna; i++) {
            odczyt5 >> punkt[i].x >> punkt[i].y;
            punkt[i].indeks = i;
        }
        string wynik=graham(punkt, zmienna);
        cout << wynik;
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

Punkt::Punkt()
{
    x = 0;
    y = 0;
    indeks = 0;
}
Punkt::Punkt(double jeden, double dwa)
{
    indeks = 0;
    x = jeden;
    y = dwa;
}


double dystans(Punkt a, Punkt b)
{
    return (a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y);
}

void sortowanie(Punkt* tablica, int n,Punkt poczatkowy)
{
    int zmiana=0;
    int polozenie = 0;
    for (int i = 0; i < n - 1; i++){
        zmiana = 0;
        for (int j = 1; j < n - i - 1; j++) {
            polozenie = pozycja(poczatkowy, tablica[j], tablica[j + 1]);
            if (polozenie == 0) {
                if (dystans(poczatkowy, tablica[j + 1]) < dystans(poczatkowy, tablica[j])) {
                    Punkt tymczasowy = tablica[j];
                    tablica[j] = tablica[j + 1];
                    tablica[j + 1] = tymczasowy;
                    zmiana = 1;
                }

            }else if (polozenie == 1) {
                Punkt tymczasowy = tablica[j];
                tablica[j] = tablica[j+1];
                tablica[j + 1] = tymczasowy;
                zmiana = 1;

            }
        }
        if (zmiana == 0) {
            break;
        }
    }
}

int pozycja(Punkt do_porownania, Punkt a, Punkt b)
{
    double wartosc = (a.y - do_porownania.y) * (b.x - do_porownania.x) - (a.x - do_porownania.x) * (b.y - do_porownania.y);
    if (wartosc < 0) { 
        return 2; 
    }
    else if(wartosc>0) {
        return 1;
    }
    else {
        return 0;
    }
    
}

string graham(Punkt* punkt, int liczba_punktow)
{
    int najmniejszy_punkt = 0; 
    double min = punkt[0].y;
    Punkt temp;
    for (int i = 1; i < liczba_punktow; i++) {
        if ((punkt[i].y < min) || (punkt[i].y == min && punkt[najmniejszy_punkt].x > punkt[i].x)) {
            najmniejszy_punkt = i;
            min = punkt[i].y;
        }
    }
    temp = punkt[najmniejszy_punkt];
    punkt[najmniejszy_punkt] = punkt[0];
    punkt[0] = temp;
    clock_t t1 = clock();
    sortowanie(punkt, liczba_punktow, punkt[0]);
    clock_t t2 = clock();
    clock_t czas_1 = t2 - t1;
    Punkt* powloka = new Punkt[liczba_punktow];
    powloka[0] = punkt[0];
    int liczba_punktow_powloki=1;

    for (int i = 1; i < liczba_punktow; i++) {
        while (i < liczba_punktow - 1 && pozycja(punkt[0], punkt[i], punkt[i + 1]) == 0) {
            i++;
        }
        powloka[liczba_punktow_powloki] = punkt[i];
        liczba_punktow_powloki++;
    }
    Lista<Object<Punkt>> graham_lista;
    Object<Punkt>** tablica_powloki = new Object<Punkt>*[liczba_punktow_powloki];
    if (liczba_punktow > 1) {
        for (int i = 0; i < liczba_punktow; i++) {
            tablica_powloki[i] = new Object<Punkt>(powloka[i]);
        }
   
    graham_lista.dodaj_do_listy(tablica_powloki[0]);
    graham_lista.dodaj_do_listy(tablica_powloki[1]);
    }
    t1 = clock();

    for (int i = 2; i < liczba_punktow; i++) {

        while (pozycja(graham_lista.ostatni->poprzedni->punkt, graham_lista.ostatni->punkt, powloka[i]) != 2) {
            graham_lista.usun_z_listy();
        }
        graham_lista.dodaj_do_listy(tablica_powloki[i]);
    }
    t2 = clock();
    clock_t czas_2 = t2 - t1;
    int k = 0;
    string wynik;
    clock_t suma_czasow = czas_2 + czas_1;
    Object<Punkt>* tymczasowy = graham_lista.pierwszy;
    while (tymczasowy != NULL) {
        wynik = wynik + "Indeks: " + to_string(tymczasowy->punkt.indeks) + "\n";
        k++;
        tymczasowy = tymczasowy->nastepny;
    }
    wynik =wynik+"Liczba punktow w powloce "+to_string(k)+" Czas sortowania: " + to_string((double)czas_1 / CLOCKS_PER_SEC) +" Czas glownej petli: "+ to_string((double)czas_2 / CLOCKS_PER_SEC) +" Laczny czas: "+ to_string((double)(suma_czasow) / CLOCKS_PER_SEC) + "\n";
    return wynik;
}

template<typename T>
Object<T>::Object()
{
    punkt = T();
    nastepny = NULL;
    poprzedni = NULL;
}

template<typename T>
Object<T>::Object(Punkt temp)
{
    punkt = temp;
    nastepny = NULL;
    poprzedni = NULL;
}

template<typename T>
void Lista<T>::dodaj_do_listy(T* tym)
{
    if (rozmiar == NULL) {
        pierwszy = tym;
        ostatni = tym;
    }
    else {
        tym->poprzedni = ostatni;
        tym->nastepny = NULL;
        ostatni->nastepny = tym;
        ostatni = tym;


    }
    set_rozmiar();
}

template<typename T>
void Lista<T>::usun_z_listy()
{
    T* temp;
    temp = new T;
    if (rozmiar == 0) {
    }
    else if (rozmiar == 1) {
        pierwszy = NULL;
        ostatni = NULL;
        rozmiar = rozmiar - 1;
    }
    else {
        temp = ostatni->poprzedni;
        delete ostatni;
        ostatni = temp;
        ostatni->nastepny = NULL;
        rozmiar = rozmiar - 1;

    }
}

template<typename T>
void Lista<T>::usun_z_listy_pierwszy()
{
    T* temp;
    temp = new T;
    if (rozmiar == 0) {
    }
    else if (rozmiar == 1) {
        pierwszy = NULL;
        ostatni = NULL;
        rozmiar = rozmiar - 1;
    }
    else {
        temp = pierwszy->nastepny;
        delete pierwszy;
        pierwszy = temp;
        pierwszy->poprzedni = NULL;
        rozmiar = rozmiar - 1;

    }
}

template<typename T>
void Lista<T>::set_rozmiar()
{
    rozmiar = rozmiar + 1;
}

template<typename T>
Lista<T>::Lista()
{
    pierwszy = new T();
    ostatni = new T();
    rozmiar = 0;
}
