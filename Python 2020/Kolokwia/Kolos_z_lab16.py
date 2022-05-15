#zad1
from PIL import Image
img=Image.open("C:\Lab11\logo.png")
img=img.rotate(90,expand=True)
img=img.convert('LA')
img.save("C:\\Lab11\\wynik.png")
#zad2
from scipy import optimize
import math
def f(x,*args):
    x1=x[0]
    x2=x[1]
    
    return (x1+10*math.sin(x2)*math.cos(x1)+x1**5)
x0=[-6,6]
tol=1e-6
ograniczenia=((-10,None),(None,10))
min=optimize.minimize(f,x0,bounds=ograniczenia,tol=tol)
print("Wyniki x i y: ",min.x)
#zad3
from scipy import interpolate
x=[-6,-3,-1,3,4,8,9,12,14]
y=[13,4,2,1,5,7,9,16,20]
#zmienione za rada na zajeciach wzgledem polecenia z 510 na 10
wyniki3=[2,10]
funckja_inter=interpolate.interp1d(x,y,kind="cubic")
print("Wyniki dla x=2 i x=10 ",funckja_inter(wyniki3))