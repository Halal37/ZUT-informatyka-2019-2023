//ALGO2 IS1 223A LAB07
//Wojciech Lidwin
//lw46577@zut.edu.pl

#include <iostream>
#include <time.h>
#include <string.h>
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
template<typename T>
class Lista2 {
public:
    T* poczatek;
    T* koniec;
    int rozmiar;
    Lista2();
    T* dodaj_do_listy(T* tym);
    void sortowanie_listy2();
};
template <typename T>
class Kopiec {
public:
    int size;
    int max_size;
    T* kopiec_dane;
    Kopiec<T>();
    void przekopcowanie_w_gore(int rozmiar, T dana);
    void przekopcowanie_w_dol(int rozmiar, T dana);
    void przekopcowanie_w_dol2(int i, int rozmiar);
    void dodaj_element(T* tablica, int rozmiar,bool gora_dol);
    void sort();
};
void sortowanie_kubelkowe(int* tablica, int rozmiar, int m);
template <typename T>
void sortowanie_kubelkowe2(T* tablica, int rozmiar, T m);
void sortowanie_przez_zliczanie(int* tablica, const int rozmiar, const int m);
int main()
{
    Kopiec<int>* kopiec = new Kopiec<int>();
    srand(time(NULL));
    int n;
    int m = 101;
    cout << "Podaj rozmiar tablicy" << endl;
    cin >> n;
    int* tablica1 = new int[n];
    int* tablica2 = new int[n];
    int* tablica3 = new int[n];
    char* tablica4 = new char[n];
    float* tablica5 = new float[n];
    for (int i = 0; i < n; i++) {
        tablica1[i]=rand() % m;
    }
    for (int i = 0; i < n; i++) {
        tablica4[i] = rand() % 26 + 97;
    }
    for (int i = 0; i < n; i++) {
        tablica5[i] =((float)rand()/float(RAND_MAX)) * 26;
    }
    memcpy(tablica2, tablica1, n * sizeof(int));
    memcpy(tablica3, tablica1, n * sizeof(int));
    clock_t t1 = clock();
    kopiec->dodaj_element(tablica1, n,true);
    kopiec->sort();
    clock_t t2 = clock();
    cout << "Czas sortowania: " << t2 - t1 << endl;
    cout<<"Kopcowanie" << endl;
    for (int i = 0; i < n; i++) {
            cout<<"Indeks: "<<i<<" " << kopiec->kopiec_dane[i] << endl;
    }
    t1 = clock();
    sortowanie_przez_zliczanie(tablica2, n, m);
    t2 = clock();
    cout << "Czas sortowania: " << t2 - t1 << endl;
    cout<<"Zliczanie " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Indeks: " << i << " " << tablica2[i] << endl;
    }
    t1 = clock();
    sortowanie_kubelkowe(tablica3, n, m);
    t2 = clock();
    cout << "Czas sortowania: " << t2 - t1 << endl;
    cout<<"Kubelek " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Indeks: " << i << " " << tablica3[i] << endl;
    }
    //2
    int cos = 26 + 97;
    char dana = cos;
    t1 = clock();
    sortowanie_kubelkowe2(tablica4, n, dana);
    t2 = clock();
    cout << "Czas sortowania: " << t2 - t1 << endl;
    cout << "Kubelek " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Indeks: " << i << " " << tablica4[i] << endl;
    }
    float t = 26;
    t1 = clock();
    sortowanie_kubelkowe2(tablica5, n, t);
    t2 = clock();
    cout << "Czas sortowania: " << t2 - t1 << endl;
    cout << "Kubelek " << endl;
    for (int i = 0; i < n; i++) {
        cout << "Indeks: " << i << " " << tablica5[i] << endl;
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



void sortowanie_kubelkowe(int* tablica, int rozmiar, int m)
{
    int min=tablica[0];
    for (int i = 1; i < rozmiar; i++) {
        if (min > tablica[i]) {
            min = tablica[i];
        }
    }
    int kubelki = m-min+1;
    Lista<Obiekt<int>>* lista_tablica = new Lista<Obiekt<int>>[rozmiar]();
    for (int i = 0; i < rozmiar; i++) {

        Obiekt<int >* tymczasowy_obiekt = new Obiekt<int>(tablica[i]);
        lista_tablica[tablica[i]/kubelki].dodaj_do_listy(tymczasowy_obiekt);
    }
    for (int i = 0; i < rozmiar; i++) {
        lista_tablica[i].sortowanie_listy();
    }
    int temp_index = 0;
    for (int i = 0; i < rozmiar; i++) {
        if (lista_tablica[i].poczatek != NULL) {
            Obiekt<int>* tymczasowy = lista_tablica[i].poczatek;
            while (tymczasowy != NULL) {
                tablica[temp_index++]=tymczasowy->dane;
                tymczasowy = tymczasowy->nastepny;
            }
        }
    }
}

template<typename T>
void Kopiec<T>::dodaj_element(T* tablica, int rozmiar, bool gora_dol)
{
    size = rozmiar;
    max_size = size * 2;
    delete kopiec_dane;
    kopiec_dane = new T[size];
    if (gora_dol == true) {
        for (int i = 0; i < size; i++) {
            przekopcowanie_w_gore(i, tablica[i]);
        }
    }
    else {
        for (int i = 0; i < size; i++) {
            przekopcowanie_w_dol(size - 1 - i, tablica[i]);
        }
    }
}
template<typename T>
void Kopiec<T>::sort()
{
    T* tablica = new T[size];
    int temp;
    for (int i = size - 1; i >= 0; i--) {
        temp = kopiec_dane[0];
       kopiec_dane[0]=kopiec_dane[i];
        kopiec_dane[i] = temp;
        przekopcowanie_w_dol2(0,i);
  }

}
template<typename T>
void Kopiec<T>::przekopcowanie_w_dol(int rozmiar, T dana)
{
    int temp;
    if (2 * rozmiar > size) {
        kopiec_dane[rozmiar] = dana;
    }
    else if (2 * rozmiar < size) {
        if (kopiec_dane[2 * rozmiar] > kopiec_dane[2 * rozmiar + 1]) {
            temp = 2 * rozmiar;
        }
        else {
            temp = 2 * rozmiar + 1;
        }
        if (kopiec_dane[temp] > dana) {
            kopiec_dane[rozmiar] = kopiec_dane[temp];
            przekopcowanie_w_dol(temp, dana);
        }
        else {
            kopiec_dane[rozmiar] = dana;
        }
    }
    else {
        if (kopiec_dane[2 * rozmiar] > dana) {
            kopiec_dane[rozmiar] = kopiec_dane[2 * rozmiar];
            kopiec_dane[2 * rozmiar] = dana;
        }
        else {
            kopiec_dane[rozmiar] = dana;
        }
    }
}

template<typename T>
void Kopiec<T>::przekopcowanie_w_dol2(int i, int rozmiar)
{
    int temp = i;
    int p = 2 * i + 2;
    int l = 2 * i + 1;
    if (p < rozmiar && kopiec_dane[p] > kopiec_dane[temp]) {
        temp = p;
    }
    if (l < rozmiar && kopiec_dane[l] > kopiec_dane[temp]) {
        temp = l;
    }
    if (temp != i) {
        swap(kopiec_dane[i], kopiec_dane[temp]);
        przekopcowanie_w_dol2(temp, rozmiar);
    }
}

template<typename T>
Kopiec<T>::Kopiec()
{
    size = 0;
    max_size = 1;
    T* temp = new T[max_size];
    delete[] kopiec_dane;
    kopiec_dane = temp;
}
template<typename T>
void Kopiec<T>::przekopcowanie_w_gore(int rozmiar, T dana)
{
    if (rozmiar == 0) {
        kopiec_dane[rozmiar] = dana;
    }
    else if (kopiec_dane[rozmiar / 2] > dana) {
        kopiec_dane[rozmiar] = dana;
    }
    else {
        kopiec_dane[rozmiar] = kopiec_dane[rozmiar / 2];
        przekopcowanie_w_gore(rozmiar / 2, dana);
    }
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
                    if (tymczasowy->dane > tymczasowy->nastepny->dane) {
                        swap(tymczasowy->dane, tymczasowy->nastepny->dane);
                        zamiana = 1;
                    }
                }
                tymczasowy = tymczasowy->nastepny;
            }
            } while (zamiana);
    }
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
Lista2<T>::Lista2()
{
    poczatek = NULL;
    koniec = NULL;
    rozmiar = 0;
}

