#!/bin/bash

mkdir ./data/$1

g++ -std=c++11 ./Algoritmos/ejercicio6_nacho.cpp -o ./bin/unimodal_solucion1
rm -f ./data/$1/datos_solucion1_$1.dat
for (( i = 1; i <= 3000001; i+=10000 ))
do
  echo -e "Iteración número ---> $i"
  ./bin/unimodal_solucion1 $i >> ./data/$1/datos_solucion1_$1.dat
done

g++ -std=c++11 ./Algoritmos/opcional_bruto.cpp -o ./bin/opcional_bruto
rm -f ./data/$1/datos_opcional_bruto_$1.dat
for (( i = 1; i <= 15001; i+=100 ))
do
  echo -e "Iteración número ---> $i"
  ./bin/opcional_bruto $i >> ./data/$1/datos_opcional_bruto_$1.dat
done

g++ -std=c++11 ./Algoritmos/genera_unimodal_secuencial.cpp -o ./bin/genera_unimodal_secuencial
rm -f ./data/$1/datos_genera_unimodal_secuencial_$1.dat
for (( i = 1; i <= 1000001; i+=5000 ))
do
  echo -e "Iteración número ---> $i"
  ./bin/genera_unimodal_secuencial $i >> ./data/$1/datos_genera_unimodal_secuencial_$1.dat
done

g++ -std=c++11 ./Algoritmos/Parts.cpp -o ./bin/Parts
rm -f ./data/$1/datos_Parts_$1.dat
for (( i = 1; i <= 1000001; i+=5000 ))
do
  echo -e "Iteración número ---> $i"
  ./bin/Parts $i >> ./data/$1/datos_Parts_$1.dat
done

g++ -std=c++11 ./Algoritmos/opcional_dyv.cpp -o ./bin/opcional_dyv
rm -f ./data/$1/datos_opcional_dyv_$1.dat
for (( i = 1; i <= 1000001; i+=5000 ))
do
  echo -e "Iteración número ---> $i"
  ./bin/opcional_dyv $i >> ./data/$1/datos_opcional_dyv_$1.dat
done

gnuplot ./grafica_$1.gp
