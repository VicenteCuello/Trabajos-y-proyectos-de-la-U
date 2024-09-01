function dydx = edopractica(x, y)
    dydx = zeros(2, 1);
    dydx(1) = y(2);
    dydx(2) = y(1) + exp(x) + x^2;
end



