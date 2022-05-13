#Laby7

# Zadanie2
#a)
Ankieta_pow$P³eæ=factor(Ankieta_pow$P³eæ)
Ankieta_pow$M.zamieszk=factor(Ankieta_pow$M.zamieszk)
Ankieta_pow$Sz.œrednia=factor(Ankieta_pow$Sz.œrednia)
Ankieta_pow$System=factor(Ankieta_pow$System)
Ankieta_pow$F.stud=factor(Ankieta_pow$F.stud)
#b)
summary(Ankieta_pow$Waga)
summary(Ankieta_pow$Wzrost)
summary(Ankieta_pow$M.zamieszk)
summary(Ankieta_pow$System)
#c)
Ankieta_pow$Œr.kursy=(Ankieta_pow$Prog1+Ankieta_pow$Algebra+Ankieta_pow$MSzS1+Ankieta_pow$Narz.in¿+Ankieta_pow$WdI)/5
#d)
Ankieta_pow.kursy = subset (Ankieta_pow,select = c(Algebra,MSzS1,Narz.in¿,Prog1,WdI))
#e)
Ankieta_pow$Algebra=NULL
Ankieta_pow$MSzS1=NULL
Ankieta_pow$Narz.in¿=NULL
Ankieta_pow$Prog1=NULL
Ankieta_pow$WdI=NULL
#lub
Ankieta_pow=Ankieta_pow[-(7:11)]
#f)
zakres3sigm<-function(x){
  lewy.kres=mean(x)-(3*sd(x))
  prawy.kres=mean(x)+(3*sd(x))
  data.frame(
    lewy.kres,prawy.kres
  )
}
zakres3sigm(Ankieta_pow$Wzrost)
#g)
zakres3sigm(Ankieta_pow$Œr.kursy)
which(Ankieta_pow$Œr.kursy<1.898835|Ankieta_pow$Œr.kursy>5.410256)
#h)
Ankieta_pow.K=filter(Ankieta_pow, P³eæ=='K')
Ankieta_pow.M=filter(Ankieta_pow, P³eæ=='M')
#i)
zakres3sigm(Ankieta_pow.K$Wzrost)
zakres3sigm(Ankieta_pow.K$Waga)
#j)
Ankieta_pow$L.g.kody=cut(Ankieta_pow$L.godz,c(0,4,8,24),c("krotko","œrednio","d³ugo"))

#Zad3)
ggplot(Ankieta_pow,aes(M.zamieszk))+geom_bar(fill='red',col='black')+ylab('Liczba zamieszka³ych')
ggplot(Ankieta_pow,aes(Sz.œrednia))+geom_bar(fill='green',col='black')+ylab('Liczba osób koñcz¹cych dan¹ szko³ê ponadpodstawow¹ ')
ggplot(Ankieta_pow,aes(M.zamieszk))+geom_bar(fill='red',col='black')+ylab('Liczba zamieszka³ych')
ggplot(Ankieta_pow,aes(System))+geom_bar(fill='blue',col='black')+ylab('U¿ywany system ')
#Laby8

#Zadanie 1)
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

#Zadanie 2)
p.opisowe(Ankieta_pow.M$Wzrost)
#kwartyl.1 175.50000000 odchylenie.standardowe 6.77904662 wspolczynnik.zmiennosci 0.03753499 wspolczynnik.asymetrii 0.17393899
p.opisowe(Ankieta_pow$Œr.kursy)
#mediana 3.6000000 kwartyl.3 4.0000000 srednia 3.6545455
p.opisowe(Ankieta_pow$L.godz)
#srednia 8.4090909 wspolczynnik.skupienia 2.8844388

#Zadanie 3)
parametry.wazone=function(x,y){
  srednia.wazona=sum((x*y)/sum(y))
  odchylenie.wazone=sqrt(sum(y*(x-srednia.wazona)^2)/(sum(y)-1))
  data.frame(
    srednia.wazona,odchylenie.wazone
  )
}
minuty=c(4,6,8,10,12,14)
uczniowie=c(9,17,13,6,3,2)
parametry.wazone(minuty,uczniowie)
#Zadanie 4)
#a)
ggplot(Ankieta_pow, aes(x=P³eæ,
                    y=Waga))+geom_boxplot(fill='#00FFFF',
                                          col='black')
