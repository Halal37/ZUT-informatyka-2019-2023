#Wojciech Lidwin 221A
import numpy as np
from random import *
#zad2 a)
print("Punkt 2 podpunkt 1")
print()
b=np.array([[1,2,3,4,5],[6,7,8,9,10]])
print(np.transpose(b))
print()

#
A=np.arange(0,100)
print(A)
print()

#
B=np.linspace(0,2,num=10)
print(B)
print()

#
C=np.arange(0,100,5)
print(C)
print()

#zad2 b)
print("Punkt 2 podpunkt 2")
print()
rn=np.random.default_rng()
D=np.linspace(0,2,num=20)
for i in range(0,20):
    D[i]=round(rn.standard_normal(),2)
print(D)
print()

#
E=np.arange(0,100)
for i in range(0,100):
  E[i]=randrange(1,101)
print(E)
print()

#
F=np.zeros((3,2))
G=np.ones((3,2))
print(F)
print()
print(G)
print()

#
H=np.random.randint(100,size=(5,5))
print(H)
H=np.uint32(H)
print(H)
print()

#
I=np.random.uniform(0.0,10.0,size=10)
I=np.uint(I)
b=I
b=np.round(b)
b=np.uint(b)
print(I)
print()
print(b)
print()
#Takie same wyniki

#zad 2 c)
print("Punkt 2 podpunkt 3")
print()
b=np.array([[1,2,3,4,5], [6,7,8,9,10]],dtype=np.int32)
print(np.ndim(b))
print()

#
print(np.size(b))
print()

#
print(b[0][1])
print()

#
print(b[0][3])
print()

#
print(b[0])
print()

#
print(b[:,0])
print()

#
J=np.random.randint(0,101,size=(20,7))
print(J[:,(0,1,2,3)])
print()

#zad2 d)
print("Punkt 2 podpunkt 4")
print()
K=np.random.randint(0,10,(3,3))
L=np.random.randint(1,10,(3,3))
print(K)
print()
print(L)
print()

#
print(np.add(K,L))
print()

#
print(np.multiply(K,L))
print()

#
print(np.divide(K,L))
print()

#
print(np.power(K,L))
print()

#
do_wlasnosci=np.linalg.eig(K)
for i in range(0,3):
    print(do_wlasnosci[0][i])
    if (do_wlasnosci[0][i]>=4):
        print(i+1, "wartość własna macierzy jest wieksza lub rowna 4")
        print()
    else:
        print(i+1, "wartość własna macierzy jest mniejsza od 4")
        print()

#
for i in range(0,3):
    print(do_wlasnosci[0][i])
    if (do_wlasnosci[0][i]>=1 and do_wlasnosci[0][i]<=4):
        print(i+1, "wartość własna macierzy jest wieksza lub rowna od 1, mniejsza lub rowna 4")
        print()
    else:
        print(i+1, "wartość własna macierzy jest miejsza od 1 lub wieksza od 4")
        print()


#
print(np.trace(L))
print()
#zad2 e)
print("Punkt 2 podpunkt 5")
print()
b=np.array([[1,2,3,4,5],[6,7,8,9,10]])

#
print(np.sum(b))
print()

#
print(np.min(b))
print()

#
print(np.max(b))
print()

#
print(np.std(b))
print()

#
print(np.mean(b,0))
print()

#
print(np.mean(b,1))
print()

#
#zad2 f)
print("Punkt 2 podpunkt 6")
print()
M=np.random.randint(0,100,50)

#
print(np.reshape(M,(10,5)))
print()

#
print(np.resize(M,(10,5)))
print()

#
M=np.reshape(M,(10,5))
print(np.ravel(M))
print()
#zwracana ciagla splaszczona tablica

#
N=np.random.randint(0,100,5)
O=np.random.randint(0,100,4)
np.resize(O,(5))
O=O[:,np.newaxis]
print(O)
print()
N=np.add(N,O)
print(N)
print()

#zad2 g)

print("Punkt 2 podpunkt 7")
print()
U=np.random.randn(5,5)
print(U)

print("Sortowanie")
print()
kopia=U
for i in range(5):
   kopia[i]=np.sort(kopia[i])
print(kopia)



sidx=U.argsort(axis=0)[::-1]
out=U[sidx,np.arange(sidx.shape[1])]
print(out)

