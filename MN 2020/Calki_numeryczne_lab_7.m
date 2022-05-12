F='x.^(cos(x))'
f=inline(F)
a=0;
b=10;
n=50;
h=(b-a)/n;
x=a:h:b;
J_1=0;
for i=1:n-1
    J_1=f(a+i*h)+J_1;
end
J_1=h*J_1
pom=0;
for i=1:n-1
    pom=pom+f(a+i*h);
end
J_2=h*((f(a)/2)+pom+(f(b)/2))
j_3_pom_1=0;
j_3_pom_2=0;
for i=1:n-1
    if(mod(i,2)==0)
   j_3_pom_1=j_3_pom_1+f(a+i*h);
    else
    j_3_pom_2=j_3_pom_2+f(a+i*h);    
    end
end
J_3=(h/3)*(f(a)+4*j_3_pom_2+2*j_3_pom_1+f(b))
J_4=quad(f,a,b)
