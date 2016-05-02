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

int dividir(vector<double>& mul, vector<int>& tam, vector<double>& pesos, int inicio, int fin)
{
  int izq;
  int der;
  int pibote;
  int temp;

  pibote = mul[inicio];
  izq = inicio;
  der = fin;

  //Mientras no se cruzen los índices
  while (izq < der){
    while (mul[der] > pibote){
	  der--;
    }

	while ((izq < der) && (mul[izq] <= pibote)){
      izq++;
    }

    // Si todavia no se cruzan los indices seguimos intercambiando
	if(izq < der){
      temp= mul[izq];
      mul[izq] = mul[der];
      mul[der] = temp;

      temp= tam[izq];
      tam[izq] = tam[der];
      tam[der] = temp;

      temp= pesos[izq];
      pesos[izq] = pesos[der];
      pesos[der] = temp;
    }
  }

  //Los indices ya se han cruzado, ponemos el pivote en el lugar que le corresponde
  temp = mul[der];
  mul[der] = mul[inicio];
  mul[inicio] = temp;

  temp = tam[der];
  tam[der] = tam[inicio];
  tam[inicio] = temp;

  temp = pesos[der];
  pesos[der] = pesos[inicio];
  pesos[inicio] = temp;

  //La nueva posición del pivote
  return der;
}

void quicksort(vector<double>& mul, vector<int>& tam, vector<double>& pesos, int inicio, int fin)
{
  int pivote;
  if(inicio < fin)
  {
    pivote = dividir(mul, tam, pesos, inicio, fin );
    quicksort( mul, tam, pesos, inicio, pivote - 1 );//ordeno la lista de los menores
    quicksort( mul, tam, pesos, pivote + 1, fin );//ordeno la lista de los mayores
  }
}

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
  quicksort(multiplicacion, tam, pesos, 0, (int)multiplicacion.size()-1);
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
