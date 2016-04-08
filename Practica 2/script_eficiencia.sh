#!/bin/bash
g++ -std=c++11 ./Algoritmos/ejercicio6.cpp -o ./bin/ejercicio6
rm -f ./data/datos_algoritmo_nacho.dat
for (( i = 0; i < 10000000; i+=10000 ))
do
  echo -e "Iteración número ---> $i"
  ./bin/ejercicio6 $i >> ./data/datos_algoritmo_nacho.dat
done
