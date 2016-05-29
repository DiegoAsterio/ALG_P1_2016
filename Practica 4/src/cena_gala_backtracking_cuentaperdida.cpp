#include <cassert>
#include <iostream>
#include <list>
#include <time.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

//Cuenta la afinidad que ya has perdido cogiendo la distribución por ahora hecha en rama
int afinidadNoConseguida(list<int> rama, int* afinidades, int n){
	int res = 0;
	list<int>::iterator itnext ;
	for(list<int>::iterator it = rama.begin(); it != prev(rama.end()); it++){
		itnext = it;
		itnext++;
		res += afinidades[(*it)*n+(*(itnext))];
	}
	res += afinidades[(*(rama.begin()))*n+(*(rama.end()))];
	return 100*rama.size() - res;
}

list<int> backtracking(list<int> rama, int* afinidades, list<int> sinusar, int &bestafinlost, int n){
	if(afinidadNoConseguida(rama,afinidades,n) >= bestafinlost){     // Si la afinidad perdida es más grande que la afinidad
		list<int> res;						 // perdida en la mejor distribucion hasta el momento, men,
		res.clear();						 // desiste del tema.
		return res;
	}else{
		int tam = sinusar.size();
		if(tam <= 1){			// Si queda una persona por sentar, men, has llegado
			rama.splice(rama.end(),sinusar);
			bestafinlost = afinidadNoConseguida(rama,afinidades,n);
			return rama;
		}else{
			list<int>::iterator it;
			list<int> res;
			list<int> aux2;
			int i = 0;
			for(it = sinusar.begin(); it != sinusar.end(); it++){	// Crea una rama por cada persona que no este sentada
				int aux = *it;
				it = sinusar.erase(it);
				rama.push_back(aux);
				aux2 = backtracking(rama, afinidades, sinusar, bestafinlost, n);
				if(aux2.size() != 0){
					res = aux2;
				}
				it = sinusar.emplace(it,aux);
				rama.remove(aux);
			}
			return res;
		}
	}
}
int main(int argc, char* argv[]){
	if (argc<2)
	{
		cerr << "La sintaxis es <num_personas>" << endl;
		return(1);
	}
	srand(time(0));
	int n = atoi(argv[1]);
	int* afinidades = new int[n*n];
	list<int> rama ; 
	list<int> sinusar ;
	for(int i = 0; i < n; i++){		// Rellena afinidades
		sinusar.push_back(i);
		for(int j = i; j < n; j++){
			afinidades[i*n+j] = afinidades[j*n+i] = rand()%101;
			if(i == j)
				afinidades[i*n+i] = 0;  // La afinidad contigo mismo es 0, si.
		}
	}
	rama.push_back(0);   // La mesa es redonda, el primer elemento da igual el que sea.
	sinusar.pop_front();
	
	int NoAfinidad = n*100;
	rama = backtracking(rama, afinidades, sinusar, NoAfinidad, n);
	
	for(int i = 0; i < n; i++){		// IMPRIME MATRIZ DE AFINIDADES
		for(int j = 0; j < n; j++){
			cout << afinidades[i*n+j] << " ";
		}
		cout << endl ;
	}
	cout << endl << "La solucion es:" << endl;   // IMPRIME LA MESA
	for(list<int>::iterator it = rama.begin(); it != rama.end(); it++){
		cout << *it << " - " ;
	}
	cout << endl << "La afinidad conseguida es " << 100*n - NoAfinidad << endl;   // IMPREME LA AFINIDAD CONSEGUIDA
	
}
