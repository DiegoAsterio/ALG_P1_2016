plot "sol_vecino_mas_cercano.tsp" using 2:3 with lines

set term png
set output "./grphx/Nacho/sol_vecino_mas_cercano.png"
replot
set term x11

plot "sol_triangles.tsp" using 2:3 with lines

set term png
set output "./grphx/Nacho/sol_triangles.png"
replot
set term x11

plot "sol_random_swap.tsp" using 2:3 with lines

set term png
set output "./grphx/Nacho/sol_random_swap.png"
replot
set term x11

plot "sol_dijsktra.tsp" using 2:3 with lines

set term png
set output "./grphx/Nacho/sol_dijsktra.png"
replot
set term x11
