# Trains and Statistic

## Pseudocodigo

```cpp
// lista de posiciones
vector<int> input(n, 0);
// se guardara la cantidad de tiquets que se necesitan para llegar desde la estacion i hasta todas las estaciones que siguen despues de ella.
vector<ll> solution(n - 1, 1);

rep(0, n - 1) cin >> input[i]; // leyendo la entrada

vector<pair<int, int>> next;


rep(0, n) next.push_back({input[i], i});

// de las estaciones alcanzables con un solo tiquet a partir de la cual se puede llegar mas lejos con solo otro tiquet, esta es la informacion que se guarda en la tabla.
st_build(next);

// total de tiquets necesarios para la solucion del problema, 
ll result = 1;
// de las estaciones alcanzables con un solo tiquet a partir de la cual se puede llegar mas lejos con solo otro tiquet.
ll next_index;
 
// dp
    per(0, n - 2)
    {
        next_index = st_query(i + 1, input[i] - 1).second + 1;
        solution[i] = n + next_index + solution[next_index - 1] - input[i] - (i + 1);
        result += solution[i];
    }
    print(result);
```

## Exlicacion

1. Partiendo de la estacion i-esima, por cada estacion que se encuentra entre la siguiente y a[i] se puede llegar a esta con solo un tiquet. O sea, se suma 1 al resultado final.
2. Siempre habra alguna estacion mas alla de la a[i] a la cual se puede llegar con solo 2 tiquets desde i, pues al menos desde la estacion a[i] se podra. A menos que a[i] = n.
3. Si lo mas lejos que se puede llegar desde alguna estacion del rango [i+1, a[i]] es la estacion j. Entonces para llegar de la estacion i-esima a cualquier estacion del rango [a[i + 1], j] se necesitaran como minimo 2 tikets. Finalmente para llegar a las estaciones mas lejanas no se podra llegar con menos de 3 tiquets pues de llegarse con solo 2 tiquets habria alguna estacion en el rango [i+1, a[i]] que podria llegar mas lejos que j, contradiciendo asi la hipotesis inicial.
4. Luego si se tiene en cuenta que sin importar cual esacion k-esima se seleccione dentro del rango[i+1, a[i]] tal que llegue a la estacion j-esima, encontrar el minimo de tiquets necesarios para llegar desde la estacion i-esima hasta cualquiera dentro del rango [j + 1, n] es lo mismo que encontrar dicho resultado para k y sumarle un tiquet por cada viaje (el de llegar de i a k). Pues para llegar de i a cualquier estacion a partir de j se necesitan minimo 3 tiquets y para llegar desde k se necesitan como minimo 2 tiquets. Y para llegar de i a cualquiera de las estaciones despues de la j-esima es optimo pasar por k .

## Complejidad

Leer la entrada es => O(n) {valido}

Construir el sparse_table para saber la estacion con mayor capacidad en un rango es => O(nlogn) {valido}

Calcular solution[i] teniendo solution[j] para todo j E [i+1, n] es => O(1) {valido}

Calcular solution[i] para todo i E [1, n] es => O(n) {valido}

La complejidad temporal del algoritmo queda de la siguiente manera:

O(nlogn) + O(1) + O(n) => O(nlogn) {valido}

## Link

https://codeforces.com/contest/675/problem/E
