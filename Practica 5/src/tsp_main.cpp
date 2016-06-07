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
  chrono::high_resolution_clock::time_point t_antes, t_despues;

  if (argc<2)
  {
    cerr << "La sintaxis es <datos_input>" << endl;
    return(1);
  }

  TSP t_branch_and_bound(argv[1]);

  vector<City> v_branch_nd_bound;

    t_antes = chrono::high_resolution_clock::now();
    t_branch_and_bound.TSP_branch_and_bound(v_branch_nd_bound);
    t_despues = chrono::high_resolution_clock::now();

    ofstream f_branch_nd_bound("sol_branch_nd_bound.tsp");

    t_branch_and_bound.TSP_WriteBack(f_branch_nd_bound, v_branch_nd_bound);

  return(0);
}
