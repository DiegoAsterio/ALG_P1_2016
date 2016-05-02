#ifndef TSP_H_INCLUDED
#define TSP_H_INCLUDED


#include <fstream>
#include <vector>

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

    public:

        TSP(char* cadena);

        void TSP_vecino_mas_cercano(vector<City>& vec);
}


#endif // TSP_H_INCLUDED


