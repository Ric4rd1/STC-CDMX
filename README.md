# Asistente del metro CDMX 🚇
Este proyecto es similar a aplicaciónes como Google Maps, Waze, Moovit y Magic Earth más enfocado a el sistema de transporte colectivo metro (**STC**) de la CDMX.
El objetivo principal es analizar el sistema de metro de la CDMX para obtener información valiosa de las rutas mediante algoritmos vistos en clase.
## Introducción
Hay lineas de metro que contienen estaciones y trenes que viajan entre ellas.

### Clases
Existen __ clases interacutando entre sí en este proyecto:
- `Stc`  🚇
- `Line`  🗺
- `Station`  🚉
- `Train`  🚄

#### Stc🚇
La clase `Stc` cuenta con las siguentes variables de estado:
- `lines` : Vector de las lineas que tiene el sistema de transporte del metro.
- `stations` : Mapa de todas las estaciones que tiene el sistema de transporte de metro. Utiliza el nombre (string) de la estación como llave y almacena objetos tipo `Station`.

La clase cuenta con los siguentes métodos:
- Constructor por default.
- Constructor con parametros (lista de Objetos `Line`).
- Constructor de copia.
- `void loadLines(string fileName)` : Carga un archivo .txt delimitado por tabs con el formato (nombre de la linea, número de estaciones, número de trenes, color, largo en km) y se almacena en `lines`.
- `void showLines()` : muestra la información de `lines` en la terminal.
- `void sortLinesLength()` : organiza las líneas de menor a mayor conforme a la distancia en km.
- `string linestoString()` : regresa las lineas en un string.
- `void addStation(Station)` : agrega un objeto tipo `Station` a `stations`.
- `void loadStations(string fileName)` : Carga un archivo .txt delimitado por tabs con el formato (nombre de estación, línea, descripción icono, TRUE o FALSE si tiene correspondencia, ubicación) y se almacena en `stations`.
- `string getStation(string)` : busca la estación con el nombre dado en el parametro y regresa la información de la estación si esta existe.

#### Line 🗺
La clase `Line` cuenta con las siguentes variables de estado:
- `name` : (string) nombre de la línea (Ej: L5)
- `numStations` : (int) número de estaciones
- `numTrains` : (int) número de trenes
- `color` : (string) color de la línea
- `lenght` : (int) distancia en km total de la línea de inicio a fin
- `stations` : Lista de estaciones
- `trains` : Lista de trenes

La clase cuenta con los siguentes métodos:
- Constructor por default
- Constructor con parametros (`name`, `numStations`, `numTrains`, `color`, `length`)
- Constructor de copia
- `void addStation(Station s)` : Agrega una estación a stations
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

### Analisis Asintotico 🐉 
Se tienen las siguentes estructuras de datos:
- `lines` (vector) **o(n)**
	- **Random Access o(1)** : los vectores funcionan como arrays utilizando apuntadores al primer elemento y tienendo el tamaño de este, de esta manera utilizando matematicas con los apuntadores se accesa de manera **o(1)**
	**-Insertar o Eliminar o(n)** : los vectores nativamente no son dinamicos, utilizan copias provisionales para agrandar o reducir su tamaño al tener que recorrer el arreglo se obtiene una complejidad de **o(n)**
- `stations` (Mapa) **o(n)**
	- Los mapas utilizan *Arboles* para almacenar los datos almacenados, se utilizan las llaves para buscar la el dato requerido. Los casos promedio para **Accesar, Buscar, Insertar y Borrar** son de **o(log(n))** y para los peores casos son de **o(n)**

## SICT0301: Evalúa los componentes
### Hace un análisis de complejidad correcto y completo todas las estructuras de datos y cada uno de sus usos en el programa.
Se hace el analisis asintótico en la parte superior de las estructuras de datos. ☝

## SICT0302B: Toma decisiones
### Selecciona y usa una estructura lineal adecuada al problema
Se utilizó un vector `lines` para almacenar las lineas del metro. Se escojió esta estructura gracias a los beneficios que ofrece para acceder rápidamente a los objetos. Random access - constant 𝓞(1)

###Selecciona una estructura de datos adecuada al problema y lo usa correctamente.
Se utilizan estructuras de datos diferentes:
- `lines` : Vector de las lineas que tiene el sistema de transporte del metro.
- `stations` : Mapa de todas las estaciones que tiene el sistema de transporte de metro. Utiliza el nombre (string) de la estación como llave y almacena objetos tipo `Station`.
- `stationsNames` Lista doble encadenada que almacena los nombres de todas las estaciones. De esta manera se pueden ordenar de una manera más eficiente.

### Selecciona un algoritmo de ordenamiento adecuado al problema
Para este problema se utilizó un algoritmo de tipo insertion sort, para poder organizar las líneas por orden de menor km a mayor km. Se decidió utilizar este método de ordenación por inserción (insertion sort) ya que es un algoritmo simple de entender e implementar, también por la eficiencia en listas pequeñas como es `lines` (tiene 12 elementos), y también requere poca memoria adicional  lo que significa que ordena la lista sin necesidad de una memoria auxiliar significativa. Solo necesita una cantidad constante de memoria adicional para realizar las comparaciones y las operaciones de intercambio. Finalmente también por la estabilidad que ofrece.

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


## Recursos
https://metro.cdmx.gob.mx/storage/app/media/red/plano_red19.pdf
https://www.metro.cdmx.gob.mx/
https://www.metro.cdmx.gob.mx/cronologia-del-metro 
https://www.kaggle.com/code/edherivndazsalazar/afluencia-en-transpote-p-blico-cdmx/input?select=movilidad.csv