ggplot(Ankieta_pow, aes(x=P³eæ,
                    y=Wzrost))+geom_boxplot(fill='#00FFFF',
                                            col='black')
ggplot(Ankieta_pow, aes(x=M.zamieszk,
                    y=Œr.kursy))+geom_boxplot(fill='#00FFFF',
                                              col='black')
ggplot(Ankieta_pow, aes(x=M.zamieszk,
                    y=L.godz))+geom_boxplot(fill='#00FFFF',
                                            col='black')
#b)
stem(Ankieta_pow$Waga)
stem(Ankieta_pow$Wzrost)
#c)
ggplot(Ankieta_pow.M,aes(x=Wzrost))+geom_histogram(fill='red',col='black',binwidth = 10)+ylab('liczba osób')
#Laby9

#Zadanie 1)
przedzia³.odchylenie=function(x,uf){
  n=length(x)
  q1=qchisq((1+uf)/2,n-1)
  q2=qchisq((1-uf)/2,n-1)
  ocena.dolna=sqrt((n-1)*var(x)/q1)
  ocena.górna=sqrt((n-1)*var(x)/q2)
  cbind(ocena.dolna,ocena.górna)
}
#np.
przedzia³.odchylenie(Ankieta_pow.M$Wzrost,0.97)
#Zad2 
#a)
#H0 rozklad jest normalny H1:~H0
shapiro.test(Ankieta_pow.M$Wzrost)
#W=0.98949, p=value=0.6305
#alfa=0.05<p-value=0.6305
#brak podstaw do odrzucenia H0
#Na poziomie istotnosci 0.01 nie ma podstaw do odrzucenia hipotezy H0, ktora mowi, ze
#rozklad wzrostu w populacji mezczyzn jest normalny
#wyniki proby nie potrwierdzily znaczacych roznic

#b)
t.test(Ankieta_pow.M$Wzrost,conf.level = 0.95)
#179.2540 181.9581
#Przedzial liczbowy o koncach 179,3 i 182.0
#Z prawdopodobienstwiem 0.95 obejmuje nieznany rzeczywisty œredni
#wzrost w populacji studentow 1 roku informatyki
t.test(Ankieta_pow.M$Wzrost,conf.level = 0.98)
#178.9947 182.2174
#Przedzial liczbowy o koncach 179,0 i 182.2
#Z prawdopodobienstwiem 0.98 obejmuje nieznany rzeczywisty œredni
#wzrost w populacji studentow 1 roku informatyki

#c)0.97
przedzia³.odchylenie(Ankieta_pow.M$Wzrost,0.97)

#Przedzia³ ufnoœci o koñcach 5.87 i 8.01 dla poziomu ufnoœci 0.97 obejmuje odchylenie standardowe wzrostu w populacji studentów I roku WI

#d)
#H0:m = 180, H1:m > 180
t.test(Ankieta_pow.M$Wzrost,mu=180,alternative = 'g')
#t= 0.88954, df=98, p-value=0.1879
#alfa=0.05
#alfa<p-value=0.1879
#brak podstaw do odrzucenia H0
#Na poziomie istnotnosci 0.05 nie ma podstaw do odrzucenia hipotezy H0 
#ze srednia wzrostu wzrostu w populacji studentow wynosi 180 centymetrow
#zatem wyniki proby nie potrwierdzaja przypuszczenia ze srednia wzrostu w
#populacji studentow jest wieksza niz 180

