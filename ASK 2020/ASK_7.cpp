// ASK_7.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <conio.h>
/*
int funkcja(unsigned long a) {
	int cnt = 0;
	for (int i = 0; i < 8; i++) {
		cnt += (a & 0x01);
		a >>= 1;
	}
	return 8 - cnt;*/
	//zle
/*	if ((8 - cnt) % 2==0) {
		return 1;
	}
	else {
		return 0;
	}*/
	
//}

int main()
{
	unsigned char a = 0x37;
	unsigned long y = 0x00;
	unsigned char a_1 = 0x00;
	unsigned char counter = 0;
	int cnt=0;
	/*
	cnt += (a & 0x01) >> 0;
	cnt += (a & 0x02) >> 1;
	cnt += (a & 0x04) >> 2;
	cnt += (a & 0x08) >> 3;
	cnt += (a & 0x10) >> 4;
	cnt += (a & 0x20) >> 5;
	cnt += (a & 0x40) >> 6;
	cnt += (a & 0x80) >> 7;*/
	unsigned char b=0;
	for (int i = 7; i >= 0; i--) {
		unsigned char as = a;
		as &= 1;
		as <<= i;
		b += as;
		a >>= 1;
	}
	/*
	cnt+=(a&0x01);
	a>>=1;
	*/
	//cnt = funkcja(a);
	printf("%d\n", b);
	__asm {
		//zad1
		/*
		xor eax, eax
		mov al, a_1
		petla_for_start:
			mov al,a_1
			and al,0x01
			add y_1, al
			shr a_1,0x01
			jnz petla_for_start
do_while_end:
mov al, 0x08;
sub al,y_1
mov y_1,al
*/
//zad2
		/*
		xor eax, eax
		xor ebx, ebx
		mov al, a_1

		PETLA_WHILE :
		mov bl, al
			and bl, 0x01
			add counter, bl
			shr al, 1
			jnz PETLA_WHILE

			xor eax, eax
			xor ebx, ebx
			mov al, counter
			and al, 1
			mov bl, 1
			sub bl, al
			mov counter, bl
			*/


   }
	printf("%d\n", counter);
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
