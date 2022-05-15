#zad1
lista=list()
file=open("C:\Lab11\zad1.txt")
for i in file:
  #  print(i)
    lista.append(i)
print(lista)
file.close()
#zad2
zad2=open("C:\Lab11\iris.txt")

zawartosc=zad2.readlines()
zawartosc=[x.strip().split(",") for x in zawartosc]
#print(zawartosc)

zad2.close()
#zad3
zad3=open("C:\Lab11\iris.txt")
zawartosc_3=zad3.readlines()
zawartosc_3=[x.strip().split(",") for x in zawartosc_3]
for i in range(len(zawartosc_3)):
 for j in range(len(zawartosc_3[i])):
  try:
    zawartosc_3[i][j]=float(zawartosc_3[i][j])
  except ValueError:
    #print("Niestety string nie mozna na float")
    pass
zawartosc_3
zawartosc_3
#zad4
zad4=open("C:\Lab11\zad4.txt","a")
for i in zawartosc_3:
 if(i[0]>5):
      zad4.write("%s\n" % i)
zad3.close()
zad4.close()
#zad5


