/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o Problema1.out Problema1.c 
Fecha:      05/07/22 
Librerías:  stdio
Resumen:    programa que ordena un vector de forma ascendente o descendente, según lo indique el usuario   
*/
//Librerías
#include <stdio.h>
//prototipo de funciones
void imprimira(int datos[]); // funcion para imprimir los datos de forma ascendente
void imprimird(int datos[]); // funcion para imprimir los datos de forma descendente
int main(){
    //declaracion de variables
    int nums[10];
    char op;
    //inicializacion de vector
    for (int i = 0; i < 10; i++)
    {
    //se llena el vector solo con numeros pares del 2 al 20
        nums[i]=2+2*i;
    }
    //se muestra al usuario el menú
    puts("**Menú**");
    printf("a Mostrar vector en orden ascendente\nd Mostrar vector en orden descendente\nx salir\n");
    //se le solicita al usuario la opción
    printf("ingrese una opcion: ");
    //se guarda la opcion solicitada por el usuario en la variable op
    scanf("%c", &op);
    //ciclo para que el programa no termine hasta que el usuario ingrese la opcion de salir
    while (op!='x')
    {
        //casos del menu
       switch (op)
    {
    case 'a':
        puts("vector ascendente");
        //se imprime el vector con la funcion ascendente
        imprimira(nums);
        //se guarda la opcion solicitada por el usuario en la variable op
        scanf("%c", &op);
        break;
    case 'd':
        puts("vector descendente");
        //se imprime el vector con la funcion descendente
        imprimird(nums);
        scanf("%c", &op);
        break;
    case 'x':
        puts("Salida exitosa");
        break;
    default:
        puts("Ingrese otra opcion");
        scanf("%c", &op);
        break;
    }
    }
    
    
    
}
void imprimira(int datos[]){
    for (int i = 0; i < 10; i++)
    {
        //se imprimen los datos del vector
        printf("%d ",datos[i]);
    }
    puts("\n");
}
void imprimird(int datos[]){
    for (int i = 9; i >= 0; i--)
    {
        //se imprimen los datos del vector
        printf("%d ",datos[i]);
    }
    puts("\n");
}