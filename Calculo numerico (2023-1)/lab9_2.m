n = 5;
b = zeros(2*n,1);
for i=1:2*n
    b(i)= i^2;
end
a = 4*diag(ones(2*n,1),0)+(-1)*diag(ones(2*n-1,1),1)+(-1)*diag(ones(2*n-1,1),-1);
h = issymmetric(a);
v = eig(a);
if sum(v<0)+h == 2*n+1
    r = chol(a);
    y = sustitucion_progresiva(r',b);
    x = sustitucion_regresiva(r,y);
end
