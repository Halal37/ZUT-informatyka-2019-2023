#Zad1
def funkcja(wartosc):
    print(wartosc/3600," godzin")
    print(wartosc/60," minut")
    print(wartosc," sekund")
#    return (wartosc)

dana=int(input("Podaj wartosc ktora chcesz zmienic "))
funkcja(dana)

#Zad2
import math
def zad2(x,n=10,k=2):
    print(math.log((x**2)+5,n)*(k+1)*x," To wynik dzialania zadania 2")
do_2_danych=int(input("Podaj wartosc ktora chcesz zmienic "))
zad2(do_2_danych,k=7)

#Zad3
zad3=lambda a: print(math.sin(a+1)+math.cos(x**4)," Taka odpowiedz dla: ", a)
for x in range(-5,3):
    zad3(x)
#zad4

def zad4(*args):
    sum=0
    for i in args:
        sum+=i
    print("Suma to: ",sum)    
zad4(5,3,4,5,6,1)
#zad5

def zad5(typ,**kwargs):
    if(typ=='A'):
         print((kwargs['r']**3)*(4/3)*math.pi)
    elif(typ=='B'):
         print(kwargs['r']*kwargs['h']*kwargs['c'])
    else:
        if(typ=='D'):
            print(kwargs['h']*(kwargs['r']**2)*(1/3)*math.pi)
        else:
            print(kwargs['h']*(kwargs['r']**2)*math.pi)

skladowa=str(input("Wybierz jaka figure chcesz policzyc, a takze jej dane: A Kule, B Prostopadloscian, C Walec, D Stozek "))
if(skladowa=='A'):
    r=float(input("Podaj promien "))
    zad5(skladowa,r=r)
elif(skladowa=='B'):
    r=float(input("Podaj bok A "))
    h=float(input("Podaj bok B "))
    c=float(input("Podaj bok C "))
    zad5(skladowa,r=r,h=h,c=c)
else:
    r=float(input("Podaj promien "))
    h=float(input("Podaj wysokosc "))
    zad5(skladowa,r=r,h=h)
#zad6
def zad6(a,b,c,d):
    print('\n',a,'\n',b,'\n',c,'\n',d,'\n')
zad6(*[3,4,5,6])

#zad7
def zad7a(a):
    suma=1
    for i in range (1,a+1):
        suma=suma*i
    print("Silnia iteracyjna ",suma)
def zad7b(a):
    if(a<2):
        return 1
    else:
        return a*zad7b(a-1)
silnia=int(input("Jaka silnia "))
zad7a(silnia)
wartosc=zad7b(silnia)
print("Silnia rekurencyjna ",wartosc)
#zad8
def zad8(a):
    if(a<3):
        return 0
    elif(a==3):
        return 1
    else:
        return zad8(a-1)+zad8(a-2)+zad8(a-3)
tribonnaci=int(input("Ile elementow "))
wartosc_tr=zad8(tribonnaci)
print("Wartosc tego elementu ",wartosc_tr)