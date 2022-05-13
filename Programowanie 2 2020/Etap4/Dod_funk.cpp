#include "Dod_funk.h"
#include <iostream>
enum{
zero= 0,
 jeden= 1,
 dwa= 2 ,
 trzy= 3,
 cztery= 4,
 piec= 5,
 szesc= 6,
 siedem= 7,
 dziewiec= 9,
 ten= 10,
 trzynascie= 13,
 czternascie= 14,
 pietnascie= 15,
 szescnascie= 16,
 dwadziescie= 20,
 trzydziesci= 30,
 czterdziesci= 40,
 piecdziesiat= 50,
 szescdziesiat= 60,
 siedemdziesiat= 70,
 osiem= 8,
 stala= 29,
 osiemdziesiat= 80,
 dzwiescie= 200
};
using namespace std;
Film Prod;
Budzet Gra(dzwiescie);
Osoba Tablica_rez;
void wait(int seconds)
{
	clock_t endwait;
	endwait = clock() + seconds * CLOCKS_PER_SEC;
	while (clock() < endwait) {}
}
static void menuwyp() {
	cout << "Menu" << endl;
}
static void powrot() {
	cout << "Powrot" << endl;
}
static void punkt1() {
	cout << "1.Zacznij gre" << endl;
}
static void punkt1_a(){//Rozwidlenie a punktu 1 
	cout << "Wybierz punkt startowy" << endl;
}
static void punkt1_a_a(){//Rozwidlenie a rozwidlenia a punktu 1 
	cout << "1.Poczatkujace studio" << endl;
}
static void punkt1_a_b(){//Rozwidlenie b rozwidlenia a punktu 1 
	cout << "2.Swiatowy potentant" << endl;
}
static void wyjscie() {
	cout << "0.Wyjdz z gry" << endl;
}
static void tworcy() {
	cout << "3.Tworcy" << endl;
}
static void punkt2() {
	cout << "2.Wczytaj gre" << endl;
}
static void ja() {
	cout << "Ja" << endl;
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


int korekcja_budzetu(int budzet, string s, int& zupka) {
	int Rezy = jeden, k = zero;
	char ch;
	do {
		obecny_budzet(budzet);
		cout << "Ktorego " << s << " chcesz zatrudnic?" << endl;
		cin >> k;
		ch = getchar();
		//k = k * k;
		if (budzet < k)
			zm_budzet();
		else {
			auto ort = budzet - k;
			cout << ort << endl;
			Prod.Nowy_budzet(ort);
			Prod.get_bud();
			budzet = ort;
			Rezy = zero;
		}
	} while (Rezy != zero);
	zupka = k;
	return budzet;
}
int korekcja_budzetu(int budzet, string s,int &zupka,Rezyser ha) {
	int Rezy = jeden, k = zero;
	char ch;
	do {
		obecny_budzet(budzet);
		cout << "Ktorego " << s << " chcesz zatrudnic?" << endl;
		cin >> k;
		ch = getchar();
		k = k * k;
		if (budzet < k)
			zm_budzet();
		else {
			auto ort = budzet - k;
			cout << ort << endl;
			Prod.Nowy_budzet(ort);
			Prod.get_bud();
			budzet = ort;
			Rezy = zero;
		}
	} while (Rezy != zero);
	zupka = k;
	return budzet;
}
int korekcja_budzetu(int budzet, string s, int& zupka,Scenarzysta ha) {
	int Rezy = jeden, k = zero;
	char ch;
	do {
		obecny_budzet(budzet);
		cout << "Ktorego " << s << " chcesz zatrudnic?" << endl;
		cin >> k;
		ch = getchar();
		if (k >= dwa) k = k - dwa;
		if (budzet < k)
			zm_budzet();
		else {
			auto ort = budzet - k;
			cout << ort << endl;
			Prod.Nowy_budzet(ort);
			Prod.get_bud();
			budzet = ort;
			Rezy = zero;
		}
	} while (Rezy != zero);
	zupka = k;
	return budzet;
}


int Wybor_ekipy(int budzet) {
	int numer_stringa = zero,wart=zero,suma=zero;
	string Tabelka[osiem]{ "Rezysera","Scenarzyste","Operatora","Kompozytora","Montazyste","Scenografa","Kostiumografa","Dzwiekowca" };
	int Tabelka_wartosci[osiem]{};
	Baza go_brrr;
	Operator oper[ten];
	Kompozytor kompozytor[ten];
	Monatzysta montazysta[ten];
	Scenograf scenograf[ten];
	Kostiumograf kostiumograf[ten];
	Dzwiekowiec dziewciekowiec[ten];
	Rezyser z[ten];
	Scenarzysta scen[ten];
	Persona* wsk[osiemdziesiat];
	for (int i = zero; i < osiemdziesiat; i++) {

		if (i < ten) {
			wsk[i] = &z[i];
			wsk[i]->stworz(i);

		}if (i == dziewiec) {
			budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart], z[i]);
			numer_stringa++;
			wart++;
			system("cls");
		}
		if ((i > dziewiec) && (i < dwadziescie)) {
			wsk[i] = &scen[i - ten];
			wsk[i]->stworz(i - ten);

		}if (i == 19) {
			budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart], scen[i-10]);
			numer_stringa++;
			wart++;
			system("cls");
		}
		if ((i > 19) && (i < trzydziesci)) {
			wsk[i] = &oper[i - dwadziescie];
			wsk[i]->stworz(i - dwadziescie);

		}if (i == stala) {
			budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart]);
			numer_stringa++;
			wart++;
			system("cls");
		}
		if ((i > stala) && (i < czterdziesci)) {
			wsk[i] = &kompozytor[i - trzydziesci];
			wsk[i]->stworz(i - trzydziesci);

		}if (i == 39) {
			budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart]);
			numer_stringa++;
			wart++;
			system("cls");
		}
		if ((i > 39) && (i < piecdziesiat)) {
			wsk[i] = &montazysta[i - czterdziesci];
			wsk[i]->stworz(i - czterdziesci);

		}if (i == 49){budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart]);
			numer_stringa++;
			wart++;
			system("cls"); }
		if ((i > 49) && (i < szescdziesiat)) {
			wsk[i] = &scenograf[i - piecdziesiat];
			wsk[i]->stworz(i - piecdziesiat);

		}if (i == 59) {
			budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart]);
			numer_stringa++;
			wart++;
			system("cls");
		}
		if ((i > 59) && (i < siedemdziesiat)) {
			wsk[i] = &kostiumograf[i - szescdziesiat];
			wsk[i]->stworz(i - szescdziesiat);

		}if (i == 69) {
			budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart]);
			numer_stringa++;
			wart++;
			system("cls");
		}
		if ((i > 69) && (i < osiemdziesiat)) {
			wsk[i] = &dziewciekowiec[i - siedemdziesiat];
			wsk[i]->stworz(i - siedemdziesiat);

		}if (i == 79) {
			budzet = korekcja_budzetu(budzet, Tabelka[numer_stringa], Tabelka_wartosci[wart]);
			numer_stringa++;
			wart++;
			system("cls");
		}
		go_brrr.stworz(wsk[i]);

	}
	cout << "Wybory: "<<endl<<"1:"<< endl;
	cout << sqrt(Tabelka_wartosci[zero]) << endl;
	cout << "2: " << endl;
	cout << Tabelka_wartosci[jeden]+2 << endl;
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
	go_brrr.usun();
	return budzet;
}

