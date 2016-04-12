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

int CuentaIntercambiosDYV(int* v, int tam, int& contador)
{
  if(tam==2)
  {
    if(v[0]>v[1])
      contador++;
  }
  else if(tam==3)
  {
    if(v[0]>v[1])
      contador++;
    if(v[0]>v[2])
      contador++;
    if(v[1]>v[2])
      contador++;
  }
  else
  {
    int* v1 = new int [tam/2];
    int* v2 = new int [(tam%2!=0)?tam/2 + 1:tam/2];
    for(int i = 0; i < tam;i++)
    {
      if(i<tam/2)
        v1[i]=v[i];
      else if(i>=tam/2)
        v2[i]=v[i];
    }
    CuentaIntercambiosDYV(v1,tam/2,contador);
    CuentaIntercambiosDYV(v2,tam/2,contador);
    return contador;
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

  int contador=0;

  t1=high_resolution_clock::now();
  CuentaIntercambiosDYV(T,n,contador);
  t2=high_resolution_clock::now();
  duration<double> transcurrido = duration_cast<duration<double> >(t2-t1);
  cout << n << " " << transcurrido.count() << endl;


}
