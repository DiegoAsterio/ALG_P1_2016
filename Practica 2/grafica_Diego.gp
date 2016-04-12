lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2

fit lineal(x) "./data/Diego/datos_solucion1_Diego.dat" via l0,l1
fit nlogaritmica(x) "./data/Diego/datos_solucion1_Diego.dat" via n0,n1
fit logaritmica(x) "./data/Diego/datos_solucion1_Diego.dat" via t0,t1,t2

plot "./data/Diego/datos_solucion1_Diego.dat", lineal(x), nlogaritmica(x), logaritmica(x)

set term png
set output "./grphx/Diego/solucion1_Diego.png"
replot
set term x11



lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2

fit lineal(x) "./data/Diego/datos_opcional_bruto_Diego.dat" via l0,l1
fit nlogaritmica(x) "./data/Diego/datos_opcional_bruto_Diego.dat" via n0,n1
fit logaritmica(x) "./data/Diego/datos_opcional_bruto_Diego.dat" via t0,t1,t2

plot "./data/Diego/datos_opcional_bruto_Diego.dat", lineal(x), nlogaritmica(x), logaritmica(x)

set term png
set output "./grphx/Diego/opcional_bruto_Diego.png"
replot
set term x11


lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2

fit lineal(x) "./data/Diego/datos_opcional_dyv_Diego.dat" via l0,l1
fit nlogaritmica(x) "./data/Diego/opcional_dyv_bruto_Diego.dat" via n0,n1
fit logaritmica(x) "./data/Diego/opcional_dyv_bruto_Diego.dat" via t0,t1,t2

plot "./data/Diego/datos_opcional_dyv_Diego.dat", lineal(x), nlogaritmica(x), logaritmica(x)

set term png
set output "./grphx/Diego/opcional_dyv_Diego.png"
replot
set term x11