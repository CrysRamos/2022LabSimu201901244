unset label
clear
set terminal jpeg
set output "newtonraphson.jpg"
set title "Problema 2"
set xlabel "x"
set ylabel "f(x)"
set grid
set style data linespoints
plot [-5:5] [-10:20] x**3-2*x*x-3*x+10