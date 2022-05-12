F='2*x.^2+y.^2+x.*y-6*x-5*y+8'
f=inline(F);
p=inline('4*x+y-6');
g=inline('2*y+x-5');
v=-5:0.1:5;
[x,y]=meshgrid(v);
e = 0.1;

z=f(x,y);
contour(x,y,z,50)
hold on
a=0.1
h=0.05
x0=-5;
y0=-5;
b=(f(x0+h,y0)-f(x0-h,y0))/(2*h);
c=(f(x0,y0+h)-f(x0,y0-h))/(2*h);
while (sqrt(b^2+c^2)>e)
b=(f(x0+h,y0)-f(x0-h,y0))/(2*h);
c=(f(x0,y0+h)-f(x0,y0-h))/(2*h);
inna=a/sqrt(b^2+c^2);
x1=x0-inna*b;
y1=y0-inna*c;
plot([x0, x1], [y0, y1], 'r');
x0=x1;
y0=y1;
end
x0
y0