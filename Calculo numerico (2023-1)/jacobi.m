function [aprox,iter] = jacobi(A,b,x0,tol,maxiter)

D = diag(diag(A));
E = -(tril(A) - D);
F = -(triu(A) - D);

N = D;
P = E+F;

iter = 1;
dif = 2*tol;
x1 = N/(P*x0+b);
while dif >= tol && iter < maxiter
    iter = iter +1;
    x_ant_2 = x0;
    x_ant = x1;
    x_sig = sustitucion_progresiva(N,P*x_ant + b);
    m = norm(x_sig-x_ant)/norm(x_sig-x_ant_2);
    dif = (m/(1-m))*norm(x_sig-x_ant);
    x0 = x1;
    x1 = x_sig;
end
aprox = x_sig;

end