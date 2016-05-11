#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include "TSP.h"
#include <omp.h>

using namespace std;

double distancia2(int x0, int x1, int y0, int y1)
{
    double n = sqrt(pow(x1-x0,2) + pow(y1-y0,2));
    return n;
}

double DistanciaRecorrido(vector<City>& vec)
{
  double dist = 0;
  for(int i = 0; i < (int)vec.size()-1;++i)
  {
    dist+=distancia2(vec[i].coord_x, vec[i+1].coord_x, vec[i].coord_y, vec[i+1].coord_y);
  }
  return dist;
}

int main(int argc, char* argv[])
{
  if (argc<2)
  {
    cerr << "La sintaxis es <datos_input>" << endl;
    return(1);
  }

  vector<City> v_vecino_mas_cercano, v_triangles, v_random_swap, v_dijsktra;

  #pragma omp parallel
  {
    #pragma omp sections
    {
      #pragma omp section
      {
        TSP t_vecino_mas_cercano(argv[1]);
        t_vecino_mas_cercano.TSP_vecino_mas_cercano(v_vecino_mas_cercano);
        ofstream f_vecino_mas_cercano("sol_vecino_mas_cercano.tsp");
        t_vecino_mas_cercano.TSP_WriteBack(f_vecino_mas_cercano, v_vecino_mas_cercano);
      }
      #pragma omp section
      {
        TSP t_random_swap(argv[1]);
        t_random_swap.TSP_RandomSwap(10000,v_random_swap);
        ofstream f_random_swap("sol_random_swap.tsp");
        t_random_swap.TSP_WriteBack(f_random_swap, v_random_swap);
      }
      #pragma omp section
      {
        TSP t_triangles(argv[1]);
        t_triangles.TSP_triangles(v_triangles);
        ofstream f_triangles("sol_triangles.tsp");
        t_triangles.TSP_WriteBack(f_triangles, v_triangles);
      }
      #pragma omp section
      {
        TSP t_dijsktra(argv[1]);
        t_dijsktra.Dijsktra(v_dijsktra);
        ofstream f_dijsktra("sol_dijsktra.tsp");
        t_dijsktra.TSP_WriteBack(f_dijsktra, v_dijsktra);
      }
    }
  }
  cout << "Distancia vecino mas cercano: " << DistanciaRecorrido(v_vecino_mas_cercano) << endl;
  cout << "Distancia random swap: " << DistanciaRecorrido(v_random_swap) << endl;
  cout << "Distancia triangles: " << DistanciaRecorrido(v_triangles) << endl;
  cout << "Distancia Dijsktra: " << DistanciaRecorrido(v_dijsktra) << endl;

  return(0);
}
