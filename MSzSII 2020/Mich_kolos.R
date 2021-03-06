#Zadanie 4
#test niezaleznosci chi^2
#H0:X i Y i Z niezalezne, H1:~H0
chisq.test(cbind(c(25,10,5),c(45,60,35),c(20,40,70)))
#X-squared = 51.082, df = 4, p-value = 2.146e-10
#Wniosek: na poziomie istotnosci 0.01 odrzucamy hipoteze H0, zatem
#stopien palenia kawy ma wplyw na jej smak

#Zadanie 5
liczb_jed=c(10,12,8,13,7,9,15,11)
liczb_koliz=c(55,65,40,66,24,35,72,54)

#przedzial ufnosci dla wspolczynnika korelacji
cor.test(liczb_jed,liczb_koliz,conf.level = 0.98)
#0.6354763 0.9930771
#interpretacja: przedzial o konczach  0.635 i 0.993 z prawdopodobienstwem
#98% obejmuje nieznany wspolczynnik korelacji pomiedzy liczba przeplywajacych jednostek
#a liczba kolizji

lm(liczb_koliz~liczb_jed)
#liczb_koliz=-12.135 liczb_jed=  5.977
#Interpretacja wspolczynnka regresji: wspolczynnik regresji 5.98 oznacza, ze zwiekszenie liczby jednostek o tys. wiaze sie 
#ze wzrostem liczby kolizji srednio biorac o okolo 6.

#test istotnosci wspolczynnika regresji
#H0: beta1=0, H1: beta1!=0
summary(lm(liczb_koliz~liczb_jed))
#F-statistic: 50.95 on 1 and 6 DF,  p-value: 0.0003808
#alfa=0.01
#Wniosek: na poziomie istotnosci 0.01 odrzucamy hipoteze H0,
#zatem mozna stwierdzic wspolczynnik regresji liczby kolizji wzgledem
#liczby przeplywajacych jednostek jest istotny

#Zadanie 1
table(Ankieta$M.zamieszk)
#Metro_wszycy=3600 happy-1480, nie happy 1588
#Autobusy_wszyscy=2500, happy=1200, neg=1000
prop.test(1588,3600,conf.level = 0.99)
#0.4197850 0.4626553

#test dla dw�ch wska�nik�W struktury
#H0:pM=pA, H1:pM!=pA
prop.test(c(1588,1000),c(3600,2500),alternative = 't')
#alfa=0.06
#X-squared = 10.041, df = 1, p-value = 0.001531
#Wniosek:na poziomie istotnosci 0.06 odrzucamy hipoteze H0,
#na rzecz hipotezy H1, a zatem odsetki osob niezadowolonych z kofortu
#jazdy warszawskim metrem oraz stolecznymi autobusami roznia sie

#Zadanie 3
ryby=c(15,12,10,18,14,17,11,22,19,13,16,16,17,18)
rodz_ryb=c(rep("dorsz",5),rep("sledz",5),rep("szczupak",4))

#zalozenie: jednorodnosc wariancji
#H0: var1=var2=var3, H1~H0
bartlett.test(ryby~rodz_ryb)
#alfa=0.05
#Bartlett's K-squared = 4.9939, df = 2, p-value = 0.08233
#Wniosek: na poziomie istotnosci 0.05 brak podstaw do odrzucenia hipotezy H0,
# o jednakowych wariancjach zawartosci bialka w miesach ryb

# test ANOVA
#H0 m1=m2=m3 (brak wp�ywu), H1:~H0 (wplyw istotny)
anova(aov(ryby~rodz_ryb))
#alfa=0.05
#F-value= 1.143  p-value=0.354
#Wniosek: na poziomie istotnosci 0.05, brak podstaw do odrzucenia hipotezy H0,
#o rownosci przecietnych zawartosci bialka w miesach badanych ryb

#Zadanie 2
p.opisowe  = function(x){
  srednia = mean(x)
  mediana = median(x)
  kwartyl.1 = quantile(x,1/4)
  kwartyl.3 = quantile(x,3/4)
  minimum = min(x)
  maximum = max(x)
  rozstep.empiryczny = max(x)-min(x)
  rozstep.miedzykwartylowy = IQR(x)
  odchylenie.standardowe = sd(x)
  wspolczynnik.zmiennosci = sd(x)/mean(x)
  wspolczynnik.asymetrii = skewness(x)
  wspolczynnik.skupienia = kurtosis(x)
  rbind(srednia,mediana,kwartyl.1,kwartyl.3,minimum,maximum,rozstep.empiryczny,rozstep.miedzykwartylowy,odchylenie.standardowe,wspolczynnik.zmiennosci,wspolczynnik.asymetrii,wspolczynnik.skupienia,deparse.level = 1)
}

pracownicy=c(17.3,17.8,17.3,16.3,17.8,17.1,17.6,17,17.1,18.6,17.9,17,18.1,17,17.6,18.7,17.9,17.5,17,18.3)
rodz_prac=c(rep("bez_szkolenia",9),rep("po_szkoleniu",11))
p.opisowe(pracownicy)

#4 wspolczynnik.zmiennosci=0.03451999 pracownicy sa slabo zroznicowani wgledem wydajnosci pracy
#5 kwartyl.gorny=17.90000000 wydajnosc pracy 75% pracownikow nie przekorczyla tej wartosci
#6 wspolczynnik.asymetrii=0.15951872  wydajnosc pracy charakteryzuje sie slaba aymetria prawostronna
#7
przedzia�.odchylenie=function(x,uf){
  n=length(x)
  q1=qchisq((1+uf)/2,n-1)
  q2=qchisq((1-uf)/2,n-1)
  ocena.dolna=sqrt((n-1)*var(x)/q1)
  ocena.g�rna=sqrt((n-1)*var(x)/q2)
  cbind(ocena.dolna,ocena.g�rna)
}
przedzia�.odchylenie(pracownicy,0.99)
#0.4250177    1.009129
#Przedzia� ufno�ci o ko�cach 0.43 i 1.01 dla poziomu ufno�ci 0.99 obejmuje odchylenie standardowe wydajnosci w populacji pracownikow zakladu
#9
#H0:m = 17.2, H1:m > 17.2
t.test(pracownicy,mu=17.2,alternative = 'g')
#alfa=0.05
#t = 2.5475, df = 19, p-value = 0.009832
#Wniosek na poziomie istotnosci 0.05 odrzucamy hipoteze H0 i przyjmujemy hipoteze H1
#zatem mozna stwierdzic, ze srednia wydajnosc pracownikow w populacji 
#jest wieksza niz 17.2 szt/h

