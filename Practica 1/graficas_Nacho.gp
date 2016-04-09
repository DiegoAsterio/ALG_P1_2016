#!/bin/usr/gnuplot

################ VARIOS AJUSTES SIMULTANEOS ############################

######## GRAFICA BURBUJA ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Nacho/burbujaO0.dat" via l0,l1
fit cuadratica(x) "./data/Nacho/burbujaO0.dat" via c0,c1,c2
fit cubica(x) "./data/Nacho/burbujaO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Nacho/burbujaO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Nacho/burbujaO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", nlogaritmica(x) title "n*log(n)", "./data/Nacho/burbujaO0.dat" lt rgb "gold" title "Burbuja"

set term png
set output "./grphx/Nacho/Ajustes/burbuja.png"
replot
set term x11

######## GRAFICA FIBONACCI ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Nacho/fibonacciO0.dat" via l0,l1
fit cuadratica(x) "./data/Nacho/fibonacciO0.dat" via c0,c1,c2
fit cubica(x) "./data/Nacho/fibonacciO0.dat" via r0,r1,r2,r3
fit f(x) "./data/Nacho/fibonacciO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Nacho/fibonacciO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", f(x) title "2-exponencial",nlogaritmica(x) title "n*log(n)", "./data/Nacho/fibonacciO0.dat" lt rgb "gold" title "Fibonacci"

set term png
set output "./grphx/Nacho/Ajustes/fibonacci.png"
replot
set term x11

######## GRAFICA FLOYD ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Nacho/floydO0.dat" via l0,l1
fit cuadratica(x) "./data/Nacho/floydO0.dat" via c0,c1,c2
fit cubica(x) "./data/Nacho/floydO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Nacho/floydO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Nacho/floydO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", nlogaritmica(x) title "n*log(n)", "./data/Nacho/floydO0.dat" lt rgb "gold" title "Foyd"

set term png
set output "./grphx/Nacho/Ajustes/floyd.png"
replot
set term x11

######## GRAFICA HANOI ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Nacho/hanoiO0.dat" via l0,l1
fit cuadratica(x) "./data/Nacho/hanoiO0.dat" via c0,c1,c2
fit cubica(x) "./data/Nacho/hanoiO0.dat" via r0,r1,r2,r3
fit f(x) "./data/Nacho/hanoiO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Nacho/hanoiO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", f(x) title "2-exponencial", nlogaritmica(x) title "n*log(n)", "./data/Nacho/hanoiO0.dat" lt rgb "gold" title "Hanoi"

set term png
set output "./grphx/Nacho/Ajustes/hanoi.png"
replot
set term x11

######## GRAFICA HEAPSORT ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Nacho/heapsortO0.dat" via l0,l1
fit cuadratica(x) "./data/Nacho/heapsortO0.dat" via c0,c1,c2
fit cubica(x) "./data/Nacho/heapsortO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Nacho/heapsortO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Nacho/heapsortO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", nlogaritmica(x) title "n*log(n)", "./data/Nacho/heapsortO0.dat" lt rgb "gold" title "Heapsort"

set term png
set output "./grphx/Nacho/Ajustes/heapsort.png"
replot
set term x11

######## GRAFICA INSERCION ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Nacho/insercionO0.dat" via l0,l1
fit cuadratica(x) "./data/Nacho/insercionO0.dat" via c0,c1,c2
fit cubica(x) "./data/Nacho/insercionO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Nacho/insercionO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Nacho/insercionO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", nlogaritmica(x) title "n*log(n)", "./data/Nacho/insercionO0.dat" lt rgb "gold" title "Insercion"

set term png
set output "./grphx/Nacho/Ajustes/insercion.png"
replot
set term x11

######## GRAFICA MERGESORT ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
#cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Nacho/mergesortO0.dat" via l0,l1
fit cuadratica(x) "./data/Nacho/mergesortO0.dat" via c0,c1,c2
#fit cubica(x) "./data/Nacho/mergesortO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Nacho/mergesortO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Nacho/mergesortO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", nlogaritmica(x) title "n*log(n)", "./data/Nacho/mergesortO0.dat" lt rgb "gold" title "Mergesort"

set term png
set output "./grphx/Nacho/Ajustes/mergesort.png"
replot
set term x11