int do_marketingu(int bud) {
	int h = jeden,era=zero;
	do {
		cout << "Budzet marketingowy: " << endl;
		cin >> era;
		if ((bud < era) || era < zero)cout << "Zla wartosc" << endl;
		else h = zero;
	} while (h != zero);
	return era;
}
int do_marketing(int bud, string p) {
	int z = jeden,rec=zero;
	do {
		if (bud == zero) {
			rec = zero;
			z = zero;
		}
		else {
			cout << p << endl;;
			cin >> rec;
			if ((bud < rec) || (rec < zero))cout << "Zla wartosc" << endl;
			else {
				bud -= rec;
				z = zero;
			}
		}
	} while (z != zero);
	cout << rec << " :Taka wartosc" << endl;
	return rec;
}
int zmiana_budzetowa(int bud,int zm) {
	bud -= zm;
	return bud;
}

void Marketing::jakas_funkcja_marketing_etap3r(int bud) {
	int era = zero, rec = zero, sna = zero, pl = zero, tra = zero, bil = zero, inte = zero;
	string Tabela[szesc]{ "Kupno recenzji: ","Reklamy na sniadaniowkach: ","Plakaty: ", "Trailery: ", "Bilb: ", "Kampania internetowa: " };
	int h = jeden, z = jeden, k = jeden, nas = jeden, kar = jeden, pol = jeden, per = jeden; //kontrolki 
	cout << "Zostalo tyle w budzetcie studia: " << endl;
	cout << bud << endl;
	era = do_marketingu(bud);
	rec = do_marketing(era, Tabela[zero]);
	era = zmiana_budzetowa(era, rec);
	kupno = rec;
	sna = do_marketing(era, Tabela[jeden]);
	era = zmiana_budzetowa(era, sna);
	sniad = sna;
	pl = do_marketing(era, Tabela[dwa]);
	era = zmiana_budzetowa(era, pl);
	plakaty = pl;
	tra = do_marketing(era, Tabela[trzy]);
	era = zmiana_budzetowa(era, tra);
	trailer = tra;
	bil = do_marketing(era, Tabela[cztery]);
	era = zmiana_budzetowa(era, bil);
	bilb = bil;
	inte = do_marketing(era, Tabela[piec]);
	era = zmiana_budzetowa(era, inte);
	internet = inte;

}

