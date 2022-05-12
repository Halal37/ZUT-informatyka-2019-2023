f=inline('2*x.^2+y.^2+x.*y-6*x-5*y+8')
v=-5:0.1:5;
[x,y]=meshgrid(v);

z=f(x,y);
figure(1)
mesh(x,y,z)
figure(2)
contour(x,y,z,50)
a=0.2;
x0=-4;
y0=4;
f(x0,y0)
f(x0-a,y0)
f(x0,y0+a)
f(x0+a,y0)

x=(f,x0)