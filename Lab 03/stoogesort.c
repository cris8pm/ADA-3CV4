//Pérez Marcelo Cristopher 3cv4
#include <stdio.h>

// Funcion que implementa stooge sort
void stoogesort(int arr[], int l, int h)
{
    if (l >= h) //--->O(1)
        return;
    // Si el primer elemento es menor que el ultimo entonces se intercambian.
    if (arr[l] > arr[h]){
        //intercambiar(arr[l], arr[h]);
        int aux=arr[l];
        arr[l]=arr[h];
        arr[h]=aux; //--->O(4)
        }
    //Complejidad de la parte NO recursiva es: O(1), entonces, si O(n^c) = O(1), c=0  
        
    //Parte Recursiva    
    //Si hay más de dos elementos en el arreglo...
    if (h - l + 1 > 2) {
        int t = (h - l + 1) / 3;
        // Ordanamiento recursivo para los primeros 2/3 del arreglo.
        stoogesort(arr, l, h - t);
        // Ordanamiento recursivo para los ultimos 2/3 del arreglo.
        stoogesort(arr, l + t, h);
        // Ordanamiento recursivo para los primeros 2/3 del arreglo.
        // Otra vez para confirmar
        stoogesort(arr, l, h - t);
        
        //La función se llama a si misma 3 veces, entonces, a=3.
        //En cada llamada solo se hace uso de 2/3 de arreglo, esto es n/(2/3) = n /b, por lo tanto b=3/2
        
        //T(n) = 3*T(n/(3/2)) + O(n^0) = O(n^(log3/2(3))
    }
}
//Funcion principal
int main()
{
    int arr[] = { 2, 4, 5, 3, 1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    //Llamado a la funcion stooge sort para ordenar el arreglo.
    stoogesort(arr, 0, n - 1);
    // Se muestra el arreglo ordenado.
    for (int i = 0; i < n; i++)
        printf("%d\n",arr[i]);;
    return 0;
}