int jakas_funkcja2etap3(int z, string s) {
	int k = zero, zmienna = zero, kamera = jeden,n=jeden;
	char ch, zn;
	Sprzet Golem[piec];
	do {
		for (int i = zero; i < piec; i++) {
			Golem[i].set_jakosc(i * i);
			Golem[i].get_jakosc();
			Golem[i].pokaz();
		}
		obecny_budzet(z);
		cout << s << endl;
		cout << "Jaki jest twoj wybor" << endl;
		cin >> k;
		ch = getchar();
		cout << "Chcesz wynajac, czy kupic?" << endl;
		cin >> zmienna;
		zn = getchar();
		auto n = k;
		k = k * k;//wynajem
		n = (piec * n * n);//kupno
		do {
			system("cls");
			switch (zmienna) {
			case 0:
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
			case 1:
				if (z < k)
					zm_budzet();
				else {
					auto ort = z -k;
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
int jakas_funkcja2etap3(int z, string s,Budzet buda) {
	int k = zero, zmienna = zero, kamera = jeden, n = jeden,zwra=zero,za=zero;
	char ch, zn;
	Sprzet Golem[piec];
	do {
		system("cls");
		//system("cls");
		for (int i = zero; i < piec; i++) {
			Golem[i].set_jakosc(i * i);
			Golem[i].get_jakosc();
			Golem[i].pokaz();
		}
		obecny_budzet(z);
		cout << s << endl;
		cout << "Jaki jest twoj wybor" << endl;
		cin >> k;
		auto cz = k;
		ch = getchar();
		cout << "Chcesz wynajac, czy kupic?" << endl;
		cin >> zmienna;
		zn = getchar();
		auto n = k;
		k = k * k;//wynajem
		n = (piec * n * n);//kupno
		do {
			switch (zmienna ) {
			case 0:
				cout << n << endl;
				if (z < n)
					zm_budzet();
				else {
					za = z;
					auto ort = z - n;
					cout << ort << endl;
					Prod.Nowy_budzet(ort);
					Prod.get_bud();
					z = ort;
					kamera = zero;
					n = zero;
				
					cout << zwra << " Tyle zwraca " << endl;
				}
				break;
			case 1:
				if (z < k)
					zm_budzet();
				else {
					za = z;
					auto ort = z - k;
					cout << ort << endl;
					Prod.Nowy_budzet(ort);
					Prod.get_bud();
					z = ort;
					kamera = zero;
					n = zero;
			
				 cout << zwra << " Tyle zwraca " << endl;
				}
				break;
			default:
				cout << "Podana zla wartosc" << endl;
				n = zero;
				break;

			}
		} while (n != zero);
	} while (kamera != zero);
	return zwra;
}


int* Dynamiczna_tablica(int* tablica, int& ilosc)
{
	ilosc++;

	int* temp = new int[ilosc ];

	for (int i = 0; i < ilosc ; i++)
	{
		temp[i] = tablica[i];
	}

	delete[]tablica;

	return temp;
}



void Menuetap3() {
	Wybor_opcji1etap3();
}
void Wybor_opcji1etap3() {
	int n = jeden, wybor = zero;
	char ch;
	do {

		menuwyp();
		punkt1();
		punkt2();
		tworcy();
		wyjscie();

		cin >> wybor;
		ch = getchar();
		system("cls");
		switch (wybor) {
		case 1:
			punkt1_a();
			Wybor_opcji1_aetap2();
			n = zero;

			break;
		case 2:
			//Na razie nic nie robi
			n = zero;
			break;
		case 3:
			ja();
			n = zero;
			break;
		case 0:
			n = zero;
			break;
		default:
			cout << "Podana zla wartosc" << endl;
			menuwyp();
			punkt1();
			punkt2();
			tworcy();
			wyjscie();
			while ((ch = getchar()) != '\n');
			break;
		}

	} while (n != zero);
}
void Wybor_opcji1_aetap2() {
	int n = jeden, p = jeden, wybor = zero, z, k = zero, h = jeden,war=zero,pocz=zero;
	string Tabelka[osiem]{ "Rezysera","Scenarzyste","Operatora","Kompozytora","Montazyste","Scenografa","Kostiumografa","Dzwiekowca" };
	string Tabelka2[trzy]{ "Kamera","Mikrofon","Efekty specjalne" };
	float a;
	char ch;
	do {
		punkt1_a_a();
		punkt1_a_b();
		cout << "3."; powrot();
		cin >> wybor;
		ch = getchar();
		system("cls");
		switch (wybor) {
		case 1:
			do {
				system("cls");
				Gra.set_finanse2();
				Gra.get_finanse();
				a = Gra.get_finanse();
				Prod.Wybor_gatunku();
				do {
					z = Prod.Ustal_budzet();
					 pocz= z;
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
				z = Wybor_ekipy(z);
				/*for (int j = 0; j < 8; j++) {
					z = jakas_funkcjaetap3(z, Tabelka[j]);
				}*/
				system("cls");
				ogarnij_sprzet2();
				for (int g = zero; g < trzy; g++) {
					//wait(3);
					if (g == dwa) {
					//	a =a+ jakas_funkcja2etap3(z, Tabelka[g], Gra);
					}
					else {
						z = jakas_funkcja2etap3(z, Tabelka2[g]);
					}
				}
				cout << "Marketing: " << endl;
				auto bud_mark = a +z- pocz;
				Marketing do_filmu(zero);
				auto zmiej = rand() % stala;
				auto zwie = rand() % stala;
				Wplyw_M wply(zwie, zmiej);
				do_filmu.jakas_funkcja_marketing_etap3r(bud_mark);
				Sprzet ca(szesc);
				Budzet zet(&do_filmu, &wply, &ca, bud_mark);
				Budzet kopia(zet);
				kopia.Odjecie_wplywow();
				kopia.get_finanse();
				kopia.Budzet_pofilmie();
				kopia.get_finanse();
				//war = jakas_funkcja_marketing_etap3(bud_mark);
			//	cout << war << endl;
				p = zero;


			} while (p != zero);
			n = zero;

			break;
		case 2:
			Gra.set_finanse();
			Gra.get_finanse();
			do {
				system("cls");
				a = Gra.get_finanse();
				Prod.Wybor_gatunku();
				do {
					z = Prod.Ustal_budzet();
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
				z = Wybor_ekipy(z);
				/*for (int j = 0; j < 8; j++) {
					z = jakas_funkcjaetap3(z, Tabelka[j]);
				}*/

				system("cls");
				ogarnij_sprzet2();
				for (int g = zero; g < trzy; g++) {
					wait(trzy);
					if (g == dwa) {
					//	a = jakas_funkcja2etap3(z, Tabelka[g], Gra);
					}
					else {
						z = jakas_funkcja2etap3(z, Tabelka2[g]);
					}
				}
				cout << "Marketing: " << endl;
				auto bud_mark = a+z - pocz;
				Marketing do_filmu;
				auto zmiej= rand() % stala;
				auto zwie= rand() % stala;
				Wplyw_M wply(zwie, zmiej);
				do_filmu.jakas_funkcja_marketing_etap3r(bud_mark);
				Sprzet ca(szesc);
				Budzet zet(&do_filmu, &wply, &ca, bud_mark);
				Budzet kopia(zet);
				zet.Odjecie_wplywow();
				zet.get_finanse();
				//war = jakas_funkcja_marketing_etap3(bud_mark);
				//cout << war << endl;

				p = zero;

			} while (p != zero);
			n = zero;
			break;
		case 3:

			Wybor_opcji1etap3();
			n = zero;
			break;
		default:
			n = zero;
			break;
		}

	} while (n != zero);
}