
################ VARIOS AJUSTES SIMULTANEOS ############################

######## GRAFICA BURBUJA ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Diego/burbujaO0.dat" via l0,l1
fit cuadratica(x) "./data/Diego/burbujaO0.dat" via c0,c1,c2
fit cubica(x) "./data/Diego/burbujaO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Diego/burbujaO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Diego/burbujaO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", nlogaritmica(x) title "n*log(n)", "./data/Diego/burbujaO0.dat" lt rgb "gold" title "Burbuja"

set term png
set output "./grphx/Diego/Ajustes/burbuja.png"
replot
set term x11

######## GRAFICA FIBONACCI ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Diego/fibonacciO0.dat" via l0,l1
fit cuadratica(x) "./data/Diego/fibonacciO0.dat" via c0,c1,c2
fit cubica(x) "./data/Diego/fibonacciO0.dat" via r0,r1,r2,r3
fit f(x) "./data/Diego/fibonacciO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Diego/fibonacciO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", f(x) title "2-exponencial",nlogaritmica(x) title "n*log(n)", "./data/Diego/fibonacciO0.dat" lt rgb "gold" title "Fibonacci"

set term png
set output "./grphx/Diego/Ajustes/fibonacci.png"
replot
set term x11

######## GRAFICA FLOYD ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Diego/floydO0.dat" via l0,l1
fit cuadratica(x) "./data/Diego/floydO0.dat" via c0,c1,c2
fit cubica(x) "./data/Diego/floydO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Diego/floydO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Diego/floydO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", nlogaritmica(x) title "n*log(n)", "./data/Diego/floydO0.dat" lt rgb "gold" title "Foyd"

set term png
set output "./grphx/Diego/Ajustes/floyd.png"
replot
set term x11

######## GRAFICA HANOI ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Diego/hanoiO0.dat" via l0,l1
fit cuadratica(x) "./data/Diego/hanoiO0.dat" via c0,c1,c2
fit cubica(x) "./data/Diego/hanoiO0.dat" via r0,r1,r2,r3
fit f(x) "./data/Diego/hanoiO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Diego/hanoiO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", f(x) title "2-exponencial", nlogaritmica(x) title "n*log(n)", "./data/Diego/hanoiO0.dat" lt rgb "gold" title "Hanoi"

set term png
set output "./grphx/Diego/Ajustes/hanoi.png"
replot
set term x11

######## GRAFICA HEAPSORT ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Diego/heapsortO0.dat" via l0,l1
fit cuadratica(x) "./data/Diego/heapsortO0.dat" via c0,c1,c2
fit cubica(x) "./data/Diego/heapsortO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Diego/heapsortO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Diego/heapsortO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", nlogaritmica(x) title "n*log(n)", "./data/Diego/heapsortO0.dat" lt rgb "gold" title "Heapsort"

set term png
set output "./grphx/Diego/Ajustes/heapsort.png"
replot
set term x11

######## GRAFICA INSERCION ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Diego/insercionO0.dat" via l0,l1
fit cuadratica(x) "./data/Diego/insercionO0.dat" via c0,c1,c2
fit cubica(x) "./data/Diego/insercionO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Diego/insercionO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Diego/insercionO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", nlogaritmica(x) title "n*log(n)", "./data/Diego/insercionO0.dat" lt rgb "gold" title "Insercion"

set term png
set output "./grphx/Diego/Ajustes/insercion.png"
replot
set term x11

######## GRAFICA MERGESORT ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
#cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Diego/mergesortO0.dat" via l0,l1
fit cuadratica(x) "./data/Diego/mergesortO0.dat" via c0,c1,c2
#fit cubica(x) "./data/Diego/mergesortO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Diego/mergesortO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Diego/mergesortO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", nlogaritmica(x) title "n*log(n)", "./data/Diego/mergesortO0.dat" lt rgb "gold" title "Mergesort"

set term png
set output "./grphx/Diego/Ajustes/mergesort.png"
replot
set term x11

######## GRAFICA QUICKSORT ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
#cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Diego/quicksortO0.dat" via l0,l1
fit cuadratica(x) "./data/Diego/quicksortO0.dat" via c0,c1,c2
#fit cubica(x) "./data/Diego/quicksortO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Diego/quicksortO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Diego/quicksortO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", nlogaritmica(x) title "n*log(n)", "./data/Diego/quicksortO0.dat" lt rgb "gold" title "Quicksort"

set term png
set output "./grphx/Diego/Ajustes/quicksort.png"
replot
set term x11

