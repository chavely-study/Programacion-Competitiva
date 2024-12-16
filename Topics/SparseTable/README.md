# Sparse Table

## Definicion

El sparse table o tabla espaciada permite computar funciones idempotentes y asociativas en un rango de un arreiglo en tiempo contante, y con una complejidad temporal de inicializacion de n log n:

st_build(input) O(n log n)

st_query(left, right) O(1)

## Explicacion

La tabla espaciada es un arreiglo bidimensional:

> [ 0 0 0 0 0 0 0 0 ]
>
> [ 0 0 0 0 0 0 0 0 ]
>
> [ 0 0 0 0 0 0 0 0 ]
>
> [ 0 0 0 0 0 0 0 0 ]

Al inicializarlo la primera fila es el propio arreiglo al cual se necesita acceder:

> [ 2 5 8 6 3 1 5 7 ]
>
> [ 0 0 0 0 0 0 0 0 ]
>
> [ 0 0 0 0 0 0 0 0 ]
>
> [ 0 0 0 0 0 0 0 0 ]

Luego en todas las filas i, el elemento j-esimo es el resultado de computar la funcion deseada entre los 2^i elementos del arreiglo original a partir del j-esimo.

Para el caso i = 0 se cumple pues 2^0 = 1 y el primer elemento en el arreiglo original a partir del j-esimo es este mismo y con su valor se inicializo la fila 0 de la tabla.

Si en la fila i - 1 se cumple para todo j que el elemento j-esimo es el resultado de computar la funcion deseada en los 2^(i - 1) elementos a partir del j-esimo en el arreiglo original.

Entonces en la fila i como la funcion deseada es idempotente y asociativa y el elemento j-esimo es el resultado de computar dicha funcion en los 2^(i - 1) elementos a partir del j-esimo en el arreiglo inicial y los 2^(i - 1) a partir del j + 2^(i - 1) - esimo (Explicacion tambien del algoritmo de inicializacion).

Luego el elemento j-esimo de la fila i es en total el resultado de computar la funcion deseada en los 2^i elementos a partir del j-esimo en el arreiglo inicial.

Como para el caso de i = 0 se cumple y si se cumple para i - 1 se cumple para el caso i, entonces queda demostrado por induccion que se cumple para todo i.

Tras aplicar el algoritmo con la funcion minimo nuestra tabla de ejemplo queda de la siguiente manera:

> [ 2 5 8 6 3 1 5 7 ]
>
> [ 2 5 6 3 1 1 5 0 ]
>
> [ 2 3 1 1 1 0 0 0 ]
>
> [ 1 0 0 0 0 0 0 0 ]

Finalmente para computar la funcion deseada en un intrvalo [left, right] se procede de la siguiente manera:

Se calcula la parte entera por debajo del logaritmo en base 2 de la longitud del intervalo (i).

Se computa la funcion deseada entre el elemento left-esimo de la fila i y el elemeno (right - 2^i + 1)-esimo de la misma fila. Esto da el resultado buscado.

Demostracion:

Como el elemento left-esimo de la fila i es el resultado de aplicar la funcion deseada en los 2^i elementos a partir del left-esimo en el arreiglo original se tiene el resultado en el intervalo: [left, left + 2^i].

Y como el elemento (right - 2^i + 1)-esimo de la fila i es el resultado de aplicar la funcion deseada en los 2^i elementos a partir del (right - 2^i + 1)-esimo en el arreiglo original se tiene el resultado en el intervalo: [right - 2^i + 1, right].

Luego el resultado de calcular la funcion deseada entre estos dos elementos de la tabla es el resultado de calcularla entre todos los elementos del conjunto: [left, left + 2^i] U [right - 2^i + 1, right].

Finalmente el intervalo [left, left + 2^i] U [right - 2^i + 1, right] es el mismo [left, right].

Esto se debe a que left = left <= right - 2^i + 1 <= left + 2^i <= right = right.

la desigualdad: right - 2^i + 1 <= left + 2^i; se demuestra facilmente despejando(a partir de log2(right - left) < i + 1 se llega a right - 2^i + 1 <= left + 2^i):

> right - 2^i + 1 <= left + 2^i
>
> right - left <= 2(2^i) - 1
>
> right - left <= 2^(i + 1) - 1
>
> right - left < 2^(i + 1)
>
> log2(right - left) < i + 1
