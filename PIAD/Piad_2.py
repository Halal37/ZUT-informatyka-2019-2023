#Wojciech Lidwin 221A lw46577
import pandas as pd
import numpy as np
import scipy.stats as sc
import matplotlib.pyplot as plt
#Zad2 podpunkt 1
print("Zad2 podpunkt 1")
zad2_1=pd.DataFrame(np.array([[0.720184489,0.657752214, 0.297794824],[0.775572034,0.532276741,0.051391112],[ 0.346071872, 0.22057064, 0.640917109],[ 0.475104139, 0.228407696,0.507173083],[ 0.475104139,0.899298837, 0.541077542]]),columns=['A','B','C'],index=['2020-03-01','2020-03-02','2020-03-03','2020-03-04','2020-03-05']).rename_axis('data')
print(zad2_1)
#                   A         B         C
#data
#2020-03-01  0.720184  0.657752  0.297795
#2020-03-02  0.775572  0.532277  0.051391
#2020-03-03  0.346072  0.220571  0.640917
#2020-03-04  0.475104  0.228408  0.507173
#2020-03-05  0.475104  0.899299  0.541078


#Zad2 podpunkt 2
print("Zad2 podpunkt 2")
zad2_2=pd.DataFrame(np.random.randint(1,100,(20,3)),columns=['A','B','C'],dtype=int).rename_axis('id')
print(zad2_2)
#     A   B   C
#id
#0   19  58  53
#1   58  17  15
#2   89  90  69
#3   41  80  15
#4   53   2  58
#5   58  10  21
#6   59  86  46
#7   52  66  28
#8   60   9  81
#9   72  84  29
#10  19  79  12
#11  38   3  31
#12   8  34  64
#13  57  17  93
#14  23  22  37
#15  85  20  37
#16  54  78  69
#17  96   6  23
#18  95  48  70
#19  63  32  74
print()
print(zad2_2[:][0:3])
#     A   B   C
#id
#0   19  58  53
#1   58  17  15
#2   89  90  69
print()
print(zad2_2[:][17:20])
#     A   B   C
#id
#17  96   6  23
#18  95  48  70
#19  63  32  74
print()
print(zad2_2.index.name)
#id
print()
print(zad2_2.columns)
#Index(['A', 'B', 'C'], dtype='object')
print()
print(zad2_2.to_string(header=False,index=False))
#19 58 53
#58 17 15
#89 90 69
#41 80 15
#53  2 58
#58 10 21
#59 86 46
#52 66 28
#60  9 81
#72 84 29
#19 79 12
#38  3 31
# 8 34 64
#57 17 93
#23 22 37
#85 20 37
#54 78 69
#96  6 23
#95 48 70
#63 32 74
print()
print(zad2_2.sample(n=5))
#     A   B   C
#id
#11  38   3  31
#18  95  48  70
#2   89  90  69
#9   72  84  29
#12   8  34  64
print()
print(zad2_2[['A']])
#     A
#id
#0   19
#1   58
#2   89
#3   41
#4   53
#5   58
#6   59
#7   52
#8   60
#9   72
#10  19
#11  38
#12   8
#13  57
#14  23
#15  85
#16  54
#17  96
#18  95
#19  63
print()
print(zad2_2[['A','B']])
#     A   B
#id
#0   19  58
#1   58  17
#2   89  90
#3   41  80
#4   53   2
#5   58  10
#6   59  86
#7   52  66
#8   60   9
#9   72  84
#10  19  79
#11  38   3
#12   8  34
#13  57  17
#14  23  22
#15  85  20
#16  54  78
#17  96   6
#18  95  48
#19  63  32
print()
print(zad2_2.iloc[0:3,0:2])
#     A   B
#id
#0   19  58
#1   58  17
#2   89  90
print()
print(zad2_2.iloc[[4]])
#     A  B   C
#id
#4   53  2  58
print()
print(zad2_2.iloc[[0,5,6,7],[0,1]])
#     A   B
#id
#0   19  58
#5   58  10
#6   59  86
#7   52  66