#Zadanie 3
#a)
#H0 rozklad jest normalny H1:~H0
shapiro.test(Ankieta_pow.K$Waga)
#W = 0.64168, p-value = 8.459e-05
#na poziomie istotnosci 
#alfa=0.01>p-value=8.459e-05
#Na poziomie istotnosci 0.01, sa podstawy do odrzucenia H0
#Odrzucamy wartosci odstajace(taka co sie bardzo rozni od sredniej) 
stem(Ankieta_pow.K$Waga)
fix(Ankieta_pow.K)
Ankieta_pow.K=Ankieta_pow.K[-11,]
shapiro.test(Ankieta_pow.K$Waga)
#W = 0.95224, p-value = 0.6951
#Na poziomie istotnosci 0.01, brak posataw do odrzucenia H0, zatem rozklad jest normalny
#b)
t.test(Ankieta_pow.K$Waga,conf.level=0.98)
# 53.71541 61.58459
#Przedzial liczbowy 53.7 i 61.6
#Z prawdopodobienstwiem 0.98, przedzial liczbowy 53.7 i 61.6 obejmuje nieznana rzeczywista œrednia
#wage w populacji studentek 1 roku informatyki
#c)
przedzia³.odchylenie(Ankieta_pow.K$Waga,0.95)
#3.033285    8.050759
#Przedzial ufnosci o koncach 3.03 i 8.05 dla poziomu ufnoœci 0.95 obejmuje odchylenie standardowe wagi w populacji studentek I roku WI
#d)
#H0:m=70, H1:m<70, alfa=0.05
t.test(Ankieta_pow.K$Waga,mu=70,alternative='l')
#t = -8.856, df = 9, p-value = 4.87e-06
#alfa=0.05<p-value = 4.87e-06
#Na poziomie istotnosci 0.05 sa podstawy do odrzucenia hipotezy H0
#zatem wyniki proby potrwierdzaja przypuszczenia ze srednia wzrostu w
#populacji studentek jest mniejsza niz 70
#(alternatywna wersja wniosku)
#Wniosek: na poziomie istotnosci 0.05 odrzucamy H0 i przyjmujemy H1, 
#rzeczywista srednia waga w populacji studentek I roku WI jest istotnie mniejsza od 70 kg.

#Laby10

#Zadanie 1
#a) zalozenie 1: normalnosc rozkladow
#H0: rozklad wzrostu studenetek jest normalny, H1:~H0
#H0': rozklad wzrostu studentow jest normalny, H1':~H0'
by(Ankieta_pow$Wzrost,Ankieta_pow$P³eæ,shapiro.test)
#K:W = 0.92411, p-value = 0.3544
#M:W = 0.98949, p-value = 0.6305
#alfa=0.05
#Wniosek:Na poziomie istotnosci, brak podstaw do odrzucenia H0,H0' (alfa<p-value), zatem 
#rozklad wzrostu w obu grupach jest normalny

#b) zalozenie 2: jednorodnosc wariancji
#H0:VarK=varM, H1:varK!=varM
var.test(data=Ankieta_pow,Wzrost~P³eæ)
#F = 0.73035, num df = 10, denom df = 98, p-value = 0.6115 
#Wniosek:Na poziomie istotnosci 0.05, brak podstaw do odrzucenia hipotezy H0 (alfa<p-value),
#zatem wariancja jest jednorodnao jednakowych wariancjach wzrostu studentow i studentek

#c) test dla 2 œrednich 
#H0:mK = mM,H1:mK < mM
t.test(data=Ankieta_pow,Wzrost~P³eæ,alternative='l',var.equal=T)
#t = -5.84, df = 108, p-value = 2.788e-08
#alfa=0.05
#Wniosek:Na poziomie istotnosci 0.05 odrzucamy hipoteze H0
# i przyjmujemy H1, zetem sredni wzrost studentek
#jest istotnie nizszy niz sredni wzrost w populacji 
#studentow

#Zadanie 2
#a)
table(Ankieta_pow$M.zamieszk)
#a) przedzia³ ufnosci dla wskaznika struktury (odsetka)
prop.test(23,110,conf.level=0.98)
#0.1299602 0.3168308
#Przedzia³ ufnoœci o koñcach 0.1299602 0.3168308 dla poziomu ufnosci 0.98 obejmuje odsetek osob mieszkajacych w akademiku

#b) test dla wskaznika struktury (odsetka)
#H0:p = 10%, H1:p > 10%
prop.test(23,110,p=0.1,alternative='g')
#X-squared = 13.359, df = 1, p-value = 0.0001286
#Wniosek: na poziomie istotnosci 0.05 odrzucamy hipoteze H0
#na rzecz H1, czyli odsetek osob mieszkajacych w akademitu
# jest istotnie wiekszy niz 10%

#c) test dla dwoch wskaznikow struktury 
table(Ankieta_pow$M.zamieszk,Ankieta_pow$F.stud)
#H0: pN=pS, H1: pN != pS,
prop.test(c(6,50),c(18,92))
#X-squared = 1.8858, df = 1, p-value = 0.1697
#Wniosek: Na poziomie istotnosci 0.05 nie ma podstaw
#do odrzucenia hipoteze H0, ze odsetek osob mieszkajacych 
# w misezkaniu z rodzina dla studentow niestacjonarnych oraz
#stacjonarnych sa takie same 

