#include <fstream>
#include <cstdlib>
#include <vector>
#include <utility>
#include <climits>
#include <iostream>
#include <cmath>
#include "TSP.h"

using namespace std;


double distancia(int x0, int x1, int y0, int y1)
{
    double n = sqrt(pow(x1-x0,2) + pow(y1-y0,2));
    return n;
}

vector<City>::iterator TSP::menorDistancia(City c, vector<City>& candidatos)
{
    vector<City>::iterator it=candidatos.begin(), min_iter = it;
    double min;
    double n;
    min=distancia(c.coord_x,(*it).coord_x,c.coord_y,(*it).coord_y);
    ++it;
    while(it!=candidatos.end())
    {
        n=distancia(c.coord_x,(*it).coord_x,c.coord_y,(*it).coord_y);
        if(n<min)
        {
            min=n;
            min_iter = it;
        }
        ++it;
    }

    return min_iter;

}

TSP::TSP(char* cadena)
{
    bool first=true;
    ifstream archivo(cadena);
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
                nCiudades=atoi(linea.c_str());
            }
            City c;
            archivo >> num;
            c.ciudad = num;
            archivo >> num;
            c.coord_x = num;
            archivo >> num;
            c.coord_y = num;
            ciudades.push_back(c);
            getline(archivo,linea);
        }
    }
    ciudades.pop_back();
    archivo.close();
}
/*
City& City::operator=(const City& other){
  if(this != &other){
    this->ciudad = other.ciudad;
    this->coord_x = other.coord_x;
    this->coord_y = other.coord_y;
  }
  return *this;
}
*/
void TSP::TSP_vecino_mas_cercano(vector<City>& solucion)
{

  solucion.push_back(ciudades[0]);

  vector<City> candidatos(ciudades);
  candidatos.erase(candidatos.begin());

  while((int)solucion.size() < nCiudades)
  {
    vector<City>::iterator it = menorDistancia(solucion.at(solucion.size()-1), candidatos);
    solucion.push_back(*it);
    candidatos.erase(it);
  }
}

void TSP::find_max(){
  std::vector<pair<int,int> > ret (ciudades.size());
  for (auto i : ret){
    i.second = 0;
  }

  for (size_t i = 0; i < ciudades.size(); i++) {
    ret[i].first = ciudades[i].ciudad;
    for (size_t j = 0; j < ciudades.size(); j++) {
      double aux  = distancia(ciudades[i].coord_x,ciudades[i].coord_y,ciudades[j].coord_x,ciudades[j].coord_y);
      if(ret[i].second<aux)
        ret[i].second = aux;
    }
  }

  max_dist = ret;
}

double TSP::afinidad(std::vector<City> v){
  int ret = 0;

  for (size_t i = 0; i < v.size() - 1; i++)
    ret += distancia(v[i].coord_x,v[i].coord_y,v[i+1].coord_x,v[i+i].coord_y);

  return ret;
}

double TSP::peso(std::vector<City> cit){
  double ret = 0;
  vector<City> v = noEstan(cit);
  for (size_t i = 0; i < v.size(); i++) {
    for (size_t j = 0; j < max_dist.size(); j++) {
      if (max_dist[i].first == v[i].ciudad){
        ret += max_dist[i].second;
        j = max_dist.size(); //TERMINO EL BUCLE
      }
    }
  }
  return ret;
}

std::vector<City> TSP::noEstan(std::vector<City> v){
  vector<City> ret ;
  bool noencontrado;
  for (size_t i = 0; i < ciudades.size(); i++) {
    noencontrado = true;
    for (size_t j = 0; j < v.size(); j++) {
      if(ciudades[i].ciudad == v[i].ciudad){
        noencontrado = false;
      }
    }
    if (noencontrado)
      ret.push_back(ciudades[i]);
  }
  return ret;
}

vector<City> TSP::bestChoice(mypq_type prior){
  if (prior.top().size() == ciudades.size()) {
    return prior.top();
  }
  else{
    vector<City> mejores = prior.top();
		prior.pop();
		std::vector<City> nuevosElementos = noEstan(mejores);

		for (auto i : nuevosElementos) {
		  std::vector<City> aux (mejores);
		  aux.push_back(i);
		  prior.push(aux);
		}
		return bestChoice(prior);
  }
}

void TSP::branch_engine_start(vector<City>& solucion){

  std::function<bool(std::vector<City>&, std::vector<City>&)> comp = [this](std::vector<City>& a, std::vector<City>& b) -> bool {return this->afinidad(a) + this->peso(a) > this->afinidad(b) + this->peso(b);};
	mypq_type prior(comp);

  std::vector<City> aux(2);
	aux[0] = ciudades[0];
	for (int i = 1 ; i<ciudades.size() ; ++i){
	  aux[1] = ciudades[i];
	  prior.push(aux);
	}

  solucion = bestChoice(prior);
}

void TSP::TSP_branch_and_bound(vector<City>& solucion){

  find_max();

  branch_engine_start(solucion);
}

