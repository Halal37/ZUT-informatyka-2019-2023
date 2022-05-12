out=sim("Lab5_mod1");
r=out.r;
th=out.th;
l=str2num(get_param("Lab5_mod1/Subsystem",'l'));
m=str2num(get_param("Lab5_mod1/Subsystem",'m'));
lmax=l+max(r);

for i=1:length(r)
    ls=l+r(i);
    %plot([0 -ls*sin(th(i))],[0 -ls*cos(th(i))],'Color','r','LineWidth',2);
    %plot([0 -ls*sin(th(i))],[0 -ls*cos(th(i))],'LineWidth',2)
    xa = 0; ya = 0; xb = -ls*sin(th(i)); yb = -ls*cos(th(i)); ne = 10; a = 1; r0=0.3;
    [xs,ys] = spring(xa,ya,xb,yb,ne,a,r0); plot(xs,ys,'LineWidth',2)
    hold on
    plot(-ls*sin(th(i)), -ls*cos(th(i)), 'b.','MarkerSize',5*m);
    hold off
    axis([-1.1*lmax 1.1*lmax -1.1*lmax 1.1*lmax])
    pause(0.01)
end
    