#Zadanie 3

# a) zalozenie 1: normalnosc rozkladow
#H0: rozklad wzrostu studenetek jest normalny, H1:~H0
#H0': rozklad wzrostu studentow jest normalny, H1':~H0'
by(Ankieta_pow$Wiek,Ankieta_pow$F.stud,shapiro.test)
#N:W = 0.94534, p-value = 0.3566
#S:W = 0.96411, p-value = 0.01237
#alfa=0.01
#Wniosek: na poziomie istotnosci 0.01 brak podstaw do odrzucenia H0 i H0'

#b) zalozenie 2 jednorodnosc wariancji
var.test(data=Ankieta_pow,Wiek~F.stud)
#H0: wariancje rozk³adow wieku w populacji studentów studiow 
#stacjonarnych i niestacjonarnych s¹ takie same, H1:~H0
#lub
#H0:varN=varS, H1:varN!=varS
#F = 0.70896, num df = 17, denom df = 91, p-value = 0.4275
#alfa=0.01
#Wniosek:Na poziomie istotnosci 0.01 brak podstaw do odrzucenia H0 (alfa<p-value)
#o jednakowych wariancjach wieku studentow stacjonarnych oraz niestacjonarnych

#c) test dla 2 srednich
#H0:mN = mS,H1:mN != mS
t.test(data=Ankieta,Wiek~F.stud,alternative='t',var.equal=T)
#t = 0.10828, df = 108, p-value = 0.914
#alfa=0.01
#Wniosek: Na poziomie istotnosci 0.01 brak podstaw by odrzucic hipoteze H0
# Zatem wyniki proby nie potwierdzaja hipotezy, ze sredni wiek pierwszego samodzielnego zetkniecia sie z 
#komputerem w populacji wszystkich stu-dentow I roku na WI zalezy od formy studiow

#Zadanie 4

#a)przedzial ufnosci dla wskaznika struktury
table(Ankieta_pow$Sz.œrednia)
prop.test(45,110,conf.level=0.99)
#0.2927890 0.5361135
#Przedzia³ ufnoœci o koñcach 0.2927890 0.5361135 dla poziomu ufnosci 0.99 obejmuje odsetek osob, ktore ukonczyly technikum informatyczne

#b)test dla wskaznika struktury 
#H0: p=25%, H1 p>25%
prop.test(39,110,p=0.25,alternative='g')
#X-squared = 5.8667, df = 1, p-value = 0.007715
#Wniosek: na poziomie istotnosci 0.01 odrzucamy hipoteze H0
#na rzecz H1, czyli odsetek osob, ktore ukonczyly LO z rozszerzona matematyka
#wsrod wszystkich studentow jest istotnie wiekszy niz 25%

#c) test dla dwoch wskaznikow struktury 
table(Ankieta_pow$Sz.œrednia,Ankieta_pow$F.stud)
#H0: pN=pS, H1: pN < pS,
prop.test(c(5,40),c(18,92),alternative='l')
#X-squared = 0.95436, df = 1, p-value = 0.1643
#Wniosek: na poziomie istotnosci 0.01 nie ma podstaw do odrzucenia hipotezy H0
#zatem odsetki osob ktore ukonczyly TI nie roznia sie zbytnio dla studentow 
#stacjonarnych i niestacjonarnych 

#Laby11

#Zadanie 1
#a) zalozenie 1: normalnosc rozkladow
plony=c(2.6,2.4,2.0,1.8,2.2,1.5,1.5,1.4,1.2,2.5,2.2,1.8,1.7,1.8,1.5,1.2,1.5,0.8,1.0)
nawozenie=c(rep("1",5),rep("2",4),rep("3",5),rep("4",5))
#a) zaloeznie 1 normalnosc rozkladow
#H01:rozklad plonow przy nawozeniu 1 jest normalny, H11:~H01
#H01:rozklad plonow przy nawozeniu 2 jest normalny, H12:~H02
#H01:rozklad plonow przy nawozeniu 3 jest normalny, H13:~H03
#H04:rozklad plonow bez nawozenia jest normalny, H14:~H04
by(plony,nawozenie,shapiro.test)
#1 W = 0.98676, p-value = 0.9672
#2w = 0.82743, p-value = 0.1612
#3 W = 0.85805, p-value = 0.2213
#4 W = 0.90345, p-value = 0.4292
#alfa=0.05
#Wniosek: Na poziomie 0.05, brak podstaw do odrzucenia hipotez podstawowych 

