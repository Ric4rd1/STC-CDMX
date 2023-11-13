# Asistente del metro CDMX 🚇
Este proyecto es similar a aplicaciónes como Google Maps, Waze, Moovit y Magic Earth más enfocado a el sistema de transporte colectivo metro (**STC**) de la CDMX.
El objetivo principal es analizar el sistema de metro de la CDMX para obtener información valiosa de las rutas mediante algoritmos y estructuras de datos vistos en clase.
## Introducción
El sistema de transporte colectivo metro de la CDMX se confroma de 12 líneas y 195 estaciónes. Cada línea se enumeran con números o letras (L1,L2,L3, L4, L5, L6, L7, L8, L9, LA, LB, L12) y tienen un color correspondiente. Las estaciones al igual tienen un color que corresponde a la línea a la que pertenecen, pueden tener más de un color cuando esta tiene correspondencia. Las estaciones tambien tienen un icono que los representa y nombre .Las lineas de metro contienen estaciones y trenes que viajan entre ellas.

### Clases
Existen __ clases interacutando entre sí en este proyecto:
- `Stc`  🚇
- `Line`  🗺
- `Station`  🚉
- `Train`  🚄

#### Stc🚇
Esta es la clase principal donde se realizan la mayoría de las funciones. La clase `Stc` cuenta con las siguentes variables de estado:
- `lines` : Vector de las lineas que tiene el sistema de transporte del metro.
- `stations` : Mapa de todas las estaciones que tiene el sistema de transporte de metro. Utiliza el nombre (string) de la estación como llave y almacena objetos tipo `Station`.
- `L1Stations`
- `...`					Listas dobles que guardan los nombres de las estaciones. Estas listas estan insertadas en orden de modo que al reccorrer la lista es de igual manera de como se hace en la realidad.
- `L12Stations` 

La clase cuenta con los siguentes métodos:
- Constructor por default.
	- **O(1)**
- Constructor con parametros (lista de Objetos `Line`).
	- **O(1)** : solo asigna una variable `lines`
- Constructor de copia.
- `void loadLines(string fileName)` : Carga un archivo .txt delimitado por tabs con el formato (nombre de la linea, número de estaciones, número de trenes, color, largo en km) y se almacena en `lines`.
	- **O(n)** : Lee un archivo txt linea por linea, depende de n líneas que tenga el archivo

- `void showLines()` : muestra la información de `lines` en la terminal.
	- **O(n)** : Recorre con un cíclo for dependiendo de n elementos

- `void sortLinesLength()` : organiza las líneas de menor a mayor conforme a la distancia en km.
	- **O(n^2)** : Al usar Bubble sort se tienen dos cíclos for anidados, por lo tanto su complejidad es cuadratica. En su mejor caso (cuando ya esta ordenado) su complejidad es de O(n)

- `void sortLinesName()` : organiza las líneas de menor a mayor según el nombre (de L1 a L12).
	- **O(n^2)** : Al usar Bubble sort se tienen dos cíclos for anidados, por lo tanto su complejidad es cuadratica. En su mejor caso (cuando ya esta ordenado) su complejidad es de O(n)

- `void sortLinesNumStations()` : organiza las líneas de menor a mayor según el número de estaciones que tiene.
	- **O(n^2)** : Al usar Bubble sort se tienen dos cíclos for anidados, por lo tanto su complejidad es cuadratica. En su mejor caso (cuando ya esta ordenado) su complejidad es de O(n)

- `voidsortLinesNumTrains()` : organiza las líneas de menor a mayro según el número de trenes que tiene.
	- **O(n^2)** : Al usar Bubble sort se tienen dos cíclos for anidados, por lo tanto su complejidad es cuadratica. En su mejor caso (cuando ya esta ordenado) su complejidad es de O(n)

- `string linestoString()` : regresa las lineas en un string.
	- **O(n)** : se usa un cíclo for para al ir recorriendolo este también se imprima

- `void addStation(Station)` : agrega un objeto tipo `Station` a `stations`.
	- **O(log n)** : La complejidad de insert en un mapa es logaritmica ya que se deriva de la estructura específica de los árboles de búsqueda binaria balanceados. Esto significa que tienen un orden y pueden ir buscando por izquierda y derecha, descartando cada iteración la mitad de los elementos.

