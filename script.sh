#!/bin/bash
#Burbuja

i=1000
echo -e "Ejecutando burbuja con tamaño maximo 30.000 a saltos de 1.000"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/burbuja $i >> ./data/$1/burbuja.dat
  echo -e "Iteración $i"
   ((i+=1000))
done

#Fibonacci

i=1
echo -e "Ejecutando fibonacci con tamaño maximo 45 a saltos de 1"
sleep 3
while [ $i -le 45 ]
do
  ./bin/fibonacci $i >> ./data/$1/fibonacci.dat
  echo -e "Iteración $i"
  ((i+=1))
done

#heapsort

i=10000
echo -e "Ejecutando heapsort con tamaño maximo 1.000.000 a saltos de 10.000"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/heapsort $i >> ./data/$1/heapsort.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

#insercion

i=1000
echo -e "Ejecutando insercion con tamaño maximo 30.000 a saltos de 1.000"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/insercion $i >> ./data/$1/insercion.dat
  echo -e "Iteración $i"
  ((i+=1000))
done

#quicksort

i=10000
echo -e "Ejecutando quicksort con tamaño maximo 1.000.000 a saltos de 10.000"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/quicksort $i >> ./data/$1/quicksort.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

#hanoi

i=1
echo -e "Ejecutando hanoi con tamaño maximo 25 a saltos de 1"
sleep 3
while [ $i -le 25 ]
do
  ./bin/hanoi $i >> ./data/$1/hanoi.dat
  echo -e "Iteración $i"
  ((i+=1))
done

#mergesort

i=10000
echo -e "Ejecutando mergesort con tamaño maximo 1.000.000 a saltos de 10.000"
sleep 3
while [ $i -le 1000000 ]
do
  ./bin/mergesort $i >> ./data/$1/mergesort.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

#floyd

i=1
echo -e "Ejecutando floyd con tamaño maximo 350 a saltos de 1"
sleep 3
while [ $i -le 350 ]
do
  ./bin/floyd $i >> ./data/$1/floyd.dat
  echo -e "Iteración $i"
  ((i+=1))
done

#seleccion

i=1000
echo -e "Ejecutando seleccion con tamaño maximo 30.000 a saltos de 1.000"
sleep 3
while [ $i -le 30000 ]
do
  ./bin/seleccion $i >> ./data/$1/seleccion.dat
  echo -e "Iteración $i"
  ((i+=1000))
done
