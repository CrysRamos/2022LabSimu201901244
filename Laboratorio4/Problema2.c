/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o Problema2.out Problema2.c 
Fecha:      05/07/22 
Librerías:  stdio
Resumen:    Programa que ordena de forma ascendente el vector ingresado por el ususario 
*/
//Librerías
#include <stdio.h>
//prototipos de funciones
void imprimir(int datos[]);//funcion para imprimir vector
void metodoburbuja(int dato[]);//funcion que aplica el ordenamiento de burbuja
//variables globales
int n=5;
int main(){
    //declaro varible del vector
    int nums[n];
    //el ususario inicializa el vetor
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese un valor entero: ");
        scanf("%d", &nums[i]);
    }
    //se muestra el vector ingresado
    puts("vector ingresado:\n");
    imprimir(nums);
    puts("Vertor Ordenado:\n");
    metodoburbuja(nums);
    puts("FIN");
}
void imprimir(int datos[]){
    for (int i = 0; i < n; i++)
    {
        //se imprimen los datos del vector
        printf("%d ",datos[i]);
    }
    puts("\n");
}
void metodoburbuja(int dato[]){
    //se declaran variables de control del ordenamiento burbuja
    int interruptor = 1;
    int pasada, j;
    //bucle que controla la cantidad de pasadas
    for (pasada = 0; pasada < n-1 && interruptor; pasada++)
    {
        interruptor = 0;
        //maneja el paso por el vector
        for (j = 0; j < n-pasada-1; j++)
        {
            //validando que el seleccionado sea mayor al siguiente
            if (dato[j] > dato[j+1])
            {
                int aux;
                //se cambia la posicion del valor
                aux = dato[j];
                dato[j] = dato[j+1];
                dato[j+1] = aux;
                
            }
            interruptor = 1;
        }   
    }
    imprimir(dato);
}