// ASk_powtorka.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
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
    // c2c1c0 b2b1b0 a1a0
    un_X x, y, z;
    z.bits.a = y.bits.a = x.bits.a = 1;//11
    z.bits.b = y.bits.b = x.bits.b = 3;//001
    z.bits.c = y.bits.c = x.bits.c = 4;//010
    x.bits.c = x.bits.b * x.bits.a;
    printf("%#4x\r\n", x.BYTE);
    printf("a= %d\r\n", x.bits.a);
    printf("b= %d\r\n", x.bits.b);
    printf("c= %d\r\n", x.bits.c);
    uint16_t a = 0x12;
    uint8_t b = 0x02;
    // unsigned char b = 0x5;
  //  uint16_t y=0x00;
    //x.bits.c = x.bits.a + 1;
    //x.bits.b = x.bits.a;
//    for (int i = 5; i != 0; i--) y -= i;
    //printf("%d\n", y);
    __asm {
        //Zad1 add
      /*  xor ax, ax
        xor bx, bx
        xor dx,dx
        mov al,a
        mov bl, a
        shl ax,4
        shl bx,2
        add dx, ax
        add dx, bx
        mov y,dx
        */

     //Zad1 sub
      /*  xor ax, ax
        xor bx, bx
        xor cx, cx
        xor dx, dx
        mov al, a
        mov bl, a
        mov cl, a
        shl ax, 5
        shl bx, 3
        shl cx, 2
        mov dx, ax
        sub dx, bx
        sub dx, cx
        mov y, dx*/

    //Zad1 bez shl shr
    /*    xor ax, ax
        xor bx, bx
        xor cx, cx
        xor dx, dx
        mov al, a
        add bx,ax
        add bx, ax
        add cx, bx
        add cx, bx
        add dx, cx
        add dx, cx
        mov y,dx
        add y,dx 
        add y,cx*/

      //Zad2 ify sub
      /*  xor ax,ax
        xor bx, bx
        mov al,a
        sub al,0x32
        jz petla
        mov bl,1
        jmp koniec
        mov bl,0
        koniec:
    petla:
        mov y,bl*/

        //zad2 cmp
   /*     xor ax, ax
        xor bx, bx
        mov al, a
        cmp al, 0x32
        jz petla
        mov bl, 1
        jmp koniec
        mov bl, 0
        koniec:
    petla:
        mov y, bl*/

    //zad2 if add
    /*    xor ax, ax
        xor bx, bx
        mov al, a
        add al, -0x32
        jz petla
        mov bl, 1
        jmp koniec
        mov bl, 0
        koniec:
    petla:
        mov y, bl*/

        //zad4 petla i++ cmp
      /*  xor ax, ax
        xor bx, bx
        xor cx, cx
        mov al, a
        mov bx, 0
        
        petla:     
        cmp bx, 0x05
        jz koniec
        add cx, bx
        add bx, 1
        jmp petla
    koniec:
        mov y, cl*/

    //Zad4 sub petla i++
      /*  xor ax, ax
        xor bx, bx
        xor cx, cx
        mov al, a
        mov bx, 0

        petla:
        sub bx, 0x05
            jz koniec
            add bx,0x05
            add cx, bx
            add bx, 0x01
            jmp petla
            koniec :
        mov y, cl*/

//zad4 petla i-- sub     unsigned long y=0x00;
/*xor eax,eax

add eax, 5

petla:
sub eax, 0
jz koniec
sub y, eax
add eax, -1
jmp petla
koniec :*/

//zad4 petla i-- cmp     unsigned long y=0x00;
/*xor eax, eax
add eax, 5
petla:
cmp eax, 0
jz koniec
sub y, eax
add eax, -1
jmp petla
koniec :*/

//zad5 while sub
/*xor eax, eax
xor ebx, ebx
petla_while :
mov ebx, eax
sub ebx, 5
jz petla_while_koniec
add eax, 1
jmp petla_while
petla_while_koniec :
mov y, eax*/

//zad5 while sub
/*xor eax, eax
xor ebx, ebx
petla_while :
mov ebx, eax
cmp ebx, 5
jz petla_while_koniec
add eax, 1
jmp petla_while
petla_while_koniec :
mov y, eax*/

//zad5 do while 
/*xor eax, eax
xor ebx,eax
petla:
add eax,1
mov ebx,eax
add ebx, -5
jnz petla
mov y, eax*/

//zad5 while add
/*xor eax, eax
xor ebx, eax

petla :
add ebx, -5
jz petla_while_koniec
add eax, 1
mov ebx, eax
jmp petla
petla_while_koniec:
mov y, eax*/

//zad6 sumowanie zer wariant bez petli
/*xor al,al
mov al,a
and al,0x01
add y,al
shr a,1

mov al, a
and al, 0x01
add y, al
shr a, 1

mov al, a
and al, 0x01
add y, al
shr a, 1

mov al, a
and al, 0x01
add y, al
shr a, 1

mov al, a
and al, 0x01
add y, al
shr a, 1

mov al, a
and al, 0x01
add y, al
shr a, 1

mov al, a
and al, 0x01
add y, al
shr a, 1

mov al, a
and al, 0x01
add y, al
shr a, 1

mov al, a
and al, 0x01
add y, al
shr a, 1

mov al,0x08
sub al,y
mov y,al*/

//zad6 suma zer petla
/*xor eax, eax
mov al, a
petla_for_start :
mov al, a
and al, 0x01
add y, al
shr a, 0x01
jnz petla_for_start
do_while_end :
mov al, 0x08;
sub al, y
mov y, al*/

//zad7 parzystosc jedynek petla
/*xor eax, eax
xor ebx, ebx
mov al, a

PETLA_WHILE :
mov bl, al
and bl, 0x01
add y, bl
shr al, 1
jnz PETLA_WHILE

xor eax, eax
xor ebx, ebx
mov al, y
and al, 1
mov bl, 1
sub bl, al
mov y, bl*/

//zad7 parzystosc jedynek bez petli 
/*xor eax, eax
xor ebx, ebx
mov al, a
mov bl, al
and bl, 0x01
add y, bl
shr al, 1


mov bl, al
and bl, 0x01
add y, bl
shr al, 1


mov bl, al
and bl, 0x01
add y, bl
shr al, 1


mov bl, al
and bl, 0x01
add y, bl
shr al, 1


mov bl, al
and bl, 0x01
add y, bl
shr al, 1


mov bl, al
and bl, 0x01
add y, bl
shr al, 1


mov bl, al
and bl, 0x01
add y, bl
shr al, 1


mov bl, al
and bl, 0x01
add y, bl
shr al, 1


mov al, y
and al, 1
mov bl, 1
sub bl, al
mov y, bl*/

//zad8 bez petli zamiana poczatku bitow na konce bitow
/*
mov bl,0
mov al,a
and al, 0x01
shl al,7 
or bl,al

mov al, a
and al, 0x02
shl al, 5
or bl, al

mov al, a
and al, 0x04
shl al, 3
or bl, al

mov al, a
and al, 0x08
shl al, 1
or bl, al

mov al, a
and al, 0x10
shr al, 1
or bl, al

mov al, a
and al, 0x20
shr al, 3
or bl, al

mov al, a
and al, 0x40
shr al, 5
or bl, al

mov al, a
and al, 0x80
shr al, 7
or bl, al


mov y,bl
*/
//zad8 petla zmiana bitow
/*xor cx,cx
xor bl,bl
mov cx, 0


petla:
cmp cx, 8
jz koniec
shl bl, 1
mov al, a
and al,0x1
or bl,al
shr a,1
add cx,1
jmp petla
koniec:
mov y,bl*/

//zad9 test mnozenie 2 liczb
/*xor ax, ax
mov bl, b
mov al, a
xor dx, dx

test bl, 0x01;
jz et0
add dx, ax
et0 :
shl ax, 1


test bl, 0x02;
jz et1
add dx, ax
et1 :
shl ax, 1

test bl, 0x04;
jz et2
add dx, ax
et2 :
shl ax, 1

test bl, 0x08;
jz et3
add dx, ax
et3 :
shl ax, 1

test bl, 0x10;
jz et4
add dx, ax
et4 :
shl ax, 1

test bl, 0x20;
jz et5
add dx, ax
et5 :
shl ax, 1

test bl, 0x40;
jz et6
add dx, ax
et6 :
shl ax, 1

test bl, 0x80;
jz et7
add dx, ax
et7 :
shl ax, 1
mov y,dx*/


//and nie dziala zad 9
/*
xor ax, ax
mov bl, b
mov al, a
xor dx, dx

and bl, 0x01

jz et0
add dx, ax
et0 :
shl ax, 1
shr b, 1

and bl, 0x01
jz et1
add dx, ax
et1 :
shl ax, 1
shr b, 1

and bl, 0x04
jz et2
add dx, ax
et2 :
shl ax, 1
shr b, 1

and bl, 0x08
jz et3
add dx, ax
et3 :
shl ax, 1
shr b, 1

and bl, 0x10
jz et4
add dx, ax
et4 :
shl ax, 1
shr b, 1

and bl, 0x20
jz et5
add dx, ax
et5 :
shl ax, 1
shr b, 1

and bl, 0x40
jz et6
add dx, ax
et6 :
shl ax, 1
shr b, 1

and bl, 0x80
jz et7
add dx, ax
et7 :
shl ax, 1
mov y, dx
*/

//zad9 petla mnozenie
/*xor ax, ax
mov bl, b
mov al, a
xor dx, dx
petla :
test bl, 0x01;
jz et
add dx, ax
et :
shl ax, 1
shr bl, 1
jnz petla
mov y, dx*/

//zad10 tu dla 9,25=(8+1+0.25)*a=(2^3+2^0+2^-2)
/*mov ax, a
shl ax, 3
add y, ax

mov ax, a
shl ax, 0
add y, ax

mov ax, a
shr ax, 2
add y, ax*/

//1,125=(2^0+2^-2)
/*mov ax, a
shl ax, 0
add y, ax

mov ax, a
shr ax, 3
add y, ax*/

//zad13 x.c=x.a+1 x.b=x.a
/*mov al, z.BYTE
add al, 1
and al, 0x03
shr al, 0
mov cl, z.BYTE
and cl, 0x1f
shl al, 5
or cl, al
mov al, z.BYTE
and al, 0x03
shr al, 0
and cl, 0xe3
shl al, 2
or cl, al
mov z.BYTE, cl*/


//x.a=x.c x.b=x.c+1 

/*mov al, z.BYTE
and al, 0xe0
mov cl, z.BYTE
and cl, 0xfc
shr al, 5
or cl, al

mov al, z.BYTE
and al, 0xe0
and cl, 0xe3
shr al, 3
mov bl, 1
shl bl, 2
add al, bl
or cl, al
mov z.BYTE, cl*/


//x.bits.c = x.bits.b; x.bits.b = x.bits.a;
/*mov al, z.BYTE
and al, 0x1c;
shl al, 3
mov cl, z.BYTE
and cl, 0x1f
or cl, al
mov al, z.BYTE
and al, 0x03
shr al, 0
and cl, 0xe3
shl al, 2
or cl, al
mov z.BYTE, cl*/


//x.c=x.b*x.a
/*xor eax, eax
mov al, z.BYTE
mov ah, z.BYTE
and ah,0x0F
test al,0x01
jz koniec
xor al,al
mov al, z.BYTE
and al,0x0E
shl al,3
or ah,al
koniec:
mov z.BYTE,ah*/
/*
xor ax, ax
xor cx, cx
xor dx, dx
xor cx, cx

mov dl, z.BYTE //dl is where we store the result
and dl, 0x0f   //zero out the c fields

mov al, z.BYTE
and al, 0x01   //get a ready for multiplying

mov bl, z.BYTE
and bl, 0x0e
shr bl, 1      //get b ready for multiplying

start:
test bl, 0x01
jz et
add cl, al

et :
shl al, 1
shr bl, 1
jnz start

shl cl, 4

or dl, cl

mov z.BYTE, dl*/


xor ax, ax
xor cx, cx
xor dx, dx
xor cx, cx
xor eax, eax

mov dl, z.BYTE //dl is where we store the result
and dl, 0x1f  //zero out the c fields

mov al, z.BYTE
and al, 0x03   //get a ready for multiplying

mov bl, z.BYTE
and bl, 0x1c
shr bl, 1      //get b ready for multiplying

start:
mov dh, bl
and dh, 0x01
sub dh, 0
jz et
add cl, al

et :
shl al, 1
shr bl, 1
jnz start

shl cl, 4

or dl, cl

mov z.BYTE, dl
/*
xor ax, ax
xor cx, cx
xor dx, dx
xor cx, cx

mov dl, z.byte //dl is where we store the result
and dl, 0x0f   //zero out the c fields

mov al, z.byte
and al, 0x01   //get a ready for multiplying

mov bl, z.byte
and bl, 0x0e
shr bl, 1      //get b ready for multiplying

start:
mov dh, bl
and dh, 0x01
sub dh, 0
jz et
add cl, al

et :
shl al, 1
shr bl, 1
jnz start

shl cl, 4

or dl, cl

mov z.byte, dl*/
}
   // printf("%d\n", y);
  //  printf("%#x", y);
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