#b) zalozenie 2: jednorodnosc wariancji
#H0: var1=var2=var3=var4, H1~H0
bartlett.test(plony~nawozenie)
#Bartlett's K-squared = 2.0916, df = 3, p-value = 0.5536
#Wniosek: Na poziomie istotnosci 0.05, brak podstaw do odrzucenia H0 o jednakowych wariancjach plonow rzepaku jarego

#c) test ANOVA
#H0 m1-m2=m3=m4 (brak wp³ywu), H1:~H0 (wplyw istotny)
anova(aov(plony~nawozenie))
#F=12.713 p-value=0.0002131
#alfa=0.05
#Wniosek: odrzucamy H0 na rzecz H1, zatem na poziomie istotnosci 0.05 mozemy
#stwierdzic, ze nawozenie wplywa na plon rzepaku jarego

#d) analiza post hoc
TukeyHSD(aov(plony~nawozenie))
#przy malych p adj odrzucamy H0
plot(TukeyHSD(aov(plony~nawozenie)))
boxplot(plony~nawozenie)
#plony na poletkach nawozonych 1 kombinacja istotnie roznia sie od nawozonych 2 i 4

#Zadanie 2
#H0: rozk³ad œrednich ocen za kursy jest normalny, H1~H0
shapiro.test(Ankieta_pow$Œr.kursy)
#W = 0.96749, p-value = 0.008668
#alfa=0.05
#Wniosek: odrzucamy H0, zatem normalnosc nie zachodzi, test 1 srednieh nie mozliwy

#test Wilcoxona
#H0: me=3.5, H1: me>3.5
wilcox.test(Ankieta_pow$Œr.kursy,mu=3.5,alternative='g')
#V = 3308.5, p-value = 0.01134
#alfa=0.05
#wniosek: na poziomie istotnosci 0.05 odrzucamy hipoteze H0
#i przyjmujemy H1, zatem mediana srednich ocen za kursy jest wyzsza niz 3.5

#Zadanie 3
#shapiro.test()
#by(Ankieta$Wzrost,Ankieta$P³eæ,shapiro.test)
#H01:  rozk³ad srednich ocen za kursy dla kobiet jest normalny, H11~H01
#H02:  rozk³ad srednich ocen za kursy dla mezczyzn jest normalny, H12~H02
by(Ankieta_pow$Œr.kursy,Ankieta_pow$P³eæ,shapiro.test)
#K. W = 0.92144, p-value = 0.3308
#M W = 0.96961, p-value = 0.02163
#alfa=0.05
#Wniosek: Na poziomie istotnosci 0.05, odrzucamy hipoteze H02, zatem
#rozk³ad srednich ocen za kursy dla mezczyzn jest normalny

#H0: meK=meM,H1: meK>meM
wilcox.test (Ankieta_pow$Œr.kursy ~ Ankieta$P³eæ,alternative='g')
#W = 537.5, p-value = 0.5298
#alfa=0.05
#Wniosek: na poziomie istotnosci 0.05 brak podstaw do odrzucenia Hipotezy H0 zatem mê¿czyŸni w populacji
#studenci I roku WI nie uzyskuj¹ ni¿szej œredniej ocen z kursów ni¿ kobiety

#Zadanie 4
#a) zalozenie 1: normalnosc rozkladu
#H01:  rozk³ad œrednich ocen za kursy dla studentow mieszkajacych w akademiku jest normalny, H11~H01
#H02:  rozk³ad œrednich ocen za kursy dla studentow mieszkajacych w mieskzaniu z rodzina jest normalny, H12~H02
#H03:  rozk³ad œrednich ocen za kursy dla studentow mieszkajacych na stancji jest normalny, H13~H03
by(Ankieta_pow$Œr.kursy,Ankieta_pow$M.zamieszk,shapiro.test)
# Akademik W = 0.92551, p-value = 0.0875
#Mieszkanie z rodzina W = 0.9584, p-value = 0.05119
#Stancja W = 0.94226, p-value = 0.0953
#alfa-0.05
#Na poziomie istotnosci 0.05, brak podstaw do odrzucenia hipotez,
#zatem rozklady sa normalne

