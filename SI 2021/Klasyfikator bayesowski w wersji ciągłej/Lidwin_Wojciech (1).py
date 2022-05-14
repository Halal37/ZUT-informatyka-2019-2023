#Wojciech Lidwin gr:334 nr.indeksu:46577

import numpy as np
import sklearn.preprocessing
import sklearn.model_selection
import pandas as pd
import random
import warnings
import sympy as sp




class Bayes():
    def __init__(self,bins=5):
        self.n_cols=None
        self.class_=None
        self.mean_=None
        self.variance_=None
        self.probY_=None
        self.bins_=bins

    def fit(self,file):
        self.n_cols=len(file.columns)-1
        self.class_=file['type'].unique()
        self.n_class_=len(self.class_)
        m=file.groupby(by='type').apply(lambda x: x.mean(axis=0))
        self.mean_=m.values
        v=file.groupby(by='type').apply(lambda x: x.var(axis=0))
        self.variance_=v.values
        pp=file.groupby(by='type').apply(lambda x: len(x)+1/len(file)*self.n_cols/self.bins_) 
        self.probY_= np.log(pp).values


    def density(self,mean,variance,x):
     density=(1/np.sqrt(2*np.pi)*variance)*np.exp((-(x-mean)**2)/(2*variance))

     return density
    def predictproba(self,df_row):
     posterior_probabilities=[]
     for i in range(self.n_class_):

        posterior=0
        for j in range(self.n_cols):

         posterior+=np.log(self.density(self.mean_[i][j],self.variance_[i][j],df_row[j]))
  
        posterior_probabilities.append(posterior)
     return posterior_probabilities

    def predict(self,file):
     predictions=[]
     for i in range(len(file)):
        
        posterior=self.predictproba(file.iloc[i,:-1])
        
        probabilites=self.probY_+posterior
        mx_idx=np.argmax(probabilites)
        predictions.append(self.class_[mx_idx])
     return predictions


def read_wine_data(path):
    D = np.genfromtxt(path, delimiter=",")
    X = D[:, 1:]
    Y = D[:, 0]
    return X, Y
def train_test_split(df,test_size):
    if isinstance(test_size,float):
        test_size=round(test_size*len(df))
    indices=df.index.tolist()
    test_indices=random.sample(population=indices,k=test_size)
    test=df.loc[test_indices]
    train=df.drop(test_indices)
    return train,test
warnings.filterwarnings('ignore')




file=pd.read_csv("wine.data", names=["type","Alcohol","Malic acid", "Ash", "Alcalinity of ash ", "Magnesium", "Total phenols", "Flavanoids", "Nonflavanoid phenols", "Proanthocyanins", "Color intensity","Hue","OD280/OD315 of diluted wines","Proline"])
file_copy=file.copy()
train_df,test_df=train_test_split(file,0.75)





clf=Bayes()
clf.fit(train_df)
pre=clf.predict(test_df)

accuracy=len(test_df.loc[pre==test_df['type']])/len(test_df)
print("Wynik zbudowanego: ")
print("Accuracy:",accuracy)


X, Y = read_wine_data("wine.data")

X_train,X_test, Y_train, Y_test =sklearn.model_selection.train_test_split(X, Y,train_size=0.75)

#wbudowany
from sklearn.naive_bayes import GaussianNB
from sklearn import metrics
model=GaussianNB()
model.fit(X_train,Y_train)
pred=model.predict(X_test)
print("Wynik wbudowanego: ")
print("Accuracy:",metrics.accuracy_score(Y_test, pred))
