import matplotlib.pyplot as plt
import random as los

los.seed()
stany=['Z','C','ZD','ZZ']

pauza=0.03 
szansa_narodziny=0.25
xy=100 
czas=100 
ile=100 
rozm=100 

class Osobnik:

    def __init__(self,rodzenie) -> None:
        if(rodzenie==0):
            self.x=los.randint(1,rozm)
            self.y=los.randint(1,rozm)
            self.kierunekX=los.randint(-1,1)
            self.kierunekY=los.randint(-1,1)

            while(self.kierunekY==0 and self.kierunekX==0):
                self.kierunekX=los.randint(-1,1)
                self.kierunekY=los.randint(-1,1)
                
            self.wiek=los.randint(0,60)
            self.predkosc= los.randint(1,3)
            if ((self.wiek >= 0 and self.wiek < 15) or (self.wiek >= 70 and self.wiek <= 100)):
                self.odp=los.random() * (3-0.01) + 0.01

            elif (self.wiek >= 40 and self.wiek < 70):
                self.odp=los.random() * (6-3.01) + 3.01

            elif (self.wiek >= 15 and self.wiek < 40):
                self.odp=los.random() * (10-6.01) + 6.01

            self.zyje=True
            self.stan=los.choice(stany)
            self.czas=0

        elif(rodzenie==1):
            self.x=los.randint(1,rozm)
            self.y=los.randint(1,rozm)
            self.kierunekX=los.randint(-1,1)
            self.kierunekY=los.randint(-1,1)

            while (self.kierunekY == 0 and self.kierunekX == 0):
                self.kierunekX=los.randint(-1,1)
                self.kierunekY=los.randint(-1,1)

            self.wiek=0
            self.predkosc=los.randint(1,3)
            self.odp=10
            self.zyje=True
            self.stan='ZZ'
            self.czas=0

def ruch(osb):
    if(osb.x<=0):
        osb.kierunekX=los.randint(0,1)
    elif(osb.x>=100):
        osb.kierunekX=los.randint(-1,0)
    if (osb.y <= 0):
        osb.kierunekY=los.randint(0,1)
    elif (osb.y >= 100):
        osb.kierunekY=los.randint(-1,0)
    osb.x=osb.x+(osb.kierunekX*osb.predkosc)
    osb.y=osb.y+(osb.kierunekY*osb.predkosc)

def starzenie(osb):
    osb.wiek+=1
    if(osb.wiek>70):
        if(osb.odp>3):
            osb.odp=3
    elif(osb.wiek>=40 and osb.wiek<70):
        if(osb.odp>6):
            osb.odp=6

def narodziny(osb1,osb2):
    if(osb1.wiek<=40 and osb1.wiek>=20 and osb2.wiek<=40 and osb2.wiek>=20):
        czynarodziny=los.random()
        if(czynarodziny<=szansa_narodziny):
            osobnik=Osobnik(1)
            osobniki.append(osobnik)

def smierc(osb):
    if(osb.odp<=0 or osb.wiek>=100):
        osb.zyje=False

def stan(osb):
    if(osb.stan=='Z'):
        if(osb.czas==2):
            osb.stan='C'
            osb.czas=0
        else:
         osb.czas+=1
    elif(osb.stan=='C'):
        if(osb.czas==7):
            osb.stan='ZD'
            osb.czas=0
        else:
         osb.czas+=1
    elif(osb.stan=='ZD'):
        if(osb.czas==5):
            osb.stan='ZZ'
            osb.czas=0
        else:
         osb.czas+=1
    elif(osb.stan=='ZZ'):
        pass

