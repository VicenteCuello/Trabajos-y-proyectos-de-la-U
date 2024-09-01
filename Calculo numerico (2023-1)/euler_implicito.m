function [x,y] = euler_implicito(y0,a,b,f,n)
h = (b-a)/n
x = [];
y = [];
x(1) = a;
y(1) = y0;
for i = 1 : n
x(i+1) = x(i) + h;
g = @(alfa) alfa - y(i) - h*f(x(i+1),alfa);
alfa0 = y(i);
alfa = fzero(g,alfa0);
y(i+1) = alfa;
end
