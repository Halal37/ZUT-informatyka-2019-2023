# Zadanie2
#a)
Ankieta$P�e�=factor(Ankieta$P�e�)
Ankieta$M.zamieszk=factor(Ankieta$M.zamieszk)
Ankieta$Sz.�rednia=factor(Ankieta$Sz.�rednia)
Ankieta$System=factor(Ankieta$System)
Ankieta$F.stud=factor(Ankieta$F.stud)
#b)
summary(Ankieta$Waga)
summary(Ankieta$Wzrost)
summary(Ankieta$M.zamieszk)
summary(Ankieta$System)
#c)
Ankieta$�r.kursy=(Ankieta$Prog1+Ankieta$Algebra+Ankieta$MSzS1+Ankieta$Narz.in�+Ankieta$WdI)/5
#d)
Ankieta.kursy = subset (Ankieta,select = c(Algebra,MSzS1,Narz.in�,Prog1,WdI))
#e)
Ankieta$Algebra=NULL
Ankieta$MSzS1=NULL
Ankieta$Narz.in�=NULL
Ankieta$Prog1=NULL
Ankieta$WdI=NULL
#lub
Ankieta=Ankieta[-(7:11)]
#f)
zakres3sigm<-function(x){
lewy.kres=mean(x)-(3*sd(x))
prawy.kres=mean(x)+(3*sd(x))
data.frame(
    lewy.kres,prawy.kres
  )
}
zakres3sigm(Ankieta$Wzrost)
#g)
zakres3sigm(Ankieta$�r.kursy)
#h)
Ankieta.K=filter(Ankieta, P�e�=='K')
Ankieta.M=filter(Ankieta, P�e�=='M')
#i)
#j)
Ankieta$L.g.kody=cut(Ankieta$L.godz,c(0,4,8,24),c("krotko","�rednio","d�ugo"))
#Zad3)
ggplot(Ankieta,aes(M.zamieszk))+geom_bar(fill='red',col='black')+ylab('Liczba zamieszka�ych')
ggplot(Ankieta,aes(Sz.�rednia))+geom_bar(fill='green',col='black')+ylab('Liczba os�b ko�cz�cych dan� szko�� ponadpodstawow� ')
ggplot(Ankieta,aes(M.zamieszk))+geom_bar(fill='red',col='black')+ylab('Liczba zamieszka�ych')
ggplot(Ankieta,aes(System))+geom_bar(fill='blue',col='black')+ylab('U�ywany system ')
