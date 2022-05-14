// prob_dfs.cpp : Ten plik zawiera funkcję „main”. W nim rozpoczyna się i kończy wykonywanie programu.
#include <iostream>
#include <cmath>
#include <vector>
#include <time.h>
using namespace std;
int sum;
int spr;
int stan;
vector <int> tablica;
int N = 4;
int check(int i, int j) {

            spr++;
            if ( abs(i - j) == abs(tablica[i] - tablica[j])|| tablica[j] == tablica[i] ) return 1;
            else return 0;
        
  

}

void  dfs(int val)
{
    stan++;
    if (val == N + 1)
    {
        
       for (int i = 1; i < val; i++) {
         
            if (sum == 1) break;
           for (int j = 1; j < i; j++) {
               
                if(check(i,j))
                    return;
               
            }
        }
        sum++;
        for (int j = 1; j < val; j++) {
            for (int k = 0; k < val-1; k++) {
                if (tablica[j]-1 == k) {
                              cout << "1";
                }
                     else { cout << "0"; }

            }

                cout << endl;
                
        }
        cout << endl;
    }
    
    for (int i = 1; i <= N; i++)
    {
        
        if (sum == 1) break;
        tablica[val] = i;
        dfs(val + 1);
        
    }

}


void result(int n) {
    tablica.resize(n + 1);
    cout << "Liczba: "<<n << endl;
    clock_t res_1, res_2;
    res_1 = clock();
    dfs(1); 
    res_2=clock();
    double time;
    time = double(res_2- res_1)/CLOCKS_PER_SEC;
    cout << "Czas: " << time << endl;
    cout<<"Stany utworzone " << stan << endl;
    cout<<"Sprawdzenia: " << spr << endl;
    tablica.clear();
    spr, stan, sum = 0;
}
int main()
{

    sum = 0;
    spr = 0;
    stan = 0;
    
    for (int i = 4; i <= 10; i++) {
        N = i;
        result(i);
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
