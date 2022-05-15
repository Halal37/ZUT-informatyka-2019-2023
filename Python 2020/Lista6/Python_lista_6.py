#zad1
import collections 
licznik=list("""Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut
labore et dolore magna aliqua. Dolor sed viverra ipsum nunc aliquet bibendum enim. In massa
tempor nec feugiat. Nunc aliquet bibendum enim facilisis gravida. Nisl nunc mi ipsum faucibus
vitae aliquet nec ullamcorper. Amet luctus venenatis lectus magna fringilla. Volutpat maecenas
volutpat blandit aliquam etiam erat velit scelerisque in. Egestas egestas fringilla phasellus faucibus
scelerisque eleifend. Sagittis orci a scelerisque purus semper eget duis. Nulla pharetra diam
sit amet nisl suscipit. Sed adipiscing diam donec adipiscing tristique risus nec feugiat in. Fusce
ut placerat orci nulla. Pharetra vel turpis nunc eget lorem dolor. Tristique senectus et netus et
malesuada.""".replace(",","").lower().replace(".","").split())
print(collections.Counter(licznik))
#Zad2
from scipy.io import arff
from io import StringIO
content = """
@relation weather

@attribute outlook {sunny, overcast, rainy}
@attribute temperature real
@attribute humidity real
@attribute windy {TRUE, FALSE}
@attribute play {yes, no}

@data
sunny,85,85,FALSE,no
sunny,80,90,TRUE,no
overcast,83,86,FALSE,yes
rainy,70,96,FALSE,yes
rainy,68,80,FALSE,yes
rainy,65,70,TRUE,no
overcast,64,65,TRUE,yes
sunny,72,95,FALSE,no
sunny,69,70,FALSE,yes
rainy,75,80,FALSE,yes
sunny,75,70,TRUE,yes
overcast,72,90,TRUE,yes
overcast,81,75,FALSE,yes
rainy,71,91,TRUE,no
"""
f = StringIO(content)
data, meta = arff.loadarff(f)
print(data)
print(meta)
c=collections.Counter(data['outlook'])
pierwsza=collections.Counter(data['temperature'])
druga=collections.Counter(data['humidity'])
trzecia=collections.Counter(data['windy'])
czwarta=collections.Counter(data['play'])
for i in data:
       print(i)
from collections import namedtuple
from collections import OrderedDict
print(c)
def do_zad_3(c):
    prawdo=[]
    p=0
    suma=len(list(c.elements()))
    for i, val in c.most_common(len(c)):
          prawdo=val/suma
          print(i,prawdo)
          c[i]=val/suma
          p+=1
       
    

do_zad_3(c)
do_zad_3(pierwsza)
do_zad_3(druga)
do_zad_3(trzecia)
do_zad_3(czwarta)

#Zad3
def funkcja_sortowania(c):
          zmienna=dict(OrderedDict(sorted(c.items(), key=lambda x:x[1])))
          print(zmienna)
funkcja_sortowania(c)
funkcja_sortowania(pierwsza)
funkcja_sortowania(druga)
funkcja_sortowania(trzecia)
funkcja_sortowania(czwarta)

 #Zad4
from collections import *

d=defaultdict(lambda:5)
print(d)
for i in range(0,5):
    c=int(input("Podaj wartosc klucza"))
    print(d[c])
    d[c]+=1
    print(d)
print(d)
#Zad5
wyraz=str(input("Podaj wyraz "))
ada=collections.deque(wyraz)
ole='k'
ola=collections.deque(ole)
ola.clear()
print("To ola ",ola)
for i in ada:
    ola.appendleft(i)
print("To ola ",ola)
if(ada==ola):
    print("To palinindrom")
else:
    print("To nie palinindrom")