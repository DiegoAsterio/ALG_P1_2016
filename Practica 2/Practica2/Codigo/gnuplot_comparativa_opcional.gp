evidente(x) = a*x**2 + b*x + c
merge(x) = n0*x*log(n1*x)

fit evidente(x) "./data/Nacho/datos_opcional_bruto_Nacho.dat" via a,b,c
fit merge(x) "./data/Nacho/datos_opcional_dyv_Nacho.dat" via n0,n1

set xrange [0:10000]
set yrange [0:0.1]

plot evidente(x), merge(x)

set term png
set output "./grphx/Nacho/Comparativa_opcional.png"
replot
set term x11
