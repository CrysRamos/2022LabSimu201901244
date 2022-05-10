/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o Problema6.out Problema6.c -lm
Fecha:      05/09/22 
Librerías:  stdio, math
Resumen:    Programa que realiza distintas sumatorias de un número ingresado por el usuario  
*/
//Librerías
#include <stdio.h>
#include <float.h>
#include <math.h>
//prototipado de funciones
long int sumaA(int n);//funcion que hace la pprimera sumatoria
float funcionB(int n);//funcion para declarar una ecuacion
float sumaB(int n);//suma de la funcionB declarada
float funcionC(int n);//se declara funcion C
float sumaC(int n);//se suma la funcionC
float sucesionBode(int n);//se declara la sucesion de bode
float sumaD(int n);//se suma la funcion de bode
int main(){
    //declaro variable local
    int numero;
    //el ususario inicializa el numero entero
    puts("Ingrese un numero entero: ");
    scanf("%d",&numero);
    //se muestra la primera sumatoria
    printf("primera sumatoria: %ld\n",sumaA(numero));
    //se muestra la segunda sumatoria
    printf("segunda sumatoria: %.2f\n", sumaB(numero));
    //se muestra el resultado de la tercera sumatoria
    printf("Tercera sumatoria: %.2f\n",sumaC(numero));
    //se muestra la cuarta sumatoria
    printf("Cuarta sumatoria: %.2f\n",sumaD(numero));
}
long int sumaA(int n){
    //variable de tipo long a que el numero crece rapido
    long int sum=0;
    for (int i = 1; i < n+1; i++)
    {
        /* se realiza la funcion de sumatoria */
        sum+= pow(i,2)*(i-3);
    }
    return sum;
}
float funcionB(int n){
    float fB;
    //se inicializa la funcion para despues sumarla
    fB= (float) 3/(n-1);
    return fB;
}
float sumaB(int n){
    float sum=0;
    for (int i = 2; i < n+1; i++)
    {
        /* se hace la sumatoria para cada n de la funcion B */
        sum+= funcionB(i);
    }
    return sum;
}


float funcionC(int n){
    float fc;
    //se inicializa la funcion C
    fc=(float) (1/sqrt(5)*(pow((1+sqrt(5))/2,n))-1/sqrt(5)*(pow((1-sqrt(5))/2,n)));
    return fc;
}

float sumaC(int n){
    float sum=0;
    for (int i = 1; i < n+1; i++)
    {
        /* se hace la sumatoria para hasta n de la funcion C */
        sum+= funcionC(i);
    }
    return sum;
}

float sucesionBode(int n){
    float fd=0;
    //se declara la funcion de Bode
    fd=(float) (0.1*(3*pow(2,(n-2))+4));
    return fd;
}

float sumaD(int n) {
    float sum=0;
    for (int i = 2; i < n+1; i++)
    {
        //se suman todas las iteraciones hasta n de la sucesion de bode
        sum+= sucesionBode(i);
    }
    return sum;
}
