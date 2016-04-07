#!/bin/bash
########################BURBUJA################################################
g++ -std=c++11 ./src/burbuja.cpp -o ./bin/burbuja
i=1000
echo -e "Ejecutando burbuja con tamaño maximo 30.000 a saltos de 1.000 sin optimizacion"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/burbuja $i >> ./data/$1/burbujaO0.dat
  echo -e "Iteración $i"
   ((i+=1000))
done

g++ -O1 -std=c++11 ./src/burbuja.cpp -o ./bin/burbuja
i=1000
echo -e "Ejecutando burbuja con tamaño maximo 30.000 a saltos de 1.000 con optimizacion O1"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/burbuja $i >> ./data/$1/burbujaO1.dat
  echo -e "Iteración $i"
   ((i+=1000))
done

g++ -O2 -std=c++11 ./src/burbuja.cpp -o ./bin/burbuja
i=1000
echo -e "Ejecutando burbuja con tamaño maximo 30.000 a saltos de 1.000 con optimizacion O2"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/burbuja $i >> ./data/$1/burbujaO2.dat
  echo -e "Iteración $i"
   ((i+=1000))
done

g++ -O3 -std=c++11 ./src/burbuja.cpp -o ./bin/burbuja
i=1000
echo -e "Ejecutando burbuja con tamaño maximo 30.000 a saltos de 1.000 con optimizacion O3"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/burbuja $i >> ./data/$1/burbujaO3.dat
  echo -e "Iteración $i"
   ((i+=1000))
done

############################FIBONACCI############################################
g++ -std=c++11 ./src/fibonacci.cpp -o ./bin/fibonacci
i=1
echo -e "Ejecutando fibonacci con tamaño maximo 25 a saltos de 1 sin optimizacion"
sleep 3
while [ $i -le 25 ]
do
  ./bin/fibonacci $i >> ./data/$1/fibonacciO0.dat
  echo -e "Iteración $i"
  ((i+=1))
done

g++ -O1 -std=c++11 ./src/fibonacci.cpp -o ./bin/fibonacci
i=1
echo -e "Ejecutando fibonacci con tamaño maximo 25 a saltos de 1 con optimizacion O1"
sleep 3
while [ $i -le 25 ]
do
  ./bin/fibonacci $i >> ./data/$1/fibonacciO1.dat
  echo -e "Iteración $i"
  ((i+=1))
done

g++ -O2 -std=c++11 ./src/fibonacci.cpp -o ./bin/fibonacci
i=1
echo -e "Ejecutando fibonacci con tamaño maximo 25 a saltos de 1 con optimizacion O2"
sleep 3
while [ $i -le 25 ]
do
  ./bin/fibonacci $i >> ./data/$1/fibonacciO2.dat
  echo -e "Iteración $i"
  ((i+=1))
done

g++ -O3 -std=c++11 ./src/fibonacci.cpp -o ./bin/fibonacci
i=1
echo -e "Ejecutando fibonacci con tamaño maximo 25 a saltos de 1 con optimizacion O3"
sleep 3
while [ $i -le 25 ]
do
  ./bin/fibonacci $i >> ./data/$1/fibonacciO3.dat
  echo -e "Iteración $i"
  ((i+=1))
done

######################################HEAPSORT#################################
g++ -std=c++11 ./src/heapsort.cpp -o ./bin/heapsort
i=10000
echo -e "Ejecutando heapsort con tamaño maximo 1.000.000 a saltos de 10.000 sin optimizacion"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/heapsort $i >> ./data/$1/heapsortO0.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

g++ -O1 -std=c++11 ./src/heapsort.cpp -o ./bin/heapsort
i=10000
echo -e "Ejecutando heapsort con tamaño maximo 1.000.000 a saltos de 10.000 con optimizacion O1"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/heapsort $i >> ./data/$1/heapsortO1.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

g++ -O2 -std=c++11 ./src/heapsort.cpp -o ./bin/heapsort
i=10000
echo -e "Ejecutando heapsort con tamaño maximo 1.000.000 a saltos de 10.000 con optimizacion O2"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/heapsort $i >> ./data/$1/heapsortO2.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

g++ -O3 -std=c++11 ./src/heapsort.cpp -o ./bin/heapsort
i=10000
echo -e "Ejecutando heapsort con tamaño maximo 1.000.000 a saltos de 10.000 con optimizacion O3"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/heapsort $i >> ./data/$1/heapsortO3.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

