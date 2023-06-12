//Realizado por Pérez Marcelo Cristopher - 3CV4
#include <stdio.h>
#include <time.h>

//Prototipos de funciones
void generarArreglo(int);
void busqSecuencial(int p[],int);
void ordenarArreglo(int arreglo[],int);

//Funcion Principal
int main()
{
    double time_spent = 0.0;
    clock_t begin = clock();
    srand(time(NULL));
    int tam;
    
    printf("Ingrese el numero de elementos del arreglo (mayor a 5): \n");
    scanf("%d", &tam);
    
    generarArreglo(tam);

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\nTiempo empleado: %f segundos", time_spent);
    
    return 0;
}

//Definicion de funciones
void generarArreglo(int n){
    int array[n];
    for(int i=0; i<n; i++){
        array[i]=rand() % 50;
        printf("Elemento [%d] = %d \n", i, array[i]);
    }
    
    busqSecuencial(array, n);
    ordenarArreglo(array, n);
}

void busqSecuencial(int p[], int tam){
  int numero, i=0;
  char band = 'F';
  printf("Que numero quiere buscar en el arreglo: ");
  scanf("%d", &numero);
  while ((band == 'F') && (i < tam)) {
    if (p[i] == numero) {
      band = 'V';
    }
    i++;
  }
  if (band == 'F') 
    printf("EL numero no existe en el arreglo");
  else 
    printf("El numero esta en la posicion [%d] del arreglo\n ", i - 1);
}

//By Insertion Sort
void ordenarArreglo(int copia[], int tam){
	int k, aux;
	for(int i=0; i<tam; i++){
		k=i; //Utilizamos k para obtener la posicion actual
		aux=copia[i];
		while((k>0)&&(aux<copia[k-1])){ /*Recorremos los numeros solo si la posicion anterior es mayor a la poscion actual 
								        y dicha posicion es mayor a cero, ya que las comparaciones siempre son a la izquierda*/
			copia[k]=copia[k-1];
			k--; //Se van reduciendo las posiciones
		}
		copia[k]=aux;
	}

	printf("\nArreglo ordenado con el metodo de Insercion: \n");
    for(int k=0; k<tam; k++)
        printf("%d, ",copia[k]);
}



/*
Completando la tabla

Tamaño del arreglo | Tiempo de Ejecución (segundos)
        5                   0.000242
        20                  0.000171
        100                 0.000622
        1000                0.004298
        10000               0.125638
        100000              6.542534
        1000000             184.487057
        10000000            No devolvio el valor
        100000000           No devolvio el valor
 

*/









