#zle
przedzial.odchylenie=function(x,uf){
ocena.dolna=sqrt(((x-1)*var(x)^2)/qchisq((1+uf)/2,x-1))
ocena.górna=sqrt(((x-1)*var(x)^2)/qchisq((1-uf)/2,x-1))
data.frame(ocena.dolna,ocena.górna)
}
#

przedzia³.odchylenie=function(x,uf){
  n=length(x)
  q1=qchisq((1+uf)/2,n-1)
  q2=qchisq((1-uf)/2,n-1)
  ocena.dolna=sqrt((n-1)*var(x)/q1)
  ocena.górna=sqrt((n-1)*var(x)/q2)
  cbind(ocena.dolna,ocena.górna)
}
przedzia³.odchylenie(Ankieta.M$Wzrost,0.97)
#Zad2 
#H0 rozklad jest normalny H1: H0
shapiro.test(Ankieta.M$Wzrost)
#W=0.98949, p=value=0.6305
#alfa=0.05<p-value=0.6305
#brak podstaw do odrzucenia H0
#nie ma podstaw do odrzucenia hipotezy H0, ktora mowi, ze
#rozklad wzrostu
#w populacji mezczyzn jest normalny
#wyniki proby nie potrwierdzily znaczacych roznic
#b)
t.test(Ankieta.M$Wzrost,conf.level = 0.95)
#179.2540 181.9581
#Przedzial liczbowy o koncach 179,3 i 182.0
#Z prawdopodobienstwiem 0.95 obejmuje nieznany rzeczywisty œredni
#wzrost w populacji studentow 1 roku informatyki
t.test(Ankieta.M$Wzrost, conf.level=0.98)
#178.9947 182.2174

#c)0.97
przedzia³.odchylenie(Ankieta.M$Wzrost,0.97)

#Przedzia³ ufnoœci o koñcach 6.0 i 8.01 dla poziomu ufnoœci 0.97 obejmuje odchylenie standardowe wzrostu w populacji studentów I roku WI
#d)
#H0:m = 180, H1:m > 180
t.test(Ankieta.M$Wzrost,mu=180,alternative = 'g')
#t= 0.88954, df=98, p-value=0.1879
#alfa=0.05<p-value=0.1879
#brak podstaw do odrzucenia H0
#Na poziomie istnotnosci 0.05 nie ma podstaw do odrzucenia hipoteze H0 
#ze srednia wzrostu wzrostu w populacji studentow wynosi 180 centymetrow
#zatem wyniki proby nie potrwierdzaja przypuszczenia ze srednia wzrostu w
#populacji studentow jest wieksza niz 180

#Zad3
#a)
shapiro.test(Ankieta.K$Waga)
#W = 0.64168, p-value = 8.459e-05
#na poziomie istotnosci 
#alfa=0.05>p-value=8.459e-05
#sa podstawy do odrzucenia H0
stem(Ankieta.K$Waga)
Ankieta.K=Ankieta.K[-11,]
shapiro.test(Ankieta.K$Waga)
#W = 0.95224, p-value = 0.6951
#brak posataw do odrzucenia H0
#b)
t.test(Ankieta.K$Waga,conf.level=0.98)
# 53.71541 61.58459
#Przedzial liczbowy 53.7 i 61.6
#Z prawdopodobienstwiem 0.98 obejmuje nieznany rzeczywisty œrednia
#wage w populacji studentek 1 roku informatyki
#c)
przedzia³.odchylenie(Ankieta.K$Waga,0.95)
#3.033285    8.050759
#Przedzial ufnosci o koncach 3.0 i 8.1 dla poziomu ufnoœci 0.95 obejmuje odchylenie standardowe wagi w populacji studentek I roku WI
#d)
t.test(Ankieta.K$Waga,mu=70,alternative='l')
#t = -8.856, df = 9, p-value = 4.87e-06
#alfa=0.05<p-value = 4.87e-06
#Na poziomie istotnosci 0.05 sa podstawy do odrzucenia hipotezy H0
#zatem wyniki proby nie potrwierdzaja przypuszczenia ze srednia wzrostu w
#populacji studentek jest mniejsza niz 70
