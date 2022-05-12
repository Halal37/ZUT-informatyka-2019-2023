//ALGO2 IS1 223A LAB06
//Wojciech Lidwin
//lw46577@zut.edu.pl

#include <iostream>
#include <time.h>
#include <string>
using namespace std;
template <typename T>
class Kopiec {
public:
    int size;
    int max_size;
    T* kopiec_dane;
    Kopiec<T>();
    int zwieksz_size();
    int zwieksz_max();
    int zmniejsz_size();
    void przekopcowanie_w_gore(int rozmiar, T dana);
    void przekopcowanie_w_dol(int rozmiar, T dana);
    T dodaj_element(T dana);
    T usun_korzen();
    void usun_wszystkie();
    string pokaz();
};
int main()
{
    srand(time(NULL));
    int inty;
    Kopiec<int>* kopiec = new Kopiec<int>();
    clock_t t1 = clock();
    for (int i = 0; i < 40; i++) {
        inty= rand() % 100 + 1;
        kopiec->dodaj_element(inty);
    }
    clock_t t2 = clock();
    cout << "Czas dodawania do kopca: " << t2 - t1 << endl;
    cout << kopiec->pokaz();
    t1 = clock();
    cout << endl;
    for (int i = 0; i < 30; i++) {
        int dana = kopiec->usun_korzen();
        if (dana != 0) {
            cout << "Maksymalny: " << dana << endl;
        }
    }
    t2 = clock();
    cout << "Czas usuwania korzenia: " << t2 - t1 << endl;
    cout << kopiec->pokaz();
    kopiec->usun_wszystkie();
    delete kopiec;

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

template<typename T>
int Kopiec<T>::zwieksz_size()
{
    size = size + 1;
    return size;
}

template<typename T>
int Kopiec<T>::zwieksz_max()
{
    max_size = max_size * 2;
    return max_size;
}
template<typename T>
int Kopiec<T>::zmniejsz_size()
{
    size = size - 1;
    return size;
}
template<typename T>
void Kopiec<T>::przekopcowanie_w_gore(int rozmiar, T dana)
{
    if (rozmiar == 0) {
        kopiec_dane[rozmiar] = dana;
    }
    else if(kopiec_dane[rozmiar/2]>dana){
        kopiec_dane[rozmiar] = dana;
    }
    else {
        kopiec_dane[rozmiar] = kopiec_dane[rozmiar / 2];
        przekopcowanie_w_gore(rozmiar / 2, dana);
    }
}
template<typename T>
void Kopiec<T>::przekopcowanie_w_dol(int rozmiar, T dana)
{
    int temp;
    if (2*rozmiar > size) {
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
T Kopiec<T>::dodaj_element(T dana)
{
    if (size < max_size) {
        przekopcowanie_w_gore(size, dana);
            zwieksz_size();
            return dana;
    }
    else {
        zwieksz_max();
        T* temp = new T[max_size];
        for (int i = 0; i < size; i++) {
            temp[i] = kopiec_dane[i];
        }

        delete[] kopiec_dane;
        kopiec_dane = temp;
        przekopcowanie_w_gore(size, dana);
        zwieksz_size();
        return dana;

    }
    return NULL;
}
template<typename T>
T Kopiec<T>::usun_korzen()
{
    if (size != 0) {
        kopiec_dane[0] = kopiec_dane[size - 1];
        kopiec_dane[size - 1] = NULL;
        kopiec_dane[size + 1];
        przekopcowanie_w_dol(0, kopiec_dane[0]);
        zmniejsz_size();
        return kopiec_dane[0];
    }
    else {
        return NULL;

    }
}
template<typename T>
void Kopiec<T>::usun_wszystkie()
{
    delete[] kopiec_dane;
    size = 0;
    max_size = 1;
}
template<typename T>
string Kopiec<T>::pokaz()
{
    string napis = "";
    if(size<11){
    for (int i = 0; i < size; i++) {
        napis=napis+"Dane na indeskie "+to_string(i)+" "+ to_string(kopiec_dane[i]) + '\n';
    }
}
else {
    for (int i = 0; i < 11; i++) {
        napis = napis + "Dane na indeskie " + to_string(i) + " " + to_string(kopiec_dane[i]) + '\n';
    }
}
return napis;
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
