#!/bin/bash
g++ -std=c++11 ./Algoritmos/genera-unimodal_secuencial.cpp -o ./bin/genera-unimodal_secuencial
rm -f ./data/datos_algoritmo_luis.dat
for (( i = 1; i < 3000001; i+=10000 ))
do
  echo -e "Iteración número ---> $i"
  ./bin/genera-unimodal_secuencial $i >> ./data/datos_algoritmo_luis.dat
done

gnuplot ./grafica_luis.gp
