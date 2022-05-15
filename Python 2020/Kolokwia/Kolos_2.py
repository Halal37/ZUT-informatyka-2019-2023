#zad1 
class Szafa():
    def __init__(self,wysokosc,szerokosc,dlugosc):
        self.__wysokosc=None
        self.wysokosc=wysokosc
        self.__szerokosc=None
        self.szerokosc=szerokosc
        self.__dlugosc=None
        self.dlugosc=dlugosc
    @property
    def wysokosc(self):
        return self.__wysokosc
    @wysokosc.setter
    def wysokosc(self,value):
        if(value<0):
            self.__wysokosc=0
        else:
            self.__wysokosc=value
    @property
    def szerokosc(self):
        return self.__szerokosc
    @szerokosc.setter
    def szerokosc(self,value):
        if(value<0):
            self.__szerokosc=0
        else:
            self.__szerokosc=value
    @property
    def dlugosc(self):
        return self.__dlugosc
    @dlugosc.setter
    def dlugosc(self,value):
        if(value<0):
            self.__dlugoscc=0
        else:
            self.__dlugosc=value
#zad2
class Domek(Szafa):
    def __init__(self,wysokosc,szerokosc,dlugosc, liczba_kondygnacji,liczba_okien=0):
        super().__init__(wysokosc,szerokosc,dlugosc)
        self.__liczba_kondygnacji=liczba_kondygnacji
        self.__liczba_okien=liczba_okien
    def __str__(self):
        return "Domek-liczba kondygnacji wynosi "+ str(self.__liczba_kondygnacji)
#zad3
from abc import ABC, abstractmethod
class Pojazd():
    @abstractmethod
    def __init__(self,kolo):
       if  isinstance(kolo, int):
            self.kolo = kolo
       else:
           raise TypeError("Zly typ danych")
    @abstractmethod
    def usun_kolo(self):
        self.kolo=self.kolo-1
class Rower(Pojazd):
    def __init__(self,kolo=2):
        super().__init__(kolo)
    def usun_kolo(self):
           super().usun_kolo()
class Samochod(Pojazd):
    def __init__(self,kolo=4,pojemnosc_silnika=200):
       if  isinstance(kolo, int):
            self.kolo = kolo
       else:
           raise TypeError("Zly typ danych")
       if  isinstance(pojemnosc_silnika, int):
            self.pojemnosc_silnika = pojemnosc_silnika
       else:
           raise TypeError("Zly typ danych")
       def usun_kolo(self):
        super().usun_kolo()
domek=Domek(3,4,5,5,6)
print(domek)
rower=Rower()
rower.usun_kolo();
print(rower.kolo)