// ASK_10.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <conio.h>
typedef union {
    unsigned char BYTE;
    struct {
        unsigned char a : 2;
        unsigned char b : 3;
        unsigned char c : 3;
    }bits;
}un_X;
int main()
{

    un_X x, y, z;
    z.bits.a = y.bits.a = x.bits.a = 2;
    z.bits.b = y.bits.b = x.bits.b = 3;
    z.bits.c = y.bits.c = x.bits.c = 4;

    printf("%#4x\r\n", x.BYTE);
    printf("a= %d\r\n", x.bits.a);
    printf("b= %d\r\n", x.bits.b);
    printf("c= %d\r\n", x.bits.c);
    x.bits.c = x.bits.a+1;
    x.bits.b = x.bits.a;
    printf("%#4x\r\n", x.BYTE);
    printf("a= %d\r\n", x.bits.a);
    printf("b= %d\r\n", x.bits.b);
    printf("c= %d\r\n", x.bits.c);

    uint8_t a = ((y.BYTE & 0x03) >> 0)+1;
    y.BYTE &= 0x1f;
    y.BYTE |= (a << 5);

    uint8_t a2 = (y.BYTE & 0x03) >> 0;
    y.BYTE &= 0xe3;
    y.BYTE |= (a2 << 2);
    printf("%#4x\r\n", y.BYTE);
    printf("a= %d\r\n", y.bits.a);
    printf("b= %d\r\n", y.bits.b);
    printf("c= %d\r\n", y.bits.c);


/*
    unsigned short y = 0;
    unsigned short a = 1000;
    y = (a << 3) - (a << 0) - (a >> 2);
    printf("%d\n", y);
    y = 0;
    y = (a << 4) - (a<<2)-(a<<1)-(a>>1)-(a>>2);
    printf("%d\n", y);
    y = 0;
    */
    __asm {
        /*Zad1
        mov ax,a
        shl ax,3
        add y, ax

       mov ax,a
       shl ax,0
       add y,ax

       mov ax,a
       shr ax,2
       add y,ax
       */
       /*zad2
        mov ax, a
        shl ax, 4
        add y, ax
        mov ax, a
        shl ax, 2
        sub y, ax
        mov ax, a
        shl ax, 1
        sub y, ax
        mov ax, a
        shr ax, 1
        sub y, ax
        mov ax, a
        shr ax, 2
        sub y, ax
        */

        mov al, z.BYTE
        add al, 1
        and al, 0x03
        shr al, 0
        mov cl, z.BYTE
        and cl, 0x1f
        shl al, 5
        or cl, al
        // mov z.BYTE,cl
        mov al, z.BYTE
        and al, 0x03
        shr al,0
        and cl, 0xe3
        shl al,2
        or cl,al
        mov z.BYTE, cl
    }
  //  printf("%d\n", y);
    printf("%#4x\r\n", z.BYTE);
    printf("a= %d\r\n", z.bits.a);
    printf("b= %d\r\n", z.bits.b);
    printf("c= %d\r\n", z.bits.c);
}
/*
x.bits.c=x.bits.b
x.bits.b=x.bits.a
x.bits.c=x.bits.b+x.bits.a
*/
// Uruchomienie programu: Ctrl + F5 lub menu Debugowanie > Uruchom bez debugowania
// Debugowanie programu: F5 lub menu Debugowanie > Rozpocznij debugowanie

// Porady dotyczące rozpoczynania pracy:
//   1. Użyj okna Eksploratora rozwiązań, aby dodać pliki i zarządzać nimi
//   2. Użyj okna programu Team Explorer, aby nawiązać połączenie z kontrolą źródła
//   3. Użyj okna Dane wyjściowe, aby sprawdzić dane wyjściowe kompilacji i inne komunikaty
//   4. Użyj okna Lista błędów, aby zobaczyć błędy
//   5. Wybierz pozycję Projekt > Dodaj nowy element, aby utworzyć nowe pliki kodu, lub wybierz pozycję Projekt > Dodaj istniejący element, aby dodać istniejące pliku kodu do projektu
//   6. Aby w przyszłości ponownie otworzyć ten projekt, przejdź do pozycji Plik > Otwórz > Projekt i wybierz plik sln
