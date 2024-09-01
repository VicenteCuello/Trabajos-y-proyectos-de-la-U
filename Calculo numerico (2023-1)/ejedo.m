% Definición del sistema de ecuaciones diferenciales
dydt = @(x, y1, y2) y2;
d2ydt2 = @(x, y1, y2) exp(x) + x^2 - y1;

% Condiciones iniciales
x0 = 0;
y1_0 = -1;
y2_0 = 1;
initial_conditions = [y1_0; y2_0];

% Solución usando ode45
[x_ode45, y_ode45] = ode45(@(x, y) [dydt(x, y(1), y(2)); d2ydt2(x, y(1), y(2))], [x0, 1], initial_conditions);

% Método de Euler explícito
h = 1; % Tamaño inicial del paso
tol = 1e-3; % Tolerancia para detener el bucle
diff = Inf; % Diferencia inicial
x_euler = cell(1, 1);
y_euler = cell(1, 1);

while diff > tol
    h = h / 10;
    i = i + 1;
    n = round(1 / h); % Número de subintervalos
    [x_euler{i}, y_euler{i}] = euler_explicito([y1_0, y2_0], x0, 1, @(x, y) [y(2); exp(x) + x^2 - y(1)], n);

    % Cálculo de la diferencia entre las aproximaciones
    diff = abs(y_ode45(end, 2) - y_euler{i}(end, 2));
    
end

% Gráfico de la última aproximación con Euler explícito
figure;
plot(x_euler{end}, y_euler{end}(:, 2), 'b-', 'LineWidth', 1.5);
xlabel('x');
ylabel('y(x)');
title('Aproximación de y(x) con Euler explícito');
grid on;

% Función para el método de Euler explícito
function [x, y] = euler_explicito(y0, a, b, f, n)
    h = (b - a) / n;
    x = zeros(n+1, 1);
    y = zeros(n+1, numel(y0));
    x(1) = a;
    y(1, :) = y0;
    
    for i = 1:n
        x(i+1) = x(i) + h;
        y(i+1, :) = y(i, :) + h * f(x(i), y(i, :))';
    end
end

