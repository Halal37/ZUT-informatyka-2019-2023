function A = Lab_5_F(p,n,X,Y)
A=zeros(p+1,1);
for i=1:n
    for j=1:p+1
        A(j)=A(j)+X(i)^(j-1)*Y(i);
    end
end