set terminal gif xFFFFFF
set output "graficaTiempos.gif"
set xlabel "Tam. de Caso n"
set ylabel "Tam. de Caso m"
set zlabel "Tiempo"

splot "tiemposSalida.txt"
