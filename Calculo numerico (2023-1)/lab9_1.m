n = 3;
b = zeros(2*n,1);
a = 4*diag(ones(2*n,1),0)+(-1)*diag(ones(2*n-1,1),1)+(-1)*diag(ones(2*n-1,1),-1);
for i=1:2*n
    b(i)= i^2;
end
z = zeros(n,n);
i = eye(n);
t = [z i;i z];
c = t*a;
q = t*b;
[l,u,p] = lu(c);
y = sustitucion_progresiva(l,p*q);
z = sustitucion_regresiva(u,y);
