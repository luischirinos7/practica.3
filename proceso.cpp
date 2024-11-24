#include<iostream>

using namespace std;

int contador_llamadas=0;

void proceso() {
  contador_llamadas++;

  cout << "Proceso ejecutado. Llamada #" << contador_llamadas << endl;
}
int obtener_contador_llamadas() {
  return contador_llamadas;
}

int main() {
  proceso();
  proceso();
  int cantidad_llamadas = obtener_contador_llamadas();
  cout<<"La funcion 'proceso' se llamo "<<cantidad_llamadas<<" veces."<<endl;

  return 0;
}