/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o Problema4.out Problema4.c -lm
Fecha:      05/08/22 
Librerías:  stdio, math
Resumen:    Programa que realiza distintas operaciones entre dos matrices de 3x3 y una constante  
*/
//Librerías
#include <stdio.h>
#include <math.h>

//declaro e inicializo variable global
int n=3;
//prototipado de funciones
void llenar(int matriz[n][n]);//funcion para llenar una matriz de 3x3
void imprimir(int matriz[n][n]);//funcion para imprimir matriz de tipo int
void imprimirf(float matriz[n][n]);//funcion para imprimir matriz de tipo float
void multiconst(int matriz[n][n], int c);//funcion que multiplica una matriz por una constante
void suma(int m1[n][n],int m2[n][n]);//funcion que suma dos matrices
void resta(int m1[n][n],int m2[n][n]);//funcion que resta dos matrices
void multiplicar(int m1[n][n],int m2[n][n]);//funcion que multiplica dos matrices
void transpuesta(int m[n][n]);//funcion que saca la transpuesta de una matriz
int determinante(int m[n][n]);//funcion que calcula el determinante de una matriz 3x3
void inversa(int m[n][n],float det);//funcion que calcula la inversa de una matriz

int main(){
    //declaracion de variables
    int cte, matA[n][n], matB[n][n];
    //el ususario ingresa una constante
    puts("Ingrese una constante c: ");
    scanf("%d",&cte);
    //el usuario llena la matriz A
    puts("Ingrese una matriz A de 3x3");
    llenar(matA);
    //el usuario llena la matriz B
    puts("\nIngrese una matriz B de 3x3");
    llenar(matB);
    //se muestra la matriz A por la constante
    printf("\na) matA por constante:");
    multiconst(matA,cte);
    //se muestra la suma de las dos matrices
    printf("b) Suma de las dos matrices:");
    suma(matA,matB);
    //se muestra la resta de las matrices
    printf("c) resta de las dos matrices:");
    resta(matA,matB);
    //se muestra la multiplicacion de las matrices
    printf("d) Multiplicacion de las 2 matrices:");
    multiplicar(matA,matB);
    //se muestra el determinante de la matriz A
    printf("e) Determinante de matA: %d\n", determinante(matA));
    //se muestra la transpuesta de la matriz B
    printf("f) Transpuesta de matB:");
    transpuesta(matB);
    printf("g) Inversa de matA:");
    //condicional para saber si existe inversa de la matriz A
    if (determinante(matA)==0)
    {
        puts("La matriz A no tiene inversa");
    }
    else{
        //se muestra la inversa de la matriz A
        inversa(matA,1/determinante(matA));
    }
}

void llenar(int matriz[n][n]){
    //ciclo que recorre las filas
    for (int i = 0; i < n; i++)
    {
        /* se recorre las columnas*/
        for (int j = 0; j < n; j++)
        {
            /* se pide al usuario llenar la matriz */
            printf("valor en la posicion %d,%d: ",i,j);
            scanf("%d",&matriz[i][j]);
        }
        
    }
}

void imprimir(int matriz[n][n]){
    //ciclo for doble que recorre toda la matriz
    for(int i=0;i<n;i++){
        printf("\n");
        for(int j=0;j<n;j++){
            //impresion de loss valores ij
            printf("%d\t",matriz[i][j]);
        }
    }
    puts("\n");
}

void imprimirf(float matriz[n][n]){
    //ciclo for doble que recorre toda la matriz
    for(int i=0;i<n;i++){
        printf("\n");
        for(int j=0;j<n;j++){
            //impresion de loss valores ij
            printf("%.2f\t",matriz[i][j]);
        }
    }
    puts("\n");
}
void multiconst(int matriz[n][n], int c){
    //se recorren filas
    for (int i = 0; i < n; i++)
    {
        /* se recorre las columnas*/
        for (int j = 0; j < n; j++)
        {
            /* se hace la multiplicacion por escalar de cada componente */
            matriz[i][j]=c*matriz[i][j];
        }
        
    }
    imprimir(matriz);
}

void suma(int m1[n][n],int m2[n][n]){
    int m[n][n];
    //se recorren filas
    for (int i = 0; i < n; i++)
    {
        /* se recorre las columnas*/
        for (int j = 0; j < n; j++)
        {
            /* se hace la multiplicacion por escalar de cada componente */
            m[i][j]=m1[i][j]+m2[i][j];
        }
        
    }
    imprimir(m);
}

