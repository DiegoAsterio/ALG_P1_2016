#include <iostream>
#include <vector>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <climits>
#include <cassert>
#include <chrono>
#include <algorithm>

using namespace std;

double uniforme(double lim=0, double max=0)
{
  double u;
  if(lim==0 && max==0)
  {
    u = (int) rand();
    u = u/(int)(RAND_MAX+1.0);
    return u;
  }
  else
  {
    if(lim<max && lim!=0)
    {
      u = (int) rand()%(int)(lim*(RAND_MAX+1));
      u = u/(int)(RAND_MAX+1.0);
      return u;
    }
    else
    {
      u = (int) rand()%(int)(max*(RAND_MAX+1));
      u = u/(int)(RAND_MAX+1.0);
      return u;
    }
  }
}

void SolucionNoGreedy(vector<int>& tam, vector<double>& pesos)
{
  vector<double> multiplicacion;
  for(int i = 0; i < (int)tam.size();i++)
  {
    multiplicacion.push_back(tam[i]*pesos[i]);
  }
  for(int i = 0; i < (int)multiplicacion.size();i++)
  {
    int min = i;
    for(int j = i; j < (int)multiplicacion.size();j++)
    {
      if(multiplicacion[min]>multiplicacion[j])
        min=j;
    }
    double aux, mul;
    int aux2;
    aux2=tam[min];
    aux=pesos[min];
    mul = multiplicacion[min];
    multiplicacion[min] = multiplicacion[i];
    multiplicacion[i] = mul;
    tam[min] = tam[i];
    pesos[min] = pesos[i];
    tam[i] = aux2;
    pesos[i] = aux;
  }
}

using namespace std::chrono;

int main(int argc, char* argv[])
{
  high_resolution_clock::time_point t_antes, t_despues;
  if(argc<2)
  {
    cout << "La sintaxis es <num_programas>" << endl;
    exit(1);
  }
  srand(time(0));
  int num_programas = atoi(argv[1]);

  //Generación de tamaños
  vector<int> tam_programas;
  for(int i = 0;i < num_programas;++i)
    tam_programas.push_back(rand()%1000000);

  //Generación de pesos uniformemente distribuidos
  vector<double> pesos;
  if(num_programas!=1)
    pesos.push_back(uniforme(0,(double)2/num_programas));
  else
    pesos.push_back(1);
  double suma = pesos[0];
  for(int i = 1; i < num_programas;++i)
  {
    double a;
    if(i==num_programas-1)
    {
      a=1-suma;
    }
    else
    {
      a=uniforme(1-suma,(double)2/num_programas);
    }
    pesos.push_back(a);
    suma+=a;
  }

  //Barajamos los dos vectores
  random_shuffle(pesos.begin(),pesos.end());
  random_shuffle(tam_programas.begin(),tam_programas.end());

  t_antes = high_resolution_clock::now();
  SolucionNoGreedy(tam_programas,pesos);
  t_despues = high_resolution_clock::now();

  duration<double> transcurrido = duration_cast<duration<double> >(t_despues-t_antes);
  cout << num_programas << " " << transcurrido.count() << "\n";

  return(0);

}