vector<City> TSP::branch_with_greedy(mypq_type prior,double media){
  if (prior.top().size() == ciudades.size()) {
    return prior.top();
  }
  else{
    vector<City> mejores = prior.top();
		prior.pop();
		std::vector<City> nuevosElementos = noEstan(mejores); //ES LA QUE DA POR CULO N^2

		for (auto i : nuevosElementos) {
		  std::vector<City> aux (mejores);
		  aux.push_back(i);
      if (afinidad(aux)/aux.size() <= media)
        prior.push(aux);
		}
		return bestChoice(prior);
  }
}

void TSP::TSP_branch_and_bound_II(vector<City>& solucion, double dist_total){

  double media = dist_total/solucion.size();

  std::function<bool(std::vector<City>&, std::vector<City>&)> comp = [this](std::vector<City>& a, std::vector<City>& b) -> bool {return this->afinidad(a)/b.size()  > this->afinidad(b)/b.size() ;};
	mypq_type prior(comp);

  std::vector<City> aux(2);
	aux[0] = ciudades[0];
	for (int i = 1 ; i<ciudades.size() ; ++i){
	  aux[1] = ciudades[i];
    if (afinidad(aux)/2 <= media)
	   prior.push(aux);
	}

  solucion = branch_with_greedy(solucion,media);
}


void TSP::TSP_triangles(vector<City>& solucion){

  vector<City> candidatos(ciudades);


  vector<City>::iterator minb = candidatos.begin();
  for (vector<City>::iterator it = candidatos.begin(); it != candidatos.end(); it++) {
    if ((*minb).coord_x>(*it).coord_x)
      minb = it;
  }

  solucion.push_back(*minb);
  candidatos.erase(minb);

  vector<City>::iterator maxb = candidatos.begin();
  for (vector<City>::iterator it = candidatos.begin(); it != candidatos.end(); it++) {
    if ((*maxb).coord_x<(*it).coord_x)
      maxb = it;
  }

  solucion.push_back(*maxb);
  candidatos.erase(maxb);


  vector<City>::iterator maxh = candidatos.begin();
  for (vector<City>::iterator it = candidatos.begin(); it != candidatos.end(); it++) {
    if ((*maxh).coord_y<(*it).coord_y)
      maxh = it;
  }

  solucion.push_back(*maxh);
  candidatos.erase(maxh);
  City aux;
  while (!candidatos.empty()){
    vector<City>::iterator mayor_lado, nearest;
    find_max_edge(solucion, mayor_lado);
    find_nearest_point(solucion,mayor_lado,candidatos, nearest);
    aux = *nearest;
    vector<City>::iterator insertar;
    MejorInsercion(aux, solucion, insertar);
    //solucion.insert(mayor_lado,aux);
    solucion.insert(insertar,aux);
    candidatos.erase(nearest);
  }

}

 void TSP::find_max_edge(vector<City>& l,vector<City>::iterator& ret){
  ret = l.begin();
  for (vector<City>::iterator it = l.begin();it != l.end();++it) {
    vector<City>::iterator it2 = it;
    vector<City>::iterator it3 = ret;
    ++it2;
    ++it3;
    if ((it2)!=l.end()){
      if(distancia((*ret).coord_x,(*it3).coord_x,(*ret).coord_y,(*it3).coord_y)
          < distancia((*it).coord_x,(*it2).coord_x,(*it).coord_y,(*it2).coord_y))
        ret = it;
    }else{
      if (distancia((*ret).coord_x,(*it3).coord_x,(*ret).coord_y,(*it3).coord_y)
          < distancia((*it).coord_x,l.front().coord_x,(*it).coord_y,l.front().coord_y))
        ret = it;
    }
  }
}

 void TSP::find_nearest_point(const vector<City>& orig, vector<City>::iterator& it, vector<City>& searching, vector<City>::iterator& ret) {
  City city1,city2;
  vector<City>::iterator it2 = it;
  ++it2;
  if (it2 == orig.end()) {
    city1 = *it;
    city2 = orig.front();
  }
  else{
    city1=*it;
    city2=*(it2);
  }

  ret = searching.begin();

  for (vector<City>::iterator it = searching.begin(); it != searching.end(); ++it) {
    if(distancia(city1.coord_x,(*it).coord_x,city1.coord_y,(*it).coord_y) + distancia(city2.coord_x,(*it).coord_x,city2.coord_y,(*it).coord_y)
      < distancia(city1.coord_x,(*ret).coord_x,city1.coord_y,(*ret).coord_y) + distancia(city2.coord_x,(*ret).coord_x,city2.coord_y,(*ret).coord_y))
      ret = it;
  }
}


