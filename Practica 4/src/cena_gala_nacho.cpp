#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <list>

using namespace std;

list<short int>& ColocaComensales(short int** matriz, int n_comensales)
{
  list<short int> resultado_final;
  //Recorro la lista de resultados para ver el mejor lugar para insertar el siguiente comensal.
  //El índice i es el comensal actual y el j es el que recorre la lista resultado_final.
  for(int i = 0; i < n_comensales; ++i)
  {
    int mejor_posicion = 0;
    int mejor_afinidad = 0;
    for(int j = 0; j < (int)resultado_final.size(); ++j)
    {
      int afinidad_izq = 0, afinidad_der = 0;
      if(j == 0)
      {
        afinidad_izq = 100;
        afinidad_der = ((int)resultado_final.size()==1)?100:matriz[i][j];
      }
      else if (j == (int)resultado_final.size()-1)
      {
        afinidad_izq = ((int)resultado_final.size()==1)?100:matriz[i][j];
        afinidad_der = 100;
      }
      else
      {
        afinidad_izq = matriz[i][resultado_final[j]];
        afinidad_der = matriz[i][resultado_final[j+1]];
      }
    }
  }
  return resultado_final;
}

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

  //Resolución del problema.



}
