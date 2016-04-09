/**
   @file C�lculo de la sucesi�n de Fibonacci
*/
#include <iostream>
using namespace std;
#include <ctime>
#include <chrono>
/**
   @brief Calcula el t�rmino n-�simo de la sucesi�n de Fibonacci.

   @param n: n�mero de orden del t�rmino buscado. n >= 1.

   @return: t�rmino n-�simo de la sucesi�n de Fibonacci.
*/

using namespace std::chrono;

int fibo(int n)
{
  if (n < 2)
    return 1;
  else
    return fibo(n-1) + fibo(n-2);
}

int main(int argc, char* argv[])
{
  high_resolution_clock::time_point t_antes, t_despues;
  int n;
  int f;

  //cout << "Numero del termino: ";
  //cin >> n;
  n=atoi(argv[1]);

  t_antes = high_resolution_clock::now();
  f = fibo(n);
  t_despues = high_resolution_clock::now();

  //cout << "El t�rmino " << n << "-esimo es: " << f << endl;
  duration<double> transcurrido = duration_cast<duration<double> >(t_despues-t_antes);
  cout << n << " " << transcurrido.count() << "\n";

  return 0;
}
