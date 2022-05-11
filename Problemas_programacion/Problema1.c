/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o Problema1.out Problema1.c 
Fecha:      05/11/22 
Librerías:  stdio
Resumen:    Programa que lee 3 numeros y devuelve la media de los positivos  
*/
//Librerías
#include <stdio.h>
int main(){
    //1. declaro e inicializo mis variables
    float x=0, media=0;
    int i=0, n=0;
    //2. validar el numero de elemento ingresados hasta que llegue a 3
    puts("Calculadora de media aritmetica");
    while (i<3)
    {
    //3. solicitar al usuario ingresar el valor del numero
        puts("Ingrese un numero: ");
        scanf("%f",&x);
    //4. validar que este sea positivo o 0
        if (x>=0)
        {
    //5. Si verdadero acumular la cantidad de elementos positivos y sumar su valor
            n++;
            media+=x;
        }
        i++;
    }
    //6. validar si todos los numeros son negativos
    if (n==0)
    {
    //7. Si verdadero imprimir mensaje no numeros positivos
        puts("Los valores ingresados eran nagativos");
    }else
    {
    //8. Si falso imprimir la media arimetica
        printf("La media aritmetica de los datos es: %.2f \n", media/n);
    }

    return 0;  
}
