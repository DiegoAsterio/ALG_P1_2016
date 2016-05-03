#ifndef TSP_H_INCLUDED
#define TSP_H_INCLUDED


#include <fstream>
#include <vector>
#include <list>

struct City{
    int ciudad;
    double coord_x;
    double coord_y;
};


using namespace std;

class TSP {

    private:
        int nCiudades;
        vector<City> ciudades;
        vector<City>::iterator menorDistancia(City c);
        list<City>::iterator find_max_edge(list<City> l);
        list<City>::iterator find_nearest_point(list<City> orig, list<City>::iterator it, list<City> searching);


    public:

        TSP(char* cadena);

        void TSP_vecino_mas_cercano(vector<City>& vec);
        void TSP_triangles(vector<City>& solucion);
        void TSP_RandomSwap(int n, vector<City>& solucion);


};
#endif // TSP_H_INCLUDED
