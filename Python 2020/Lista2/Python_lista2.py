#Laby2
#Zad1
g=[0,- 2, 1, 7, 3, 4]
print(g[::-1])
#Zad2
wzrost=int(input("Podaj swoj wzrost w centymetrach "))
waga=int(input("Podaj swoja wage w gramach "))
print(wzrost/100)
print(waga/1000)
wzrost_m=(wzrost/100)
waga_kg=(waga/1000)
print("Wzrost w metrach: ", wzrost_m)
print("Waga w kg: ",waga_kg)
BMI=waga_kg/wzrost_m**2
print("Twoje BMI to: ",round(BMI,2))
#Zad3
import math
x=float(input("Podaj x: "))
y=float(input("Podaj y: "))
a=math.exp(1)+math.log10(x**2+1)*(x-1)/math.cos((y**3-1))+6
print(a)
#dla x=2 i y=4 9.42725071768477
#dla x=-9.5 i y=6.4 30.988365064872394
#Zad4
x_2=float(input("Podaj x: "))
y_2=float(input("Podaj y: "))
z=float(input("Podaj z: "))
c=int(input("Podaj c: "))
if c==1:
    odp=x_2+y_2+z
if c==2:
    odp=x_2-y_2-z
elif c==3:
    odp=x_2*y_2*z
else:
    if (y_2!=0 and z!=0 and c!=1):
            odp=x_2/y_2/z
if(y_2!=0 and z!=0):
    print("To twoja odpowiedz: ",odp)
#Zad5
zad5=int(input("Jak duzy trojkat? "))
for i in range(zad5):
    print("");
    for j in range(i+1):
                print("X",end=" ")
#Zad6
print(" ")
#A=[i for i in range(1, 8, 3)] in range(0,3)
#print (A)
for i in range(1,4):
        print("1 4 7")
#Zad7
wartosc=int(input(" Podaj ile chcesz liczb pierwszych "))
if(wartosc>=2):
        print("Liczba jest pierwsza: ",2)
for i in range(1,wartosc+1):
    for j in range(2,i):
             
             if(i%j==0):
                        break
             else:
                print("Liczba jest pierwsza: ",i)
                break
#Zad8
dana=int(input("Podaj jaka liczba do sumy "))
suma=0
for i in range(dana):
                if int(i%10)==3:
                     suma=suma+i
                if int(i%100)==14:
                      suma=suma+i
print("Taka wyszla suma ",suma)

#Zad9
trojkat=int(input("Podaj dane do trojkata Pascala "))


