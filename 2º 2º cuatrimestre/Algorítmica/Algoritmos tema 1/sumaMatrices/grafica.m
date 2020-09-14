clear all;
A= load('tiemposSalida.txt');

X= 1000:500:5000;
Y= X;

k= 1;
for i=1:length(X)
    for j=1:length(Y)
        Z(i,j)= A(k,3);
        k= k+1;
    end
end

surf(X, Y, Z);