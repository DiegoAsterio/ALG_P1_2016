#ifndef __Mesa_h__
#define __Mesa_h__

#include <vector>
#include <string>

/**
* @brief TDA Mesa
*
* El TDA Mesa representa una mesa, se sabe donde se encuentra la última persona
* que se ha sentado y se tiene el vector de personas sentadas.
*/
/**
* @page repConjunto Rep del TDA Mesa
*
* Posicion de la última persona sentada
*
* Personas sentadas
*
* @section invConjunto Invariante de la representación
*
* Una Mesa debe tener al menos una persona sentada y una última persona sentada
* se sentará a una persona.
*
* @section faConjunto Función de abstracción
*
* Cada instancia de este TDA contiene un puntero a nodo,
* y un vector de int que representan personas.
*/
class Mesa {
private:
	std::vector<std::string> personas;

public:
	/**
	* @brief Constructor por parámetros de la clase Letra.
	* @param generador ultima persona sentada.
	* @param personas sentadas.
	*/
	Mesa(std::vector<std::string>);

	/**
	* @brief Método para encontrar personas sentadas en la mesa.
	* @return Un vector con los sentados.
	*/
	std::vector<std::string> getSentadas() const;

	/**
	* @brief Método para recuperar la longitud de la mesa.
	*	@return Número de personas sentadas en la mesa
	*/
	int getSize() const;

};



#endif
