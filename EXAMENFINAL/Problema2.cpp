/*
Autor:      anaramos
Compilador: g++ (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  g++ -o Problema2.out Problema2.cpp -lm
Fecha:      05/16/22 
Librerías:  iostream, math
Resumen:    programa que simula el movimiento de tres cohetes   
*/
//Librerías
#include <iostream>
#include <math.h>
using namespace std;
//declaramos clase 
class cohete
{
public:
    /* declaramos los atributos que tendrá cada objeto */
    float empuje;
    float TSFC;
    float CD;
    float seccionT;
    float mo;
    float mfo;
public:
    //declaramos metodo
    void mostrarinformacion(float Eo,float consumoempuje,float CoeficienteD,float A,float m,float mf);

};
//defino fuera de la clase el metodo mostrarinformacion
void cohete::mostrarinformacion(float Eo,float consumoempuje,float CoeficienteD,float A,float m,float mf)
{   //asigno los valores a los atributos
    empuje= Eo;
    TSFC= consumoempuje;
    CD= CoeficienteD;
    seccionT=A;
    mo=m;
    mfo=mf;
    //escribir los datos en consola
    cout<<"Empuje del cohete:\t\t"<<empuje<<"\tN";
    cout<< endl;
    cout<<"consumo especifico del empuje:\t"<<consumoempuje<<"\tkg/Ns";
    cout<< endl;
    cout<<"Coeficiente de forma CD:\t"<<CoeficienteD;
    cout<< endl;
    cout<<"Seccion transversal del cohete: "<<A<<"\tm^2";
    cout<< endl;
    cout<<"Masa del propulsor:\t\t"<<m<<"\tkg";
    cout<< endl;
    cout<<"Masa inicial del combustible:\t"<<mf<<"\tkg";
    cout<< endl;
}
int main(){
    //declaro obtetos
    cohete cohete1;
    cohete cohete2;
    cohete cohete3;
    cout<<"\n***Caracteristicas de AH MUN***";
    cout << endl;
    //utilizo el metodo para el primer objeto
    cohete1.mostrarinformacion(3*pow(10,7),3.248*pow(10,-4),61.27,201.06,1.1*pow(10,5),1.5*pow(10,6));
    cout<<"\n***Caracteristicas de AHAU KIN***";
    cout << endl;
    //utilizo el metodo para el segundo objeto
    cohete2.mostrarinformacion(2.7*pow(10,7),2.248*pow(10,-4),61.27,201.06,1.1*pow(10,5),1.5*pow(10,6));
    cout<<"\n***Caracteristicas de CHAC***";
    cout << endl;
    //utilizo el metodo para el tercer cohete
    cohete3.mostrarinformacion(2.5*pow(10,7),2.248*pow(10,-4),70.25,215.00,1.8*pow(10,5),2.1*pow(10,6));
    return 0;
}


