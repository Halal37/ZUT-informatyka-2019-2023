import matplotlib.pyplot as plt
import math
import numpy as np
import matplotlib.cm as cm
#x=np.arange(-math.pi,math.pi,2*math.pi/128)
#def funcos(x,*args):
#     y=[0]*len(x)
#     dana=0
#     for i in x:
#         y[dana]=math.cos(i)
#         dana+=1
#     return y
#def funsing(x,*args):
#     y=[0]*len(x)
#     dana=0
#     for i in x:
#         y[dana]=math.copysign(1,i)
#         dana+=1
#     return y
#print(len(x))
#print(len(funcos(x)))

#plt.plot(x,funcos(x),color='black',label='cos(x)')
#plt.plot(x,funsing(x),color='red',label='sign(x)')
#plt.legend()
#plt.xticks([-math.pi,-math.pi/2,0,math.pi/2,math.pi])
#plt.yticks([-1,0,1])
#plt.savefig('C:\\Lab11\\plot.png')
#plt.show()


#zad2
#x=np.linspace(-5,5)
#y=np.linspace(-5,5)
#X,Y=np.meshgrid(x,y)
#def funkcja(x,y):
#    return np.sin(x)*np.cos(y-1)
#Z=funkcja(X,Y)
#fig=plt.figure()
#ax = fig.gca(projection='3d')
#surf=ax.plot_surface(X,Y,Z,cmap=cm.coolwarm,linewidth=0)
#ax.set_xlabel("X")
#ax.set_ylabel("Y")
#ax.set_zlabel("Z")
#plt.show()


#zad3?
#x=np.linspace(-np.pi,np.pi,128)
#plt.subplot(2,1,1)
#plt.plot(x,np.cos(5*x))
#plt.subplot(2,1,2)
#plt.plot(x,np.sin(10*x))
#plt.show()


#zad4?
#X=np.random.rand(100)
#Y=np.random.rand(100)
#C=np.random.randint(0,2,100)
#plt.scatter(X,Y,c=C,s=50,cmap='autumn')
#plt.show()


#zad6
#X=list(range(0,12,1))
#Y=np.random.normal(0,12,12)
#c=min(Y)
#print(c)
#plt.bar(X,Y,color='red',edgecolor='black')
#for i in range(0,12):
# if(Y[i]>0):
#    plt.text(x=X[i]-1,y=-2,s=Y[i])
# else:
#     plt.text(x=X[i]-1,y=Y[i]-2,s=Y[i])
#plt.show()

#zad7
#x=np.linspace(-2,2,256)
#y=np.linspace(-2,2,256)
#X,Y=np.meshgrid(x,y)
#Z=-y**3+ 2*X + Y**2 + X**2-1
#C=plt.contour(X,Y,Z,16,color='black',linewidth=0.4)
#plt.clabel(C,fontsize=7)

#plt.contourf(X,Y,Z,16,alpha=0.9,cmap=cm.hot)
#plt.show()

#plt.savefig('konturowy.png',dpi=480)
#plt.show()
#zad8
c=np.loadtxt("C:\Lab11\pie.txt",dtype=str,comments='#',delimiter=";")
print(c[0][0])
print(c[0][1])
x=c[:,0]
y=c[:,1]
for i, j in c:
    b=i
#x=np.arange(1,7)
#y=np.random.randint(10,30,6)
plt.pie(y,labels=x,shadow=True,explode=[0,0,0,0,0.1,0.2])
plt.show()


#x=np.loadtxt("C:\Lab11\pie.txt",dtype=str,comments='#',delimiter=";")


#zad3

#def funsin(x,*args):
#     y=[0]*len(x)
#     dana=0
#     for i in x:
#         y[dana]=math.sin(i)
#         dana+=1
#     return y
#def funcos(x,*args):
#     y=[0]*len(x)
#     dana=0
#     for i in x:
#         y[dana]=math.cos(i)
#         dana+=1
#     return y
#dane=np.linspace(-math.pi,math.pi,128)
#dane2=dane*10
##sinus=np.sin(dane2)
#cosinus=np.cos(5*dane)
#print(dane)
#print(dane2)
##plt.subplot(311)
#plt.plot(dane,cosinus,color='black',label='cos(x)')
#plt.subplot(312)

#plt.subplot(311)
#plt.axes([dane,funcos(5*dane),0,1])
#plt.plot(dane,funcos(dane*5),color='blue',label='cos(5x)')
#plt.subplot(312)
#plt.plot(dane,funsin(dane2),color='red',label='sin(10x)')
#plt.legend()
#plt.axis([-3,3,-1,3])
#plt.show()
#zad4
#plt.scatter()