#b) zalozenie 2:jednorodnosc wariancji
#H0: var1=var2=var3, H1~H0
bartlett.test(Ankieta_pow$Œr.kursy~Ankieta_pow$M.zamieszk)
#Bartlett's K-squared = 0.78333, df = 2, p-value = 0.6759
#Wniosek: na poziomie istotnosci 0.05, brak podstaw do orzucenia hipotezy H0 o jednakowych wariancjach srednich ocen

#c) test anova
#H0 m1=m2=m3 (brak wp³ywu), H1:~H0 (wplyw istotny)
anova(aov(Ankieta_pow$Œr.kursy~Ankieta_pow$M.zamieszk))
#F=0.9967 p=value=0.3725
#alfa=0.05
#Wniosek na poziomie istotnosci 0.05 nie ma podstaw by odrzucic hipoteze H0, zatem nie mozna stwierdzic istotnego wplywu miejsa zamieszkania na srednia ocen

#Zadanie 5
#zalozenie 1: rozklad jest normalny
#H01:  rozk³ad srednich ocen za kursy dla studentow nisetacjonarncyh jest normalny, H11~H01
#H02:  rozk³ad srednich ocen za kursy dla studentow stancjonarncyh jest normalny, H12~H02
by(Ankieta_pow$Œr.kursy,Ankieta_pow$F.stud,shapiro.test)
#N W = 0.96318, p-value = 0.6641
#S W = 0.9605, p-value = 0.007001
#alfa=0.05
#Wniosek:Na poziomie istotnosci 0.05, odrzucamy hipoteze H02, zatem rozk³ad srednich ocen za kursy dla studentow stancjonarncyh nie jest normalny
#Test Wilcox 
#H0: meN=meS, H1: meN!=meS
wilcox.test(Ankieta_pow$Œr.kursy~Ankieta_pow$F.stud)
#W = 744.5, p-value = 0.5017
#alfa=0.05
#Wniosek na poziomie istotnosci 0.05 nie mamy podstaw do odrzucenia hipotezy H0, zatem srednia studentow stacjonarnych i niestacjonarcych nie rozni sie

#Zadanie 6

#zalozenie 1: rozklad jest normalny
#H01:rozklad srednich ocen za kursy dla studentow, ktorzy
#ukoñczyli LO(PM) jest normalny, H11:~H01
#H02:rozklad srednich ocen za kursy dla studentow, ktorzy
#ukoñczyli LO(RM) jest normalny, H12:~H02
#H03:rozklad srednich ocen za kursy dla studentow, ktorzy
#ukoñczyli TI jest normalny, H13:~H03
by(Ankieta_pow$Œr.kursy,Ankieta_pow$Sz.œrednia,shapiro.test)
#Inna: W = 0.96825, p-value = 0.8639
#LO (PM): W = 0.92782, p-value = 0.1245
#LO (RM): W = 0.9701, p-value = 0.3782
#TI: W = 0.94105, p-value = 0.0235
#alfa=0.05
#Wniosek: Na poziomie istotnosci 0.05 odrzucamy hipotezê H03 o normalnym rozk³adzie œrednich ocen za kursy dla studentów, którzy
#ukoñczyli TI

#test Kruskala_Wallisa
#H0:me1=me2=me3=me4, H1:~H0
kruskal.test(data=Ankieta_pow, Œr.kursy~Sz.œrednia)
#Kruskal-Wallis chi-squared = 17.222, df = 3, p-value = 0.0006361
#alfa=0.05
#Wniosek:Na poziomie istotnosci 0.05 odrzucamy H0 na korzysc H1, zatem srednie oceny za kursy z 1. semestru zaleza od 
#ukonczonej szkoly sredniej
boxplot(Ankieta_pow$Œr.kursy~Ankieta_pow$Sz.œrednia)

#Zadanie 7
#zalo¿enie 1: rozklad jest normalny
#H0: rozklad liczby godzin studentow w akademiku jest normalny, H1:~H0
#H0':rozklad liczby godzin studentow w mieszkaniu jest normalny, H1':~H0'
#H0":rozklad liczby godzin studentow na stancji jest normalny, H1":~H0"
by(Ankieta_pow$L.godz,Ankieta_pow$M.zamieszk,shapiro.test)
#A:W = 0.93366, p-value = 0.1312
#M:W = 0.93739, p-value = 0.006019
#S:W = 0.9385, p-value = 0.075
#alfa=0.01
#Wniosek:Na poziomie istotnosci 0.01 za³o¿enie nie jest spelnione,poniewa¿ odrzucamy H0', 
#rozklad liczby godzin studentow w mieszkaniu nie jest normalny

