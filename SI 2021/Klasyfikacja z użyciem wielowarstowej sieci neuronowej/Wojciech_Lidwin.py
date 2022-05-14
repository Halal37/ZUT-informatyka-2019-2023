#Wojciech Lidwin 46577
from sklearn.datasets import fetch_openml
from sklearn.model_selection import train_test_split
import sklearn.utils
import math
import numpy as np
import random  
import matplotlib.pyplot as plt
#Wraz z kodem wyslalem obrazek, ktory mialem prawie caly czas w glowie podczas kazdego przeczytania o aktywowaniu neuronu
# 1 implementacja  sekcji nr 3
class MLP(object):
    def __init__(self,hidden=10,epochs=100,eta=0.1,shuffle=True,output=3,features_number=4):
        self.hidden=hidden
        self.epochs=epochs
        self.eta=eta
        self.shuffle=shuffle
        self.output = output
        self.features_number = features_number
        self.w_h=[[np.random.normal(0, 0.1, 1)[0] for i in range(self.hidden)] for j in range(self.features_number)] 
        self.w_o=[[np.random.normal(0, 0.1, 1)[0] for i in range(self.output)] for j in range(self.hidden)] 
        self.b_h=np.array([0 for i in range(self.hidden)])
        self.b_o=np.array([0 for i in range(self.output)])
    def _sigmoid(self,z):
        fi= 1/(1+np.exp(-z))
        return fi

    def _forward(self, X):
        o_h=np.dot(X,self.w_h)+self.b_h
        activation_h=self._sigmoid(o_h)
        o_o=np.dot(activation_h,self.w_o)+self.b_o
        activation_o=self._sigmoid(o_o)
        return activation_h, activation_o


    def _compute_cost(self,y,out):
        J=0
        cost=0

        for i in range(len(y)):
         cost+=J
         J=0
         for k in range(self.output):  
          J+=y[i][k]*np.log(out[i][k])+(1-y[i][k])*np.log(1-out[i][k])
        return -cost
    def fit(self, X_train, y_train):

        cost=[]
        accuracy=[]

        for i in range(self.epochs):
            if(self.shuffle==True):
              X_train,y_train=sklearn.utils.shuffle(X_train,y_train)

            a_h,a_o=self._forward(X_train)

            poch_o=a_o*(1-a_o)
            delta_o=(a_o-y_train)*poch_o
            poch_h=a_h*(1-a_h)
            delta_h=np.dot(delta_o,np.transpose(self.w_o))*poch_h

            grad_w_h=np.dot(np.transpose(X_train),delta_h)
            grad_b_h=delta_h
            grad_w_o=np.dot(np.transpose(a_h),delta_o)
            grad_b_o=delta_o

            self.w_h=self.w_h-(grad_w_h*self.eta)
            self.w_o=self.w_o-(grad_w_o*self.eta)
            self.b_h=self.b_h-(grad_b_h*self.eta)
            self.b_o=self.b_o-(grad_b_o*self.eta)

            cost.append(self._compute_cost(y_train,a_o))

            arg=self.predict(X_train)
            acc_sum=0
            for i in range(len(y_train)):
                if(np.argmax(y_train[i])==arg[i]):
                    acc_sum+=1
            result=acc_sum/len(y_train)*100
            accuracy.append(result)

        

        x_print=[]
        for i in range(self.epochs):
            x_print.append(i)

        plt.plot(x_print,cost)
        plt.xlabel("Krok")
        plt.ylabel("Funkcja kosztu")
        plt.show()

        plt.plot(x_print,accuracy)
        plt.xlabel("Krok")
        plt.ylabel("Dokladnosc")
        plt.show()

    def predict(self, X):
        a_h,a_o=self._forward(X)
        predicted=[]
        for i in range(len(a_o)):
          c=np.argmax(a_o[i])
          predicted.append(c)
        return predicted


#main

X_iris, y_iris = fetch_openml(name="iris", version=1, return_X_y=True)
y_iris_coded=[]
a=[1,0,0]
b=[0,1,0]
c=[0,0,1]
for i in y_iris:
    if(i=='Iris-setosa'):
        y_iris_coded.append(a)
    elif(i=='Iris-versicolor'):
       y_iris_coded.append(b)
    elif(i=='Iris-virginica'):
        y_iris_coded.append(c)
    else:
        pass

X_train, X_test, y_train, y_test =train_test_split(X_iris, y_iris_coded, random_state=13)

date=MLP(50,eta=0.01)
date.fit(X_train,y_train)


# 2 MLP do klasyfikacji binarnej

from sklearn.datasets import make_classification
N_X,N_Y=make_classification(100,10)

N_Y_coded=[]
a=[1,0]
b=[0,1]
for i in N_Y:
    if(i==1):
        N_Y_coded.append(a)
    elif(i==0):
       N_Y_coded.append(b)
    else:
        pass

X_train, X_test, y_train, y_test =train_test_split(N_X, N_Y_coded, random_state=13)
date=MLP(50,eta=0.01,output=2,features_number=10)
date.fit(X_train,y_train)