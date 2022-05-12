//ALGO2 IS1 223A LAB10
//Wojciech Lidwin
//lw46577@zut.edu.pl

#include <iostream>
#include <cmath>
#include <complex>
using namespace std;
const double pi = acos(-1);
complex<double>* dft(complex<double>* tablica, int N);
void fft(complex<double>* tablica, int N);
complex<double> blad(complex<double>* tab_dft, complex<double>* tab_tft, int N);
int main()
{
    int do_pokazu=0;
    cout << "Czy pokazac wspolczynniki? " << endl;
    cout << "1. Tak" << endl;
    cout << "0. Nie" << endl;
    cin >> do_pokazu;
    int cos = 13;
    for (int o = 1; o <= cos; o++) {
        const int N = 1 << o;
        double* f = new double[N];
        for (int n = 0; n < N; n++) {
            f[n] = n / (double)N;
        }
        complex<double>* f_com = new complex<double>[N];
        for (int j = 0; j < N; j++) {
            f_com[j] = complex<double>(f[j], 0);
        }
        clock_t t1 = clock();
        complex<double>* cDFT = dft(f_com,N);
        clock_t t2 = clock();
        double dft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
        cout << "Czas DFT: " << dft_time << endl;
        t1 = clock();
        fft(f_com, N);
        complex<double>* cFFT = f_com;
        t2 = clock();
        double fft_time = (t2 - t1) / (double)CLOCKS_PER_SEC * 1000.0;
        cout << "Czas FFT: " << fft_time << endl;
        complex<double> zgodnosc = blad(cDFT,cFFT,N);
        cout << "Blad "<<zgodnosc << endl;
        if (do_pokazu>=1) {
            for (int j = 0; j < N; j++) {
                cout << "DFT: " << cDFT[j] << endl;
                cout << "TFT: " << cFFT[j] << endl;
            }
        }
        delete[] f, cDFT, cFFT, f_com;
    }
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

complex<double>* dft(complex<double>* tablica, int N)
{
    double do_potegi = -pi * 2.0;
    complex<double>* wynik=new complex<double>[N];
    for (int j = 0; j < N; j++) {
        complex<double> sum(0, 0);
        for (int k = 0; k < N; k++) {
            sum += tablica[k] * exp(complex<double>(0.0, (double)(do_potegi * k * j / N)));
        }
        wynik[j] = sum;
    }
    return wynik;
}

void fft(complex<double>* tablica, int N)
{
    if (N == 1) {
        return;
}
    double do_potegi = -pi * 2.0;
    complex<double>* parzyste = new complex<double>[N / 2];
    complex<double>* nieparzyste=new complex<double>[N / 2];
    for (int j = 0; j < N; j++) {
        if (j % 2 ==0 ) {
            parzyste[j / 2] = tablica[j];
        }
        else {
            nieparzyste[(j -1)/ 2] = tablica[j];
        }
    }
    fft(parzyste, N / 2);
    fft(nieparzyste, N / 2);
    for (int j = 0; j < N / 2; j++) {
        complex<double> temp = exp(complex<double>(0.0, do_potegi *j/N))*nieparzyste[j];
        tablica[j] = parzyste[j] + temp;
        tablica[N / 2 + j] = parzyste[j] - temp;
    }

}

complex<double> blad(complex<double>* tab_dft, complex<double>* tab_tft, int N)
{
    complex<double> sum(0, 0);
    for (int j = 0; j < N; j++) {
        sum = abs(tab_dft[j] - tab_tft[j]);
}
    sum = sum *complex<double> (1 / N);
    return sum;
}
