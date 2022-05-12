%zad1
A=[-4 -6 -15; -2 -2 0;-5 -3 -4;-7 -3 -12]
b=[-250 -60 -100 -220]
f=[2 1.5 3]
Aeq=[ ];
beq=[];
lb=[0 0 0]
ub=[];
[X,Z]=linprog(f,A,b,Aeq,beq,lb,ub);
x=ceil(X)
Z=f*x
sklad=-A*x
%zad2
A2=[ 5 25; 1/2 0; 100 250; 10 10];
b2=[500 15 7500 400];
f2=[-100 -200];
Aeq2=[ ];
beq2=[];
lb2=[0 0];
ub2=[];
[X2,Z2]=linprog(f2,A2,b2,Aeq2,beq2,lb2,ub2);
X2
Z2=-Z2
sklad2=A2*X2