#zaloeznie 1 normalnosc rozkladow
#H01:rozklad wydajnosci pracy pracownikow bez przeszkolenia jest normalny, H11:~H01
#H02:rozklad wydajnosci pracy pracownikow po przeszkoleniu jest normalny, H12:~H02
by(pracownicy,rodz_prac,shapiro.test)
#alfa=0.01
#bez_przeszkolenia W = 0.91201, p-value = 0.3302
#z_przeszkoleniem W = 0.91959, p-value = 0.3153
#Wniosek: napoziomie istotnosci 0.01 brak postaw do odrzucenia hiptezy H0, zatem 
#rozklad wydajnosci pracy pracownikow bez przeszkolenia jest normalny

#Wniosek: napoziomie istotnosci 0.01 brak postaw do odrzucenia hiptezy H0, zatem 
#rozklad wydajnosci pracy pracownikow z przeszkoleniem jest normalny

#zalozenie 2: jednorodnosc wariancji
#H0: var1=var2, H1~H0
bartlett.test(pracownicy~rodz_prac)
#alfa=0.01
#Bartlett's K-squared = 0.66391, df = 1, p-value = 0.4152
#Wniosek: Na poziomie istotnosci 0.01 brak podstaw do odrzucenia hipotezy H0,
#o jednorodnosci wariancji wydajnosci pracownikow bez i z przeszkoleniem

# test ANOVA
#H0 m1=m2 (brak wp�ywu), H1:~H0 (wplyw istotny)
anova(aov(pracownicy~rodz_prac))
#alfa=0.01
#F-value=4.4076 p-value=0.05015 
#Wniosek: na poziomie istotnosci 0.01 brak podstaw by odrzucic hipoteze H0,
# nie mozemy stwierdzic, by przeszkolenie wplywalo na wydajnosc pracy pracownikow


temperatura=c(37.0,36.8,37.9,37.2,38.0,37.0,37.1,36.5,36.5,37.0,37.5,37.8,37.8,38.0,37.2,37.2,37.0,37.5,37.3,37.9)
lek=c(rep("A",10),rep("B",10))
p.opisowe(temperatura)
#kwartyl.1=37.00000000 temperatura 25% pracjentow nie przekracza tej wartosci 
#wspolczynnik.zmiennosci   0.01265839 pacjaenci sa slabo zroznicowani wgledem temperatury ciala
#wspolczynnik.asymetrii   -0.00572055 temperatura ciala charakteryzuje sie slaba asymetria lewostronna
przedzia�.odchylenie(temperatura,0.997)
#0.315651   0.8602514
#Przedzia� ufno�ci o ko�cach 0.32 i 0.86 dla poziomu ufno�ci 0.997 obejmuje odchylenie standardowe temperatury w populacji pacjentow

#H0 rozklad jest normalny H1:~H0
shapiro.test(temperatura)
#alfa=0.05
#W = 0.93126, p-value = 0.1633
#Wniosek: na poziomie istotnosci 0.05, brak podstaw do odrzucenia hipotezy H0,
#zatem rozklad jest normalny

t.test(temperatura,conf.level = 0.997)
#36.95087 37.66913

#H0:m = 38, H1:m < 38
t.test(temperatura,mu=38,alternative = 'l')
#t = -6.5337, df = 19, p-value = 1.473e-06
#alfa=0.05
#Wniosek: na poziomie istotnosci 0.05 odrzucamy hipoteze H0,
#na rzecz hipotezy H1 zatem srednia temperatura ciala chorych jest istotnie nizszaniz 38 stopni Celsjusza

#zaloeznie 1 normalnosc rozkladow
#H01:rozklad temperatur osob przyjmujacych lek A jest normalny, H11:~H01
#H02:rozklad wydajnosci pracy pracownikow po przeszkoleniu jest normalny, H12:~H02
by(temperatura, lek,shapiro.test)
#alfa=0.05
#Wniosek: na poziomie istotnosci 0.05 brak podstaw do odrzucenia hiptezy H0,
#o normalnosci rozkladu temperatur osob przyjmujacych lek A

#zalozenie 2: jednorodnosc wariancji
#H0: var1=var2, H1~H0
bartlett.test(temperatura~lek)
#alfa=0.05
#Bartlett's K-squared = 1.2603, df = 1, p-value = 0.2616
#Wniosek: na poziomie istotnosci 0.05, brak podstaw do odrzucenia hipotezy H0,
#o jednorodnosci wariancji osob przyjmujacych lek A i B


temperatura_a=c(37.0,  36.8,  37.9,  37.2,  38.0,  37.0,  37.1,  36.5,  36.5,  37.0)
temparatura_b=c(37.5,  37.8,  37.8,  38.0,  37.2,  37.2,  37.0,  37.5,  37.3,  37.9)
#H0 m1=m2 (brak wp�ywu), H1:~H0 (wplyw istotny)
anova(aov(temperatura~lek))
#F-value=4.7306 p-value=0.0432
#Wniosek: na poziomie istotnosci 0.05 odrzucamy hipoteze H0, na rzecz hipotezy H1
#zatem sotosowanie rodzaju leku ma wplyw na temperature, a zatem dzialanie leku A jest lepsze


metoda=c(2,  5,  3,  6,  4,10,  12,  12,  14,20,  23,  26,  24,  22)
rodzaj=c(rep("A",5),rep("B",4),rep("C",5))
#zalozenie: jednorodnosc wariancji
#H0: var1=var2=var3, H1~H0
bartlett.test(metoda~rodzaj)
#alfa=0.05
#Bartlett's K-squared = 0.5261, df = 2, p-value = 0.7687
#Wniosek: na poziomie istotnosci 0.05 brak podstaw do odrzucenia hipotezy H0,
# o jednakowych wariancjach wydajnosci pracy roznych metod produkcji pewnego wyrobu

