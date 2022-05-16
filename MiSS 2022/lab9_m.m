out=sim("lab9_sl");
h1=out.h1;
h2=out.h2;
S1=str2num(get_param("lab9_sl/Subsystem",'S1'));
S2=str2num(get_param("lab9_sl/Subsystem",'S2'));
Swy1=str2num(get_param("lab9_sl/Subsystem",'Swy1'));
Swy2=str2num(get_param("lab9_sl/Subsystem",'Swy2'));
g=str2num(get_param("lab9_sl/Subsystem",'g'));
qwe=str2num(get_param("lab9_sl/Subsystem",'qwe'));
f1=str2num(get_param("lab9_sl/Subsystem",'f1'));
f2=str2num(get_param("lab9_sl/Subsystem",'f2'));

for i=1:length(h1)
    plot([0,0],[0,max(h1)+1],'b')
    hold on
    plot([0,S1+S2+2],[0,0],'b')
    plot([S1,S1],[Swy1,max(h1)+1],'b')
    plot([S1,S1+1],[Swy1,Swy1],'b')
    plot([S1+1,S1+1],[Swy1,max(h2)+1],'b')
    plot([S1+S2+1,S1+S2+1],[Swy2,max(h2)+1],'b')
    plot([S1+S2+1,S1+S2+2],[Swy2,Swy2],'b')
    
    fill([0,S1,S1,0],[0,0,h1(i),h1(i)],[135/255,206/255,235/255],'EdgeColor','None')
    fill([S1,S1+1,S1+1,S1],[0,0,Swy1,Swy1],[135/255,206/255,235/255],'EdgeColor','None')
    fill([S1+1,S1+S2+1,S1+S2+1,S1+1],[0,0,h2(i),h2(i)],[135/255,206/255,235/255],'EdgeColor','None')
    fill([S1+S2+1,S1+S2+2,S1+S2+2,S1+S2+1],[0,0,Swy2,Swy2],[135/255,206/255,235/255],'EdgeColor','None')
    hold off
    axis([-1,S1+S2+2,-1,max(h1)+2])
    pause(0.02)
end