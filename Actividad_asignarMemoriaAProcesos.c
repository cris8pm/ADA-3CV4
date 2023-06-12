//Perez Marcelo Cristopher - 3CV4
#include<stdio.h>

//Function prototypes
void setMemory(int blockSize[], int processSize[]);

//Main function
int main(){
    int blocks[] = {100, 500, 200, 300, 600};
    int process[] = {212, 417, 112, 426};
   
    setMemory(blocks, process);

    printf("\nMemory blocks remaining:\n");
    for (int i=0; i<5; i++)
        printf("%d ", blocks[i]);
    
    return 0;
}

//Definition of functions
void setMemory(int blockSize[], int processSize[]){
	
    //Set memory for each process
    for(int i=0; i<4; i++){
        int process = processSize[i];
        int assigned = 0;

        //Choose the smallest memory block
        for(int j=0; j<5; j++){
            if(blockSize[i]>=process){
                //Set memory to the process
                blockSize[i]-=process;
                assigned=1;
                break;
            }
        }

        if (!assigned)
            printf("Process %d could not be allocated memory.\n", i+1);
    }
}


/*
a) ¿Conseguiste una solución óptima?
	No, quedo mucha memoria disponible en los diferentes bloques y hubo procesos sin asignar.
b) ¿Cuántos huecos de espacio libre quedaron?
	Quedaron 3 huecos completos, el del bloque 1,4 y 5.
c) ¿Quedó algún proceso sin asignar?
	Si, el proceso 1 y 4.
*/


