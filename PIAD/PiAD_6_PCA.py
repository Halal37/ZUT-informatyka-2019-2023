#Wojciech Lidwin lw46577
import numpy as np
import matplotlib.pyplot as plt
from sklearn import datasets
from sklearn.decomposition import PCA
import pandas as pd

#Funkcje wykorzysytwane do zadan
def pc(dots,wymiar):
 print()
 if(wymiar!=1):
  srednie=np.mean(dots)
  print(srednie)

  odchy=dots-srednie
  print()
  print(odchy)
  print()

  kowar=np.cov(odchy.T)
  print()
  print()
  print()

 else:
  kowar=np.cov(dots.T)
  print()
  print(kowar)
  print()

 wartosci,wektory=np.linalg.eig(kowar)
 print()
 print()
 if(wymiar==1):

     wekt = wektory[:, np.argmax(wartosci)]
     transformacja = np.dot(dots, wekt)
     wynik=np.outer(transformacja, wekt)
 else:
  sort = np.argsort(wartosci)[::-1]
  wektory_sort = wektory[:, sort]
  V = wektory_sort[:, 0:wymiar]

  rzutowanie=V.T.dot(odchy.T)

  wynik=rzutowanie.T

 return wynik

def pc_do_e(dots,wymiar):
 print()

 srednie=np.mean(dots)

 odchy=dots-srednie

 kowar=np.cov(odchy.T)


 wartosci,wektory=np.linalg.eig(kowar)

 sort = np.argsort(wartosci)[::-1]
 wektory_sort = wektory[:, sort]
 V = wektory_sort[:, 0:wymiar]

 rzutowanie=V.T.dot(odchy.T)

 wynik=rzutowanie.T

 return wynik

def krzyw_var(dots):
 print()

 srednie=np.mean(dots)

 odchy=dots-srednie


 kowar=np.cov(odchy.T)
 print()



 wartosci,wektory=np.linalg.eig(kowar)
 print()
 return(np.cumsum(wartosci/wartosci.sum()))


#zad1 a) Generowanie 200 obiektow
rng=np.random.RandomState(0)
dots= rng.randn(200, 2)
dots2=np.dot(dots,rng.rand(2,2))
#zad1 b) Wizualizacja efektu
plt.scatter(dots[:,0],dots[:,1])
plt.show()
#zad1 c) Redukcja do 1 wymiaru i wizualizacja podobnie dla rysunku 1 w konspekcie

X_ra=pc(dots2,1)

plt.scatter(dots[:,0],dots[:,1])
plt.scatter(dots2[:,0],dots2[:,1],color='green')
plt.scatter(X_ra[:,0],X_ra[:,1],color='red')
plt.show()

#Zad2 a) Wczytanie zbioru iris
iris=datasets.load_iris()
#Zad2 b) Redukcja do 2 wymiaru
dane_iris=iris.data
dane_iris=pc(dane_iris,2)
#Zad2 c) Wizualizacja dla 2 wymiaru danych iris po redukcji 
cel_iris=iris.target
plt.scatter(dane_iris[:, 0],-dane_iris[:, 1], c=cel_iris)
plt.show()

#zad3 a) Wczytanie zbioru digits
digits = datasets.load_digits()
#zad3 b) Redukcja do 2 wymiaru
dane_digits=pc(digits.data,2)
#zad3 c) Krzywa wariancji dla rosnacych danych skladowych
print()
do_war=krzyw_var(digits.data)
plt.plot(do_war)
plt.show()
#zad3 d) Wizualizacja dla 2 wymiaru danych digits po redukcji
plt.scatter(dane_digits[:, 0], dane_digits[:, 1], c=digits.target)
plt.colorbar()
plt.show()
#zad3 e) Proba oceny sredniego bledu rekonstrukcji dla zbioru digits
#Skoro dla powyzej 4 wymiarowosci nawet dla bazowej funckji inversji zwracane sa zle wyniki to sie poddalem na tym etapie, tu wizualizacja proby
pierwsze=0
max=60
wyniki_mojego_pca=[]
wyniki_sk_pca=[]
for i in range(pierwsze,max):
    pca = PCA(n_components=i)

    pca_wb = pca.fit(digits.data).transform(digits.data)
    zwrot=pca.inverse_transform(pca_wb)

    pca1 = pc_do_e(digits.data,i)
    zwrot2=pca.inverse_transform(pca1)

    blad=np.linalg.norm((digits.data-zwrot2),None)
    wyniki_mojego_pca.append(blad)
    blad2=np.linalg.norm((digits.data-zwrot),None)
    wyniki_sk_pca.append(blad2)

plt.plot(wyniki_sk_pca)
plt.plot(wyniki_mojego_pca,'g')
plt.show()