import numpy as np
from datetime import datetime, timedelta
import pandas as pd
import random
import collections
import scipy.stats as scist
import matplotlib.pyplot as plt
from sklearn.datasets import load_digits
from sklearn.decomposition import PCA
from matplotlib import cm
import math as m
from sklearn import datasets
from sklearn.naive_bayes import GaussianNB
from sklearn.discriminant_analysis import QuadraticDiscriminantAnalysis
from sklearn.neighbors import KNeighborsClassifier
from sklearn.svm import SVC
from sklearn.tree import DecisionTreeClassifier
from sklearn.model_selection import train_test_split
from sklearn.metrics import roc_curve
import sklearn as skd
import time
from sklearn.model_selection import GridSearchCV
#1

#1.1
x, y = datasets.make_classification(n_samples=400,n_classes=2,n_features=2,n_redundant=0,n_clusters_per_class=2)

#1.2
plt.scatter(x[:,0], x[:,1], c=y, cmap='viridis')
plt.show()

#1.3
klasyfikatory = [GaussianNB(), QuadraticDiscriminantAnalysis(), KNeighborsClassifier(), SVC(probability=True),DecisionTreeClassifier()]
ac_s=[[0]* 100 for i in range(5)]
rc_s=[[0]* 100 for i in range(5)]
pc_s=[[0]* 100 for i in range(5)]
f1_s=[[0]* 100 for i in range(5)]
ro_s=[[0]* 100 for i in range(5)]
time_tr=[[0]* 100 for i in range(5)]
time_l=[[0]* 100 for i in range(5)]
for i in range(5):


 for j in range(100):
    x_train, x_test, y_train, y_test = train_test_split(x,y)
 
    clf=klasyfikatory[i]
    t0 = time.time()
    clf.fit(x_train,y_train)
    t1 = time.time()
    time_tr[i][j]=t1-t0
    t2 = time.time()
    y_pred=clf.predict(x_test)
    t3 = time.time()
    time_l[i][j]=t3-t2
    ac_s[i][j]=skd.metrics.accuracy_score(y_test ,y_pred)
    rc_s[i][j]=skd.metrics.recall_score(y_test ,y_pred)
    pc_s[i][j]=skd.metrics.precision_score(y_test ,y_pred)
    f1_s[i][j]=skd.metrics.f1_score(y_test ,y_pred)
    ro_s[i][j]=skd.metrics.roc_auc_score(y_test ,y_pred)
    if(j==99):
        #rysunek 4
       fpr, tpr, thresholds = skd.metrics.roc_curve(y_test, y_pred)
       roc_auc = skd.metrics.roc_auc_score(y_test, y_pred)
       plt.figure()
       lw = 2
       plt.plot(fpr, tpr, color='darkorange',
         label="AUC="+str(roc_auc))
       plt.plot([0, 1], [0, 1], color='navy', lw=lw, linestyle='--')
       plt.xlim([0.0, 1.0])
       plt.ylim([0.0, 1.05])
       plt.legend(loc=4)
       plt.show()
       #rysunek 3
       fig, axs = plt.subplots(1, 3, figsize=(12,6))
       axs[0].set_title("oczekiwane")
       axs[0].scatter(x_test[:, 0], x_test[:, 1], c=y_test, s=9)
       axs[1].set_title("obliczone")
       axs[1].scatter(x_test[:, 0], x_test[:, 1], c=y_pred, s=9)
       colors = np.empty(len(y_test), dtype=str)
    
       for i in range(len(y_test)):
         if (y_test[i] != y_pred[i]):
             colors[i] = 'r'
         else:
             colors[i] = 'g'
    
       axs[2].set_title("różnice")
       axs[2].scatter(x_test[:, 0], x_test[:, 1], c=colors, s=9)
       plt.savefig('zad_1_3_blad_klasyfikacji_' + str("asdf") + '.png')
       plt.show()
       #rysunek 5
       x_min, x_max = x_test[:, 0].min() - 1, x_test[:, 0].max() + 1
       y_min, y_max = x_test[:, 1].min() - 1, x_test[:, 1].max() + 1
       xx, yy = np.meshgrid(np.arange(x_min, x_max, 0.1),
                          np.arange(y_min, y_max, 0.1))
    
       Z = clf.predict(np.c_[xx.ravel(), yy.ravel()])
       Z = Z.reshape(xx.shape)
    
       plt.contourf(xx, yy, Z, alpha=0.2)
       plt.scatter(x_test[:, 0], x_test[:, 1], c=y_pred,
                 s=20, alpha=0.5)
    
       plt.savefig('zad_1_3_discriminative_' + str("asdf") + '.png')
       plt.show()


print(ac_s)
resultac=[np.sum(x)/100 for x in ac_s]
resultrc=[np.sum(x)/100 for x in rc_s]
resultpc=[np.sum(x)/100 for x in pc_s]
resultf1=[np.sum(x)/100 for x in f1_s]
resultro=[np.sum(x)/100 for x in ro_s]
resulttt=[np.sum(x) for x in time_tr]
resulttl=[np.sum(x) for x in time_l]
lista=[]
lista.append(resultac)
lista.append(resultrc)
lista.append(resultpc)
lista.append(resultf1)
lista.append(resultro)
lista.append(resulttt)
lista.append(resulttl)
print(resultac)
print(lista)

data=pd.DataFrame(lista,index=["accuracy_score","recall_score","precision_score","f1_score","roc_auc","train_time","time_learning"],columns=["GaussianNB","QuadraticDiscriminantAnalysis","KNeighborsClassifier","SVC","DecisionTreeClassifier"])#,"train_time","time_learning"])

data.plot.bar()
plt.show()

