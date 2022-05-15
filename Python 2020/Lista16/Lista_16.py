#from scipy.misc import imread,imsave
from PIL import Image, ImageEnhance 
import numpy as np
import scipy as sc
from scipy import optimize
from scipy import interpolate
from scipy import integrate
import math
img=np.array(Image.open("C:\Lab11\logo.png"))
img=256-img
img=Image.fromarray((img).astype(np.uint8))
img.save("C:\Lab11\logoN.png")

#zad2
img2=Image.open("C:\Lab11\logo.png")
img2=img2.reduce(1,(0,0,150,140))
img2=img2.convert('LA')
img2=img2.rotate(45,expand=True)
img2=ImageEnhance.Brightness(img2)
img2=img2.enhance(0.3)
img2.save("C:\Lab11\logo2.png")

#zad3
img3=Image.open("C:\Lab11\obraz1.png")
img3=img3.reduce(1,(0,0,160,160))
rotacja1=img3.rotate(180)
rotacja2=img3.rotate(90)
rotacja3=rotacja1.rotate(90)

nowy1=Image.new('RGB',(img3.width+rotacja3.width,img3.height))
nowy1.paste(img3,(0,0))
nowy1.paste(rotacja3,(img3.width,0))

nowy2=Image.new('RGB',(rotacja2.width+rotacja1.width,rotacja2.height))
nowy2.paste(rotacja2,(0,0))
nowy2.paste(rotacja1,(rotacja2.width,0))

nowy3=Image.new('RGB',(nowy1.width,nowy1.height+nowy2.height))
nowy3.paste(nowy1,(0,0))
nowy3.paste(nowy2,(0,nowy1.height))

nowy3.save("C:\\Lab11\\obraz2.png")

#zad4
#sc.optimize.minimize()
x0=[-10,-10]
tol=1e-6
def fun(x,*args):
    x1=x[0]
    x2=x[1]
    return (((x1+2*x2-7)**2)+(2*x1+x2-5)**2)
wynik=optimize.minimize(fun,x0,tol)
print(wynik)
def fun2(x,*args):
    x1=x[0]
    x2=x[1]
    
    return 0.5+(((math.sin((x1**2)-(x2**2))**2)-0.5)/(1+((x1**2)-(x2**2))*0.001)**2)
x0=[-5,5]
wynik2=optimize.minimize(fun2,x0,tol)
print(wynik2)

#zad5
def funmin(x,*args):
    x1=x[0]
    x2=x[1]
    
    return (x1-3*x2+2)
x0=[1,2]
bd=((2,10),(1,8))
cons=({'type': 'ineq','fun': lambda x: 2*x[0]+x[1]-6},
     {'type': 'ineq','fun': lambda x: -x[0]+x[1]-1} )
wynikmin=optimize.minimize(fun2,x0,bounds=bd,constraints=cons,tol=tol)
print(wynikmin)
#zad6
def fun2(x,*args):
    x1=x[0]
    x2=x[1]
    
    return 0.5+(((math.sin((x1**2)-(x2**2))**2)-0.5)/(1+((x1**2)-(x2**2))*0.001)**2)
def fun3(x,y,*args):
 
    return math.exp(x+2*y)
wynik3=integrate.nquad(fun3,[[0,1],[0,1]]) 
print("Calka")
print(wynik3)
def fun4(x,y,*args):
 
    return (x+(y**2)*x)

def fun5(x,y,*args):
 
    return (x*math.sin(x)+6*y**2)
wynik4=integrate.nquad(fun4,[[0,2],[2,3]]) 
print("Calka")
print(wynik4)
wynik5=integrate.nquad(fun5,[[0,2],[0,math.pi]]) 
print("Calka")
print(wynik5)
#zad7
def fun6(x,*args):

    return (-(x**4)+(4*x**3)+(2*x**2)+8)
def fun7(x,*args):
     y=[0]*len(x)
     dana=0
     for i in x:
         y[dana]=(-(i**4)+(4*i**3)+(2*i**2)+8)
         dana+=1
     return y
dokladny=integrate.quad(fun6,-1,4) 
print("To jest dokladny wynik: ",dokladny)
x_do_cal=[-1,0,1,2,3,4]
#do_wzgl=dokladny[0]
trapezy=integrate.simps(fun7(x_do_cal),x_do_cal)
print("To jest trapezow wynik: ",trapezy)
print("Blad wzgledny trapez: ",abs(dokladny[0]-trapezy)/dokladny[0])
parabole=integrate.trapz(fun7(x_do_cal),x_do_cal)
print("To jest parabol wynik: ",parabole)
print("Blad wzgledny parabole: ",abs(dokladny[0]-parabole)/dokladny[0])

#zad8
import matplotlib.pyplot as plt

x=[7,10,11,15,19]
y=[7,12,13,15,13]
c=[9.75,12.10,17]
interpolacja=interpolate.interp1d(x,y,kind="cubic")
#nowe=np.linspace(7,19,num=100,endpoint=True)
#print(interpolacja)
print(interpolacja(c))
#plt.plot(x,y,'o',c,interpolacja(c),'o',nowe,interpolacja(nowe),'--')
#plt.show()











































