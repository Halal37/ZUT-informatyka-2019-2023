F='2*x.^2+y.^2+x.*y-6*x-5*y+8'
f=inline(F)
v=-5:0.1:5;
[x,y]=meshgrid(v);

z=f(x,y);
figure(1)
mesh(x,y,z)
figure(2)
contour(x,y,z,50)
hold on
x1=-4;
y1=-4;
x2=0;
y2=0;
ax=-5;
ay=-5;
bx=5;
by=5;
cy=(ay+by)/2;
cx=(ax+bx)/2; 
lx=bx-ax;
ly=by-bx
polowienie_iteracje=0
while (sqrt((x2-x1)^2+(y2-y1)^2) > 0.001)
    polowienie_iteracje=polowienie_iteracje+1;
        if polowienie_iteracje > 1
        x1=x2;
        y1=y2;
        end
          ly=by-ay;
   y1=ay+0.25*ly;
   y2=by-0.25*ly;
        if (f(x1,cy)<f(x1,y1) && f(x1,cy)<f(x1,y2))
            by=by-0.25*ly;
            ay=ay+0.25*ly;
            cy=(ay+by)/2; 
        elseif f(x1,cy)>f(x1,y2)
                ay=cy;
                cy=y2;
            else
                by=cy;
                cy=y1;
            
        end
        y2=(ay+by)/2;
  plot([x1 x1],[y1 y2],'r')
    lx=bx-ax;
   x1=ax+0.25*lx;
   x2=bx-0.25*lx;
        if (f(cx,y1)<f(x1,y1) && f(cx,y1)<f(x2,y1))
            bx=bx-0.25*lx;
            ax=ax+0.25*lx;
            cx=(ax+bx)/2; 
        elseif f(cx,y1)>f(x2,y1)
                ax=cx;
                cx=x2;
            else
                bx=cx;
                cx=x1;
            
        end
        x2=(ax+bx)/2;
  plot([x1 x2],[y2 y2],'r')

  polowienie_wynik1=(ax+bx)/2; 
  polowienie_wynik2=(ay+by)/2; 
end
polowienie_wynik1
polowienie_wynik2
polowienie_iteracje