/*
Autor:      anaramos
Compilador: gcc (Ubuntu 9.3.0-17ubuntu1~20.04) 9.3.0 
Compilado:  gcc -o Problema1.out Problema1.c -lm
Fecha:      05/16/22 
Librerías:  stdio, math, stdlib
Resumen:    programa que simula el movimiento de tres cohetes 
*/
//Librerías
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
//definimos constantes a utilizar
#define G 6.693*pow(10,-11)
#define RT 6.378*pow(10,6)
#define MT 5.97*pow(10,24)
#define R 287.06
#define L 6.5*pow(10,-3)
#define go 9.81
#define TO 288.15
#define Po 101325
//prototipado de funciones
void cohete1(float t, float h, float v, float y0);
void cohete2(float t, float h, float v, float y0);
void cohete3(float t, float h, float v,float y0);
float fmasa(float E, float TSFC,float mo, float mfo,float t);
float dmasa(float a, float e);
float densidad(float y);
float gravedad(float y);
float fa(float y,float E, float tsfc, float mo, float mfo,float t, float CD, float A,float vo);
float aceleracion(float mo,float TSFC,float E,float mfo,float t,float h, float CD,float A,float vo);
float velocidad(float vo,float e, float tsfc, float cd, float A, float mo, float mfo,float t, float h);
float posicion(float yo, float E, float tsfc, float cd,float A, float mo, float mfo, float t, float v);
int main(){
    //variables locales y condiciones iniciales
    float t=0,y=0.44,v=0, h=0.1;
    puts("Cohete 1: AH MUN \n");
    cohete1(t,h,v,y);
    puts("Cohete 2: AHAU KIN \n");
    cohete2(t,h,v,y);
    puts("Cohete 3: CHAC");
    cohete3(t,h,v,y);
}

float fmasa(float E, float TSFC,float mo, float mfo,float t){
    float fmasa;
    //masa en funcion del tiempo
    fmasa= mo-(TSFC*E*t+mfo);
    return fmasa;
}
float dmasa(float a, float e){
    float f;
    f= -a*e;
    return f;
}
float densidad(float y){
    float densidad;
    //densidad en funcion de y
    densidad= Po/(R*TO)*pow((1- (L*y)/TO),go/(R*L));
    return densidad;
}
float gravedad(float y){
    float gravedad;
    //graveddad en funcion de la altura
    gravedad= (G*MT)/(pow(RT+y,2));
    return gravedad;
}
float fa(float y,float E, float tsfc, float mo, float mfo,float t, float CD, float A,float vo){
    float fa;
    //fuerza en funcion de densidad y velocidad
    fa= densidad(y)/2 *CD*A*velocidad(vo,E,tsfc,CD,A,mo,mfo,t,y)*sqrt(velocidad(vo,E,tsfc,CD,A,mo,mfo,t,y)*velocidad(vo,E,tsfc,CD,A,mo,mfo,t,y));
    return fa;
}
float aceleracion(float mo,float TSFC,float E,float mfo,float t,float h, float CD,float A,float vo){
    float f;
    //ecuacion diferencial
    f= (E-fa(h,E,TSFC,mo,mfo,t,CD,A,vo)-fmasa(E,TSFC,mo,mfo,t)*gravedad(h))/fmasa(E,TSFC,mo,mfo,t);
    return f;
}
float velocidad(float vo,float e, float tsfc, float cd, float A, float mo, float mfo,float t, float h){
    float v; 
    v= vo + aceleracion(mo,tsfc,e,mfo,t,h,cd,A,vo)*t;
    return v;
}
float posicion(float yo, float E, float tsfc, float cd,float A, float mo, float mfo, float t, float v){
    float resp;
    resp= velocidad(v,E,tsfc,cd,A,mo,mfo,t,yo)*t+1/2 *aceleracion(mo,tsfc,E,mfo,t,yo,cd,A,v)*pow(t,2);
    return resp;
}






