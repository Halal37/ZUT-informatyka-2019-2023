import time
class Osoba:
    pole_statyczne=0
    def __init__(self,pesel,imie,nazwisko,wzrost=0.0,waga=0.0):
        self.__pesel=pesel
        self.__imie=imie
        self.__nazwisko=nazwisko
        self.__wzrost=None
        self.wzrost=wzrost
        self.__waga=None
        self.waga=waga
        self.liczba()
    @property
    def wzrost(self):
        return self.__wzrost
    @wzrost.setter
    def wzrost(self,value):
        if(value<0):
            self.__wzrost=0
        else:
            self.__wzrost=value
    @property
    def waga(self):
        return self.__waga
    @waga.setter
    def waga(self,value):
        if(value<0):
            self.__waga=0
        else:
            self.__waga=value
    @property
    def pesel(self):
        return self.__pesel
    @property
    def imie(self):
        return self.__imie
    @property
    def nazwisko(self):
        return self.__nazwisko
    @staticmethod
    def liczba():
        Osoba.pole_statyczne+=1
    def __del__(self):
        Osoba.pole_statyczne-=1
        del self

    def rok_urodzenia(self):
       es=int(self.__pesel[2])
       if(es==8 or es==9):
           rok=1800
       elif(es==0 or es==1):
           rok=1900
       elif(es==2 or es==3):
           rok=2000
       elif(es==4 or es==5):
           rok=2100
       elif(es==6 or es==7):
           rok=2200
       pierw_rok=int(self.__pesel[0])*10
       drugi_rok=int(self.__pesel[1])
       rok=rok+pierw_rok+drugi_rok
       return int(rok)
    def __hash__(self):
        return hash(self.__pesel)
    #     return hash(self.__repr__())
    def __eq__(self,other):
        if isinstance(other, Osoba):
            return ((self.__pesel == other.__pesel))
        else:
            return False
    def __str__(self):
        return self.__pesel+', '+self.__imie+', '+self.__nazwisko
    def __repr__(self):
        return {'Pesel':self.__pesel,'Imie':self.__imie,'Nazwisko':self.__nazwisko}
    @property
    def wiek(self):
       rok=self.rok_urodzenia()
       zycie=0
       es=int(self.__pesel[2])
       if(es==8 or es==0 or es==2 or es==4 or es==6):
           mie=0
       elif(es==9 or es==1 or es==3 or es==5 or es==7):
           mie=1
       miesiac=str(str(mie)+self.__pesel[3])
       dzien=str(self.__pesel[4]+self.__pesel[5])
       obecna_data=time.strftime("%Y%m%d",time.localtime())
       obecny_rok=int(str(obecna_data[0]+obecna_data[1]+obecna_data[2]+obecna_data[3]))
       obecny_miesiac=str(obecna_data[4]+obecna_data[5])
       obecny_dzien=str(obecna_data[6]+obecna_data[7])
       zycie=obecny_rok-rok
       if(miesiac>obecny_miesiac):
           zycie=zycie-1
       elif(miesiac==obecny_miesiac):
           if(dzien>obecny_dzien):
               zycie=zycie-1
       return zycie
    @classmethod
    def stworz_z_cm(cls,pesel,imie,nazwisko,wzrost,waga):
       return cls(str(pesel),str(imie),str(nazwisko),float(wzrost/100),float(waga))
