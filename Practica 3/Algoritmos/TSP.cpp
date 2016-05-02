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

TSP::void TSP_triangulillos(vector<City>& solucion){
    list<City> solulista;

    list<City> candidatos(ciudades);

    solulista.push_back(candidatos.front());
    for (size_t i = 0; i < c; i++) {
      if (minb.coord_x>candidatos[i].coord_x)
        minb = candidatos[i];
    }


}
