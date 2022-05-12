//ALGO2 IS1 223A LAB04
//Wojciech Lidwin
//lw46577@zut.edu.pl

#include <iostream>
#include <time.h>
#include <string>
using namespace std;
int indeks = 0;
template <typename T>
class Drzewo {
public:
    int indeks;
    Drzewo* p;
    Drzewo* l;
    Drzewo* r;
    T dane;
    bool kolor;
    Drzewo();
    Drzewo(T nowa_wartosc);
    Drzewo(T nowa_wartosc, int wr_indeks);
};
template<typename T>
class Obiekt {
public:
    Obiekt* netymt;
    T zmienna_a;

};
template<typename T>
class Lista {
public:
    Obiekt<Drzewo<int>>* poczatek;
    Obiekt<Drzewo<int>>* koniec;
    int rozmiar;
    Lista();
    Obiekt<Drzewo<int>>* poprawnosc_RBT(Obiekt<Drzewo<int>>* tym);
    string pokaz(int wysokosc, int ilosc);
};
template<typename T>
void wyszukanie_pre_order(Drzewo<T>* korzen, Lista<Obiekt<Drzewo<int>>>* tym);
template<typename T>
void wyszukanie_in_order(Drzewo<T>* korzen, Lista<Obiekt<Drzewo<int>>>* tym);
template<typename T>
Drzewo<T>* wyszukaj(Drzewo<T>* korzen, Drzewo<T>* tym);
template<typename T>
void usun(Drzewo<T>* korzen, Drzewo<T>* tym);
template<typename T>
int usuwanie(Drzewo<T>* korzen);
template<typename T>
int wysokosc(Drzewo<T>* korzen);
template <typename T>
int tworz(Drzewo<T>* &korzen, int i);
template <typename T>
int umiesc(Drzewo<T>* korzen, Drzewo<T>* tym);
template <typename T>
bool kolor(Drzewo<T>* tym) {
    if (tym == NULL) {
        return false;
    }
    else if (tym->kolor == false) {
        return false;
    }
    else {
        return true;
    }
}

string kolor_str(bool tym) {
  if (tym == false) {
        return "BLACK";
    }
    else {
        return "RED";
    }
}

