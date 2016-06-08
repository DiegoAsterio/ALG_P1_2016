#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <climits>
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
  Ciudad& operator=(const Ciudad& c)
  {
    ciudad=c.ciudad;
    coord_y = c.coord_y;
    coord_x = c.coord_x;
    return *this;
  }
  bool operator==(const Ciudad c)
  {
    if(ciudad == c.ciudad && coord_x == c.coord_x && coord_y == c.coord_y)
      return true;
    return false;
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

list<int> BacktrackingTSP(list<int> rama, double* afinidades, list<int> sinusar,double& minima_suma, int n)
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
      aux2 = BacktrackingTSP(rama, afinidades, sinusar,minima_suma, n);
      if(aux2.size() != 0){
        res = aux2;
      }
      it = sinusar.emplace(it,aux);
      rama.remove(aux);
    }
    return res;
  }

}

vector<Ciudad>::iterator menorDistancia(Ciudad c, vector<Ciudad>& candidatos)
{
    vector<Ciudad>::iterator it=candidatos.begin(), min_iter = it;
    double min;
    double n;
    min=Distancia(c.coord_x,(*it).coord_x,c.coord_y,(*it).coord_y);
    ++it;
    while(it!=candidatos.end())
    {
        n=Distancia(c.coord_x,(*it).coord_x,c.coord_y,(*it).coord_y);
        if(n<min)
        {
            min=n;
            min_iter = it;
        }
        ++it;
    }

    return min_iter;

}

void TSP_vecino_mas_cercano(vector<Ciudad>& solucion, vector<Ciudad>& ciudades)
{

  solucion.push_back(ciudades[0]);

  vector<Ciudad> candidatos(ciudades);
  candidatos.erase(candidatos.begin());

  while((int)solucion.size() < (int)ciudades.size())
  {
    vector<Ciudad>::iterator it = menorDistancia(solucion.at(solucion.size()-1), candidatos);
    solucion.push_back(*it);
    candidatos.erase(it);
  }
}

double DistanciaRecorrido(list<Ciudad>& lista)
{
  double dist = 0;
  for(list<Ciudad>::iterator i = lista.begin(); i !=lista.end();++i)
  {
    list<Ciudad>::iterator sig=i;
    ++sig;
    dist+=Distancia(i->coord_x, sig->coord_x, i->coord_y, sig->coord_y);
  }
  return dist;
}

double DistanciaRecorrido(vector<Ciudad>& vec)
{
  double dist = 0;
  for(int i = 0; i < (int)vec.size()-1;++i)
  {
    dist+=Distancia(vec[i].coord_x, vec[i+1].coord_x, vec[i].coord_y, vec[i+1].coord_y);
  }
  return dist;
}

list<Ciudad> BranchGredy(list<Ciudad> rama, list<Ciudad> sinusar, double &cota)
{
  if(DistanciaRecorrido(rama) >= cota){     // Si la afinidad perdida es más grande que la afinidad
  	list<Ciudad> res;						 // perdida en la mejor distribucion hasta el momento, men,
  	res.clear();						 // desiste del tema.
  	return res;
  }else{
  	int tam = sinusar.size();
    double dis_rama = DistanciaRecorrido(rama);
  	if(tam <= 1 && dis_rama>0){			// Si queda una persona por sentar, men, has llegado
  		rama.splice(rama.end(),sinusar);
  		cota = dis_rama;
  		return rama;
  	}else{
  		list<Ciudad>::iterator it;
  		list<Ciudad> res;
  		list<Ciudad> aux2;
  		for(it = sinusar.begin(); it != sinusar.end(); it++){	// Crea una rama por cada persona que no este sentada
  			Ciudad aux = *it;
  			it = sinusar.erase(it);
  			rama.push_back(aux);
  			aux2 = BranchGredy(rama, sinusar, cota);
  			if(aux2.size() != 0){
  				res = aux2;
  			}
  			it = sinusar.emplace(it,aux);
  			rama.remove(aux);
  		}
  		return res;
  	}
  }
}

double BranchNBound(vector<Ciudad> mapa, vector<Ciudad>& solucion)
{
  vector<Ciudad> sol;
  TSP_vecino_mas_cercano(sol, mapa);
  double cota = DistanciaRecorrido(sol);
  list<Ciudad> rama_inicial;
  list<Ciudad> sinusar;
  rama_inicial.push_back(mapa[0]);
  for(int i = 1; i < (int)mapa.size();++i)
    sinusar.push_back(mapa[i]);
  cout << cota << endl;
  list<Ciudad> solucion_lista = BranchGredy(rama_inicial, sinusar, cota);
  for(list<Ciudad>::iterator it = solucion_lista.begin(); it!=solucion_lista.end();++it)
    solucion.push_back(*it);
  return DistanciaRecorrido(solucion);
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
  vector<Ciudad> solucion;
  LeeFichero(argv[1], mapa);

  double distancia = BranchNBound(mapa, solucion);
  cout << "La distancia es de: " << distancia << endl;

  ofstream f(argv[2]);
  WriteBack(f,solucion);
}
