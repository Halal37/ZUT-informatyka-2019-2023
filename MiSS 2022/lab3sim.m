
OUT=sim('lab4_2.slx');
th=OUT.th;
l=str2num(get_param('lab4_2/Subsystem','l'))
m=str2num(get_param('lab4_2/Subsystem','m'))
for i=1:length(th)
    plot([0 -l*sin(th(i))],[0 -l*cos(th(i))],'Color','r','LineWidth',2);
    hold on
    plot(-l*sin(th(i)), -l*cos(th(i)), 'b.','MarkerSize',5*m);
    hold off
    axis([-1.1*l 1.1*l -1.1*l 1.1*l])
    pause(0.01)
end