#include "Agregacja.h"
#include "Marketing.h"
#include <iostream>
using namespace std;
Agregacja :: Agregacja() { a = new Wplyw_M(13,16); }
Agregacja::Agregacja(const Agregacja& d)
    : a(new Wplyw_M(d.a->zwie)) {
    int k = 0;
    k = d.a->zwie - d.a->zmie;
    cout << k << " :To Poziom wplywu(roznica dodatnich i negatywnych wplywow)" << endl;
}
 Agregacja :: ~Agregacja() { delete a; }