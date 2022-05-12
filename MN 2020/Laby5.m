X=input("Wprowadz X ")
Y=input("Podaj Y ") 
p=input("Podaj stopien wielomianu")
n=length(X)
Psi=Lab_5_PSI(p,n,X)
Psi
F=Lab_5_F(p,n,X,Y)
F
A=Psi^(-1)*F
A
x=min(X):0.1:max(X)
y=Zad1(A,x)
plot(X,Y,'or',x,y,'b')