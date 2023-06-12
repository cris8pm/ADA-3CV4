#Perez Marcelo Cristopher - 3CV4
import time
inicio = time.time()

def solve_maze(maze, start, end):
    def is_valid_move(x, y):
        return 0 <= x < len(maze) and 0 <= y < len(maze[0]) and maze[x][y] == 0

    def dfs(x, y):
        if (x, y) == end:
            return [(x, y)]

        maze[x][y] = 2  # Mark the cell as visited
        for dx, dy in [(0, 1), (1, 0), (0, -1), (-1, 0)]:
            nx, ny = x + dx, y + dy
            if is_valid_move(nx, ny):
                path = dfs(nx, ny)
                if path:
                    return [(x, y)] + path

        return None

    return dfs(*start)


maze = [
    [0, 0, 0, 1, 0, 1, 0, 0],
    [0, 1, 0, 1, 0, 0, 0, 1],
    [0, 1, 0, 0, 0, 1, 1, 1],
    [0, 1, 1, 1, 0, 1, 0, 0],
    [0, 0, 0, 0, 1, 0, 0, 1],
    [0, 1, 0, 1, 0, 1, 0, 0],
    [1, 0, 0, 1, 0, 1, 0, 1],
    [1, 0, 1, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 1, 0, 1, 0],
]

print('The maze is')
print()
for line in maze:
	print(line)
print()

start = (0, 7)
end = (5, 7)

path = solve_maze(maze, start, end)
if path:
    print("Maze solved! Path:", path)
else:
    print("No solution found.")
    
fin = time.time()
print("\nThe elapsed time is: ", fin-inicio)