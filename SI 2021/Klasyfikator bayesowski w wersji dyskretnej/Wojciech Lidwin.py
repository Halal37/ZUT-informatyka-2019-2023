#Wojciech Lidwin 46577 grupa:334
import numpy as np
import sklearn.preprocessing
import sklearn.model_selection
from sklearn.base import BaseEstimator, ClassifierMixin
class Bayes_Discrete(BaseEstimator, ClassifierMixin):
    def __init__(self,domain_sizes,laplace=False,log=False):
        self.domain_sizes_=domain_sizes 
        self.laplace_=laplace
        self.log_=log
        self.class__=None
        self.ProbY__=None 
        self.Prob_=None 
    def fit(self,X,y):
        self.class__=np.unique(y)
        m,n=X.shape 
        K=self.class__.size
        self.ProbY__=np.zeros(K)
        for index, label in enumerate(self.class__):
            self.ProbY__[index]= np.sum(y==label)/m

        self.Prob_=np.ndarray((K,n),dtype="object")
        for y_index in range(K):
            for j in range(n):
                self.Prob_[y_index,j]=np.zeros(self.domain_sizes_[j])

        yy=np.zeros(m,dtype="int8")
        for y_index,label in enumerate(self.class__):
            yy[y==label]=y_index

        for i in range(m):
            x=X[i]
            for j in range(n):
                self.Prob_[yy[i],j][x[j]]+=1

        for y_index in range(K):
            if not self.laplace_:
                self.Prob_[y_index,:]/=self.ProbY__[y_index]*m
            else:
                self.Prob_[y_index,:]=(self.Prob_[y_index]+1)/(self.ProbY__[y_index]*m+self.domain_sizes_)

    def predict(self,X):
        return self.class__[np.argmax(self.predict_proba(X),axis=1)]
    def predict_proba(self,X):
        m,n = X.shape
        K=self.class__.size
        probas=np.zeros((m,K))
        for i in range(m):
            probas[i]=self.ProbY__
            for y in range(K):
                for j in range(n):
                    if not self.log_:
                     probas[i,y]*=self.Prob_[y,j][X[i,j]]
                    else:
                     probas[i,y]+=np.log(self.Prob_[y,j][X[i,j]]) 
        return probas


def discretize(X, bins=5, mins_ref=None, maxes_ref=None):
    if mins_ref is None:
        mins_ref = np.min(X, axis=0)
        maxes_ref = np.max(X, axis=0)
    X_d = np.clip(((X - mins_ref) / (maxes_ref - mins_ref) * bins).astype("int8"), 0, bins - 1)
    return X_d, mins_ref, maxes_ref

def read_wine_data(path):
    D = np.genfromtxt(path, delimiter=",")
    X = D[:, 1:]
    Y = D[:, 0]
    return X, Y


def read_abalone_data(path):
    D = np.genfromtxt(path, delimiter=",")
    X = D[:, :21]
    Y = D[:, -1]
    return X, Y





X, Y = read_wine_data("wine.data")

X_train,X_test, Y_train, Y_test =sklearn.model_selection.train_test_split(X, Y,train_size=0.75)

bins = 5

X_train_d, mins, maxes= discretize(X_train, bins)
X_test_d, _, _ = discretize(X_test, bins, mins, maxes)

size=X.shape[1]
domain_sizes=bins*np.ones(size,dtype="int8")
clf= Bayes_Discrete(domain_sizes)
clf.fit(X_train_d,Y_train)
clf.predict(X_test_d)

acc_train=clf.score(X_train_d,Y_train)
acc_test=clf.score(X_test_d,Y_test)
print("Wine bez laplace i logarytmu: ")
print("Dokladnosc Train: " + str(acc_train))
print("Dokladnosc Test: " + str(acc_test))

clf_l= Bayes_Discrete(domain_sizes,laplace=True)
clf_l.fit(X_train_d,Y_train)
clf_l.predict(X_test_d)

acc_train_l=clf_l.score(X_train_d,Y_train)
acc_test_l=clf_l.score(X_test_d,Y_test)
print("Wine z laplace i bez logarytmu: ")
print("Dokladnosc Train: " + str(acc_train_l))
print("Dokladnosc Test: " + str(acc_test_l))

clf_ll= Bayes_Discrete(domain_sizes,laplace=True,log=True)
clf_ll.fit(X_train_d,Y_train)
clf_ll.predict(X_test_d)

acc_train_ll=clf_ll.score(X_train_d,Y_train)
acc_test_ll=clf_ll.score(X_test_d,Y_test)
print("Wine z laplace i z logarytmem: ")
print("Dokladnosc Train: " + str(acc_train_ll))
print("Dokladnosc Test: " + str(acc_test_ll))

X2, Y2=read_abalone_data("waveform.data")

X2_train,X2_test, Y2_train, Y2_test =sklearn.model_selection.train_test_split(X2, Y2,train_size=0.95)
bins = 9

X2_train_d, mins2, maxes2 = discretize(X2_train, bins)
X2_test_d, _, _ = discretize(X2_test, bins, mins2, maxes2)

size2=X2.shape[1]
domain_sizes2=bins*np.ones(size2,dtype="int8")
clf2= Bayes_Discrete(domain_sizes2,laplace=True)
clf2.fit(X2_train_d,Y2_train)
clf2.predict(X2_test_d)

acc_train2=clf2.score(X2_train_d,Y2_train)
acc_test2=clf2.score(X2_test_d,Y2_test)
print("Inny zbior:")
print("Dokladnosc Train: " + str(acc_train2))
print("Dokladnosc Test: " + str(acc_test2))





