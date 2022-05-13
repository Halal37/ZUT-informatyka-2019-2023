// ASK_4_1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <conio.h>

int main()
{
    unsigned char a = 10;
    unsigned short y;
    //    y = a * 24;
  //  y =
        //a*36=a(32+4)=
 //       (unsigned short)(a << 5) - (unsigned short)(a << 3);
 /*   printf("%#4x   ", y);
    if (a == 0x32) {
        y = 0;
    }
    else {
        y = 1;
    }

    printf("%#4x   ", y);*/
    __asm {
 /*       xor bx, bx; bh i bl
        xor ax, ax; ah i al;
        mov bh, 0;
mov ah,0

mov al,a
shl ax,5
mov bl, a
shl bx, 2
add bx,ax 
mov y, bx*/

//Zad3
/*xor ax,ax
xor bx, bx
mov al, a
shl ax,5
mov bl, a
shl bx, 3
sub ax, bx
mov y, ax*/

//Zad5

//Domowe_sub
 /*       xor ax, ax
        xor bx, bx
        mov ax, 0x32
        sub ax, 0x32
        jz rowna
        mov y, 1
        jmp wynik
        rowna :
        mov y, 0
            wynik :

*/
//Domowe_cmp
/*
  xor ax, ax
  xor bx, bx
  mov ax, 0x32
  mov bx,0x16
  cmp ax, bx
  jz rowna
  mov y,1
  jmp wynik
  rowna:
  mov y,0
 wynik:     
*/
//Zad_domowe_add
   /*     xor ax, ax
        xor bx, bx
        mov ax, 0x32
        add ax, -0x32
        jnz rowna
        mov y, 0
        jmp wynik
        rowna :
        mov y, 1
            wynik :*/
            
}
    printf("%d\n",y);
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
