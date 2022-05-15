#from collections import namedtuple
import math
import collections
#zad1
def analizujProstokat(x1,y1,x0,y0):
    blok_a=math.sqrt(((x1-x1)**2)+((y1-y0)**2))
    blok_b=math.sqrt(((x1-x0)**2)+((y1-y1)**2))
    pole=blok_a*blok_b
    obwod=2*blok_a+2*blok_b
    print("Pole to ",pole)
    print("Obwod to ",obwod)


analizujProstokat(8,7,1,3)

#zad2
def analizujProstokat2(A):
    blok_a=math.sqrt(((A[0]-A[0])**2)+((A[1]-A[3])**2))
    blok_b=math.sqrt(((A[0]-A[2])**2)+((A[1]-A[1])**2))
    pole=blok_a*blok_b
    obwod=2*blok_a+2*blok_b
    print("Pole to ",pole)
    print("Obwod to ",obwod)
Punkt=collections.namedtuple('Punkt',['x1','y1','x0','y0'])
A=Punkt(8,7,1,3)
analizujProstokat2(A)

#zad3
lista=list(range(1,1002,2))

print(lista)
#zad4
import copy
lista_4=list(range(1,11))
lista_4_a=copy.copy(lista_4)
lista_4_a[7]=15
print("Pierwsza lista ",lista_4)
print("Druga lista ",lista_4_a)
#zad5
int_lista=[]
float_lista=[]
for i in range(0,10):


#zad6