'''
#2.1
x, y = datasets.make_classification(n_samples=400,n_classes=2,n_features=2,n_redundant=0)
#2.2
klasyfikator=SVC(probability=True)
#2.3
parametry={
   #'kernel': ('linear', 'poly', 'rbf', 'sigmoid'),
   #'gamma' :('scale', 'auto'),
   'C': [1,2,3,4,5,6,7,8,9,10],
   'degree': [0,1,2,3,4,5,6]
    }

from sklearn.metrics import make_scorer
from sklearn.metrics import accuracy_score
scoring = {'AUC': 'roc_auc', 'Accuracy': make_scorer(accuracy_score)}
clf=GridSearchCV(klasyfikator,parametry,scoring=scoring,refit='AUC', return_train_score=True)

clf.fit(x, y)
results = clf.cv_results_
print(results)
plt.figure(figsize=(13, 13))


plt.xlabel("parametry")
plt.ylabel("accuracy")

ax = plt.gca()

X_axis = np.array(results['param_C'].data, dtype=float)
Y_axis= np.array(results['param_degree'].data, dtype=float)
for scorer, color in zip(sorted(scoring), ['g', 'k']):
    for sample, style in (('train', '--'), ('test', '-')):
        sample_score_mean = results['mean_%s_%s' % (sample, scorer)]
        sample_score_std = results['std_%s_%s' % (sample, scorer)]

        if(scorer=='AUC' and sample=='test'):
            ax.plot(X_axis, sample_score_mean, style, color=color,
                alpha=1 if sample == 'test' else 0.7,
                label="%s (%s)" % (scorer, sample))

    best_index = np.nonzero(results['rank_test_%s' % scorer] == 1)[0][0]
    best_score = results['mean_test_%s' % scorer][best_index]


plt.grid(False)
plt.show()


ac_s=[]
rc_s=[]
pc_s=[]
f1_s=[]
ro_s=[]
time_tr=[]
time_l=[]
for j in range(100):
    x_train, x_test, y_train, y_test = train_test_split(x,y)
    t0 = time.time()
    clf.fit(x_train,y_train)
    t1 = time.time()
    time_tr.append(t1-t0)
    t2 = time.time()
    y_pred=clf.predict(x_test)
    t3 = time.time()
    time_l.append(t3-t2)
    ac_s.append(skd.metrics.accuracy_score(y_test ,y_pred))
    rc_s.append(skd.metrics.recall_score(y_test ,y_pred))
    pc_s.append(skd.metrics.precision_score(y_test ,y_pred))
    f1_s.append(skd.metrics.f1_score(y_test ,y_pred))
    ro_s.append(skd.metrics.roc_auc_score(y_test ,y_pred))
    if(j==99):
        #rysunek 4
       fpr, tpr, thresholds = skd.metrics.roc_curve(y_test, y_pred)
       roc_auc = skd.metrics.roc_auc_score(y_test, y_pred)
       plt.figure()
       lw = 2
       plt.plot(fpr, tpr, color='darkorange',
         label="AUC="+str(roc_auc))
       plt.plot([0, 1], [0, 1], color='navy', lw=lw, linestyle='--')
       plt.xlim([0.0, 1.0])
       plt.ylim([0.0, 1.05])
       plt.legend(loc=4)
       plt.show()
       #rysunek 3
       fig, axs = plt.subplots(1, 3, figsize=(12,6))
       axs[0].set_title("oczekiwane")
       axs[0].scatter(x_test[:, 0], x_test[:, 1], c=y_test, s=9)
       axs[1].set_title("obliczone")
       axs[1].scatter(x_test[:, 0], x_test[:, 1], c=y_pred, s=9)
       colors = np.empty(len(y_test), dtype=str)
    
       for i in range(len(y_test)):
         if (y_test[i] != y_pred[i]):
             colors[i] = 'r'
         else:
             colors[i] = 'g'
    
       axs[2].set_title("różnice")
       axs[2].scatter(x_test[:, 0], x_test[:, 1], c=colors, s=9)
       plt.savefig('zad_1_3_blad_klasyfikacji_' + str("asdf") + '.png')
       plt.show()
       #rysunek 5
       x_min, x_max = x_test[:, 0].min() - 1, x_test[:, 0].max() + 1
       y_min, y_max = x_test[:, 1].min() - 1, x_test[:, 1].max() + 1
       xx, yy = np.meshgrid(np.arange(x_min, x_max, 0.1),
                          np.arange(y_min, y_max, 0.1))
    
       Z = clf.predict(np.c_[xx.ravel(), yy.ravel()])
       Z = Z.reshape(xx.shape)
    
       plt.contourf(xx, yy, Z, alpha=0.2)
       plt.scatter(x_test[:, 0], x_test[:, 1], c=y_pred,
                 s=20, alpha=0.5)
    
       plt.savefig('zad_1_3_discriminative_' + str("asdf") + '.png')
       plt.show()

print(ac_s)
print(rc_s)
print(pc_s)
print(f1_s)
print(ro_s)
print(time_tr)
print(time_l)
resultac=np.sum(ac_s)/100 
resultrc=np.sum(rc_s)/100 
resultpc=np.sum(pc_s)/100 
resultf1=np.sum(f1_s)/100 
resultro=np.sum(ro_s)/100 
resulttt=np.sum(time_tr)/100
resulttl=np.sum(time_l)/100
lista=[]
lista.append(resultac)
lista.append(resultrc)
lista.append(resultpc)
lista.append(resultf1)
lista.append(resultro)
lista.append(resulttt)
lista.append(resulttl)
print(resultac)
print(lista)
data=pd.DataFrame(lista,index=["accuracy_score","recall_score","precision_score","f1_score","roc_auc","train_time","time_learning"],columns=["SVC"])
data.plot.bar()
plt.show()
'''