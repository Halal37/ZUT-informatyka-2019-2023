#include "Operator.h"
#define stala 29
void Operator::set_rep(int s) {
	rep = s;
}
void Operator::set_gat(int s) {
	gat = s;
}
void Operator::set_pen(int s) {
	pen = s;
}
void Operator::set_roz(int s) {
	roz = s;
}
void Operator::set_prof(int s) {
	prof = s;
}
void Operator::set_imie(string s) { imie = s; }
void Operator::set_nazwisko(string s) { nazwisko = s; }
//srand(time(NULL));
void Operator::stworz(int z)
{
	int c = 0, g = 0, prawdo = 0;

	string imiona[stala]{ "Martin","Steven","Quentin","Christopher","David","Wesley","Mel","Paolo","Xavier","James","John","Peter","Damien","Denis","Wojciech","Tim","Paul","Clint","Anthony","Taika","Robert","Jim","Guy","Sam","Darren","Alfonso","Terry","Edgar","Ridley" };
	string nazwiska[stala]{ "Scorsese","Spilberg","Tarantino","Nolan","Fincher","Anderson","Lynch","Gibson","Sorrentino","Dolan","Cameron","Jackson","Chazelle","Villeneuve","Smarzowski","Burton","Eastwood","Russo","Zemeckis","Waititi","Jarmusch","Ritchie","Mendes","Cuaron","Aronofsky","Gilliam","Wright","Scott","Coen" };
	//for (int i = 0; i < z; i++) {
	prawdo = rand() % 400;
	if ((prawdo < 314)&&prawdo>216)
		set_rep((z)+10);
	else set_rep(z);
	set_gat(z);
	set_pen(z);
	if ((prawdo > 490) || (prawdo < 4))set_roz((z+3) * z * 3);
	else set_roz(z);
	if (prawdo < 494) set_prof(z + 2);
	else set_prof(z);
	c = rand() % stala;
	g = rand() % stala;
	set_imie(imiona[c]);
	set_nazwisko(nazwiska[g]);
	//} 

//	for (int i = 0; i < z; i++) {
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
	//}
}

void Operator::usun()
{

}