#Zad2 podpunkt 3
print("Zad2 podpunkt 3")
print()
zad2_3=pd.DataFrame(np.random.randint(-100,100,(20,3)),columns=['A','B','C'],dtype=int).rename_axis('id')
print(zad2_3.describe())
#              A          B           C
#count  20.00000  20.000000   20.000000
#mean   -5.05000 -12.650000  -15.000000
#std    63.32828  53.106918   60.205787
#min   -96.00000 -96.000000 -100.000000
#25%   -59.50000 -41.000000  -66.750000
#50%    -7.00000 -19.000000  -24.500000
#75%    58.75000  20.750000   32.250000
#max    94.00000  87.000000   98.000000
print()
print(zad2_3.describe()[zad2_3.describe()>0])
#              A          B          C
#count  20.00000  20.000000  20.000000
#mean        NaN        NaN        NaN
#std    63.32828  53.106918  60.205787
#min         NaN        NaN        NaN
#25%         NaN        NaN        NaN
#50%         NaN        NaN        NaN
#75%    58.75000  20.750000  32.250000
#max    94.00000  87.000000  98.000000
print()
print(zad2_3.A.describe()[zad2_3.A.describe()>0])
#count    20.00000
#std      63.32828
#75%      58.75000
#max      94.00000
#Name: A, dtype: float64
print()
print(zad2_3.describe().sum(axis=0))
#A    68.528280
#B    12.206918
#C     4.205787
#dtype: float64
print()
print(zad2_3.describe().sum(axis=1))
#count     60.000000
#mean     -32.700000
#std      176.640985
#min     -292.000000
#25%     -167.250000
#50%      -50.500000
#75%      111.750000
#max      279.000000
#dtype: float64
print()



#Zad2 podpunkt 4
print("Zad2 podpunkt 4")
print()
zad2_4_a=pd.DataFrame(np.random.randint(-100,100,(4,2)),columns=['A','B'],dtype=int).rename_axis('id')
zad2_4_b=pd.DataFrame(np.random.randint(-100,100,(4,2)),columns=['A','B'],dtype=int).rename_axis('id')
print(zad2_4_a)
#     A   B
#id
#0   65  82
#1    9  96
#2  -30  26
#3  -20  36
print()
print(zad2_4_b)
#     A   B
#id
#0  -81  30
#1  -42 -54
#2   52  97
#3  -36  87
print()
print(pd.concat([zad2_4_a,zad2_4_b],ignore_index=True))
#    A   B
#0  65  82
#1   9  96
#2 -30  26
#3 -20  36
#4 -81  30
#5 -42 -54
#6  52  97
#7 -36  87
z=pd.concat([zad2_4_a,zad2_4_b],ignore_index=True).transpose()
print()
print(z)
#    0   1   2   3   4   5   6   7
#A  65   9 -30 -20 -81 -42  52 -36
#B  82  96  26  36  30 -54  97  87
print()



#Zad2 podpunkt 5
print("Zad2 podpunkt 5")
df=pd.DataFrame(data={"x": [1,2,3,4,5], "y": ['a', 'b', 'a', 'b', 'b']}, index=np.arange(5)) 
df.index.name='id' 
print(df)
#    x  y
#id
#0   1  a
#1   2  b
#2   3  a
#3   4  b
#4   5  b
print()
print(df.sort_values('id'))
#    x  y
#id
#0   1  a
#1   2  b
#2   3  a
#3   4  b
#4   5  b
print()
print(df.sort_values('y',ascending=False))
#    x  y
#id
#1   2  b
#3   4  b
#4   5  b
#0   1  a
#2   3  a


