#include<iostream>
#include<limits>
#include<cmath>

using namespace std;

int lineas_cruzadas(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4){

  double m1=(x2!=x1)?(y2-y1)/(x2-x1):numeric_limits<double>::infinity();
  double m2=(x4!=x3)?(y4-y3)/(x4-x3):numeric_limits<double>::infinity();

  if (m1==m2){
    return 0;
  }

  if(m1*m2==-1||(isinf(m1)&&m2==0)||(m1==0&&isinf(m2))){
    return 1;
  }

  double b1=y1-m1*x1;
  double b2=y3-m2*x3;
  double x_interseccion=(b2-b1)/(m1-m2);
  double y_interseccion=m1*x_interseccion+b1;

  if (min(x1, x2)<=x_interseccion&&x_interseccion<=max(x1, x2)&&
      min(y1, y2)<=y_interseccion&&y_interseccion<=max(y1, y2)&&
      min(x3, x4)<=x_interseccion&&x_interseccion<=max(x3, x4)&&
      min(y3, y4)<=y_interseccion&&y_interseccion<=max(y3, y4)){
    return -1; 
  } else{
    return -2; 
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

  int resultado = lineas_cruzadas(x1, y1, x2, y2, x3, y3, x4, y4);

  if(resultado==1){
    cout<<"Las lineas se cruzan."<<endl;
  } else if(resultado==0){
    cout<<"Las lineas son paralelas."<<endl;
  } else{
    cout<<"Las lineas no se cruzan ni son paralelas."<<endl;
  }
  return 0;
}