os=Osoba('02311154321','Kamil','Slimak',-1.50,16)
#os.wzrost=-160
print(os.wzrost)
dane=os.rok_urodzenia()
print(dane)
print("Takie pole statyczne: ", Osoba.pole_statyczne)
os2=Osoba('04320454321','Wojciech','Lidwin')
print("Takie pole statyczne: ", Osoba.pole_statyczne)
os3=Osoba('04320457621','Piotr','Lotr')
print("Takie pole statyczne: ", Osoba.pole_statyczne)
#del os3
print("Takie pole statyczne: ", Osoba.pole_statyczne)
ile_lat=os.wiek
print(ile_lat)
print(os)
print(os._Osoba__wzrost)
print(os.__repr__())
os4=Osoba.stworz_z_cm('04320484329','Pawel','Gawel',171,68)
print(os4._Osoba__wzrost)
#zad2
class Pracownik(Osoba):
    def __init__(self,pesel,imie,nazwisko,miejsce_zatrudnienia,wzrost=0.0,waga=0.0,pensja=0.0):
        super().__init__(pesel,imie,nazwisko,wzrost=0.0,waga=0.0)
        self.__miejsce_zatrudnienia=miejsce_zatrudnienia
        self.__pensja=pensja
    @property
    def miejsce_zatrudnienia(self):
        return self.__miejsce_zatrudnienia
    @property
    def pensja(self):
        return self.__pensja
    @pensja.setter
    def pensja(self,value):
        if(value<0):
            self.__pensja=0
        else:
            self.__pensja=value
    def __str__(self):
       return self.pesel+', '+self.imie+', '+self.nazwisko+', '+self.__miejsce_zatrudnienia
    def __repr__(self):
        return {'Pesel':self.pesel,'Imie':self.imie,'Nazwisko':self.nazwisko,"Miejsce Zatrudnienia":self.__miejsce_zatrudnienia}
pracownik=Pracownik('02311154371','Wojciech','Lidwin',"Huta",-1.50,16,2000)
os5=Osoba('01322734183','Alicja','Galicja')
pracownik_2=Pracownik('96022341649','Konstancja','Francja','Kwiaciarnia')
pracownik_3=Pracownik('47041095864','Emilia','Imponderabilia','Muzeum Lotnictwa')
print(pracownik.__repr__())
print(pracownik.__str__())
#zad3
baza=set([os])
baza.add(os2)
baza.add(os3)
baza.add(os4)
baza.add(os5)
baza.add(pracownik)
baza.add(pracownik_2)
baza.add(pracownik_3)
for i in baza:
    print(i.__repr__())
#zad4
from abc import ABC, abstractmethod
import math
class Figura(ABC):
    @abstractmethod
    def oblicz_pole(self):
        pass
    @abstractmethod
    def typ_figury(self):
        pass
    def print(self):
        print('Figura: ', self.typ_figury(), ', Pole:', self.oblicz_pole())
class Trojkat(Figura):
    def __init__(self,a,b,c):
       if  isinstance(a, (int, float)):
            self.a = a
       else:
           raise TypeError("Zly typ danych, 1 wartosc")
       if  isinstance(b, (int, float)):
            self.b = b
       else:
           raise TypeError("Zly typ danych, 2 wartosc")
       if  isinstance(c, (int, float)):
            self.c = c
       else:
           raise TypeError("Zly typ danych, 3 wartosc")
    @property
    def a(self):
        return self.__a
    @a.setter
    def a(self,value):
        if(value<0):
            self.__a=0
        else:
            self.__a=value
    @property
    def b(self):
        return self.__b
    @b.setter
    def b(self,value):
        if(value<0):
            self.__b=0
        else:
            self.__b=value
    @property
    def c(self):
        return self.__c
    @c.setter
    def c(self,value):
        if(value<0):
            self.__c=0
        else:
            self.__c=value
    def oblicz_pole(self):
        p=(self.a+self.b+self.c)/2
        return math.sqrt(p*(p-self.a)*(p-self.b)*(p-self.c))
    def typ_figury(self):
        return 'Trojkat'
class Kolo(Figura):
    def __init__(self,r):
       if  isinstance(r, (int, float)):
            self.r = r
       else:
           raise TypeError("Zly typ danych")

    @property
    def r(self):
        return self.__r
    @r.setter
    def r(self,value):
        if(value<0):
            self.__r=0
        else:
            self.__r=value
    def oblicz_pole(self):
     return 3.14*self.r**2
    def typ_figury(self):
     return 'Kolo'
trojkat=Trojkat(4,4,4)
print(trojkat.oblicz_pole())
print(trojkat.typ_figury())
kolo=Kolo(5.12)
print(kolo.oblicz_pole())
print(kolo.typ_figury())
#zad5