######## GRAFICA SELECCION ###########
lineal(x) = l0*x + l1
cuadratica(x) = c0*x**2 + c1*x + c2
cubica(x) = r0*x**3 + r1*x**2 + r2*x + r3
#f(x) = e0*(2**(e1*x + e2)) + e3
nlogaritmica(x) = n0*x*log(n1*x) + n2

fit lineal(x) "./data/Diego/seleccionO0.dat" via l0,l1
fit cuadratica(x) "./data/Diego/seleccionO0.dat" via c0,c1,c2
fit cubica(x) "./data/Diego/seleccionO0.dat" via r0,r1,r2,r3
#fit f(x) "./data/Diego/seleccionO0.dat" via e0,e1,e2,e3
fit nlogaritmica(x) "./data/Diego/seleccionO0.dat" via n0,n1,n2
plot lineal(x) title "Lineal", cuadratica(x) title "Cuadratica", cubica(x) title "Cubica", nlogaritmica(x) title "n*log(n)", "./data/Diego/seleccionO0.dat" lt rgb "gold" title "Seleccion"

set term png
set output "./grphx/Diego/Ajustes/seleccion.png"
replot
set term x11

##################### COMPARACION OPTIMIZACIONES #############################

######## GRAFICA BURBUJA ###########
cuadratica0(x) = c0*x**2 + c1*x + c2
cuadratica1(x) = c3*x**2 + c4*x + c5
cuadratica2(x) = c6*x**2 + c7*x + c8
cuadratica3(x) = c9*x**2 + c10*x + c11
fit cuadratica0(x) "./data/Diego/burbujaO0.dat" via c0,c1,c2
fit cuadratica1(x) "./data/Diego/burbujaO1.dat" via c3,c4,c5
fit cuadratica2(x) "./data/Diego/burbujaO2.dat" via c6,c7,c8
fit cuadratica3(x) "./data/Diego/burbujaO3.dat" via c9,c10,c11
plot "./data/Diego/burbujaO0.dat" lt rgb "gold" title "BurbujaO0", "./data/Diego/burbujaO1.dat" lt rgb "gold" title "BurbujaO1", "./data/Diego/burbujaO2.dat" lt rgb "gold" title "BurbujaO2", "./data/Diego/burbujaO3.dat" lt rgb "gold" title "BurbujaO3", cuadratica0(x) title "Cuadrática O0", cuadratica1(x) title "Cuadrática O1", cuadratica2(x) title "Cuadrática O2", cuadratica3(x) title "Cuadrática O3"

set term png
set output "./grphx/Diego/Eficiencia/burbuja.png"
replot
set term x11

######## GRAFICA FIBONACCI ###########
f0(x) = e0*(2**(e1*x + e2)) + e3
f1(x) = e4*(2**(e5*x + e6)) + e7
f2(x) = e8*(2**(e9*x + e10)) + e11
f3(x) = e12*(2**(e13*x + e14)) + e15

fit f0(x) "./data/Diego/fibonacciO0.dat" via e0,e1,e2,e3
fit f1(x) "./data/Diego/fibonacciO1.dat" via e4,e5,e6,e7
fit f2(x) "./data/Diego/fibonacciO2.dat" via e8,e9,e10,e11
fit f3(x) "./data/Diego/fibonacciO3.dat" via e12,e13,e14,e15
plot "./data/Diego/fibonacciO0.dat" lt rgb "gold" title "FibonacciO0", "./data/Diego/fibonacciO1.dat" lt rgb "gold" title "FibonacciO1", "./data/Diego/fibonacciO2.dat" lt rgb "gold" title "FibonacciO2", "./data/Diego/fibonacciO3.dat" lt rgb "gold" title "FibonacciO3", f0(x) title "2-exponencial O0", f1(x) title "2-exponencial O1", f2(x) title "2-exponencial O2", f3(x) title "2-exponencial O3"

set term png
set output "./grphx/Diego/Eficiencia/fibonacci.png"
replot
set term x11

######## GRAFICA FLOYD ###########
cubica0(x) = r0*x**3 + r1*x**2 + r2*x + r3
cubica1(x) = r4*x**3 + r5*x**2 + r6*x + r7
cubica2(x) = r8*x**3 + r9*x**2 + r10*x + r11
cubica3(x) = r12*x**3 + r13*x**2 + r14*x + r15