##################################INSERCION###################################
g++ -std=c++11 ./src/insercion.cpp -o ./bin/insercion
i=1000
echo -e "Ejecutando insercion con tamaño maximo 30.000 a saltos de 1.000 sin optimizacion"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/insercion $i >> ./data/$1/insercionO0.dat
  echo -e "Iteración $i"
  ((i+=1000))
done

g++ -O1 -std=c++11 ./src/insercion.cpp -o ./bin/insercion
i=1000
echo -e "Ejecutando insercion con tamaño maximo 30.000 a saltos de 1.000 con optimizacion O1"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/insercion $i >> ./data/$1/insercionO1.dat
  echo -e "Iteración $i"
  ((i+=1000))
done

g++ -O2 -std=c++11 ./src/insercion.cpp -o ./bin/insercion
i=1000
echo -e "Ejecutando insercion con tamaño maximo 30.000 a saltos de 1.000 con optimizacion O2"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/insercion $i >> ./data/$1/insercionO2.dat
  echo -e "Iteración $i"
  ((i+=1000))
done

g++ -O3 -std=c++11 ./src/insercion.cpp -o ./bin/insercion
i=1000
echo -e "Ejecutando insercion con tamaño maximo 30.000 a saltos de 1.000 con optimizacion O3"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/insercion $i >> ./data/$1/insercionO3.dat
  echo -e "Iteración $i"
  ((i+=1000))
done

##################################QUICKSORT#####################################
g++ -std=c++11 ./src/quicksort.cpp -o ./bin/quicksort
i=10000
echo -e "Ejecutando quicksort con tamaño maximo 1.000.000 a saltos de 10.000 sin optimizacion"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/quicksort $i >> ./data/$1/quicksortO0.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

g++ -O1 -std=c++11 ./src/quicksort.cpp -o ./bin/quicksort
i=10000
echo -e "Ejecutando quicksort con tamaño maximo 1.000.000 a saltos de 10.000 con optimizacion O1"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/quicksort $i >> ./data/$1/quicksortO1.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

g++ -O2 -std=c++11 ./src/quicksort.cpp -o ./bin/quicksort
i=10000
echo -e "Ejecutando quicksort con tamaño maximo 1.000.000 a saltos de 10.000 con optimizacion O2"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/quicksort $i >> ./data/$1/quicksortO2.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

g++ -O3 -std=c++11 ./src/quicksort.cpp -o ./bin/quicksort
i=10000
echo -e "Ejecutando quicksort con tamaño maximo 1.000.000 a saltos de 10.000 con optimizacion O3"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/quicksort $i >> ./data/$1/quicksortO3.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

####################################HANOI####################################
g++ -std=c++11 ./src/hanoi.cpp -o ./bin/hanoi
i=1
echo -e "Ejecutando hanoi con tamaño maximo 25 a saltos de 1 sin optimizacion"
sleep 3
while [ $i -le 25 ]
do
  ./bin/hanoi $i >> ./data/$1/hanoiO0.dat
  echo -e "Iteración $i"
  ((i+=1))
done

g++ -O1 -std=c++11 ./src/hanoi.cpp -o ./bin/hanoi
i=1
echo -e "Ejecutando hanoi con tamaño maximo 25 a saltos de 1 con optimizacion O1"
sleep 3
while [ $i -le 25 ]
do
  ./bin/hanoi $i >> ./data/$1/hanoiO1.dat
  echo -e "Iteración $i"
  ((i+=1))
done

g++ -O2 -std=c++11 ./src/hanoi.cpp -o ./bin/hanoi
i=1
echo -e "Ejecutando hanoi con tamaño maximo 25 a saltos de 1 con optimizacion O2"
sleep 3
while [ $i -le 25 ]
do
  ./bin/hanoi $i >> ./data/$1/hanoiO2.dat
  echo -e "Iteración $i"
  ((i+=1))
done

g++ -O3 -std=c++11 ./src/hanoi.cpp -o ./bin/hanoi
i=1
echo -e "Ejecutando hanoi con tamaño maximo 25 a saltos de 1 con optimizacion O3"
sleep 3
while [ $i -le 25 ]
do
  ./bin/hanoi $i >> ./data/$1/hanoiO3.dat
  echo -e "Iteración $i"
  ((i+=1))
