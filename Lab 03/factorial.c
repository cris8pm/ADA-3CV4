//Pérez Marcelo Cristopher - 3CV4
#include<stdio.h>

int factorial (int numero){
	if(numero < 1) //--> O(1)
		return 0;
	else if (numero==1) //--> O(1)
		return 1;
	//En la parte NO recursiva tenemos los casos bases, los cuales hacen una complejidad de O(1), si O(n^c) = O(1), c=0
	else
		return numero * factorial(numero-1);
		
}

int main (){
	
	printf("El factorial de 4 es: %d", factorial(4));
	return 0;
}