#test kruskala-Wallisa
#me1=me2=me3, H1:~H0
kruskal.test(Ankieta_pow$L.godz~Ankieta_pow$M.zamieszk)
#Kruskal-Wallis chi-squared = 2.8363, df = 2, p-value = 0.2422
#Wniosek: na poziomie istotnoœci 0.01 nie ma podstaw do odrzucenia H0,
#nie mo¿na potwierdziæ istotnego wplywu miejsca zamieszkania na dlugosc
#czasu spedzanego przy komputerze w populacji studentow.

#Laby 12
#Zadanie 1
przed.kuracja=c(225,236,312,238,241,196,205,259,218)
po.kuracji=c(216,195,245,235,221,170,180,265,179)
#zalozezie; normalnosc rozkladu roznicy zmiennnych
#H0: rozklad roznicy zmiennnych jest normalny
#H1: nie prawda, ze H0 H1:~H0
shapiro.test(przed.kuracja-po.kuracji)
#W = 0.96898, p-value = 0.8858
#alfa=0.01
#wniosek:Na poziomie istotnosci, brak podstaw do odrzucenia hipotezy H0, zatem rozklad jest normalny

#test t Studenta dla prob zaleznych
#H0:m1-m2=0, H1:m1-m2>0
t.test(przed.kuracja,po.kuracji,alternative = 'g',paired=T)
#t = 3.3633, df = 8, p-value = 0.004942
#alfa=0.01
#Wniosek: Na poziomie istotnosci 0.01 odrzucamy hipoteze H0 i przyjmujemy hipoteze H1 
# czyli leczenie statynami skutecznie wplywa na obnizenie poziomu cholesterolu.

#Zadanie 2
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

#Zadanie 3 
#test niezaleznosci chi^2
#H0: X,Y sa niealezny, H1:~H0
chisq.test(cbind(c(152,52),c(8,188)))
#X-squared = 203.67, df = 1, p-value = 2.2e-16
#alfa=0.01
#Wniosek:Na poziomie istotnosci 0.01 odrzucamy H0 na rzecz H1, zatem
#mozna stwierdzic, ze rosliny cebuli wychodowane z wiekszych cebulek dymki
#wyrastaja czesciej w pedy kwiatostanowe

#Zadanie 4
przed.dieta=c(87.5,56,67,82.5,92,59,90.5,80.5,65,92)
po.diecie=c(86,54,66,83,87,62,87,90,61,70)
#H0: rozklad roznicy zmiennnych jest normalny
#H1: nie prawda, ze H0 H1:~H0
shapiro.test(przed.dieta-po.diecie)
#W = 0.83934, p-value = 0.04333
#alfa=0.05
#wniosek: Na poziomie istotnosci odrzucamy hipoteze H0 i przyjmujemy 
#hipoteze H1 zatem rozklad roznicy zmiennych nie jest normalny

#test Wilcoxona
#H0:m1-m2=0, H1:m1-m2>0
wilcox.test(przed.dieta,po.diecie,alternative = 'g',paired=T)
#alfa=0.05
#V = 40, p-value = 0.1162
#Wniosek: na poziomie istotnosci 0.05 brak podstaw do odrzucenia hipotezy H0,
#zatem nie mozna stwierdzic, ze dieta wplywa na spadek wagi popoulacji kobiet

#Zadanie 5
prod=c(0.8,1.2,1.6,1.8,2.2,1.6,2.4,2)
brak=c(6,10,12,15,18,15,20,16)

#a) podac interpretacje wspolczynnka korelacji liniowej
cor(prod,brak)
#0.9811157
#Interpretacja: pomiedzy liczba produkowanych brakow a wielkoœcia produkcji istniej silna zaleznosc korelacyjna dodatnia, 
#wzrost produkcji jest zwiazany ze wzrostem liczby brakow.

#b) przedzial ufnosci dla wspolczynnika korelacji
cor.test(prod,brak,conf.level = 0.98)
#0.8581196 0.9976229
#Interpretacja: przedzial o koncach 0.959 i 0.998 z prawdopodobienstwem 98% obejmuje nieznany wspolczynnik korelacji pomiedzy
#liczba brakow a wielkoscia produkcji.

