# R2D2 and Droid Army

## Pseudocodigo

```cpp
_tables[5][exponent][power];
 
bool can_be_destroyed(int left, int right, int k, int m)
{
    int shots = 0;
    rep(0, m) shots += st_query(left, right, i);
    return shots <= k;
}

droid_army = vector<vector<int>>(m, n, 0); // entrada
rep(0, n) repi(j, 0, m) cin >> droid_army[j][i]; // leyendo la entrada

// construyendo la tabla espaciada para las caracteristicas de los droides para cada tipo de arma.
rep(0, m) st_build(droid_army[i], i); 

// intervalo a analizar actualmente.
int left = 0, right = 0;

// mayor intervalo que es posible derribar de los analizados hasta el momento.
pair<int, int> max_segment;

// mientras el intervalo actual sea valido, es decir, no se ha pasado del final del arreiglo
while (left < n && right < n)
	// si se puede destruir el intervalo actual
	if (can_be_destroyed(left, right, k, m))
		// si el intervalo actual es mayor o igual que el mayor intervalo valido encontrado hasta el momento.
		if (max_segment.second - max_segment.first <= right - left)
			// el mayor intervalo valido encontrado hasta el momento es el actual. 
			// se actualiza el valor del mismo.
			max_segment = {left, right};
		// se actualiza el intervalo agregando un elemento a la derecha.
		right++;
	// si no se puede destruir el intervalo actual
	else
		// se quita el elemento mas a la izquierda del intervalo.
		left++;
		// si el intervalo poseia un solo elemento hay que agregar otro elemento a la derecha para que el intervalo no quede vacio.
		if (left > right) right++;

// mejor solucion encontrada.
left, right = max_segment;

// se imprime la mejor solucion tras analizar todo el arreiglo.
rep(0, m - 1) cout << st_query(left, right, i) << ' ';
cout << st_query(left, right, m - 1);
NEW_LINE;
```

## Demostracion

La solucion vista pasa por el siguiente analisis:

1. La cantidad de disparos necesarios para destruir una caracteristica completa de todos los droids de un intervalo es igual al maximo valor que posee un droid de ese intervalo en dicha caracteristica.
2. Para destruir todas las caracteristicas de todos los droids en un intervalo se necesitan tantos disparos como son necesarios para destruir cada caracteristica sumados. Si esta cantidad es menor que la cantidad de disparos que se pueden usar se puede destruir el intervalo, sino no.
3. Finalmente para analizar todos los intervalos se utilizan 2 punteros. Uno al inicio y otro al final del intervalos.
4. Si en algun momento el intervalo que comienza por el i-esimo droide no puede ser destruido, entonces ningun intervalo mayor que este que comience por el mismo droide podra ser destruido, pues harian falta una cantidad mayor o igual de disparos para destruirlos y no se dispone de disparos suficientes para desruir el intervalo actual siquiera.
5. Si tras analizar un intervalo este se puede derribar y al agregarle un elemento a la derecha ya no se puede derribar, entonces ya hay un intervalo de longitud (l - 1) que se puede derribar, por lo tanto cualquier intervalo que comience por alguno de los elementos del intervalo actual y termine en el ultimo elemento del mismo no mejora la solucion actual, por lo tanto se puede ignorar.
6. Entonces si se parte del intervalo que posee solo el primer elemento y se van agregando elementos al final del mismo mientras sea posible, se llega al mayor intervalo que es posible destruir partiendo del primer droide(4), si posteriormente se elimina el primer elemento del intevalo, por (5) se sabe que no hay necesidad de analizar los subintervalos que comienzan por el nuevo primer elemento del intervalo y terminan antes del ultimo elemento actual del intervalo, luego se procede a cntinuar analizando todos los subintervalos que comienzan por este nuevo primer elemento a partir del que termina en el ultimo elemento actual.
7. Efectuando (6) hasta que el primer elemento sea el ultimo elemento del arreiglo y guardando la mejor solucion encontrada se obtiene la mejor solucion entre las soluciones que comienzan a partir de cada uno de los droides del arreiglo completo, es decir todas.

## Complejidad

Leer la entrada es O(nm) => O(5n) => O(n) {valido}

Construir las tablas espaciadas necesarias es O(mnlogn) => O(5nlogn) => O(nlogn) {valido}

Se comprueban todos los subsegmentos validos moviendo el puntero izquierdo y derecho unas n veces en total antes de llegar al final del arreiglo, o sea, que se realizan 2n comprobaciones. Y cada comprobacion es O(m) => O(5) => O(1). Luego Comprobar el arreiglo completo es O(2n * 1) => O(2n) => O(n) {valido}

Y finalmente imprimir la solucion es O(m) => O(1) {valido}

La complejidad temporal del algoritmo queda de la siguiente manera:

O(n) + O(nlogn) + O(n) + O(1) => O(nlogn) {valido}

## Link

https://codeforces.com/contest/514/problem/D
