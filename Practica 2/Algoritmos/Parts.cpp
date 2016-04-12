#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <mach/mach_time.h>
#include <cstdio>
#include <chrono>

int &  rift_lims(int* arr, int beg, int end, int & res){

  int N = end - beg;

  if (N  == 1) {
    res = beg;
    return arr[beg];
  }
  else if (arr [beg + N/2 - 1] < arr [end - 1])
    return rift_lims(arr, beg + N/2 , end, res);
  else
    return rift_lims(arr,beg, beg + N/2, res);
}

int rift(int * arr, int n, int & res){

  int beg = 0, end = n;

  return rift_lims(arr,beg,end,res);
}

double uniforme()
{
double u;
  u = (double) rand();
  u = u/(double)(RAND_MAX+1.0);
 return u;
}

int main(int argc, char * argv[])
{

  if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

  int n = atoi(argv[1]);

  int * T = new int[n];
  assert(T);

  srand(mach_absolute_time());
  double u=uniforme();
  int p=1+(int)((n-2)*u);
  T[p]=n-1;
  for (int i=0; i<p; i++) T[i]=i;
  for (int i=p+1; i<n; i++) T[i]=n-1-i+p;

#ifdef _PRINT_IT_
  cout << "El vector generado es:" << endl;
  for (int j=0; j<n; j++) {cout << T[j] << " ";}
  cout << endl;
#endif

int res=0;
std::chrono::high_resolution_clock::time_point t1, t2;

t1=std::chrono::high_resolution_clock::now();
rift(T,n,res);
t2=std::chrono::high_resolution_clock::now();
int punto_cambio=res;

std::chrono::duration<double> transcurrido = std::chrono::duration_cast<std::chrono::duration<double> >(t2-t1);
cout << n << " " << transcurrido.count() << "\n";

#ifdef _PRINT_IT_
cout << endl << "La posicion en la que cambia la monotonia es: " << punto_cambio << endl ;
#endif
}
