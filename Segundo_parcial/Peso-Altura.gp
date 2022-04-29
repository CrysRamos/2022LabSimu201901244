unset label
clear
set terminal jpeg
set output "pesoAltura.jpg"
set title "Problema 2"
set xlabel "metros"
set ylabel "libras"
set grid
set style data points
plot "pesoAltura"