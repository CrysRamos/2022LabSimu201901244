/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o Problema5.out Problema5.c 
Fecha:      05/11/22 
Librerías:  stdio
Resumen:    Programa que lee dos numeros, genera un rango entre estos y determina los numeros primos que hay en el rango 
*/
//Librerías
#include <stdio.h>
int esprimo(int n);
int main(){
    int N1,N2,i;
    printf("Ingrese un numero entero: ");
    scanf("%d",&N1);
    printf("Ingrese otro numero entero: ");
    scanf("%d",&N2);
    i=N1;
    while (i<=N2)
    {
        /* code */
        
        if (esprimo(i)==1)
        {
            /* code */
            printf("%d \n",i);
        }
        i=i+1;
    }
    
}
int esprimo(int n){
    //declaro e inicializo variables de procedimiento
    int j=2,primo=1;
    //bucle para valuar si el numero es primo, siempre que n sea mayor a 1
    while ( j<n && primo==1)
    {
        /* condicional para conocer el residuo de N/2 */
        if (n%j==0)
        {
            /* si el residuo es 0 variable primo cambia */
            primo=0;
        }
        else{
            // de lo contrario i aumenta en 1
            j=j+1;
        }
    }
    return primo;
}

