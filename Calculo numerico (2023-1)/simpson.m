function I= simpson(a,b,f,n)
h = (b-a)/n;
x = a:h:b;
I = 0;
for i = 1:n
    I = I + (h/6)*(f(x(i)) + 4*f((x(i)+x(i+1))/2) + f(x(i+1)));
end