- `void loadStations(string fileName)` : Carga un archivo .txt delimitado por tabs con el formato (nombre de estación, línea, descripción icono, TRUE o FALSE si tiene correspondencia, ubicación) y se almacena en `stations`.
	- **O(n)** : Lee un archivo txt linea por linea, depende de n líneas que tenga el archivo

- `string getStation(string)` : busca la estación con el nombre dado en el parametro y regresa la información de la estación si esta existe.
	-  **O(log n)** : La complejidad de acceso en un mapa es logaritmica ya que se deriva de la estructura específica de los árboles de búsqueda binaria balanceados. Esto significa que tienen un orden y pueden ir buscando por izquierda y derecha, descartando cada iteración la mitad de los elementos.

- `void loadStationDlist(string fileName)` : Carga un archivo .txt delimitado por tabs e inserta los nombres de las estaciones a su lista doble correspondiente.
	- **O(n)** : Lee un archivo txt linea por linea, depende de n líneas que tenga el archivo

- `string getLineMap(String line)` : Despliega el mapa de la linea, osea el orden en el que los trenes viajan.
	- **O(n)** : se utiliza un cíclo while que recorre la lista e ir imprimiendo las estaciónes en un formato hasta que termine

#### Line 🗺
La clase `Line` cuenta con las siguentes variables de estado:
- `name` : (string) nombre de la línea (Ej: L5)
- `numStations` : (int) número de estaciones
- `numTrains` : (int) número de trenes
- `color` : (string) color de la línea
- `length: (int) distancia en km total de la línea de inicio a fin
- `stations` : Lista de estaciones
- `trains` : Lista de trenes

La clase cuenta con los siguentes métodos:
- Constructor por default
- Constructor con parametros (`name`, `numStations`, `numTrains`, `color`, `length`)
- Constructor de copia
- `void addTrain(Train t)` : Agrega un tren a trains
- `void removeStation(Station s)` : Elimina una estación de stations
- `void removeTrain(Train t)` : Elimina una estación de stations

### Station🚉
La clase `Station` cuenta con las siguentes variables de estado:
- `name` : (string) nombre de la estación.
- `line` : (string) nombre de la linea a la que pertenece la estación.
- `icon` : (string) breve descripción del icono de la estación.
- `conection` : (bool) muestra si la estación tiene correspondencia.
- `location` : (string) ubicación.

La clase cuenta con los siguentes métodos:
- Constructor por default
- Constructor con parametros (`name`, `line`, `icon`, `conection`, `location`)
- Constructor de copia
- Getters
- Setters

### Analisis Asintotico Estructuras de Datos🐉 
Se tienen las siguentes estructuras de datos:
- `lines` (vector) **O(n)**
	- **Random Access O(1)** : los vectores funcionan como arrays utilizando apuntadores al primer elemento y tienendo el tamaño de este, de esta manera utilizando matematicas con los apuntadores se accesa de manera **O(1)**
	**-Insertar o Eliminar O(n)** : los vectores nativamente no son dinamicos, utilizan copias provisionales para agrandar o reducir su tamaño al tener que recorrer el arreglo se obtiene una complejidad de **O(n)**
- `L1...L12Stations` (Lista doblemente encadenada) **O(n)**
	- **Random Access O(n)** : Al buscar un elemento en la lista se debe recorrer la lista por elemento en orden hasta encontrar lo deseado
	- **Acceso por iterador O(1)** : Al usar un iterador este se puede quedar apuntando a cualquer parte de la lista, sirve para accesar de forma inmediata a elementos que esten siendo apuntados por el iterador. Se utiliza para métodos como `current()`, `next()`, `previous()`.
	- **Insertar o Eliminar O(1)** : Al utilizar apuntadores como head y tail se puede insertar y eliminar de forma directa.
- `stations` (Mapa) **O(n)**
	- Los mapas utilizan *Arboles* para almacenar los datos almacenados, se utilizan las llaves para buscar la el dato requerido. Los casos promedio para **Accesar, Buscar, Insertar y Borrar** son de **O(log(n))** y para los peores casos son de **O(n)**

## SICT0301: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa.
Se hace el analisis asintótico en la parte superior de las estructuras de datos. ☝

### Hace un análisis de complejidad correcto y completo para todos los demás componentes del programa y determina la complejidad final del programa.
Al explicar cada funcion se hace un análisis de complejidad. 
El analisis de complejidad general del programa **O(n^2)**: Esta aproximación se basa principalmente en las operaciones de ordenamiento cuadrático que se realizan en las líneas (Sorts). Estas son las acciones más costosas. Cabe mencionar que podría cambiar en caso de que el número de elementos aumentara de manera muy grande(no es un problema ya que el número de estaciones no cambiará).
- La complejidad total dependerá del tamaño de los conjuntos de datos involucrados (número de líneas y estaciones).
- La operación más costosa es el ordenamiento de líneas, que es cuadrático y podría ser ineficiente si es que la cantidad de elementos subiera.
- Las operaciones de carga y manipulación de estaciones tienen complejidad lineal o constante.

## SICT0302B: Toma decisiones
### Selecciona y usa una estructura lineal adecuada al problema
Se utilizó un vector `lines` para almacenar las lineas del metro. Se escojió esta estructura gracias a los beneficios que ofrece para acceder rápidamente a los objetos. Random access - constant 𝓞(1)

### Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
Se utilizan estructuras de datos diferentes:
- `lines` : Vector de las lineas que tiene el sistema de transporte del metro.
- `stations` : Mapa de todas las estaciones que tiene el sistema de transporte de metro. Utiliza el nombre (string) de la estación como llave y almacena objetos tipo `Station`.
- `L~station` Lista doble encadenada que almacena los nombres de todas las estaciones. De esta manera se pueden ordenar y accesar de una manera más eficiente, fácil y rápida.

### Selecciona un algoritmo de ordenamiento adecuado al problema
Para este problema se utilizó un algoritmo de tipo bubble sort, para poder organizar las líneas por orden de menor km a mayor km. Se decidió utilizar este método de ordenación por Bubble Sort  ya que es un algoritmo simple de entender e implementar, también por la eficiencia en listas pequeñas como es `lines` (tiene 12 elementos), y también requere poca memoria adicional  lo que significa que ordena la lista sin necesidad de una memoria auxiliar significativa. Solo necesita una cantidad constante de memoria adicional para realizar las comparaciones y las operaciones de intercambio. Finalmente también por la estabilidad que ofrece.

### Usa un árbol adecuado para resolver un problema

## SICT0303B: Implementa acciones científicas
### Implementa mecanismos para consultar información de las estructuras correctos y útiles dentro de un programa.
Dentro de la clase `Stc` se tienen los siguentes métodos para consultar información:
- `linestoString` : obtiene la información de las lineas del metro.
- `getStationLine(string)` : obtiene la linea a la que pertenece la estación dada.
- `getStationIcon(string)` : obtiene el icono a la que pertenece la estación dada.
- `getStationLocation(string)` : obtiene el icono a la que pertenece la estación dada.
- `getSationConection(string)` : indica si la estación dada tiene correspondencia.
- `getStation(string)` : devuelve toda la información de la estación dada.

### Implementa mecanismos de lectura de archivos correctos y útiles dentro de un programa.
Se utilizan 2 archivos de texto delimitados por Tabs ("Lines.txt" y "Stations.txt") para hacer una lectura de ellos e instanciar los objetos de `Line` y `Station`.

### Implementa mecanismos de escritura de archivos para guardar los datos de las estructuras de manera correcta.

Se crea un archivo de salida llamado `outputFile.txt` donde se hace la escritura de los datos obtenidos de forma ordenada.


## Recursos
https://metro.cdmx.gob.mx/storage/app/media/red/plano_red19.pdf
https://www.metro.cdmx.gob.mx/
https://www.metro.cdmx.gob.mx/cronologia-del-metro 
https://www.kaggle.com/code/edherivndazsalazar/afluencia-en-transpote-p-blico-cdmx/input?select=movilidad.csv
