#!/bin/bash

mkdir ./data
mkdir ./grphx
mkdir ./grphx/$1
mkdir ./bin
mkdir ./data/$1

g++ -std=c++11 -w ./Algoritmos/solucion_greedy_optima.cpp -o ./bin/solucion_greedy_optima
rm -f ./data/$1/solucion_greedy_optima_$1.dat
echo -e "Ejecutando la solucion greedy optima"
sleep 2
for (( i = 1; i <= 10001; i+=100 ))
do
  echo -e "Iteración número ---> $i"
  ./bin/solucion_greedy_optima $i >> ./data/$1/solucion_greedy_optima_$1.dat
done

g++ -std=c++11 -w ./Algoritmos/solucion_greedy_primera.cpp -o ./bin/solucion_greedy_primera
rm -f ./data/$1/solucion_greedy_primera$1.dat
echo -e "Ejecutando la solucion greedy primera"
sleep 2
for (( i = 1; i <= 10001; i+=100 ))
do
  echo -e "Iteración número ---> $i"
  ./bin/solucion_greedy_primera $i >> ./data/$1/solucion_greedy_primera_$1.dat
done
