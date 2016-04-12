#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>

//generador de ejemplos para el problema de la comparaci�n de preferencias. Simplemente se genera una permutaci�n aleatoria del vector 0,1,2,...,n-2,n-1

double uniforme() //Genera un n�mero uniformemente distribuido en el
                  //intervalo [0,1) a partir de uno de los generadores
                  //disponibles en C.
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}

int CuentaIntercambios(int* v, int tam)
{
  int inter=0;
  for(int i=0;i<tam;i++)
  {
    for(int j = i; j < tam;j++)
    {
      if(v[i]<v[j])
      {
        int aux=v[i];
        v[i] = v[j];
        v[j] = aux;
        inter++;
      }
    }
  }
}

using namespace std::chrono;


int main(int argc, char * argv[])
{
  high_resolution_clock::time_point t1, t2;

  if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

  int n = atoi(argv[1]);

  int * T = new int[n];
  assert(T);

  srand(time(0));

  for (int j=0; j<n; j++) T[j]=j;
  //algoritmo de random shuffling the Knuth (permutaci�n aleatoria)
  for (int j=n-1; j>0; j--) {
     double u=uniforme();
     int k=(int)(j*u);
     int tmp=T[j];
     T[j]=T[k];
     T[k]=tmp;
  }
  //for (int j=0; j<n; j++) {cout << T[j] << " ";}
  //cout << endl;

  t1=high_resolution_clock::now();
  int valor = CuentaIntercambios(T,n);
  t2=high_resolution_clock::now();
  duration<double> transcurrido = duration_cast<duration<double> >(t2-t1);
  cout << n << " " << transcurrido.count() << endl;


}
