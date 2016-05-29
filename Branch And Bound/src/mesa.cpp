#ifndef __Mesa_cpp__
#define __Mesa_cpp__

#include "mesa.h"

Mesa::Mesa( std::vector<std::string> personas){
	this->personas = personas;
}

std::vector<std::string> Mesa::getSentadas() const{
	return this->personas;
}

int Mesa::getSize() const{
	return this->personas.size();
}

#endif
