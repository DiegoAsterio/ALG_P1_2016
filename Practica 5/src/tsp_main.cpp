#include <fstream>
#include <iostream>
#include <vector>
#include <chrono>
#include <cmath>
#include "TSP.h"

using namespace std;
using namespace std::chrono;


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
  high_resolution_clock::time_point t_antes, t_despues;

  if (argc<2)
  {
    cerr << "La sintaxis es <datos_input>" << endl;
    return(1);
  }

  TSP t_branch_and_bound(argv[1]);
  TSP t_vecino_mas_cercano(argv[1]);

  vector<City> v_branch_nd_bound;
  vector<City> v_vecinos_mas_cercanos;

  t_vecino_mas_cercano.TSP_vecino_mas_cercano(v_vecinos_mas_cercanos);
  double dist_total=DistanciaRecorrido(v_vecinos_mas_cercanos);

    t_antes = high_resolution_clock::now();
    t_branch_and_bound.TSP_branch_and_bound_II(v_branch_nd_bound, dist_total);
    t_despues = high_resolution_clock::now();

    ofstream f_branch_nd_bound("sol_branch_nd_bound.tsp");

    t_branch_and_bound.TSP_WriteBack(f_branch_nd_bound, v_branch_nd_bound);

  return(0);
}
