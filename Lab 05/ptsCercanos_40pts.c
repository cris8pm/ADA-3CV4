//Perez Marcelo Cristopher - 3CV4 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

struct Punto {
    int x;
    int y;
};

double distancia_puntos(struct Punto p1, struct Punto p2) {
    // Calcula la distancia euclidiana entre dos puntos en un plano cartesiano
    int dx = p2.x - p1.x;
    int dy = p2.y - p1.y;
    return sqrt(dx*dx + dy*dy);
}

double distancia_mas_cercana(struct Punto puntos[], int num_puntos) {
    double distancia_minima = -1;

    // Comparar cada par de puntos y actualizar la distancia minima
    for (int i = 0; i < num_puntos; i++) {
        for (int j = i + 1; j < num_puntos; j++) {
            double distancia = distancia_puntos(puntos[i], puntos[j]);
            if (distancia_minima == -1 || distancia < distancia_minima) {
                distancia_minima = distancia;
            }
        }
    }

    return distancia_minima;
}

int main() {
	//Para almacenar el tiempo de ejecucion del codigo
    double time_spent = 0.0;
    clock_t begin = clock();
    
    // Ejemplo de uso para 40 puntos
    struct Punto coordenadas[] = {
	{-97, -31},
{-15, -69},
{-55, -53},
{-77, -45},
{-39, -89},
{-64, -10},
{-79, -59},
{-94, -56},
{-25, -95},
{-10, -46},
{-90, -74},
{-25, -58},
{-65, -68},
{-39, -87},
{-90, -62},
{-62, -20},
{-14, -26},
{-79, -6},
{-36, -79},
{-96, -15},
{-89, -11},
{-1, -59},
{-65, -4},
{-76, -8},
{-89, -20},
{-50, -63},
{-70, -13},
{-41, -81},
{-95, -19},
{0, -19},
{-61, -25},
{-29, -62},
{-25, -84},
{-35, -33},
{-3, -27},
{-76, -78},
{-31, -81},
{-16, -27},
{-26, -6},
{-86, -41} };
    int num_puntos = sizeof(coordenadas) / sizeof(coordenadas[0]);

    double distancia = distancia_mas_cercana(coordenadas, num_puntos);
    printf("La distancia mas cercana es: %lf\n", distancia);
	
	clock_t end = clock();
 
    //Calcula el tiempo transcurrido encontrando la diferencia (end - begin) y
    //Dividiendo la diferencia por CLOCKS_PER_SEC para convertir a segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\nThe elapsed time is %f seconds", time_spent);
    
    return 0;
}
