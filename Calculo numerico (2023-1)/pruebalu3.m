a = [0 0 12 1 6 2 1 0; 0 0 0 12 2 6 2 1; 0 0 0 0 10 2 6 2; 0 0 0 0 0 10 2 6; 6 2 1 0 0 0 0 0; 4 6 2 1 0 0 0 0; 10 4 6 2 3 0 0 0; 0 10 4 6 5 3 0 0];

% Factorización LU con permutación de filas
[p, l, u] = lu(a);

% Definir la matriz identidad modificada
I_modified = [0 0 0 0 1 0 0 0; 0 0 0 0 0 1 0 0; 0 0 0 0 0 0 1 0; 0 0 0 0 0 0 0 1; 1 0 0 0 0 0 0 0; 0 1 0 0 0 0 0 0; 0 0 1 0 0 0 0 0; 0 0 0 1 0 0 0 0];

% Calcular la matriz P - I
P_minus_I = p - I_modified;

% Calcular la norma infinito de P - I
norm_P_minus_I = norm(P_minus_I, 'inf');

% Mostrar los resultados
disp('Matriz L:');
disp(l);
disp('Matriz U:');
disp(u);
disp('Permutación de filas:');
disp(p);
disp(['La norma ‖P - I‖infinito es: ' num2str(norm_P_minus_I)]);
