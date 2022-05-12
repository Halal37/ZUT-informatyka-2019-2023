syms a
f=inline('2*x.^2+y.^2+x.*y-6*x-5*y+8');
v=-5:0.1:5;
[x,y]=meshgrid(v);
epsilon = 0.001;

z=f(x,y);
contour(x,y,z,50)
hold on

%solve for direction d1 = (1, 0)
x0 = -4;
y0 = -4;
last_x = x0;
last_y = y0;
d1x = 1;
d1y = 0;
d2x = 0;
d2y = 1;

iter = 0;

while(1)
    iter = iter + 1;
    x1 = x0 + a * d1x;
    y1 = y0 + a * d1y;
    f(x1, y1);

    der = diff(f(x1, y1));
    result_a = solve(der, a);
    x1 = x0 + result_a * d1x;
    y1 = y0 + result_a * d1y;
    f(x1, y1);
    plot([x0, x1], [y0, y0], 'r');
    
    %t1 = sqrt((x1 - x0)^2 + (y1 - y0)^2)

    %solve for direction d2 = (0, 1)

    x2 = x0 + a * d2x;
    y2 = y0 + a * d2y;
    f(x2, y2);
    der = diff(f(x2, y2));
    result_a = solve(der, a);
    x2 = x0 + result_a * d2x;
    y2 = y0 + result_a * d2y;
    
    %t2 = sqrt((x2 - x0)^2 + (y2 - y0)^2)

    f(x2, y2);
    
    if(f(x1, y1) < f(x2, y2))
        x0 = x1;
        y0 = y1;
    else
        x0 = x2;
        y0 = y2;
    end
    
    plot([x0, x0], [y0, y1], 'r');
    condition = sqrt((x2 - x1)^2 + (y2 - y1)^2);
    check = vpa(simplify(condition), 5);
    if(check < epsilon)
        break
    end
end
x0;
x1;
x2;
vpa(simplify(x2), 5)
y0;
y1;
y2;
vpa(simplify(y2), 5)
iter