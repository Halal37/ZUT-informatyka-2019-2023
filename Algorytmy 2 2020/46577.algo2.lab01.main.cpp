//ALGO2 IS1 223A LAB01
//Wojciech Lidwin
//lw46577@zut.edu.pl
// Algorytmy_Lista<Object>.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <time.h>
#include <string>
#include <charconv>
using namespace std;
template<typename T, typename T2>
struct Object {
    T zmienna_a;
    T2 zmienna_b;
    Object* poprzedni;
    Object* nastepny;
    Object();
    Object(int a,char b);
};
template <typename T>
class Lista {
    public:
    T* pierwszy;
    T* ostatni;
    int rozmiar;
    Lista<T>();
   void funkcja_b(Object<int, char>* tym);
   void funkcja_a(Object<int, char>* tym);
   void funkcja_c();
   void funkcja_d();
   void funkcja_e(int wartosc);
   void funkcja_f(int wartosc, Object<int, char>* tym);
   Object<int, char>* funkcja_g(Object<int, char>* tym);
   bool funkcja_h(Object<int, char>* tym);
   void funkcja_i( Object<int, char>* tym, Object<int, char>* zmiana);
   void funkcja_j();
   void funkcja_k();
  void set_rozmiar();
};



void funkcja_wyswietl2(Lista<Object<int, char>>* tymczasowy) {
    Object<int, char>* temp;
    temp = new Object<int, char>;
    temp = tymczasowy->pierwszy;

    for (int i = 0; i < tymczasowy->rozmiar; i++) {
                cout << "Jest taki jest "<<i+1<<" element: " << endl;
                cout << "Zmienna a: " << temp->zmienna_a << endl;
                cout << "Zmienna b: " << temp->zmienna_b << endl;

        temp = temp->nastepny;
    }
};


void menu() {
    cout << "Co chcesz zrobic?" << endl;
    cout << "1. Dodac nowy element na poczatek list" << endl;
    cout << "2. Dodac nowy element na koniec listy" << endl;
    cout << "3. Usunac ostatni element" << endl;
    cout << "4. Usunac pierwszy element" << endl;
    cout << "5. Zwrocenie danych podanego elementu listy" << endl;
    cout << "6. Podmiana danych podanego elementu listy" << endl;
    cout << "7. Wyszukanie elementu" << endl;
    cout << "8. Wyszukanie i usuniecie elementu" << endl;
    cout << "9. Dodanie nowego elementu z wymuszeniem porzadku" << endl;
    cout << "10. Czyszczenie listy" << endl;
    cout << "11. Zwrocenie napisowej reprezentacji listy" << endl;
    cout << "Inne zakoncz program" << endl;

}

int main()
{
    srand(time(NULL));
    int do_sprawdzenia = 0;
    int do_indeksow;
    int inty;
    int chary;
    char ch;
    int inty_2;
    int chary_2;
    char ch_2;
    double czas;
    clock_t time_1, time_2;
    Lista<Object<int, char>>* lista = new Lista<Object<int, char>>();
    Object<int, char>* wartosc_obiektu = new Object<int, char>();
    Object<int, char>* wartosc_zamiennika = new Object<int, char>();

    time_1 = clock();
    for (int i = 0; i < 100; i++) {
        inty = rand() % 100 + 1;
        chary = rand() % 26+97;
        ch = chary;
        wartosc_obiektu = new Object<int, char>(inty, ch);
        lista->funkcja_b(wartosc_obiektu);
    }
    time_2 = clock();
    czas = double(time_2-time_1) / (double)CLOCKS_PER_SEC;
    cout <<"Tyle minelo czasu "<< time_1 << endl;
    cout << "Tyle minelo czasu " << time_2 << endl;
    cout << "Tyle minelo czasu " << czas << endl;

    lista->funkcja_k();
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;

   for (int i = 0; i < 900; i++) {
       time_1 = clock();
       inty = rand() % 100 + 1;
       chary = rand() % 26 + 97;
       ch = chary;
       wartosc_obiektu = new Object<int, char>(inty, ch);
       lista->funkcja_h(wartosc_obiektu);
       delete wartosc_obiektu;
   }
   time_2 = clock();
   czas = double(time_2 - time_1) / (double)CLOCKS_PER_SEC;
   cout << "Tyle minelo czasu " << time_1 << endl;
   cout << "Tyle minelo czasu " << time_2 << endl;
   cout << "Tyle minelo czasu " << czas << endl;
   lista->funkcja_k();
   cout << endl;
   cout << endl;
   cout << endl;
   cout << endl;
   lista->funkcja_j();

   do {
       menu();
       int x;
       cin >> x;
       switch (x) {
       case 1:
           inty = rand() % 100 + 1;
           chary = rand() % 26 + 97;
           ch = chary;
           wartosc_obiektu = new Object<int, char>(inty, ch);
           lista->funkcja_a(wartosc_obiektu);
           break;
       case 2:
           inty = rand() % 100 + 1;
           chary = rand() % 26 + 97;
           ch = chary;
           wartosc_obiektu = new Object<int, char>(inty, ch);
           lista->funkcja_b(wartosc_obiektu);
          break;
       case 3:
           lista->funkcja_c();
           break;
       case 4:
           lista->funkcja_d();
          break;
       case 5:
           cout << "Podaj nr indeksu ktory chcesz wyszukac " << endl;
           cin >> do_indeksow;
           lista->funkcja_e(inty);
          break;
       case 6:
           cout << "Podaj nr indeksu ktory chcesz zamienic " << endl;
           cin >> do_indeksow;
           inty = rand() % 100 + 1;
           chary = rand() % 26 + 97;
           ch = chary;
           wartosc_obiektu = new Object<int, char>(inty, ch);
           lista->funkcja_f(do_indeksow, wartosc_obiektu);
           break;
       case 7:
           inty = rand() % 100 + 1;
           chary = rand() % 26 + 97;
           ch = chary;
           wartosc_obiektu = new Object<int, char>(inty, ch);
           lista->funkcja_g(wartosc_obiektu);
           break;
       case 8:
           inty = rand() % 100 + 1;
           chary = rand() % 26 + 97;
           ch = chary;
           wartosc_obiektu = new Object<int, char>(inty, ch);
           lista->funkcja_h(wartosc_obiektu);
           break;
       case 9:
           inty = rand() % 100 + 1;
           chary = rand() % 26 + 97;
           ch = chary;
           wartosc_obiektu = new Object<int, char>(inty, ch);
           inty_2 = rand() % 100 + 1;
           chary_2 = rand() % 26 + 97;
           ch_2 = chary_2;
           wartosc_zamiennika = new Object<int, char>(inty_2, ch_2);
           lista->funkcja_i(wartosc_obiektu, wartosc_zamiennika);
           break;
       case 10:
           lista->funkcja_j();
           break;
       case 11:
           lista->funkcja_k();
          break;
       default:
           delete lista;
           do_sprawdzenia = 1;
           break;
       }
   } while (do_sprawdzenia == 0);
}

// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista<Object> błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln







template<typename T>
void Lista<T>::funkcja_b(Object<int, char>* tym)
{
    if (rozmiar == NULL) {
        pierwszy = tym;
        ostatni = tym;
    }
    else {
        tym->nastepny = pierwszy;
        tym->poprzedni = NULL;
        pierwszy->poprzedni = tym;
        pierwszy = tym;

    }
    set_rozmiar();
}

template<typename T>
void Lista<T>::funkcja_a(Object<int, char>* tym)
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
void Lista<T>::funkcja_c()
{
    Object<int, char>* temp;
    temp = new Object<int, char>;
    if (rozmiar == 0) {
        cout << "Nie mozna usunac cos co nie istnieje. Byt jest niebytu nie ma." << endl;
    }
    else if (rozmiar == 1) {
        cout << "Lista<Object> zostala usunieta " << endl;
         pierwszy=NULL;
         ostatni=NULL;
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
void Lista<T>::funkcja_d()
{
    Object<int, char>* temp;
    temp = new Object<int, char>;
    if (rozmiar == 0) {
        cout << "Nie mozna usunac cos co nie istnieje. Byt jest niebytu nie ma." << endl;
    }
    else if (rozmiar == 1) {
        cout << "Lista<Object> zostala usunieta " << endl;
        pierwszy=NULL;
        ostatni=NULL;
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
void Lista<T>::funkcja_e(int wartosc)
{
    Object<int, char>* temp;
    temp = new Object<int, char>;
    if(wartosc<rozmiar){
    if (wartosc < rozmiar / 2) {
        temp = pierwszy;
        for (int i = 1; i < wartosc; i++) {
            temp = temp->nastepny;
        }
        cout << " Twoj szukany int: "<< temp->zmienna_a << endl;
        cout << " Twoj szukany char: "<< temp->zmienna_b << endl;
    }
    else {
        temp = ostatni;
        for (int i = 0; i < rozmiar - wartosc; i++) {
            temp = temp->poprzedni;
        }
        cout << "Twoj szukany int: " << temp->zmienna_a << endl;
        cout << "Twoj szukany char: " << temp->zmienna_b << endl;
    }
}
else {
cout << "Wartosc poza indeksem " << endl;
}
}

template<typename T>
void Lista<T>::funkcja_f(int wartosc,Object<int,char> *tym)
{
    Object<int, char>* temp;
    temp = new Object<int, char>;
    if (wartosc < rozmiar) {
        if (wartosc < rozmiar / 2) {
            temp = pierwszy;
            for (int i = 1; i < wartosc; i++) {
                temp = temp->nastepny;
            }
            temp->zmienna_a = tym->zmienna_a;
            temp->zmienna_b= tym->zmienna_b;
        }
        else {
            temp = ostatni;
            for (int i = 0; i < rozmiar - wartosc; i++) {
                temp = temp->poprzedni;
            }
            temp->zmienna_a = tym->zmienna_a;
            temp->zmienna_b = tym->zmienna_b;
        }
    }
    else {
        cout << "Wartosc poza indeksem " << endl;
    }
}

template<typename T>
Object<int,char>* Lista<T>::funkcja_g(Object<int, char>* tym)
{
    Object<int, char>* temp;
    temp = new Object<int, char>;
    temp = pierwszy;
    for (int i = 0; i < rozmiar; i++) {
        if (temp->zmienna_a == tym->zmienna_a) {
            if (temp->zmienna_b == tym->zmienna_b) {
                cout << "Jest taki szukany element " << endl;
                cout << "Zmienna a: " << temp->zmienna_a << endl;
                cout << "Zmienna b: " << temp->zmienna_b << endl;
                return temp;
  //              break;
            }
        }
        temp = temp->nastepny;
    }
    return NULL;
}

template<typename T>
bool Lista<T>::funkcja_h(Object<int, char>* tym)
{

        Object<int, char>* temp;
        temp = new Object<int, char>;
       temp = funkcja_g(tym);
      if (temp != NULL) {

          if ((temp==pierwszy|| temp==ostatni)) {
              if (temp==pierwszy){
                  Object<int, char>* tym;
                  tym = new Object<int, char>;
                   if (rozmiar == 1) {
                      cout << "Lista<Object> zostala usunieta " << endl;
                      pierwszy = NULL;
                      ostatni = NULL;

                  }
                  else {
                      tym = pierwszy->nastepny;
                      delete pierwszy;
                      pierwszy = tym;
                      pierwszy->poprzedni = NULL;


                  }
              }
              else {
                  Object<int, char>* tym;
                  tym = new Object<int, char>;
                  if (rozmiar == 1) {
                      cout << "Lista<Object> zostala usunieta " << endl;
                      pierwszy = NULL;
                      ostatni = NULL;

                  }
                  else {
                      tym = ostatni->poprzedni;
                      delete ostatni;
                      ostatni = tym;
                      ostatni->nastepny = NULL;


                  }

              }
          }
          else {
              temp->nastepny->poprzedni = temp->poprzedni;
              temp->poprzedni->nastepny = temp->nastepny;
          }
        rozmiar = rozmiar - 1;

        return true;
    }
    return false;
}

template<typename T>
void Lista<T>::funkcja_i(Object<int, char>* tym, Object<int, char>* zmiana)
{
    Object<int, char>* temp;
    temp = new Object<int, char>;
    temp = funkcja_g(tym);
    if (temp != NULL) {

        if (ostatni == temp) {
            zmiana->poprzedni = ostatni;
            zmiana->nastepny = NULL;
            ostatni->nastepny = zmiana;
            ostatni = zmiana;
            set_rozmiar();

        }
        else {
            temp->nastepny->poprzedni = zmiana;
            zmiana->nastepny = temp->nastepny;
            zmiana->poprzedni = temp;
            temp->nastepny = zmiana;
            set_rozmiar();

        }
    }


}

template<typename T>
void Lista<T>::funkcja_j()
{
    Object<int, char>* temp, * tym;
    temp = new Object<int, char>;
    tym = new Object<int, char>;
    int i = 0;
    while(rozmiar>2){
        temp = pierwszy->nastepny;
        delete pierwszy;
        pierwszy = temp;
        pierwszy->poprzedni = NULL;
        tym = ostatni->poprzedni;
        delete ostatni;
        ostatni = tym;
        ostatni->nastepny = NULL;
        rozmiar = rozmiar - 2;

    }
    if (rozmiar == 2) {
        temp = ostatni->poprzedni;
        delete ostatni;
        ostatni = temp;
        ostatni->nastepny = NULL;
        rozmiar = rozmiar - 1;

    }
    if (rozmiar == 1) {
        ostatni = NULL;
        pierwszy = NULL;
        rozmiar = rozmiar - 1;
        cout << "Lista<Object> zostala usunieta " << endl;
    }

}

template<typename T>
void Lista<T>::funkcja_k()
{
    Object<int, char>* temp;
    temp = new Object<int, char>;
    temp = pierwszy;
    string a;
    string z;
    string roz = "Rozmiar listy to  " + to_string(rozmiar);
    cout << roz << endl;
    cout << endl;
    for (int i = 0; i < rozmiar; i++) {
        if (i<10 || i>rozmiar - 10) {
            z = to_string(i + 1);
            cout <<"Taki adres: "<< temp<<endl;
            cout << "Jest to jest " << z << " element: " << endl;
            a = to_string(temp->zmienna_a);
            cout << "Zmienna a: " << a << endl;
            cout << "Zmienna b: " << temp->zmienna_b << endl;
        }

        temp = temp->nastepny;
    }
}


template<typename T>
void Lista<T>::set_rozmiar()
{
    rozmiar = rozmiar + 1;
}


template<typename T, typename T2>
Object<T, T2>::Object()
{
    zmienna_a = NULL;
    zmienna_b = NULL;
    nastepny = NULL;
    poprzedni = NULL;
}
template<typename T, typename T2>
Object<T, T2>::Object(int a, char b)
{
    zmienna_a = a;
    zmienna_b = b;
    nastepny = NULL;
    poprzedni = NULL;
}

template<typename T>
Lista<T>::Lista()
{
    pierwszy = new T();
    ostatni = new T();
    rozmiar = 0;
}