# test ANOVA
#H0 m1=m2=m3, H1:~H0
anova(aov(metoda~rodzaj))
#alfa=0.05
#F-value= 131.56  p-value=2.085e-08
#Wniosek: na poziomie istotnosci 0.05, odrzucamy hipoteze H0 i przyjmujemy hipoteze H1, zatem
# srednia wydajnosc pracy przy produkcji rozni sie w zaleznosci od metody

#Zadanie 4
#test niezaleznosci chi^2
#H0:X i Y niezalezne, H1:~H0
chisq.test(cbind(c(37,9),c(13,41)))
#X-squared = 29.348, df = 1, p-value = 6.048e-08
#Wniosek: na poziomie istotnosci 0.01 odrzucamy hipoteze H0, zatem
#podwyzszone cisnienie i choroba wiencoa sa ze soba powiazane


#Zadanie 5
wielkosc_prod=c(1,2,3,4,5,6,7)
zuzycie_sur=c(3.3,4.1,4.4,5.0,5.2,6.1,6.6)

#przedzial ufnosci dla wspolczynnika korelacji
cor.test(wielkosc_prod,zuzycie_sur,conf.level = 0.99)
# 0.8887204 0.9993180
#interpretacja: przedzial o konczach  0.635 i 0.993 z prawdopodobienstwem
#98% obejmuje nieznany wspolczynnik korelacji pomiedzy liczba przeplywajacych jednostek
#a liczba kolizji

lm(zuzycie_sur~wielkosc_prod)
#liczb_koliz=2.857 liczb_jed=  0.525 
#Interpretacja wspolczynnka regresji: wspolczynnik regresji 0.525 oznacza, ze zwiekszenie produkcji wyrobu o tys. wiaze sie 
#ze wzrostem brakow pewnego surowca srednio biorac o okolo 525.

#test istotnosci wspolczynnika regresji
#H0: beta1=0, H1: beta1!=0
summary(lm(zuzycie_sur~wielkosc_prod))
#F-statistic: 276.3 on 1 and 5 DF,  p-value: 1.439e-05
#alfa=0.05
#Wniosek: na poziomie istotnosci 0.01 odrzucamy hipoteze H0,
#zatem mozna stwierdzic wspolczynnik regresji zuzytych surowcow wzgledem
#wielkosci produkcji jest istotny

#Zadanie 1
table(Ankieta$M.zamieszk)
#Metro_wszycy=3600 happy-1480, nie happy 1588
#Autobusy_wszyscy=2500, happy=1200, neg=1000
prop.test(195,200,conf.level = 0.99)
#0.9243299 0.9928481

#test dla dw�ch wska�nik�W struktury
#H0:pM=pA, H1:pM!=pA
prop.test(c(1588,1000),c(200,200),alternative = 't')
#alfa=0.06
#X-squared = 10.041, df = 1, p-value = 0.001531
#Wniosek:na poziomie istotnosci 0.06 odrzucamy hipoteze H0,
#na rzecz hipotezy H1, a zatem odsetki osob niezadowolonych z kofortu
#jazdy warszawskim metrem oraz stolecznymi autobusami roznia sie

#H0: X,Y sa niealezny, H1:~H0
chisq.test(cbind(c(9,5),c(191,195)))
#alfa=0.05
#X-squared = 0.66617, df = 1, p-value = 0.4144
#Wniosek: na poziomie istotnosci 0.05, brak podstaw do odrzucenia Hipotezy H0,
#zatem nie mozna stwierdzic by 



ucz=c(27,25,8,9,5,25,26,17,18,20,11,14,16,15)
ucz_rodza=c(rep("A",5),rep("B",5),rep("C",4))

#zalozenie: jednorodnosc wariancji

#H0: var1=var2=var3, H1~H0
bartlett.test(ucz~ucz_rodza)
#alfa=0.05
#Bartlett's K-squared = 6.7732, df = 2, p-value = 0.03382
#Wniosek: na poziomie istotnosci 0.05 odzrzucamy hipoteze H0, na rzecz hipotezy H1,
#zatem wariancje b��d�w uczni�w r�nych uczelni nie s� jednorodne


#H0 me1=me2, H1:~H0
kruskal.test(ucz~ucz_rodza)
#alfa=0.05
#Kruskal-Wallis chi-squared = 3.5736, df = 2, p-value = 0.1675
#Wniosek: na poziomie istotno�ci 0.05 nie ma podstaw do odrzucenia H0,
#nie mo�na potwierdzi� istotnego wplywu uczelni na poziom wiedzy ze statystyki matematycznej w populacji studentow.

#Metro_wszycy=3600 happy-1480, nie happy 1588
#Autobusy_wszyscy=2500, happy=1200, neg=1000
prop.test(195,200,conf.level = 0.99)
#0.9243299 0.9928481

#test dla dw�ch wska�nik�W struktury
#H0:pM=pA, H1:pM!=pA
prop.test(c(1588,1000),c(200,200),alternative = 't')
#alfa=0.06
#X-squared = 10.041, df = 1, p-value = 0.001531
#Wniosek:na poziomie istotnosci 0.06 odrzucamy hipoteze H0,
#na rzecz hipotezy H1, a zatem odsetki osob niezadowolonych z kofortu
#jazdy warszawskim metrem oraz stolecznymi autobusami roznia sie

#H0: X,Y sa niealezny, H1:~H0
chisq.test(cbind(c(9,5),c(191,195)))
#alfa=0.05
#X-squared = 0.66617, df = 1, p-value = 0.4144
#Wniosek: na poziomie istotnosci 0.05, brak podstaw do odrzucenia Hipotezy H0,
#zatem nie mozna stwierdzic by 


#H0:p = 38%, H1:p < 38%
prop.test(68,200,p=0.38,alternative='l')
#alfa=0.03
#X-squared = 1.1938, df = 1, p-value = 0.1373
#Wniosek: na poziomie istotnosci 0.03 brak podstaw do odrzucenia hipotezy
#H0 zatem nie mo�na stwierdzi�, by odsetek pal�cych student�w Akademii Morskiej by� istotnie mniejszy

porzeczki=c(48,42,50,56,55,45,60,44,40,41,42,38,44,34,39,40,41,45,43,35)
porzeczki_rodz=c(rep("Cza",8),rep("Czerw",12))
p.opisowe(porzeczki)
#kwartyl g�rny               45.7500000 poziom witaminy C 75% porzeczek nie przekroczy�a tej warto�ci
#odchylenie.standardowe    6.7893105 poziom witaminy C odchyla si� od �redniego poziomu witaminy C o oko�o t� warot��
#wspolczynnik.skupienia    3.1196181 rozk�ad poziomu witaminy C charakteryzuje si� wy�szym skupieniem wok� �redniej ni� rozk�ad normalny


