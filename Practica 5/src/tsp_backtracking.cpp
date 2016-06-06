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

/*void CreaArbol(vector<Ciudad> mapa, Nodo* arbol)
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
}*/

double Distancia(int x0, int x1, int y0, int y1)
{
    double n = sqrt(pow(x1-x0,2) + pow(y1-y0,2));
    return n;
}

/*void RellenaMap(map<float, vector<Ciudad> >& recorridos, Nodo* arbol, vector<Ciudad>& rec, float distancia=0, int nhijo=0)
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
      if(sig->hermano_der!=0)
      {
        ++nhijo;
        actual = sig->hermano_der;
        RellenaMap(recorridos, actual, rec, distancia, nhijo);
      }
      else nhijo=0;
    }
    else
    {
      actual=sig;
      RellenaMap(recorridos, actual, rec, distancia, nhijo);
    }
  }
}*/

double suma(list<int> rama, double* afinidades,int n){
	int sum=0;
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

list<int> BacktrackingTSP(list<int> rama, double* afinidades, list<int> sinusar,double& minima_suma, int n, long long int& cont, double& total)
{
  if(cont%1000000==0) cout << cont << " --- " << total << endl;
  ++cont;
  int tam = sinusar.size();
  if(tam <= 1){
    rama.splice(rama.end(),sinusar);
    double sum=suma(rama,afinidades,n);
    if(minima_suma>sum && sum>0)
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
	for(int i = 0; i < n; i++){		// Rellena afinidades
		sinusar.push_back(i);
		for(int j = i; j < n; j++){
			afinidades[i*n+j] = afinidades[j*n+i] = Distancia(mapa[i].coord_x,mapa[j].coord_x,mapa[i].coord_y, mapa[j].coord_y);
			if(i == j)
				afinidades[i*n+i] = 0;  // La afinidad contigo mismo es 0, si.
		}
	}
  rama.push_back(0);
	sinusar.pop_front();


  long long int cont=0;
  double total=1;
  for(int i = 0; i < n;++i)
    total*=n;

  sol = BacktrackingTSP(rama, afinidades, sinusar, distancia_recorrido, n, cont, total);
  cout << "El tamaño del recorrido es: " << distancia_recorrido << endl;
  ofstream f(argv[2]);
  vector<Ciudad> recorrido;
  for(list<int>::iterator it=sol.begin();it!=sol.end();++it)
  {
    recorrido.push_back(Ciudad(mapa[*it].ciudad, mapa[*it].coord_x, mapa[*it].coord_y));
  }
  WriteBack(f,recorrido);
}
