#Wojciech Lidwin grupa 334 indeks:46577
import numpy as np
from sklearn.base import BaseEstimator,ClassifierMixin
from matplotlib import pyplot as plt
from sklearn.datasets import make_classification

class Perceptron_delta(BaseEstimator,ClassifierMixin):
    def __init__(self):
        self.w=None 
        self.k=None 
    def check(self,X):

        s=np.dot(self.w,(X))
        if s>0.0: 
            return 1
        else: 
            return -1
    def fit(self,X,y,learning):

        label=np.ones(X.shape[0],dtype="int8")
        for i,val in enumerate(y):
            if(val==0):
                label[i]=-1
      
        self.k=0
        self.w=np.zeros(X.shape[1]+1)
        X=np.c_[np.ones(X.shape[0]),X]

        while True:
            error=[]
            for i in range(m):
                f=self.check(X[i])
                if not label[i] == f:
                    error.append(i)
                    break 
            if len(error)==0:
                break
            i=error[np.random.randint(len(error))]
            self.w=self.w + X[i] * learning * label[i] 
            self.k=self.k+1





def template(m,learning):
    print()
    X, y = make_classification(n_features=2, n_redundant=0, n_informative=2,
    n_clusters_per_class=1, n_classes=2, n_samples=m, class_sep = 2)
    clf=Perceptron_delta()
    clf.fit(X,y,learning)
    print(clf.w)
    print(clf.k)


m = 10
X, y = make_classification(n_features=2, n_redundant=0, n_informative=2,
n_clusters_per_class=1, n_classes=2, n_samples=m, class_sep = 2)
plt.scatter(X[:, 0], X[:, 1], marker='x', c=y, s=25, edgecolor='k')
plt.show()

clf=Perceptron_delta()
clf.fit(X,y,1.0)
print(clf.w)
print(clf.k)

for i in range(20,100,10):
    template(i,0.1)

print("Uczenia ")
for i in np.arange(0.05,1.0,0.05):
    template(20,i)