#H0 rozklad jest normalny H1:~H0
shapiro.test(porzeczki)
#alfa=0.05
#W = 0.92336, p-value = 0.115
#Wniosek: na poziomie istotnosci 0.05, brak podstaw do odrzucenia hipotezy H0,
#o normalnym rozkladzie witamyny C w porzeczkach

t.test(porzeczki,conf.level = 0.96)
#40.75296 47.44704
#Przedzia� ufno�ci o ko�cach 40.75 i 47.45 dla poziomu ufnosci 0.96 obejmuje wartosc oczekiwanej witaminy C w porzeczkach

#H0:m = 46, H1:m < 46
t.test(porzeczki,mu=46,alternative = 'l')
#t = -1.2515, df = 19, p-value = 0.113
#Wniosek: na poziomie istotnosci 0.05, brak podstaw do odrzucenia hipotezy H0,
#zatem nie mo�na stwierdzi�, by �rednia zawarto�� witaminy C w porzeczkach by�a istotnie mnniejsza ni� 46 mg.


#H01:rozklad temperatur osob przyjmujacych lek A jest normalny, H11:~H01
#H02:rozklad wydajnosci pracy pracownikow po przeszkoleniu jest normalny, H12:~H02
by(porzeczki, porzeczki_rodz,shapiro.test)
#H0:rozklad witaminy C w czerwonych porzeczkach jest normalny, H1:~H0
#W = 0.94458, p-value = 0.6566
#Wniosek: na poziomie istotno�ci 0.06 brak podstaw do odrzucenia hipotezy H0, o 
#normalno�ci rozk�adu witaminy C w czerwonych porzeczkach

#H0:rozklad witaminy C w czarnych porzeczkach jest normalny, H1:~H0
#W = 0.95638, p-value = 0.7313
#Wniosek: na poziomie istotno�ci 0.06 brak podstaw do odrzucenia hipotezy H0, o 
#normalno�ci rozk�adu witaminy C w czarnych porzeczkach




#H0: var1=var2, H1~H0
var.test(porzeczki~porzeczki_rodz)
#alfa=0.06
#F = 3.7456, num df = 7, denom df = 11, p-value = 0.05058
#Wniosek: Na poziomie istotnosci 0.06 odrzucamy hipoteze H0, na rzecz
# hipotezy H1, zatem wariancje w witaminy c w czarnych i czerwonych porzeczkach nie s� jednorodne


#H0 m1=m2 , H1:~H0 
t.test(porzeczki~porzeczki_rodz)
#alfa=0.06
#t = 3.9813, df = 9.5216, p-value = 0.00286
#Wniosek: na poziomie istotnosci 0.06 odrzucamy hipoteze H0 na rzecz hipotezy H1
# zatem �rednie warto�ci witaminy C w porzeczkach czarnych i czerwonych r�ni si�

przed_wyp=c(0.22,0.18,0.16,0.19,0.20,0.23,0.17,0.25)
po_wyp=c(0.28,0.25,0.20,0.30,0.19,0.26,0.28,0.24)

#H0: rozklad roznicy zmiennnych jest normalny
#H1: nie prawda, ze H0 H1:~H0
shapiro.test(przed_wyp-po_wyp)
#W = 0.91488, p-value = 0.3897
#Wniosek: na poziomie istotno�ci 0.03, brak podstaw do odrzucenia Hipotezy H0,
#o normalnosci rozk�adu czasu reakcji na bodziec

#H0:m1=m2, H1:m1<m2
t.test(przed_wyp,po_wyp,alternative = 'l',paired=T)
#t = -3.0151, df = 7, p-value = 0.9902
#Wniosek: na poziomie istotno�ci 0.05, odrzucamy hipoteze H0, na rzecz hipotezy H1 zatem alkohol ma istotny wp�yw na czas reakcji kierowc�w 


pnorm(1025,1000,50)-pnorm(975,1000,50)
# 20 dziew 30 boi
#srednia 3200 g dziew 3700 boi
#odchylenie 780 i 850 

#5.78
#25 osob
#conf 0.98

klasyy=c(3.71,4.28,3.43,3.09,4.50,2.95,3.38,4.98,3.20,4.05,3.20,3.1,3.38,4.06,3.60,2.80,3.81,4.50,4.11,4.85)
klasyy_rodz=c(rep("1",11),rep("2",9))
p.opisowe(klasyy)
#               3.2000000 �rednia ocen u 25% uczni�w nie przekroczy�a tej warto�ci
#   0.6429365 oceny odchyla si� od �redniej ocen o oko�o t� warto��
#   2.0524506 rozk�ad �redniej uczniow charkteryzuje si� ni�szym skupieniem wok� �redniej ni� rozk�ad normalny

#odchylenie.standardowe    6.7893105 poziom witaminy C odchyla si� od �redniego poziomu witaminy C o oko�o t� warot��
#wspolczynnik.skupienia    3.1196181 rozk�ad poziomu witaminy C charakteryzuje si� wy�szym skupieniem wok� �redniej ni� rozk�ad normalny
#H0 rozklad jest normalny H1:~H0
shapiro.test(klasyy)
#W = 0.95133, p-value = 0.3877
#Wniosek: na poziomie istotnosci 0.05, brak podstaw do odrzucenia hipotezy H0,
#o normalnym rozkladzie ocen uczniow

t.test(klasyy,conf.level = 0.98)
#3.383911 4.114089
#Przedzia� ufno�ci o ko�cach 3.38 i 4.11 dla poziomu ufnosci 0.98 obejmuje wartosc oczekiwanej oceny uczniow

#H0:m = 3.45, H1:m > 3.45
t.test(klasyy,mu=3.45,alternative = 'g')
#t = 2.0798, df = 19, p-value = 0.02566
#Wniosek: na poziomie istotno�ci odrzucamy hipoteze H0 i przyjmujemy hipotez� H1, a zatem �rednia ocen uczni�w klas pierwszych i drugich jest istotnie wy�sza ni� 3.45

