#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <climits>
#include <cassert>
#include <chrono>

using namespace std;


int& buscaPuntoDeCambio(int* v, int indice1, int indice2, int& res)
{
  int indi=(indice1+indice2)/2;
  if(v[indice1]>v[indice1+1])
  {
    res=indice1;
    return res;
  }
  else if(v[indice2]>v[indice2-1])
  {
    res=indice2;
    return res;
  }
  else if(v[indi]-v[indi-1]>0 &&  v[indi]-v[indi+1]>0)
  {
    res=indi;
    return res;
  }
  else
  {
    buscaPuntoDeCambio(v, indice1, indi, res);
    buscaPuntoDeCambio(v, indi, indice2, res);
  }

}

double uniforme()
{
double u;
  u = (double) rand();
  u = u/(double)(RAND_MAX+1.0);
 return u;
}


using namespace std;

int main(int argc, char* argv[])
{
  if(argc<2)
  {
    cout << "Falta el numero de componentes.\n";
    exit(1);
  }
  /*
  vector<int> v;
  int N=atoi(argv[1]);
  srand(time(NULL));
  int aleatorio=rand() % N, random;

  //Inicialización aleatoria del vector.
  for(int i = 0; i < N;i++)
  {
    random=0;
    if(i<aleatorio)
    {
      if(v.size()!=0)
        random=(rand()%10 + 1) + v[v.size()-1];
      else random = rand()%1000;
      v.push_back(random);
    }
    else if(i==aleatorio)
    {
      if(i==0)
        v.push_back(rand());
      else v.push_back(v[v.size()-1]+1);
    }
    else
    {
        random=v[v.size()-1] - (rand()%10 + 1);
      v.push_back(random);
    }
  }
  */

  int n = atoi(argv[1]);

  int * T = new int[n];
  assert(T);

  srand(time(0));
  double u=uniforme();
  int p=1+(int)((n-2)*u);
  T[p]=n-1;
  for (int i=0; i<p; i++) T[i]=i;
  for (int i=p+1; i<n; i++) T[i]=n-1-i+p;

  //for (int j=0; j<n; j++) {cout << T[j] << " ";}


  int res=0;
  t1=high_resolution_clock::now();
  buscaPuntoDeCambio(T,0,n-1, res);
  t2=high_resolution_clock::now();
  int punto_cambio=res;
  duration<double> transcurrido = duration_cast<duration<double> >(t2-t1);
  cout << n << " " << transcurrido.count() << "\n";

  return 0;
}
