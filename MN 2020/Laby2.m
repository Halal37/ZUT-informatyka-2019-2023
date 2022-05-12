A=input("Wprowadz macierz ")
b=input("Wprowadz b ")
%wzory Cramera
t=Cramer(A,b)
%metoda eliminacji gaussa jordana
w=eliminacja_gaussa_jordana(A,b);
%dzielenie macierzy
z=A\b
%macierz odwrotna
x=inv(A)*b
