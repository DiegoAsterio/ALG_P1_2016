#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <chrono>

//generador de ejemplos para el problema de la comparaci�n de preferencias. Simplemente se genera una permutaci�n aleatoria del vector 0,1,2,...,n-2,n-1

double uniforme()
{
 int t = rand();
 double f = ((double)RAND_MAX+1.0);
 return (double)t/f;
}

inline static void mergesort(int T[], int num_elem);

static void mergesort_lims(int T[], int inicial, int final);

inline static void insercion(int T[], int num_elem);

static void insercion_lims(int T[], int inicial, int final);

static void fusion(int T[], int inicial, int final, int U[], int V[]);


inline static void insercion(int T[], int num_elem)
{
  insercion_lims(T, 0, num_elem);
}


static void insercion_lims(int T[], int inicial, int final)
{
  int i, j;
  int aux;
  for (i = inicial + 1; i < final; i++) {
    j = i;
    while ((T[j] < T[j-1]) && (j > 0)) {
      aux = T[j];
      T[j] = T[j-1];
      T[j-1] = aux;
      j--;
    };
  };
}


const int UMBRAL_MS = 100;

void CuentaIntercambiosDYV(int T[], int num_elem, int& contador)
{
  mergesort_lims(T, 0, num_elem);
}

static void mergesort_lims(int T[], int inicial, int final, int& contador)
{
    int k = (final - inicial)/2;

    int * U = new int [k - inicial + 1];
    assert(U);
    int l, l2;
    for (l = 0, l2 = inicial; l < k; l++, l2++)
	     U[l] = T[l2];
    U[l] = INT_MAX;

    int * V = new int [final - k + 1];
    assert(V);
    for (l = 0, l2 = k; l < final - k; l++, l2++)
	     V[l] = T[l2];
    V[l] = INT_MAX;

    mergesort_lims(U, 0, k);
    mergesort_lims(V, 0, final - k);
    fusion(T, inicial, final, U, V);
    delete [] U;
    delete [] V;
}


static void fusion(int T[], int inicial, int final, int U[], int V[], int& contador)
{
  int j = 0;
  int k = 0;
  for (int i = inicial; i < final; i++)
    {
      if (U[j] < V[k]) {
	       T[i] = U[j];
	        j++;
      }
      else{
	       T[i] = V[k];
	        k++;
      };
    };
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
