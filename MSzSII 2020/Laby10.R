#Zad10
# a) zalozenie 1: normalnosc rozkladow
#H0: rozklad wzrostu studenetek jest normalny, H1:~H0
#H0': rozklad wzrostu studentow jest normalny, H1':~H0'
by(Ankieta$Wzrost,Ankieta$P³eæ,shapiro.test)
#K:W = 0.92411, p-value = 0.3544
#M:W = 0.98949, p-value = 0.6305
#alfa=0.05
#Wniosek: brak podstaw do odrzucenia (alfa<p-value)

 #b) zalozenie 2: jednorodnosc wariancji
#H0:VarK=varM, H1:varK!=varM
var.test(data=Ankieta,Wzrost~P³eæ)
#F = 0.73035, num df = 10, denom df = 98, p-value = 0.6115 
#Wniosek: brak podstaw do odrzucenia H0 (alfa<p-value)

#c) test dla 2 œrednich 
#H0:mK = mM,H1:mK < mM
t.test(data=Ankieta,Wzrost~P³eæ,alternative='l',var.equal=T)
#t = -5.84, df = 108, p-value = 2.788e-08
#alfa=0.05
#Wniosek:Na poziomie istotnosci 0.05 odrzucamy hipoteze H0
# i przyjmujemy H1, zetem sredni wzrost studentek
#jest istotnie nizszy niz sredni wzrost w populacji 
#studentow

#Zadanie 2
table(Ankieta$M.zamieszk)
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
table(Ankieta$M.zamieszk,Ankieta$F.stud)
#H0: pN=pS, H1: pN != pS,
prop.test(c(6,50),c(18,92))
#X-squared = 1.8858, df = 1, p-value = 0.1697
#Wniosek: Na poziomie istotnosci 0.05 nie ma podstaw
#do odrzucenia hipoteze H0, ze odsetki osob mieszkajacych 
# w misezkaniu z rodzina dla studentow niestacjonarnych oraz
#stacjonarnych sa takie same 

#zad3 
# a) zalozenie 1: normalnosc rozkladow
#H0: rozklad wzrostu studenetek jest normalny, H1:~H0
#H0': rozklad wzrostu studentow jest normalny, H1':~H0'
by(Ankieta$Wiek,Ankieta$F.stud,shapiro.test)
#N:W = 0.94534, p-value = 0.3566
#S:W = 0.96411, p-value = 0.01237
#alfa=0.01
#Wniosek brak podstaw do odrzucenia H0 i H0'

#b)
var.test(data=Ankieta,Wiek~F.stud)
#H0:varN=varS, H1:varN!=varS
#F = 0.70896, num df = 17, denom df = 91, p-value = 0.4275
#alfa=0.01
#Wniosek: brak podstaw do odrzucenia H0 (alfa<p-value)

#c) 
#H0:mN = mS,H1:mN != mS
t.test(data=Ankieta,Wiek~F.stud,alternative='t',var.equal=T)
#t = 0.10828, df = 108, p-value = 0.914
#alfa=0.01
#Wniosek: Na poziomie istotnosci 0.01 brak podstaw by odrzucic hipoteze H0
# Zatem sredni wiek pierwszego samodzielnego zetkniecia sie z 
#komputerem w populacji wszystkich stu-dentow I roku na WI nie zalezy od formy studiow

#Zad4
#a)
table(Ankieta$Sz.œrednia)
prop.test(45,110,conf.level=0.99)
#0.2927890 0.5361135
#Przedzia³ ufnoœci o koñcach 0.2927890 0.5361135 dla poziomu ufnosci 0.98 obejmuje odsetek osob, ktore ukonczyly technikum informatyczne
#b)
#H0: p=25%, H1 p>25%
prop.test(39,110,p=0.25,alternative='g')
#X-squared = 5.8667, df = 1, p-value = 0.007715
#Wniosek: na poziomie istotnosci 0.01 odrzucamy hipoteze H0
#na rzecz H1, czyli odsetek osob, ktore ukonczyly LO z rozszerzona matematyka
# jest istotnie wiekszy niz 25%

#c) test dla dwoch wskaznikow struktury 
table(Ankieta$Sz.œrednia,Ankieta$F.stud)
#H0: pN=pS, H1: pN < pS,
prop.test(c(5,40),c(18,92),alternative='l')
#X-squared = 0.95436, df = 1, p-value = 0.1643
#Wniosek: na poziomie istotnosci 0.01 nie ma podstaw do odrzucenia hipotezy H0
#zatem odsetki nie roznia sie zbytnio