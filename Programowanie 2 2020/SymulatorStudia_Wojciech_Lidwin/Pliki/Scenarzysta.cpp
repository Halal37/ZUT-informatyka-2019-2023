#include "Scenarzysta.h"
#define stala 29
void Scenarzysta::set_rep(int s) {
	if (s < 2) rep = s;
		else rep = s -1; }
void Scenarzysta::set_gat(int s) {
	if (s < 2) gat = s;
	else gat = s -2; }
void Scenarzysta::set_pen(int s) {
	if (s < 2)pen = s;
	else pen = s -2; }
void Scenarzysta::set_roz(int s) {
	if (s < 2) roz = s;
	else roz = s -2; }
void Scenarzysta::set_prof(int s) {
	if (s < 2) prof = s;
	else prof = s -2; }
void Scenarzysta::set_imie(string s) { imie = s; }
void Scenarzysta::set_nazwisko(string s) { nazwisko = s; }
void Scenarzysta::stworz(int z)
{
	int c = 0, g = 0, prawdo = 0;

	array<string, stala> imiona{ "Martin","Steven","Quentin","Christopher","David","Wesley","Mel","Paolo","Xavier","James","John","Peter","Damien","Denis","Wojciech","Tim","Paul","Clint","Anthony","Taika","Robert","Jim","Guy","Sam","Darren","Alfonso","Terry","Edgar","Ridley" };
	array<string, stala> nazwiska{ "Scorsese","Spilberg","Tarantino","Nolan","Fincher","Anderson","Lynch","Gibson","Sorrentino","Dolan","Cameron","Jackson","Chazelle","Villeneuve","Smarzowski","Burton","Eastwood","Russo","Zemeckis","Waititi","Jarmusch","Ritchie","Mendes","Cuaron","Aronofsky","Gilliam","Wright","Scott","Coen" };
	prawdo = rand() % 400;
	if (prawdo > 350)
		set_rep((z)+5);
	else set_rep(z);
	set_gat(z);
	set_pen(z);
	if ((prawdo > 490) || (prawdo < 4))set_roz(z + 7);
	else set_roz(z);
	if (prawdo > 130) set_prof(z * z);
	else set_prof(z);
	c = rand() % stala;
	g = rand() % stala;
	set_imie(imiona[c]);
	set_nazwisko(nazwiska[g]);

}

void Scenarzysta::usun()
{

}