#H0 rozklad jest normalny H1:~H0
by(klasyy,klasyy_rodz,shapiro.test)
#klasa 1
#alfa 0.05
#W = 0.91394, p-value = 0.2713
#Wniosek: na poziomie istotno�ci 0.05 brak podstaw do odrzucenia hipotezy H0, o normalno�ci rozk��du ocen uczni�w klas pierwszych

#klasa 2
#alfa 0.01
#W = 0.98751, p-value = 0.9917
#Wniosek: na poziomie istotno�ci 0.01 brak podstaw do odrzucenia hipotezy H0, o normalno�ci rozk��du ocen uczni�w klas drugich


#H0: var1=var2, H1~H0
var.test(klasyy~klasyy_rodz)
#F = 1.0043, num df = 10, denom df = 8, p-value = 0.9848
#Wniosek na poziomie istotno�ci 0.01 brak podstaw do odrzucenia Hipotezy H0, o jedno�ci wariancji ocen uczniow 

#H0 m1=m2, H1:m1<m2
t.test(klasyy~klasyy_rodz,var.equal=TRUE,alternative="l")
#t = -0.32003, df = 18, p-value = 0.3763
#Wniosek na poziomie istotno�ci 0.05 brak podstaw do odrzucenia hipotezy H0, a zatem nie mo�na stwierdzi�, by �rednia ocen uczni�w klas 2 by�a istotnie wi�ksz ni� uczni�w klas 1

sol=c(1.5,2.5,2.0,3.5,3.0,2.3,4.0,4.4,3.5,5.0,4.5,5.5)
sol_rodz=c(rep("1",3),rep("5",3),rep("10",3),rep("20",3))

#H0: var1=var2=var3=var4, H1~H0
bartlett.test(sol~sol_rodz)
#Bartlett's K-squared = 0.15047, df = 3, p-value = 0.9852
#Wniosek: na poziomie istotnosci 0.03 brak podstaw do odrzucenia hipotezy H0, a zatem wariancje soli w iskrze pstrz�ga s� jednorodne
#H0 m1=m2=m3=m4 (brak wp�ywu), H1:~H0 (wplyw istotny)
anova(aov(sol~sol_rodz))
#F-value= 18.887 p-value=0.0005474
#Wniosek: na poziomie istotnosci 0.03 odrzucamy hipoteze H0 i przyjmujemy hipoteze H1, wi�c �rednia zawarto�� procentowa soli r�ni w zale�no�ci od czasu solenia

#160 68 92
16
#H0:p = 35%, H1:p > 35%
prop.test(68,160,p=0.38,alternative='g')
#X-squared = 1.1908, df = 1, p-value = 0.1376
17
#Wniosek: Na poziomie istotno�ci 0.05, brak podstaw do odrzucenia hipotezy H0, a zatem nie mo�na stwierdzi�, �e wi�cej ni� 35% pracownik�w tego zak�adu ma zak��cenia s�uchu


przed_tr=c(16,13,14,21,19,18.5,28,17)
po_tr=c(21,17,20,26.5,23.5,22,21,18)
#H0 rozklad jest normalny H1:~H0
shapiro.test(przed_tr-po_tr)
#Wniosek: poziomie istotno�ci 0.03 odrzucamy hipoteze H0, na rzecz hipotezy H1,
#zatem rozk�ad r�nicy wynik�w test�w nie jest normalny

#test Wilcoxona
#H0:m1=m2, H1:m1<m2
wilcox.test(przed_tr,po_tr,alternative = 'l',paired=T)
#V = 8, p-value = 0.09766
#Wniosek: na poziomie istotno�ci 0.03 brak podstaw do odrzucenia hipotezy H0, zatem nie mo�emy stwierdzi�, by trening zwi�ksza� liczb� zapami�tanych przez uczni�w element�w

czas_prac=c(1,2,3,4,5,6,7,8)
wydajnosc_prac=c(18,20,18,17,15,15,14,12)

cor.test(czas_prac,wydajnosc_prac,conf.level = 0.98)
#-0.9916883 -0.5775550
#interpretacja: przedzial o koncach  -0.992 i -0.578 z prawdopodobienstwem
#98% obejmuje nieznany wspolczynnik korelacji pomiedzy czasem pracy
#a wydajnoscia

lm(wydajnosc_prac~czas_prac)
#wydajnosc_prac=20.5714     czas_prac =-0.9881
#Interpretacja wspolczynnka regresji: wspolczynnik regresji -0.9881 oznacza, �e zwiekszenie czasu pracy o tys. wia�e si� 
#ze spadkiem wydajno�ci pracy �rednio o oko�o 988 

#H0: beta1=0, H1: beta1!=0
summary(lm(wydajnosc_prac~czas_prac))
#F-statistic: 41.92 on 1 and 6 DF,  p-value: 0.0006446
#Wniosek: na poziomie istotno�ci 0.02, mamy podstawy by odrzuci� hipoteze H0 i przyj�� hipoteze H1, zatem
#mo�na stwierdzi�, �e wspolczynnik regresji wydajno�ci pracy wzgledem
#czasu pracy jest istotny

#przedzial ufnosci dla wspolczynnika korelacji
cor.test(wielkosc_prod,zuzycie_sur,conf.level = 0.99)
# 0.8887204 0.9993180
#interpretacja: przedzial o konczach  0.635 i 0.993 z prawdopodobienstwem
#98% obejmuje nieznany wspolczynnik korelacji pomiedzy liczba przeplywajacych jednostek
#a liczba kolizji

lm(zuzycie_sur~wielkosc_prod)
#liczb_koliz=2.857 liczb_jed=  0.525 
#Interpretacja wspolczynnka regresji: wspolczynnik regresji 0.525 oznacza, ze zwiekszenie produkcji wyrobu o tys. wiaze sie 
#ze wzrostem brakow pewnego surowca srednio biorac o okolo 525.

#test istotnosci wspolczynnika regresji
#H0: beta1=0, H1: beta1!=0
summary(lm(zuzycie_sur~wielkosc_prod))
#F-statistic: 276.3 on 1 and 5 DF,  p-value: 1.439e-05
#alfa=0.05
#Wniosek: na poziomie istotnosci 0.01 odrzucamy hipoteze H0,
#zatem mozna stwierdzic wspolczynnik regresji zuzytych surowcow wzgledem
#wielkosci produkcji jest istotny