#Zad2 podpunkt 6
print("Zad2 podpunkt 6")
slownik={'Day':['Mon','Tue','Mon','Tue','Mon'], 'Fruit':['Apple','Apple','Banana','Banana','Apple'], 'Pound':[10,15,50,40,5], 'Profit':[20,30,25,20,10]}
zad2_6=pd.DataFrame(slownik)
print(zad2_6)
#   Day   Fruit  Pound  Profit
#0  Mon   Apple     10      20
#1  Tue   Apple     15      30
#2  Mon  Banana     50      25
#3  Tue  Banana     40      20
#4  Mon   Apple      5      10
print(zad2_6.groupby('Day').sum())
#     Pound  Profit
#Day
#Mon     65      55
#Tue     55      50
#dokonuje zgrupowania takich samych wartości w 'Day'
print(zad2_6.groupby(['Day','Fruit']).sum())
#Day Fruit
#Mon Apple      15      30
#    Banana     50      25
#Tue Apple      15      30
#    Banana     40      20
#dokonuje zgrupowania wartości w 'Day', a następnie w 'Fruit'



#Zad2 podpunkt 7
print("Zad2 podpunkt 7")
df=pd.DataFrame(np.random.randn(20, 3), index=np.arange(20), columns=['A','B','C'])
df.index.name='id'
print(df)
df['B']=1 #zamienia wartosci dla 'B' na jeden
print(df)
df.iloc[1,2]=10 # dla wartości drugiego rzędu w trzeciej kolumnie dokonywana jest podmiana na 10
print(df)
df[df<0]=-df #gdy wartość jest mniejsza od zera to zamiania ją na liczbę dodatnią 
print(df)
#Zad2 podpunkt 8
print("Zad2 podpunkt 8")


df.iloc[[0, 3], 1] = np.nan #zmienia 1 i 4 wiersz 2 kolumny na wartość nan
print(df)
df.fillna(0, inplace=True) # zamiania wartosci nan na zera
print(df)
df.iloc[[0, 3], 1] = np.nan #zmienia 1 i 4 wiersz 2 kolumny na wartość nan
df=df.replace(to_replace=np.nan,value=-9999) #zamienia wartosci nan na -9999
print(df)
df.iloc[[0, 3], 1] = np.nan #zmienia 1 i 4 wiersz 2 kolumny na wartość nan
print(pd.isnull(df))#wyświetla odpowiednio true dla wartości nan i false dla innych wartości 

#PUNKT 3:
#zad1
df=pd.DataFrame(data={"x": [1,2,3,4,5], "y": ['a', 'b', 'a', 'b', 'b']})
print()
print(df.groupby(['y']).mean())
#          x
#y
#a  2.000000
#b  3.666667

#zad2
print()
print(df.value_counts('y'))
#y
#b    3
#a    2
#dtype: int64
print()
print(df.value_counts('x'))
#x
#1    1
#2    1
#3    1
#4    1
#5    1
#dtype: int64
print()
print(df.value_counts())
#x  y
#1  a    1
#2  b    1
#3  a    1
#4  b    1
#5  b    1
#dtype: int64

#zad3
print()
data=np.loadtxt("./autos.csv",dtype=str,delimiter=',') #muszę wpisywać pełną ścieżkę gdyż ./ nie działa przy użyciu visual code
print(data)
#[['' 'normalized-losses' 'make' ... 'highway-mpg' 'price' 'symboling']
# ['0' '' 'alfa-romero' ... '27.0' '13495.0' '3']
# ['1' '' 'alfa-romero' ... '27.0' '16500.0' '3']
# ...
# ['202' '95.0' 'volvo' ... '23.0' '21485.0' '-1']
# ['203' '95.0' 'volvo' ... '27.0' '22470.0' '-1']
# ['204' '95.0' 'volvo' ... '25.0' '22625.0' '-1']]

print()
data=pd.read_csv("./autos.csv") #pandas lepiej wczytuje pliki i nadaje im od razu prawidłowy typ
print(data)
#     Unnamed: 0  normalized-losses  ...    price symboling
#0             0                NaN  ...  13495.0         3
#1             1                NaN  ...  16500.0         3
#2             2                NaN  ...  16500.0         1
#3             3              164.0  ...  13950.0         2
#4             4              164.0  ...  17450.0         2
#..          ...                ...  ...      ...       ...
#200         200               95.0  ...  16845.0        -1
#201         201               95.0  ...  19045.0        -1
#202         202               95.0  ...  21485.0        -1
#203         203               95.0  ...  22470.0        -1
#204         204               95.0  ...  22625.0        -1

#[205 rows x 27 columns]

