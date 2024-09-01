function [x,y] = euler_implicito_sistemas(f,a,b,y0,n)


%y0 debe ser columna
h = (b-a)/n;
y = [];
x = [];


y(:,1) = y0;
x(1) = a;

for i = 1 : n
  x(i+1) = x(i) + h;
  g = @(alfa) alfa - y(:,i) - h*f(x(i+1),alfa); 
  alfa0 = y(:,i);
  alfa = fsolve(g,alfa0);
  y(:,i+1) = alfa;
end  