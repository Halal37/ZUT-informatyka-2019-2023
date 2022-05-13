#lab1

#zad 1 a)
2*(3^3)+log(2401,7)
#b)
2^(1/3)
#c)
(2^(1/3))^(1/5)
#Zad 2
Zad2M1=matrix(c(1,-10,12,3,2,1,-8,4,5),3,3)
Zad2M2=matrix(c(1,3,-1,2,1,5),3,2)
#a)
det(Zad2M1)
#b)
solve(Zad2M2)
#c)
TransZad2M1=t(Zad2M1)
det(TransZad2M1)
#d)
Zad2M1%*%Zad2M2
Zad2M1%*%Zad2M1
Zad2M1%*%TransZad2M1
#e)
Zad2M1[1,1:3]*Zad2M2[1:3,2]
#Zad3
Zad3M1=matrix(c(1,2,5,-2,1,2,5,-3,-1,0,2,1,-2,3,5,2),4,4)
Zad3M2=matrix(c(-7,21,40,2),4,1)
solve(Zad3M1,Zad3M2)
#Zad4
Zad4M1=c(1:100)
Zad4M2=Zad4M1*Zad4M1
summary(factor(Zad4M2%%10))
summary(factor(Zad4M2%%2))
summary(factor(Zad4M2%%3))
summary(factor(Zad4M2%%6))
#Zad5
r=function (x){
  wartosc=x*(pi/180)
}
Zad5M1=r(c(0,30,45,60,90))
data.frame(
  cosinus=cos(Zad5M1),sinus=sin(Zad5M1),tangens=tan(Zad5M1),cotangens=cos(Zad5M1)/sin(Zad5M1))
#Zad6
Zad6M1=1:30
Zad6M2=c("A","B","C")
paste(Zad6M1,Zad6M2)

#Laby2

#zad1
dbinom(c(0,1,2,3,4),4,1/3)
#zad2
#a)
dbinom(2,100,0.01)
#b)
pbinom(2,100,0.01)
#zad3
dgeom(3,0.02)
#zad4
dbinom(2,4,1/7)
#zad5
dbinom(3,4,0.5)
dbinom(5,8,0.5)
#zad6
1-pbinom(2,750,0.004)
#Zad7
#a)
dbinom(5,10,0.5)
#b)
pbinom(8,10,0.5)-pbinom(2,10,0.5)
#Zad8
#a)
dgeom(4,1/6)
#b)
1-pgeom(5,1/6)
#Zad9
1-pbinom(2,400,0.005)

#Laby3


#Zad1
#a)
qnorm(0.97)
#b)
qchisq(0.975,9)
#c)
qt(0.95,9)
#d)
qf(0.995,10,23)
#Zad2
#a)
pnorm(2.5,1.5,2)
#b)
1-pnorm(-0.5,1.5,2)
#c)
pnorm(2,1.5,2)-pnorm(0.5,1.5,2)
#d)
#x<5 i x>-1
pnorm(5,1.5,2)-pnorm(-1,1.5,2)
#e)
#x<1 i x>0
pnorm(1,1.5,2)-pnorm(0,1.5,2)
#f)
#x<-0.5 lub x>0.5, czyli 1-przedzial xe[-0.5;0.5]
1-(pnorm(0.5,1.5,2)-pnorm(-0.5,1.5,2))
#g)
#x>1 lub x<-1/3
1-(pnorm(1,1.5,2)-pnorm(-1/3,1.5,2))
#Zad3
#Liczymy dla jednej zarowki dystrybuante, dlatego mnozymy przez 1000
#Wynik 23, bo to 22.cos podnosimy o jeden, bo nie ma fragmentu zarowki
pnorm(90,100,5)*1000
#Zad4
#a)
(1-pnorm(7.1,6.8,0.3))*30
#b)
#kwantyl przestrzen od zera do danego wyniku. Mediana kwantyl dla 50%
qnorm(0.15,6.8,0.3)
#Zad5
#a)
pnorm(10,15,13)-pnorm(5,15,13)
#b)
1-pnorm(20,15,13)
#Zad6
#a)
qnorm(0.8849,20,5)
#b)
qnorm(1-0.6554,20,5)
#c)
20-qnorm((1-0.6826)/2,20,5)
#d)
20-qnorm((0.00511)/2,20,5)

#Laby4

#Zad1
#a)
# qnorm(0.5)=(5-m)/1
pnorm(6,5-qnorm(0.5),1)-pnorm(3,5-qnorm(0.5),1)
#b)
#qnorm(0.6)=(6-m)/2
pnorm(6,6-2*qnorm(0.6),2)-pnorm(3,6-2*qnorm(0.6),2)
#Zad2
#m=5.2% 
(0.03-0.052)/qnorm(0.121)
qnorm(0.8,0.052,(0.03-0.052)/qnorm(0.121))*100
#Zad3
#m=10, 5=qnorm(0.95,10,sig) sig=a-m/qnorm(p)
pnorm(0,10,-(5-10)/qnorm(0.95))
#zad4
#m=46% 
#4/qnorm(0.6)=sig
#1-kwnatyl(0.70,)
#a)
1-pnorm(70,46,(4/qnorm(0.6)))
#b)
qnorm(0.9,46,(4/qnorm(0.6)))

#Laby5

#Zad1
# x<90.5 i X>82.5 p=0.3472 
4/qnorm(1.3472/2)
(1-pnorm(95,86.5,4/qnorm(1.3472/2)))*400
#Zad2

qnorm(0.75,4001.5,(-2265.6/qnorm(0.2)))
#Zad3
A=matrix(c(1,1,qnorm(0.8),qnorm(0.44)),2,2)
B=matrix(c(2,1.5),2,1)
m=solve(A,B)[1]
sig=solve(A,B)[2]
pnorm(0.5,m,sig)
#Zad4
A=matrix(c(1,1,qnorm(2/524),qnorm(517/524)),2,2)
B=matrix(c(17,70),2,1)
m=solve(A,B)[1]
sig=solve(A,B)[2]
pnorm(55,m,sig)-pnorm(45,m,sig)
#Zad5
10/qnorm(1.93/2)
500*(1-pnorm(170,165,10/qnorm(1.93/2)))
#Laby6
#Zad1
pnorm((132.5-96)/sqrt(96*0.92))-pnorm((84.5-96)/sqrt(96*0.92))
#Zad2
pnorm((498-497.5)/(0.05*sqrt(250)))
#Zad3
pnorm(24.5/(sqrt(50*0.99)))
#Zad4
pnorm(4/(0.4*sqrt(40)))
#Zad5
#a)
pnorm(4.5/sqrt(475*0.525))
#b)
pnorm(-5.5/sqrt(475*0.525))-pnorm(-74.5/sqrt(475*0.525))
