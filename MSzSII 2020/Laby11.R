#Laby 11
#zad1
plony=c(2.6,2.4,2.0,1.8,2.2,1.5,1.5,1.4,1.2,2.5,2.2,1.8,1.7,1.8,1.5,1.2,1.5,0.8,1.0)
nawozenie=c(rep("1",5),rep("2",4),rep("3",5),rep("4",5))
#a) zaloeznie 1 normalnosc rozkladow
#H01:rozklad plonow przy nawozeniu 1 jest normalny, H11:~H01
#H01:rozklad plonow przy nawozeniu 1 jest normalny, H12:~H02
#H01:rozklad plonow przy nawozeniu 1 jest normalny, H13:~H03
#H04:rozklad plonow bez nawozenia jest normalny, H14:~H04
by(plony,nawozenie,shapiro.test)
#1 W = 0.98676, p-value = 0.9672
#2w = 0.82743, p-value = 0.1612
#3 W = 0.85805, p-value = 0.2213
#4 W = 0.90345, p-value = 0.4292
#Brak podstaw do odrzucenia hipotez podstawowych 

#b) za³o¿enie 2: jednorodnosc wariancji
#H0: var1=var2=var3=var4, H1~H0
bartlett.test(plony~nawozenie)
#Bartlett's K-squared = 2.0916, df = 3, p-value = 0.5536
#Wniosek: Brak podstaw do odrzucenia H0

#C) test ANOVA
#H0 m1-m2=m3=m4 (brak wp³ywu), H1:~H0 (wplyw istotny)
anova(aov(plony~nawozenie))
#F=12.713 p-value=0.0002131
#alfa=0.05
#Wniosek: odrzucamy H0 na rzecz H1, zatem na poziomie istotnosci 0.05 mozemy
#stwierdzic, ze nawozenie wplywa na plon rzepaku jarego
#d) analiza post hoc
TukeyHSD(aov(plony~nawozenie))
#przy malych p adj odrzucamy H0, przy istotnych roznicach 
#1 lub 3 kombinacja nawozic
plot(TukeyHSD(aov(plony~nawozenie)))
#Najlepszy efekt kombinacja numer 1

#Zad2
#H0: rozk³ad œrednich ocen za kursy jest normalny, H1~H0
shapiro.test(Ankieta$Œr.kursy)
#W = 0.96749, p-value = 0.008668
#Wniosek: odrzucamy H0, zatem normalnosc nie zachodzi, test 1 srednieh nie mozliwy

#test Wilcoxona
#H0: me=3.5, H1: me>3.5
wilcox.test(Ankieta$Œr.kursy,mu=3.5,alternative='g')
#V = 3308.5, p-value = 0.01134
#alfa=0.05
#wniosek: na poziomie istotnosci 0.05 odrzucamy hipoteze H0
#i przyjmujemy H1, zatem mediana srednich ocen za kursy jest wyzsza niz 3.5

#zad3 
#shapiro.test()
#by(Ankieta$Wzrost,Ankieta$P³eæ,shapiro.test)
#H01:  rozk³ad œrednich ocen za kursy dla kobiet jest normalny, H11~H01
#H02:  rozk³ad œrednich ocen za kursy dla mezczyzn jest normalny, H12~H02
by(Ankieta$Œr.kursy,Ankieta$P³eæ,shapiro.test)
#K. W = 0.92144, p-value = 0.3308
#M W = 0.96961, p-value = 0.02163
#alfa=0.05
#Wniosek odrzucamy hipoteze H02
#H0: meK=meM,H1: meK>meM
wilcox.test (Ankieta$Œr.kursy ~ Ankieta$P³eæ,alternative='g')
#W = 537.5, p-value = 0.5298
#alfa=0.05
#Wniosek: na poziomie istotnosci 0.05 brak podstaw do odrzucenia Hipotezy H0 zatem mê¿czyŸni w populacji
#studenci I roku WI nie uzyskuj¹ ni¿szej œredniej ocen z kursów ni¿ kobiety
#Zad4 
#H01:  rozk³ad œrednich ocen za kursy dla studentow mieszkajacych w akademiku jest normalny, H11~H01
#H02:  rozk³ad œrednich ocen za kursy dla studentow mieszkajacych w mieskzaniu z rodzina jest normalny, H12~H02
#H03:  rozk³ad œrednich ocen za kursy dla studentow mieszkajacych na stancji jest normalny, H13~H03
by(Ankieta$Œr.kursy,Ankieta$M.zamieszk,shapiro.test)
# Akademik W = 0.92551, p-value = 0.0875
#Mieszkanie z rodzina W = 0.9584, p-value = 0.05119
#Stancja W = 0.94226, p-value = 0.0953
#alfa-0.05
#Brak podstaw do odrzucenia hipotez

#H0: var1=var2=var3, H1~H0
bartlett.test(Ankieta$Œr.kursy~Ankieta$M.zamieszk)
#Bartlett's K-squared = 0.78333, df = 2, p-value = 0.6759
#Brak podstaw do orzucenia hipotezy H0

#H0 m1=m2=m3 (brak wp³ywu), H1:~H0 (wplyw istotny)
anova(aov(Ankieta$Œr.kursy~Ankieta$M.zamieszk))
#F=0.9967 p=value=0.3725
#alfa=0.05
#Wniosek na poziomie istotnosci 0.05 nie mo¿emy odrzucic hipotezy H0, zatem miejse zamieszkania nie ma wplywu na srednia ocen

#zad5
#H01:  rozk³ad œrednich ocen za kursy dla studentow nisetacjonarncyh jest normalny, H11~H01
#H02:  rozk³ad œrednich ocen za kursy dla studentow stancjonarncyh jest normalny, H12~H02
by(Ankieta$Œr.kursy,Ankieta$F.stud,shapiro.test)
#N W = 0.96318, p-value = 0.6641
#S W = 0.9605, p-value = 0.007001
#alfa=0.05
#Wniosek: Odrzucamy hipoteze H02
#H0: meN=meS, H1: meN!=meS
wilcox.test(Ankieta$Œr.kursy~Ankieta$F.stud)
#W = 744.5, p-value = 0.5017
#alfa=0.05
#Wniosek na poziomie istotnosci 0.05 nie mamy podstaw do odrzucenia hipotezy H0, zatem srednia studentow stacjonarnych i niestacjonarcych nie rozni sie