void TSP::TSP_RandomSwap(int n, vector<City>& solucion){
	City aux1,aux2,aux3;
	srand(time(0));
	int j,k;
	double distant,distlueg;
	for(vector<City>::iterator it = ciudades.begin(); it!=ciudades.end();it++){
		solucion.push_back(*it);
	}
	for(int i = 0; i < n; i++){
		j = nCiudades*rand()/(RAND_MAX + 1.0);
		do{
			k = (nCiudades)*rand()/(RAND_MAX + 1.0);
		}while((j > nCiudades - 3 && k < 3)||(k > nCiudades - 3 && j < 3));
		j = j%nCiudades;
		k = k%nCiudades;
		distlueg = distant = 0;
		for(vector<City>::iterator it = ciudades.begin(); it!=ciudades.end()-1;it++){
      vector<City>::iterator it2 = it;
      ++it2;
			distant += distancia((*it).coord_x,(*it2).coord_x,(*it).coord_y,(*it2).coord_y);
		}
		distant += distancia(ciudades[0].coord_x,ciudades[nCiudades-1].coord_x,ciudades[0].coord_y,ciudades[nCiudades-1].coord_y);
			aux1 = ciudades[j];
			aux2 = ciudades[j+1];
			aux3 = ciudades[j+2];
			ciudades[j] = ciudades[k];
			ciudades[j+1] = ciudades[k+1];
			ciudades[j+2] = ciudades[k+2];
			ciudades[k] = aux1;
			ciudades[k+1] = aux2;
			ciudades[k+2] = aux3;
		for(vector<City>::iterator it = ciudades.begin(); it!=ciudades.end()-1;it++){
      vector<City>::iterator it2 = it;
      ++it2;
			distlueg += distancia((*it).coord_x,(*it2).coord_x,(*it).coord_y,(*it2).coord_y);
		}
		distlueg += distancia(ciudades[0].coord_x,ciudades[nCiudades-1].coord_x,ciudades[0].coord_y,ciudades[nCiudades-1].coord_y);
		if(distant < distlueg){
			aux1 = ciudades[j];
			aux2 = ciudades[j+1];
			aux3 = ciudades[j+2];
			ciudades[j] = ciudades[k];
			ciudades[j+1] = ciudades[k+1];
			ciudades[j+2] = ciudades[k+2];
			ciudades[k] = aux1;
			ciudades[k+1] = aux2;
			ciudades[k+2] = aux3;
		}
	}

}

pair<double,vector<City>::iterator> TSP::DevuelveMenorDistancia(City c, vector<City>& candidatos)
{
    vector<City>::iterator it=candidatos.begin(), min_iter=it;
    double min;
    double n;
    min=distancia(c.coord_x,(*it).coord_x,c.coord_y,(*it).coord_y);
    ++it;
    while(it!=candidatos.end())
    {
        n=distancia(c.coord_x,(*it).coord_x,c.coord_y,(*it).coord_y);
        if(n<min)
        {
            min=n;
            min_iter = it;
        }
        ++it;
    }
    pair<double,vector<City>::iterator> ret(min, min_iter);
    return ret;

}

void TSP::Dijsktra(vector<City>& res)
{
  vector<City> candidatos(ciudades);
  res.push_back(candidatos[0]);
  candidatos.erase(candidatos.begin());

  while(candidatos.size()!=0)
  {
    double dist = INT_MAX;
    vector<City>::iterator min_dist;
    for(vector<City>::iterator it = res.begin();it!=res.end();++it)
    {
      pair<double, vector<City>::iterator> f =DevuelveMenorDistancia(*it, candidatos);
      if(dist>f.first)
      {
        min_dist = f.second;
        dist = f.first;
      }
    }
    vector<City>::iterator mejor;
    MejorInsercion(*min_dist,res,mejor);
    if(mejor==res.end())
      res.push_back(*min_dist);
    else
      res.insert(mejor, *min_dist);
    candidatos.erase(min_dist);
  }
}

void TSP::MejorInsercion(City c, vector<City>& resul, vector<City>::iterator& mejor)
{
  if(resul.size()==1)
  {
    mejor = resul.end();
  }
  else
  {
    mejor = resul.end();
    double dis = INT_MAX;
    vector<City>::iterator it = resul.begin();
    while(it!=resul.end())
    {
      double nueva_dis=distancia((*it).coord_x,c.coord_x,(*it).coord_y,c.coord_y);
      vector<City>::iterator it2=it, it3;
      it3=it;
      ++it;
      if(it!=resul.end())
      {
        nueva_dis+=distancia((*it).coord_x,c.coord_x,(*it).coord_y,c.coord_y);
        nueva_dis-=distancia((*it).coord_x,(*it2).coord_x,(*it).coord_y,(*it2).coord_y);
      }
      else{
        it2=resul.begin();
        nueva_dis+=distancia((*(resul.begin())).coord_x,c.coord_x,(*(resul.begin())).coord_y,c.coord_y);
        nueva_dis-=distancia((*it3).coord_x,(*it2).coord_x,(*it3).coord_y,(*it2).coord_y);
      }
      if(nueva_dis<dis)
      {
        mejor = it;
        dis = nueva_dis;
      }
      if(it!=resul.end())
        ++it;
    }
  }
}


void TSP::TSP_WriteBack(ofstream& os, vector<City> sol)
{
  os << "DIMENSION: " << sol.size() << endl;
  for(int i = 1;i<=(int)sol.size();++i)
  {
    os << i << " " << sol[i-1].coord_x << " " << sol[i-1].coord_y << endl;
  }
}
