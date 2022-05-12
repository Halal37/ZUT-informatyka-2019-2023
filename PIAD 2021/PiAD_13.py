#Wojciech Lidwin 221A lw46577
from sklearn import datasets
from sklearn.cluster import AgglomerativeClustering as AC
from sklearn.decomposition import PCA
import numpy as np 
import pandas as pd
import matplotlib.pyplot as plt
import scipy
from sklearn.metrics import jaccard_score
from mpl_toolkits.mplot3d.axes3d import Axes3D
from scipy.spatial import ConvexHull, convex_hull_plot_2d
import scipy.cluster.hierarchy as shc
def find_perm(clusters, Y_real, Y_pred):
 perm=[]
 for i in range(clusters):
  idx = Y_pred == i
  new_label=scipy.stats.mode(Y_real[idx])[0][0]
  perm.append(new_label)
 return [perm[label] for label in Y_pred]

#2.1
#Wczytanie danych z iris i rozdzielenie ich na czesc wejsciowa i decyzje

iris=datasets.load_iris()
X=iris.data
Y=iris.target


#2.2
#Klasteryzacja za pomoca paru metod
clusters=[]
clusters.append(AC(n_clusters = 3,linkage='single').fit_predict(X))
clusters.append(AC(n_clusters = 3,linkage='average').fit_predict(X))
clusters.append(AC(n_clusters = 3,linkage='complete').fit_predict(X))
clusters.append(AC(n_clusters = 3,linkage='ward').fit_predict(X))

#1 opcja dziala na zasadzie minimalizacji odleglosci miedzy obserwacjami z dwoch zestawow
#2 opcja korzysta ze sredniej odleglosci obserwacji zestawow
#3 opcja wykorzystuje maksymalne odleglosci miedzy obserwacjami z dwoch zestawow
#4 opcja dokonuje minimalizacji wariancji klastrow


#2.3
#Dopasowanie rezultatu klasteryzacji do rzeczywistych klas decyzyjnych.
for i in range(len(clusters)):

    clusters[i]=find_perm(3,Y,clusters[i])


#2.4
#Obliczenie indeksu Jaccarda
jaccard_scores=[]

for i in range(len(clusters)):
    jaccard_scores.append(jaccard_score(Y,clusters[i], average='macro'))
print(jaccard_scores)

#Wynik powyzszych linii kodu:
#[0.516734693877551, 0.8337499999999999, 0.7335482138060704, 0.8133735545500252]
#Indeks Jaccarda jest to miara sluzaca po porwonywania podobienstwa dwoch zbiorow. 
##Gdy wynik jest rowny 1 zbiory sa identyczne, natomiast, gdy wynik to 0 mamy do czynienia z zupelnie roznymi zbiorami
#Wartosci znajdujace sie pomiedzy okreslaja nam czesciowe podobienstwo 
#Miara ta pozawala nam okreslic roznice miedzy wynikiem oryginalem, a uzyskanym rezultatem
#2.5
#Wizualizacja danych dla przestrzeni 2D
X_cp=X
X = PCA(n_components=2).fit_transform(X)




for i in range(len(clusters)):

 hull1 = ConvexHull(X[Y==0])
 hull2 = ConvexHull(X[Y==1])
 hull3 = ConvexHull(X[Y==2])

 Z=np.array(clusters[i])

 hull4 = ConvexHull(X[Z==0])
 hull5 = ConvexHull(X[Z==1])



 fig, axis = plt.subplots(1, 3, figsize=(12, 6))
 axis[0].set_title("Prawdziwe: ")
 axis[0].scatter(X[:, 0], X[:, 1], c=Y,cmap='cividis')

 for simplex in hull1.simplices:

     axis[0].plot(X[Y==0][simplex,0],X[Y==0][simplex,1],'k-')

 for simplex in hull2.simplices:

     axis[0].plot(X[Y==1][simplex,0],X[Y==1][simplex,1],'k-')

 for simplex in hull3.simplices:

     axis[0].plot(X[Y==2][simplex,0],X[Y==2][simplex,1],'k-')

 for simplex in hull4.simplices:

     axis[1].plot(X[[Z==0]][simplex,0],X[[Z==0]][simplex,1],'k-')

 for simplex in hull5.simplices:

     axis[1].plot(X[[Z==1]][simplex,0],X[[Z==1]][simplex,1],'k-')

 if(len(X[Z==2])>2):
  hull6 = ConvexHull(X[Z==2])
  for simplex in hull6.simplices:

     axis[1].plot(X[[Z==2]][simplex,0],X[[Z==2]][simplex,1],'k-')
 axis[1].set_title("Przewidenie: ")
 axis[1].scatter(X[:, 0], X[:, 1],c=clusters[i],cmap='cividis')
 colors=np.empty(len(Y), dtype=str)
 for j in range(len(Y)):
             if (Y[j] != clusters[i][j]):
                 colors[j] = 'r'
             else:
                 colors[j] = 'g'
 axis[2].set_title("Roznice: ")
 axis[2].scatter(X[:,0],X[:,1], c=colors)
 plt.savefig("2d" + str(i) + ".png")

#2.6
#Wizualizacja danych dla przestrzeni 3D
X=X_cp
X = PCA(n_components=3).fit_transform(X)


for i in range(len(clusters)):
 fig = plt.figure( figsize=(12, 6))
 ax= fig.add_subplot(1, 3, 1, projection='3d')
 ax.scatter(X[:, 0], X[:, 1], X[:, 2],c=Y,marker='o',cmap='cividis')
 ax.set_xlabel('0', fontsize= 20, alpha=0.6)
 ax.set_ylabel('1', fontsize= 20, alpha=0.6)
 ax.set_zlabel('2', fontsize= 20, alpha=0.6)
 ax= fig.add_subplot(1, 3, 2, projection='3d')
 ax.scatter(X[:, 0], X[:, 1], X[:, 2],c=clusters[i],marker='o',cmap='cividis')
 ax.set_xlabel('0', fontsize= 20, alpha=0.6)
 ax.set_ylabel('1', fontsize= 20, alpha=0.6)
 ax.set_zlabel('2', fontsize= 20, alpha=0.6)
 for j in range(len(Y)):
             if (Y[j] != clusters[i][j]):
                 colors[j] = 'r'
             else:
                 colors[j] = 'g'
 ax= fig.add_subplot(1, 3, 3, projection='3d')
 ax.scatter(X[:, 0], X[:, 1], X[:, 2],c=colors,marker='o')
 ax.set_xlabel('0', fontsize= 20, alpha=0.6)
 ax.set_ylabel('1', fontsize= 20, alpha=0.6)
 ax.set_zlabel('2', fontsize= 20, alpha=0.6)
 plt.savefig("3d" + str(i) + ".png")

type=['single','average','complete','ward']



#2.7
#Tworzenie wykresow dla dendrogramow
for i in type:
  fig = plt.figure( figsize=(12, 6))
  shc.dendrogram(shc.linkage(X, method=i))
  plt.savefig("Dendrogram "+ i + ".png")
