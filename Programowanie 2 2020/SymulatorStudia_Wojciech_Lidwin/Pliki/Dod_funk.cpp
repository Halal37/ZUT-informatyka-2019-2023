#include "Dod_funk.h"
#include <iostream>
//Przestrzen nazw dla funkcji
namespace Funkcje {
	//Zastapienie liczb w kodzie nazwami
	enum {
		zero = 0,
		jeden = 1,
		dwa = 2,
		trzy = 3,
		cztery = 4,
		piec = 5,
		szesc = 6,
		siedem = 7,
		dziewiec = 9,
		ten = 10,
		trzynascie = 13,
		czternascie = 14,
		pietnascie = 15,
		szescnascie = 16,
		dziewietnascie=19,
		dwadziescie = 20,
		trzydziesci = 30,
		trzydziesci_dziewiec =39,
		czterdziesci = 40,
		czterdziesci_dziewiec=49,
		piecdziesiat = 50,
		piecdziesiat_dziewiec = 59,
		szescdziesiat = 60,
		szescdziesiat_dziewiec =69,
		siedemdziesiat = 70,
		siedemdziesiat_dziewiec =79,
		osiem = 8,
		stala = 29,
		osiemdziesiat = 80,
		dzwiescie = 200
	};
	using namespace std;
	//Deklaracja klas
	Film Prod;
	Budzet Gra(dzwiescie);
	//Funkcja, pozwalajaca na odczekanie podanej wartosci czasu do nastepnego polecenia
	void wait(int seconds)
	{
		clock_t endwait;
		endwait = clock() + seconds * CLOCKS_PER_SEC;
		while (clock() < endwait) {}
	}
	//Funckje statyczne cout
	static void menuwyp() {
		cout << "Menu" << endl;
	}
	static void powrot() {
		cout << "Powrot" << endl;
	}
	static void punkt1() {
		cout << "1.Zacznij gre" << endl;
	}
	static void punkt1_a() {//Rozwidlenie a punktu 1 
		cout << "Wybierz punkt startowy" << endl;
	}
	static void punkt1_a_a() {//Rozwidlenie a rozwidlenia a punktu 1 
		cout << "1.Poczatkujace studio" << endl;
	}
	static void punkt1_a_b() {//Rozwidlenie b rozwidlenia a punktu 1 
		cout << "2.Swiatowy potentant" << endl;
	}
	static void wyjscie() {
		cout << "0.Wyjdz z gry" << endl;
	}
	static void tworcy() {
		cout << "2.Tworcy" << endl;
	}
	static void ja() {
		cout << "Wojciech Lidwin grupa:123A" << endl;
	}
	static void zm_budzet() {
		cout << "Za maly budzet;" << endl;
	}
	static void zatrudnij_obsade() {
		cout << "Zatrudnij obsade" << endl;
	}
	static void ogarnij_sprzet2() {
		cout << "Ogarnij sprzet" << endl;
	}
	void obecny_budzet(int z) {
		cout << "Obecny budzet: " << z << endl;
	}

