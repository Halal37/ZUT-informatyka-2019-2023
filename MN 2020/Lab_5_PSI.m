function A = Lab_5_PSI(p,n,X)
A=zeros(p+1)
for i=1:n
    for j=1:p+1
        for k=1:p+1
           A(j,k)= A(j,k)+X(i)^(j+k-2)
        end
    end
end