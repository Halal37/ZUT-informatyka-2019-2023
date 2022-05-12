#Wojciech Lidwin 221A lw46577
import numpy as np
import pandas as pd
from math import log, e,floor
data=pd.read_csv("./zoo.csv")
print(data)
print()
#1 Funkcja freq
def freq(x,kolumna):
       pi=x.groupby([kolumna]).size().div(len(x))
       ni=x.groupby([kolumna]).count()
       wynik=pd.concat([pi,ni.reindex(pi.index)],axis=1)
       print(wynik)
       print()

#2 Funkcja freq2
def freq2(x,kolumna,kolumna2):
       pi=x.groupby([kolumna,kolumna2]).size().div(len(x))
       ni=x.groupby(kolumna)[kolumna2].value_counts().unstack(fill_value=0).stack()
       wynik=pd.concat([ni,pi.reindex(ni.index)],axis=1)
       wynik=wynik.fillna(0)
       print(wynik)
       print()

df = pd.DataFrame({'A': ['cos', 'sin', 'ctg', 'ctg', 'ctg',
                         'sin', 'sin', 'cos', 'sin', 'cos'],
                  'B': ['a', 'b', 'a', 'b', 'b', 'b', 'a', 'a', 'b','b'] })
#Pi i ni dla A
freq(df,'A')
#A    pi   ni
#cos  0.3  3
#ctg  0.3  3
#sin  0.4  4
print()

freq2(df,'A','B')
#A   B ni pi
#cos a  2  0.2
#    b  1  0.1
#ctg a  1  0.1
#    b  2  0.2
#sin a  1  0.1
#    b  3  0.3
print()

#3 Funkcja liczaca entropie
def entropia(x,kolumna):
    suma=0
    pi=x.groupby([kolumna]).size().div(len(x))
    for i in pi.values:
        suma=suma+i*log(i,2)
    return -suma
#Entropia dla A
print(entropia(df,'A'))
#1.5709505944546684
print()

#Funkcja liczaca infogain
def infogain(x,kolumna,kolumna2):
    pi=x.groupby([kolumna]).size().div(len(x))
    piw=x.groupby([kolumna,kolumna2]).size().div(len(x))
    ni=x.groupby(kolumna)[kolumna2].value_counts().unstack(fill_value=0).stack()
    czesc=pd.concat([ni,piw.reindex(ni.index)],axis=1)
    czesc=czesc.fillna(0)
    z=0
    a=0
    n=0
    prawdo=[0 for y in range(len(czesc.values[:,1]))] 
    for i in czesc.values[:,1]:
        prawdo[a]=i/pi.values[n]
        z=z+1
        a=a+1
        if(z==floor(len(czesc.values[:,1])/len(pi.values))):
            z=0
            n=n+1
    n=0
    suma=0
    for i in prawdo:
        if (i!=0):
          suma=suma+czesc.values[n][1]*log(i,2)
        n=n+1
    ent=entropia(x,kolumna2)
    wynik=ent+suma
    return wynik

#Infogain dla A i B
print(infogain(df,'A','B'))
#0.0954618442383216
print()


#Wyświetlenie wynikow przyrostu informacji dla danych z dananie i danej type
wynik=[0 for y in range(len(data.columns)-1)] 
for i in range(len(data.columns)):
    if(data.columns[i]!="type"):
        wynik[i]=((data.columns[i],'type', infogain(data,data.columns[i], 'type')))
wynik=sorted(wynik, key = lambda x: x[2])
print(wynik)
#[('domestic', 'type', 0.050668779845517875), 
#('predator', 'type', 0.09344704054083142), 
#('venomous', 'type', 0.13308962953512316), 
#('catsize', 'type', 0.3084903449142815), 
#('aquatic', 'type', 0.3894874837982223), 
#('fins', 'type', 0.4666135671503897), 
#('airborne', 'type', 0.4697026095047725), 
#('tail', 'type', 0.5004604482515025), 
#('breathes', 'type', 0.6144940279390549), 
#('backbone', 'type', 0.6761627418829199), 
#('feathers', 'type', 0.717949976500291), 
#('hair', 'type', 0.7906745736101795), 
#('eggs', 'type', 0.830138448363348), 
#('toothed', 'type', 0.8656941534932372), 
#('milk', 'type', 0.9743197211096903), 
#('legs', 'type', 1.3630469031539394), 
#('animal', 'type', 2.390559682294039)]
