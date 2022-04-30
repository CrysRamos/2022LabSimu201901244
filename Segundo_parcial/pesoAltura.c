/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o pesoAltura.out pesoAltura.c -lm
Fecha:      04/29/22 
Librerías:  stdio, math
Resumen:    programa que calcula la recta que mejor aproxima el crecimiento y estima el peso según su altura  
*/
//Librerías
#include <stdio.h>
#include <math.h>

//declaro e inicializo variables globales
float altura[]={70,63,72,60,66,70,74,65,62,67,65,68}, peso[]={155,150,180,135,156,168,178,160,132,145,139,152};
//Obtenemos el número de elementos dividiento el tamaño del vector entre el tamaño de un elemento
int n = sizeof(altura)/sizeof(altura[0]);

//prototipo de funciones
void imprimir(float datos[]); // funcion para imprimir los datos
float estimacion(float altura,float dato1, float dato2); // funcion para estimar el peso en base a la altura
float propagacionError(float altura, float dato1, float erdato1, float erdato2,float eraltura);//funcion para propagar el error
float suma(float datos[]); //funcion para sumar los valores de un vector
float sumaMulti(float datos1[], float datos2[]); //funcion para sumar la multiplicacion de dos vectores

void main(){
    //declaración de variables para encontrar la recta que mejor aproxima el crecimiento
    float erorx, errorm, errorb, b, m, r, alturametros[n], estatura, pesoEst, errpesoEst;
    erorx= 0.002;
    //ciclo for para cambiar los datos dados en pulgadas a metros
    for (int i = 0; i < n; i++)
    {
        alturametros[i]= altura[i]*0.0254;
    }
    //impresion de los valores experimentales de peso
    puts("Valor de los datos de peso en lb");
    imprimir(peso);
    //impresión de los valores experimentales de altura en metros
    puts("Valor de los datos de estatura en m");
    imprimir(alturametros);

    //los valores de ecuacion lineal, por medio de minimos cuadrados
    m = (n*sumaMulti(alturametros,peso)-(suma(alturametros)*suma(peso)))/(n*sumaMulti(alturametros,alturametros)-(suma(alturametros)*suma(alturametros)));
    errorm= (sqrt(n)*erorx)/(sqrt(n*sumaMulti(alturametros,alturametros)-suma(alturametros)*suma(alturametros)));
    b = (suma(peso)-m*suma(alturametros))/n;
    errorb= erorx/sqrt(n);
    r = (n*sumaMulti(alturametros,peso)-(suma(alturametros)*suma(peso)))/sqrt((n*sumaMulti(alturametros,alturametros)-(suma(alturametros)*suma(alturametros)))*(n*sumaMulti(peso,peso)-(suma(peso)*suma(peso))));
    //imprime la ecuacion lineal
    printf("Ecuacion que describe el crecimiento del peso en base a la altura: y= (%.3f+-%.3f)(x+-%.3f) + (%.3f+-%.3f)\n",m,errorm,erorx,b,errorb);
    //imprime coeificiente de determinacion el r cuadrado
    printf("Coeficiente de determinacion: %.3f\n",r*r);
    //Se pide al usuario ingresar una altura
    printf("\n**Ingrese una altura en (m) para estimar su peso:** ");
    scanf("%f", &estatura);
    //condicional para validar que la altura ingresada sea valida
    if (estatura<=0)
    {
        puts("Altura ingresada invalida");
    }
    else{
        pesoEst= estimacion(estatura,m,b);
        errpesoEst= propagacionError(estatura,m,errorm,errorb,erorx);
        printf("Su peso estimado es de %.3f+-%.3f lb\n",pesoEst, errpesoEst);
    }
    
}

void imprimir(float datos[]){
    for (int i = 0; i < n; i++)
    {
        //se imprimen los datos para cada iteracion menor a n el tamaño del vector
        printf("%.1f ",datos[i]);
    }
    puts("\n");
}

float estimacion(float altura, float dato1, float dato2){
    //declaro variable local
    float y;
    //ecuacion que estima el peso en relación a la altura
    y= dato1*altura+dato2;
    return y;
}

float propagacionError(float altura, float dato1, float erdato1, float erdato2,float eraltura){
    //declaro variable local
    float errory;
    //aplico formula de propagacion de errores para multiplicación y suma
    errory= sqrt((erdato1/dato1)*(erdato1/dato1)+(eraltura/altura)*(eraltura/altura))+erdato2;
    return errory;
}
    


//reliza la suma de los elementos de un vector ingresado
float suma(float datos[]){
    //declaración e inicialización de variables locales
    float resp = 0;
    for (int i = 0; i < n; i++)
    {
        //suma cada valor en la posicion i del vector
        resp += datos[i];
    }
    return resp;
}

//realiza la suma de los elementos de dos vectores ingresados
float sumaMulti(float datos1[], float datos2[]){
    float resp = 0;
    for (int i = 0; i < n; i++)
    {
        //suma la multiplicación de cada valor del vector
        resp += datos1[i]*datos2[i];
    }
    return resp;
}