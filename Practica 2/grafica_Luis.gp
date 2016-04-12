lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2

fit lineal(x) "./data/Luis/datos_solucion1_Luis.dat" via l0,l1
fit nlogaritmica(x) "./data/Luis/datos_solucion1_Luis.dat" via n0,n1
fit logaritmica(x) "./data/Luis/datos_solucion1_Luis.dat" via t0,t1,t2

plot "./data/Luis/datos_solucion1_Luis.dat", lineal(x), nlogaritmica(x), logaritmica(x)

set term png
set output "./grphx/Luis/solucion1_Luis.png"
replot
set term x11


lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2

fit lineal(x) "./data/Luis/datos_opcional_bruto_Luis.dat" via l0,l1
fit nlogaritmica(x) "./data/Luis/datos_opcional_bruto_Luis.dat" via n0,n1
fit logaritmica(x) "./data/Luis/datos_opcional_bruto_Luis.dat" via t0,t1,t2

plot "./data/Luis/datos_opcional_bruto_Luis.dat", lineal(x), nlogaritmica(x), logaritmica(x)

set term png
set output "./grphx/Luis/opcional_bruto_Luis.png"
replot
set term x11

lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2

fit lineal(x) "./data/Luis/datos_genera_unimodal_secuencial_Luis.dat" via l0,l1
fit nlogaritmica(x) "./data/Luis/datos_genera_unimodal_secuencial_Luis.dat" via n0,n1
fit logaritmica(x) "./data/Luis/datos_genera_unimodal_secuencial_Luis.dat" via t0,t1,t2

plot "./data/Luis/datos_genera_unimodal_secuencial_Luis.dat", lineal(x), nlogaritmica(x), logaritmica(x)

set term png
set output "./grphx/Luis/genera_unimodal_secuencial_Luis.png"
replot
set term x11

lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2

fit lineal(x) "./data/Luis/datos_opcional_dyv_Luis.dat" via l0,l1
fit nlogaritmica(x) "./data/Luis/datos_opcional_dyv_Luis.dat" via n0,n1
fit logaritmica(x) "./data/Luis/datos_opcional_dyv_Luis.dat" via t0,t1,t2

plot "./data/Luis/datos_opcional_dyv_Luis.dat", lineal(x), nlogaritmica(x), logaritmica(x)

set term png
set output "./grphx/Luis/opcional_dyv_Luis.png"
replot
set term x11
