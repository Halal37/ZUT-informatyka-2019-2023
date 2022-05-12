syms a
syms b
F='2*x.^2+y.^2+x.*y-6*x-5*y+8'
f=inline(F);
v=-5:0.1:5;
[x,y]=meshgrid(v);
e = 0.001;

z=f(x,y);
contour(x,y,z,50)
hold on

x0 = -4;
y0 = -4;
x1=0;
x2=0;
y1=0;
y2=0;
d1x = 1;
d1y = 0;
d2x = 0;
d2y = 1;
iteracje=0;
while(sqrt((x1-x0)^2+(y1-y0)^2) > e)||(sqrt((x2-x0)^2+(y2-y0)^2) > e)
    
    iteracje=iteracje+1;
    
    x1 = x0 + a * d1x;
    y1 = y0 + a * d1y;
    pierwsza = diff(f(x1, y1));
    pierwsza_wynik = solve(pierwsza, a);
    x1 = x0 + pierwsza_wynik * d1x;
    y1 = y0 + pierwsza_wynik * d1y;
    plot([x0, x1], [y0, y0], 'r');
    

    x2 = x0 + b * d2x;
    y2 = y0 + b * d2y;
    druga = diff(f(x2, y2));
    drugi_wynik = solve(druga, b);
    x2 = x0 + drugi_wynik * d2x;
    y2 = y0 + drugi_wynik * d2y;
    
    if(f(x1, y1) < f(x2, y2))
        x0 = x1;
        y0 = y1;
    else
        x0 = x2;
        y0 = y2;
    end   
    plot([x0, x0], [y0, y1], 'r');
end
iteracje
x_min=vpa(simplify(x0), 5)
y_min=vpa(simplify(y0), 5)
punkt_startowy=[-4;-4];
fun=@(x)2*x(1)^2+x(2)^2+x(1)*x(2)-6*x(1)-5*x(2)+8;
wynik=fminsearch(fun,punkt_startowy)