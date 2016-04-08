#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <climits>
#include <cassert>
#include <chrono>

using namespace std;


int& buscaPuntoDeCambio(vector<int> v, int indice1, int indice2, int& res)
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

using namespace std::chrono;

int main(int argc, char* argv[])
{
  high_resolution_clock::time_point t1, t2;
  if(argc<2)
  {
    cout << "Falta el numero de componentes.\n";
    exit(1);
  }
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

  int res=0;
  t1=high_resolution_clock::now();
  buscaPuntoDeCambio(v,0,N-1, res);
  t2=high_resolution_clock::now();
  int punto_cambio=res;
  duration<double> transcurrido = duration_cast<duration<double> >(t2-t1);
  cout << N << " " << transcurrido.count() << "\n";

  return 0;
}
