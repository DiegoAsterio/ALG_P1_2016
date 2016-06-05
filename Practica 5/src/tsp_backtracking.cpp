#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <time.h>
#include <map>
#include <list>
#include <chrono>

using namespace std;
using namespace std::chrono;

struct Ciudad
{
  float coord_x, coord_y;
  short int ciudad;

  Ciudad()
  {
    ciudad = 0;
    coord_x = 0;
    coord_y = 0;
  }
};

struct Nodo
{
  Ciudad actual;
  Nodo* hijo_izq;
  Nodo* hermano_der;

  Nodo()
  {
    hijo_izq=hermano_der=0;
  }
  Nodo(Ciudad c, Nodo* hijo, Nodo* hermano)
  {
    actual = c;
    hijo_izq = hijo;
    hermano_der = hermano;
  }
};

void LeeFichero(char* nombre, vector<Ciudad>& mapa)
{
  bool first=true;
  ifstream archivo(nombre);
  string linea;
  double num;
  if(archivo.fail())
      cerr << "I couldn't open the file" << endl;
  else{
      while(!archivo.eof())
      {
          if(first)
          {
              getline(archivo,linea);
              linea.erase(linea.begin(),linea.begin()+10);
              first=false;
          }
          Ciudad c;
          archivo >> num;
          c.ciudad = num;
          archivo >> num;
          c.coord_x = num;
          archivo >> num;
          c.coord_y = num;
          mapa.push_back(c);
          getline(archivo,linea);
      }
  }
  mapa.pop_back();
  archivo.close();
}

void CreaArbol(vector<Ciudad> mapa, Nodo* arbol)
{
  //Crea el arbol con todas las posibilidades.
  Nodo* actual=arbol;
  for(int i = 0; i < (int)mapa.size()-1; ++i)
  {
    vector<Ciudad> param(mapa);
    if(i==0)
    {
      actual->hijo_izq = new Nodo(mapa[i],0,0);
      actual = actual->hijo_izq;
      param.erase(param.begin());
      CreaArbol(param, actual);
    }
    else
    {
      actual->hermano_der = new Nodo(mapa[i],0,0);
      actual = actual->hermano_der;
      param.erase(param.begin()+i);
      CreaArbol(param, actual);
    }
  }
}

double Distancia(int x0, int x1, int y0, int y1)
{
    double n = sqrt(pow(x1-x0,2) + pow(y1-y0,2));
    return n;
}

void RellenaMap(map<float, vector<Ciudad> >& recorridos, Nodo* arbol, vector<Ciudad>& rec, float distancia=0, int nhijo=0)
{
  Nodo* actual = arbol;
  rec.push_back(actual->actual);
  while(actual->hijo_izq !=0 && actual->hermano_der !=0)
  {
    Nodo* sig=actual->hijo_izq;
    for(int i = 0; i < nhijo;++i)
      sig=sig->hermano_der;
    distancia+=Distancia(actual->actual.coord_x, sig->actual.coord_x, actual->actual.coord_y, sig->actual.coord_y);

    if(sig->hijo_izq==0)
    {
      recorridos.insert(recorridos.begin(), pair<double,vector<Ciudad> >(distancia, rec));
      ++nhijo;
    }
    else
    {
      actual=sig;
      RellenaMap(recorridos, actual, rec, distancia, nhijo);
    }
  }
}

double BacktrackingTSP(vector<Ciudad> mapa, vector<Ciudad>& sol)
{
  vector<Ciudad> copia_mapa(mapa);
  Nodo* arbol = new Nodo(mapa[0],0,0);
  mapa.erase(mapa.begin());
  CreaArbol(mapa,arbol);

  map<float, vector<Ciudad> > recorridos;
  vector<Ciudad> aux;
  RellenaMap(recorridos, arbol, aux);
  for(int i=0; i < (int)(recorridos.begin())->second.size();++i)
    cout << (recorridos.begin())->second[i].ciudad << " " << (recorridos.begin())->second[i].coord_x << " " << (recorridos.begin())->second[i].coord_y << endl;
  sol=(recorridos.begin())->second;
  return recorridos.begin()->first;
}

int main(int argc, char* argv[])
{

  if(argc<3)
  {
    cout << "Hay que introducir el fichero de entrada <arg1> y el fichero de salida <arg2>" << endl;
    exit(1);
  }

  vector<Ciudad> mapa, sol;
  LeeFichero(argv[1], mapa);
  int tam_recorrido = BacktrackingTSP(mapa, sol);
  cout << "El tamaño del recorrido es: " << tam_recorrido << endl;
}
