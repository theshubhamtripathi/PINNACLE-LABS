#include <stdio.h>

#define ROWS 5
#define COLS 5

char maze[ROWS][COLS] = {
    {'S', '1', '1', '0', '0'},
    {'0', '0', '1', '0', '1'},
    {'1', '0', '1', '0', '1'},
    {'1', '0', '0', '0', '1'},
    {'1', '1', '1', 'F', '1'}
};

int visited[ROWS][COLS] = {0};

int solveMaze(int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || maze[x][y] == '0' || visited[x][y]) {
        return 0;
    }
    if (maze[x][y] == 'F') {
        printf("Found the finish at (%d, %d)\n", x, y);
        return 1;
    }

    visited[x][y] = 1;

    if (solveMaze(x - 1, y)) return 1; // Move up
    if (solveMaze(x + 1, y)) return 1; // Move down
    if (solveMaze(x, y - 1)) return 1; // Move left
    if (solveMaze(x, y + 1)) return 1; // Move right

    visited[x][y] = 0;
    return 0;
}

int main() {
    printf("Maze Layout:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }

    printf("\nSolving the maze...\n");
    if (!solveMaze(0, 0)) {
        printf("No path found from start to finish.\n");
    }
    return 0;
}
