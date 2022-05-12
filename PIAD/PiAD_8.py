#lw46577 
import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.preprocessing import StandardScaler
#import scipy.spatial.distance

#1a)
#Funkcja distp liczaca odleglosc euklidesowa miedzy dwoma zbiorami punktow
def distp(X, C):
            distances=[]
            for featureset in X:
                distances.append([np.linalg.norm(featureset-centroid) for centroid in C])
            return distances

#1b)
#Funkcja distm liczaca odleglosc mahalanobisa miedzy dwoma zbiorami punktow
def distm(X=None, C=None,V=None):

    x_m = X - np.mean(C)
    V = np.cov(X.T)
    inv_covmat = np.linalg.inv(V)
    l = np.dot(x_m, inv_covmat)
    dist = np.dot(l, x_m.T)
    return dist


#1c)
#Funkcja ksrodki wyznaczajaca centra oraz sasiedztwa
def ksrodki(X,k):
    index = np.random.choice(len(X), k, replace=False)
    C = X[index,:]
    var = False
    P = []
    P_c = []
    C_c = []
    while True:
        if var and  np.array_equal(P_c,P) and np.array_equal(C_c,C):
            break
        else:  
            P_c = P.copy()
            C_c = C.copy()    
            dist = distp(X, C)
            P = np.argmin(dist, axis=1)
            for j in range(k):
                C[j] = X[P == j].mean(axis=0)
            var = True

    return [C, P]



#Przyklad dzialania algorytmu
center_1 = np.array([1,1])
center_2 = np.array([5,5])
center_3 = np.array([8,1])
data_1 = np.random.randn(200, 2) + center_1
data_2 = np.random.randn(200,2) + center_2
data_3 = np.random.randn(200,2) + center_3
data = np.concatenate((data_1, data_2, data_3), axis = 0)
k=3
C, CX = ksrodki(data, k)
plt.scatter(data[:,0], data[:,1], c=CX, cmap='plasma')
plt.scatter(C[:,0], C[:,1], marker="+", color="k", s=150, linewidths=5)
plt.show()

#2 Dodanie zbioru autos i stworzenie z niego danych X
Autos = pd.read_csv(".\\autos (1).csv")
x = Autos["compression-ratio"].to_numpy()
y = Autos["height"].to_numpy()
X = np.vstack((x, y)).T
sca = StandardScaler()
sca.fit(X)
sca.transform(X)
k=5
C, CX = ksrodki(X, k)

#3 wizualizacja danych
plt.scatter(X[:,0], X[:,1], c=CX, cmap='cividis')
plt.scatter(C[:,0], C[:,1], marker="+", color="k", s=150, linewidths=5)
plt.show()