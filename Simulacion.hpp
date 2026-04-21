#ifndef SIMULACION_H
#define SIMULACION_H

#include <vector>
#include <omp.h>

inline void inicializarPlaca(std::vector<double> &placa, int tamaño)
{
    for (int i = 0; i < tamaño * tamaño; i++)
    {
        placa[i] = 0.0;
    }

    for (int i = 0; i < tamaño; i++)
    {
        placa[i] = 100.0;
    }
}

inline void calcularTemperatura(std::vector<double> &t_old, std::vector<double> &t_new, int tamaño, int nIteraciones)
{
#pragma omp parallel
    {
        for (int n = 0; n < nIteraciones; n++)
        {

#pragma omp for schedule(static)
            for (int i = 1; i <= tamaño - 2; i++)
            {
                for (int j = 1; j <= tamaño - 2; j++)
                {
                    int centro = i * tamaño + j;
                    int arriba = (i - 1) * tamaño + j;
                    int abajo = (i + 1) * tamaño + j;
                    int derecha = i * tamaño + j + 1;
                    int izquierda = i * tamaño + j - 1;

                    t_new[centro] = (t_old[arriba] + t_old[abajo] + t_old[derecha] + t_old[izquierda]) / 4;
                }
            }
#pragma omp single nowait
            std::swap(t_old, t_new);
        }
    }
}

#endif