sery=c(30.5,31.2,29.9,31.2,32.3,29.1,28.2,28.1,26.4,26.8,26.8,26.2,26.5,26.1,25.2,28.8,29.1,29.2,26.1,27.2)
sery_rodz=c(rep("Lato",10),rep("Zima",10))
p.opisowe(sery)
shapiro.test(sery)
4
#H0 rozklad jest normalny H1:~H0
#W = 0.94257, p-value = 0.268
#Wniosek: na poziomie istotno�ci 0.05 brak podstaw do odrzucenia hipotezy H0, o normalnym rozk�adzie t�uszczu w serach

t.test(sery,conf.level = 0.965)
#1.518463    3.067832

przedzia�.odchylenie(sery,0.965)
#1.518463    3.067832
#interpretacja: z prawdopodobie�stwem 96,5% odchylenie standardowe znajduje si� w przedziale 1.52 i 3.08

t.test(klasyy,mu=3.45,alternative = 'g')


by(sery,sery_rodz,shapiro.test)
8
#H0 rozklad t�uszcu w serach letnich jest normalny H1:~H0
#Lato W = 0.95614, p-value = 0.7411
#Wniosek: Na poziomie istotno�ci brak podstaw do odrzucenia hipotezy H0, na rzecz hipotezy H1,
#o normalno�ci rozk�ad�w t�uszcz�w w serze letnim

9
#H0 rozklad t�uszczu w serach zimowych jest normalny H1:~H0
#zima W = 0.87823, p-value = 0.1245
#Wniosek: Na poziomie istotno�ci brak podstaw do odrzucenia hipotezy H0, na rzecz hipotezy H1,
#o normalno�ci rozk�ad�w t�uszcz�w w serze zimowym


bartlett.test(sery~sery_rodz)
10
#H0: var1=var2, H1~H0
#Bartlett's K-squared = 0.92406, df = 1, p-value = 0.3364
#Wniosek: na poziomie istotnosci 0.01 brak podstaw do odrzucenia hipotezy H0, a zatem wariancje t�uszczu w serach s� jednorodne

anova(aov(sery~sery_rodz))
11
#H0 m1=m2, H1:~H0 
#F-value= 8.5168 p-value=0.009174
12
#Wniosek: na poziomie istotnosci 0.01 odrzucamy hipoteze H0 i przyjmujemy hipoteze H1, wi�c zawarto�� t�uszczu w serze zale�y od pory roku

testy=c(11,12,13,12,10,15,18,21,23,24,30,25,32,28,20)
testy_rodz=c(rep("15-20",5),rep("20-25",5),rep("25-30",5))

bartlett.test(testy~testy_rodz)
13
#H0: var1=var2=var3, H1~H0
#Bartlett's K-squared = 5.638, df = 2, p-value = 0.05967
#Wniosek: na poziomie istotnosci 0.05 brak podstaw do odrzucenia hipotezy H0, a zatem wariancje wynik�w kolokwium s� jednorodne

anova(aov(testy~testy_rodz))
14
#H0 m1=m2=m3 , H1:~H0 
#F-value= 24.146 p-value=6.216e-05
15
#Wniosek: na poziomie istotnosci 0.05 odrzucamy hipoteze H0 i przyjmujemy hipoteze H1, wi�c na wyniki kolowkium ma wp�yw ich czas

#Fryz 492 badanych 94 modny wyniki z�e 51 wszyscy �le uczcz�cy 245

#Metro_wszycy=3600 happy-1480, nie happy 1588
#Autobusy_wszyscy=2500, happy=1200, neg=1000
prop.test(51,94,conf.level = 0.96)
16
#0.4322955 0.6489758
#Z prawdopodobie�stwem 96% mo�na stwierdzi�, �e odsetek modnych m�odzie�c�w maj�cych s�abe wyniki w nauce znajduje si� w przedziale 0.43 do 0.65

#test dla dw�ch wska�nik�W struktury
#H0:pModni=pnie_Modni, H1:pModni>pnie_Modni
prop.test(c(51,194),c(94,401),alternative = 'g')
17
#X-squared = 0.82996, df = 1, p-value = 0.1811
18
#Wniosek: na poziomie istotno�ci 0.02 brak podstaw do odrzucenia hipotezy H0, a zatem nie mo�na stwierdzi�, by odsetek m�odzie�c�w o s�abych wynikach w nauce by� istotnie wy�szy ni� dla pozosta�ych m�odzie�c�w


wiek=c(26,30,22,28,32,25,27,28,24,33,20,37)
bledy=c(6.48,3.56,4.94,3.69,5.67,9.18,5.29,2.74,5.87,5.66,6.00,5.53)
cor.test(wiek,bledy,conf.level = 0.99)
21
#-0.7865447  0.5749687
#Interpretacja: przedzial o konczach  -0.787 i 0.575 z prawdopodobienstwem
#99% obejmuje nieznany wspolczynnik korelacji pomiedzy wiekiem badanych
#a liczba b��d�w


22
#liczb_koliz=7.28571  liczb_jed=  -0.06873 
#Interpretacja wspolczynnka regresji: wspolczynnik regresji -0.06873  oznacza, ze wzrost wieku o 10 lat wi��e si� z 
#ze spadkiem liczby bl�d�w 0.6.

23
#H0: beta1=0, H1: beta1!=0
#F-statistic: 0.4207 on 1 and 10 DF,  p-value: 0.5312
24
#Wniosek: na poziomie istotnosci 0.02 brak podstaw do odrzucenia hipotezy H0,
#zatem na podstawie pr�bki nie mo�na stwierdzi�, by wiek wp�ywa� na zmian� liczby pope�nianych b��d�w

