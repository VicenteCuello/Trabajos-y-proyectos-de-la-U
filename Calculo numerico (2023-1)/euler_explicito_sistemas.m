function [x,y] = euler_explicito_sistemas(y0,a,b,f,n)
%y0 debe ser un vector columna  
h = (b-a)/n;
x = [];
y = [];

x(1) = a;
y(:,1) = y0;
for i = 1 : n
  x(i+1) = x(i) + h;
  y(:,i+1) = y(:,i) + h*f(x(i),y(:,i));
end  