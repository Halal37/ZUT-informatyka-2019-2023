#Lab7 lw46577 
import sklearn.datasets as skd
import sklearn.neighbors
import numpy as np
from collections import Counter
import math
import matplotlib.pyplot as plt
from matplotlib.colors import ListedColormap
from sklearn.model_selection import train_test_split
from sklearn.metrics import mean_squared_error
from sklearn import neighbors
import pandas as pd
from sklearn.model_selection import KFold
from sklearn.decomposition import PCA
from sklearn.model_selection import LeaveOneOut
from sklearn.neighbors import KDTree

#Podpunkt 2 bez KDT

def distance(x1, x2):
        return np.sqrt(np.sum((x1 - x2)**2))
class KNN_k:
    def __init__(self, n_neighbors = 1, use_KDTree = False):
        self.n_neighbors=n_neighbors
        self.use_KDTree=use_KDTree
    def fit(self,X, y):
        self.X_t = X
        self.y_t = y

    def predict(self,X):
        dane=[self._predict(i) for i in X]
        return np.array(dane)

    def _predict(self, x):
        distances = [distance(x, i) for i in self.X_t]
        
        k_idx = np.argsort(distances)[:self.n_neighbors]
        
        k_neighbor_labels = [self.y_t[i] for i in k_idx]  
        
        most_common = Counter(k_neighbor_labels).most_common(1)
        return most_common[0][0]
    def score(self,X,y):
        print()
    def score(self, X, y):
        predictions = self.predict(X)
        return (predictions == y).sum() / len(y)*100

class KNN_r:
    def __init__(self, n_neighbors = 1, use_KDTree = False):
        self.n_neighbors=n_neighbors
        self.use_KDTree=use_KDTree
    def fit(self,X, y):
        self.X_t = X
        self.y_t = y

    def predict(self,X):
        dane=[self._predict(i) for i in X]
        return np.array(dane)

    def _predict(self, x):
          
        distances = []
    
        for i in range(self.X_t.shape[0]):
           distances.append(distance(self.X_t[i], x))
     
        distances = np.array(distances)
        inds = np.argsort(distances)
    
        distances = distances[inds]
        y_sorted = self.y_t[inds] 

        value = np.average(y_sorted[:self.n_neighbors])
        return value

    def score(self,X,y):
        print()
    def score(self, X, y):
        predictions = self.predict(X)
        return (mean_squared_error(y,predictions))*10
#3.1 Generowanie danych klasyfikacji
X,y=skd.make_classification(n_samples =100,
n_features =2,
n_informative =2,
n_redundant =0,
n_repeated =0,
random_state=3)
#3.2 Klasyfikacja knn
A=KNN_k(1)
A.fit(X,y)
pr=A.predict(X)

klas=A.score(y,pr)
print(klas)
#Taki procent: 100.0
print()
 
#4.3 Wizualizacja danych

cmap_light = ListedColormap(['#FFAAAA', '#AAFFAA', '#AAAAFF'])
cmap_bold = ListedColormap(['#FF0000', '#00FF00', '#0000FF'])

h = 0.02
x_min, x_max = X[:, 0].min() - 1, X[:, 0].max() + 1
y_min, y_max = X[:, 1].min() - 1, X[:, 1].max() + 1
xx, yy = np.meshgrid(np.arange(x_min, x_max, h),
                         np.arange(y_min, y_max, h))
Z=A.predict(np.c_[xx.ravel(), yy.ravel()])

Z = Z.reshape(xx.shape)
plt.figure()
plt.pcolormesh(xx, yy, Z, cmap=cmap_light)


plt.scatter(X[:, 0], X[:, 1], c=y, cmap=cmap_bold)
plt.xlim(xx.min(), xx.max())
plt.ylim(yy.min(), yy.max())


plt.show()






#3.4 Wczytanie danych iris
iris = skd.load_iris()
vis_d=iris.data
vis_t=iris.target
X_train, X_test, y_train, y_test = train_test_split(iris.data, iris.target, random_state = 40, test_size = 0.2)

#3.5 Wizualizacja i realizacja knn dla iris uzywajac PCA
X,y=skd.make_classification(n_samples =100,
n_features =2,
n_informative =2,
n_redundant =0,
n_repeated =0,
random_state=3)
B=KNN_k(2)
B.fit(X_train,y_train)
pr=B.predict(X_test)
klasa=B.score(y_test,pr)
print(klasa)
#Taki procent: 26.666666666666668
print()