######## GRAFICA QUICKSORT ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
#cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Nacho/quicksortO0.dat" via l0,l1
fit cuadratica(x) "./data/Nacho/quicksortO0.dat" via c0,c1,c2
#fit cubica(x) "./data/Nacho/quicksortO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Nacho/quicksortO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Nacho/quicksortO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", nlogaritmica(x) title "n*log(n)", "./data/Nacho/quicksortO0.dat" lt rgb "gold" title "Quicksort"

set term png
set output "./grphx/Nacho/Ajustes/quicksort.png"
replot
set term x11

######## GRAFICA SELECCION ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Nacho/seleccionO0.dat" via l0,l1
fit cuadratica(x) "./data/Nacho/seleccionO0.dat" via c0,c1,c2
fit cubica(x) "./data/Nacho/seleccionO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Nacho/seleccionO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Nacho/seleccionO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", nlogaritmica(x) title "n*log(n)", "./data/Nacho/seleccionO0.dat" lt rgb "gold" title "Seleccion"

set term png
set output "./grphx/Nacho/Ajustes/seleccion.png"
replot
set term x11

##################### COMPARACION OPTIMIZACIONES #############################

######## GRAFICA BURBUJA ###########
cuadratica0(x) = c0*x**2 + c1*x + c2
cuadratica1(x) = c3*x**2 + c4*x + c5
cuadratica2(x) = c6*x**2 + c7*x + c8
cuadratica3(x) = c9*x**2 + c10*x + c11
fit cuadratica0(x) "./data/Nacho/burbujaO0.dat" via c0,c1,c2
fit cuadratica1(x) "./data/Nacho/burbujaO1.dat" via c3,c4,c5
fit cuadratica2(x) "./data/Nacho/burbujaO2.dat" via c6,c7,c8
fit cuadratica3(x) "./data/Nacho/burbujaO3.dat" via c9,c10,c11
plot "./data/Nacho/burbujaO0.dat" lt rgb "gold" title "BurbujaO0", "./data/Nacho/burbujaO1.dat" lt rgb "gold" title "BurbujaO1", "./data/Nacho/burbujaO2.dat" lt rgb "gold" title "BurbujaO2", "./data/Nacho/burbujaO3.dat" lt rgb "gold" title "BurbujaO3", cuadratica0(x) title "Cuadrática O0", cuadratica1(x) title "Cuadrática O1", cuadratica2(x) title "Cuadrática O2", cuadratica3(x) title "Cuadrática O3"

set term png
set output "./grphx/Nacho/Eficiencia/burbuja.png"
replot
set term x11

######## GRAFICA FIBONACCI ###########
f0(x) = e0*(2**(e1*x + e2)) + e3
f1(x) = e4*(2**(e5*x + e6)) + e7
f2(x) = e8*(2**(e9*x + e10)) + e11
f3(x) = e12*(2**(e13*x + e14)) + e15

fit f0(x) "./data/Nacho/fibonacciO0.dat" via e0,e1,e2,e3
fit f1(x) "./data/Nacho/fibonacciO1.dat" via e4,e5,e6,e7
fit f2(x) "./data/Nacho/fibonacciO2.dat" via e8,e9,e10,e11
fit f3(x) "./data/Nacho/fibonacciO3.dat" via e12,e13,e14,e15
plot "./data/Nacho/fibonacciO0.dat" lt rgb "gold" title "FibonacciO0", "./data/Nacho/fibonacciO1.dat" lt rgb "gold" title "FibonacciO1", "./data/Nacho/fibonacciO2.dat" lt rgb "gold" title "FibonacciO2", "./data/Nacho/fibonacciO3.dat" lt rgb "gold" title "FibonacciO3", f0(x) title "2-exponencial O0", f1(x) title "2-exponencial O1", f2(x) title "2-exponencial O2", f3(x) title "2-exponencial O3"

set term png
set output "./grphx/Nacho/Eficiencia/fibonacci.png"
replot
set term x11

######## GRAFICA FLOYD ###########
cubica0(x) = r0*x**3 + r1*x**2 + r2*x + r3
cubica1(x) = r4*x**3 + r5*x**2 + r6*x + r7
cubica2(x) = r8*x**3 + r9*x**2 + r10*x + r11
cubica3(x) = r12*x**3 + r13*x**2 + r14*x + r15


