temperatura = [300, 400, 500, 600, 700, 800, 900, 1000, 1100];
Emisividad_termica = [0.024, 0.035, 0.046, 0.058, 0.067, 0.083, 0.097, 0.111, 0.125];

s = spline(temperatura, Emisividad_termica);

s_550 = ppval(s, 550);
s_750 = ppval(s, 750);
s_1030 = ppval(s, 1030);







