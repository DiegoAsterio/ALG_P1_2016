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


void solucionGreedy(vector<int>& tam, vector<double>& pesos)
{
  std::vector<int> aux1;
  std::vector<double> aux2;

  while (! tam.empty()) {
    size_t index = 0;
    for (size_t i = 0; i < tam.size(); i++) {
      if(tam[i]*pesos[i]<tam[index]*pesos[index])
        index = i;
    }

    aux1.push_back(tam[index]);
    aux2.push_back(pesos[index]);

    tam.erase(tam.begin()+index);
    pesos.erase(pesos.begin()+index);
  }
  tam = aux1;
  pesos = aux2;
}

void fill_weighs(vector<double> & v, int n)
{
  vector<double> aux;

  srand(time(0));

  for (size_t i = 0; i < n; i++) {
    aux.push_back(rand()/2);
  }

  double sum = 0;

  for (size_t i = 0; i < n; i++) {
    sum += aux[i];
  }

  for (size_t i = 0 ; i < n ; ++i){
    v.push_back(aux[i]/sum);
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
  fill_weighs(pesos,num_programas);

  //Barajamos los dos vectores
  random_shuffle(pesos.begin(),pesos.end());
  random_shuffle(tam_programas.begin(),tam_programas.end());

  t_antes = high_resolution_clock::now();
  solucionGreedy(tam_programas,pesos);
  t_despues = high_resolution_clock::now();
  
  duration<double> transcurrido = duration_cast<duration<double> >(t_despues-t_antes);
  cout << num_programas << " " << transcurrido.count() << "\n";

  return(0);

}