fit cubica0(x) "./data/Nacho/floydO0.dat" via r0,r1,r2,r3
fit cubica1(x) "./data/Nacho/floydO1.dat" via r4,r5,r6,r7
fit cubica2(x) "./data/Nacho/floydO2.dat" via r8,r9,r10,r11
fit cubica3(x) "./data/Nacho/floydO3.dat" via r12,r13,r14,r15
plot "./data/Nacho/floydO0.dat" lt rgb "gold" title "FloydO0", "./data/Nacho/floydO1.dat" lt rgb "gold" title "FloydO1", "./data/Nacho/floydO2.dat" lt rgb "gold" title "FloydO2", "./data/Nacho/floydO3.dat" lt rgb "gold" title "FloydO3", cubica0(x) title "Cubica O0", cubica1(x) title "Cubica O1", cubica2(x) title "Cubica O2", cubica3(x) title "Cubica O3"

set term png
set output "./grphx/Nacho/Eficiencia/floyd.png"
replot
set term x11

######## GRAFICA HANOI ###########
f0(x) = e0*(2**(e1*x + e2)) + e3
f1(x) = e4*(2**(e5*x + e6)) + e7
f2(x) = e8*(2**(e9*x + e10)) + e11
f3(x) = e12*(2**(e13*x + e14)) + e15

fit f0(x) "./data/Nacho/hanoiO0.dat" via e0,e1,e2,e3
fit f1(x) "./data/Nacho/hanoiO1.dat" via e4,e5,e6,e7
fit f2(x) "./data/Nacho/hanoiO2.dat" via e8,e9,e10,e11
fit f3(x) "./data/Nacho/hanoiO3.dat" via e12,e13,e14,e15
plot "./data/Nacho/hanoiO0.dat" lt rgb "gold" title "HanoiO0", "./data/Nacho/hanoiO1.dat" lt rgb "gold" title "HanoiO1", "./data/Nacho/hanoiO2.dat" lt rgb "gold" title "HanoiO2", "./data/Nacho/hanoiO3.dat" lt rgb "gold" title "HanoiO3", f0(x) title "2-exponencial O0", f1(x) title "2-exponencial O1", f2(x) title "2-exponencial O2", f3(x) title "2-exponencial O3"

set term png
set output "./grphx/Nacho/Eficiencia/hanoi.png"
replot
set term x11

######## GRAFICA HEAPSORT ###########
nlogaritmica0(x) = n0*x*log(n1*x)
nlogaritmica1(x) = n2*x*log(n3*x)
nlogaritmica2(x) = n4*x*log(n5*x)
nlogaritmica3(x) = n6*x*log(n7*x)


fit nlogaritmica0(x) "./data/Nacho/heapsortO0.dat" via n0,n1
fit nlogaritmica1(x) "./data/Nacho/heapsortO1.dat" via n2,n3
fit nlogaritmica2(x) "./data/Nacho/heapsortO2.dat" via n4,n5
fit nlogaritmica3(x) "./data/Nacho/heapsortO3.dat" via n6,n7
plot "./data/Nacho/heapsortO0.dat" lt rgb "gold" title "HeapsortO0", "./data/Nacho/heapsortO1.dat" lt rgb "gold" title "HeapsortO1", "./data/Nacho/heapsortO2.dat" lt rgb "gold" title "HeapsortO2", "./data/Nacho/heapsortO3.dat" lt rgb "gold" title "HeapsortO3", nlogaritmica0(x) title "nlog(n) O0", nlogaritmica1(x) title "nlog(n) O1", nlogaritmica2(x) title "nlog(n) O2", nlogaritmica3(x) title "nlog(n) O3"

set term png
set output "./grphx/Nacho/Eficiencia/heapsort.png"
replot
set term x11

######## GRAFICA INSERCION ###########
cuadratica0(x) = c0*x**2 + c1*x + c2
cuadratica1(x) = c3*x**2 + c4*x + c5
cuadratica2(x) = c6*x**2 + c7*x + c8
cuadratica3(x) = c9*x**2 + c10*x + c11
fit cuadratica0(x) "./data/Nacho/insercionO0.dat" via c0,c1,c2
fit cuadratica1(x) "./data/Nacho/insercionO1.dat" via c3,c4,c5
fit cuadratica2(x) "./data/Nacho/insercionO2.dat" via c6,c7,c8
fit cuadratica3(x) "./data/Nacho/insercionO3.dat" via c9,c10,c11
plot "./data/Nacho/insercionO0.dat" lt rgb "gold" title "InsercionO0", "./data/Nacho/insercionO1.dat" lt rgb "gold" title "InsercionO1", "./data/Nacho/insercionO2.dat" lt rgb "gold" title "InsercionO2", "./data/Nacho/insercionO3.dat" lt rgb "gold" title "InsercionO3", cuadratica0(x) title "Cuadrática O0", cuadratica1(x) title "Cuadrática O1", cuadratica2(x) title "Cuadrática O2", cuadratica3(x) title "Cuadrática O3"

