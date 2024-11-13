#include<iostream>
using namespace std;

void determinarCuadrante(double x, double y){
    if (x>0&&y>0){
        cout<<"El punto ("<<x<<", "<<y<<") esta en el primer cuadrante."<<endl;
    } else if (x<0&&y>0){
        cout<<"El punto ("<<x<<", "<<y<<") esta en el segundo cuadrante."<<endl;
    } else if (x<0&&y<0){
        cout<<"El punto ("<<x<<", "<<y<<") esta en el tercer cuadrante."<<endl;
    } else if (x>0&&y<0){
        cout<<"El punto ("<<x<<", "<<y<<") esta en el cuarto cuadrante."<<endl;
    } else if (x==0&&y==0){
        cout<<"El punto ("<<x<<", "<<y<<") esta en el origen."<<endl;
    } else if (x==0){
        cout<<"El punto ("<<x<<", "<<y<<") esta en el eje Y."<<endl;
    } else if (y==0){
        cout<<"El punto ("<<x<<", "<<y<<") esta en el eje X."<<endl;
    }
}

bool enLaMismaLinea(double puntos[3][2], double &A, double &B, double &C){
    double x1=puntos[0][0], y1=puntos[0][1];
    double x2=puntos[1][0], y2=puntos[1][1];

    A=y2-y1;
    B=x1-x2;
    C=x2*y1-x1*y2;

    for (int i=2; i<3;++i){
        double x=puntos[i][0], y=puntos[i][1];
        if (A*x+B*y+C!= 0) return false;
    }

    return true;
}

int main(){
    const int num_puntos=3;
    double puntos[num_puntos][2];

    for (int i=0; i<num_puntos; ++i) {
        cout<<"Introduce la coordenada x del punto "<<i+1<<": ";
        cin >> puntos[i][0];
        cout<<"Introduce la coordenada y del punto "<<i+1<<": ";
        cin >> puntos[i][1];
        determinarCuadrante(puntos[i][0], puntos[i][1]);
    }

    double A, B, C;
    if (enLaMismaLinea(puntos, A, B, C)){
        cout<<"Todos los puntos estan en la misma linea."<<endl;
        cout<<"La ecuacion de la linea es: "<<A<<"x + "<<B<<"y + "<<C<<" = 0" << endl;
    } else {
        cout<<"Los puntos no estan en la misma linea."<<endl;
    }

    return 0;
}
