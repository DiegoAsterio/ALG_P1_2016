#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>

using namespace std;



int main(int argc, char*argv[])
{
  if(argc<2)
  {
    cout << "El formato es <numero comensales>" << endl;
    exit(1);
  }

  //Inicialización de la matriz de adyacencia de comensales.

  int num_comensales = atoi(argv[1]);
  short int** matriz_adyacencia = new short int*[num_comensales];
  for(int i = 0; i < num_comensales;++i)
    matriz_adyacencia[i] = new short int[num_comensales];

  //Rellenando la maatriz de adyacencia.

  srand(time(NULL));
  for(int i = 0; i < num_comensales; ++i)
    for(int j = 0; j < num_comensales; ++j)
      matriz_adyacencia[i][j] = rand() % 101;

  

}