#
a=[("number",float),("short",'U20'),("name",'U20')]
b=[(3,"MZ","mazowieckie"),(2,"ZP","zachodniopomorskie"),(1,"ML","malopolskie")]

c=np.array(b,dtype=a)
c=np.sort(c,order='number')
print(c[1][2])
print()

#punkt 3 zad1
print("zad1")
print()
zad1=np.random.randint(0,100,(10,5))
print("Suma glownej przekatnej to: ")
print(np.trace(zad1))

#punkt 3 zad2
print("zad2")
print()
rn=np.random.default_rng()
zad2a=np.linspace(0,2,num=20)
for i in range(0,20):
    zad2a[i]=round(rn.standard_normal())

zad2b=np.linspace(0,2,num=20)
for i in range(0,20):
    zad2b[i]=round(rn.standard_normal())
print(np.multiply(zad2a,zad2b))

#punkt 3 zad3
print("zad3")
print()
zad3a=np.random.randint(1,100,10)
zad3b=np.random.randint(1,100,10)
zad3a=np.reshape(zad3a,(2,5))
zad3b=np.reshape(zad3b,(2,5))
zad3a=np.add(zad3a,zad3b)
print(zad3a)
print()

#punkt 3 zad4
print("zad4")
print()
zad4a=np.random.randint(1,100,(5,4))
zad4b=np.random.randint(1,100,(4,5))
zad4a=np.reshape(zad4a,(4,5))
print(np.add(zad4a,zad4b))
print()

#punkt 3 zad5
print("zad5")
print()
print(zad4a)
print()
print(zad4b)
print()
print(np.multiply(zad4a[:,3],zad4b[:,4]))
print()

#punkt 3 zad6
print("zad6")
print()
zad6a=np.random.normal(size=5)
zad6b=np.random.uniform(size=5)

print(np.mean(zad6a))
print(np.mean(zad6b))
print()

print(np.std(zad6a))
print(np.std(zad6b))
print()

print(np.var(zad6a))
print(np.var(zad6b))
print()

#Srednie sa mniejsze dla rozkladu normalnego, natomiast rozklad ten ma wieksza wariancje i odchylenie standardowe od jednostajnego

#punkt 3 zad7
print("zad7")
print()
a=np.random.randint(1,100,(3,3))
b=np.random.randint(1,100,(3,3))
print(a*b)
print()
print(np.dot(a,b))

#punkt 3 zad8
print("zad8")
print()
zad8=np.random.randint(1,101,(5,5))
print(zad8)
print(zad8.strides)
print(np.lib.stride_tricks.as_strided(zad8,shape=(3,5),strides=zad8.strides))

#punkt3 zad9
print("zad9")
print()
a=np.random.randint(1,100,4)
b=np.random.randint(1,100,4)
print(a)
print()
print(b)
print()
print(np.vstack((a,b)))
#scala jako nowy wiersz
print()
print(np.hstack((a,b)))
#scala poprzez dodanie drugiej macierzy do macierzy 1

#punkt 3 zad10
print("zad10")
print()
zad10=np.arange(0,24).reshape(4,6)
print(zad10)
print()
print(zad10.strides)
print()
print(np.lib.stride_tricks.as_strided(zad10[0],shape=(2,3),strides=(24,4)))
print()
print(np.ndarray.max(np.lib.stride_tricks.as_strided(zad10[0],shape=(2,3),strides=(24,4))))
print()
print(np.lib.stride_tricks.as_strided(zad10[0][3:6],shape=(2,3),strides=(24,4)))
print()
print(np.ndarray.max(np.lib.stride_tricks.as_strided(zad10[0][3:6],shape=(2,3),strides=(24,4))))
print()
print(np.lib.stride_tricks.as_strided(zad10[2],shape=(2,3),strides=(24,4)))
print()
print(np.ndarray.max(np.lib.stride_tricks.as_strided(zad10[2],shape=(2,3),strides=(24,4))))
print()
print(np.lib.stride_tricks.as_strided(zad10[2][3:6],shape=(2,3),strides=(24,4)))
print()
print(np.ndarray.max(np.lib.stride_tricks.as_strided(zad10[2][3:6],shape=(2,3),strides=(24,4))))