from matplotlib.pyplot import imread,imsave
from scipy import ndimage

# A = imread('python.png')
# A = A*3
# A[A>1] = 1
# imsave('python2.png',A)

from scipy.optimize import minimize

# x^2+y^2, pkt pocz: [-10,8], tol=10^(-5)
# def f(x):
#     x1,x2 = x
#     return x1**2+x2**2

# x0 = [-10,8]
# eps = 1e-5
# res = minimize(f,x0,tol=eps,method = 'Nelder-Mead')
# print(res.x,res.fun)

# x^2-y^2+5x+y; x+y>=2 x,y \in [-10,10] tol = 1e-5 pkt pocz: [-2,6]
# def f(x):
#     x1,x2 = x
#     return x1**2-x2**2+5*x1+x2
# def c1(x):
#     x1,x2 = x
#     return x1 + x2 - 2
# con1 = {'type': 'ineq', 'fun': c1}
# con  = [con1]

# b1 = [-10,10]
# b2 = [-10,10]
# b = [b1,b2]

# x0 = [-2,6]
# eps = 1e-5
# res = minimize(f,x0,tol=eps,method = 'SLSQP',bounds = b,constraints= con)
# print(res)

from scipy import integrate
# # -x^2+7 [-5,5]
# # def f(x):
# #     return -x**2+7

# # res = integrate.quad(f,-5,5)
# # print(res)


# # x^2 +y^2, x,y \in [-10,10]
# def f(x,y):
#     return x**2 + y**2

# res = integrate.nquad(f,[[-10,10],[-10,10]])
# print(res)
from scipy import interpolate

# t = [1,3,6,7,8,10]
# w = [0.1,0.7,0.8,0.4,0.3,0.1]
# f = interpolate.interp1d(t,w,kind = 'cubic')
# print(f(4.5))

#Zadanie 1
# A = imread('logo.png')
# #A[A>1] = 1
# A = 1-A
# imsave('logoN.png',A)
#Zadanie 2




#Zadanie 4
#(x1 + 2x2 − 7)2 + (2x1 + x2 − 5)2, x0 = [−10,−10], tol = 1e − 6,
# def f(x):
#     x1,x2 = x
#     return (x1+2*x2-7)**2 + (2*x1+x2-5)**2

# x0 = [-10,-10]
# eps = 1e-6
# res = minimize(f,x0,tol=eps,method = 'Nelder-Mead')
# print(res.x,res.fun)
#import numpy as np
#def f(x):
#    x1,x2 = x
#    return 0.5+((np.sin(x1**2-x2**2)**2-0.5))/(1+0.001*(x1**2+x2**2))**2
#x0=[-5,5]
#eps=1e-6
#res = minimize(f,x0,tol=eps,method= 'Nelder-Mead')
#print(res.x)






#Zadanie 5
# def f5(x):
#     x1,x2 = x
#     return x1-3*x2+2

# def c1(x):
#     x1,x2 = x
#     return 2*x1 + x2 - 6
# con1 = {'type': 'ineq', 'fun': c1}
# def c2(x):
#     x1,x2 = x
#     return -1*x1+x2-1
# con2 = {'type': 'ineq', 'fun': c2}
# con = [con1,con2]

# b1 = [2,10]
# b2 = [1,8]
# b = [b1,b2]

# x0 = [1,2]
# res = minimize(f5,x0,method = 'SLSQP',bounds = b,constraints= con)
# print("Zadanie 5 ", res.x,res.fun,res.nit)

import math as m
#Zadanie 6
# def f_1(x,y):
#     return m.exp(x+2*y)
# def f_2(x,y):
#     return x+x*y**2

# def f_3(x,y):
#     return x*m.sin(x)+6*y**2

# int1 = integrate.nquad(f_1,[[0,1],[0,1]])
# int2 = integrate.nquad(f_2,[[2,3],[0,2]])
# int3 = integrate.nquad(f_1,[[0,m.pi],[0,2]])
# print("Całka 1: ", int1[0],'\n',"Całka 2: ", int2[0],'\n',"Całka 3: ", int3[0],'\n')


#Zadanie 7
#f(x) = −x4 + 4x3 + 2x2 + 8
# import numpy
# def f(x):
#     return (-1)*x**4+4*x**3+2*x**2+8
# x = numpy.array([-1,0,1,2,3,4])
# i_quad = integrate.quad(f,-1,4)
# i_trap= integrate.trapz(f(x),x)
# i_par= integrate.simps(f(x),x)
# print("Całka quad: ", i_quad[0],'\n',"Całka trapezami: ",i_trap,'\n',"Całka parabolami: ", i_par,'\n')
# err_1 = abs(i_quad[0] - i_trap) / abs(i_quad[0])
# err_2 = abs(i_quad[0] - i_par) / abs(i_quad[0])
# print(err_1,err_2)

#Zadanie 8
# from scipy import interpolate
# a = [7,10,11,15,19]
# b = [7,12,13,15,13]
# f = interpolate.interp1d(a,b,kind='cubic')
# print(f([9.75,12.1,17]))