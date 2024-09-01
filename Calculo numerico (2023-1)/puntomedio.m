function I= puntomedio(a,b,f,n)
h = (b-a)/n;
x = a:h:b;
I = 0;
for i = 1:n
    I = I + h * f((x(i)+x(i+1))/2);
end