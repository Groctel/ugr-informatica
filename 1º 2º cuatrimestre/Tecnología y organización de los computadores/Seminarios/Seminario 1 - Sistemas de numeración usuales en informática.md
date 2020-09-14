# SISTEMAS DE NUMERACIÓN USUALES EN INFORMÁTICA

## 1 - REPRESENTACIÓN POSICIONAL DE LOS NÚMEROS

El valor de una cifra dentro de un número depende de su posición en el conjunto de la base en la que se encuentra (valor absoluto) y en el propio número.

x)<sub>b</sub> = ... + n·b<sup>3</sup> + n·b<sup>1</sup> + n·b<sup>2</sup> + n·b<sup>0</sup> + n·b<sup>-1</sup> + n·b<sup>-2</sup> + n·b<sup>-3</sup> + ...

### 1.1 - BASES COMUNES DE CONTEO

- B<sub>10</sub> = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
  - 9271,64)<sub>10</sub> = 9·10<sup>3</sup> + 2·10<sup>2</sup> +7·10<sup>1</sup> + 1·10<sup>0</sup> + 6·10<sup>-1</sup> + 4·10<sup>-2</sup> = 9000 + 200 + 70 + 1 + 0,6 + 0,04
- B<sub>2</sub> = {0, 1}
- B<sub>8</sub> = {0, 1, 2, 3, 4, 5, 6, 7}
- B<sub>16</sub> = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F}

### 1.2 - ALGORITMOS DE CAMBIO DE BASE

Sabiendo el valor decimal que adquiere una cifra en función de su valor absoluto y su posición  podemos usar el algoritmo de base 10 para encontrar el valor decimal de un número.

- 1101,011)<sub>2</sub> = 1·2<sup>3</sup> + 1·2<sup>2</sup> + 0·2<sup>1</sup> + 1·2<sup>0</sup> + 0·2<sup>-1</sup> + 1·2<sup>-2</sup> + 1·2<sup>-3</sup> = 8 + 2 + 1 + 0.25 + 0.125 = 11375)<sub>10</sub>

Para tomar el valor en base 2 de un número natural en base 10 se divide recursivamente dicho número entre 2 y se leen los restos en orden inverso.

###### 53)<sub>10</sub> → 110101)<sub>2</sub>
```mathematica
53 / 2 = 26   53 % 2 = 1
26 / 2 = 13   26 % 2 = 0
 13 / 2 = 6   13 % 2 = 1
  6 / 2 = 3   6 % 2 = 0
  3 / 2 = 1   3 % 2 = 1
  1 / 2 = 0   1 % 2 = 1
        53  =  110101
```

Para tomar el valor en base 2 de la parte decimal de un número en base 10 se multiplica recursivamente dicho número por 2 y se lee la parte entera en orden directo. Al igual que ocurre en base decimal al dividir 10<sup>n</sup>/3, es posible que queden decimales infinitos.

###### 0,423)<sub>10</sub> → 01101...)<sub>2</sub>
```mathematica
0.423 * 2 = 0,846 --> 0
0.846 * 2 = 1.692 --> 1
0.692 * 2 = 1.384 --> 1
0.384 * 2 = 0.768 --> 0
0.768 * 2 = 1.536 --> 1...
```

## 2 - SISTEMA DE NUMERACIÓN EN BASE 2

## 3 - CÓDIGOS INTERMEDIOS

Los códigos intermedios son bases cuyo cardinal es potencia de 2 y sirven para hacer más legible el texto escrito en binario. La más utilizada es la base hexadecimal (16 dígitos).

| HEXADECIMAL | DECIMAL | BINARIO |
| :---: | :---: | :---: |
| 0 | 0 | 0000 |
| 1 | 1 | 0001 |
| 2 | 2 | 0010 |
| 3 | 3 | 0011 |
| 4 | 4 | 0100 |
| 5 | 5 | 0101 |
| 6 | 6 | 0110 |
| 7 | 7 | 0111 |
| 8 | 8 | 1000 |
| 9 | 9 | 1001 |
| A | 10 | 1010 |
| B | 11 | 1011 |
| C | 12 | 1100 |
| D | 13 | 1101 |
| E | 14 | 1110 |
| F | 15 | 1111 |

Podemos pasar de decimal a hexadecimal de la misma forma que pasamos de decimal a binario, pero dividiendo y multilpicando por 16.

Usando la tabla podemos transformar un número en base hexadecimal a base binaria tomando cada dígito hexadecimal como cuatro dígitos binarios, eliminando los ceros más y menos significativos.

11D,1E)<sub>16 = H</sub> = 0001 0001 1101 , 0001 1110 = 10011101,0001111)<sub>2</sub>

## 4 - EJERCICIOS

### EJERCICIO 1

Pasar los siguientes números de decimal a binario:
- 26,1875)<sub>10</sub>
- 125,42)<sub>10</sub>

### EJERCICIO 2

Pasar de binario a decimal los siguientes números:
- 0,10100)<sub>2</sub>
- 11001,110)<sub>2</sub>

### EJERCICIO 3

Transformar de hexadecimal a binario:
- A798C,1E)<sub>16</sub>

### EJERCICIO 4

Transformar de binario a hexadecimal:
- 1111111101111000010)<sub>2</sub>

### EJERCICIO 5

Transformar de hexadecimal a decimal:
- 3B5E,34)<sub>16</sub>

### EJERCICIO 6

Transformar de decimal a hexadecimal:
- 314,22)<sub>10</sub>

### EJERCICIO 7

Transformar de BCD a decimal:
- 0011 1000 0111 , 1001 0010

### EJERCICIO 8

Transformar de decimal a BCD:
- 745,2345)<sub>10</sub>

## 5 - SOLUCIONES

### EJERCICIO 1

- 26,1875)<sub>10</sub> = 11010,0011)<sub>2</sub>
- 125,42)<sub>10</sub> = 1111101,0110...)<sub>2</sub>

### EJERCICIO 2

- 0,10100)<sub>2</sub> = 0,625)<sub>10</sub>
- 11001,110)<sub>2</sub> = 26,75)<sub>10</sub>

### EJERCICIO 3

- A798C,1E)<sub>16</sub> = 10100111100010011100,0001111)<sub>2</sub>

### EJERCICIO 4

- 1111111101111000010)<sub>2</sub> = 7FBC2)<sub>H</sub>

### EJERCICIO 5

- 3B5E,34)<sub>16</sub> = 15198,20313)<sub>10</sub>

### EJERCICIO 6

- 314,22)<sub>10</sub> = 13A,385)<sub>H</sub>

### EJERCICIO 7

- 0011 1000 0111 , 1001 0010)<sub>BCD</sub> = 387,92)<sub>10</sub>

### EJERCICIO 8

- 745,2345)<sub>10</sub> = 0111 0100 0101 , 0010 0011 0100 0101)<sub>BCD</sub>