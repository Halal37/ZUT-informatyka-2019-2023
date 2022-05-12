// ALGO2 IS1 46577 LAB02
// Wojciech Lidwin
// lw46577@zut.edu.pl

#include <iostream>
#include <time.h>
#include <string>
using namespace std;
template <typename T>
class Tablica_dyn {
public:
 int size;
 int max_size;
 T* tablica_dane;
 Tablica_dyn<T>();
 void zwieksz_size();
 void zwieksz_max();
 void dodawanie_elementu(T* tym);
 T* zwroc_i(int element);
 T*  podmiana_i(int element, T* tym);
 void czyszczenie();
string zwroc_napis();
void sortowanie();


};
template <typename T,typename T2>
class Object {
public:
    T zmienna_a;
    T2 zmienna_b;
    Object(T a, T2 b);
    Object();
    int operator <(const Object<T, T2> &tym) {
        if (zmienna_a < tym.zmienna_a) {
            return 1;
        }
        return 0;
    }
    int operator >(const Object<T, T2>& tym) {
        if (zmienna_a > tym.zmienna_a) {
            return 1;
        }
        return 0;
    }
};
int main()
{
    srand(time(NULL));
    int inty ;
    int chary;
    char cha;
    Tablica_dyn<Object<int, char>>* tablica = new Tablica_dyn<Object<int, char>>();
   Object<int, char>* wartosc_obiektu = new Object<int, char>();
   clock_t t1 = clock();
   double max_time_per_element = 0.0;
    for (int i = 0; i < 10000000; i++) {
        inty = rand() % 100 + 1;
        chary = rand() % 26 + 97;
        cha = chary;
        wartosc_obiektu = new Object<int, char>(inty, cha);
        clock_t t1_element = clock();
        tablica->dodawanie_elementu(wartosc_obiektu);
        clock_t t2_element = clock();
        double time_per_element = t2_element - t1_element;
        if (time_per_element > max_time_per_element) {
            cout << "Taki indeks: " << i << endl;
            max_time_per_element = time_per_element;
        }

    }
    clock_t t2 = clock();
    cout << "Czas wykonania programu: " << t2 - t1 << endl;
    cout << "Czas zamortyzowany: " << max_time_per_element << endl;
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
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

template<typename T, typename T2>
Object<T, T2>::Object(T a, T2 b)
{
    zmienna_a = a;
    zmienna_b = b;
}

template<typename T, typename T2>
Object<T, T2>::Object()
{
    zmienna_a = NULL;
    zmienna_b = NULL;
}

template<typename T>
Tablica_dyn<T>::Tablica_dyn()
{
    size = 0;
    max_size = 1;
   T* temp = new T[max_size];
    delete[] tablica_dane;
    tablica_dane = temp;

}

template<typename T>
void Tablica_dyn<T>::zwieksz_size()
{
    size = size + 1;
}

template<typename T>
void Tablica_dyn<T>::zwieksz_max()
{
    max_size = max_size * 2;
}

template<typename T>
void Tablica_dyn<T>::dodawanie_elementu(T* tym)
{
    if (size < max_size) {

        tablica_dane[size]=*tym;
        zwieksz_size();
    }
    else {
        zwieksz_max();
        T* temp = new T[max_size];
            for (int i = 0; i < size; i++) {
                temp[i] = tablica_dane[i];
            }

        delete[] tablica_dane;
        tablica_dane = temp;
        tablica_dane[size] = *tym;
        zwieksz_size();
    }

}

template<typename T>
T* Tablica_dyn<T>::zwroc_i(int element)
{
    if (element <= size) {
        return &tablica_dane[element - 1];
    }
    else {
        return NULL;
    }
}

template<typename T>
T* Tablica_dyn<T>::podmiana_i(int element, T* tym)
{
    if (zwroc_i(element) != NULL) {
        tablica_dane[element - 1] = *tym;
        return &tablica_dane[element - 1];
    }
    else {
        return NULL;
    }
}

template<typename T>
void Tablica_dyn<T>::czyszczenie()
{
        delete[] tablica_dane;
    size = 0;
    max_size = 1;

}

template<typename T>
string Tablica_dyn<T>::zwroc_napis()
{
    string a;
    string b;
    string rozmiar;
    string adres;
    string wypisz=""+'\n';
    string b_cha;
    string pusta = "Pusta tablica";
    wypisz="Rozmiar: "+to_string(size) + '\n'+"Maksymalny rozmiar: "+to_string(max_size) + '\n';
    for (int i = 0; i < size; i++) {
        if (i<10 || i>size - 11) {
            rozmiar ="Taki element tablicy "+ to_string(i + 1)+'\n';
            a="Zmienna a: "+to_string(tablica_dane[i].zmienna_a) + '\n';
           b_cha = tablica_dane[i].zmienna_b;
            b = "Zmienna b: " + b_cha + '\n';
            wypisz =wypisz+ rozmiar + a + b;
        }
    }

    if (size == 0) {
        return pusta;
    }
    else {
        return wypisz;
    }

}

template<typename T>
void Tablica_dyn<T>::sortowanie()
{
    T temp;
    for (int i = 0; i < size-1; i++) {
        for(int j = 0; j < size - 1; j++) {
            if (tablica_dane[j] > tablica_dane[j+1])
            {
                temp = tablica_dane[j];
                tablica_dane[j] = tablica_dane[j+1];
                tablica_dane[j+1] = temp;
            }
        }
}
}



