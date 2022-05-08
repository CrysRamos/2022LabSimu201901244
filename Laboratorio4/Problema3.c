/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o Problema3.out Problema3.c -lm
Fecha:      05/07/22 
Librerías:  stdio, math
Resumen:    Programa que realiza suma, producto escalar y vectorial de 2 vectores 
*/
//Librerías
#include <stdio.h>
#include <math.h>
//prototipado de funciones
void imprimira(float datos[]);//funcion que imprime un vector de tipo flotante
void imprimir(int datos[]);//funcion que imprime un vector de tipo entero
void suma(int dato1[],int dato2[]);//funcion que suma dos vectores
float magnitud(int dato1[]);//funcion que encuentra la magnitud o modulo de un vector
float productopunto(int dato1[], int dato2[]);//funcion que hace el producto punto entre dos vectores
void productocruz(int dato1[], int dato2[]);//funcion que hace el producto cruz de dos vectores 
//variables globales
int n=3;
int main(){
    //declaracion de variables
    int posicion1[n], posicion2[n],sum[n];
    //inicializacion de primer vector a traves del ususario
    puts("**Vector 1**");
    for (int i = 0; i < n; i++)
    {
        printf("componente: ");
        //guarda el valor ingresado por el usuario en cada posicion del vector
        scanf("%d",&posicion1[i]);
    }
    //inicializacion del vector 2 a traves del usuario
    puts("**Vector 2**");
    for (int i = 0; i < n; i++)
    {
        printf("componente: ");
        //guarda elvalor ingresado en cada posicion del vector
        scanf("%d",&posicion2[i]);
    }
    //se muestra la maggnitud de cada vector con la funcion magnitud
    puts("a) MAGNITUD DE CADA VECTOR ");
    printf("\tvector1: %.2f\n",magnitud(posicion1));
    printf("\tvector2: %.2f\n",magnitud(posicion2));
    //se muestra la suma de los vectores con la funcion suma
    printf("b) SUMA DE LOS VECTORES (");
    suma(posicion1,posicion2);
    printf(")\n");
    //se muestra el producto interno con la funcion productopunto
    printf("c) PRODUCTO INTERNO: %.1f\n",productopunto(posicion1,posicion2));
    //se muestra el producto vectorial con la funcion productocruz
    printf("d) PRODUCTO VECTORIAL: " );
    productocruz(posicion1,posicion2);
    puts("\n");
}
void imprimira(float datos[]){
    //se imprime cada valor de un vector
    for (int i = 0; i < n; i++)
    {
        //se imprimen los datos del vector
        printf("%.1f  ",datos[i]);
    }
    
}
void imprimir(int datos[]){
    for (int i = 0; i < n; i++)
    {
        //se imprimen los datos del vector
        printf("%d  ",datos[i]);
    }
    
}
void suma(int dato1[],int dato2[]){
    //variable local que almacena el vector resultante
    int sum[n];
    //se suma el vector componente a componente
    for (int i = 0; i < n; i++)
    {
        sum[i]= dato1[i]+dato2[i];
    }
    //se imprime la resultante
    imprimir(sum);
}
float magnitud(int dato1[]){
    //variable local
    float resp;
    //raiz de la suma de cuadrados de las componentes de un vector
    resp= sqrt(pow(dato1[0],2)+pow(dato1[1],2)+pow(dato1[2],2));
    return resp;
}

float productopunto(int dato1[], int dato2[]){
    //declaro variable local
    float resp=0;
    //se suma la multiplicacion de cada componente de los vectores
    for (int i = 0; i < n; i++)
    {
        resp+= dato1[i]*dato2[i];
    }
    return resp;
}

void productocruz(int dato1[], int dato2[]){
    //varible local qque almacena el vector resultante
    float resp[n];
    //se hace la operacion para cada componente de la resultante
    resp[0]=dato1[1]*dato2[2]-dato1[2]*dato2[1];
    resp[1]=dato1[2]*dato2[0]-dato1[0]*dato2[2];
    resp[2]=dato1[0]*dato2[1]-dato1[1]*dato2[0];
    //se imprime elvector resultante
    imprimira(resp);
}
