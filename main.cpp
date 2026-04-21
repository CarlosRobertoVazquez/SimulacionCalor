#include <iostream>
#include <vector>
#include <iomanip>
#include <omp.h>
#include "Simulacion.hpp"

void imprimirPlaca(const std::vector<double> &placa, int filas)
{
    for (int i = 0; i < filas; ++i)
    {
        for (int j = 0; j < filas; ++j)
        {
            // Calculamos el índice: fila actual * total de columnas + columna actual
            std::cout << std::setw(8) << placa[i * filas + j] << " ";
        }
        std::cout << std::endl; // Salto de línea al terminar cada fila
    }
    std::cout << "----------------------------------------------------" << std::endl;
}

int main(int argc, char *argv[])
{
    int tamaño = std::stoi(argv[1]);
    int nIteraciones = std::stoi(argv[2]);

    // buffers para guaradar las temperaturas con el tamaño de la placa
    std::vector<double> t_old(tamaño * tamaño);
    std::vector<double> t_new(tamaño * tamaño);

    inicializarPlaca(t_new, tamaño);
    inicializarPlaca(t_old, tamaño);
    // trabajamos solo con la parte interior del vector asi que para iterar sobre este se usa
    // calculamos la tempratura de los cuadrantes en cada instante de tiempo
    double t1 = omp_get_wtime();
    int nIter = 1;
    for (int i = 0; i < nIter; i++)
    {
        calcularTemperatura(t_old, t_new, tamaño, nIteraciones);
    }
    double t2 = omp_get_wtime();
    double elapsed = (double)(t2 - t1) / nIter;
    printf("%g\n", elapsed);
}