template<typename T>
T* Lista2<T>::dodaj_do_listy(T* tym)
{
    if (koniec != NULL) koniec->nastepny = tym;
    tym->nastepny = NULL;
    koniec = tym;
    if (poczatek == NULL) poczatek = koniec;
    rozmiar++;
    return koniec;
}

template<typename T>
void Lista2<T>::sortowanie_listy2()
{
    int zamiana;

    if (poczatek != NULL) {
        do {
            zamiana = 0;
            T* tymczasowy = poczatek;
            while (tymczasowy != NULL) {
                if (tymczasowy->nastepny != NULL) {
                    if (tymczasowy->dane > tymczasowy->nastepny->dane) {
                        swap(tymczasowy->dane, tymczasowy->nastepny->dane);
                        zamiana = 1;
                    }
                }
                tymczasowy = tymczasowy->nastepny;
            }
        } while (zamiana);
    }
}

template<typename T>
void sortowanie_kubelkowe2(T* tablica, int rozmiar, T m)
{
    T min = tablica[0];
    for (int i = 1; i < rozmiar; i++) {
        if (min > tablica[i]) {
            min= tablica[i];
        }
    }
    T kubelki = m - min + 1;
    Lista2<Obiekt<T>>* lista_tablica = new Lista2<Obiekt<T>>[rozmiar]();
    for (int i = 0; i < rozmiar; i++) {

        Obiekt<T>* tymczasowy_obiekt = new Obiekt<T>(tablica[i]);
        lista_tablica[int(tablica[i] / kubelki)].dodaj_do_listy(tymczasowy_obiekt);
    }
    lista_tablica;
    for (int i = 0; i < rozmiar; i++) {
        lista_tablica[i].sortowanie_listy2();
    }
    int temp_index = 0;

    for (int i = 0; i < rozmiar; i++) {
        if (lista_tablica[i].poczatek != NULL) {
            Obiekt<T>* tymczasowy = lista_tablica[i].poczatek;
            while (tymczasowy != NULL) {
                tablica[temp_index++] = tymczasowy->dane;
                tymczasowy = tymczasowy->nastepny;
            }
        }
    }
}
void sortowanie_przez_zliczanie(int* tablica, const int rozmiar, const int m)
{

    int* do_zliczania = new int[m]();
    int* temp = new int[m]();
    for (int i = 0; i < rozmiar; i++) {
        do_zliczania[tablica[i]] = do_zliczania[tablica[i]] + 1;
    }
    for (int i = 1; i < m; i++) {
        do_zliczania[i] = do_zliczania[i] + do_zliczania[i - 1];
    }
    for (int i = rozmiar - 1; i >= 0; i--) {
        temp[do_zliczania[tablica[i]] - 1] = tablica[i];
        do_zliczania[tablica[i]]--;
    }
    for (int i = 0; i < rozmiar; i++) {
        tablica[i] = temp[i];
    }
}
