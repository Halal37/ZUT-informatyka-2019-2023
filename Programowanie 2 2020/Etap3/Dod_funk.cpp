#include "Dod_funk.h"
#include <iostream>
#define ten 10
using namespace std;
extern int e_rec, e_sna, e_pl, e_tra, e_bil, e_inte;
Film Prod;
Budzet Gra(200);
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

int jakas_funkcjaetap3(int z, string s) {
	srand(time(NULL));
	char ch;
	int k = 0, Rezy = 1,c=0,g=0,n=0,ur=0, prawdo=0;
	int ug = 0;
	Osoba etap3[ten];
	string imiona[29]{ "Martin","Steven","Quentin","Christopher","David","Wesley","Mel","Paolo","Xavier","James","John","Peter","Damien","Denis","Wojciech","Tim","Paul","Clint","Anthony","Taika","Robert","Jim","Guy","Sam","Darren","Alfonso","Terry","Edgar","Ridley" };
	string nazwiska[29]{ "Scorsese","Spilberg","Tarantino","Nolan","Fincher","Anderson","Lynch","Gibson","Sorrentino","Dolan","Cameron","Jackson","Chazelle","Villeneuve","Smarzowski","Burton","Eastwood","Russo","Zemeckis","Waititi","Jarmusch","Ritchie","Mendes","Cuaron","Aronofsky","Gilliam","Wright","Scott","Coen" };
	do {
		system("cls");
		//Tablica_rez.Rez();
		for (int i = 0; i < 10; i++) {
			etap3[i].set_gat (i * i);
			etap3[i].set_pen(i * i);
			etap3[i].set_prof (i * i);
			etap3[i].set_rep ( i * i);
			etap3[i].set_roz (i * i);
			if (i == 0) {
				cout << "Oferowany kandydat:" << endl;
				etap3[i].set_imie("Stazysta");
				etap3[i].set_nazwisko ("Stazysta");
			}
			else {
				c = rand() % 29;
				g = rand() % 29;
				etap3[i].set_imie(imiona[c]);
				etap3[i].set_nazwisko(nazwiska[g]);

			}//for (int i = 0; i < 10; i++) {

			//}
			for (int i = 0; i <ten; i++) {
				//cout << "Nr." << n << ": " << endl;
				n++;
				if ((n >= 91) && (n <= 100)) {
					wait(1);
					cout << "Nr." << n-90 << ": " << endl;
					Osoba Kopiaetap(etap3[i]);
					cout << Kopiaetap.get_gat();
					cout << endl;
					prawdo = rand() % 400;
					if(prawdo>50)
						Kopiaetap.set_rep((i * i )+ 5);
					cout << "Uznanie krytykow: " << Kopiaetap.get_rep() << "\t";
					cout << endl;
					cout << "Pobierana pensja w tysiacach: " << Kopiaetap.get_pen() << "\t";
					cout << endl;
					if ((prawdo > 50) || (prawdo < 4))Kopiaetap.set_roz(i + 16);
					cout << "Rozpoznawalnosc: " << Kopiaetap.get_roz() << "\t";
					cout << endl;
					if (prawdo < 100) Kopiaetap.set_prof(i * i * i);
					cout << "Profesjonalizm: " << Kopiaetap.get_prof() << "\t";
					cout << endl;
					cout << "Imie: " << Kopiaetap.get_imie() << "\t";
					cout << endl;
					cout << "Nazwisko: " << Kopiaetap.get_nazwisko() << "\t";
					cout << endl;
					
				}
		}

		}
		obecny_budzet(z);
		cout << "Ktorego " << s << " chcesz zatrudnic?" << endl;
		cin >> k;
		ch = getchar();
		k = k*k;
		if (z < k)
			zm_budzet();
		else {
			auto ort = z - k;
			cout << ort << endl;
			Prod.Nowy_budzet(ort);
			Prod.get_bud();
			z = ort;
			Rezy = 0;
		}
	} while (Rezy != 0);
	return z;

}
int do_marketingu(int bud) {
	int h = 1,era=0;
	do {
		cout << "Budzet marketingowy: " << endl;
		cin >> era;
		if ((bud < era) || era < 0)cout << "Zla wartosc" << endl;
		else h = 0;
	} while (h != 0);
	return era;
}
int do_marketing(int bud, string p) {
	int z = 1,rec=0;
	do {
		if (bud == 0) {
			rec = 0;
			z = 0;
		}
		else {
			cout << p << endl;;
			cin >> rec;
			if ((bud < rec) || (rec < 0))cout << "Zla wartosc" << endl;
			else {
				bud -= rec;
				z = 0;
			}
		}
	} while (z != 0);
	cout << rec << " :Taka wartosc" << endl;
	return rec;
}
int zmiana_budzetowa(int bud,int zm) {
	bud -= zm;
	return bud;
}
int jakas_funkcja_marketing_etap3(int bud) {
	int era = 0, rec = 0, sna = 0, pl = 0, tra = 0, bil = 0, inte = 0;
	string Tabela[6]{"Kupno recenzji: ","Reklamy na sniadaniowkach: ","Plakaty: ", "Trailery: ", "Bilb: ", "Kampania internetowa: " };
	int h = 1,z=1,k=1,nas=1,kar=1,pol=1,per=1; //kontrolki 
	cout << "Zostalo tyle w budzetcie studia: " << endl;
	cout << bud << endl;
	era=do_marketingu(bud);
	rec=do_marketing(era, Tabela[0]);
	era = zmiana_budzetowa(era, rec);

	sna = do_marketing(era, Tabela[1]);
	era = zmiana_budzetowa(era, sna);

	pl = do_marketing(era, Tabela[2]);
	era = zmiana_budzetowa(era, pl);

	tra = do_marketing(era, Tabela[3]);
	era = zmiana_budzetowa(era, tra);

	bil = do_marketing(era, Tabela[4]);
	era = zmiana_budzetowa(era, bil);

	inte = do_marketing(era, Tabela[5]);
	era = zmiana_budzetowa(era, inte);
//	e_rec = rec;

	Marketing Wartosc(rec,sna,pl,tra,bil,inte);
	Wplyw_M kok(13, 16);
//	Agregacja C;
//	Agregacja KopiaC(C);
	int sprawdzak = 0;
	Budzet buda;
	sprawdzak = buda.zmiana_marketingowa(Wartosc, bud);
	cout << sprawdzak << " Tyle zostalo budzetu" << endl;
	era=Sedzia(Wartosc, kok);
	return era;
}

