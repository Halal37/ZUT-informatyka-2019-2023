import numpy as np
import scipy as sc
#zad1
n=int(input("Podaj n "))
A=np.zeros((n-1))
for i in range(0,len(A)):
    A[i]=i+2
for i in range(0,len(A)):
    if(A[i]!=0):
      #  print(A[i])
        for j in range(i+1,len(A)):
            if(A[j]%A[i])==0:
                A[j]=0
print(A[A[0:n]>0])
