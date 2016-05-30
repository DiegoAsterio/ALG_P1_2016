#include <string>
#include <vector>
#include <random>
#include <queue>
#include <algorithm>
#include <iostream>
#include <chrono>
#include <ctime>


class Invitados{
private:
	std::vector<std::vector<int> > preferencia;

	typedef std::priority_queue<std::vector<int> ,std::vector<std::vector<int> >, std::function<bool(std::vector<int>&, std::vector<int>&)> > mypq_type;

	/**
	* @brief Método para encontrar la afinidad de un vector personas sentadas en la mesa.
	* @return El valor de la afinidad
	*/
  int afinidad(std::vector<int> pers) {

  	int afinidad=0, N = pers.size();

  	for (int i = 1; i < N; ++i){
  		afinidad += preferencia[pers[i-1]][pers[i]];
  	}
    afinidad += preferencia[pers[0]][pers[N-1]];

  	std::vector<int> noSentadas = noEstan(pers);

  	for (size_t i = 0; i < noSentadas.size(); i++) {
  		afinidad += preferencia[pers[N-1]][noSentadas[i]];
  	}

  	afinidad %= preferencia.size() + 1;

  	return afinidad;
  }


	/**
	* @brief Metodo que devuelve los elementos del diccionario que no estan en el vector
	* @arg parcial vector que se le pasa para encontrar las personas restantes.
	* @return Los elementos que no estan en parcial y si estan en el map
	*/
	std::vector<int> noEstan(std::vector<int> parcial) const{
	  std::vector<int> solucion;

	  for (size_t i = 0; i < preferencia.size(); ++i){
		  if (std::find(parcial.begin(),parcial.end(),i) == parcial.end()){
			  solucion.push_back(i);
		  }
	  }
	  return solucion;
  }
	/**
	* @brief Metodo que encuentra una mesa con buena preferencia con Branch n Bound
	* @return El vector de personas que la ocupan con el orden adecuado.
	*/
  std::vector<int> encuentraMejorMesa() {
    int N = preferencia.size();

	  std::function<bool(std::vector<int>&, std::vector<int>&)> comp = [this](std::vector<int>& a, std::vector<int>& b) -> bool {return this->afinidad(a) < this->afinidad(b);};
	  mypq_type prior(comp);

	  std::vector<int> aux(2);
	  aux[0] = 0;
	  for (int i = 1 ; i<N ; ++i){
		  aux[1] = i;
		  prior.push(aux);
	  }

	  return bestChoice(prior);
}

	/**
	* @brief herramienta recursiva para encontrar la mejor mesa
	* @return en última instancia devuelve la mejor eleccion de mesa
	*/
  std::vector<int> bestChoice(mypq_type prior){
	   if (prior.top().size() == preferencia.size()){
		  return prior.top();
	  }
	  else{
		  std::vector<int> mejores = prior.top();
		  prior.pop();
		  std::vector<int> nuevosElementos = noEstan(mejores);

		  for (auto i : nuevosElementos) {
			  std::vector<int> aux (mejores);
			  aux.push_back(i);
			  prior.push(aux);
		  }
		  return bestChoice(prior);
	  }
  }

  void generateRandomMatrix(std::vector<std::vector<int> >& m, const int& s){
  	std::default_random_engine generator(s);
  	std::uniform_int_distribution<int> distribution(0,100);
  	auto rng = std::bind(distribution, generator);
  	for (size_t i = 0; i < m.size(); i++)
  		for (size_t j = i; j < m[i].size(); j++){
  			if (i==j)
  				m[i][j] = 0;
  			else
  				m[j][i] = m[i][j] = rng();
  		}
  }

public:
	/**
	* @brief constructor con un vector de nombres
	*	@arg names son los nombres de las personas que habrá que sentar
	*/
	Invitados(const int& size){

    preferencia = std::vector<std::vector<int> > (size,std::vector<int>(size));

    generateRandomMatrix(preferencia, size);
  }

	/**
	*	@brief devuelve la puntuacion de la mesa
	* @return un entero que simboliza la puntuacion
	*/
	int getMejorAfinidad(){
    return afinidad(encuentraMejorMesa());
  }
};

int main(int argc, char * argv[]){

  if(argc<2)
  {
    std::cout << "El formato es ./cena_gala_diego <numero comensales>" << std::endl;
    std::exit(1);
  }

  int num_comensales = atoi(argv[1]);

  Invitados nuevaInvitacion(num_comensales);

  //Resolución del problema.
  std::chrono::high_resolution_clock::time_point t_antes, t_despues;

  t_antes = std::chrono::high_resolution_clock::now();
  nuevaInvitacion.getMejorAfinidad();
  t_despues = std::chrono::high_resolution_clock::now();


  std::chrono::duration<double> transcurrido = std::chrono::duration_cast<std::chrono::duration<double> >(t_despues-t_antes);
  std::cout << num_comensales << " " << transcurrido.count() << "\n";

}
