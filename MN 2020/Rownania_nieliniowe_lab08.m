F='exp(x)+(x.^2)-2'
f=inline(F)
x=-2:0.1:2;
plot(x,f(x))
grid on
a=input("Podaj poczatek przedzialu, czyli a ")
b=input("Podaj koniec przedzialu, czyli b ")
a_kopia=a;
b_kopia=b;
polowienie_iteracje=0;
falsi_iteracje=0;
newton_iteracje=0;
while(b-a)>0.001 
    polowienie_iteracje=polowienie_iteracje+1;
    c=(a+b)/2;
    if abs(f(c))<=0.001
        break 
    else
        if f(c)*f(a)<0
            b=c;
        else
            a=c;
        end
    end
  polowienie_wynik=(a+b)/2;  
end
f0=fzero(F,a_kopia)
polowienie_wynik
polowienie_iteracje
a=a_kopia;
b=b_kopia;
przedzial=a:0.1:b;
falsi_iteracje=0;
k=1;
while abs(przedzial(k+1)-przedzial(k))>0.001
    x1=(a*f(b)-b*f(a))/(f(b)-f(a));
    if(k+1 == length(przedzial))
       break
    end
    k=k+1;
    falsi_iteracje=falsi_iteracje+1;
    if f(a)*f(x1)<0
        przedzial(k+1)=(przedzial(k)*f(a)-a*f(przedzial(k)))/(f(a)-f(przedzial(k)));
    elseif f(b)*f(x1)<0
        przedzial(k+1)=(przedzial(k)*f(b)-b*f(przedzial(k)))/(f(b)-f(przedzial(k)));
    end
    falsi_wynik=przedzial(k+1);
end

falsi_iteracje
falsi_wynik
a=a_kopia;
b=b_kopia;
przedzial=a:0.1:b;
k=1;
h=0.01;
pochodna=(f(przedzial+h)-f(przedzial-h))/(2*h);
while (k<2)||(abs(przedzial(k)-przedzial(k-1))>0.001)
    newton_iteracje=newton_iteracje+1;
    k=k+1;
    if(abs(pochodna(newton_iteracje))>0.001)
       przedzial(newton_iteracje+1)=przedzial(newton_iteracje)-(f(przedzial(newton_iteracje))/pochodna(newton_iteracje));
    end
    if(przedzial(newton_iteracje+1)*f(a)>0)
        a=przedzial(newton_iteracje+1);
        newton_wynik=a;
    else
        b=przedzial(newton_iteracje+1);
        newton_wynik=b;
    end
    if(newton_iteracje+1 == length(przedzial))
       break
    end
end
newton_wynik
newton_iteracje