// ASK_11.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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
    /*cccbbbaa
    x.bits.c=x.bits.b;
    x.bits.b=x.bits.a*/
    z.bits.a = y.bits.a = x.bits.a = 2;//10
    z.bits.b = y.bits.b = x.bits.b = 3;//011
    z.bits.c = y.bits.c = x.bits.c = 4;//100
    printf("%#4x\r\n", x.BYTE);
    printf("a= %d\r\n", x.bits.a);
    printf("b= %d\r\n", x.bits.b);
    printf("c= %d\r\n", x.bits.c);
   /* x.bits.c = x.bits.b;
    x.bits.b = x.bits.a;
    printf("%#4x\r\n", x.BYTE);
    printf("a= %d\r\n", x.bits.a);
    printf("b= %d\r\n", x.bits.b);
    printf("c= %d\r\n", x.bits.c);
    uint8_t a = ((y.BYTE & 0x1c) >> 0);
    y.BYTE &= 0x1f;
    y.BYTE |= (a << 3);
    uint8_t a2 = (y.BYTE & 0x03) >> 0;
    y.BYTE &= 0xe3;
    y.BYTE |= (a2 << 2);
    printf("%#4x\r\n", y.BYTE);
    printf("a= %d\r\n", y.bits.a);
    printf("b= %d\r\n", y.bits.b);
    printf("c= %d\r\n", y.bits.c);*/
    //x.bits.c=x.bits.b+x.bits.a;
    uint8_t a2 = ((y.BYTE & 0x03) >> 0);
    uint8_t a = ((y.BYTE & 0x1c) >> 0);
    
    y.BYTE |= (a << 2);
   // y.BYTE &= 0xe3;
    //a=a;
    a = a + a2;
    y.BYTE |= (a << 5);
    y.BYTE &= 0x1f;
    printf("%#4x\r\n", y.BYTE);
    printf("a= %d\r\n", y.bits.a);
    printf("b= %d\r\n", y.bits.b);
    printf("c= %d\r\n", y.bits.c);

    __asm {
        //zad1
            mov al, z.BYTE
            and al, 0x1c;
            mov cl, z.BYTE
            and cl, 0x1f
            shl al, 3
            or cl, al
            mov al, z.BYTE
            and al, 0x03
            shr al, 0
            and cl, 0xe3
            shl al, 2
            or cl, al
            mov z.BYTE, cl
            

    }
    printf("%#4x\r\n", z.BYTE);
    printf("a= %d\r\n", z.bits.a);
    printf("b= %d\r\n", z.bits.b);
    printf("c= %d\r\n", z.bits.c);
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
