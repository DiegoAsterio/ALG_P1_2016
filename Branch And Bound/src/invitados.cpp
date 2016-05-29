#ifndef __Invitados_cpp__
#define __Invitados_cpp__

#include "invitados.h"

std::vector<std::string> Invitados::noEstan(const std::vector<std::string>& parcial) const{
	std::vector<std::string> solucion;
	for (auto i : posicion){
		if (std::find(parcial.begin(),parcial.end(),i.first) == parcial.end()){
			solucion.push_back(i.first);
		}
	}
	return solucion;
}

int Invitados::afinidad(const Mesa& mesa) {
	std::vector<std::string> pers = mesa.getSentadas();
	int afinidad=0, N = pers.size();

	for (int i = 1; i < N; ++i){
		afinidad += preferencia[posicion[pers[i-1]]][posicion[pers[i]]];
	}
	afinidad += preferencia[posicion[pers[0]]][posicion[pers[N-1]]];

	std::vector<std::string> noSentadas = noEstan(pers);

	for (size_t i = 0; i < noSentadas.size(); i++) {
		afinidad += preferencia[posicion[pers[N]]][posicion[noSentadas[i]]];
	}

	afinidad %= posicion.size() + 1;

	return afinidad;
}

std::vector<std::string> Invitados::bestChoice(mypq_type prior){
	if (prior.top().getSize() == posicion.size()){
		return prior.top().getSentadas();
	}
	else{
		std::vector<std::string> mejores = prior.top().getSentadas();
		prior.pop();
		std::vector<std::string> nuevosElementos = noEstan(mejores);

		for (auto i : nuevosElementos) {
			std::vector<std::string> aux (mejores);
			aux.push_back(i);
			prior.push(Mesa(aux));
		}
		return bestChoice(prior);
	}
}

std::vector<std::string> Invitados::encuentraMejorMesa() {
	std::vector<std::string> v;
	for (auto it : posicion){
		v.push_back(it.first);
	}

	std::function<bool(Mesa&,Mesa&)> comp = [this](Mesa &a, Mesa &b) -> bool {return this->afinidad(a) < this->afinidad(b);};
	mypq_type prior(comp);

	std::vector<std::string> aux(2);
	aux[0] = v[0];
	for (int i = 1 ; i<v.size() ; ++i){
		aux[1] = v[i];
		prior.push(Mesa(aux));
	}

	return bestChoice(prior);
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

Invitados::Invitados(const std::vector<std::string> names){
	int index = 0;
	for (auto str : names){
		if (posicion.find(str) == posicion.end())
			posicion[str] = index++;
	}

	preferencia = std::vector<std::vector<int> > (names.size(),std::vector<int>(names.size()));

	generateRandomMatrix(preferencia, posicion.size());
}


std::vector<std::string> Invitados::getInvitados() const{
	return Invitados::encuentraMejorMesa();
}
int Invitados::getMejorAfinidad(){
	return Invitados::afinidad(Invitados::encuentraMejorMesa());
}

#endif
