import PyQt5.QtWidgets as widok
import numpy as np
#zad1
def Guzik():
    print("Pierwszy program ")
napis="Witaj uzytkowniku"
prz="Przycisk"
app=widok.QApplication([])
window=widok.QWidget()
etykieta=widok.QLabel(napis)
przycisk=widok.QPushButton(prz)
przycisk.clicked.connect(Guzik)
uklad=widok.QVBoxLayout()
uklad.addWidget(etykieta)
uklad.addWidget(przycisk)
window.setLayout(uklad)
window.show()
app.exec_()

#zad2
from functools import partial
dana=""
def Funkcja_do_zad2(num):
    num
#    global dana
 #   dana=dana+str(num)
 #   equation.set(dana)
#kalkulator=widok.qapplication([])
#okno=widok.qwidget()
#ustawienie=widok.qgridlayout()
#okno.setlayout(ustawienie)
#nazwy=['c','<-','','znak','7','8','9','/','4','5','6','*','1','2','3','-','0','.','=','+']
#ulozenie= [(i, j) for i in range(5) for j in range(4)]
#for ulozenie, nazwy in zip(ulozenie,nazwy):
#    if nazwy=='':
#     continue
#    guzik=widok.qpushbutton(nazwy)
#    guzik.clicked.connect(funkcja_do_zad2(nazwy))
#    ustawienie.addwidget(guzik,*ulozenie)
    
#tablica=np.array()
#for i in range(0,10):
#    tablica[i]=widok.QPushButton(str(i))
#zero=widok.QPushButton('0')
#jeden=widok.QPushButton('1')
#dwa=widok.QPushButton('2')
#trzy=widok.QPushButton('3')
#cztery=widok.QPushButton('4')
#piec=widok.QPushButton('5')
#szesc=widok.QPushButton('6')
#siedem=widok.QPushButton('7')
#osiem=widok.QPushButton('8')
#dziewiec=widok.QPushButton('9')
#ustawienie=widok.QVBoxLayout()
#ustawienie.addWidget(zero,0,1)
#ustawienie.addWidget(jeden,0,2)
#ustawienie.addWidget(dwa,0,3)
#ustawienie.addWidget(trzy,1,1)
#ustawienie.addWidget(cztery,1,2)
#ustawienie.addWidget(piec,1,3)
#ustawienie.addWidget(szesc,2,1)
#ustawienie.addWidget(siedem,2,2)
#ustawienie.addWidget(osiem,2,3)
#ustawienie.addWidget(dziewiec,3,1)
#okno.setLayout(ustawienie)
#okno.setWindowTitle('Kalkulator')
#okno.show()
#kalkulator.exec_()

from PyQt5.QtCore import Qt
from PyQt5.QtWidgets import QGridLayout
from PyQt5.QtWidgets import QLineEdit
from PyQt5.QtWidgets import QPushButton
from PyQt5.QtWidgets import QApplication
from PyQt5.QtWidgets import QMainWindow
from PyQt5.QtWidgets import QWidget
from PyQt5.QtWidgets import QVBoxLayout

    
class Aplikacja(widok.QDialog):
    def __init__(self):
        super().__init__()
        self.app=widok.QApplication([])
        self.window=widok.QWidget()
        self.window.setFixedSize(300,100)
        self.layout=widok.QVBoxLayout()
        self.label=widok.QLabel("Wcisnij przycisk ")
        self.button=widok.QPushButton("Start")
        self.layout.addWidget(self.label)
        self.layout.addWidget(self.button)
        self.button.clicked.connect(self.click)
        self.window.setLayout(self.layout)
        self.window.show()
        self.app.exec_()
    def click(self):
         dialog=Dialog()
         dialog.exec_()
         if dialog.result()==1:
            wynik=int(dialog.lineEdit1.text())+int(dialog.lineEdit2.text())
            self.label.setText("Wynik: "+str(wynik))
class Dialog(widok.QDialog):
    def __init__(self):
        super().__init__()
        self.layout=widok.QHBoxLayout()
        self.label1=widok.QLabel("Liczby do dodania: ")
        self.lineEdit1=widok.QLineEdit()
        self.lineEdit2=widok.QLineEdit()
        self.button1=widok.QPushButton("Zatwierdz")
        self.button2=widok.QPushButton("Odrzuc")
        self.layout.addWidget(self.label1)
        self.layout.addWidget(self.lineEdit1)
        self.layout.addWidget(self.button1)
        self.layout.addWidget(self.lineEdit2)
        self.layout.addWidget(self.button2)
        self.button1.clicked.connect(self.accept)
        self.button2.clicked.connect(self.reject)
        self.setLayout(self.layout)
newApp=Aplikacja()
