def dodawanie_macierzy(A,B):
   m=len(A)
   n=len(A[0])
   drugi_m=len(B)
   drugi_n=len(B[0])
   if(m==drugi_m and n==drugi_n):
         C=[[0 for i in range(m)]for j in range(n)]
         for i in range(n):
               for j in range(m):
                     C[i][j]=A[i][j]+B[i][j]
         print(C)
   else:
       print("Zle rozmiary")
def dodawanie_stalej_do_macierzy(A,stala):
    m=len(A)
    n=len(A[0])
    C=[[0 for i in range(m)]for j in range(n)]
    for i in range(n):
               for j in range(m):
                     C[i][j]=stala+A[i][j]
    print(C)
   
def mnozenie_macierzy(A,B):
   m=len(A)
   n=len(A[0])
   drugi_m=len(B)
   drugi_n=len(B[0])
   if(n==drugi_m ):
         C=[[0 for i in range(drugi_n)]for j in range(m)]
         for i in range(m):
               for j in range(drugi_n):
                   for k in range(n):
                     C[i][j]+=A[i][k]*B[k][j]
         print(C)
def mnozenie_macierzy_przez_skalar(A,stala):
    m=len(A)
    n=len(A[0])
    C=[[0 for i in range(m)]for j in range(n)]
    for i in range(n):
               for j in range(m):
                     C[i][j]=A[i][j]*stala
    print(C)
def iloczyn_Hadmarda(A,B):
   m=len(A)
   n=len(A[0])
   drugi_m=len(B)
   drugi_n=len(B[0])
   if(m==drugi_m and n==drugi_n):
         C=[[0 for i in range(m)]for j in range(n)]
         for i in range(n):
               for j in range(m):
                     C[i][j]=A[i][j]*B[i][j]
         print(C)
def iloczyn_Kroneckera(A,B):
    m=len(A)
    n=len(A[0])
    drugi_m=len(B)
    drugi_n=len(B[0])
    C = [[0 for j in range(n * drugi_n)] for i in range(m * drugi_m)] 
    for i in range(0,m): 
        for k in range(0,drugi_m): 
            for j in range(0,n): 
                for l in range(0,drugi_n): 
                    C[i + l][j + k] = A[i][j] * B[k][l] 
                    
    print(C)
def Kroneckerproduct(A,B): 
    rowa=len(A)
    cola=len(A[0])
    rowb=len(B)
    colb=len(B[0])      
      
    C = [[0 for j in range(cola * colb)] for i in range(rowa * rowb)] 

    for i in range(0, rowa): 
        for k in range(0, rowb): 
            for j in range(0, cola): 
                for l in range(0, colb): 
                    C[i + l + 1][j + k + 1] = A[i][j] * B[k][l] 
                    print (C[i + l + 1][j + k + 1],end=' ') 
                    
    print(C)
def iloczyn_Kroneckera(A:"macierz",B:"macierz")->"wynik":
    """
    Funkcja liczaca iloczyn Kroneckera dwoch macierzy
    """