// ASK_6.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <iostream>
#include <conio.h>

int main()
{
	unsigned char a = 0x35;
	unsigned long y=0x00;
	/*for (int i = 0; i != 5; i++) {
		y += i;
	}
	printf("%d\n", y);*/
	__asm {
	//Zad1 ASK	
		/*
		xor eax,eax
	petla_for:
	sub eax,5
    jz petla_for_koniec
		add eax, 5
		add y, eax
		add eax, 1
		jmp petla_for

   petla_for_koniec:

   */
   //Zad2 
   /*
		xor eax, eax
		add eax,5
		petla_for :
		cmp eax, 0
			jz petla_for_koniec
			sub y, eax
			add eax, -1
			jmp petla_for

			petla_for_koniec :
		*/
//Zad3
		
		xor eax, eax
		add eax, 5
		petla_for :
		sub eax, 0
			jz petla_for_koniec
			sub y, eax
			add eax, -1
			jmp petla_for

			petla_for_koniec :

//Zad4
		/*
		xor eax,eax
		xor ebx,ebx
petla_while:
mov ebx,eax
sub ebx,5
jz petla_while_koniec
add eax,1
jmp petla_while
petla_while_koniec:
mov y,eax*/

//Zad5
		/*
		xor eax, eax
		petla_while :
		add eax, 1
			cmp eax, 5
			jz petla_while_koniec
			jmp petla_while
			petla_while_koniec :
		mov y, eax*/

//Zad6
		/*
		xor eax, eax
		xor ebx, ebx
		petla_while :
			add eax, 1
			mov ebx, eax
			add ebx, -5
			jnz petla_while	
				mov y, eax
				*/
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
