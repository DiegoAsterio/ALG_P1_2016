lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2

fit lineal(x) "./data/Nacho/datos_solucion1_Nacho.dat" via l0,l1
fit nlogaritmica(x) "./data/Nacho/datos_solucion1_Nacho.dat" via n0,n1
fit logaritmica(x) "./data/Nacho/datos_solucion1_Nacho.dat" via t0,t1,t2

plot "./data/Nacho/datos_solucion1_Nacho.dat", lineal(x), nlogaritmica(x), logaritmica(x)

set term png
set output "./grphx/Nacho/solucion1_Nacho.png"
replot
set term x11


lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2
cuadratica(x) = c0*x**2 + c1*x + c2

fit lineal(x) "./data/Nacho/datos_opcional_bruto_Nacho.dat" via l0,l1
fit nlogaritmica(x) "./data/Nacho/datos_opcional_bruto_Nacho.dat" via n0,n1
fit logaritmica(x) "./data/Nacho/datos_opcional_bruto_Nacho.dat" via t0,t1,t2
fit cuadratica(x) "./data/Nacho/datos_opcional_bruto_Nacho.dat" via c0,c1,c2

plot "./data/Nacho/datos_opcional_bruto_Nacho.dat", lineal(x), nlogaritmica(x), logaritmica(x), cuadratica(x)

set term png
set output "./grphx/Nacho/opcional_bruto_Nacho.png"
replot
set term x11

lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2

fit lineal(x) "./data/Nacho/datos_genera_unimodal_secuencial_Nacho.dat" via l0,l1
fit nlogaritmica(x) "./data/Nacho/datos_genera_unimodal_secuencial_Nacho.dat" via n0,n1
fit logaritmica(x) "./data/Nacho/datos_genera_unimodal_secuencial_Nacho.dat" via t0,t1,t2

plot "./data/Nacho/datos_genera_unimodal_secuencial_Nacho.dat", lineal(x), nlogaritmica(x), logaritmica(x)

set term png
set output "./grphx/Nacho/genera_unimodal_secuencial_Nacho.png"
replot
set term x11

lineal(x) = l0*x + l1
nlogaritmica(x) = n0*x*log(n1*x)
logaritmica(x) = t0*log(t1*x) + t2

fit lineal(x) "./data/Nacho/datos_Parts_Nacho.dat" via l0,l1
fit nlogaritmica(x) "./data/Nacho/datos_Parts_Nacho.dat" via n0,n1
fit logaritmica(x) "./data/Nacho/datos_Parts_Nacho.dat" via t0,t1,t2

plot "./data/Nacho/datos_Parts_Nacho.dat", lineal(x), nlogaritmica(x), logaritmica(x)

set term png
set output "./grphx/Nacho/Parts_Nacho.png"
replot
set term x11
