Laby5
#Zadanie 1
# X~N(86.5, sig), P(82.5<X<90.5)=0.3472  P(X>95)*400=?
# pnorm((90.5-86.5)/sig)-pnorm((82.5-86.5)/sig)=0.3472
# pnorm(4/sig)-pnorm(-4/sig)=0.3472
# pnorm(4/sig)-1+pnorm(4/sig)=0.3472
# 2pnorm(4/sig)=1.3472
# pnorm(4/sig)=1.3472/2
# 4/sig=qnorm(1.3472/2)
sig=4/qnorm(1.3472/2)
# P(X>95)=1-P(X<=95)
pnorm(95,86.5,sig,F)*400

#Zadanie 3



A=matrix(c(1,1,qnorm(0.8),qnorm(0.44)),2,2)
B=matrix(c(2,1.5),2,1)
m=solve(A,B)[1]
sig=solve(A,B)[2]



# P(X<0.5)
pnorm(0.5,m,sig)

#Zadanie 4
