x=0:0.1:10
h=0.2;
y=x.^(cos(x))
F='x.^(cos(x))'
f=inline(F)
pochodna_analityczna=(x.^(cos(x)-1)).*(cos(x)-x.*log(x).*sin(x));
pochodna_num_2=(f(x+h)-f(x))/h;
pochodna_num_3=(f(x+h)-f(x-h))/(2*h);
pochodna_num_5=(f(x-2*h)+8*f(x+h)-8*f(x-h)-f(x+2*h))/(12*h);
hold on
grid on
plot(x,y)
plot(x,pochodna_analityczna,'b--')
plot(x,pochodna_num_2,'m--')
plot(x,pochodna_num_3,'k--')
plot(x,pochodna_num_5,'y--')
legend('funkcja','pochodna_analityczna','pochodna_num_2','pochodna_num_3','pochodna_num_5')
title(['Funckja i pochodne F(x)=x^(cos(x))'])
hold off