#include "Budzet.h"
#include <iostream>
using namespace std;
void Budzet::set_finanse() {
	finanse = 4000000;
}
void Budzet::set_finanse2() {
	finanse = 200;
}
double Budzet::get_finanse() const {
	cout << finanse << endl;
		return finanse;
}
void Budzet::nowy_finanse(int i) {
	finanse = i;
}


