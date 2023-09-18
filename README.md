# Asistente del metro CDMX 🚇
Este proyecto es similar a aplicaciónes como Google Maps, Waze, Moovit y Magic Earth más enfocado a el sistema de transporte colectivo metro (**STC**) de la CDMX.
El objetivo principal es analizar el sistema de metro de la CDMX para obtener información valiosa de las rutas mediante algoritmos vistos en clase.
## Introducción
Hay lineas de metro que contienen estaciones y trenes que viajan entre ellas.

#### Clases
Existen __ clases interacutando entre sí en este proyecto:
- `Stc`
- `Line`
- `Station`
- `Train`

##### Stc
La clase `Stc` cuenta con las siguentes variables de estado:
- `lines` : Lista de las lineas que tiene el sistema de transporte del metro

La clase cuenta con los siguentes métodos:
- Constructor por default
- Constructor con parametros (lista de Objetos `Line`)
- Constructor de copia
- `void loadLines(string fileName)` : Carga un archivo .txt delimitado por tabs con el formato (nombre de la linea, número de estaciones, número de trenes, color, largo en km) y se almacena en `lines`
- `void showLines()` : muestra la información de `lines` en la terminal
- `void sortLinesLength()` : organiza las líneas de menor a mayor conforme a la distancia en km

##### Lines
La clase `Lines` cuenta con las siguentes variables de estado:
- `name` : nombre de la línea (Ej: L5)
- `numStations` : número de estaciones
- `numTrains` : número de trenes
- `color` : color de la línea
- `lenght` : distancia en km total de la línea de inicio a fin
- `stations` : Lista de estaciones
- `trains` : Lista de trenes

La clase cuenta con los siguentes métodos:



## SICT0302B: Toma decisiones
### Selecciona y usa una estructura lineal adecuada al problema

### Selecciona un algoritmo de ordenamiento adecuado al problema

### Usa un árbol adecuado para resolver un problema
