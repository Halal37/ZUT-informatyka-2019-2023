#include "Kostiumograf.h"
#define stala 29
void Kostiumograf::set_rep(int s) {
	rep = s+3;
}
void Kostiumograf::set_gat(int s) {
	gat = s=2;
}
void Kostiumograf::set_pen(int s) {
	pen = s;
}
void Kostiumograf::set_roz(int s) {
	roz = s+7;
}
void Kostiumograf::set_prof(int s) {
	prof = s=1;
}
void Kostiumograf::set_imie(string s) { imie = s; }
void Kostiumograf::set_nazwisko(string s) { nazwisko = s; }
void Kostiumograf::stworz(int z)
{
	int c = 0, g = 0, prawdo = 0;

	array<string, stala> imiona{ "Martin","Steven","Quentin","Christopher","David","Wesley","Mel","Paolo","Xavier","James","John","Peter","Damien","Denis","Wojciech","Tim","Paul","Clint","Anthony","Taika","Robert","Jim","Guy","Sam","Darren","Alfonso","Terry","Edgar","Ridley" };
	array<string, stala> nazwiska{ "Scorsese","Spilberg","Tarantino","Nolan","Fincher","Anderson","Lynch","Gibson","Sorrentino","Dolan","Cameron","Jackson","Chazelle","Villeneuve","Smarzowski","Burton","Eastwood","Russo","Zemeckis","Waititi","Jarmusch","Ritchie","Mendes","Cuaron","Aronofsky","Gilliam","Wright","Scott","Coen" };
	prawdo = rand() % 400;
	if (prawdo > 373)
		set_rep(z -2);
	else set_rep(z);
	set_gat(z);
	set_pen(z);
	if ((prawdo > 498) || (prawdo < 2))set_roz(z * z * z*z*z);
	else set_roz(z);
	if (prawdo > 8) set_prof(z - 1);
	else set_prof(z);
	c = rand() % stala;
	g = rand() % stala;
	set_imie(imiona[c]);
	set_nazwisko(nazwiska[g]);
}

