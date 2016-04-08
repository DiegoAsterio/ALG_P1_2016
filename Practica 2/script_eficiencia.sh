#!/bin/bash
g++ -std=c++11 ./Algoritmos/ejercicio6_nacho.cpp -o ./bin/ejercicio6_nacho
rm -f ./data/datos_algoritmo_nacho.dat
for (( i = 0; i < 3000000; i+=10000 ))
do
  echo -e "Iteración número ---> $i"
  ./bin/ejercicio6_nacho $i >> ./data/datos_algoritmo_nacho.dat
done
