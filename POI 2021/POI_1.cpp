// POI_1.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
//

#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;
int main()
{
	int m1 =6, m2 = 7, c1 = 38, c2 = 79, k0 = 12;
	int n1, n2;
	float N, k1;
	printf(" % 3s % 3s\n", "N", "k1");
	for (n1 = 0; n1 < 10; ++n1) {
		for (n2 = 0; n2 < 10; ++n2) {
			N = (float)(m1 * (c1 - c2) - c1 * (m1 - m2)+k0 * (m1 - m2)) / (n1
				* (m1 - m2) - m1 * (n1 - n2));
			k1 = (float)(n1 * N + c1 - k0) / m1;
			if (N > 0 && (floor(N) == N) && N < 128 && k1 < 128)
				cout<< N<<" "<< k1 << endl;
		}
	}
	return 0;
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
