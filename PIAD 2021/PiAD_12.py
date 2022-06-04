import matplotlib.pyplot as plt
import numpy as np
from sklearn.datasets import make_classification
from sklearn.model_selection import train_test_split
from sklearn.multiclass import OneVsOneClassifier, OneVsRestClassifier
from sklearn.svm import SVC
from sklearn.linear_model import LogisticRegression, Perceptron
from sklearn.metrics import roc_curve, roc_auc_score, auc, accuracy_score, recall_score, precision_score, f1_score
import pandas as pd
from sklearn.preprocessing import LabelBinarizer

def multiclass_roc_auc_score(y_test, y_pred, average="macro",mc='ovo'):
    lb = LabelBinarizer()
    lb.fit(y_test)
    y_test = lb.transform(y_test)
    y_pred = lb.transform(y_pred)
    return roc_auc_score(y_test, y_pred, average=average,multi_class=mc)

def piad():
     X, Y = make_classification(n_samples=1500, n_classes=4, n_features=2, n_informative=2, n_redundant=0, n_clusters_per_class=1, random_state=0)
     X_train, X_test, y_train, y_test = train_test_split(X, Y, test_size=0.5, train_size=0.5)
     clf = []
     clf.append(OneVsOneClassifier(
         SVC(kernel="linear", probability=True)
      ))
     clf.append(OneVsRestClassifier(
         SVC(kernel="linear", probability=True)
      ))
     clf.append(OneVsOneClassifier(
         SVC(kernel="rbf", probability=True)
      ))
     clf.append(OneVsRestClassifier(
         SVC(kernel="rbf", probability=True)
      ))
     clf.append(OneVsOneClassifier(
        Perceptron()
     ))
     clf.append(OneVsRestClassifier(
        Perceptron()
     ))
     clf.append(OneVsOneClassifier(
        LogisticRegression()
     ))
     clf.append(OneVsRestClassifier(
        LogisticRegression()
     ))

     y_pred = []
     labels = [0, 1, 2, 3]
    
     for c in clf:
        c.fit(X_train, y_train)


        y_pred.append(c.predict(X_test))

    # y_pred2=label_binarize()
     #y_pred2.fit(y_test)
     #X_train2, X_test2, y_train2, y_test2 = train_test_split(X, y, test_size=0.5, train_size=0.5)
     accuracy_scores=[]
     recall_scores = []
     precision_scores = []
     f1_scores = []
     roc_auc_scores=[]


     for k in range(0, len(clf)):
        recall_scores.append(recall_score(y_test, y_pred[k], average="macro"))
        precision_scores.append(precision_score(y_test, y_pred[k], average="macro"))
        f1_scores.append(f1_score(y_test, y_pred[k], average="macro"))
        accuracy_scores.append(accuracy_score(y_test, y_pred[k]))
    #    if(k%2==0):
      #   roc_auc_scores.append(multiclass_roc_auc_score(y_test, y_pred,"macro",'ovo'))#roc_auc_score(y_test, y_pred2,average='macro',multi_class='ovo'))
     #   else:
      #   roc_auc_scores.append((y_test, y_pred,"macro",'oro'))#roc_auc_score(y_test, y_pred2,average='macro',multi_class='oro'))

     print("accuracy scores {}".format(accuracy_scores))
     print("Recall scores {}".format(recall_scores))
     print("Precisionl scores {}".format(precision_scores))
     print("f1 scores {}".format(f1_scores))
     
   #  print("roc auc scores {}".format(roc_auc_scores))
     x_min, x_max = X_test[:, 0].min() - 1, X_test[:, 0].max() + 1
     y_min, y_max = X_test[:, 1].min() - 1, X_test[:, 1].max() + 1
     xx, yy = np.meshgrid(np.arange(x_min, x_max, 0.1),
                         np.arange(y_min, y_max, 0.1))

     for k in range(0, len(clf)):
        Z = clf[k].predict(np.c_[xx.ravel(), yy.ravel()])
        Z = Z.reshape(xx.shape)

        plt.contourf(xx, yy, Z, alpha=0.2)
        plt.scatter(X_test[:, 0], X_test[:, 1], c=y_pred[k],
                    s=20, alpha=0.5)
        plt.savefig("wykres" + str(k) + ".png")
        plt.clf()
     for k in range(0, len(clf)):
         fig, axs = plt.subplots(1, 3, figsize=(12, 6))
         axs[0].set_title("oczekiwane")
         axs[0].scatter(X_test[:, 0], X_test[:, 1], c=y_test, s=5, cmap='plasma')
         axs[1].set_title("obliczone")
         axs[1].scatter(X_test[:, 0], X_test[:, 1], c=y_pred[k], s=5, cmap='plasma')
         colors = np.empty(len(y_test), dtype=str)
    
    
         for i in range(len(y_test)):
             if (y_test[i] != y_pred[k][i]):
                 colors[i] = 'r'
             else:
                 colors[i] = 'g'
    
         axs[2].set_title("różnice")
         axs[2].scatter(X_test[:, 0], X_test[:, 1], c=colors, s=9)
         plt.savefig('asdf' + str(k) + ".png")
     col=['red','darkorange','green','purple','red','darkorange','green']
     plt.savefig('asdf'  + ".png")
     for k in range(0, 4):
         fpr, tpr, thresholds = roc_curve(y_test, y_pred[k], pos_label=k)
         roc_auc = auc(fpr, tpr)
         plt.figure()
         lw = 2
         plt.plot(fpr, tpr, color=col[k],
                  label="AUC=" + str(roc_auc))
         plt.plot([0, 1], [0, 1], color='navy', lw=lw, linestyle='--')
         plt.xlim([0.0, 1.0])
         plt.ylim([0.0, 1.05])
         plt.legend(loc=4)
         plt.savefig("auc" + str(k) + ".png")


     lista=[]

     lista.append(accuracy_scores)
     lista.append(recall_scores)
     lista.append(precision_scores)
     lista.append(f1_scores)
     print(lista)
     #lista.append(roc_auc_scores)
     data=pd.DataFrame(lista,index=["accuracy_score","recall_score","precision_score","f1_score"],columns=["OVO==SVCl","OVR==SVCl","OVO==SVCr","OVR==SVCr","OVO==Perceptron","OVR==Perceptron","OVO==LogisticR","OVR==LogisticR"])
     data.plot.bar()
     plt.savefig("Wykresy" + ".png")
#if _name_ == '_main_':
piad()