set term png
set output "./grphx/Nacho/Eficiencia/insercion.png"
replot
set term x11

######## GRAFICA MERGESORT ###########
nlogaritmica0(x) = n0*x*log(n1*x)
nlogaritmica1(x) = n2*x*log(n3*x)
nlogaritmica2(x) = n4*x*log(n5*x)
nlogaritmica3(x) = n6*x*log(n7*x)


fit nlogaritmica0(x) "./data/Nacho/mergesortO0.dat" via n0,n1
fit nlogaritmica1(x) "./data/Nacho/mergesortO1.dat" via n2,n3
fit nlogaritmica2(x) "./data/Nacho/mergesortO2.dat" via n4,n5
fit nlogaritmica3(x) "./data/Nacho/mergesortO3.dat" via n6,n7
plot "./data/Nacho/mergesortO0.dat" lt rgb "gold" title "MergesortO0", "./data/Nacho/mergesortO1.dat" lt rgb "gold" title "MergesortO1", "./data/Nacho/mergesortO2.dat" lt rgb "gold" title "MergesortO2", "./data/Nacho/mergesortO3.dat" lt rgb "gold" title "MergesortO3", nlogaritmica0(x) title "nlog(n) O0", nlogaritmica1(x) title "nlog(n) O1", nlogaritmica2(x) title "nlog(n) O2", nlogaritmica3(x) title "nlog(n) O3"

set term png
set output "./grphx/Nacho/Eficiencia/mergesort.png"
replot
set term x11

######## GRAFICA QUICKSORT ###########
nlogaritmica0(x) = n0*x*log(n1*x)
nlogaritmica1(x) = n2*x*log(n3*x)
nlogaritmica2(x) = n4*x*log(n5*x)
nlogaritmica3(x) = n6*x*log(n7*x)


fit nlogaritmica0(x) "./data/Nacho/quicksortO0.dat" via n0,n1
fit nlogaritmica1(x) "./data/Nacho/quicksortO1.dat" via n2,n3
fit nlogaritmica2(x) "./data/Nacho/quicksortO2.dat" via n4,n5
fit nlogaritmica3(x) "./data/Nacho/quicksortO3.dat" via n6,n7
plot "./data/Nacho/quicksortO0.dat" lt rgb "gold" title "QuicksortO0", "./data/Nacho/quicksortO1.dat" lt rgb "gold" title "QuicksortO1", "./data/Nacho/quicksortO2.dat" lt rgb "gold" title "QuicksortO2", "./data/Nacho/quicksortO3.dat" lt rgb "gold" title "QuicksortO3", nlogaritmica0(x) title "nlog(n) O0", nlogaritmica1(x) title "nlog(n) O1", nlogaritmica2(x) title "nlog(n) O2", nlogaritmica3(x) title "nlog(n) O3"

set term png
set output "./grphx/Nacho/Eficiencia/quicksort.png"
replot
set term x11

######## GRAFICA SELECCION ###########
cuadratica0(x) = c0*x**2 + c1*x + c2
cuadratica1(x) = c3*x**2 + c4*x + c5
cuadratica2(x) = c6*x**2 + c7*x + c8
cuadratica3(x) = c9*x**2 + c10*x + c11
fit cuadratica0(x) "./data/Nacho/seleccionO0.dat" via c0,c1,c2
fit cuadratica1(x) "./data/Nacho/seleccionO1.dat" via c3,c4,c5
fit cuadratica2(x) "./data/Nacho/seleccionO2.dat" via c6,c7,c8
fit cuadratica3(x) "./data/Nacho/seleccionO3.dat" via c9,c10,c11
plot "./data/Nacho/seleccionO0.dat" lt rgb "gold" title "SeleccionO0", "./data/Nacho/seleccionO1.dat" lt rgb "gold" title "SeleccionO1", "./data/Nacho/seleccionO2.dat" lt rgb "gold" title "SeleccionO2", "./data/Nacho/seleccionO3.dat" lt rgb "gold" title "SeleccionO3", cuadratica0(x) title "Cuadrática O0", cuadratica1(x) title "Cuadrática O1", cuadratica2(x) title "Cuadrática O2", cuadratica3(x) title "Cuadrática O3"

set term png
set output "./grphx/Nacho/Eficiencia/seleccion.png"
replot
set term x11
