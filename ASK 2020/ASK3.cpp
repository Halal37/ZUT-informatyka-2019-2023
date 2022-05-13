// ASK3.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <conio.h>
using namespace std;
int main()
{
    unsigned char a = 0xA;
    unsigned char b = 0x5;
    unsigned char c = 0x8;
    unsigned char y;
    unsigned char n = 0xA;
    unsigned char u = 0x5;
    unsigned char p = 0x8;
    unsigned char x;
    x = a + u - p;
    printf("%x \n", x);
    x += n ;
    printf("%x \n", x);
    x = n << 1;
    printf("%x \n", x);
    x <<= 2 ;
    printf("%x \n", x);
    x >>= 1;
    printf("%x \n", x);
    
    __asm {
//Zad1
      /*  xor al, al
        mov al, a
        add al, b;
        sub al, c;
        mov y, al */

//Zad2
/*
//         mov al, a
//          add y, al*/

//Zad3
  /*     xor al, al
        mov al, a
        shl al, 0x01
        mov y, al*/
//Zad4
        xor al, al
//        mov al, y
        shl al, 0x02
        mov y, al
//Zad5
      //mov al, y
      //shr al, 0x01
     //mov y, al

    }
    printf("%x", y);
    getchar();
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
