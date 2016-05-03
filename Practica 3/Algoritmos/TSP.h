#ifndef TSP_H_INCLUDED
#define TSP_H_INCLUDED


#include <fstream>
#include <vector>
#include <vector>

struct City{
    int ciudad;
    double coord_x;
    double coord_y;
    City& operator=(const City&);
};


using namespace std;

class TSP {

    private:
        int nCiudades;
        vector<City> ciudades;
        vector<City>::iterator menorDistancia(City c, vector<City>& candidatos);
        void find_max_edge(vector<City>& l, vector<City>::iterator&);
        void find_nearest_point(const vector<City>& orig, vector<City>::iterator& it, vector<City>& searching,  vector<City>::iterator&);


    public:

        TSP(char* cadena);

        void TSP_vecino_mas_cercano(vector<City>& vec);
        void TSP_triangles(vector<City>& solucion);
        void TSP_RandomSwap(int n, vector<City>& solucion);
        void TSP_WriteBack(ofstream& os, vector<City> sol);

};
#endif // TSP_H_INCLUDED
