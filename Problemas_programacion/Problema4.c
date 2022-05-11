/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o Problema4.out Problema4.c 
Fecha:      05/11/22 
Librerías:  stdio
Resumen:    Programa que lee un valor mayor a 1 y determina si es primo 
*/
//Librerías
#include <stdio.h>
int main(){
    //declaro variable
    int N;
    //el usuario inicializa variable 
    puts("Ingrese un valor mayor a 1: ");
    scanf("%d",&N);
    //declaro e inicializo variables de procedimiento
    int i=2,primo=1;
    //bucle para valuar si el numero es primo, siempre que n sea mayor a 1
    while ( i<N-1 && primo==1)
    {
        /* condicional para conocer el residuo de N/2 */
        if (N%i==0)
        {
            /* si el residuo es 0 variable primo cambia */
            primo=0;
        }
        else{
            // de lo contrario i aumenta en 1
            i=i+1;
        }
    }
    if (primo==0)
    {
        /* si primo es cero entonces el numero no es primo */
        puts("No es un numero primo");
    }
    else
    {
        /* de los contrario es primo */
        puts("Es un numero primo");
    }
    
    
}
