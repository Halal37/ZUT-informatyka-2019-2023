#Zad1
przed.kuracja=c(225,236,312,238,241,196,205,259,218)
po.kuracji=c(216,195,245,235,221,170,180,265,179)
#zalozezie; normalnosc rozkladu roznicy zmiennnych
#H0: rozklad roznicy zmiennnych jest normalny
#H1: nie prawda, ze H0 H1:~H0
shapiro.test(przed.kuracja-po.kuracji)
#W = 0.96898, p-value = 0.8858
#alfa=0.01
#wniosek: brak podstaw do odrzucenia hipotezy H0

#test t Studenta dla prob zaleznych
#H0:m1-m2=0, H1:m1-m2>0
t.test(przed.kuracja,po.kuracji,alternative = 'g',paired=T)
#t = 3.3633, df = 8, p-value = 0.004942
#alfa=0.01
#Wniosek: Na poziomie istotnosci 0.01 odrzucamy hipoteze H0 i przyjmujemy hipoteze H1 
# czyli leczenie statynami skutecznie wplywa na obnizenie poziomu cholesterolu.
#zadanie2
#x-wysokosc y-temperatura
x=c(150,300,450,600,750,900,1200,1500,1800)
y=c(27.2,26,24.2,22.5,21.7,20.5,19,17.4,16)
#a) wykres punktow empirycznych
plot(x,y)

#b) wspolczynnik korelacji
cor(x,y)
#-0.9845745 
#Wartosc bliska jedynce wiec silna
#Interpretacja: pomiedzy wysokoscia nad poziomem morza a temperatura
#powietrza istnieje silna zaleznosc korelacyjna 
#ujemna tzn. im wyzej nad poziomem morza tym tempertatura powietrza nizsza

#c) przedzial ufnosci dla wspolczynnika korelacji
cor.test(x,y,conf.level = 0.95)
#-0.9968673 -0.9258359
#Interpretacja: przedzial liczbowy o koncach -0.9968673 -0.9258359
#z prawdopodobienstwem 0.95 obejmuje wspolczynnik korelacji miedzy wysokoscia nad 
#poziomem morza a temperatura powietrza. 

#d)liniowa funkcja regresji
lm(y~x)
#y=27.322424    x=-0.006719 
#Interpretacja wspolczynnika regresji: wspolczynnik regresji -0.007
#oznacza, ze ze wzrostem wysokosci nad poziomem morza 
# o 100 metrow spada srednio temperatura powietrza o okolo 0.7 stopnia 
#Celsjusza.

#e) wykres funkcji regresji 
abline(lm(y~x))

#f) test istotnosci wspolczynnika regresji
#H0: beta1=0, H1: beta1!=0
summary(lm(y~x))
#t=-14.89 p-value=1.48e-06=0.00000148
#alfa=0.02
#Wniosek: odrzucamy H0 na rzecz H1, zatem na poziomie istotnosci 0.02
#mozna stwierdzic, ze 
#wpsolczynnik regresji miedzy wysokoscia nad poziomem morza, a temperatura 
#powietrza jest istotny


#zad3 
#test niezaleznosci chi^2
#H0: X,Y sa niealezny, H1:~H0
chisq.test(cbind(c(152,52),c(8,188)))
#X-squared = 203.67, df = 1, p-value = 2.2e-16
#alfa=0.01
#Wniosek:Na poziomie istotnosci 0.01 odrzucamy H0 na rzecz H1, zatem
#mozna stwierdzic, ze rosliny cebuli wychodowane z wiekszych cebulek dymki
#wyrastaja czesciej w pedy kwiatostanowe

#Zad4
przed.dieta=c(87.5,56,67,82.5,92,59,90.5,80.5,65,92)
po.diecie=c(86,54,66,83,87,62,87,90,61,70)
#H0: rozklad roznicy zmiennnych jest normalny
#H1: nie prawda, ze H0 H1:~H0
shapiro.test(przed.dieta-po.diecie)
#alfa=0.05
#wniosek: Na poziomie istotnosci odrzucamy hipoteze H0 i przyjmujemy 
#hipoteze H1 zatem rozklad roznicy zmiennych nie jest normalny

#test Wilcoxona
#H0:m1-m2=0, H1:m1-m2>0
wilcox.test(przed.dieta,po.diecie,alternative = 'g',paired=T)
#alfa=0.05
#V = 40, p-value = 0.1162
#Wniosek: na poziomie istotnosci 0.05 brak podstaw do odrzucenia hipotezy H0,
#zatem nie mozna stwierdzic, ze diete wplywa na spadek wagi popoulacji kobiet

#zad5
zet=c(0.8,1.2,1.6,1.8,2.2,1.6,2.4,2.0)
zaz=c(6,10,12,15,18,15,20,16)
cor(zet,zaz)
#0.9811157
#Wniosek: istnieje silna zaleznosc miedzy liczba brakow a wielkoscia produkcji