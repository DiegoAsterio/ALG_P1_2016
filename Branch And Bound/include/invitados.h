#ifndef __Invitados_h__
#define __Invitados_h__

#include <string>
#include <vector>
#include <map>
#include <random>
#include <queue>
#include <algorithm>
#include "mesa.h"

/**
 *  @brief TDA Invitados
 *
 *
 *
 *
 *
 *  El invariante de representación de esta clase viene dado por una matriz de incidencia
 *  que valorará las preferencias de unas personas respecto a otras.
 *
*/
/**
* @page repConjunto Rep del TDA Invitados
*
* Posicion en la tabla de las personas de la mesa
*
* Puntuaciones de afinidad
*
* @section invConjunto Invariante de la representación
*
* Todos los invitados tienen una afinidad unos con otros
*
* @section faConjunto Función de abstracción
*
* Cada instancia de este TDA contiene un Diccionario para saber donde estan las
* personas para encontrar su afinidad.
*/

class Invitados{
private:
	std::map<std::string,int> posicion;
	std::vector<std::vector<int> > preferencia;

	typedef std::priority_queue<Mesa,std::vector<Mesa>, std::function<bool(Mesa&, Mesa&)> > mypq_type;

	/**
	* @brief Constructor por defecto de Invitados.
	*
	* No se utilizará;
	*/
	Invitados()
				{			}

	/**
	* @brief Método para encontrar la afinidad de un vector personas sentadas en la mesa.
	* @return El valor de la afinidad
	*/
	int afinidad(const Mesa&);

	/**
	* @brief Metodo que devuelve los elementos del diccionario que no estan en el vector
	* @arg parcial vector que se le pasa para encontrar las personas restantes.
	* @return Los elementos que no estan en parcial y si estan en el map
	*/
	std::vector<std::string> noEstan(const std::vector<std::string>&) const;

	/**
	* @brief Metodo que encuentra una mesa con buena preferencia con Branch n Bound
	* @return El vector de personas que la ocupan con el orden adecuado.
	*/
	std::vector<std::string> encuentraMejorMesa() const;

	/**
	* @brief herramienta recursiva para encontrar la mejor mesa
	* @return en última instancia devuelve la mejor eleccion de mesa
	*/
	std::vector<std::string> bestChoice(mypq_type prior) ;



	/**
	* @brief interfaz para encontrar la mejor mesa
	* @return devuelve la mejor eleccion de mesa
	*/
	std::vector<std::string> encuentraMejorMesa();

public:
	/**
	* @brief constructor con un vector de nombres
	*	@arg names son los nombres de las personas que habrá que sentar
	*/
	Invitados(const std::vector<std::string>);

	/**
	* @brief devuelve la lista con un buen orden.
	* @return nombres ordenados
	*/
	std::vector<std::string> getInvitados() const;

	/**
	*	@brief devuelve la puntuacion de la mesa
	* @return un entero que simboliza la puntuacion
	*/
	int getMejorAfinidad();
};

#endif