void resta(int m1[n][n],int m2[n][n]){
    int m[n][n];
    //se recorren filas
    for (int i = 0; i < n; i++)
    {
        /* se recorre las columnas*/
        for (int j = 0; j < n; j++)
        {
            /* se hace la multiplicacion por escalar de cada componente */
            m[i][j]=m1[i][j]-m2[i][j];
        }
        
    }
    imprimir(m);
}

void multiplicar(int m1[n][n],int m2[n][n]){
    int producto[n][n];
    // Necesitamos recorrer cada columna de la matB
    for (int a = 0; a < n; a++) {
        // Dentro recorremos las filas de matA
        for (int i = 0; i < n; i++) {
            int suma = 0;
            // Y cada columna de matA
            for (int j = 0; j < n; j++) {
                // Multiplicamos y sumamos resultado
                suma += m1[i][j] * m2[j][a];
            }
            // Lo acomodamos dentro del producto
            producto[i][a] = suma;
        }
    
    }
    imprimir(producto);
}

void transpuesta(int m[n][n]){
    int resp[n][n];
    //ciclo que recorre las filas
    for (int i = 0; i < n; i++)
    {
        /* se recorre las columnas*/
        for (int j = 0; j < n; j++)
        {
            //se cambian filas por columnas
            resp[i][j]=m[j][i]; 
        }
        
    }
    imprimir(resp);
}

int determinante(int m[n][n]){
    int determinante;
    //determinante de 3x3 con la regla de sarrus
        determinante= (m[0][0]*m[1][1]*m[2][2])+(m[0][1]*m[1][2]*m[2][0])+
        (m[1][0]*m[2][1]*m[0][2])-(m[2][0]*m[1][1]*m[0][2])-
       (m[2][1]*m[1][2]*m[0][0])-(m[1][0]*m[0][1]*m[2][2]);
    return determinante;
}
void inversa(int m[n][n],float det){
    int adjunta[n][n],Tadjunta[n][n];
    float inversa[n][n];
    adjunta[0][0]= m[1][1]*m[2][2]-m[2][1]*m[1][2];
    adjunta[0][1]= m[1][0]*m[2][2]-m[2][0]*m[1][2];
    adjunta[0][2]= m[1][0]*m[2][1]-m[2][0]*m[1][1];
    adjunta[1][0]= m[0][1]*m[2][2]-m[2][1]*m[0][2];
    adjunta[1][1]= m[0][0]*m[2][2]-m[2][0]*m[0][2];
    adjunta[1][2]= m[0][0]*m[2][1]-m[2][0]*m[0][1];
    adjunta[2][0]= m[0][1]*m[1][2]-m[1][1]*m[0][2];
    adjunta[2][1]= m[0][0]*m[1][2]-m[1][0]*m[0][2];
    adjunta[2][2]= m[0][0]*m[1][1]-m[1][0]*m[0][1];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            adjunta[i][j]= pow(-1,i+j)*adjunta[i][j];
        }
        
    }
    //se saca la transpuesta a la adjunta
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            Tadjunta[i][j]=adjunta[j][i]; 
        }
        
    }
    //se multiplica la transpuesta por 1/determinante
    for (int i = 0; i < n; i++)
    {
        /* se recorre las columnas*/
        for (int j = 0; j < n; j++)
        {
            /* se hace la multiplicacion por escalar de cada componente */
            inversa[i][j]=(float)det*Tadjunta[i][j];
        }
        
    }
    imprimir(inversa);
    
    
}


void gauss(int m[n][n]){
    float matriz[n][n];
    for (int i = 0; i < n; i++)
    {
        /* se divide toda la primera fila entre el valor a_11 de la matriz  */
        matriz[0][i]= m[0][i]/m[0][0];
    }
    //operacion para modiicar la fila 2
    for (int i = 0; i < n; i++)
    {
        /* se resta la fila2-a_21*fila1 */
        matriz[1][i]= (m[1][i]- m[1][0]*matriz[0][i])/(m[1][1]- m[1][0]*matriz[0][1]) ;
        //la nueva fila2 se divide entre el valor a_22
        //matriz[1][i]= matriz[1][i]/matriz[1][1];
    }
    //operacion para modificar la fila 3
    for (int i = 0; i < n; i++)
    {
        /* se resta la fila3-a_31*fila1  */
        matriz[2][i]=(m[2][i]- m[2][0]*matriz[0][i])- (m[2][i]- m[2][1]*matriz[1][i]);
        /* se resta la fila3-a_32*fila2  */
        //matriz[2][i]=matriz[2][i]- matriz[2][1]*matriz[1][i] ;
        //la nueva fila3 se divide entre el valor a_33
        //matriz[2][i]= matriz[2][i]/matriz[2][2];

    }
    imprimirf(matriz);    
}