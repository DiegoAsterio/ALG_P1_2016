#!/bin/bash
#Burbuja
mkdir ./datos
g++ -std=gnu++0x burbuja.cpp -o burbuja
i=1000
echo -e "Ejecutando burbuja con tamaño maximo 30.000 a saltos de 1.000"
sleep 3
while [ $i -le 30000 ]
do
  ./burbuja $i >> ./datos/burbuja.dat
  echo -e "Iteración $i"
   ((i+=1000))
done

#Fibonacci
g++ -std=gnu++0x fibonacci.cpp -o fibonacci
i=1
echo -e "Ejecutando fibonacci con tamaño maximo 45 a saltos de 1"
sleep 3
while [ $i -le 45 ]
do
  ./fibonacci $i >> ./datos/fibonacci.dat
  echo -e "Iteración $i"
  ((i+=1))
done

#heapsort
g++ -std=gnu++0x heapsort.cpp -o heapsort
i=10000
echo -e "Ejecutando heapsort con tamaño maximo 1.000.000 a saltos de 10.000"
sleep 3
while [ $i -le 1000000 ]
do
  ./heapsort $i >> ./datos/heapsort.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

#insercion
g++ -std=gnu++0x insercion.cpp -o insercion
i=1000
echo -e "Ejecutando insercion con tamaño maximo 30.000 a saltos de 1.000"
sleep 3
while [ $i -le 30000 ]
do
  ./insercion $i >> ./datos/insercion.dat
  echo -e "Iteración $i"
  ((i+=1000))
done

#quicksort
g++ -std=gnu++0x quicksort.cpp -o quicksort
i=10000
echo -e "Ejecutando quicksort con tamaño maximo 1.000.000 a saltos de 10.000"
sleep 3
while [ $i -le 1000000 ]
do
  ./quicksort $i >> ./datos/quicksort.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

#hanoi
g++ -std=gnu++0x hanoi.cpp -o hanoi
i=1
echo -e "Ejecutando hanoi con tamaño maximo 25 a saltos de 1"
sleep 3
while [ $i -le 25 ]
do
  ./hanoi $i >> ./datos/hanoi.dat
  echo -e "Iteración $i"
  ((i+=1))
done

#mergesort
g++ -std=gnu++0x mergesort.cpp -o mergesort
i=10000
echo -e "Ejecutando mergesort con tamaño maximo 1.000.000 a saltos de 10.000"
sleep 3
while [ $i -le 1000000 ]
do
  ./mergesort $i >> ./datos/mergesort.dat
  echo -e "Iteración $i"
  ((i+=10000))
done

#floyd
g++ -std=gnu++0x floyd.cpp -o floyd
i=1
echo -e "Ejecutando floyd con tamaño maximo 350 a saltos de 1"
sleep 3
while [ $i -le 350 ]
do
  ./floyd $i >> ./datos/floyd.dat
  echo -e "Iteración $i"
  ((i+=1))
done

#seleccion
g++ -std=gnu++0x seleccion.cpp -o seleccion
i=1000
echo -e "Ejecutando seleccion con tamaño maximo 30.000 a saltos de 1.000"
sleep 3
while [ $i -le 30000 ]
do
  ./seleccion $i >> ./datos/seleccion.dat
  echo -e "Iteración $i"
  ((i+=1000))
done