	//Funckja zwracajaca nowa wartosc budzetu, po dokonaniu przez uzytkownika wyboru czlonka ekipy
	int korekcja_budzetu(int budzet, string s, int& zupka) {
		int Rezy = jeden, wybor_uzytkownika = zero;
		do {
			obecny_budzet(budzet);
			cout << "Ktorego " << s << " chcesz zatrudnic?" << endl;
			while (true) {
				cin >> wybor_uzytkownika;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Zly typ" << endl;
				}
				break;
			}if ((wybor_uzytkownika >= zero) && (wybor_uzytkownika < ten)) {
				if (budzet < wybor_uzytkownika)
					zm_budzet();
				else {
					auto ort = budzet - wybor_uzytkownika;
					cout << ort << endl;
					Prod.Nowy_budzet(ort);
					Prod.get_bud();
					budzet = ort;
					Rezy = zero;
				}
			}
			else {
				cout << "Wartosc nie moze byc mniejsza od zera" << endl;
			}
		} while (Rezy != zero);
		zupka = wybor_uzytkownika;
		return budzet;
	}
	//Przecziazenie funkcji dla klasy Rezyserow
	int korekcja_budzetu(int budzet, string s, int& zupka, Rezyser ha) {
		int Rezy = jeden, wybor_uzytkownika = zero;
		do {
			obecny_budzet(budzet);
			cout << "Ktorego " << s << " chcesz zatrudnic?" << endl;
			while (true) {
				cin >> wybor_uzytkownika;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Zly typ" << endl;
					wait(ten);
				}
				break;
			}if ((wybor_uzytkownika >= zero) && (wybor_uzytkownika < ten)) {
				wybor_uzytkownika = wybor_uzytkownika * wybor_uzytkownika;
				if (budzet < wybor_uzytkownika){
					zm_budzet();
				}
				else {
					auto ort = budzet - wybor_uzytkownika;
					cout << ort << endl;
					Prod.Nowy_budzet(ort);
					Prod.get_bud();
					budzet = ort;
					Rezy = zero;
				}
			}
			else {
				cout<<"Wartosc nie moze byc mniejsza od zera" << endl;
			}
		} while (Rezy != zero);
		zupka = wybor_uzytkownika;
		return budzet;
	}
	//Przeciazenie funkcji dla klasy Scenarzysta
	int korekcja_budzetu(int budzet, string s, int& zupka, Scenarzysta ha) {
		int Rezy = jeden, wybor_uzytkownika = zero;
		do {
			obecny_budzet(budzet);
			cout << "Ktorego " << s << " chcesz zatrudnic?" << endl;
			while (true) {
				cin >> wybor_uzytkownika;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Zly typ" << endl;
				}
				break;
			}
			if ((wybor_uzytkownika >= zero)&&(wybor_uzytkownika < ten)) {
				if (wybor_uzytkownika >= dwa) wybor_uzytkownika = wybor_uzytkownika - dwa;
				if (budzet < wybor_uzytkownika)
					zm_budzet();
				else {
					auto ort = budzet - wybor_uzytkownika;
					cout << ort << endl;
					Prod.Nowy_budzet(ort);
					Prod.get_bud();
					budzet = ort;
					Rezy = zero;
				}
			}
			else {
				cout << "Wartosc nie moze byc mniejsza od zera" << endl;
			}
		} while (Rezy != zero);
		zupka = wybor_uzytkownika;
		return budzet;
	}

	//Funkcja realizujaca wybor ekipy do realizowanej produkcji
	int Wybor_ekipy(int budzet, vector<int>& Tablica_wartosci) {
		int numer_stringa = zero, wart = zero, suma = zero,i=zero;
		array<string, osiem> Tabelka{ "Rezysera","Scenarzyste","Operatora","Kompozytora","Montazyste","Scenografa","Kostiumografa","Dzwiekowca" };
		array<int, osiem> Tabelka_wartosci{};
		Baza go_brrr;
		array<Operator, ten> oper;
		array<Kompozytor, ten> kompozytor;
		array<Monatzysta, ten> montazysta;
		array<Scenograf, ten> scenograf;
		array<Kostiumograf, ten> kostiumograf;
		array<Dzwiekowiec, ten> dziewciekowiec;
		array<Rezyser, ten> z;
		array<Scenarzysta, ten> scen;
		array<Persona*, osiemdziesiat> wsk;
		auto it = wsk.begin();
		while(it!=wsk.end())
		{
			cout << "Nr." << i%ten << ": " << endl;

			if (i < ten) {
				
				wsk[i] = &z[i];
				wsk[i]->stworz(i);
				Persona::getbaze()->stworz(wsk[i]);
				Persona::getbaze()->wyswietl(i);
				cout << endl;
			}if (i == dziewiec) {
				budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart], z[i]);
				numer_stringa++;
				wart++;
				system("cls");
			}
			if ((i > dziewiec) && (i < dwadziescie)) {
				wsk[i] = &scen[i - ten];
				wsk[i]->stworz(i - ten);
				Persona::getbaze()->stworz(wsk[i]);
				Persona::getbaze()->wyswietl(i);
				cout << endl;
			}if (i == dziewietnascie) {
				budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart], scen[i - ten]);
				numer_stringa++;
				wart++;
				system("cls");
			}
			if ((i > dziewietnascie) && (i < trzydziesci)) {
				wsk[i] = &oper[i - dwadziescie];
				wsk[i]->stworz(i - dwadziescie);
				Persona::getbaze()->stworz(wsk[i]);
				Persona::getbaze()->wyswietl(i);
				cout << endl;
			}if (i == stala) {
				budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart]);
				numer_stringa++;
				wart++;
				system("cls");
			}
			if ((i > stala) && (i < czterdziesci)) {
				wsk[i] = &kompozytor[i - trzydziesci];
				wsk[i]->stworz(i - trzydziesci);
				Persona::getbaze()->stworz(wsk[i]);
				Persona::getbaze()->wyswietl(i);
				cout << endl;
			}if (i == trzydziesci_dziewiec) {
				budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart]);
				numer_stringa++;
				wart++;
				system("cls");
			}
			if ((i > trzydziesci_dziewiec) && (i < piecdziesiat)) {
				wsk[i] = &montazysta[i - czterdziesci];
				wsk[i]->stworz(i - czterdziesci);
				Persona::getbaze()->stworz(wsk[i]);
				Persona::getbaze()->wyswietl(i);
				cout << endl;
			}if (i == czterdziesci_dziewiec) {
				budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart]);
				numer_stringa++;
				wart++;
				system("cls");
			}
			if ((i > czterdziesci_dziewiec) && (i < szescdziesiat)) {
				wsk[i] = &scenograf[i - piecdziesiat];
				wsk[i]->stworz(i - piecdziesiat);
				Persona::getbaze()->stworz(wsk[i]);
				Persona::getbaze()->wyswietl(i);
				cout << endl;
			}if (i == piecdziesiat_dziewiec) {
				budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart]);
				numer_stringa++;
				wart++;
				system("cls");
			}
			if ((i > piecdziesiat_dziewiec) && (i < siedemdziesiat)) {
				wsk[i] = &kostiumograf[i - szescdziesiat];
				wsk[i]->stworz(i - szescdziesiat);
				Persona::getbaze()->stworz(wsk[i]);
				Persona::getbaze()->wyswietl(i);
				cout << endl;
			}if (i == szescdziesiat_dziewiec) {
				budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart]);
				numer_stringa++;
				wart++;
				system("cls");
			}
			if ((i > szescdziesiat_dziewiec) && (i < osiemdziesiat)) {
				wsk[i] = &dziewciekowiec[i - siedemdziesiat];
				wsk[i]->stworz(i - siedemdziesiat);
				Persona::getbaze()->stworz(wsk[i]);
				Persona::getbaze()->wyswietl(i);
				cout << endl;
			}if (i == siedemdziesiat_dziewiec) {
				budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart]);
				numer_stringa++;
				wart++;
				system("cls");
			}

			i++;
			it++;
		}
		go_brrr.wyswietl_all();
		cout << "Wybory: " << endl << "1:" << endl;
		cout << sqrt(Tabelka_wartosci[zero]) << endl;
		cout << "2: " << endl;
		cout << Tabelka_wartosci[jeden] + dwa << endl;
		cout << "3: " << endl;
		cout << Tabelka_wartosci[dwa] << endl;
		cout << "4: " << endl;
		cout << Tabelka_wartosci[trzy] << endl;
		cout << "5: " << endl;
		cout << Tabelka_wartosci[cztery] << endl;
		cout << "6: " << endl;
		cout << Tabelka_wartosci[piec] << endl;
		cout << "7: " << endl;
		cout << Tabelka_wartosci[szesc] << endl;
		cout << "8: " << endl;
		cout << Tabelka_wartosci[siedem] << endl;

		Tablica_wartosci[zero] = Persona::getbaze()->get_rep(sqrt(Tabelka_wartosci[zero])) + Persona::getbaze()->get_rep(Tabelka_wartosci[jeden]+dwa+ten)+
			Persona::getbaze()->get_rep(Tabelka_wartosci[dwa]+dwadziescie) + Persona::getbaze()->get_rep(Tabelka_wartosci[trzy]+trzydziesci) +
			Persona::getbaze()->get_rep(Tabelka_wartosci[cztery]+czterdziesci) + Persona::getbaze()->get_rep(Tabelka_wartosci[piec]+piecdziesiat) +
			Persona::getbaze()->get_rep(Tabelka_wartosci[szesc]+szescdziesiat) + Persona::getbaze()->get_rep(Tabelka_wartosci[siedem]+siedemdziesiat) ;

		Tablica_wartosci[jeden]= Persona::getbaze()->get_gat(sqrt(Tabelka_wartosci[zero])) + Persona::getbaze()->get_gat(Tabelka_wartosci[jeden] + ten+dwa) +
			Persona::getbaze()->get_gat(Tabelka_wartosci[dwa] + dwadziescie) + Persona::getbaze()->get_gat(Tabelka_wartosci[trzy] + trzydziesci) +
			Persona::getbaze()->get_gat(Tabelka_wartosci[cztery] + czterdziesci) + Persona::getbaze()->get_gat(Tabelka_wartosci[piec] + piecdziesiat) +
			Persona::getbaze()->get_gat(Tabelka_wartosci[szesc] + szescdziesiat) + Persona::getbaze()->get_gat(Tabelka_wartosci[siedem] + siedemdziesiat);

		Tablica_wartosci[dwa]= Persona::getbaze()->get_roz(sqrt(Tabelka_wartosci[zero])) + Persona::getbaze()->get_roz(Tabelka_wartosci[jeden] + ten+dwa) +
			Persona::getbaze()->get_roz(Tabelka_wartosci[dwa] + dwadziescie) + Persona::getbaze()->get_roz(Tabelka_wartosci[trzy] + trzydziesci) +
			Persona::getbaze()->get_roz(Tabelka_wartosci[cztery] + czterdziesci) + Persona::getbaze()->get_gat(Tabelka_wartosci[piec] + piecdziesiat) +
			Persona::getbaze()->get_roz(Tabelka_wartosci[szesc] + szescdziesiat) + Persona::getbaze()->get_roz(Tabelka_wartosci[siedem] + siedemdziesiat);

		Tablica_wartosci[trzy]= Persona::getbaze()->get_prof(sqrt(Tabelka_wartosci[zero])) + Persona::getbaze()->get_prof(Tabelka_wartosci[jeden] + ten+dwa) +
			Persona::getbaze()->get_prof(Tabelka_wartosci[dwa] + dwadziescie) + Persona::getbaze()->get_prof(Tabelka_wartosci[trzy] + trzydziesci) +
			Persona::getbaze()->get_prof(Tabelka_wartosci[cztery] + czterdziesci) + Persona::getbaze()->get_prof(Tabelka_wartosci[piec] + piecdziesiat) +
			Persona::getbaze()->get_prof(Tabelka_wartosci[szesc] + szescdziesiat) + Persona::getbaze()->get_prof(Tabelka_wartosci[siedem] + siedemdziesiat);

		wait(ten);
		system("cls");

		int numer_pracownika,wybor;
		cout << "Chcesz usunac zbazy jakiegos pracownika?" << endl;
		cout << "1. Tak" << endl;
		cout << "2. Nie" << endl;
		while (true) {
			cin >> wybor;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Zly typ" << endl;
			}
			break;
		}
		if (wybor == jeden) {
			Persona::getbaze()->wyswietl_all();
			cout << "Jakiego" << endl;
			cout << "Podaj numer" << endl;
			while (true) {
				cin >> numer_pracownika;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Zly typ" << endl;
				}
				break;
			}
			
			Persona::getbaze()->usun(numer_pracownika);
			Persona::getbaze()->wyswietl_all();
		}
		return budzet;
	}
	

	int Wybor_sprzetu(int z, string s, vector<int>& Tab,int rodzaj, vector<int>& Zapis_wyborow) {
		int wybor_uzytkownika = zero, zmienna = zero, kamera = jeden,  i = zero, pomoc = jeden;
		array<Sprzet, piec> Golem;
		do {
			for (Sprzet v : Golem)
			{
				cout << "Nr. " << i << " sprzetu" << endl;
				cout << endl;
				v.set_jakosc(i * i);
				v.get_jakosc();
				if (Tab[(rodzaj*piec)+i] != zero) {
					cout << "0.Koszt kupna: " << zero << endl << "1.Koszt wynajmu: " << zero << endl;
					cout << endl;
				}
				else {
					v.pokaz();
				}
				i++;
			}
			obecny_budzet(z);
			cout << s << endl;
			cout << endl;
				cout << "Jaki jest twoj wybor" << endl;
				do {
					while (true) {
						cin >> wybor_uzytkownika;
						if (cin.fail()) {
							cin.clear();
							cin.ignore();
							cout << "Zly typ" << endl;
						}
						break;
					}
					if ((wybor_uzytkownika >= zero) && (wybor_uzytkownika < piec)) {
						if  (z >= wybor_uzytkownika * wybor_uzytkownika) {
							pomoc = zero;
						}
						else {
							cout << "Nie stac cie: " << endl;
						}
					}
				} while (pomoc != zero);
				pomoc = jeden;
				cout << "Chcesz wynajac, czy kupic?" << endl;
				
				do {

					while (true) {
						cin >> zmienna;
						if (cin.fail()) {
							cin.clear();
							cin.ignore();
							cout << "Zly typ" << endl;
						}
						break;
					}
						if ((zmienna >= zero) && (zmienna <= jeden)) {
							Zapis_wyborow[(rodzaj * piec) + wybor_uzytkownika] = wybor_uzytkownika * wybor_uzytkownika;
							if (zmienna == jeden) {
								pomoc = zero;
							}
							if (zmienna == zero) {
								if (z >= piec * wybor_uzytkownika * wybor_uzytkownika) {
									Tab[(rodzaj * piec) + wybor_uzytkownika] = Zapis_wyborow[(rodzaj * piec) + wybor_uzytkownika];
									pomoc = zero;
								}
								else {
									cout << "Nie stac cie na kupno" << endl;
								}
							}
						}
					
				} while (pomoc != zero);
			auto n = wybor_uzytkownika;
			wybor_uzytkownika = wybor_uzytkownika * wybor_uzytkownika;//wynajem
			n = (piec * n * n);//kupno
			do {
				system("cls");
				switch (zmienna) {
				case zero:
					cout << n << endl;
					if (z < n)
						zm_budzet();
					else {
						auto ort = z - n;
						cout << ort << endl;
						Prod.Nowy_budzet(ort);
						Prod.get_bud();
						z = ort;
						kamera = zero;
						n = zero;
					}
					break;
				case jeden:
					if (z < wybor_uzytkownika)
						zm_budzet();
					else {
						auto ort = z - wybor_uzytkownika;
						cout << ort << endl;
						Prod.Nowy_budzet(ort);
						Prod.get_bud();
						z = ort;
						kamera = zero;
						n = zero;
					}
					break;
				default:
					cout << "Podana zla wartosc" << endl;
					n = zero;
					break;

				}
			} while (n != zero);
		} while (kamera != zero);
		return z;
	}

	//Glowna funkcja, pierwsze menu
	void Glowne_menu() {
		PlaySound(TEXT("NO.wav"), NULL, SND_ASYNC);
		Menu_pierwszy_wybor_uzytkownika();
	}
	//Drugie menu, wybieramy rozpoczecie gry, lub wyswietlenie listy tworcow, lub zakonczenie pracy programu
	void Menu_pierwszy_wybor_uzytkownika() {
		int n = jeden, wybor = zero;
		do {

			menuwyp();
			punkt1();
			tworcy();
			wyjscie();

			while (true) {
				cin >> wybor;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Zly typ" << endl;
				}
				break;
			}
			system("cls");
			switch (wybor) {
			case jeden:
				punkt1_a();
				Pod_menu();
				n = zero;

				break;
			case dwa:
				ja();
				n = zero;
				break;
			case zero:
				n = zero;
				break;
			default:
				cout << "Podana zla wartosc" << endl;
				menuwyp();
				punkt1();
				tworcy();
				wyjscie();
				break;
			}

		} while (n != zero);
	}
	//Funckja realizowana, gdy wybierzemy rozpoczecie gry
	void Pod_menu() {
		int n = jeden, p = jeden, wybor = zero, z, 	h = jeden,pocz = zero;
		array<string, trzy> Tabelka2{ "Kamera","Mikrofon","Efekty specjalne" };
		float a;
		vector<int>Magazyn;
		vector<int>Schowek;
		vector<int>Wartosci_ekipy;
		for (int i = zero; i < pietnascie; i++) {
			Schowek.push_back(zero);
			Magazyn.push_back(zero);
	
		}
		for (int i = zero; i < 4; i++) {
			Wartosci_ekipy.push_back(zero);
		}
		for (int i = zero; i < pietnascie; i++) {
		
	
		}
		do {
			punkt1_a_a();
			punkt1_a_b();
			cout << "3."; powrot();
			while (true) {
				cin >> wybor;
				if (cin.fail()) {
					cin.clear();
					cin.ignore();
					cout << "Zly typ" << endl;
				}
				break;
			}
			system("cls");
			switch (wybor) {
			case jeden:
				do {
					system("cls");
					cout << "Obecny budzet: " << endl;
					Gra.set_finanse2();
					a = Gra.get_finanse();
					Prod.Wybor_gatunku();
					do {
						z = Prod.Ustal_budzet(a);
						pocz = z;
						cout << a << endl;
						cout << z << endl;
						if (a < z)
							zm_budzet();
						else {
							Gra.nowy_finanse(a - z);
							Prod.M_time();
							Prod.set_tyt();
							Prod.get_tyt();
							h = zero;
						}
					} while (h != zero);
					h = jeden;
					zatrudnij_obsade();
					z = Wybor_ekipy(z,Wartosci_ekipy);
					ogarnij_sprzet2();
					for (int g = zero; g < trzy; g++) {
						
					
							z = Wybor_sprzetu(z, Tabelka2[g],Magazyn,g,Schowek);
						
					}
					cout << "Marketing: " << endl;
					int suma_elementow = zero;
					int bud_mark = a + z - pocz;
					Marketing do_filmu(zero);
					auto zmiej = rand() % stala;
					auto zwie = rand() % stala;
					Wplyw_M wply(zwie, zmiej);
					do_filmu.Rozdzial_budzetu_marketingowego(bud_mark);

			
					for (int i = zero; i < pietnascie; i++) {
						if (i < piec) {
							cout << Magazyn[i] << " To sa Magazyn: Kamery: " << i << endl;
							cout << endl;
						}
						else   if ((i >= piec) && (i < ten)) {
							cout << Magazyn[i] << " To sa Magazyn: Mikrofonu: " << i - piec << endl;
							cout << endl;
						}
						else {
							cout << Magazyn[i] << " To sa Magazyn: Efektow specjalnych " << i - ten << endl;
							cout << endl;
						}
					}

					for (vector<int>::iterator it = Schowek.begin(); it != Schowek.end(); ++it)
						suma_elementow += *it;
					Sprzet ca(suma_elementow);
					Budzet zet(&do_filmu, &wply, &ca, bud_mark, Wartosci_ekipy[jeden], Wartosci_ekipy[zero], Wartosci_ekipy[trzy], Wartosci_ekipy[dwa]);
					Budzet kopia_bazy;
					cout << endl;
					cout << endl;
					cout << zet;
					zet.nowy_finanse_2(a);
					cout << zet;
					cout << endl;
					cout >> zet;
					cout << zet;
					cout << endl;
					zet(zet);
					cout << endl;
					cout << zet;
					cout << endl;
					zet[zet];
					zet.get_finanse2();
					cout << endl;
					cout << endl;
					cout << endl;
					kopia_bazy = zet;
					int zmienna_budzetowa = zet.get_finanse();
					Persona::getbaze()->usun();
					if (zmienna_budzetowa <= zero) {
						cout << "Niestety przegrales gre: " << endl;
						PlaySound(TEXT("Fail.wav"), NULL, SND_ASYNC);
						wait(szesc);
						n = zero;
					}
					Pod_menu(zmienna_budzetowa,Magazyn, kopia_bazy);
					
					p = zero;


				} while (p != zero);
				n = zero;

				break;
			case dwa:
				Gra.set_finanse();
				Gra.get_finanse();
				do {
					system("cls");
					a = Gra.get_finanse();
					Prod.Wybor_gatunku();
					do {
						z = Prod.Ustal_budzet(a);
						cout << a << endl;
						cout << z << endl;
						if (a < z)
							zm_budzet();
						else {
							Prod.M_time();
							Prod.set_tyt();
							Prod.get_gat();

							h = zero;
						}
					} while (h != zero);

					zatrudnij_obsade();
					z = Wybor_ekipy(z,Wartosci_ekipy);
					ogarnij_sprzet2();
					for (int g = zero; g < trzy; g++) {
						
							z = Wybor_sprzetu(z, Tabelka2[g], Magazyn, g, Schowek);
						
					}
					cout << "Marketing: " << endl;
					int suma_elementow=zero;
					int bud_mark = a + z - pocz;
					Marketing do_filmu;
					auto zmiej = rand() % stala;
					auto zwie = rand() % stala;
					Wplyw_M wply(zwie, zmiej);
					do_filmu.Rozdzial_budzetu_marketingowego(bud_mark);

				
					for (int i = zero; i < pietnascie; i++) {
						if (i < piec) {
							cout << Magazyn[i] << " To sa Magazyn: Kamery: " << i << endl;
							cout << endl;
						}
						else   if ((i >= piec) && (i < ten)) {
							cout << Magazyn[i] << " To sa Magazyn: Mikrofonu: " << i - piec << endl;
							cout << endl;
						}
						else {
							cout << Magazyn[i] << " To sa Magazyn: Efektow specjalnych " << i - ten << endl;
							cout << endl;
						}
					}

					for (vector<int>::iterator it = Schowek.begin(); it != Schowek.end(); ++it)
						suma_elementow += *it;
					Sprzet ca(suma_elementow);
					Budzet zet(&do_filmu, &wply, &ca, bud_mark,Wartosci_ekipy[jeden],Wartosci_ekipy[zero],Wartosci_ekipy[trzy],Wartosci_ekipy[dwa]);
					Budzet kopia_bazy;
					cout << endl;
					cout << endl;
					cout << zet;
					zet.nowy_finanse_2(a);
					cout << zet;
					cout << endl;
					cout >> zet;
					cout << zet;
					cout << endl;
					zet(zet);
					cout << endl;
					cout << zet;
					cout << endl;
					zet[zet];
					cout << endl;
					cout << endl;
					cout << endl;
					kopia_bazy = zet;
					int zmienna_budzetowa = zet.get_finanse();
					Persona::getbaze()->usun();
					if (zmienna_budzetowa <= zero) {
						cout << "Niestety przegrales gre: " << endl;
						PlaySound(TEXT("Fail.wav"), NULL, SND_ASYNC);
						wait(szesc);
						n = zero;
					}
					Pod_menu(zmienna_budzetowa,Magazyn,kopia_bazy);
					
					p = zero;

				} while (p != zero);
				n = zero;
				break;
			case 3:

				Menu_pierwszy_wybor_uzytkownika();
				n = zero;
				break;
			default:
				n = zero;
				break;
			}

		} while (n != zero);
	}

