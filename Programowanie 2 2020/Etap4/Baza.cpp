#include "Baza.h"

void Baza::stworz(Persona* osoba)
{
    Lista** temp = new Lista * [ilosc_osob + 1];
    //int size = sizeof(temp)/sizeof(temp[0]);
    //std::cout << "size ==  :" << size << std::endl;
    for (size_t i = 0; i < ilosc_osob; ++i)
        temp[i] = lista_osob[i];
    Lista* kart = new Lista{ osoba };
    temp[ilosc_osob] = kart;
    delete[] lista_osob;
    ++lista_osob;
    //size_t id_pacjeta = lista_osob;
  //  osoba->set_id_karty(id_pacjeta);
    //std::cout << "id karty :" << id_pacjeta << "\t" << osoba->get_id_karty() << std::endl;
    lista_osob = temp;
}

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