#zad5
#podloga=np.linspace(2,4.5,6)
#y=np.linspace(0,0,6)
#x=np.loadtxt("C:\Lab11\hist.txt",dtype=str,comments='#',delimiter=";")
#print(x)
#plt.hist(x[:,1],bins=9)
#plt.ylabel("Liczba ocen")
#plt.xlabel("oceny")
#plt.axis([2.0,5.0,0,7])
#plt.xticks(x[:,1],['2.0','2,5','3.0','3.5','4.0','4.5'])
#plt.plot(podloga,y)
#plt.show()


import matplotlib.pyplot as plt
import numpy as np
import math as m
#wykres 2d; y = x^2, x [-4,4]; y = abs(x)
"""
x = np.linspace(-4,4,50)

plt.subplot(1,2,1)
plt.plot(x, x**2, 'r*')
plt.title('pierwszy wykres')
plt.xlabel('Oś X')
plt.xlabel('Oś Y')

plt.subplot(1,2,2)
plt.plot(x, np.abs(x), 'b')
plt.title('drugi wykres')
plt.xlabel('Oś X')
plt.xlabel('Oś Y')
plt.show()
"""
#plt.figure()

#3d; x^2 + y^2, x [-5;5], y = [-7,7]

#from mpl_toolkits.mplot3d import Axes3D
#from matplotlib import cm
""" #wykres 3d
x = np.linspace(-5,5,50)
y = np.linspace(-7,7,50)

X, Y = np.meshgrid(x,y)

fig = plt.figure()
ax = fig.gca(projection = '3d')
ax.plot_surface(X,Y, X**2+Y**2, cmap = cm.coolwarm)
plt.show()
"""
""" #punkty
from matplotlib import cm
X = np.random.rand(100)
Y = np.random.rand(100)
C = np.random.randint(0,2,100)
plt.scatter(X, Y, 50, C, cmap = 'autumn')
plt.show()
"""
""" #histogram - slupki
x = np.random.randint(0,10,200)
plt.hist(x, bins = 10, color = 'blue', rwidth = 0.7)
plt.show()
"""
"""
#slupki
X = np.arange(1,7)
Y = np.random.rand(6)
plt.bar(X,Y, color = 'yellow', edgecolor = 'blue')
plt.show()
"""
""" 
#wykres kolowy
X = np.arange(1,7)
Y = np.random.randint(10,30,6)
plt.pie(Y, labels = X, shadow = True, explode=[0,0.1,0,0,0,0.3])
plt.show()
"""
"""
x = np.linspace(-5,5,128)
y = np.linspace(-5,5,128)

X, Y = np.meshgrid(x,y)
Z = X**2 + 2*X*Y - 0.5*Y**2
plt.contourf(X,Y,Z,levels = 16, alpha = 0.8, cmap = cm.hot)
C = plt.contour(X,Y,Z,levels = 16, colors = 'black', linewidths = 0.5)
plt.clabel(C, fontsize = 8)
plt.xticks([])
plt.yticks([])
plt.savefig('wykres.png', dpi = 1000)
plt.show()
"""

#1
"""
x = np.linspace(-(m.pi),m.pi,128)

plt.plot(x, np.cos(x), 'k',label="cos")
plt.plot(x, np.sin(x), 'r',label="sin")
plt.title('wykres')
plt.xlabel('Oś X')
plt.xlabel('Oś Y')
plt.xticks([-np.pi, -np.pi/2, 0, np.pi/2, np.pi],
[r'$-pi$', r'$-frac{​​pi}​​{​​2}​​$', 0, r'$+frac{​​pi}​​{​​2}​​$', r'$+pi$'])
plt.yticks([-1,0,1],[r'$-1$',r'$0$',r'$+1$'])
plt.legend(loc="upper left")
plt.savefig('plot.png', dpi = 1000)

plt.show()
"""

#2
"""
x = np.linspace(-5,5,50)
y = np.linspace(-5,5,50)

X, Y = np.meshgrid(x,y)

fig = plt.figure()
ax = fig.gca(projection = '3d')
ax.plot_surface(X,Y, np.sin(X)-np.cos(Y-1), cmap = cm.coolwarm)
plt.show()
"""
#3
"""
x = np.linspace(-(m.pi),m.pi,128)
plt.subplot(2,1,1)
plt.plot(x, np.cos(5*x))
"""
#4

#from matplotlib import cm
#X = np.random.rand(1024)
#Y = np.random.rand(1024)
#C = ( np.round(X) + np.round(Y))%2
#plt.scatter(X, Y, 7, C, cmap = cm.coolwarm)
#plt.show()