#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <time.h>
#include <list>
#include <chrono>

using namespace std;

void ColocaComensales(short int** matriz, int n_comensales, list<int>& resultado_final)
{
  //Recorro la lista de resultados para ver el mejor lugar para insertar el siguiente comensal.
  //El índice i es el comensal actual y el j es el que recorre la lista resultado_final.
  for(int i = 0; i < n_comensales; ++i)
  {
    list<int>::iterator mejor_posicion = resultado_final.begin();
    int mejor_afinidad = 0;

    for(list<int>::iterator iter = resultado_final.begin(); iter != resultado_final.end(); ++iter)
    {

      //Hallo el iterador de antes de end.
      list<int>::iterator antes_end = resultado_final.begin();
      for(list<int>::iterator iter2 = resultado_final.begin(); iter2!=resultado_final.end(); ++iter2)
      {
        list<int>::iterator aux = iter2;
        ++aux;
        if(aux!=resultado_final.end())
          antes_end = aux;
      }

      //Asigno los pesos de cada comensal para sus acompañantes a izquierdas y derechas.
      //La lista la considero circular, el primero esta al lado del último y viceversa.
      int afinidad_izq = 0, afinidad_der = 0;
      if(iter == resultado_final.begin() || iter == antes_end)
      {
        list<int>::iterator aux = iter;
        ++aux;
        afinidad_izq = matriz[i][*iter];
        afinidad_der = (aux!=resultado_final.end())?matriz[i][*aux]:matriz[i][resultado_final.front()];
      }
      else
      {
        list<int>::iterator aux = iter;
        ++aux;
        afinidad_izq = matriz[i][*iter];
        afinidad_der = matriz[i][*aux];
      }

      //Cambio mejor afinidad y mejor posicion si he encontrado un lugar mejor donde insertar;
      int puntuacion = afinidad_der + afinidad_izq;
      if(puntuacion>mejor_afinidad)
      {
        mejor_posicion = iter;
        mejor_afinidad = puntuacion;
      }
      if(puntuacion==200)
        break;
    }

    resultado_final.insert(mejor_posicion,i);
  }
}

using namespace std::chrono;

int main(int argc, char*argv[])
{

  if(argc<2)
  {
    cout << "El formato es <numero comensales>" << endl;
    exit(1);
  }

  //Inicialización de la matriz de adyacencia de comensales.

  int num_comensales = atoi(argv[1]);
  short int** matriz_adyacencia = new short int*[num_comensales];
  for(int i = 0; i < num_comensales;++i)
    matriz_adyacencia[i] = new short int[num_comensales];

  //Rellenando la maatriz de adyacencia. La afinidad con uno mismo es 0 para
  //evitar una colocación trivial.

  srand(time(NULL));
  for(int i = 0; i < num_comensales; ++i)
    for(int j = i; j < num_comensales; ++j)
    {
      if(j==i)
        matriz_adyacencia[i][j]=0;
      else
        matriz_adyacencia[i][j] = rand() % 101;
    }

  for(int i = 0; i < num_comensales; ++i)
    for(int j = i; j < num_comensales; ++j)
    {
      if(j==i)
        matriz_adyacencia[j][i]=0;
      else
        matriz_adyacencia[j][i] = matriz_adyacencia[i][j];
    }

  //Resolución del problema.
  high_resolution_clock::time_point t_antes, t_despues;
  list<int> mesa_comensales;
  t_antes = high_resolution_clock::now();
  ColocaComensales(matriz_adyacencia,num_comensales,mesa_comensales);
  t_despues = high_resolution_clock::now();

/*  cout << "Matrizz de adyacencia:" << endl;
  for(int i = 0; i < num_comensales;i++)
  {
    for(int j = 0; j < num_comensales;j++)
    {
      cout << matriz_adyacencia[i][j] << " ";
    }
    cout << endl;
  }
  cout << "Orden de comensales:" << endl;
  for(list<int>::iterator it = mesa_comensales.begin();it!=mesa_comensales.end();++it)
    cout << *it << " ";
  cout << endl;*/

  duration<double> transcurrido = duration_cast<duration<double> >(t_despues-t_antes);
  cout << num_comensales << " " << transcurrido.count() << "\n";

}
