//ALGO2 IS1 223A LAB03
//Wojciech Lidwin
//lw46577@zut.edu.pl

#include <iostream>
#include <time.h>
#include<string>
using namespace std;
template<typename T>
class Obiekt;
template<typename T>
class Lista;

template <typename T>
class Drzewo {
public:
    int indeks;
    Drzewo* p;
    Drzewo* l;
    Drzewo* r;
    T dane;
    Drzewo();
    Drzewo(T nowa_wartosc);
    Drzewo(T nowa_wartosc, int wr_indeks);


    template<typename T>  friend int dodaj_do_drzewa(Drzewo<T>* korzen, Drzewo<T>* tym);
    template <typename T> friend Drzewo<T>* wyszukaj(Drzewo<T>* korzen, Drzewo<T>* tym);
    template <typename T> friend void usun(Drzewo<T>* korzen, Drzewo<T>* tym);
    template <typename T> friend void usuwanie(Drzewo<T>* korzen);
    template<typename T> friend void wyszukanie_pre_order(Drzewo<T>* korzen, Lista<Obiekt<Drzewo<int>>>* tym);
    template<typename T> friend void wyszukanie_in_order(Drzewo<T>* korzen, Lista<Obiekt<Drzewo<int>>>* tym);
    template<typename T> friend int wysokosc(Drzewo<T>* korzen);
};
template<typename T>
class Obiekt {
public:
    Obiekt* next;
    T zmienna_a;

};
template<typename T>
class Lista {
public:
    Obiekt<Drzewo<int>>* poczatek;
    Obiekt<Drzewo<int>>* koniec;
    int rozmiar;
    Lista();
    Obiekt<Drzewo<int>>* dodaj(Obiekt<Drzewo<int>>* tym);
    string pokaz(int wysokosc, int ilosc);
};
template <typename T>
int dodaj_do_drzewa(Drzewo<T>* korzen, Drzewo<T>* tym);
template <typename T>
Drzewo<T>* wyszukaj(Drzewo<T>* korzen, Drzewo<T>* tym);
template <typename T>
void usun(Drzewo<T>* korzen, Drzewo<T>* tym);
template <typename T>
void usuwanie(Drzewo<T>* korzen);
template<typename T>
void wyszukanie_pre_order(Drzewo<T>* korzen, Lista<Obiekt<Drzewo<int>>>* tym);
template<typename T>
void wyszukanie_in_order(Drzewo<T>* korzen, Lista<Obiekt<Drzewo<int>>>* tym);
template<typename T>
int wysokosc(Drzewo<T>* korzen);
/*
template <typename T>
int komparator(Drzewo<T>* tym, Drzewo<T>* temp) {
    if (tym->dane < temp->dane) {
        return 0;
    }
    else if (tym->dane > temp->dane) {
        return 1;
    }
    else {
        return 2;
    }

}
template<typename T>
int dodaj_do_drzewa(Drzewo<T>* korzen, Drzewo<T>* tym, int(*f)(Drzewo<T>*, Drzewo<T>*));*/
/*
template <typename T>
bool operator <(const Drzewo<T>& temp, const Drzewo<T>& tym) {
    if (temp.dane < tym.dane) {
        return true;
    }
    return false;
}
template <typename T>
int operator >(const Drzewo<T>& temp, const Drzewo<T>& tym) {
    if (temp.dane > tym.dane) {
        return true;
    }
    return false;
}*/
int main()
{
    string do_pokazania;
    Lista<Obiekt<Drzewo<int>>> lista;
    Lista<Obiekt<Drzewo<int>>> lista_2;
  //  Obiekt<Drzewo<int>>* obiekt;

    srand(time(NULL));
    int inty;
    int indeks = 0;
    inty = rand() % 100 + 1;
    clock_t t1 = clock();
   Drzewo<int>* dab = new Drzewo<int>(inty, indeks);
   indeks += 1;
    for (int i = 1; i < 10000000; i++) {
        inty = rand() % 1000000000 + 1;
        Drzewo<int>* nowy = new Drzewo<int>(inty, indeks);
        indeks = dodaj_do_drzewa(dab, nowy);
    }
    clock_t t2 = clock();
    wyszukanie_pre_order(dab,&lista);
    int high = wysokosc(dab);
    do_pokazania= lista.pokaz(high,indeks);
    cout << do_pokazania << endl;
    cout << "Czas dodawania punktow: " << t2 - t1 << endl;

    int ilosc_trafien = 0;
    t1 = clock();
    for (int i = 0; i < 10000; i++) {
        inty = rand() % 10000 + 1;
        Drzewo<int>* nowy = new Drzewo<int>(inty);
        Drzewo<int>* trafienie = wyszukaj(dab, nowy);
        if (trafienie != NULL) {
            ilosc_trafien++;
        }
        delete nowy;
    }
    t2 = clock();
    cout << "Ilosc trafien: " << ilosc_trafien << endl;
    cout << "Czas szukania trafien: " << t2 - t1 << endl;
    usuwanie(dab);
    delete dab;
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
Drzewo<T>::Drzewo()
{
    indeks=0;
    p=NULL;
    l=NULL;
    r=NULL;
    dane = NULL;
}

template<typename T>
Drzewo<T>::Drzewo(T nowa_wartosc)
{
    indeks = 99;
    p = NULL;
    l = NULL;
    r = NULL;
    dane = nowa_wartosc;
}

template<typename T>
Drzewo<T>::Drzewo(T nowa_wartosc,int wr_indeks)
{
    indeks = wr_indeks;
    p = NULL;
    l = NULL;
    r = NULL;
    dane = nowa_wartosc;
}

template<typename T>
int dodaj_do_drzewa(Drzewo<T>* korzen, Drzewo<T>* tym)
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
            return tym->indeks;
        }
    }
        tym->p = nowy;
        if (nowy == NULL) {
            korzen = tym;
        }
        else if (nowy->dane < tym->dane) {
            nowy->r = tym;
        }
        else {
            nowy->l = tym;
        }
        return tym->indeks+1;

}
/*
template<typename T>
int dodaj_do_drzewa(Drzewo<T>* korzen, Drzewo<T>* tym,int(*f)(Drzewo<T>*, Drzewo<T>*))
{
    Drzewo<T>* temp = korzen;
    Drzewo<T>* nowy = NULL;
    while (temp != NULL) {
        nowy = temp;
        if (f(tym,temp)=0) {
            temp = temp->l;
        }
        else if (f(tym, temp) = 1) {
            temp = temp->r;
        }
        else {
            return tym->indeks;
        }
    }
    tym->p = nowy;
    if (nowy == NULL) {
        korzen = tym;
    }
    else if (f(nowy,tym)=0) {
        nowy->r = tym;
    }
    else {
        nowy->l = tym;
    }
    return tym->indeks + 1;

}*/
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
    temp=wyszukaj(korzen, tym);
    if ((temp->l == NULL) && (temp->r == NULL)) {
         if (temp->p == NULL) {
             temp->dane=NULL;
          }
         else{
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
            while (temp->l!=NULL) {
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
void wyszukanie_pre_order(Drzewo<T>* korzen,Lista<Obiekt<Drzewo<int>>>*tym)
{
    Lista<Obiekt<Drzewo<int>>> lista;
    Obiekt<Drzewo<int>>* obiekt;
    obiekt = new Obiekt<Drzewo<int>>;
    if (korzen != NULL) {
        obiekt->zmienna_a = *korzen;
        tym->dodaj(obiekt);
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
        wyszukanie_pre_order(korzen->l,tym);
        obiekt->zmienna_a = *korzen;
        tym->dodaj(obiekt);
        wyszukanie_pre_order(korzen->r,tym);
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
            return pomocnicza_2+1;
        }
        else {
            return pomocnicza_1+1;

        }

    }

}

template<typename T>
void usuwanie(Drzewo<T>* korzen)
{
    while (korzen->dane != NULL) {
        usun(korzen, korzen);

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
Obiekt<Drzewo<int>>* Lista<T>::dodaj(Obiekt<Drzewo<int>>* tym)
{
    if (koniec !=NULL) koniec->next = tym;
    tym->next = NULL;
    koniec = tym;
    if (poczatek==NULL) poczatek = koniec;
    rozmiar++;
    return koniec;
}

template<typename T>
string Lista<T>::pokaz(int wysokosc,int ilosc)
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
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + "NULL" + ", l: " + "NULL" + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                    }
                    else if (tym->zmienna_a.r == NULL) {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + "NULL" + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                    }
                    else if (tym->zmienna_a.l == NULL) {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + "NULL" + ", l: " + "NULL" + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';

                    }
                    else {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + "NULL" + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                    }

                }
                else {
                    if ((tym->zmienna_a.r == NULL) && (tym->zmienna_a.l == NULL)) {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + "NULL" + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                    }
                    else if (tym->zmienna_a.r == NULL) {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                    }
                    else if (tym->zmienna_a.l == NULL) {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + "NULL" + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';

                    }
                    else {
                        dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                    }

                }
                tym = tym->next;

        }
    }else{
    if (poczatek == NULL) {
        dane_do_wypisania = dane_do_wypisania + "puste" + '\n';
    }
    else {
        tym = poczatek;
        while (tym) {
            if (tym->zmienna_a.p == NULL) {
                if ((tym->zmienna_a.r == NULL) && (tym->zmienna_a.l == NULL)) {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + "NULL" + ", l: " + "NULL" + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                }
                else if (tym->zmienna_a.r == NULL) {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + "NULL" + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                }
                else if (tym->zmienna_a.l == NULL) {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + "NULL" + ", l: " + "NULL" + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';

                }
                else {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + "NULL" + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                }

            }
            else {
                if ((tym->zmienna_a.r == NULL) && (tym->zmienna_a.l == NULL)) {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + "NULL" + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                }
                else if (tym->zmienna_a.r == NULL) {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + "NULL" + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                }
                else if (tym->zmienna_a.l == NULL) {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + "NULL" + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';

                }
                else {
                    dane_do_wypisania = dane_do_wypisania + "(" + to_string(tym->zmienna_a.indeks) + ":  " + "[p: " + to_string(tym->zmienna_a.p->indeks) + ", l: " + to_string(tym->zmienna_a.l->indeks) + ", r: " + to_string(tym->zmienna_a.r->indeks) + "], dane: " + to_string(tym->zmienna_a.dane) + ")," + '\n';
                }

            }
            tym = tym->next;
        }
    }

        }
    return dane_do_wypisania;
    }

//   cout <<"("<<tym->zmienna_a.indeks<<":  "<<"[p: "<< tym->zmienna_a.p->indeks<<", l: "<<tym->zmienna_a.l->indeks<<", r: "<<tym->zmienna_a.r->indeks<<"], dane: "<<tym->zmienna_a.dane<<")," <<endl;