done

############################MERGESORT##########################################
g++ -std=c++11 ./src/mergesort.cpp -o ./bin/mergesort
i=10000
echo -e "Ejecutando mergesort con tamaño maximo 1.000.000 a saltos de 10.000 sin optimizacion"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/mergesort $i >> ./data/$1/mergesortO0.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

g++ -O1 -std=c++11 ./src/mergesort.cpp -o ./bin/mergesort
i=10000
echo -e "Ejecutando mergesort con tamaño maximo 1.000.000 a saltos de 10.000 con optimizacion O1"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/mergesort $i >> ./data/$1/mergesortO1.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

g++ -O2 -std=c++11 ./src/mergesort.cpp -o ./bin/mergesort
i=10000
echo -e "Ejecutando mergesort con tamaño maximo 1.000.000 a saltos de 10.000 con optimizacion O2"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/mergesort $i >> ./data/$1/mergesortO2.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

g++ -O3 -std=c++11 ./src/mergesort.cpp -o ./bin/mergesort
i=10000
echo -e "Ejecutando mergesort con tamaño maximo 1.000.000 a saltos de 10.000 con optimizacion O3"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/mergesort $i >> ./data/$1/mergesortO3.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

###############################FLOYD############################################
g++ -std=c++11 ./src/floyd.cpp -o ./bin/floyd
i=1
echo -e "Ejecutando floyd con tamaño maximo 350 a saltos de 1 sin optimizacion"
sleep 3
while [ $i -le 350 ]
do
  ./bin/floyd $i >> ./data/$1/floydO0.dat
  echo -e "Iteración $i"
  ((i+=1))
done

g++ -O1 -std=c++11 ./src/floyd.cpp -o ./bin/floyd
i=1
echo -e "Ejecutando floyd con tamaño maximo 350 a saltos de 1 con optimizacion O1"
sleep 3
while [ $i -le 350 ]
do
  ./bin/floyd $i >> ./data/$1/floydO1.dat
  echo -e "Iteración $i"
  ((i+=1))
done

g++ -O2 -std=c++11 ./src/floyd.cpp -o ./bin/floyd
i=1
echo -e "Ejecutando floyd con tamaño maximo 350 a saltos de 1 con optimizacion O2"
sleep 3
while [ $i -le 350 ]
do
  ./bin/floyd $i >> ./data/$1/floydO2.dat
  echo -e "Iteración $i"
  ((i+=1))
done

g++ -O3 -std=c++11 ./src/floyd.cpp -o ./bin/floyd
i=1
echo -e "Ejecutando floyd con tamaño maximo 350 a saltos de 1 con optimizacion O3"
sleep 3
while [ $i -le 350 ]
do
  ./bin/floyd $i >> ./data/$1/floydO3.dat
  echo -e "Iteración $i"
  ((i+=1))
done

#################################SELECCION#####################################
g++ -std=c++11 ./src/seleccion.cpp -o ./bin/seleccion
i=1000
echo -e "Ejecutando seleccion con tamaño maximo 30.000 a saltos de 1.000 sin optimizacion"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/seleccion $i >> ./data/$1/seleccionO0.dat
  echo -e "Iteración $i"
  ((i+=1000))
done

g++ -O1 -std=c++11 ./src/seleccion.cpp -o ./bin/seleccion
i=1000
echo -e "Ejecutando seleccion con tamaño maximo 30.000 a saltos de 1.000 con optimizacion O1"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/seleccion $i >> ./data/$1/seleccionO1.dat
  echo -e "Iteración $i"
  ((i+=1000))
done

g++ -O2 -std=c++11 ./src/seleccion.cpp -o ./bin/seleccion
i=1000
echo -e "Ejecutando seleccion con tamaño maximo 30.000 a saltos de 1.000 con optimizacion O2"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/seleccion $i >> ./data/$1/seleccionO2.dat
  echo -e "Iteración $i"
  ((i+=1000))
done

g++ -O3 -std=c++11 ./src/seleccion.cpp -o ./bin/seleccion
i=1000
echo -e "Ejecutando seleccion con tamaño maximo 30.000 a saltos de 1.000 con optimizacion O3"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/seleccion $i >> ./data/$1/seleccionO3.dat
  echo -e "Iteración $i"
  ((i+=1000))
done
