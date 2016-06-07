#ifndef TSP_H_INCLUDED
#define TSP_H_INCLUDED


#include <fstream>
#include <vector>
#include <utility>
#include <queue>
#include <vector>

struct City{
    int ciudad;
    double coord_x;
    double coord_y;
    //City& operator=(const City&);
};


using namespace std;

class TSP {
    typedef std::priority_queue<std::vector<City> ,std::vector<std::vector<City> >, std::function<bool(std::vector<City>&, std::vector<City>&)> > mypq_type;

    private:
        int nCiudades;
        vector<pair<int,int> > max_dist;
        vector<City> ciudades;
        vector<City>::iterator menorDistancia(City c, vector<City>& candidatos);
        void find_max_edge(vector<City>& l, vector<City>::iterator&);
        void find_nearest_point(const vector<City>& orig, vector<City>::iterator& it, vector<City>& searching,  vector<City>::iterator&);
        void branch_engine_start(vector<City>&);
        void find_max();
        double afinidad(vector<City>);
        double peso(vector<City>);
        vector<City> noEstan(vector<City>);
        vector<City> bestChoice(mypq_type);


    public:

        TSP(char* cadena);

        pair<double,vector<City>::iterator> DevuelveMenorDistancia(City c, vector<City>& candidatos);
        void Dijsktra(vector<City>& res);
        void MejorInsercion(City c, vector<City>& resul, vector<City>::iterator& mejor);
        void TSP_vecino_mas_cercano(vector<City>& vec);
        void TSP_triangles(vector<City>& solucion);
        void TSP_RandomSwap(int n, vector<City>& solucion);
        void TSP_WriteBack(ofstream& os, vector<City> sol);
        void TSP_branch_and_bound(vector<City>& solucion);

};
#endif // TSP_H_INCLUDED
