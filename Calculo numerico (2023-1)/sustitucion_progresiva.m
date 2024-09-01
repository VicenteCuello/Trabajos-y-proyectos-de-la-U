function x = sustitucion_progresiva(l,b)
x = zeros(length(b),1);
x(1) = b(1)/l(1,1);
for i = 2:length(b)
    suma = 0;
    for j= 1:i-1
        suma = suma + l(i,j)*x(j);
    end
    x(i) = (b(i) - suma)/l(i,i);
end



end

