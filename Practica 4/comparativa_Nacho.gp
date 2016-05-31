#!/bin/usr/gnuplot

set xrange [0:10]
plot "./data/Nacho/cena_gala_nacho.dat" with lines, "./data/Nacho/cena_gala_luis.dat" with lines, "./data/Nacho/cena_gala_backtracking_cuentaperdida.dat" with lines, "./data/Nacho/cena_gala_diego.dat" with lines

set term png
set output "./grphx/Nacho/comparativa_todos.png"
replot
set term x11

set xrange [0:10]
plot "./data/Nacho/cena_gala_nacho.dat" with lines, "./data/Nacho/cena_gala_diego.dat" with lines
set term png
set output "./grphx/Nacho/comparativa_diego_nacho.png"
replot
set term x11
