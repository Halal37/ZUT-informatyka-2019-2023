clc;
close all;
clear;
%Zad1
load("lab11_data2.mat")

xu=data2(:,[1:2]);
xu=xu.';
zu=data2(:,[3:6]);
zu=zu.';

rs=xu*zu.';
ps=zu*zu.';
c=rs*ps^(-1)

zu2=[zu;zu.^2];
rs2=xu*zu2.';
ps2=zu2*zu2.';
c2=rs2*ps2^(-1)
%Zad2
load("lab11_data1.mat")

xt=data1(:,[1:2]);
zt=data1(:,[3:6]);
xpp1=zt*c(1,:).';
ypp1=zt*c(2,:).';

zt2=[zt,zt.^2];
xpp2=zt2*c2(1,:).';
ypp2=zt2*c2(2,:).';

errorx1=mean((xpp1-xt(:,1)).^2);
errory1=mean((ypp1-xt(:,2)).^2);
error1=(errorx1+errory1)/2

errorx2=mean((xpp2-xt(:,1)).^2);
errory2=mean((ypp2-xt(:,2)).^2);
error2=(errorx2+errory2)/2

%Zad3

ddx=@(dx,dy,x,y) [dx,dy,x,y]*c(1,:).';
ddy=@(dx,dy,x,y) [dx,dy,x,y]*c(2,:).';
x(1)=60;y(1)=0;xp(1)=0;yp(1)=0;

xpp(1)=ddx(xp(1),yp(1),x(1),y(1));
ypp(1)=ddy(xp(1),yp(1),x(1),y(1));
STOP=500;
h=2^(-8);

for t=h:h:STOP
    x(end+1)=x(end)+h*xp(end);
    y(end+1)=y(end)+h*yp(end);
    xp(end+1)=xp(end)+h*xpp(end);
    yp(end+1)=yp(end)+h*ypp(end);
    xpp(end+1)=ddx(xp(end),yp(end),x(end),y(end));
    ypp(end+1)=ddy(xp(end),yp(end),x(end),y(end));
end

figure('Name','Euller');
plot(x,y);
figure('Name','From file data');
plot(zt(:,3),zt(:,4))


