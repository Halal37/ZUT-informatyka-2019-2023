// SymulatorStudia.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//
#include "Dod_funk.h"
#include "Osoba.h"
#include "Marketing.h"
#include <iostream>
using namespace std;
int main()
{
    Osoba** cos;
    Osoba*** zonk;
    size_t ilosc = 0;
    size_t jakas_inna_w = 0;
    for(size_t i=0;i<10;i++){
    Nadaj_pamiec(cos, ilosc);
    Wypisz_narodowosc(cos, ilosc);}
   /* Nadaj_pamiec(cos, ilosc);
    Wypisz_narodowosc(cos, ilosc);
    Nadaj_pamiec(cos, ilosc);
    Wypisz_narodowosc(cos, ilosc);
    Wypisz_narodowosc(cos, ilosc);*/
   usun_wybranego(cos, ilosc, jakas_inna_w);
    Wypisz_narodowosc(cos, ilosc);


  /* Nadaj_pamiec(zonk, ilosc,jakas_inna_w);
  Wypisz_narodowosc(zonk, ilosc,jakas_inna_w);
    Nadaj_pamiec(zonk, ilosc, jakas_inna_w);
   Wypisz_narodowosc(zonk, &ilosc, &jakas_inna_w);
    Nadaj_pamiec(zonk, ilosc, jakas_inna_w);
    Wypisz_narodowosc(zonk, &ilosc, &jakas_inna_w);
    Nadaj_pamiec(zonk, ilosc, jakas_inna_w);
    Wypisz_narodowosc(zonk, &ilosc, &jakas_inna_w);*/



    Usun(cos, ilosc);
   // Usun(zonk, ilosc,jakas_inna_w);


    if (cos == nullptr)
      cout << "Pamiec zostala zwolniona prawidlowo !" <<endl;
 //     if (zonk == nullptr)
 //        cout << "Pamiec zostala zwolniona prawidlowo !" << endl;


    Marketing* ktos = new Marketing(34, 12);
    ktos->informacje_marketingowe();


    int dyn_ilosc = 1;

    int* tablica = new int[dyn_ilosc];

    for (int i = 0; i < 10; i++)
    {
        tablica[i] = i;

        tablica = Dynamiczna_tablica(tablica, dyn_ilosc);

        cout << "Powiekszenie o:  " << i << endl;

        for (int i = 0; i < dyn_ilosc -1; i++)
        {
           cout << tablica[i] << " " << endl;
        }
  
    }


    Menu();


    return 0;
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