void Pod_menu(int bud, vector<int>& Magazyn,Budzet& Pierwszy) {
	int warunek = jeden, p = jeden, wybor = zero, z, h = jeden, pocz = zero;
	array<string, trzy> Tabelka2{ "Kamera","Mikrofon","Efekty specjalne" };
	float a;
	char ch;
	vector<int>Schowek;
	vector<int> Wartosci_ekipy;
	for (int i = zero; i < cztery; i++) {
		Wartosci_ekipy.push_back(zero);
	}
	for (int i = zero; i < pietnascie; i++) {
		Schowek.push_back(zero);
		if (i < piec) {
			cout << Magazyn[i] << " To sa Magazyn: Kamery: " << i << endl;
			cout << endl;
		}
		else   if ((i >= piec) && (i < ten)) {
			cout << Magazyn[i] << " To sa Magazyn: Mikrofonu: " << i - piec << endl;
			cout << endl;
		}
		else {
			cout << Magazyn[i] << " To sa Magazyn: Efektow specjalnych " << i - ten << endl;
			cout << endl;
		}
	}
	for (int i = zero; i < pietnascie; i++) {
		
	}
	do {
		cout << "1. Tworze kolejny film" << endl;
		cout << "2."; powrot();
		while (true) {
			cin >> wybor;
			if (cin.fail()) {
				cin.clear();
				cin.ignore();
				cout << "Zly typ" << endl;
			}
			break;
		}
		ch = getchar();
		system("cls");
		switch (wybor) {
		case jeden:
			do {
				system("cls");
				Gra.nowy_finanse(bud);
				a = Gra.get_finanse();
				Prod.Wybor_gatunku();
				do {
					z = Prod.Ustal_budzet(a);
					pocz = z;
					cout << a << endl;
					cout << z << endl;
					if (a < z)
						zm_budzet();
					else {
						Gra.nowy_finanse(a - z);
						Prod.M_time();
						Prod.set_tyt();
						Prod.get_tyt();
						h = zero;
					}
				} while (h != zero);
				h = jeden;
				zatrudnij_obsade();
				z = Wybor_ekipy(z,Wartosci_ekipy);
				ogarnij_sprzet2();
				for (int g = zero; g < trzy; g++) {
		
					
						z = Wybor_sprzetu(z, Tabelka2[g], Magazyn, g, Schowek);
					
				}
				cout << "Marketing: " << endl;
				int suma_elementow = zero;
				int bud_mark = a + z - pocz;
				Marketing do_filmu(zero);
				auto zmiej = rand() % stala;
				auto zwie = rand() % stala;
				Wplyw_M wply(zwie, zmiej);
				do_filmu.Rozdzial_budzetu_marketingowego(bud_mark);

				for (int i = zero; i < pietnascie; i++) {
					if (i < piec) {
						cout << Magazyn[i] << " To sa Magazyn: Kamery: " << i << endl;
						cout << endl;
					}
					else   if ((i >= piec) && (i < ten)) {
						cout << Magazyn[i] << " To sa Magazyn: Mikrofonu: " << i - piec << endl;
						cout << endl;
					}
					else {
						cout << Magazyn[i] << " To sa Magazyn: Efektow specjalnych " << i - ten << endl;
						cout << endl;
					}
				}

				for (vector<int>::iterator it = Schowek.begin(); it != Schowek.end(); ++it)
					suma_elementow += *it;
				Sprzet ca(suma_elementow);
				Budzet zet(&do_filmu, &wply, &ca, bud_mark, Wartosci_ekipy[jeden], Wartosci_ekipy[zero], Wartosci_ekipy[trzy], Wartosci_ekipy[dwa]);
				zet.nowy_finanse_2(bud);
				cout << zet;
				cout << endl;
				cout >> zet;
				cout << zet;
				cout << endl;
				zet(zet);
				cout << endl;
				cout << zet;
				cout << endl;
				zet[zet];
				cout << endl;
				cout<<"Taka zmiana wzgledem pierwszego budzetu: "<< zet.get_finanse()- Pierwszy.get_finanse2()<<endl;
				cout << endl;
				int zmienna_budzetowa = zet.get_finanse();
				Persona::getbaze()->usun();
				bud = zmienna_budzetowa;
				if (bud <= zero) {
					system("cls");
					cout << "Niestety przegrales gre: " << endl;
					PlaySound(TEXT("Fail.wav"), NULL, SND_ASYNC);
					wait(szesc);
					warunek = zero;
				}
				wait(szesc);
				p = zero;


			} while (p != zero);

			break;
	
		case dwa:

			Menu_pierwszy_wybor_uzytkownika();
			warunek = zero;
			break;
		default:
			warunek = zero;
			break;
		}

	} while (warunek != zero);
}
}
