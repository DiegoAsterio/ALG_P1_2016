#!/bin/usr/gnuplot

######## GRAFICA CENA_GALA_NACHO ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2

fit lineal(x) "./data/Nacho/cena_gala_nacho.dat" via l0,l1
fit cuadratica(x) "./data/Nacho/cena_gala_nacho.dat" via c0,c1,c2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", "./data/Nacho/cena_gala_nacho.dat" lt rgb "gold" title "Cena_gala_nacho"

set term png
set output "./grphx/Nacho/cena_gala_nacho.png"
replot
set term x11

######## GRAFICA CENA_GALA_BACKTRACKING_CUENTAPERDIDA ###########
factorial(x) = a*int(x)! + b

fit factorial(x) "./data/Nacho/cena_gala_backtracking_cuentaperdida.dat" via a, b
plot factorial(x) title "factorial", "./data/Nacho/cena_gala_backtracking_cuentaperdida.dat" lt rgb "gold" title "cena_gala_backtracking_cuentaperdida"

set term png
set output "./grphx/Nacho/cena_gala_backtracking_cuentaperdida.png"
replot
set term x11
