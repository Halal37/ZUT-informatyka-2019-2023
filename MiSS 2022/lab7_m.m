out=sim("lab7_sl");
th1=out.r;
th2=out.th;
l1=str2num(get_param("lab7_sl/Subsystem",'l1'));
l2=str2num(get_param("lab7_sl/Subsystem",'l2'));
m1=str2num(get_param("lab7_sl/Subsystem",'m1'));
m2=str2num(get_param("lab7_sl/Subsystem",'m2'));


for i=1:length(th1)
    x1=-l1*sin(th1(i));
    y1=-l1*cos(th1(i));
    x2=x1-l2*sin(th2(i));
    y2=y1-l2*cos(th2(i));
    
    ls=th1(i);
    plot([0 x1],[0 y1],'Color','r','LineWidth',2);
    xa = 0; ya = 0; xb = -ls*sin(th2(i)); yb = -ls*cos(th2(i)); ne = 10; a = 1; r0=0.3;
    hold on
    plot(x1, y1, 'b.','MarkerSize',5*m1);
    hold on
    plot([x1 x2],[y1 y2],'Color','r','LineWidth',2);
    hold on
    plot(x2, y2, 'b.','MarkerSize',5*m2);
    hold off
    axis([-1.1*(l1+l2) 1.1*(l1+l2) -1.1*(l1+l2) 1.1*(l1+l2)])
    pause(0.01)
end