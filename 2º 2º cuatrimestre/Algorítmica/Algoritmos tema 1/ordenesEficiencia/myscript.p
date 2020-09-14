set terminal gif xFFFFFF
set output "graficaComparacion.gif"
set xlabel "Tam. de Caso"
set ylabel "Tiempo"
set xrange [0:10]
set yrange [1:50]

plot 3*x title "O(n)", 0.5*x*x title "O(n^2)", 2**x title "O(2^n)", 7*log(x)+10 title "O(log(n))"
