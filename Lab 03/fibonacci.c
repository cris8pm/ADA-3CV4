//Pérez Marcelo Cristopher - 3CV4
#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n)
{
  //Parte recursiva
  //Ya que el método recursivo en Fibonacci calcula y guarda las mismas operaciones una y otra vez, no es la mejor técnica para calcular
  //su complejidad, de ahí que se dispara rápidamente. Además, no se cumplen los mismos parámetros para aplicar el Teorema maestro.
  //Entonces, el algoritmo de Fibonacci recursivo tendrá como mínimo una complejidad exponencial O(2^n)
  //Se puede usar un arreglo auxiliar para ir guardando los resultados de las operaciones, y esto nos daría una mejor complejidad.
  if (n>2)
    return fibonacci(n-1) + fibonacci(n-2);
    //A partir de aquí comienzan los casos bases, los cuales son cuando n vale 2, 1 o 0. Esto 
    //representaría la parte NO recursiva, la cual en general tendría una complejidad de O(1), y si O(n^c) entonces c=0
  else if (n==2) //--> O(1)
    return 1;
  else if (n==1) //--> O(1)   
    return 1;
  else if (n==0) //--> O(1)
    return 0;
}

int main()
{
	//Se indica el limite de los elementos de la secuencia Fibonacci
	int num;
    for (num=0; num<=20; num++)
      printf("%d\n", fibonacci(num));
      
  return 0;
}
