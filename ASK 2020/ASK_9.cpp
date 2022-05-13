// ASK_9.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <conio.h>
int main()
{
    uint8_t a = 0x12;
    uint8_t r = 0x00;
    uint8_t b = 0x02;
    uint16_t y = 0x00;
   // y = a * b;
   /* if (b0)y += a << 0;
    if (b1)y += a << 0;
    if (b2)y += a << 0;
    if (b3)y += a << 0;
    if (b4)y += a << 0;
    if (b5)y += a << 0;
    if (b6)y += a << 0;
    if (b7)y += a << 0;*/
 /*   if (b & 0x01) y += 1;
    a <<= 1;
    if (b & 0x02) y += 1;
    a <<= 1;
    if (b & 0x04) y += 1;
    a <<= 1;
    if (b & 0x08) y += 1;
    a <<= 1;
    if (b & 0x10) y += 1;
    a <<= 1;
    if (b & 0x20) y += 1;
    a <<= 1;
    if (b & 0x40) y += 1;
    a <<= 1;
    if (b & 0x80) y += 1;
    a <<= 1;
    printf("%d\n", y);*/
    __asm {
        xor ax, ax
        mov bl, b
        mov al, a
        xor dx,dx
       // mov cl,0x01
   /*
        test bl, 0x01;b0
        jz et0
        add dx,ax
        et0:
        shl ax, 1

        test bl, 0x02; b1
        jz et1
        add dx, ax
        et1:
        shl ax,1
            test bl, 0x04; b2
            jz et2
            add dx, ax
            et2 :
        shl ax, 1
            test bl, 0x08; b3
            jz et3
            add dx, ax
            et3 :
        shl ax, 1

            test bl, 0x10; b4
            jz et4
            add dx, ax
            et4 :
        shl ax, 1

            test bl, 0x20; b5
            jz et5
            add dx, ax
            et5 :
        shl ax, 1
            test bl, 0x40; b6
            jz et6
            add dx, ax
            et6 :
        shl ax, 1
            test bl, 0x80; b7
            jz et7
            add dx, ax
            et7 :
        shl ax, 1*/
    petla:
      //  test bl,0x01
      //  jnz koniec
       // sub r,8
   //     sub r,8
  //      jnz koniec
        test bl, 0x01;    
        jz et
        add dx, ax  
            et :
        shl ax, 1  
        shr bl,1
      inc r
      jnz petla
            
//     koniec:
            mov y,dx
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
