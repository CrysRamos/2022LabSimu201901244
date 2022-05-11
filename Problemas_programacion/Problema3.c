/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o Problema3.out Problema3.c 
Fecha:      05/11/22 
Librerías:  stdio
Resumen:    programa que calcula la raiz cuadrada entera por defecto de un numero N 
*/
//Librerías
#include <stdio.h>
int main(){
    //declaracion de variable de entrada
    int N;
    // el usuario inicializa el valor de N
    puts("Ingrese un numero positivo: ");
    scanf("%d",&N);
    //se inicializa variable de salida
    int i=1;
    //bucle que busca la raiz incrementando de uno a uno hasta llegar a N
    while (i*i<=N)
    {
        i=i+1;
    }
    //se muestra el valor final de i-1
    printf("La raiz entera de %d es %d\n",N,i-1);
}