def spotkanie(osb1,osb2):
    odl=max(abs(osb1.x - osb2.x),abs(osb1.y - osb2.y))
    if(odl<=2 and osb1.zyje==True and osb2.zyje==True):
        #ZZ z Z
        if(osb1.stan=="ZZ" and osb2.stan=="Z" and osb1.zyje==True and osb2.zyje==True):
            if(osb1.odp<=3):
                osb1.stan="Z"
                osb1.czas=-1
        elif(osb1.stan=="Z" and osb2.stan=="ZZ" and osb1.zyje==True and osb2.zyje==True):
            if(osb2.odp<=3):
                osb2.stan="Z"
                osb2.czas=-1   
       #ZZ z C         
        elif(osb1.stan=="ZZ" and osb2.stan=="C" and osb1.zyje==True and osb2.zyje==True):
            if(osb1.odp<=6):
                osb1.stan="Z"
            else:
                osb1.odp-=3
        elif(osb1.stan=="C" and osb2.stan=="ZZ" and osb1.zyje==True and osb2.zyje==True):
            if(osb2.odp<=6):
                osb2.stan="Z"
            else:
                osb2.odp-=3   
       #ZZ z ZD
        elif(osb1.stan=="ZZ" and osb2.stan=="ZD" and osb1.zyje==True and osb2.zyje==True):
            osb2.odp+=1
            if(osb2.odp>10):
               osb2.odp=10 
        elif(osb1.stan=="ZD" and osb2.stan=="ZZ" and osb1.zyje==True and osb2.zyje==True):
            osb1.odp+=1
            if(osb1.odp>10):
               osb1.odp=10  
        # ZZ z ZZ
        elif(osb1.stan=="ZZ" and osb2.stan=="ZZ" and osb1.zyje==True and osb2.zyje==True):
            temp=max(osb1.odp,osb2.odp)
            if ((osb1.wiek >= 0 and osb1.wiek < 15) or (osb1.wiek >= 70 and osb1.wiek <= 100) and temp>3):
                osb1.odp=3
            elif (osb1.wiek >= 40 and osb1.wiek < 70 and temp>6):
                osb1.odp=6
            else:
                osb1.odp=temp

            if ((osb2.wiek >= 0 and osb2.wiek < 15) or (osb2.wiek >= 70 and osb2.wiek <= 100) and temp>3):
                osb2.odp=3
            elif (osb2.wiek >= 40 and osb2.wiek < 70 and temp>6):
                osb2.odp=6
            else:
                osb2.odp=temp
        # C z Z        
        elif(osb1.stan=="C" and osb2.stan=="Z" and osb1.zyje==True and osb2.zyje==True):
            osb1.czas=-1
            if(osb2.odp<=6):
                osb2.stan="C"                 
        elif(osb1.stan=="Z" and osb2.stan=="C" and osb1.zyje==True and osb2.zyje==True):
            osb2.czas=-1 
            if(osb1.odp<=6):
                osb1.stan="C"               
        # C z ZD
        elif(osb1.stan=="C" and osb2.stan=="ZD" and osb1.zyje==True and osb2.zyje==True):
            if(osb2.odp<=6):
                osb2.stan="Z"
                osb2.czas=-1   
        elif(osb1.stan=="ZD" and osb2.stan=="C" and osb1.zyje==True and osb2.zyje==True):
            if(osb1.odp<=6):
                osb1.stan="Z"
                osb1.czas=-1                
        # C z C
        elif(osb1.stan=="C" and osb2.stan=="C" and osb1.zyje==True and osb2.zyje==True):
            osb1.odp=min(osb1.odp,osb2.odp)
            osb2.odp=osb1.odp
        # Z z ZD
        elif(osb1.stan=="Z" and osb2.stan=="ZD" and osb1.zyje==True and osb2.zyje==True):
            osb2.odp-=1
        elif(osb1.stan=="ZD" and osb2.stan=="Z" and osb1.zyje==True and osb2.zyje==True):
            osb1.odp-=1        
        #Z z Z
        elif(osb1.stan=="Z" and osb2.stan=="Z" and osb1.zyje==True and osb2.zyje==True):
            osb1.odp-=1
            osb2.odp-=1   
        #ZD z ZD
        elif(osb1.stan=="ZD" and osb2.stan=="ZD"):
            pass       

        osb1.kierunekX=los.randint(-1,1)
        osb1.kierunekY=los.randint(-1,1)
        while (osb1.kierunekY == 0 and osb1.kierunekX == 0):
            osb1.kierunekX=los.randint(-1,1)
            osb1.kierunekY=los.randint(-1,1)
        osb2.kierunekX=los.randint(-1,1)
        osb2.kierunekY=los.randint(-1,1)
        while (osb2.kierunekY == 0 and osb2.kierunekX == 0):
            osb2.kierunekX=los.randint(-1,1)
            osb2.kierunekY=los.randint(-1,1)
        return True
    else:
        return False

def odpornosc(osb):
    if(osb.stan=='Z'):
        osb.odp-=0.1
        
    elif(osb.stan=='C'):
        osb.odp-=0.50

    elif(osb.stan=='ZD'):
        osb.odp+=0.10
        if((osb.wiek >= 0 and osb.wiek < 15) or (osb.wiek >= 70 and osb.wiek <= 100)):
         if(osb.odp>3.0):
            osb.odp=3.0
        elif(osb.wiek >= 40 and osb.wiek < 70):
         if(osb.odp>6.0):
            osb.odp=6.0
        elif(osb.wiek >= 15 and osb.wiek < 40):
         if(osb.odp>10.0):
            osb.odp=10.0

    elif(osb.stan=='ZZ'):
        osb.odp+=0.05
        if((osb.wiek >= 0 and osb.wiek < 15) or (osb.wiek >= 70 and osb.wiek <= 100)):
         if(osb.odp>3.0):
            osb.odp=3.0
        elif(osb.wiek >= 40 and osb.wiek < 70):
         if(osb.odp>6.0):
            osb.odp=6.0
        elif(osb.wiek >= 15 and osb.wiek < 40):
         if(osb.odp>10.0):
            osb.odp=10.0

osobniki=[]

for i in range(0,ile):
    osobnik=Osobnik(0)
    osobniki.append(osobnik)

plt.figure()
for tura in range(0,czas):
    for osobnik1 in osobniki:
        for osobnik2 in osobniki:
            if(osobnik1!=osobnik2 and osobnik1.zyje==True and osobnik2.zyje==True):
                czyspotkanie=spotkanie(osobnik1,osobnik2)
                if(czyspotkanie==True):
                    narodziny(osobnik1,osobnik2)
    ilezyje = 0
    for osobnik in osobniki:
        if(osobnik.zyje==True):
            ilezyje=ilezyje+1
            if osobnik.stan == 'C':
                plt.plot(osobnik.x,osobnik.y,'.',color='red')
            elif osobnik.stan == 'Z':
                plt.plot(osobnik.x,osobnik.y,'.',color='yellow')            
            elif osobnik.stan == 'ZZ':
                plt.plot(osobnik.x,osobnik.y,'.',color='green')
            elif osobnik.stan == 'ZD':
                plt.plot(osobnik.x,osobnik.y,'.',color='orange')


        ruch(osobnik)
        starzenie(osobnik)
        odpornosc(osobnik)
        stan(osobnik)
        smierc(osobnik)

    plt.axis([0,xy,0,xy])
    plt.title('Tura: '+str(tura)+'  liczba żywych osobnikow: '+str(ilezyje))
    plt.show(block=False)
    plt.pause(pauza)
    plt.cla()



