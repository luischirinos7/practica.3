#include<iostream>
#include<cmath>
using namespace std;

bool dentroDelCuadrante(double x, double y, double x_min, double x_max, double y_min, double y_max){
    return (x>=x_min&&x<=x_max&&y>=y_min&&y<=y_max);
}
double calcularDistancia(double x1, double y1, double x2, double y2){
    return sqrt(pow(x2-x1, 2)+pow(y2-y1, 2));
}

int main(){
    const int num_puntos=5; 
    double puntos[num_puntos][2]={
        {1.0, 2.0},
        {-1.0, -2.0},
        {3.0, 4.0},
        {5.0, 6.0},
        {7.0, 8.0}
    };
    
    double x_min, x_max, y_min, y_max;
    cout<<"Introduce los limites del cuadrante (x_min): ";
    cin>>x_min;
    cout<<"Introduce los limites del cuadrante (x_max): ";
    cin>>x_max;
    cout<<"Introduce los limites del cuadrante (y_min): ";
    cin>>y_min;
    cout<<"Introduce los limites del cuadrante (y_max): ";
    cin>>y_max;

    double puntoX, puntoY;
    cout<<"Introduce las coordenadas del punto de referencia x: ";
    cin>>puntoX;
    cout<<"Introduce las coordenadas del punto de referencia y: ";
    cin>>puntoY;

    if (!dentroDelCuadrante(puntoX, puntoY, x_min, x_max, y_min, y_max)){
        cout<<"El punto de referencia no esta dentro de los limites del cuadrante."<<endl;
        return 0;
    }

    cout<<"Distancias desde el punto ("<<puntoX<<", "<<puntoY<<") a otros puntos dentro del cuadrante:"<<endl;

    for (int i=0; i<num_puntos; ++i){
        if (dentroDelCuadrante(puntos[i][0], puntos[i][1], x_min, x_max, y_min, y_max)){
            double distancia=calcularDistancia(puntoX, puntoY, puntos[i][0], puntos[i][1]);
            cout<<"Distancia a ("<<puntos[i][0]<<", "<<puntos[i][1]<<") es "<<distancia<<endl;
        }
    }

    return 0;
}