czas_y=c(33.9,36.9,48.1,44.4,38.3,39.8,46.6,42.4,45.1,51.4,47,48,39.2,58.4,42.8,28.6,68.4,40,18.3,59.6,50.6,57.3,60.1,47.8,27.1)
czasy__rodz=c(rep("A",12),rep("B",13))
p.opisowe(czas_y)
#kwartyl.1                39.2000000 25% kajak�w nie przekroczy�o tej warto�ci czasu przep�yni�cia trasy
#odchylenie.standardowe   11.2871047 czas przep�yni�cia trasy przez kajaki odchyla si� �rednio o t� warto��
#wspolczynnik.asymetrii   -0.1747166 rozk�ad czasu przep�yni�cia trasy charakteryzuje si� s�ab� asymetri� lewostron�
4
#H0 rozklad czasu przep�yni�cia trasy przez przez kajki jest normalny H1:~H0
shapiro.test(czas_y)
#W = 0.98334, p-value = 0.9424
#Wniosek: na poziomie istotno�ci 0.01 brak podstaw do odrzucenia hipotezy H0, a zatem rozk�ad czasu przep�yni�cia trasy przez kajaki jest normalny
5
t.test(czas_y,conf.level = 0.91)
#40.81587 48.79213
#Przedzia� ufno�ci o ko�cach 40.82 i 48.79 dla poziomu ufnosci 0.91 obejmuje �rednii czas przep�yni�cia trasy

6
#H0:m = 50.6, H1:p != 50.6
t.test(czas_y,mu=50.6)
#t = -2.5675, df = 24, p-value = 0.0169
#Wniosek: na poziomie istno�ci 0.01 brak podstaw do odrzucenia hipotezy H0, a zatem �redni czas przep�yni�cia trasy mo�e wynosi� 50.6

7
by(czas_y,czasy__rodz,shapiro.test)
#H0 rozklad czasu przep�yni�cia trasy przez przez kajki A jest normalny H1:~H0
#W = 0.95708, p-value = 0.7415
#Wniosek: na poziomie istotno�ci 0.01 brak podstaw do odrzucenia hipotezy H0, a zatem rozk�ad czasu przep�yni�cia trasy przez kajaki A jest normalny

#H0 rozklad czasu przep�yni�cia trasy przez przez kajki B jest normalny H1:~H0
#W = 0.95544, p-value = 0.6825
#Wniosek: na poziomie istotno�ci 0.01 brak podstaw do odrzucenia hipotezy H0, a zatem rozk�ad czasu przep�yni�cia trasy przez kajaki B jest normalny

#H0: var1=var2, H1~H0
bartlett.test(czas_y,czasy__rodz)
#Bartlett's K-squared = 10.077, df = 1, p-value = 0.001502
#Wniosek: na poziomie istotno�ci 0.01 odrzucamy hipoteze H0 i przyjmujemy hipoteze H1, 
#a zatem wariancje kajak�w A i kajak�w B nie s� jednorodne

8
#H0 meA=meB , H1:meA<meB
kruskal.test(czas_y,czasy__rodz,alternative="l")
#Kruskal-Wallis chi-squared = 0.57988, df = 1, p-value = 0.446
#Wniosek na poziomie istotno�ci 0.04 brak podstaw do odrzucenia hipotezy H0, a zatem nie mo�na przyj��, �e czas przep�yni�cia trasy przez kajaki typu A jest kr�tszy ni� czas przep�yni�cia trasy przez kajaki typu B

waga_prod=c(160,217,182,255,191,202,227,190,185,259,164,232,168,175,162,179,171)
waga_typ=c(rep("A",6),rep("B",6),rep("C",5))
9
#H0: varA=varB=varC, H1~H0
bartlett.test(waga_prod,waga_typ)
#Wniosek: na poziomie istotno�ci 0.1 brak podstaw do odrzucenia hipotezy H0, a zatem wariancje wagi produkt�w r�nych producent�w s� jednorodne
10
#H0 mA=mB=mC, H1:~H0 
anova(aov(waga_prod~waga_typ))
#F-value= 2.592 p-value=0.1102
#Wniosek: na poziomie istotno�ci brak podstaw do odrzucenia hipotezy H0, a zatem nie mo�na stwierdzi�, by waga produktu zale�a�a od producenta

11
prop.test(120,353,conf.level = 0.92)
#0.2959916 0.3867385
#Z prawdopodobie�stwem 92% mo�na stwierdzi�, �e odsetek kupuj�cych karm� Purina w populacji generalnej znajduje si� w przedziale 0.30 do 0.39
12
#H0:X i Y niezalezne, H1:~H0
chisq.test(cbind(c(47,73),c(85,148)))
#X-squared = 0.14284, df = 1, p-value = 0.7055
#Wniosek: na poziomie istotno�ci 0.02 brak podstaw do odrzucenia hipotezy H0, a zatem wyb�r karmy nie zale�y od gatunku posiadanego zwierz�cia

l.statk�w=c(12,75,42,54,69,73,48,62)
Po�owy=c(392,351.9,385.2,395.9,379.7,374.6,379.5,340)

13
cor.test(l.statk�w,Po�owy,conf.level=0.94)
#-0.8986694  0.2136309
#Interpretacja: przedzial o koncach  -0.899 i -0.214 z prawdopodobienstwem
#94% obejmuje nieznany wspolczynnik korelacji pomiedzy liczb� statk�w
#a rozmiarem po�ow�w

14
lm(Po�owy~l.statk�w)
#Wielko�� po�ow�w=402.9016 l.statk�w=  -0.5159
#Interpretacja wspolczynnka regresji: wspolczynnik regresji -0.516 oznacza, ze zwiekszenie liczby statk�w o tys. wiaze sie 
#ze spadkiem rozmiarem po�ow�w srednio biorac o okolo 516.

15
#H0: beta1=0, H1: beta1!=0
summary(lm(Po�owy~l.statk�w))
#F-statistic: 2.657 on 1 and 6 DF,  p-value: 0.1542
#Wniosek: na poziomie istotnosci 0.02 brak podstaw do odrzucenia hipotezy H0, 
#a zetem nie mo�na strwierdzi� by wsp�czynnik regresji rozmiary po��w wzgl�dem liczby statk�w by� istotny
progno=c(413.7,361.8,352.8,397,394.4,372.7,393.3,370.7)
16
#H0: rozklad roznicy zmiennnych prognozy i po�ow�w jest normalny H1:~H0
shapiro.test(progno-Po�owy)
#W = 0.91518, p-value = 0.392
#wniosek:Na poziomie istotnosci 0.04, brak podstaw do odrzucenia hipotezy H0, zatem rozklad r�znicy prognozy i po�ow�w jest normalny

