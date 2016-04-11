#!/bin/bash

g++ -std=c++11 ./Algoritmos/ejercicio6_nacho.cpp -o ./bin/unimodal_solucion1
rm -f ./data/$1/datos_solucion1_$1.dat
for (( i = 0; i < 3000000; i+=10000 ))
do
  echo -e "Iteración número ---> $i"
  ./bin/unimodal_solucion1 $i >> ./data/$1/datos_solucion1_$1.dat
done

gnuplot ./grafica_$1.gp
