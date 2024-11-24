#include<iostream>
#include<limits>
#include<cmath>

using namespace std;

const double PI=acos(-1);

double angulo_interseccion(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4, bool en_grados=false){

  double m1 = (x2 != x1) ? (y2 - y1) / (x2 - x1) : numeric_limits<double>::infinity();
  double m2 = (x4 != x3) ? (y4 - y3) / (x4 - x3) : numeric_limits<double>::infinity();

  double angulo_rad = atan2(m2 - m1, 1 + m1 * m2);

  if (en_grados) {
    double angulo_grados = angulo_rad * 180.0 / PI;
    return angulo_grados;
  } else {
    return angulo_rad;
  }
}

int main() {
  double x1, y1, x2, y2, x3, y3, x4, y4;

  cout<<"Ingrese las coordenadas del punto inicial de la primera linea (x1): ";
  cin>>x1;
  cout<<"Ingrese las coordenadas del punto inicial de la primera linea (y1): ";
  cin>>y1;
  cout<<"Ingrese las coordenadas del punto final de la primera linea (x2): ";
  cin>>x2;
  cout<<"Ingrese las coordenadas del punto final de la primera linea (y2): ";
  cin>>y2;
  cout<<"Ingrese las coordenadas del punto inicial de la segunda linea (x3): ";
  cin>>x3;
  cout<<"Ingrese las coordenadas del punto inicial de la segunda linea (y3): ";
  cin>>y3;
  cout<<"Ingrese las coordenadas del punto final de la segunda linea (x4): ";
  cin>>x4;
  cout<<"Ingrese las coordenadas del punto final de la segunda linea (y4): ";
  cin>>y4;

  double angulo_radianes=angulo_interseccion(x1, y1, x2, y2, x3, y3, x4, y4);
  cout<<"Angulo en radianes: "<<angulo_radianes<<endl;
  double angulo_grados=angulo_interseccion(x1, y1, x2, y2, x3, y3, x4, y4, true);
  cout<<"Angulo en grados: "<<angulo_grados<<endl;

  return 0;
}