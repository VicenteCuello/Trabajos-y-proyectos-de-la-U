function y = lagrange(nodos, x)

n = length(nodos);
y = zeros(size(nodos));

for i = 1:n
    L = ones(size(nodos));
    for j = 1:n
        if j ~= i
            L = L .* (x - nodos(j)) ./ (nodos(i) - nodos(j));
        end
    end
    y(i) = L(i);
end