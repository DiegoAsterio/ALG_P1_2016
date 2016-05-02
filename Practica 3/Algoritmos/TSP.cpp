#include <fstream>
#include <cstdlib>
#include <cmath>
#include "TSP.h"

using namespace std;


double distancia(int x0, int x1, int y0, int y1)
{
    double n = sqrt((x1-x0)^2 + (y1-y0)^2);
    return n;
}

TSP::vector<City>::iterator menorDistancia(City c)
{
    vector<City>::iterator it=candidatos.begin();
    double min;
    double n;
    int i=0;
    min=distancia(c.coord_x,(*it).coord_x,c.coord_y,(*it).coord_y);
    ++it;
    while(it!=it.end())
    {
        n=distancia(c.coord_x,(*it).coord_x,c.coord_y,(*it).coord_y);
        if(n<min)
        {
            min=n;
            i++;
        }
        ++it;
    }
    int aux=0;
    it=candidatos.begin();
    while(aux<i)
    {
        ++it;
        ++aux;
    }

    return it;

}

TSP::TSP(char* cadena)
{
    bool first=true;
    ifstream archivo(cadena);
    string linea;
    int num;
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
}

TSP::void TSP_vecino_mas_cercano(vector<City>& solucion)
{

  solucion.push_back(ciudades.get(0));

  vector<City> candidatos(ciudades);
  candidatos.erase(candidatos.begin());

  while(solucion.size() < nCiudades)
  {
    vector<City>::iterator it = candidatos.menorDistancia(solucion.at(solucion.size()-1));
    solucion.push_back(*it);
    candidatos.erase(it);
  }
  return solucion;
}

TSP::void TSP_triangles(vector<City>& solucion){
  list<City> solulista;

  list<City> candidatos(ciudades);

  list<City>::iterator minb = candidatos.begin();
  for (list<City>::iterator it = candidatos.begin(); it != candidatos.end(); it++) {
    if (*minb.coord_x>*it.coord_x)
      minb = it;
  }

  solulista.push_back(*minb);
  candidatos.erase(minb);

  list<City>::iterator maxb = candidatos.begin();
  for (list<City>::iterator it = candidatos.begin(); it != candidatos.end(); it++) {
    if (*maxb.coord_x<*it.coord_x)
      maxb = it;
  }

  solulista.push_back(*maxb);
  candidatos.erase(maxb);


  list<City>::iterator maxh = candidatos.begin();
  for (list<City>::iterator it = candidatos.begin(); it != candidatos.end(); it++) {
    if (*maxh.coord_x<*it.coord_x)
      maxh = it;
  }

  solulista.push_back(*maxh);
  candidatos.erase(maxh);

  while (!candidatos.empty()){
    list<City>::iterator mayor_lado = find_max_edge(solulista);
    list<City>::iterator nearest = find_nearest_point(solulista,mayor_lado,candidatos);
    solulista.insert(mayor_lado,*nearest);
    candidatos.erase(nearest);
  }
}

TSP::list<City>::iterator find_max_edge(list<City> l){
  list<City>::iterator ret = l.begin();
  for (list<City>::iterator it = l.begin();it != l.end();++it) {
    if (it+1!=l.end()){
      if(distancia(*ret.coord_x,*ret.coord_y,*(ret+1).coord_x,*(ret+1).coord_y)
          < distancia(*it.coord_x,*it.coord_y,*(it+1).coord_x,*(it+1).coord_y))
        ret = it;
    }else{
      if (distancia(*ret.coord_x,*ret.coord_y,*(ret+1).coord_x,*(ret+1).coord_y)
          < distancia(*it.coord_x,*it.coord_y,l.front().coord_x,l.front().coord_y))
        ret = it;
    }
  }
  return ret;
}

TSP::list<City>::iterator find_nearest_point(list<City> orig, list<City>::iterator it, list<City> searching) {
  City city1,city2;
  if (it+1 == it.end()) {
    city1 = *it;
    city2 = orig.front()
  }
  else{
    city1=*it;
    city2=*(it+1);
  }

  list<City>::iterator ret = searching.begin();

  for (list<City>::iterator it = searching.begin(); it != searching.end(); ++it) {
    if(distancia(city1.coord_x,*it.coord_x,city1.coord_y,*it.coord_y) + distancia(city2.coord_x,*it.coord_x,city2.coord_y,*it.coord_y)
      < distancia(city1.coord_x,*ret.coord_x,city1.coord_y,*ret.coord_y) + distancia(city2.coord_x,*ret.coord_x,city2.coord_y,*ret.coord_y))
      ret = it;
  }
  return ret;
}