fit cubica0(x) "./data/Diego/floydO0.dat" via r0,r1,r2,r3
fit cubica1(x) "./data/Diego/floydO1.dat" via r4,r5,r6,r7
fit cubica2(x) "./data/Diego/floydO2.dat" via r8,r9,r10,r11
fit cubica3(x) "./data/Diego/floydO3.dat" via r12,r13,r14,r15
plot "./data/Diego/floydO0.dat" lt rgb "gold" title "FloydO0", "./data/Diego/floydO1.dat" lt rgb "gold" title "FloydO1", "./data/Diego/floydO2.dat" lt rgb "gold" title "FloydO2", "./data/Diego/floydO3.dat" lt rgb "gold" title "FloydO3", cubica0(x) title "Cubica O0", cubica1(x) title "Cubica O1", cubica2(x) title "Cubica O2", cubica3(x) title "Cubica O3"

set term png
set output "./grphx/Diego/Eficiencia/floyd.png"
replot
set term x11

######## GRAFICA HANOI ###########
f0(x) = e0*(2**(e1*x + e2)) + e3
f1(x) = e4*(2**(e5*x + e6)) + e7
f2(x) = e8*(2**(e9*x + e10)) + e11
f3(x) = e12*(2**(e13*x + e14)) + e15

fit f0(x) "./data/Diego/hanoiO0.dat" via e0,e1,e2,e3
fit f1(x) "./data/Diego/hanoiO1.dat" via e4,e5,e6,e7
fit f2(x) "./data/Diego/hanoiO2.dat" via e8,e9,e10,e11
fit f3(x) "./data/Diego/hanoiO3.dat" via e12,e13,e14,e15
plot "./data/Diego/hanoiO0.dat" lt rgb "gold" title "HanoiO0", "./data/Diego/hanoiO1.dat" lt rgb "gold" title "HanoiO1", "./data/Diego/hanoiO2.dat" lt rgb "gold" title "HanoiO2", "./data/Diego/hanoiO3.dat" lt rgb "gold" title "HanoiO3", f0(x) title "2-exponencial O0", f1(x) title "2-exponencial O1", f2(x) title "2-exponencial O2", f3(x) title "2-exponencial O3"

set term png
set output "./grphx/Diego/Eficiencia/hanoi.png"
replot
set term x11

######## GRAFICA HEAPSORT ###########
nlogaritmica0(x) = n0*x*log(n1*x)
nlogaritmica1(x) = n2*x*log(n3*x)
nlogaritmica2(x) = n4*x*log(n5*x)
nlogaritmica3(x) = n6*x*log(n7*x)


fit nlogaritmica0(x) "./data/Diego/heapsortO0.dat" via n0,n1
fit nlogaritmica1(x) "./data/Diego/heapsortO1.dat" via n2,n3
fit nlogaritmica2(x) "./data/Diego/heapsortO2.dat" via n4,n5
fit nlogaritmica3(x) "./data/Diego/heapsortO3.dat" via n6,n7
plot "./data/Diego/heapsortO0.dat" lt rgb "gold" title "HeapsortO0", "./data/Diego/heapsortO1.dat" lt rgb "gold" title "HeapsortO1", "./data/Diego/heapsortO2.dat" lt rgb "gold" title "HeapsortO2", "./data/Diego/heapsortO3.dat" lt rgb "gold" title "HeapsortO3", nlogaritmica0(x) title "nlog(n) O0", nlogaritmica1(x) title "nlog(n) O1", nlogaritmica2(x) title "nlog(n) O2", nlogaritmica3(x) title "nlog(n) O3"

set term png
set output "./grphx/Diego/Eficiencia/heapsort.png"
replot
set term x11

######## GRAFICA INSERCION ###########
cuadratica0(x) = c0*x**2 + c1*x + c2
cuadratica1(x) = c3*x**2 + c4*x + c5
cuadratica2(x) = c6*x**2 + c7*x + c8
cuadratica3(x) = c9*x**2 + c10*x + c11
fit cuadratica0(x) "./data/Diego/insercionO0.dat" via c0,c1,c2
fit cuadratica1(x) "./data/Diego/insercionO1.dat" via c3,c4,c5
fit cuadratica2(x) "./data/Diego/insercionO2.dat" via c6,c7,c8
fit cuadratica3(x) "./data/Diego/insercionO3.dat" via c9,c10,c11
plot "./data/Diego/insercionO0.dat" lt rgb "gold" title "InsercionO0", "./data/Diego/insercionO1.dat" lt rgb "gold" title "InsercionO1", "./data/Diego/insercionO2.dat" lt rgb "gold" title "InsercionO2", "./data/Diego/insercionO3.dat" lt rgb "gold" title "InsercionO3", cuadratica0(x) title "Cuadrática O0", cuadratica1(x) title "Cuadrática O1", cuadratica2(x) title "Cuadrática O2", cuadratica3(x) title "Cuadrática O3"

