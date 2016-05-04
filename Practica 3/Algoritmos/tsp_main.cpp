#include <fstream>
#include <iostream>
#include <vector>
#include <cmath>
#include "TSP.h"

using namespace std;

double distancia2(int x0, int x1, int y0, int y1)
{
    double n = sqrt(pow(x1-x0,2) + pow(y1-y0,2));
    return n;
}

int main(int argc, char* argv[])
{
  if (argc<2)
  {
    cerr << "La sintaxis es <datos_input>" << endl;
    return(1);
  }

  TSP t_vecino_mas_cercano(argv[1]), t_triangles(argv[1]), t_random_swap(argv[1]), t_dijsktra(argv[1]);

  vector<City> v_vecino_mas_cercano, v_triangles, v_random_swap, v_dijsktra;

  t_vecino_mas_cercano.TSP_vecino_mas_cercano(v_vecino_mas_cercano);
  t_triangles.TSP_triangles(v_triangles);
  t_dijsktra.Dijsktra(v_dijsktra);
  t_random_swap.TSP_RandomSwap(1000,v_random_swap);

  ofstream f_vecino_mas_cercano("sol_vecino_mas_cercano.tsp");
  ofstream f_triangles("sol_triangles.tsp");
  ofstream f_random_swap("sol_random_swap.tsp");
  ofstream f_dijsktra("sol_dijsktra.tsp");


  t_vecino_mas_cercano.TSP_WriteBack(f_vecino_mas_cercano, v_vecino_mas_cercano);
  t_triangles.TSP_WriteBack(f_triangles, v_triangles);
  t_random_swap.TSP_WriteBack(f_random_swap, v_random_swap);
  t_dijsktra.TSP_WriteBack(f_dijsktra, v_dijsktra);


  double dist = 0;
  for(int i = 0; i < (int)v_random_swap.size()-1;++i)
  {
    dist+=distancia2(v_random_swap[i].coord_x, v_random_swap[i+1].coord_x, v_random_swap[i].coord_y, v_random_swap[i+1].coord_y);
  }
  cout << "Distancia random swap: " << dist << endl;

  dist = 0;
  for(int i = 0; i < (int)v_vecino_mas_cercano.size()-1;++i)
  {
    dist+=distancia2(v_vecino_mas_cercano[i].coord_x, v_vecino_mas_cercano[i+1].coord_x, v_vecino_mas_cercano[i].coord_y, v_vecino_mas_cercano[i+1].coord_y);
  }
  cout << "Distancia vecino mas cercano: " << dist << endl;

  dist = 0;
  for(int i = 0; i < (int)v_triangles.size()-1;++i)
  {
    dist+=distancia2(v_triangles[i].coord_x, v_triangles[i+1].coord_x, v_triangles[i].coord_y, v_triangles[i+1].coord_y);
  }
  cout << "Distancia triangles: " << dist << endl;

  dist = 0;
  for(int i = 0; i < (int)v_dijsktra.size()-1;++i)
  {
    dist+=distancia2(v_dijsktra[i].coord_x, v_dijsktra[i+1].coord_x, v_dijsktra[i].coord_y, v_dijsktra[i+1].coord_y);
  }
  cout << "Distancia dijsktra: " << dist << endl;

  return(0);
}
