#include <fstream>
#include <iostream>
#include <vector>
#include "TSP.h"

using namespace std;

int main(int argc, char* argv[])
{
  if (argc<3)
  {
    cerr << "La sintaxis es <datos_input> <solucion_output>" << endl;
    exit(1);
  }

  TSP t_vecino_mas_cercano(argv[1]), t_triangles(argv[1]), t_random_swap(argv[1]);
  vector<City> v_vecino_mas_cercano, v_triangles, v_random_swap;
  t_vecino_mas_cercano.TSP_vecino_mas_cercano(v_vecino_mas_cercano);
  t_triangles.TSP_triangles(v_triangles);
  t_random_swap.TSP_RandomSwap(50,v_random_swap);
  string output(argv[2]);
  ofstream f_vecino_mas_cercano(output+"_vecino_mas_cercano.tsp");
  ofstream f_triangles(output+"_triangles.tsp");
  ofstream f_random_swap(output+"_random_swap.tsp");
  t_vecino_mas_cercano.TSP_WriteBack(f_vecino_mas_cercano, v_vecino_mas_cercano);
  t_triangles.TSP_WriteBack(f_triangles, v_triangles);
  t_random_swap.TSP_WriteBack(f_random_swap, v_random_swap);

  exit(0);
}
