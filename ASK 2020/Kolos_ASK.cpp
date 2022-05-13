// Kolos_ASK.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <conio.h>
int main()
{
    uint8_t a = 0xff;
    uint8_t y = 0x00;
  // uint16_t y = 0x00;
    __asm {
       // zad18
    /*    xor ax, ax
        xor bx, bx
        xor dx, dx
        mov al, a
        mov bl, a
        shl ax, 5
        shl bx, 1
        add dx, ax
        add dx, bx
        mov y, dx */

        //zad71
      /*  mov bl, 0
        mov al, a
        and al, 0x01
        shl al, 6
        or bl, al

        mov al, a
        and al, 0x02
        shl al, 6
        or bl, al

        mov al, a
        and al, 0x04
        shl al, 0
        or bl, al

        mov al, a
        and al, 0x08
        shl al, 0
        or bl, al

        mov al, a
        and al, 0x10
        shr al, 0
        or bl, al

        mov al, a
        and al, 0x20
        shr al, 0
        or bl, al

        mov al, a
        and al, 0x40
        shr al, 6
        or bl, al

        mov al, a
        and al, 0x80
        shr al, 6
        or bl, al
        

        mov y, bl*/
    }
   // printf("%d\n", y);
   // printf("%#x", y);
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