#zad4
print()
print(data.groupby("make")["city-mpg"].mean())
#make
#alfa-romero      20.333333
#audi             18.857143
#bmw              19.375000
#chevrolet        41.000000
#dodge            28.000000
#honda            30.384615
#isuzu            31.000000
#jaguar           14.333333
#mazda            25.705882
#mercedes-benz    18.500000
#mercury          19.000000
#mitsubishi       24.923077
#nissan           27.000000
#peugot           22.454545
#plymouth         28.142857
#porsche          17.400000
#renault          23.000000
#saa              20.333333
#subaru           26.333333
#toyota           27.500000
#volkswagen       28.583333
#volvo            21.181818
#Name: city-mpg, dtype: float64

#zad5
print()
print(data.groupby("make")["fuel-type"].count())
#make
#alfa-romero       3
#audi              7
#bmw               8
#chevrolet         3
#dodge             9
#honda            13
#isuzu             4
#jaguar            3
#mazda            17
#mercedes-benz     8
#mercury           1
#mitsubishi       13
#nissan           18
#peugot           11
#plymouth          7
#porsche           5
#renault           2
#saa               6
#subaru           12
#toyota           32
#volkswagen       12
#volvo            11
#Name: fuel-type, dtype: int64
print()

#zad6
print(np.polyfit(data['length'],data['city-mpg'],1))
#[-0.35576533 87.14020723]
print(np.polyfit(data['length'],data['city-mpg'],2))
#[ 4.39610791e-03 -1.89441985e+00  2.21104093e+02]
print()


#zad7
print(sc.pearsonr(data['length'],data['city-mpg'])) #pierwsza zmienna
#(-0.6709086615585712, 3.5955288422259193e-28)

#zad8

m,b=np.polyfit(data['length'],data['city-mpg'],1)
plt.style.use('ggplot')
plt.plot(data['length'],data['city-mpg'],'bo',label="Punkty")
plt.plot(data['length'], m * data['length']+b, label="Linia regresji")
plt.legend()
plt.show()

#zad9
print()
x=np.linspace(0,data['length'].size,data['length'].size)
dane=sc.gaussian_kde(data['length'])
dane=dane(x)

plt.plot(x,dane,'b',label="Funkcja gestosci")
plt.plot(data['length'], np.full_like(data['length'], -0.01), '|k', markeredgewidth=1,label="Probki")
plt.legend()
plt.show()

#lub

plt.hist(data['length'],label="Funkcja gestosci")
plt.plot(data['length'], np.full_like(data['length'], -0.01), '|k', markeredgewidth=1,label="Probki")
plt.legend()
plt.show()

#zad10


y=np.linspace(0,data['width'].size,data['width'].size)
dane2=sc.gaussian_kde(data['width'])
dane2=dane2(y)
fig, ax=plt.subplots(1,2, figsize=(5, 5))

ax[0].plot(x,dane,'b',label="Funkcja gestosci dlugosci")
ax[0].plot(data['length'], np.full_like(data['length'], -0.01), '|k', markeredgewidth=1,label="Probki")
ax[0].legend()

ax[1].plot(y,dane2,'g',label="Funkcja gestosci szerokosci")
ax[1].plot(data['width'], np.full_like(data['width'], -0.01), '|k', markeredgewidth=1,label="Probki")
ax[1].legend()

plt.show()

#zad11


xmin=np.min(data['length'])
xmax=np.max(data['length'])

ymin=np.min(data['width'])
ymax=np.max(data['width'])


X11, Y11=np.meshgrid(np.arange(xmin, xmax), np.arange(ymin, ymax))
position=np.vstack([X11.ravel(), Y11.ravel()])

kernel11=sc.gaussian_kde(np.vstack([data['length'], data['width']]))
Z11=np.reshape(kernel11(position).T, X11.shape)

ax1 = plt.contour(X11, Y11, Z11,cmap='jet')
plt.plot(data['length'], data['width'], '|k', label='Probki')
plt.colorbar(ax1)
plt.legend()
plt.savefig('obrazek.png')
plt.savefig('obrazek.pdf')
plt.show()