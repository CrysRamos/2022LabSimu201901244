unset label
clear
set terminal jpeg
set output "pesoAltura.jpg"
set title "Problema 1"
set xlabel "metros"
set ylabel "libras"
set grid
set style data points
plot "pesoAltura" using 1:3:2:4 with xyerrorbars , 126.597*x-60.740