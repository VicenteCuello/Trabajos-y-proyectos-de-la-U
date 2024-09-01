nodos = [-2 -1 0 1 2];
valores = [-25 -4 -1 8 47];

% Crear vector de puntos de evaluación
X = -2:4/1000:2;

% Evaluar polinomio de interpolación en cada punto de X
Y = zeros(size(X));
for i = 1:length(X)
    Y(i) = lagrange(nodos, X(i)) * valores';
end

c = polyfit(nodos, valores, 4);
x = -2:4/1000:2; 
p = polyval(c, x);
plot(x, p, nodos, valores, 'o')
legend('Datos', 'Interpolación')