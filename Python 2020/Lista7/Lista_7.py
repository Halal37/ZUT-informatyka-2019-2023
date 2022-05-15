#zad1
from math import *
import math
print(dir(math))
#zad2
help(math.cos)
help(math.log)
#zad3
from Matrix import Operacje
import Matrix
import imp
#Operacje=imp.load_source('Operacje','C:/Users/JaSzw/OneDrive/Pulpit/Python/Lista_7/Lista_7/Matrix/Operacje.py')
#dodawanie
n=int(input("Wartosc: "))
cz=int(input("Wartosc: "))
A=[[0]*n for i in range(n)]
for i in range(n):
    for j in range(0,i):
        A[i][j]=j+i+6
#print(A)
B=[[0]*cz for i in range(cz)]
for i in range(cz):
    for j in range(0,i):
        B[i][j]=j+i*3
#print(B)
Z=[[5, 6, 1], [8, 7, 9], [1, 5, 2]]
G=[[4, 6, 7], [2, 5, 1], [0, 3, 9]]
U = [[1, 2, 3], [4, 5, 6]]
O = [[1, 0, 0], [0, 1, 0], [0, 0, 1]]
#Operacje.dodawanie_macierzy(A,B)
#print("Tu mnozenie")
#Operacje.mnozenie_macierzy(Z,G)
#Operacje.dodawanie_stalej_do_macierzy(A,4)
#Operacje.mnozenie_macierzy_przez_skalar(A,4)
#Operacje.iloczyn_Hadmarda(A,B)
print("Kro")
Operacje.iloczyn_Kroneckera(U,O)
Operacje.Kroneckerproduct(U,O)
help(Operacje.iloczyn_Kroneckera)