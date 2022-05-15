import numpy as np
import scipy as sc
#zad1
n=int(input("Podaj n "))
A=np.zeros((n-1))
for i in range(0,len(A)):
    A[i]=i+2
for i in range(0,len(A)):
    if(A[i]!=0):
        for j in range(i+1,len(A)):
            if(A[j]%A[i])==0:
                A[j]=0
print(A[A[0:n]>0])
#zad2
B=np.arange(1,21,1).reshape(4,5).T
print(B)
#zad3
def Kramer(macierz,wektor):
       W=int(np.linalg.det(macierz))
       wynik=np.zeros(len(macierz[0]))
       for i in range(0,len(macierz[0])):
            temp=np.copy(macierz)
            for j in range(0,len(macierz)):
                      temp[j,i]=wektor[j]
            det_temp=int(np.linalg.det(temp))
            wynik[i]=int(det_temp/W)
       print(wynik)
C=np.array([[8,2,1],[5,-3,-7],[0,-5,7]])
Wolne=np.array([[16],[-22],[11]])
Kramer(C,Wolne)
#zad5
zad5_a=np.ones((2,2))
zad5_b=np.zeros((2,1))
pomoc=np.hstack((zad5_b,zad5_a))
pomoc_1=np.hstack((pomoc,zad5_b))
dol=np.hstack((zad5_b.T,zad5_b.T))
lewo=np.vstack((pomoc_1,dol))
prawo=np.vstack((zad5_b.T,zad5_a))
calosc=np.hstack((lewo,prawo))
print(calosc)
#zad6
wolne=np.arange(0,21,2)
print(wolne)
podzielne_3=np.arange(3,34,3)
print(podzielne_3)
polaczone=np.hstack((wolne,podzielne_3))
print(polaczone)
posortowane=np.sort(polaczone)
print(posortowane)