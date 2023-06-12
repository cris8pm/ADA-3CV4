//Pérez Marcelo Cristopher
#include <stdio.h>
#include <stdbool.h>

bool busqbin(int* vec, int ini, int fin, int elem){
        if (ini > fin) return false; //---> O(1)
        int medio = (ini + fin) / 2; //---> O(3)
        if(vec[medio] == elem) return true; //--->O(1) 
        //Complejidad de la parte NO recursiva es: O(1), entonces, si O(n^c) = O(1), c=0
        
        //Parte Recursiva
        if(elem < vec[medio])
            return busqbin(vec, ini, medio - 1,elem); //Se llama así misma una vez, por lo tanto, a=1
        else if (elem > vec[medio])
            return busqbin(vec,medio + 1,fin,elem); //Dependiendo del If solo se va a tomar una mitad del arreglo, así,
                                                    //tenemos 2 subproblemas. b=2
        
        //T(n)= 1*T(n/2)+O(n^0) = O(n^0*log2(n)) = O(log2(n))
}

int main()
{
    int array[7];
    for(int i=0; i<7; i++)
        array[i]= i*2;
    
    //[0][2][4][6][8][10][12]  Array de 7 elementos.
    
    //Se busca el numero "10"
    if(busqbin(array, 0, 7, 10))
        printf("Valor encontrado!");
    else
        printf("El valor buscado no existe en el arreglo :(");
    return 0;
}

