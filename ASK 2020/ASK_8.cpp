// ASK_8.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <conio.h>
using namespace std;

int main()
{  
	unsigned char a = 0x12;
    unsigned char b = 0x48;
    unsigned char wynik;
	unsigned long y = 0x00;
	unsigned char a_1 = 0x00;
    unsigned char b_1 = 0x00;
	unsigned char counter = 0;
   /* for (int i = 0; i < 8; i++) {
        a_1<<=1;
        a_1|=a&1;
        a >>= 1;
    }*/
  //  if (b & 0x01)
   /*     b_1 = (b & 0x01) << 7 |
        (b & 0x02) << 5 |
        (b & 0x04) << 3 |
        (b & 0x08) << 1 |
        (b & 0x08) >> 1 |
        (b & 0x20) >> 5 |
        (b & 0x40) >> 3 |
        (b & 0x80) >> 7;
    printf("%d\n", a_1);
    printf("%d\n", b_1);*/
    __asm {
 //       xor eax, eax
  //      mov al,a_1
        mov bh,0

        mov bl,b
        and bl,0x01
        shl bl,7
        or bh,bl
        mov bl, b
        and bl, 0x02
        shl bl, 5
        or bh, bl
        mov bl, b
        and bl, 0x04
        shl bl, 3
        or bh, bl
        mov bl, b
        and bl, 0x08
        shl bl, 1
        or bh, bl
        mov bl, b
        and bl, 0x10
        shr bl, 1
        or bh, bl
        mov bl, b
        and bl, 0x20
        shr bl, 3
        or bh, bl
        mov bl, b
        and bl, 0x40
        shr bl, 5
        or bh, bl
        mov bl, b
        and bl, 0x80
        shr bl, 7
        or bh, bl
        mov wynik,bh

    }
    printf("%#x", wynik);
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
