import numpy as np 
A=np.loadtxt("C:\Lab11\irisP.txt",dtype=str,comments='#',delimiter=',',usecols=(3,4))
#print(A)
sum_a=0
ilosc=0;

Unikaty_a=np.unique(A[:,1])
czek=str(Unikaty_a[0])
print(Unikaty_a)
for i,j in A:
 if(czek==j):
  sum_a=sum_a+float(i)
  ilosc=ilosc+1;
 else:
    print("Taka jest suma ",sum_a/ilosc," nazwy ", czek)
    czek=j
    suma_a=0
    ilosc=0;
    sum_a=sum_a+float(i)
    ilosc=ilosc+1;
print("Taka jest suma ",sum_a/ilosc," nazwy ", czek)
#zad2
B=np.loadtxt("C:\Lab11\irisP.txt",dtype=str,comments='#',delimiter=',',usecols=(2,4))
Unikaty_b=np.unique(B[:,1])
for i,j in B:
     if(czek==j):
      sum_a=sum_a+float(i)
      ilosc=ilosc+1;
     elif(i=='?'):
         i=sum_a/ilosc