#test t Studenta dla prob zaleznych
#H0:m_prog=m_po�, H1:m_prog>m_po�
t.test(progno,Po�owy,alternative = 'g',paired=T)
#t = 1.043, df = 7, p-value = 0.1658
#Wniosek: Na poziomie istotnosci 0.04 brak podstaw do odrzucenia hipotezy H0, a zatem nie mo�na stwierdzi�, by
#prognozy by�y zbyt optymistyczne






#egzamin 
pnorm(1025,1000,50)-pnorm(975,1000,50)
# 20 dziew 30 boi
#srednia 3200 g dziew 3700 boi
#odchylenie 780 i 850 

#5.78
#25 osob
#conf 0.98
pnorm(0.5,0,1)
-pnorm(-0.5,0,1)
1-pnorm(0.5,0,1)
qnorm(0.95)
sqrt((25*(5.78)^2)/42.980)
sqrt((25*(5.78)^2)/10.856)

macierzx=c(0,1)
macierzxwart=c(0.6, 0.4)
macierzy=c(1,2,3)
macierzywart=c(0.5,0.3,0.2)

ix=c(0.5, 0.5)
ix2=c(-1,2)
iy=c(0.5,0.5)
iy2=c(-2,1)
EX=sum(ix*ix2)
#EXkwa=sum((ix*ix2^2))
DXkwa=sum(ix*(ix2-EX)^2)
EY=sum(iy*iy2)
DYkwa=sum(iy*(iy2-EY)^2)
EXY=-1
cova=EXY-(EX*EY)
koral=cova/sqrt(DXkwa*DYkwa)
35.20134
39.79866
37.5
pnorm(84,82,6)-pnorm(75,82,6)
pnorm(2/6,0,1)-pnorm(-7/6,0,1)
sqrt(30)*(11.25-13)/4.35
-7.35/(3*3.5)
-7.35/9
pnorm(-3,-2,2)
pnorm(1,-2,2)-pnorm(-3,-2,2)
pnorm(8,-2,2)-pnorm(1,-2,2)
pracownicy=c(21,12,11,15,9,10,17,8,16,13,12,9,18)
#hip m>8
#uf 95
sred=sum(pracownicy)/13
wartosci=(pracownicy-sred)^2
odchyleniast=sqrt(sum(wartosci)/13)
#4.404, 23.337
#prawa strona 4 lewy wzor
(13*(3.82^2)/4.404)
(13*(3.82^2)/23.337)
wart=((13.15-8)/3.82)*sqrt(12)
#1.782,inf
czas=c(15,25,35,45,55)
pacjenci=c(20,30,36,8,6)
sumka=czas*pacjenci
sum(sumka)/100
eska=(czas-30)^2
eska*pacjenci
sqrt(sum(eska*pacjenci)/100)
#sred 30
#odchylenie 10.82

10.82/(1+((1.96)/sqrt(200)))
10.82/(1-((1.96)/sqrt(200)))
#9.502957 12.56084
#31 1.96
#m>35
#H0:m=35,H1:m>35
((30-35)/10.82)*sqrt(100)
#-4.62 

#<u(1-a),inf) 2.33 [2.33,n)

#Na poziomie istotnosc 0.01 brak podstaw do odrzucenia hipotezy H0, a zatem nie mo�na stwierdzic, czas oczekiwania u specjalisty by� d�u�szy ni� 35 min.
#Podpunkt || odpoweied�
#28 30
#29 10.82
#30 (9.503,12.561) Z prawdopowdobie�stwem 95% mo�na stwierdzi�, �e odchylenie standardowe znajduje si� w tym przedziale
#31 1.96
#32 H0:m=35,H1:m>35
#33 -4.62 
#34 2.33
#35 [2.33,n)
#36 Na poziomie istotnosc 0.01 brak podstaw do odrzucenia hipotezy H0, a zatem nie mo�na stwierdzic, czas oczekiwania u specjalisty by� d�u�szy ni� 35 min.


pnorm(-8,-4,3)
#25 0.0912
pnorm(3,-4,3)-pnorm(-8,-4,3)
#26 0.8990
pnorm(5,-4,3)-pnorm(3,-4,3)
#27 0.0085

#1 0.15
#2 (P X=-2)=0.25 (P X=-1)=0.3 (P X=0)=0.15 (P X=4)=0.3
#3 0.55
#4 0.7
#5 0.4
#6 6.1
#7 5.94
#8 0.45
#9 4/9
#10 1/3
#11 0.25
#12 6.1875
#13 0.2
#14 0.165
#15 -3.2
#16 1.525
#17 C



ix=c(0.25, 0.3,0.15,0.3)
ix2=c(-2,-1,0,4)
iy=c(0.55,0.45)
iy2=c(-2,3)
EX=sum(ix*ix2)
EXkwa=sum((ix*ix2^2))
EXkwa-(EX)^2

DXkwa=sum(ix*(ix2-EX)^2)

EY=sum(iy*iy2)
DYkwa=sum(iy*(iy2-EY)^2)
EXY=0.2
cova=EXY-(EX*EY)
koral=cova/sqrt(DXkwa*DYkwa)

-0.5*EX-3
((-0.5)^2)*EXkwa

pracownicy=c(37,34,0,5,17,17,0,2,24,33,4,0,5,32,3,19,24,6,8,26,24,29,9,29,13)
sum(pracownicy)/25
wartosci=(pracownicy-16)^2
odchyleniast=sqrt(sum(wartosci)/25)

# 16
# 12.15
#(158.14,838.00) Z prawdopodobienstwem 95% mo�na stwierdzi�, �e warjancji sta�u pracy pracownik�w znajduj� si� w tym przedziale 
sqrt(25*(12.15^2)/4.404)
sqrt(25*(12.15^2)/23.337)
#H0:m=12, H1:m>12
((16-12)/12.15)*sqrt(24)
#1.782
#[1.782,n)

5/(1+(1.96/sqrt(150)))
5/(1-(1.96/sqrt(150)))
1-pnorm(700,880,100)
((11.25-13)/4.35)/sqrt(30)
#-0.073
#(inf,-2.58]=[2.58,inf)
#Na poziomie istotnosci 0.01 brak podstaw do odrzucenia hipotezy H0, a zatam nie mo�emy stwierdzi� by �rednie zu�ycie wody istotnie r�ni�o si� od 13 m^3
y=c(-2,1)
iy=c(6/7,1/7)
