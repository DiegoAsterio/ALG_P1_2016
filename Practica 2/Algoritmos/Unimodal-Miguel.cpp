#include <iostream>
using namespace std;
#include <ctime>
#include <cstdlib>
#include <climits>
#include <cassert>

int montana(int* v, int n){

    if(n==2){             //////////  Si el vector tiene 2 elementos
        if(v[0] < v[1]){
            return 1 ;
        }else{
            return 0 ;
        }

    }else if(n==1){       //////////   Si el vector tiene 1 elemento
        return 0 ;

    }else{                 /////////   Si el vector tiene mas de 2 elementos
        int i = montana(v,n/2);
        int j = montana(v+n/2,n/2) ;
        if(v[i] < v[n/2 + j]){
            return n/2 + j;
        }else{
            return i ;
        }

    }
}

double uniforme()
{
double u;
  u = (double) rand();
  u = u/(double)(RAND_MAX+1.0);
 return u;
}

int main(int argc, char * argv[])
{

  if (argc != 2)
    {
      cerr << "Formato " << argv[0] << " <num_elem>" << endl;
      return -1;
    }

  int n = atoi(argv[1]);

  int * T = new int[n];
  assert(T);

srand(time(0));
double u=uniforme();
int p=1+(int)((n-2)*u);
T[p]=n-1;
for (int i=0; i<p; i++) T[i]=i;
for (int i=p+1; i<n; i++) T[i]=n-1-i+p;

cout << "El vector generado es:" << endl;
for (int j=0; j<n; j++) {cout << T[j] << " ";}
int res = montana(T,n);
cout << endl << "La posición en la que cambia la monotonía es: " << res << endl ;
}