void cohete1(float t, float h, float v,float y0){
    float Eo=3*pow(10,7), TSFC=3.248*pow(10,-4), CD=61.27;
    float A=201.06,mo=1.1*pow(10,5),mfo=1.5*pow(10,6),mf=mfo,a=0;
    printf("Empuje del cohete \t%f\n", Eo);
    printf("consumo especifico del empuje %f\n",TSFC);
    printf("Coeficiente de forma\t %f\n",CD);
    printf("seccion transversal del cohete %f\n",A);
    printf("masa del propulsor \t%f\n",mo);
    printf("masa inicial del combusible %f\n",mfo);
    while (mf>=0 && y0>=0)
    {
        /* hacemos el metodo numerico de euler */
        mf+= dmasa(TSFC,Eo);
        if (mf==0)
        {
        /* mostramos el tiempo cuando mf=0 */
        printf("el timpo en el que se agota el combustible es %f\n",t);
        }
        //valuamos posicion en condiciones iniciales y aplicamos metodo de euler
        y0+= posicion(y0,Eo,TSFC,CD,A,mo,mfo,t,v);
        if (y0==0)
        {
            /* mostramos el tiempo en el que cae al suelo */
            printf("El timpo que tardo en caer al suelo es de %f\n",t);
        }
        
        //valuamos velocidad con condiciones iniciales y aplicamos metodo numerico
        v+= velocidad(v,Eo,TSFC,CD,A,mo,mfo,t,y0);
        if (v==0 && y0!=0)
        {
            /* velocidad es cero en la altura maxima */
            printf("La altura maxima alcanzada es %f\n",y0);
        }
        //valuamos aceleracion en t=0, v=0 y=0.44 y aplicamos metodo numerico
        a+= aceleracion(mo,TSFC,Eo,mfo,t,y0,CD,A,v);
        t+=h; //aumentamos el tiempo
    }

    
    
}
void cohete2(float t, float h, float v, float y0){
    float Eo=2.7*pow(10,7), TSFC=2.248*pow(10,-4), CD=61.27;
    float A=201.06,mo=1.1*pow(10,5),mfo=1.5*pow(10,6), mf=mfo, a=0;
    printf("Empuje del cohete \t%f\n", Eo);
    printf("consumo especifico del empuje %f\n",TSFC);
    printf("Coeficiente de forma\t %f\n",CD);
    printf("seccion transversal del cohete %f\n",A);
    printf("masa del propulsor \t%f\n",mo);
    printf("masa inicial del combusible %f\n",mfo);
    while (mf>=0 && y0>=0)
    {
        /* hacemos el metodo numerico de euler */
        mf+= dmasa(TSFC,Eo);
        if (mf==0)
        {
        /* mostramos el tiempo cuando mf=0 */
        printf("el timpo en el que se agota el combustible es %f\n",t);
        }
        //valuamos posicion en condiciones iniciales y aplicamos metodo numerico
        y0+= posicion(y0,Eo,TSFC,CD,A,mo,mfo,t,v);
        if (y0==0)
        {
            /* mostramos el tiempo en el que cae al suelo */
            printf("El timpo que tardo en caer al suelo es de %f\n",t);
        }
        
        //valuamos velocidad con condiciones iniciales y aplicamos metodo numerico
        v+= velocidad(v,Eo,TSFC,CD,A,mo,mfo,t,y0);
        if (v==0 && y0!=0)
        {
            /* velocidad es cero en la altura maxima */
            printf("La altura maxima alcanzada es %f\n",y0);
        }
        //valuamos aceleracion en t=0, v=0 y=0.44 y aplicamos metodo numerico
        a+= aceleracion(mo,TSFC,Eo,mfo,t,y0,CD,A,v);
        t+=h; //aumentamos el tiempo
    }

}
void cohete3(float t, float h, float v, float y0){
    float Eo=2.5*pow(10,7), TSFC=2.248*pow(10,-4), CD=70.25;
    float A=215.00,mo=1.8*pow(10,5),mfo=2.1*pow(10,6), mf=mfo, a=0;
    printf("Empuje del cohete \t%f\n", Eo);
    printf("consumo especifico del empuje %f\n",TSFC);
    printf("Coeficiente de forma\t %f\n",CD);
    printf("seccion transversal del cohete %f\n",A);
    printf("masa del propulsor \t%f\n",mo);
    printf("masa inicial del combusible %f\n",mfo);
    while (mf>=0 && y0>=0)
    {
        /* hacemos el metodo numerico de euler */
        mf+= dmasa(TSFC,Eo);
        if (mf==0)
        {
        /* mostramos el tiempo cuando mf=0 */
        printf("el timpo en el que se agota el combustible es %f\n",t);
        }
        //valuamos posicion en condiciones iniciales y aplicamos metodo numerico
        y0+= posicion(y0,Eo,TSFC,CD,A,mo,mfo,t,v);
        if (y0==0)
        {
            /* mostramos el tiempo en el que cae al suelo */
            printf("El timpo que tardo en caer al suelo es de %f\n",t);
        }
        
        //valuamos velocidad con condiciones iniciales y aplicamos metodo de euler
        v+= velocidad(v,Eo,TSFC,CD,A,mo,mfo,t,y0);
        if (v==0 && y0!=0)
        {
            /* velocidad es cero en la altura maxima */
            printf("La altura maxima alcanzada es %f\n",y0);
        }
        //valuamos aceleracion en t=0, v=0 y=0.44 y aplicamos metodo de euler
        a+= aceleracion(mo,TSFC,Eo,mfo,t,y0,CD,A,v);
        t+=h; //aumentamos el tiempo
    }

}
