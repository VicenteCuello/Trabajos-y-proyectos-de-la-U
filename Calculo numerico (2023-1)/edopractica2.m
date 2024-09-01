x0 = 0;
x1 = 1;
N = 100; % Número de puntos de la malla
h = (x1 - x0) / N; % Tamaño del paso
x = x0:h:x1; % Malla de puntos equidistantes
y = zeros(2, N+1);
y(:, 1) = [1; -1]; % Condiciones iniciales

for i = 1:N
    k1 = edopractica(x(i), y(:, i));
    k2 = edopractica(x(i) + h/2, y(:, i) + h/2 * k1);
    k3 = edopractica(x(i) + h/2, y(:, i) + h/2 * k2);
    k4 = edopractica(x(i) + h, y(:, i) + h * k3);
    
    y(:, i+1) = y(:, i) + (h/6) * (k1 + 2*k2 + 2*k3 + k4);
end

% Graficar la solución
plot(x, y(1, :));
xlabel('x');
ylabel('y(x)');
title('Solución de la EDO: y''''(x) - y(x) = exp(x) + x^2');