#c) oszacowac funkcje regresji
lm(brak~prod)
#y=-0.3438 x=8.4375
#Interpretacja wspolczynnka regresji: wspolczynnik regresji 8.44 oznacza, ze zwiekszenie produkcji o tys. sztuk wiaze sie 
#ze wzrostem liczby brakow srednio biorac o okolo 8 szt.

#d) test istotnosci wspolczynnika regresji
#H0: beta1=0, H1: beta1!=0
summary(lm(brak~prod))
#t=12.425 p=1.66e-05
#alfa=0.01
#Wniosek: na poziomie istotnosci 0.01 odrzucamy H0 na rzecz H1, zatem regresja miedzy liczba brakow a wielkosci¹ produkcji 
#jest statystycznie istotna.

#Zadanie 6
#test niezaleznosci chi^2
#H0:X i Y niezalezne, H1:~H0
chisq.test(cbind(c(45,35,30),c(25,25,40)))
#X-squared = 6.8783, df = 2, p-value = 0.03209
#alfa=0.05
#Wniosek: na poziomie istotnosci 0.05 odrzucamy H0 na rzecz H1, zatem istnieje istotna zaleznosc miedzy kierunkiem ukonczonych studiow
# a zadowoleniem z aktualnej pracy.

#Zadania dodatkowe
Fizycz=c(37,1,5,0,2.5,23,4,0.5,5.5,3,19,6,8,24.5,9,2)
Umysl=c(34,17,18,33,32,24,26,29,28)
Prac=c(37,1,5,0,2.5,23,4,0.5,5.5,3,19,6,8,24.5,9,2,34,17,18,33,32,24,26,29,28)
Prac_typ=c(rep("F",16),rep("U",9))
#a) zaloeznie 1 normalnosc rozkladow
#H01:rozklad stazu pracy pracownikow fizycznych jest normalny, H11:~H01
#H02:rozklad stazu pracy pracownikow umyslowych jest normalny, H12:~H02
by(Prac,Prac_typ,shapiro.test)
#F W = 0.79391, p-value = 0.002263
#U W = 0.91735, p-value = 0.3707
#alfa=0.02
#Wniosek: na poziomie istotnosci 0.02 odrzucamy hipoteze H01, zatem rozklad
#stazu pracy pracownikow fizycznych nie jest normalny

#test t Studenta
#H0:m1-10=0, H1:m1-10<0
t.test(Umysl,mu=10,alternative = 'l')
#t = 8.1443, df = 8, p-value = 1
#alfa=0.02
#Wniosek: na poziomie istotnosi 0.02 brak podstaw do odrzucenia hipotezy H0, zatem
# na podstawie probki nie mozna stwierdzic, by sredni staz pracownikow umyslowych, byl krotszy niz 10 lat

#test wilcoxona
#H0:m1-8=0, H1:m1-8>0
fix(Fizycz)
Fizycz2=Fizycz[-4]
wilcox.test(Fizycz,mu=8,alternative = 'g')
#V = 55, p-value = 0.6226
#alfa=0.02
#Wniosek: na poziomie istotnosci 0.02 brak podstaw do odrzucenia hipotezy H0,
#zatem na podstawie probki nie mozna przyjac, ze sredni czas pracy pracownikow fizycznych jest dluzszy niz 8 lat

#test t Studenta
#H0:mF=mU, H1:mF<mU
wilcox.test(Fizycz,Umysl,alternative = 'l')
#alfa=0.02
#W = 16, p-value = 0.0004112
#Wniosek: na poziomie istotnosci 0.02 odrzucamy hipoteze H0, zatem
#sredni staz pracy pracownikow umyslowych jest istotnie dluzszy niz sredni staz pracy pracownikow fizycznych

#zad dodat 2
#test niezaleznosci chi^2
#H0: X,Y sa niealezny, H1:~H0
chisq.test(cbind(c(50,128),c(50,72)))
#alfa=0.01
#X-squared = 4.8507, df = 1, p-value = 0.02764
#wniosek: na poziomie istotnosci 0.01, brak podstaw do odrzucenia hipotezy H0,
#zatem nie mozna stwierdzic, ze pierwszy lek podawany pacjenta jest skuteczniejszy niz 2.
