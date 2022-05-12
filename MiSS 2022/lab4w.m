
out=sim("lab4_");
x=out.x;
y=out.y;
R=str2num(get_param("lab4_/Subsystem",'R'));
rs=str2num(get_param("lab4_/Subsystem",'rs'));

for i=1:length(x)
    plot(x(1:i),y(1:i))
    rectangle('Position',[-R -R, 2*R,2*R], 'Curvature', [1 1]);
    rectangle('Position',[x(i)-rs,y(i)-rs,2*rs,2*rs],'Curvature',[1 1]);
    axis([-8 8 -8 8])
    daspect([1 1 1])
    pause(2^-7)
end