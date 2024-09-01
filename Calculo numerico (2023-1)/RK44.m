function [x,y] = RK44(f,a,b,y0,n)
%y0 debe ser columna
h = (b-a)/n;
y = [];
x = [];

y(:,1) = y0;
x(1) = a;

for i = 1 : n
    x(i+1) = x(i) + h;
    k_1 = h*f(x(i),y(:,i));
    k_2 = h*f(x(i)+0.5*h,y(:,i)+0.5*k_1);
    k_3 = h*f(x(i)+0.5*h,y(:,i)+0.5*k_2);
    k_4 = h*f(x(i)+h,y(:,i)+k_3);
    y(:,i+1) = y(:,i) + (1/6)*(k_1+2*(k_2+k_3)+k_4); 
end