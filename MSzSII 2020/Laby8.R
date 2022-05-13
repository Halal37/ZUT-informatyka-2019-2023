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
#a)
Ankieta.M=filter(Ankieta, P³eæ=='M')
p.opisowe(Ankieta.M$Wzrost)
p.opisowe(Ankieta$Œr.kursy)
p.opisowe(Ankieta$L.godz)
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
#Zadanie 4
#a)
ggplot(Ankieta, aes(x=P³eæ,
 y=Waga))+geom_boxplot(fill='#00FFFF',
col='black')
ggplot(Ankieta, aes(x=P³eæ,
                    y=Wzrost))+geom_boxplot(fill='#00FFFF',
                                          col='black')
ggplot(Ankieta, aes(x=M.zamieszk,
                    y=Œr.kursy))+geom_boxplot(fill='#00FFFF',
                                          col='black')
ggplot(Ankieta, aes(x=M.zamieszk,
                    y=L.godz))+geom_boxplot(fill='#00FFFF',
                                          col='black')
#b)
stem(Ankieta$Waga)
stem(Ankieta$Wzrost)
#c)
ggplot(Ankieta.M,aes(x=Wzrost))+geom_histogram(fill='red',col='black',binwidth = 10)+ylab('liczba osób')
