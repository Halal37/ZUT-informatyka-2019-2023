import PyQt5.QtWidgets as widok
import PyQt5.QtCore as czas
class Swiatla():
    def __init__(self):
        super().__init__()
        self.app=widok.QApplication([])
        self.window=widok.QWidget()
        self.layout=widok.QVBoxLayout()
        self.label1=widok.QLabel("Swiatla: ")
        self.button1=widok.QPushButton(" ")
        self.button2=widok.QPushButton(" ")
        self.button3=widok.QPushButton(" ")
        self.button4=widok.QPushButton("Rozpocznij swiatla")
        self.button1.setObjectName("sButton1")
        self.button2.setObjectName("sButton2")
        self.button3.setObjectName("sButton3")
        self.button4.setObjectName("sButton4")
        self.layout.addWidget(self.label1)
        self.layout.addWidget(self.button4)
        self.layout.addWidget(self.button1)
        self.layout.addWidget(self.button2)
        self.layout.addWidget(self.button3)
        self.button4.clicked.connect(self.wyswietl)
        self.window.setLayout(self.layout)
        self.window.show()
        self.app.exec_()
    def wyswietl(self):
         timer=czas.QTimer()
         timer.singleShot(0,self.czerwone)
         timer.singleShot(5000,self.czerwono_zotle)
         timer.singleShot(7000,self.zielone)
         timer.singleShot(12000,self.zolte)
         timer.singleShot(14000,self.wyswietl)
    def zielone(self):
        self.button1.setStyleSheet("background-color: black")
        self.button2.setStyleSheet("background-color: black")
        self.button3.setStyleSheet("background-color: green")
    def czerwone(self):
        self.button1.setStyleSheet("background-color: red")
        self.button2.setStyleSheet("background-color: black")
        self.button3.setStyleSheet("background-color: black")
    def czerwono_zotle(self):
        self.button1.setStyleSheet("background-color: red")
        self.button2.setStyleSheet("background-color: yellow")
        self.button3.setStyleSheet("background-color: black")
    def zolte(self):
        self.button1.setStyleSheet("background-color: black")
        self.button2.setStyleSheet("background-color: yellow")
        self.button3.setStyleSheet("background-color: black")
newApp=Swiatla()

