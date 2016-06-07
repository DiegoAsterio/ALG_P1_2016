#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <climits>
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
  Ciudad(short int c, float c_x, float c_y)
  {
    ciudad = c;
    coord_x = c_x;
    coord_y = c_y;
  }
  Ciudad& operator=(Ciudad& c)
  {
    ciudad=c.ciudad;
    coord_y = c.coord_y;
    coord_x = c.coord_x;
    return *this;
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

double Distancia(int x0, int x1, int y0, int y1)
{
    double n = sqrt(pow(x1-x0,2) + pow(y1-y0,2));
    return n;
}

double suma(list<int> rama, double* afinidades,int n){
	double sum=0;
	list<int>::iterator it;
	list<int>::iterator next_it;
	for(it=rama.begin(); it!=prev(rama.end());++it){
		next_it=it;
		++next_it;
		sum += afinidades[(*it)*n+(*(next_it))];
	}
	sum+= afinidades[(*(rama.begin()))*n+(*(prev(rama.end())))];
	return sum;
}

list<int> BacktrackingTSP(list<int> rama, double* afinidades, list<int> sinusar,double& minima_suma, int n, double& cont, double& total)
{
  int tam = sinusar.size();
  double sum=suma(rama,afinidades,n);
  if(tam <= 1 && minima_suma>sum && sum>0){
    rama.splice(rama.end(),sinusar);
    minima_suma=sum;
    return rama;
  }else{
    list<int>::iterator it;
    list<int> res;
    list<int> aux2;
    for(it = sinusar.begin(); it != sinusar.end(); ++it){
      int aux = *it;
      it = sinusar.erase(it);
      rama.push_back(aux);
      aux2 = BacktrackingTSP(rama, afinidades, sinusar,minima_suma, n, cont, total);
      if(aux2.size() != 0){
        res = aux2;
      }
      it = sinusar.emplace(it,aux);
      rama.remove(aux);
    }
    return res;
  }

}

void WriteBack(ofstream& os, vector<Ciudad> sol)
{
  os << "DIMENSION: " << sol.size() << endl;
  for(int i = 1;i<=(int)sol.size();++i)
  {
    os << sol[i-1].ciudad << " " << sol[i-1].coord_x << " " << sol[i-1].coord_y << endl;
  }
}

int main(int argc, char* argv[])
{

  if(argc<3)
  {
    cout << "Hay que introducir el fichero de entrada <arg1> y el fichero de salida <arg2>" << endl;
    exit(1);
  }

  vector<Ciudad> mapa;
  list<int> sol;
  LeeFichero(argv[1], mapa);
  int n=(int)mapa.size();
  double distancia_recorrido=INT_MAX;
	double* afinidades = new double[n*n];
	list<int> rama ;
	list<int> sinusar ;
	for(int i = 0; i < n; i++){
		sinusar.push_back(i);
		for(int j = i; j < n; j++){
			afinidades[i*n+j] = afinidades[j*n+i] = Distancia(mapa[i].coord_x,mapa[j].coord_x,mapa[i].coord_y, mapa[j].coord_y);
			if(i == j)
				afinidades[i*n+i] = 0;
		}
	}
  rama.push_back(0);
	sinusar.pop_front();


  double cont=0;
  double total=1;
  for(int i = 0; i < n;++i)
    total*=n;

  sol = BacktrackingTSP(rama, afinidades, sinusar, distancia_recorrido, n, cont, total);
  cout << "El tamaño del recorrido es: " << distancia_recorrido << endl;
  ofstream f(argv[2]);
  vector<Ciudad> recorrido;
  for(list<int>::iterator it=sol.begin();it!=sol.end();++it)
  {
    recorrido.push_back(Ciudad(mapa[*it].ciudad, mapa[mapa[*it].ciudad-1].coord_x, mapa[mapa[*it].ciudad-1].coord_y));
  }
  WriteBack(f,recorrido);
}
