F='x.^(cos(x))'
f=inline(F)
a=0;
b=10;
x=a:0.1:b;
y=f(x);
n=3000;
x_a=(b-a)*rand(1,n);
y_a=(b-a)*rand(1,n);  
J_monte_carlo=(sum(f(x_a))*(b-a))/n
J_quad=quad(f,a,b)
hold on
for i=1:length(x_a)
 if(y_a(i)>=f(x_a(i))) plot(x_a(i),y_a(i),'k*')
 else plot(x_a(i),y_a(i),'m*')
 end  
end
plot(x,y,'b')