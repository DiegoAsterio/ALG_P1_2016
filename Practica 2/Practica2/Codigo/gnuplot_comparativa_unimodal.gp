solucion1(x) = t0*log(t1*x) + t2
secuencial(x) = l0*x + l1
parts(x) = t3*log(t4*x) + t5

fit solucion1(x) "./data/Nacho/datos_solucion1_Nacho.dat" via t0,t1,t2
fit secuencial(x) "./data/Nacho/datos_genera_unimodal_secuencial_Nacho.dat" via l0,l1
fit parts(x) "./data/Nacho/datos_Parts_Nacho.dat" via t3,t4,t5

set xrange [0:3000000]

plot solucion1(x), parts(x)

set term png
set output "./grphx/Nacho/Comparativa_unimodal.png"
replot
set term x11