int jakas_funkcja2etap3(int z, string s) {
	int k = 0, zmienna = 0, kamera = 1,n=1;
	char ch, zn;
	Sprzet Golem[5];
	do {
		//system("cls");
		for (int i = 0; i < 5; i++) {
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
		n = (5 * n * n);//kupno
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
					kamera = 0;
					n = 0;
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
					kamera = 0;
					n = 0;
				}
				break;
			default:
				cout << "Podana zla wartosc" << endl;
				n = 0;
				break;
				
			}
		} while (n != 0);
	} while (kamera != 0);
	return z;
}
int jakas_funkcja2etap3(int z, string s,Budzet buda) {
	int k = 0, zmienna = 0, kamera = 1, n = 1,zwra=0,za=0;
	char ch, zn;
	Sprzet Golem[5];
	do {
		system("cls");
		//system("cls");
		for (int i = 0; i < 5; i++) {
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
		n = (5 * n * n);//kupno
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
					kamera = 0;
					n = 0;
					zwra = buda.zmiana_sprzetowa(Golem[cz], za,1);
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
					kamera = 0;
					n = 0;
				 zwra=buda.zmiana_sprzetowa(Golem[cz], za);
				 cout << zwra << " Tyle zwraca " << endl;
				}
				break;
			default:
				cout << "Podana zla wartosc" << endl;
				n = 0;
				break;

			}
		} while (n != 0);
	} while (kamera != 0);
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
	int n = 1, wybor = 0;
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
			n = 0;

			break;
		case 2:
			//Na razie nic nie robi
			n = 0;
			break;
		case 3:
			ja();
			n = 0;
			break;
		case 0:
			n = 0;
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

	} while (n != 0);
}
void Wybor_opcji1_aetap2() {
	int n = 1, p = 1, wybor = 0, z, k = 0, h = 1,war=0,pocz=0;
	string Tabelka[8]{ "Rezysera","Scenarzyste","Operatora","Kompozytora","Montazyste","Scenografa","Kostiumografa","Dzwiekowca" };
	string Tabelka2[3]{ "Kamera","Mikrofon","Efekty specjalne" };
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
						h = 0;
					}
				} while (h != 0);
				h = 1;
				zatrudnij_obsade();

				for (int j = 0; j < 8; j++) {
					z = jakas_funkcjaetap3(z, Tabelka[j]);
				}
				system("cls");
				ogarnij_sprzet2();
				for (int g = 0; g < 3; g++) {
					wait(3);
					if (g == 2) {
						a =a+ jakas_funkcja2etap3(z, Tabelka[g], Gra);
					}
					else {
						z = jakas_funkcja2etap3(z, Tabelka2[g]);
					}
				}
				cout << "Marketing: " << endl;
				auto bud_mark = a - pocz;
				war = jakas_funkcja_marketing_etap3(bud_mark);
			//	cout << war << endl;
				p = 0;


			} while (p != 0);
			n = 0;

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

						h = 0;
					}
				} while (h != 0);

				zatrudnij_obsade();
				for (int j = 0; j < 8; j++) {
					z = jakas_funkcjaetap3(z, Tabelka[j]);
				}

				system("cls");
				ogarnij_sprzet2();
				for (int g = 0; g < 3; g++) {
					wait(3);
					if (g == 2) {
						a = jakas_funkcja2etap3(z, Tabelka[g], Gra);
					}
					else {
						z = jakas_funkcja2etap3(z, Tabelka2[g]);
					}
				}
				cout << "Marketing: " << endl;
				auto bud_mark = a - pocz;
				war = jakas_funkcja_marketing_etap3(bud_mark);
				//cout << war << endl;

				p = 0;

			} while (p != 0);
			n = 0;
			break;
		case 3:

			Wybor_opcji1etap3();
			n = 0;
			break;
		default:
			n = 0;
			break;
		}

	} while (n != 0);
}