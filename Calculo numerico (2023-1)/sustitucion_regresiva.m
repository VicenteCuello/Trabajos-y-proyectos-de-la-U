function x = sustitucion_regresiva(u,y)
n = length(y);
x = zeros(n,1);
x(end) = y(end)/u(end,end);
for i = 1:n-1
    suma = 0;
    for j = n-i:n
        suma = suma + u(end-i,j)*x(j);
    end
    x(end-i) = (y(end-i) - suma)/u(end-i,end-i);
end



end

