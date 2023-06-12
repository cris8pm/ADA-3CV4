//Perez Marcelo Cristopher - 3CV4
#include<stdio.h>

//Prototipo de funciones
int min(int, int, int);
int calcMinCost(int cost[5][5], int, int);

int main() {
    int cost[5][5] = {{4, 7, 8, 6, 4},{6, 7, 3, 9, 2},{3, 8, 1, 2, 4},{7, 1, 7, 3, 7},{2, 9, 8, 9, 3}};
    int m=4, n=4;
    int costominimo=calcMinCost(cost, m, n);
    printf("El costo minimo de la ruta es: %d\n", costominimo);

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

int calcMinCost(int cost[5][5], int m, int n){
    int dp[5][5]; //---->Arreglo auxiliar
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