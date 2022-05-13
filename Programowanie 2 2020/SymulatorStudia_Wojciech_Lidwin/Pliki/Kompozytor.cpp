#include "Kompozytor.h"
#define stala 29
void Kompozytor::set_rep(int s) {
	 rep = s;
}
void Kompozytor::set_gat(int s) {
	 gat = s;
}
void Kompozytor::set_pen(int s) {
	pen = s;
}
void Kompozytor::set_roz(int s) {
	 roz = s;
}
void Kompozytor::set_prof(int s) {
	prof = s;
}
void Kompozytor::set_imie(string s) { imie = s; }
void Kompozytor::set_nazwisko(string s) { nazwisko = s; }
void Kompozytor::stworz(int z)
{
	int c = 0, g = 0, prawdo = 0;

	array<string, stala> imiona{ "Martin","Steven","Quentin","Christopher","David","Wesley","Mel","Paolo","Xavier","James","John","Peter","Damien","Denis","Wojciech","Tim","Paul","Clint","Anthony","Taika","Robert","Jim","Guy","Sam","Darren","Alfonso","Terry","Edgar","Ridley" };
	array<string, stala> nazwiska{ "Scorsese","Spilberg","Tarantino","Nolan","Fincher","Anderson","Lynch","Gibson","Sorrentino","Dolan","Cameron","Jackson","Chazelle","Villeneuve","Smarzowski","Burton","Eastwood","Russo","Zemeckis","Waititi","Jarmusch","Ritchie","Mendes","Cuaron","Aronofsky","Gilliam","Wright","Scott","Coen" };
	prawdo = rand() % 400;
	if (prawdo > 344)
		set_rep((z)+4);
	else set_rep(z);
	set_gat(z);
	set_pen(z);
	if ((prawdo > 490) || (prawdo < 4))set_roz(z *z*z*z);
	else set_roz(z);
	if (prawdo > 130) set_prof(z * z);
	else set_prof(z);
	c = rand() % stala;
	g = rand() % stala;
	set_imie(imiona[c]);
	set_nazwisko(nazwiska[g]);
}
