# SimulacionCalor
Practica Tema 2 Computación de Altas Prestaaciones

Implementacion base line sin ninguna optimazación paralela, se ha ejcutado con una 
matriz de 2048 en unas 2048 iteraciones se ejecuta en un tiempo de 0.00424049 de media en 1000 iteraciones.

Tras implementar Open MP al realizar las pruebas la ejecucion es mucho mas lenta que la versión secuencal lo es debido a que la memoria es un cuello de botella importante solo con omp 