# Turn Off The TV

## Pseudocodigo

```cpp
tv_sets, numbers = read_input();
new_index = get_map(numbers);
rep(0, n)
{
	tv_set[i].start = new_index[tv_set[i].start]
	tv_set[i].end = new_index[tv_set[i].end]
}
 
vector<int> count(n + 2, 0), prefix(n + 2, 0);
rep(0, n)
{
	count[tv_sets[i + 1].start]++;
	count[tv_sets[i + 1].end + 1]--;
}
rep(1, prefix.size()) prefix[i] = prefix[i - 1] + count[i];

st_build(prefix);


 rep(1, n + 1) if (st_query(tv_sets[i].start, tv_sets[i].end) > 1)
{
        print(i);
        return;
}
print(-1);

```

## Explicacion

1. Para poder crrear un aray donde trabajar con los rangos de los tv_sets se necesita redimensionar el rango de la entrada, como en total se dan 2e6 indices y ademas se necesita guardar el antecesor de todos los comienzos pues seran necesarios mas adelante, y esto es 3e6, lo cual si se puede guardar en memoria. Pues se mapean los indices de la entrada a nuevos indices en el rango 3e6.
2. Se suma 1 al inicio de cada tv_set y se resta uno luego del final. Esto significa que al hacer la suma en un prefijo hasta el elemento i, se sabra cuantos tv_sets activan el i-esimo televisor.
3. Se construye el sparse table con el array de suma de prefijos.
4. Finalmente si el minimo en el rango de un tv_set en el array de suma de prefijos es mayor que 1 quiere decir que para todo televisor en el rango del tv_set hubo mas de 1 tv_sets que lo encendian, por tanto al quitar el tv_set actual se mantendra al menos un tv_set encendiendo todos los televisores, por tanto el tv_set actual es redundante y se puede quitar sin ningun riesgo.

## Complejidad

Leer la entrada es => O(n) {valido}

Crear el indx_map es => O(nlogn) {valido} // hace falta ordenar los n indices originales para crear el mapa.

Asignar los nuevos ingices es O(n) {valido}

Crear el arreiglo de suma de prefijos es _O(n) {valido}

Construir el sparse_table es O(nlogn) {valido}

Revisar si cada tv_set es redundante o no con el sparse_table es O(n) {valido}

La complejidad temporal del algoritmo queda de la siguiente manera:

O(n) + O(nlogn) + O(n) + O(n) + O(nlogn) + O(n) = O(nlogn) {valido}

## Link

https://codeforces.com/contest/863/problem/E
