#include <cassert>
#include <iostream>
#include <list>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;


int suma(list<int> rama, int* afinidades,int n){
	int sum=0;
	list<int>::iterator it;
	list<int>::iterator next_it;
	for(it=rama.begin(); it!=rama.end();++it){
		next_it=it;
		next_it++;
		sum += afinidades[(*it)*n+(*(next_it))];
	}
	sum+= afinidades[(*(rama.begin()))*n+(*(prev(rama.end())))];
	return sum;
}


list<int> backtracking(list<int> rama, int* afinidades, list<int> sinusar,int& maxima_suma, int n){
		int tam = sinusar.size();
		if(tam <= 1){			
			rama.splice(rama.end(),sinusar);
			maxima_suma=suma(rama,afinidades,n);
			return rama;
		}else{
			list<int>::iterator it;
			list<int> res;
			list<int> aux2;
			for(it = sinusar.begin(); it != sinusar.end(); it++){
				int aux = *it;
				it = sinusar.erase(it);
				rama.push_back(aux);
				aux2 = backtracking(rama, afinidades, sinusar,maxima_suma, n);
				if(aux2.size() != 0){
					res = aux2;
				}
				it = sinusar.emplace(it,aux);
				rama.remove(aux);
			}
			return res;
		}
}

void Imprime(int* afinidades, list<int> rama, int n, int suma)
{
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
	cout << endl << "La afinidad conseguida es " << suma << endl;   // IMPREME LA AFINIDAD CONSEGUIDA
}

int main(int argc, char* argv[]){
	if (argc<2)
	{
		cerr << "La sintaxis es <num_personas>" << endl;
		return(1);
	}
	srand(time(NULL));
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
	rama.push_back(0);   
	sinusar.pop_front();

	high_resolution_clock::time_point t_antes, t_despues;
	int suma=0;
	t_antes = high_resolution_clock::now();
	rama = backtracking(rama, afinidades, sinusar, suma, n);
	t_despues = high_resolution_clock::now();

	//Imprime(afinidades, rama, n, NoAfinidad);

	duration<double> transcurrido = duration_cast<duration<double> >(t_despues-t_antes);
  cout << n << " " << transcurrido.count() << "\n";

}
