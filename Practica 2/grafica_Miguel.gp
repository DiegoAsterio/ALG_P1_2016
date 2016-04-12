lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2

fit lineal(x) "./data/Miguel/datos_solucion1_Miguel.dat" via l0,l1
fit nlogaritmica(x) "./data/Miguel/datos_solucion1_Miguel.dat" via n0,n1
fit logaritmica(x) "./data/Miguel/datos_solucion1_Miguel.dat" via t0,t1,t2

plot "./data/Miguel/datos_solucion1_Miguel.dat", lineal(x), nlogaritmica(x), logaritmica(x)

set term png
set output "./grphx/Miguel/solucion1_Miguel.png"
replot
set term x11

lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2
cuadratica(x) = c0*x**2 + c1*x + c2

fit lineal(x) "./data/Miguel/datos_opcional_bruto_Miguel.dat" via l0,l1
fit nlogaritmica(x) "./data/Miguel/datos_opcional_bruto_Miguel.dat" via n0,n1
fit logaritmica(x) "./data/Miguel/datos_opcional_bruto_Miguel.dat" via t0,t1,t2
fit cuadratica(x) "./data/Miguel/datos_opcional_bruto_Miguel.dat" via c0,c1,c2


plot "./data/Miguel/datos_opcional_bruto_Miguel.dat", lineal(x), nlogaritmica(x), logaritmica(x)

set term png
set output "./grphx/Miguel/opcional_bruto_Miguel.png"
replot
set term x11
