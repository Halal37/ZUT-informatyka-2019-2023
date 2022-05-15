#Zad1

nowa_lacina=set("""Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut
labore et dolore magna aliqua. Dolor sed viverra ipsum nunc aliquet bibendum enim. In massa
tempor nec feugiat. Nunc aliquet bibendum enim facilisis gravida. Nisl nunc mi ipsum faucibus
vitae aliquet nec ullamcorper. Amet luctus venenatis lectus magna fringilla. Volutpat maecenas
volutpat blandit aliquam etiam erat velit scelerisque in. Egestas egestas fringilla phasellus faucibus
scelerisque eleifend. Sagittis orci a scelerisque purus semper eget duis. Nulla pharetra diam
sit amet nisl suscipit. Sed adipiscing diam donec adipiscing tristique risus nec feugiat in. Fusce
ut placerat orci nulla. Pharetra vel turpis nunc eget lorem dolor. Tristique senectus et netus et
malesuada.""".replace(",","").lower().replace(".","").split())
u=len(nowa_lacina)
print(u)
print(nowa_lacina)
#Zad2
A=set((1,2,3,4,5))
B=set((2,4,5))

print (A)
print(A.issubset(B))
print(B.issubset(A))
#przeciecie
print (A.intersection(B))
#suma
print (A.union(B))
#roznica
print(A.difference(B))
print(B.difference(A))
#roznica symetryczna zbiorow
print (A.symmetric_difference(B))
print("Zad3")
lista=[]
#Zad3
import itertools
for i in itertools.product(A,B):
    print(i)
    lista.append(i)
print(lista)
#Zad4
import random
jednosc=["zero","jeden","dwa","trzy","cztery","piec","szesc","siedem","osiem","dziewiec"]
jed=enumerate(jednosc)
nascie=["dziesiec","jedenascie","dwanascie","trzynascie","czternasie","pietnascie","szescnascie","siedemnascie","osiemnascie","dziewietnascie"]
nas=enumerate(nascie)
dzies=["psuto","pusto","dwadziescia","trzydziesci","czterdziesci","piecdziesiat","szescdziesiat","siedemdziesiat","osiemdziesiat","dziewiecdziesiat"]
dzie=enumerate(dzies)
a=random.randint(0,99)
print(a)
if(a<10):
        for i,val in enumerate(jednosc):
            if(i==a):
                  print (val)
elif(a<20):
    for i,val in enumerate(nascie):
        if(i+10==a):
            print(val)
else:
    print(a%10)
    for i,val in enumerate(jednosc):
            if(i==a%10):
                  es=val
    a=a-(a%10)
    a=a/10
    for i,val in enumerate(dzies):
            if(i==a%10):
                  kes=val
    print(kes+es)
#Zad5


#kara="lorem ipsum dolor sit amet consectetur adipiscing elit sed do eiusmod tempor incididunt ut"
#kar=kara.split()
#print(kar)
#s=lacina.split()
#print(s)
#kar2a=set(lacina)
#print(kar2a)
