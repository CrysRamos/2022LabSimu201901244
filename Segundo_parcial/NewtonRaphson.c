/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o NewtonRaphson.out NewtonRaphson.c -lm
Fecha:      04/26/22 
Librerías:  stdio, math, stdlib
Resumen:    El programa encuentra una aproximación de la raiz de una función con el metodo de Newton Raphson
*/
//Librerías
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//prototipos de funciones
float f(float x); //funcion original
float df(float x); // derivada de la funcion
void NewtonRaphson(float xi, float tol, int maxiter, int *aiter, float *sol); //aplicacion del metodo newton raphson

//funcion principal
void main (void){
    //definicion de variables
    float x_i, tolerancia, sol;
    int iteraciones, iteracionA;
    //Obtener e inicializar datos
    printf("Ingrese el valor aproximado de x: ");
    //se guarda el valor aproximado de la raiz en la variale x_i
    scanf("%f",&x_i);
    printf("Ingrese el valor de tolerancia: ");
    //se guarda el valor de la tolerancia en su respectiva variable
    scanf("%f",&tolerancia);
    printf("Ingrese el valor de las iteraciones: ");
    //se guarda el valor de cuantas iteraciones queremos que se hagan
    scanf("%d",&iteraciones);
    //se aplica el metodo de Newton Raphson con la funcion ya creada
    NewtonRaphson(x_i, tolerancia, iteraciones, &iteracionA, &sol);
    //condicional para saber si la funcion NewtonRaphson ya encontro la raiz de la funcion
    if (iteracionA == iteraciones)
        printf("\nNo hay solucion despues de %d iteraciones\n",iteraciones);
    else
    {
        printf("\nLuego de %d iteraciones la solucion es %.2f\n",iteracionA,sol);
    }
}

//funcion para representar la ecuación original
float f (float x){
    float eq=0;
    eq= x*x*x-2*x*x-3*x+10;
    return eq;
}
//funcion para representar la derivada de la ecuacion
float df(float x){
    float deq=0;
    deq= 3*x*x-4*x-3;
    return deq;
}

//Funcion que realiza el metodo de Newton Raphson
void NewtonRaphson(float xi, float tol, int maxiter, int *aiter, float *sol){
    //declaracion de variables locales de la funcion
    float xant, x, dif;
    int i=1;
    //se iguala el primer valor al anterior ya que es la primera iteracion
    xant=xi;
    //se aplica la formula del método de Newton
    x= xant- f(xant)/df(xant);
    //diferencia entre las primeras iteraciones
    dif= x-xant;
    //aplicando valor absoluto ya que solo se necesita saber que tan separados estan los valores
    (dif<0)?dif=-dif:dif;
    /*bucle que sigue evaluando las demas iteraciones hasta que se llegue 
    a la tolerancia ingresada y que no se sobrepase el numero de iteraciones*/
    while (dif>tol && i<maxiter)
    {        
        xant=x;
        x=xant-f(xant)/df(xant);
        //aumento de 1 a 1 en las iteraciones
        i++;
        dif = x-xant;
        (dif<0)?dif=-dif:dif; 
    }
    *sol=x;
    *aiter = i;
}