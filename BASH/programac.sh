#!/bin/bash
read -p "Ingrese nombre del archivo:" archivo
if [[ -e $archivo.c ]]; then 
    echo "El archivo ya existe"
else
    touch $archivo.c
    echo "/*" >> $archivo.c
    echo "Autor: " $USER >> $archivo.c
    gcc --version >> version.txt
    echo "Compilador: $(head -n1 version.txt) ">> $archivo.c
    rm version.txt
    echo "Compilado: gcc -o $archivo.out $archivo.c ">> $archivo.c
    echo "Fecha: $(date +%D) " >> $archivo.c
    echo "Librerías: " stdio >> $archivo.c
    read -p "Ingrese un resumen del archivo:" resumen
    echo "Resumen: $resumen " >> $archivo.c
    read -p "Ingrese las entradas del archivo:" entradas
    echo "Entradas: $entradas " >> $archivo.c
    read -p "Ingrese las salidas del archivo:" salidas
    echo "Salidas: $salidas " >> $archivo.c
    echo "*/" >> $archivo.c
    echo //Librerías >> $archivo.c
    echo "#include <stdio.h>" >> $archivo.c
    echo //Enumere el pseudocódigo >> $archivo.c
fi