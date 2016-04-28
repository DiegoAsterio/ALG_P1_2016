#!/bin/bash

mkdir ./data
mkdir ./grphx
mkdir ./grphx/$1
mkdir ./bin
mkdir ./data/$1

g++ -std=c++11 -w ./Algoritmos/solucion_no_greedy.cpp -o ./bin/solucion_no_greedy
rm -f ./data/$1/solucion_no_greedy_$1.dat
echo -e "Ejecutando la solucion no greedy"
sleep 2
for (( i = 0; i <= 10000; i+=100 ))
do
  echo -e "Iteración número ---> $i"
  ./bin/solucion_no_greedy $i >> ./data/$1/solucion_no_greedy_$1.dat
done

g++ -std=c++11 -w ./Algoritmos/solucion_greedy_primera.cpp -o ./bin/solucion_greedy_primera
rm -f ./data/$1/solucion_greedy_primera$1.dat
echo -e "Ejecutando la solucion greedy primera"
sleep 2
for (( i = 0; i <= 10000; i+=100 ))
do
  echo -e "Iteración número ---> $i"
  ./bin/solucion_greedy_primera $i >> ./data/$1/solucion_greedy_primera$1.dat
done
