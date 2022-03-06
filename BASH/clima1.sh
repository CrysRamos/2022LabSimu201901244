#!/bin/bash
#Enviar la información otenida del link al archivo climabash
curl wttr.in/Guatemala > /home/ejercicio1/climabash  
#Lee y muestra las primeras  lineas del documento climabash
head -n7 /home/ejercicio1/climabash
#Borra el archivo climabash
rm /home/ejercicio1/climabash
