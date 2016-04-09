lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2

fit lineal(x) "./data/datos_algoritmo_nacho.dat" via l0,l1
fit nlogaritmica(x) "./data/datos_algoritmo_nacho.dat" via n0,n1
fit logaritmica(x) "./data/datos_algoritmo_nacho.dat" via t0,t1,t2

set key bottom
plot "./data/datos_algoritmo_nacho.dat", lineal(x), nlogaritmica(x), logaritmica(x)

set term png
set output "./grphx/algoritmo_Nacho.png"
replot
set term x11