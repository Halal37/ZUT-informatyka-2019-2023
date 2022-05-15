class Potega :
  def __init__(self,a=0,b=0):
    self.a=a
    self.b=b
  def __call__(self):
    self.b =self.b+1
    return self.a**self.b
pot=Potega(2)
for i in range(0,10):
   print(pot())
class Pot :
  def __init__(self,a=0,b=0,c=0):
    self.a=a
    self.b=b
    self.c=c
  def __iter__(self):
    return self
  def __next__(self):
      if self.b>self.c:
          raise StopIteration
      else:
          self.b+=1
          return self.a**self.b
for i in Pot(2,3,8):
    print(i)
class DList:
 def __init__(self):
     self.head=None
     self.tail=None
     return
 class Element:
     def __init__ ( self , value , next = None , prev = None ):
      self.__value = value
      self.next = None
      self.prev = None
     @property
     def value ( self ):
       return self.__value
     def __init__ ( self , args ):
        self.__root = None
        self.__end = None
        for i in args :
         self.insert (i)
     def insert (self , value ):
# - przypadek , gdy lista jest pusta
      if not isinstance(value,Element):
          value=Element(value)
# - przypadek , gdy trzeba przeiterowac szukajac
# wiekszego elementu i wstawic przed nim

# - przypadek , gdy wstawiamy na koncu
      #pass
     def __iter__(self ):
       curr = self.__root
       while not ( curr is None ):
              yield curr.value #- zwraca generator
              curr = curr.next
     def __reversed__(self ):
      pass
     def __contains__(self , value ):
# przebiega po liscie az trafi
# na rowny lub wiekszy elemnet
# jesli wiekszy lub koniec listy
# zwraca false
        pass
# ----------------- TESTY -----------------
dlista = DList ([2 , 3, 4, 5])
for i in dlista :
 print (i)
print ('\n--------\n')
dlista = DList ([8 , 10, 9, 13])
dlista.insert (7)
dlista.insert (12)
dlista.insert (15)
for i in reversed ( dlista ):
 print (i)
print ('\n--------\n')
print ('Contain 8: ', 8 in dlista )
print ('Contain 13: ', 13 in dlista )
print ('Contain 15: ', 15 in dlista )
print ('Contain 6: ', 6 in dlista )
print ('Contain 11: ', 11 in dlista )
print ('Contain 17: ', 17 in dlista )