set term png
set output "./grphx/Diego/Eficiencia/insercion.png"
replot
set term x11

######## GRAFICA MERGESORT ###########
nlogaritmica0(x) = n0*x*log(n1*x)
nlogaritmica1(x) = n2*x*log(n3*x)
nlogaritmica2(x) = n4*x*log(n5*x)
nlogaritmica3(x) = n6*x*log(n7*x)


fit nlogaritmica0(x) "./data/Diego/mergesortO0.dat" via n0,n1
fit nlogaritmica1(x) "./data/Diego/mergesortO1.dat" via n2,n3
fit nlogaritmica2(x) "./data/Diego/mergesortO2.dat" via n4,n5
fit nlogaritmica3(x) "./data/Diego/mergesortO3.dat" via n6,n7
plot "./data/Diego/mergesortO0.dat" lt rgb "gold" title "MergesortO0", "./data/Diego/mergesortO1.dat" lt rgb "gold" title "MergesortO1", "./data/Diego/mergesortO2.dat" lt rgb "gold" title "MergesortO2", "./data/Diego/mergesortO3.dat" lt rgb "gold" title "MergesortO3", nlogaritmica0(x) title "nlog(n) O0", nlogaritmica1(x) title "nlog(n) O1", nlogaritmica2(x) title "nlog(n) O2", nlogaritmica3(x) title "nlog(n) O3"

set term png
set output "./grphx/Diego/Eficiencia/mergesort.png"
replot
set term x11

######## GRAFICA QUICKSORT ###########
nlogaritmica0(x) = n0*x*log(n1*x)
nlogaritmica1(x) = n2*x*log(n3*x)
nlogaritmica2(x) = n4*x*log(n5*x)
nlogaritmica3(x) = n6*x*log(n7*x)


fit nlogaritmica0(x) "./data/Diego/quicksortO0.dat" via n0,n1
fit nlogaritmica1(x) "./data/Diego/quicksortO1.dat" via n2,n3
fit nlogaritmica2(x) "./data/Diego/quicksortO2.dat" via n4,n5
fit nlogaritmica3(x) "./data/Diego/quicksortO3.dat" via n6,n7
plot "./data/Diego/quicksortO0.dat" lt rgb "gold" title "QuicksortO0", "./data/Diego/quicksortO1.dat" lt rgb "gold" title "QuicksortO1", "./data/Diego/quicksortO2.dat" lt rgb "gold" title "QuicksortO2", "./data/Diego/quicksortO3.dat" lt rgb "gold" title "QuicksortO3", nlogaritmica0(x) title "nlog(n) O0", nlogaritmica1(x) title "nlog(n) O1", nlogaritmica2(x) title "nlog(n) O2", nlogaritmica3(x) title "nlog(n) O3"

set term png
set output "./grphx/Diego/Eficiencia/quicksort.png"
replot
set term x11

######## GRAFICA SELECCION ###########
cuadratica0(x) = c0*x**2 + c1*x + c2
cuadratica1(x) = c3*x**2 + c4*x + c5
cuadratica2(x) = c6*x**2 + c7*x + c8
cuadratica3(x) = c9*x**2 + c10*x + c11
fit cuadratica0(x) "./data/Diego/seleccionO0.dat" via c0,c1,c2
fit cuadratica1(x) "./data/Diego/seleccionO1.dat" via c3,c4,c5
fit cuadratica2(x) "./data/Diego/seleccionO2.dat" via c6,c7,c8
fit cuadratica3(x) "./data/Diego/seleccionO3.dat" via c9,c10,c11
plot "./data/Diego/seleccionO0.dat" lt rgb "gold" title "SeleccionO0", "./data/Diego/seleccionO1.dat" lt rgb "gold" title "SeleccionO1", "./data/Diego/seleccionO2.dat" lt rgb "gold" title "SeleccionO2", "./data/Diego/seleccionO3.dat" lt rgb "gold" title "SeleccionO3", cuadratica0(x) title "Cuadrática O0", cuadratica1(x) title "Cuadrática O1", cuadratica2(x) title "Cuadrática O2", cuadratica3(x) title "Cuadrática O3"

set term png
set output "./grphx/Diego/Eficiencia/seleccion.png"
replot
set term x11
