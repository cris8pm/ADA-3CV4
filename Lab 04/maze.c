//Perez Marcelo Cristopher - 3CV4
#include <stdbool.h>
#include <stdio.h>
#include <time.h>


#define ROWS 9
#define COLS 8


void printMaze(int maze[ROWS][COLS])
{
for(int i=0;i<ROWS;i++){
	for(int j=0;j<COLS;j++){
		printf("%d \t",maze[i][j]);
	}
	printf("\n");
	}
}

bool is_valid_move(int maze[ROWS][COLS], int x, int y) {
    return x >= 0 && x < ROWS && y >= 0 && y < COLS && maze[x][y] == 0;
}

bool dfs(int maze[ROWS][COLS], int x, int y, int end_x, int end_y, int path[ROWS * COLS][2], int *path_length) {
    if (x == end_x && y == end_y) {
        path[*path_length][0] = x;
        path[*path_length][1] = y;
        (*path_length)++;
        return true;
    }

    maze[x][y] = 2;
    int moves[][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

    for (int i = 0; i < 4; i++) {
        int nx = x + moves[i][0];
        int ny = y + moves[i][1];
        if (is_valid_move(maze, nx, ny)) {
            if (dfs(maze, nx, ny, end_x, end_y, path, path_length)) {
                path[*path_length][0] = x;
                path[*path_length][1] = y;
                (*path_length)++;
                return true;
            }
        }
    }

    return false;
}

int main() {
    double time_spent = 0.0;
    clock_t begin = clock();
    
    int maze[ROWS][COLS] = {
        {0, 0, 0, 1, 0, 1, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1, 1, 1},
        {0, 1, 1, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 1},
        {0, 1, 0, 1, 0, 1, 0, 0},
        {1, 0, 0, 1, 0, 1, 0, 1},
        {1, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 1, 0},
        
    };

	printf("This is the maze\n");
	printMaze(maze);

    int start_x = 0;
    int start_y = 7;
    int end_x = 5;
    int end_y = 7;

    int path[ROWS * COLS][2];
    int path_length = 0;

    if (dfs(maze, start_x, start_y, end_x, end_y, path, &path_length)) {
        printf("Maze solved! Path:\n");
        for (int i = path_length - 1; i >= 0; i--) {
            printf("(%d, %d)\n", path[i][0], path[i][1]);
        }
    } else {
        printf("No solution found.\n");
    }
    
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("\n\nThe elapsed time is %f seconds", time_spent);
    
    return 0;
}