pca=PCA(n_components=2)
pca.fit(vis_d)
New_X=pca.transform(vis_d)
h=0.02
x_min, x_max = New_X[:, 0].min() - 1, New_X[:, 0].max() + 1
y_min, y_max = New_X[:, 1].min() - 1, New_X[:, 1].max() + 1
xx, yy = np.meshgrid(np.arange(x_min, x_max, h),
                         np.arange(y_min, y_max, h))
p=np.vstack((xx.flatten(),yy.flatten())).transpose()
p2=pca.inverse_transform(p)
Z=B.predict(p2)
Z=Z.reshape(xx.shape)
plt.figure()
plt.pcolormesh(xx, yy, Z, cmap=cmap_light)



for i in set(vis_t):
    x_pca=[New_X[x,0] for x in range(len(vis_t))]
    y_pca=[New_X[x,1] for x in range(len(vis_t))]
    plt.scatter(x_pca, y_pca, c=vis_t, cmap=cmap_bold)
plt.show()


#3.6 Kroswalidacja leaye-one-out
from sklearn.model_selection import LeaveOneOut



for K in range(1,10):
 scores=[]
 loo = LeaveOneOut()
 for train, test in loo.split(X):
    model =KNN_k(K)
    model.fit(X[train], y[train])  #fit the model
    pred=model.predict(X[test])
    error =model.score(y[test],pred)
    scores.append(error)
 print("To jest liczba sasiadow i jego średnia",K,np.mean(scores))
#To jest liczba sasiadow i jego średnia 1 80.0
#To jest liczba sasiadow i jego średnia 2 80.0
#To jest liczba sasiadow i jego średnia 3 85.0
#To jest liczba sasiadow i jego średnia 4 83.0
#To jest liczba sasiadow i jego średnia 5 81.0
#To jest liczba sasiadow i jego średnia 6 82.0
#To jest liczba sasiadow i jego średnia 7 85.0
#To jest liczba sasiadow i jego średnia 8 85.0
#To jest liczba sasiadow i jego średnia 9 85.0
print()

#4.1 Genracja danych do regresji
X,y=skd.make_regression(n_samples =100,
n_features =2,
n_informative =2,
random_state=3
)
#4.2 Regresja knn
C=KNN_r(4)
C.fit(X,y)
pr=C.predict(X)


klas=C.score(y,pr)
print(klas)
#4690.046101439841
print()
#4.3 Wizualizacja i trend

model = KNN_r(2)

model.fit(X, y)  
pred=model.predict(X) 
error =model.score(X,y) 

h = 0.02
x_min, x_max = X[:, 0].min() - 1, X[:, 0].max() + 1
y_min, y_max = X[:, 1].min() - 1, X[:, 1].max() + 1
xx, yy = np.meshgrid(np.arange(x_min, x_max, h),
                         np.arange(y_min, y_max, h))
Z=model.predict(np.c_[xx.ravel(), yy.ravel()])

Z = Z.reshape(xx.shape)
plt.figure()
plt.pcolormesh(xx, yy, Z, cmap=cmap_light)


plt.scatter(X[:, 0], X[:, 1], c=y, cmap=cmap_bold)
plt.xlim(xx.min(), xx.max())
plt.ylim(yy.min(), yy.max())


plt.show()

scores = [] 
for K in range(20):
    K = K+1
    model = KNN_r(K)

    model.fit(X_train, y_train)  
    pred=model.predict(X_test) 
    error =model.score(X_test,y_test) 
    scores.append(error) 



prin = pd.DataFrame(scores) 
print(prin)
#           0
#0   0.000000
#1   0.000000
#2   0.074074
#3   0.062500
#4   0.080000
#5   0.111111
#6   0.115646
#7   0.114583
#8   0.127572
#9   0.163333
#10  0.190083
#11  0.199074
#12  0.179487
#13  0.159864
#14  0.139259
#15  0.165365
#16  0.169550
#17  0.192387
#18  0.201293
#19  0.197500
plt.plot(prin)
plt.show()

#4.4 wczytanie boston
boston=skd.load_boston()
x=boston.data[:,:]
y_b=boston.target
X_train,X_test,y_train,y_test=train_test_split(x,y_b,test_size=0.30,random_state=100)




#4.5 Proba 10 krotnej walidacji krzyzowej
scores=[]
kfold=KFold(n_splits=10,shuffle=True,random_state=3)
for K in range(1,10):
 for train,test in kfold.split(X_test):
  model = KNN_r(K)
  model.fit(X_train[train], y_train[test])  #fit the model
  pred=model.predict(X_test[test])
  error =model.score(y_test[test],pred)
  scores.append(error)
 print(scores.mean())