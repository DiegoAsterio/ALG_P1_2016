#!/bin/usr/gnuplot

######## GRAFICA CENA_GALA_NACHO ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2

fit lineal(x) "./data/Diego/cena_gala_nacho.dat" via l0,l1
fit cuadratica(x) "./data/Diego/cena_gala_nacho.dat" via c0,c1,c2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", "./data/Diego/cena_gala_nacho.dat" lt rgb "gold" title "Cena_gala_nacho"

set term png
set output "./grphx/Diego/cena_gala_nacho.png"
replot
set term x11

######## GRAFICA CENA_GALA_BACKTRACKING_CUENTAPERDIDA ###########
fac(x) = (int(x)==0) ? 1.0 : int(x) * fac(int(x)-1.0)
factorial(x) = a*fac(x) + b

fit factorial(x) "./data/Diego/cena_gala_backtracking_cuentaperdida.dat" via a, b
plot factorial(x) title "factorial", "./data/Diego/cena_gala_backtracking_cuentaperdida.dat" with lines lt rgb "gold" title "cena_gala_backtracking_cuentaperdida"

set term png
set output "./grphx/Diego/cena_gala_backtracking_cuentaperdida.png"
replot
set term x11

######## GRAFICA CENA_GALA_LUIS ###########
fac(x) = (int(x)==0) ? 1.0 : int(x) * fac(int(x)-1.0)
factorial(x) = a*fac(x) + b

fit factorial(x) "./data/Diego/cena_gala_luis.dat" via a, b
plot factorial(x) title "factorial", "./data/Diego/cena_gala_luis.dat" with lines lt rgb "gold" title "cena_gala_luis"

set term png
set output "./grphx/Diego/cena_gala_luis.png"
replot
set term x11

######## GRAFICA CENA_GALA_DIEGO ###########
fac(x) = (int(x)==0) ? 1.0 : int(x) * fac(int(x)-1.0)
factorial(x) = a*fac(x) + b

fit factorial(x) "./data/Diego/cena_gala_diego.dat" via a, b
plot factorial(x) title "factorial", "./data/Diego/cena_gala_diego.dat" with lines lt rgb "gold" title "cena_gala_diego"

set term png
set output "./grphx/Diego/cena_gala_diego.png"
replot
set term x11
