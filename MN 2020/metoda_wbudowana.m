function metoda_wbudowana(A,b)
n=size(b,1);
    x=zeros(n,1);
    if det(A)==0
           error('Nie mozna wykonac operacji')
    end
    x=A\b;
    disp('Metodą wbudowaną:');
    fprintf('x = %0.2f \n',x(1))
    fprintf('y = %0.2f \n',x(2))
    fprintf('z = %0.2f \n',x(3))
end