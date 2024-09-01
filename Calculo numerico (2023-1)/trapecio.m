function I= trapecio(a,b,f,n)
h = (b-a)/n;
x = a:h:b;
I = 0;
for i = 1:n
    I = I + (h/2) * (f(x(i)) + f(x(i+1)));
end