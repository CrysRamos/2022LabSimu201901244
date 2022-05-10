/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o Problema5.out Problema5.c 
Fecha:      05/08/22 
Librerías:  stdio
Resumen:    Programa que calcula el factorial de un número con funcion recursiva
*/
//Librerías
#include <stdio.h>
//Prototipado de funciones
long long int factorialn(long long int n);

int main(void) {
    //numero al que se le va calcular el factorial
    int numero;
    //el usuario ingresa el numero
    printf("Ingrese un numero entero para calcular el factorial: ");
    scanf("%d", &numero);
    //se imprime el valor del factorial
    printf("El factorial de %d es %lld\n", numero, factorialn(numero));
}

long long int factorialn(long long int n) {
    // Si hemos llegado a 1, detenemos la recursión
    if (n <= 1){
        //1! y 0! son 1
        return 1;
    }
    else{
        //se multiplican los valores disminuyendo 
        return n * factorialn(n - 1); // Se resta 1 
    }  
    
}