template <typename T>
int poprawnosc_RBT(Drzewo<T>* &korzen, Drzewo<T>* &tym);
int main()
{
    srand(time(NULL));
    Lista<Obiekt<Drzewo<int>>> lista;
    string do_pokazania;
    int inty;
    inty = rand() % 100 + 1;
    clock_t t1 = clock();
    Drzewo<int>* dab = new Drzewo<int>(0, 0);
    dab->kolor = false;
    indeks += 1;
    for (int i = 1; i < 10; i++) {
        inty = rand() % 100+ 1;
         tworz(dab, inty);
    }
    clock_t t2 = clock();
    wyszukanie_pre_order(dab, &lista);
    int high = wysokosc(dab);
    do_pokazania = lista.pokaz(high, indeks);
    cout << do_pokazania << endl;
    cout << "Czas dodawania punktow: " << t2 - t1 << endl;

    int trafienia = 0;
    t1 = clock();
    for (int i = 1; i < 100; i++) {
        inty = rand() % 100 + 1;
        Drzewo<int>* nowy = new Drzewo<int>(inty);
        Drzewo<int>* traf=wyszukaj(dab, nowy);
        if (traf != NULL) {
            trafienia++;
        }
        delete nowy;
    }
    t2 = clock();
    cout << "Ilosc trafien: " << trafienia << endl;
    cout << "Czas szukania trafien: " << t2 - t1 << endl;
    usuwanie(dab);
    delete dab;
    indeks = 0;
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Etymplorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > poprawnosc_RBT nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > poprawnosc_RBT istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln

template<typename T>
Drzewo<T>::Drzewo()
{
    indeks = 0;
    p = NULL;
    l = NULL;
    r = NULL;
    dane = NULL;
    kolor = true;
}
template<typename T>
Drzewo<T>::Drzewo(T nowa_wartosc)
{
    indeks = 99;
    p = NULL;
    l = NULL;
    r = NULL;
    dane = nowa_wartosc;
    kolor = true;
}

template<typename T>
Drzewo<T>::Drzewo(T nowa_wartosc, int wr_indeks)
{
    indeks = wr_indeks;
    p = NULL;
    l = NULL;
    r = NULL;
    dane = nowa_wartosc;
    kolor = true;
}
template <typename T>
int tworz(Drzewo<T>* &korzen, int i) {
    int sprawdzacz = 0;
    int sprawdzacz_2 = 0;
    Drzewo<int>* nowy = new Drzewo<int>(i, indeks);
    sprawdzacz=umiesc(korzen, nowy);
    if (sprawdzacz == 0) {
        return 0;
    }
    sprawdzacz_2=poprawnosc_RBT(korzen,nowy);
    if (sprawdzacz_2 == 1) {
        return 1;
    }
    else { return 0; }
}
template <typename T>
int umiesc(Drzewo<T>* korzen, Drzewo<T>* tym) {
    Drzewo<T>* temp = korzen;
    Drzewo<T>* nowy = NULL;
    while (temp != NULL) {
        nowy = temp;
        if (tym->dane < temp->dane) {
            temp = temp->l;
        }
        else if (tym->dane > temp->dane) {
            temp = temp->r;
        }
        else {
            return 0;
        }
    }
    tym->p = nowy;
    if (nowy == NULL) {
        korzen = tym;
        indeks++;
    }
    else if (nowy->dane < tym->dane) {
        nowy->r = tym;
        indeks++;
    }
    else {
        nowy->l = tym;
        indeks++;
    }
    return 1;
}
template <typename T>
int poprawnosc_RBT(Drzewo<T>*& korzen, Drzewo<T>*& tym) {
    Drzewo<T>* temp_p = NULL;
    Drzewo<T>* temp_p_p = NULL;
    Drzewo<T>* y = NULL;
    bool zmiana=false;
    while ((tym != korzen) && (tym->kolor != false) && (tym->p->kolor == true)) {
        temp_p = tym->p;
        temp_p_p = tym->p->p;
        if (temp_p == temp_p_p->l) {
             y = temp_p_p->r;
            if (kolor(y) == true) {
                y->kolor = false;
                temp_p->kolor = false;
                temp_p_p->kolor = true;
                tym = temp_p_p;
            }
            else {
                if (tym == temp_p->r) {
                    rotacja_w_lewo(korzen, temp_p);
                    tym = temp_p;
                    temp_p = tym->p;
                }
                rotacja_w_prawo(korzen, temp_p_p);
                zmiana = temp_p->kolor;
                temp_p->kolor = temp_p_p->kolor;
                temp_p_p->kolor = zmiana;
                tym = temp_p;
            }

        }
        else {
            y = temp_p_p->l;
            if (temp_p_p == korzen) {

            }
            if (kolor(y)== true) {
                y->kolor = false;
                temp_p->kolor = false;
                temp_p_p->kolor = true;
                tym = temp_p_p;
            }
            else {
                if (tym == temp_p->l) {
                    rotacja_w_prawo(korzen, temp_p);
                    tym = temp_p;
                    temp_p = tym->p;
                }
                rotacja_w_lewo(korzen, temp_p_p);
                zmiana = temp_p->kolor;
                temp_p->kolor = temp_p_p->kolor;
                temp_p_p->kolor = zmiana;
                tym = temp_p;
            }
        }
    }
    korzen->kolor = false;
    return 1;
}

template <typename T>
void rotacja_w_lewo(Drzewo<T>* &korzen,Drzewo<T>* &tym){

    Drzewo<T>* temp = tym->r;
    tym->r = temp->l;
    if (tym->r != NULL) {
        tym->r->p = tym;
    }
    temp->p = tym->p;
    if (tym->p == NULL) {
        korzen = temp;
    }
    else if (tym == tym->p->l) {
        tym->p->l = temp;
    }
    else {
        tym->p->r = temp;
    }
    temp->l = tym;
    tym->p = temp;
}



template <typename T>
void rotacja_w_prawo(Drzewo<T>* &korzen, Drzewo<T>* &tym){

    Drzewo<T>* temp = tym->l;
    tym->l = temp->r;
    if (tym->l != NULL) {
        tym->l->p = tym;
    }
    temp->p = tym->p;
    if (tym->p == NULL) {
        korzen = temp;
    }
    else if (tym == tym->p->l) {
        tym->p->l = temp;
    }
    else {
        tym->p->r = temp;
    }
    temp->r = tym;
    tym->p = temp;
}
template<typename T>
void wyszukanie_pre_order(Drzewo<T>* korzen, Lista<Obiekt<Drzewo<int>>>* tym)
{
    Lista<Obiekt<Drzewo<int>>> lista;
    Obiekt<Drzewo<int>>* obiekt;
    obiekt = new Obiekt<Drzewo<int>>;
    if (korzen != NULL) {
        obiekt->zmienna_a = *korzen;
        tym->poprawnosc_RBT(obiekt);
        wyszukanie_pre_order(korzen->l, tym);
        wyszukanie_pre_order(korzen->r, tym);
    }
}
template<typename T>
void wyszukanie_in_order(Drzewo<T>* korzen, Lista<Obiekt<Drzewo<int>>>* tym)
{
    Lista<Obiekt<Drzewo<int>>> lista;
    Obiekt<Drzewo<int>>* obiekt;
    obiekt = new Obiekt<Drzewo<int>>;
    if (korzen != NULL) {
        wyszukanie_pre_order(korzen->l, tym);
        obiekt->zmienna_a = *korzen;
        tym->poprawnosc_RBT(obiekt);
        wyszukanie_pre_order(korzen->r, tym);
    }
}

template<typename T>
int wysokosc(Drzewo<T>* korzen)
{
    int pomocnicza_1 = 0;
    int pomocnicza_2 = 0;
    int rozmiar = 1;
    if (korzen == NULL) {
        return -1;
    }
    else {
        pomocnicza_1 = wysokosc(korzen->r);
        pomocnicza_2 = wysokosc(korzen->l);
        if (pomocnicza_1 < pomocnicza_2) {
            return pomocnicza_2 + 1;
        }
        else {
            return pomocnicza_1 + 1;

        }

    }

}
template<typename T>
Lista<T>::Lista()
{
    poczatek = NULL;
    koniec = NULL;
    rozmiar = 0;
}
template<typename T>
Obiekt<Drzewo<int>>* Lista<T>::poprawnosc_RBT(Obiekt<Drzewo<int>>* tym)
{
    if (koniec != NULL) koniec->netymt = tym;
    tym->netymt = NULL;
    koniec = tym;
    if (poczatek == NULL) poczatek = koniec;
    rozmiar++;
    return koniec;
}
template<typename T>
string Lista<T>::pokaz(int wysokosc, int ilosc)
{
    string dane_do_wypisania;
    dane_do_wypisania = " " + '\n';
    dane_do_wypisania += "wysokosc: " + to_string(wysokosc) + '\n';
    dane_do_wypisania += "ilosc: " + to_string(ilosc) + '\n';
    Obiekt<Drzewo<int>>* tym;
    if (ilosc > 100) {
        tym = poczatek;
        for (int i = 0; i < 100; i++) {
            if (tym->zmienna_a.p == NULL) {
                if ((tym->zmienna_a.r == NULL) && (tym->zmienna_a.l == NULL)) {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + "NULL" + ", l: " + "NULL" + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                }
                else if (tym->zmienna_a.r == NULL) {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + "NULL" + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                }
                else if (tym->zmienna_a.l == NULL) {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + "NULL" + ", l: " + "NULL" + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';

                }
                else {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + "NULL" + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                }

            }
            else {
                if ((tym->zmienna_a.r == NULL) && (tym->zmienna_a.l == NULL)) {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + "NULL" + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                }
                else if (tym->zmienna_a.r == NULL) {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                }
                else if (tym->zmienna_a.l == NULL) {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + "NULL" + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';

                }
                else {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                }

            }
            tym = tym->netymt;

        }
    }
    else {
        if (poczatek == NULL) {
            dane_do_wypisania = dane_do_wypisania + "puste" + '\n';
        }
        else {
            tym = poczatek;
            while (tym) {
                if (tym->zmienna_a.p == NULL) {
                    if ((tym->zmienna_a.r == NULL) && (tym->zmienna_a.l == NULL)) {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ "+kolor_str(tym->zmienna_a.kolor)+" p: " + "NULL" + ", l: " + "NULL" + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                    }
                    else if (tym->zmienna_a.r == NULL) {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + "NULL" + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                    }
                    else if (tym->zmienna_a.l == NULL) {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + "NULL" + ", l: " + "NULL" + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';

                    }
                    else {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + "NULL" + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                    }

                }
                else {
                    if ((tym->zmienna_a.r == NULL) && (tym->zmienna_a.l == NULL)) {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + "NULL" + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                    }
                    else if (tym->zmienna_a.r == NULL) {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                    }
                    else if (tym->zmienna_a.l == NULL) {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + "NULL" + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';

                    }
                    else {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[ " + kolor_str(tym->zmienna_a.kolor)+" p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                    }

                }
                tym = tym->netymt;
            }
        }

    }
    return dane_do_wypisania;
}
template<typename T>
Drzewo<T>* wyszukaj(Drzewo<T>* korzen, Drzewo<T>* tym)
{
    Drzewo<T>* temp = korzen;
    Drzewo<T>* nowy = NULL;
    while (temp != NULL) {
        nowy = temp;
        if (tym->dane < temp->dane) {
            temp = temp->l;
        }
        else if (tym->dane > temp->dane) {
            temp = temp->r;
        }
        else {
            return nowy;
        }
    }
    return NULL;


}

template<typename T>
void usun(Drzewo<T>* korzen, Drzewo<T>* tym)
{
    Drzewo<T>* temp = NULL;
    Drzewo<T>* do_zmian = NULL;
    temp = wyszukaj(korzen, tym);
    if ((temp->l == NULL) && (temp->r == NULL)) {
        if (temp->p == NULL) {
            temp->dane = NULL;
        }
        else {
            if (temp->p->l == temp) {
                temp->p->l = NULL;
                delete temp;
            }
            else {
                temp->p->r = NULL;
                delete temp;
            }
        }
    }
    else if ((temp->l == NULL) != (temp->r == NULL))
    {
        int i = 0;
        do_zmian = temp;
        if (temp->l != NULL) {
            temp = temp->l;

            do_zmian->dane = temp->dane;
            do_zmian->indeks = temp->indeks;
            do_zmian->l = temp->l;
            do_zmian->r = temp->r;
            if (temp->l != NULL) {
                temp->l->p = do_zmian;

            }
            if (temp->r != NULL) {
                temp->r->p = do_zmian;
            }

        }
        else {
            temp = temp->r;

            do_zmian->dane = temp->dane;
            do_zmian->indeks = temp->indeks;
            do_zmian->l = temp->l;
            do_zmian->r = temp->r;
            if (temp->l != NULL) {
                temp->l->p = do_zmian;

            }
            if (temp->r != NULL) {
                temp->r->p = do_zmian;
            }

        }
        delete temp;
    }
    else {
        int i = 0;
        do_zmian = temp;
        temp = temp->r;
        while (temp->l != NULL) {
            temp = temp->l;
            i += 1;
        }

        do_zmian->dane = temp->dane;
        do_zmian->indeks = temp->indeks;
        if (i == 0) {
            if (temp->r != NULL) {
                temp->p->r = temp->r;
                temp->r->p = temp->p;

            }
            else {
                temp->p->r = NULL;
            }
        }
        else {
            if (temp->r != NULL) {
                temp->p->l = temp->r;
                temp->r->p = temp->p;

            }
            else {
                temp->p->l = NULL;
            }

        }
        delete temp;
    }

}
template<typename T>
int usuwanie(Drzewo<T>* korzen)
{
    while (korzen->dane != NULL) {
        usun(korzen, korzen);

    }
    return 1;
}
