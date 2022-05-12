out=sim("lab8_sl");
x=out.x;
y=out.y;
l=str2num(get_param("lab8_sl/Subsystem",'l'));
m=str2num(get_param("lab8_sl/Subsystem",'m'));
ai=str2num(get_param("lab8_sl/Subsystem",'ai'));
xi=str2num(get_param("lab8_sl/Subsystem",'xi'));
yi=str2num(get_param("lab8_sl/Subsystem",'yi'));
di=str2num(get_param("lab8_sl/Subsystem",'di'));

for i=1:length(x)
    a=sqrt(x(i)^2+y(i)^2);
    b=sqrt(l^2-a^2);
    z=l-b;
    plot3(x(i),y(i),z,'g.','markersize',10*m);
    hold on
    plot3([0,x(i)],[0,y(i)],[l,z],'k');
    for j=1:length(ai)
        if ai(j)<0
            plot3(xi(j),yi(j),di(j),'b.','MarkerSize',10*abs(ai(j)))
        else
            plot3(xi(j),yi(j),di(j),'r.','MarkerSize',10*abs(ai(j)))
        end
    end
    hold off
    daspect([1 1 1]);
    axis([-l,l,-l,l,-1,l+1])
    pause(0.02)
end