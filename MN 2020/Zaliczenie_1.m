F='sqrt(2*x)'
f=inline(F)
x=2;
h=0.1;
pochodna_num_2=(f(x+h)-f(x))/h
pochodna_num_3=(f(x+h)-f(x-h))/(2*h)
pochodna_num_5=(f(x-2*h)+8*f(x+h)-8*f(x-h)-f(x+2*h))/(12*h)