import time
class Ulamek:
    def __init__(self,a,b):
        self.__var1=a
        self.__var2=b
        pass
   # @classmethod
    def __str__(self):
        return str( self.__var1 ) + "/" + str( self.__var2 )
    def __mul__(self,other):
        return Ulamek(self.__var1*other.__var1,self.__var2*other.__var2)
    def nww(a,b):
        if(a<b):
            return nww(b,a)
        k=a
        while(k%b!=0):
            k+=a
        return k
    def __add__(self,other):
        wielo=nww(self.__var2,other.__var2)
        a=wielo/self.__var2
        b=wielo/other.__var2
        return Ulamek((self.__var1*a)+(other.__var1*b),wielo)
    def __sub__(self,other):
        wielo=nww(self.__var2,other.__var2)
        a=wielo/self.__var2
        b=wielo/other.__var2
        return Ulamek((self.__var1*a)-(other.__var1*b),wielo)
    def __truediv__(self,other):
        return Ulamek(self.__var1*other.__var2,self.__var2*other.__var1)

ulamek1=Ulamek(3,4)
ulamek2=Ulamek(4,3)
ulamek3=ulamek1/ulamek2
print(ulamek3)

class Osoba:
    pole_statyczne=0
    def __init__(self,pesel,imie,nazwisko,wzrost=0.0,waga=0.0):
        self.__pesel=str(pesel)
        self.__imie=str(imie)
        self.__nazwisko=str(nazwisko)
        self.__wzrost=wzrost
        self.__waga=waga
        self.liczba()
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
        return self.__pesel
    def __str__(self):
        return self.__pesel+', '+self.__imie+', '+self.__nazwisko
    def __repr__(self):
        return {'Pesel':self.__pesel,'Imie':self.__imie,'Nazwisko':self.__nazwisko}
    def wzrost(self,wartosc):
        self.__wzrost=wartosc
    def waga(self,wartosc):
        self.__waga=wartosc
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
os=Osoba('02311154321','Wojciech','Lidwin')
dane=os.rok_urodzenia()
print(dane)
print("Takie pole statyczne: ", Osoba.pole_statyczne)
os2=Osoba('04320454321','Kamil','Lidwin')
print("Takie pole statyczne: ", Osoba.pole_statyczne)
os3=Osoba('04320454321','Kamil','Lidwin')
print("Takie pole statyczne: ", Osoba.pole_statyczne)
del os3
print("Takie pole statyczne: ", Osoba.pole_statyczne)
ile_lat=os.wiek()
print(ile_lat)
print(os)
print(os.__repr__())
os4=Osoba.stworz_z_cm('04320454321','Kamil','Lidwin',171,68)
print(os4._Osoba__wzrost)

