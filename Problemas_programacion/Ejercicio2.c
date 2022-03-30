/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o Ejercicio2.out ejercicio2.c 
Fecha:      03/18/22 
Librerías:  stdio
Resumen:    El programa calcula la media aritmética de los números ingresados
*/
//Librerías
#include <stdio.h>
//1. declaro e inicializo mis variables
    int x=0, n=0, min=0, max=0;
    float med=0;
int main()
{   
//2. Leer los datos ingresados
    puts("**Ingrese alturas enteras, para finalizar el programa ingrese una altura negativa**");
    puts("Ingrese una altura: ");
    scanf("%d", &x);
//3. se guarda el primer valor en maximo  minimo
    min=x;
    max=x;
//4. Validar que la altura sea mayor a cero
    while (x >= 0)
    {
        n++;
        med += x;
        if (x>max)
        {
            //5. Para cada valor ingresado busca el max
            max=x;
        }
        if (x<min)
        {
            //6. Para cada valor ingresado busca el min
            min=x;
        }
        //7. Lee mas valores de alturas
        puts("Ingrese otra altura: ");
        scanf("%d", &x);
        
    }
    //8. Verifica que se haya ingresado al menos un valor
    if (n==0)
    {
        puts("No ingreso alturas validas");
    }
    else
    {
        //9. Devuelve la media, maximo y minimo
        med=med/n;
        printf("De los valores ingresados: La media es: %f, \n El valor maximo es: %d \n El valor minimo es: %d\n",med,max,min);
    }
    return 0;
}


