//Perez Marcelo Cristopher -3CV4
// C code to demonstrate Divide and
// Conquer Algorithm
#include <stdio.h>
#include <time.h>
int DAC_Max(int a[], int index, int l);
int DAC_Min(int a[], int index, int l);

// function to find the maximum no.
// in a given array.
int DAC_Max(int a[], int index, int l)
{
	int max;
	if(l - 1 == 0)
	{
	return a[index];
	}
	if (index >= l - 2) {
		if (a[index] > a[index + 1])
			return a[index];
		else
			return a[index + 1];
	}

	// logic to find the Maximum element
	// in the given array.
	max = DAC_Max(a, index + 1, l);

	if (a[index] > max)
		return a[index];
	else
		return max;
}

// Function to find the minimum no.
// in a given array.
int DAC_Min(int a[], int index, int l)
{
	int min;
	if(l - 1 == 0)
	{
	return a[index];
	}
	if (index >= l - 2) {
		if (a[index] < a[index + 1])
			return a[index];
		else
			return a[index + 1];
	}

	// Logic to find the Minimum element
	// in the given array.
	min = DAC_Min(a, index + 1, l);

	if (a[index] < min)
		return a[index];
	else
		return min;
}

// Driver Code
int main()
{
    srand(time(NULL));
	//para almacenar el tiempo de ejecución del código
    double time_spent = 0.0;
 
    clock_t begin = clock();
    
	// Defining the variables
	int min, max, N, tam;

	// Initializing the array
    int array[100];
	for(int i=0; i<100; i++){
        array[i]=rand() % 10000;
    }

	// recursion - DAC_Max function called
	max = DAC_Max(array, 0, 100);

	// recursion - DAC_Max function called
	min = DAC_Min(array, 0, 100);
	printf("The minimum number in a given array is : %d\n", min);
	printf("The maximum number in a given array is : %d", max);
	
	clock_t end = clock();
 
    // calcula el tiempo transcurrido encontrando la diferencia (end - begin) y
    // dividiendo la diferencia por CLOCKS_PER_SEC para convertir a segundos
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
 
    printf("\n\nThe elapsed time is %f seconds", time_spent);
    
	return 0;
}

// This code is contributed by Ashish Rana (GFG Team)