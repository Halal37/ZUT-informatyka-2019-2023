import numpy as np
#zad1
n=int(input("Podaj n "))
A=np.ones((n,n))
for i in range(0,len(A)):
    for j in range(1,len(A[0])):
        A[i,j]=(A[i,j]+i)**j
print(A)
#zad2
n=int(input("Podaj n "))
A=np.ones((n,n))
pom=1
pom_2=0
for i in range(0,len(A)):
   if(pom_2!=n):
    for j in range(0,len(A[0])):
        A[i,j]=pom
        pom+=1
        pom_2+=1
   else:
        for j in range(len(A[0]),0,-1):
            A[i,j-1]=pom
            pom+=1
            pom_2=0
print(A)
#zad4
for i in range(0,len(A)):
    for j in range(0,len(A[0])):
          if((A[i,j]%5==0) or (A[i,j]%3==0)):
                  A[i,j]=0
print(A)
#zad3
#n=int(input("Podaj n "))
#A=np.ones((n,n))
#pom=1
#for i in range(len(A[0]),0,-1):
#        A[i-1,0]=pom
#        pom+=1
#for j in range(1,len(A[0])):
 #   A
#print(A)
#zad5
#sasiedztwo
C=[(2,4,6),(3),(),(),(4,5),(3)]
print(C[0])
n=len(C)
A=np.zeros((n,n))
for element in C:
 try:
    print(len(element))
 except TypeError:
     print(1)              
for i in range(0,len(A)):
    i
    for j in range(0,len(A[0])):
     try:
        for k in range(0,len(C[i])):
            if(C[i][k]==j+1):
                A[i,j]=1
     except TypeError:
         for k in range(0,1):
              if(C[i]==j+1):
                A[i,j]=1
print(A)
#incydencja
m=0
z=0
for element in C:
 try:
     m+=len(element)
 except TypeError:
     m+=1  
print(m)
A=np.zeros((n,m))
for i in range(0,len(A)):
    i
    for j in range(0,len(A[0])):
     try:
        for k in range(0,len(C[i])):
            if(C[i][k]==j+1):
                if(i==j):
                  A[j][z]=2
                  z+=1
                else:
                 A[i][z]=1
                 A[j][z]=-1
                 z+=1
                #A[i,j]=1
     except TypeError:
         for k in range(0,1):
              if(C[i]==j+1):
                if(i==j):
                 A[j][z]=2
                 z+=1
                else:
                 A[i][z]=1
                 A[j][z]=-1
                 z+=1
print(A)