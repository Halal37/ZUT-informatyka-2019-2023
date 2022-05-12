x=[-3.0,-2.5,-2.0,-1.5,-1.0,-0.5,0.0,0.5,1.0,1.5,2.0,2.5,3.0]
y=[-0.2,-0.3,0.6,1,0.4,-0.3,0,0.3,-0.4,-1,-0.6,0.2,0.2]
xp=0.8
yp=-0.05
%Zad2
wynik1=interp1(x,y,xp,'nearest')
wynik2=interp1(x,y,xp,'linear')
wynik3=interp1(x,y,xp,'spline')
wynik4=interp1(x,y,xp,'cubic')
%Najbardziej dokladny spline, potem blisko nearest
%zad3
figure()
hold on

xx=linspace(-3.0,3.0,1000)

y1=interp1(x,y,xx,'nearest')
y2=interp1(x,y,xx,'linear')
y3=interp1(x,y,xx,'spline')
y4=interp1(x,y,xx,'cubic')
plot(x,y)
plot(xx,y1)
plot(xx,y2)
plot(xx,y3)
plot(xx,y4)
legend({'oryginal','nearest','linear','spline','cubic'})
%Najlepsza metoda spline
%Zad4 
n=[1,2,3,4,5,6,7,8,9,10,11,12,13]
p=polyfit(x,y,9)
y5=polyval(p,xx)
hold on
plot(xx,y5)
%zad5
wynik=polyval(p,xp)