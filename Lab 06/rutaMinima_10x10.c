//Perez Marcelo Cristopher - 3CV4
#include<stdio.h>
#include <time.h>

//Prototipo de funciones
int min(int, int, int);
int calcMinCost(int cost[10][10], int, int);

int main() {
	double time_spent = 0.0;
    clock_t begin = clock();
    
    int cost[10][10] = {
	{4, 7, 8, 6, 4, 3, 8, 1, 2, 4},
	{6, 7, 3, 9, 2, 2, 9, 8, 9, 3},
	{3, 8, 1, 2, 4, 7, 1, 7, 3, 7},
	{7, 1, 7, 3, 7, 4, 7, 8, 6, 4},
	{2, 9, 8, 9, 3, 6, 7, 3, 9, 2},
	{4, 7, 8, 6, 4, 3, 8, 1, 2, 4},
	{6, 7, 3, 9, 2, 2, 9, 8, 9, 3},
	{7, 1, 7, 3, 7, 4, 7, 8, 6, 4},
	{2, 9, 8, 9, 3, 6, 7, 3, 9, 2},
	{3, 8, 1, 2, 4, 7, 1, 7, 3, 7}
	};
    int m=9, n=9;
    int costominimo=calcMinCost(cost, m, n);
    printf("El costo minimo de la ruta es: %d\n", costominimo);

	clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\nThe elapsed time is %f seconds", time_spent);
    return 0;
}


//Definicion de funciones
int min(int a, int b, int c){
    int minVal=a;
    if(b<minVal)
        minVal=b;
    
    if(c<minVal)
        minVal=c;
    
    return minVal;
}

int calcMinCost(int cost[10][10], int m, int n){
    int dp[10][10]; //---->Arreglo auxiliar
    dp[0][0] = cost[0][0];

    //Costos minimos de la primera columna
    for(int i=1; i<=m; i++)
        dp[i][0] = dp[i-1][0]+cost[i][0];
    

    //Costos minimos de la primera fila
    for(int j=1; j<=n; j++)
        dp[0][j] = dp[0][j-1]+cost[0][j];
    

    //Costos restantes
    for(int i=1; i<=m; i++) {
        for(int j=1; j<=n; j++)
            dp[i][j]=cost[i][j]+min(dp[i-1][j-1], dp[i-1][j], dp[i][j-1]);
    }

    return dp[m][n];
}

/*
1. Propon un caso de prueba con una matriz de 10x10 y uno de 100x100. Intenta resolverlos con ambas versiones de la solucion al problema MCP.

	a)¿El tiempo de ejecucion aumento (mide el tiempo de ejecucion)?
		El tiempo invertido en la matriz de 10x10 fue de 0.000069 seconds, mientras qu ela matriz de 100x100 obtuvo un tiempo de 0.000333 seconds
	b)Es notoria la diferencia de complejidades.
		Al incrementar el numero de la matriz se incrementan las posibles combinaciones para la ruta minima, sin embargo, la complejidad no cambia ya que solo estamos modificando la entrada
		de datos y no como los manipulamos.
		
2. El algoritmo de Dijkstra es una forma efectiva de resolver problemas similares al MCP.

	a)Realiza una breve investigacion teórica del mismo.
		Fue creado y publicado por el Dr. Edsger W. Dijkstra, un científico Neerlandés brillante en ciencias de la computación e ingeniería de software.
		El algoritmo de Dijkstra básicamente inicia en el nodo que escojas (el nodo de origen) y analiza el grafo para encontrar el camino más corto entre ese nodo y todos los otros nodos 
		en el grafo.
		El algoritmo mantiene un registro de la distancia conocida más corta desde el nodo de origen hasta cada nodo y actualiza el valor si encuentra un camino más corto.
		Una vez que el algoritmo ha encontrado el camino más corto entre el nodo de origen y otro nodo, ese nodo se marca como "visitado" y se agrega al camino.
		El proceso continúa hasta que todos los nodos en el grafo han sido añadidos al camino. De esta forma, tenemos un camino que conecta al nodo de origen con todos los otros nodos siguiendo 
		el camino más corto posible para llegar a cada uno de ellos.
		Este algoritmo es usado por los dispositivos GPS para encontrar el camino más corto entre la ubicación actual y el destino del usuario. Tiene amplias aplicaciones en la industria, 
		especialmente en aquellas áreas que requieren modelar redes.
	
	b) Averigua si este algoritmo es capaz de resolver los tres casos propuestos anteriormente en un tiempo aceptable.
		Efectivamente, ya que básicamente una matriz se podría comportar como un grafo se podría utilizar este algoritmo para resolverlo.
*/
