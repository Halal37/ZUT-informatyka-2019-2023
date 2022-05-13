#include "Baza.h"
//Tworzy lub zwieksza baze osob, rezerwuje pamiec
void Baza::stworz(Persona* osoba)
{
    
    Lista** temp = new Lista * [ilosc_osob + 1];
    for (size_t i = 0; i < ilosc_osob; ++i)
        temp[i] = lista_osob[i];
    Lista* kart = new Lista{ osoba };
    temp[ilosc_osob] = kart;
    delete[] lista_osob;
    ++lista_osob;
    ++ilosc_osob;
    lista_osob = temp;
}
//Wyswietlenie pojedynczej osoby
void Baza::wyswietl() {
    int i = 0; 
    cout << "Oferowany kandydat:" << endl;
    cout << i<<" Obserwowanie i:" << endl;
    cout << lista_osob[i]->get_gat() << "\t";
    cout << endl;
    cout << "Uznanie krytykow: " << lista_osob[i]->get_rep() << "\t";
    cout << endl;
    cout << "Pobierana pensja w tysiacach: " << lista_osob[i]->get_pen() << "\t";
    cout << endl;
    cout << "Rozpoznawalnosc: " << lista_osob[i]->get_roz() << "\t";
    cout << endl;
    cout << "Profesjonalizm: " << lista_osob[i]->get_prof() << "\t";
    cout << endl;
    cout << "Imie: " << lista_osob[i]->get_imie() << "\t";
    cout << endl;
    cout << "Nazwisko: " << lista_osob[i]->get_nazwisko() << "\t";
    cout << endl;
}

void Baza::wyswietl(int i) {
 //   int i = 0;
    cout << "Oferowany kandydat:" << endl;
    cout <<"Dostosowanie do gatunkow: "<< lista_osob[i]->get_gat() << "\t";
    cout << endl;
    cout << "Uznanie krytykow: " << lista_osob[i]->get_rep() << "\t";
    cout << endl;
    cout << "Pobierana pensja w tysiacach: " << lista_osob[i]->get_pen() << "\t";
    cout << endl;
    cout << "Rozpoznawalnosc: " << lista_osob[i]->get_roz() << "\t";
    cout << endl;
    cout << "Profesjonalizm: " << lista_osob[i]->get_prof() << "\t";
    cout << endl;
    cout << "Imie: " << lista_osob[i]->get_imie() << "\t";
    cout << endl;
    cout << "Nazwisko: " << lista_osob[i]->get_nazwisko() << "\t";
    cout << endl;
    cout << endl;
}

//Wyswietlenie calej listy osob
void Baza::wyswietl_all() {
    cout << ilosc_osob<<endl;
    for (int i = 0; i < ilosc_osob; i++) {
        cout << endl;
         cout << "Numer osoby w bazie: " << i << endl;
         cout << endl;
        cout << lista_osob[i]->get_gat() << "\t";
        cout << endl;
        cout << "Uznanie krytykow: " << lista_osob[i]->get_rep() << "\t";
        cout << endl;
        cout << "Pobierana pensja w tysiacach: " << lista_osob[i]->get_pen() << "\t";
        cout << endl;
        cout << "Rozpoznawalnosc: " << lista_osob[i]->get_roz() << "\t";
        cout << endl;
        cout << "Profesjonalizm: " << lista_osob[i]->get_prof() << "\t";
        cout << endl;
        cout << "Imie: " << lista_osob[i]->get_imie() << "\t";
        cout << endl;
        cout << "Nazwisko: " << lista_osob[i]->get_nazwisko() << "\t";
        cout << endl;
    }
}
int Baza::get_rep(int i) {
    return lista_osob[i]->get_rep();
}
int Baza::get_gat(int i) {
    return lista_osob[i]->get_gat();
}
int Baza::get_roz(int i) {
    return lista_osob[i]->get_roz();
}
int Baza::get_prof(int i) {
    return lista_osob[i]->get_prof();
}

//Usuniecie calej listy osob
void Baza::usun()
{
    for (size_t i = 0; i < ilosc_osob; ++i) {
        delete lista_osob[i];
    }
    delete[] lista_osob;
    lista_osob = nullptr;
    ilosc_osob = 0;
    cout << "Usuniety jestes typie" << endl;

}
//Usuniecie konkretnej osoby
void Baza::usun(int z)
{
if (z < ilosc_osob) {
    Lista** temp = new Lista * [ilosc_osob - 1];
    short int j{ -1 };
    for (int i = 0; i <ilosc_osob ; ++i)
        if (i != z) {
            
            ++j;
            temp[j] = lista_osob[i];
        }

        delete[] lista_osob;
        --ilosc_osob;
        lista_osob = temp;
    }
else
cout << "Index jest nieprawidlowy" << endl;
}
Baza::~Baza()
{
    usun();
    if (lista_osob == nullptr) {
        cout << "Baza usunieta prawidlowo" << endl;
    }
    else {
        cout << "Baza: Cos sie popsulo" << endl;
        
    }


}
//Zwraca zmienna string o nazwie imie
string Lista::get_imie() const {
    return osoba->get_imie();
}
//Zwraca zmienna string o nazwie nazwisko
string Lista::get_nazwisko() const {
    return osoba->get_nazwisko();
}
//Zwraca zmienna int o nazwie gat
int Lista::get_gat() const {
    return osoba->get_gat();
}
//Zwraca zmienna int o nazwie pen
int Lista::get_pen() const {
    return osoba->get_pen();
}
//Zwraca zmienna int o nazwie prof
int Lista::get_prof() const {
    return osoba->get_prof();
}
//Zwraca zmienna int o nazwie rep
int Lista::get_rep() const{
    return osoba->get_rep();
}
//Zwraca zmienna int o nazwie roz
int Lista::get_roz() const{
    return osoba->get_roz();
}
Baza Baza:: operator=(Baza const& d) {
    if (&d != this) {
        for (size_t i = 0; i < ilosc_osob; ++i) {
            delete lista_osob[i];
        }
        delete[] lista_osob;
        lista_osob = nullptr;
        ilosc_osob = d.ilosc_osob;
        //ilosc_kolumn = d.ilosc_kolumn;
       lista_osob = new Lista*[ilosc_osob];
        assert(lista_osob != 0);
        for (int i = 0; i < ilosc_osob; i++)
            lista_osob[i] = d.lista_osob[i];
    }
    return *this;
}
