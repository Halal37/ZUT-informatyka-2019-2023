#include "Rezyser.h"
#include <ctime>
#define stala 29
Zmiana_wplywow* Rezyser::wplywy;
void Rezyser::set_rep(int s) { rep = s*s; }
void Rezyser::set_gat(int s) { gat = s * s; }
void Rezyser::set_pen(int s) { pen = s * s; }
void Rezyser::set_roz(int s) { roz = s * s; }
void Rezyser::set_prof(int s) { prof = s * s; }
void Rezyser::set_imie(string s) { imie = s; }
void Rezyser::set_nazwisko(string s) { nazwisko = s; }
void Rezyser::stworz(int z)
{
	int c = 0, g = 0, prawdo = 0, licznik = 0;;
	zarezerwuj();
	set_wplyw();
	if (get_wplyw() > 0) {
		cout << "Dostales bonus: " << get_wplyw() << endl;
		licznik = get_wplyw();
	}
	string imiona[stala]{ "Martin","Steven","Quentin","Christopher","David","Wesley","Mel","Paolo","Xavier","James","John","Peter","Damien","Denis","Wojciech","Tim","Paul","Clint","Anthony","Taika","Robert","Jim","Guy","Sam","Darren","Alfonso","Terry","Edgar","Ridley" };
	string nazwiska[stala]{ "Scorsese","Spilberg","Tarantino","Nolan","Fincher","Anderson","Lynch","Gibson","Sorrentino","Dolan","Cameron","Jackson","Chazelle","Villeneuve","Smarzowski","Burton","Eastwood","Russo","Zemeckis","Waititi","Jarmusch","Ritchie","Mendes","Cuaron","Aronofsky","Gilliam","Wright","Scott","Coen" };
	prawdo = rand() % 400;
	if (prawdo > 50)
		set_rep((z) + 5);
		else set_rep(z);
	set_wplyw();
	if ((get_wplyw() > 0) && (licznik != get_wplyw())) {
		cout << "Dostales bonus:" << get_wplyw() << endl;
		licznik = get_wplyw();
	}
		set_gat(z+get_wplyw());
		set_pen(z);
		set_wplyw();
		if ((get_wplyw() > 0) && (licznik != get_wplyw())) {
			cout << "Dostales bonus:" << get_wplyw() << endl;
			licznik = get_wplyw();
		}
		if ((prawdo > 50) || (prawdo < 4))set_roz(z + 1+ get_wplyw());
		else set_roz(z+ get_wplyw());
		set_wplyw();
		if ((get_wplyw() > 0) && (licznik != get_wplyw())) {
			cout << "Dostales bonus:" << get_wplyw() << endl;
			licznik = get_wplyw();
		}
		if (prawdo < 100) set_prof(z * z + get_wplyw());
		else set_prof(z+ get_wplyw());
		c = rand() % stala;
		g = rand() % stala;
		set_imie(imiona[c]);
		set_nazwisko(nazwiska[g]);
		zwolnij();
		cout << "Oferowany kandydat:" << endl;
		cout << "Nr." << z << ": " << endl;
		cout << get_gat() << "\t";
		cout << endl;
		cout << "Uznanie krytykow: " << get_rep() << "\t";
		cout << endl;
		cout << "Pobierana pensja w tysiacach: " << get_pen() << "\t";
		cout << endl;
		cout << "Rozpoznawalnosc: " << get_roz() << "\t";
		cout << endl;
		cout << "Profesjonalizm: " << get_prof() << "\t";
		cout << endl;
		cout << "Imie: " << get_imie() << "\t";
		cout << endl;
		cout << "Nazwisko: " << get_nazwisko() << "\t";
		cout << endl;
}

