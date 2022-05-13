// ASK_5.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <conio.h>
int main()
{
    unsigned char a = 0x35;
    unsigned char y;
    unsigned char b=0x22;
    unsigned char c = b & 0xaa;
    unsigned char d = b & 0x55;
    c=c >> 1;
    d = d << 1;
    b = c | d;

//Zad2
 /*   a = a & 0x01;
    b = b & 0xfd;
   
    a=a << 1;
   
   b= b | a;*/
   // b = b | (a & 0x02);
//and &
 //   a & 0xbb;
 //   printf("%d\n", a);
//or | 0x44
    //xor ^ 0x44
    printf("%d\n", b);
    __asm {
        mov al,0x34
        mov b,0x11
   /*     mov a,al
        add a,0x02
        mov b, bl
        add b,0xfd
        or a,b
        mov output a*/


//Zad2
/*
mov a, al
and a, 0x01
mov b, bl
and b, 0xfd
shl a,1
or a,b
*/
//Zad3
mov bl,b
mov c, b
mov d, b
and c,0xaa
and d,0x55
shr c,1
shl d,1
or c,d
mov output c

 //       or al,0x44
 //      add al,0xbb
 //       xor al,0x44
        mov y,al
    }
    printf("%d\n", y);
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
