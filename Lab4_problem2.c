#include <stdio.h>
#include <stdlib.h>

//max grid size
#define MAX 300

//direction vectors
int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

//stack structure for DFS
typedef struct {
    int row, col;
} Point;

//depth-first search (DFS) function 
void dfs(char** grid, int gridSize, int* gridColSize, int r, int c) {
    Point stack[MAX * MAX];
    int top = -1;

    //pushes cell to stack
    stack[++top] = (Point){r, c};

    while (top >= 0) {
        Point p = stack[top--];

        //checks bounds & if its land
        if (p.row < 0 || p.col < 0 || p.row >= gridSize || p.col >= gridColSize[p.row] || grid[p.row][p.col] != '1')
            continue;

        //been there
        grid[p.row][p.col] = '0';

        //push adjacent cells
        for (int i = 0; i < 4; i++) {
            int nr = p.row + dr[i];
            int nc = p.col + dc[i];
            stack[++top] = (Point){nr, nc};
        }
    }
}

//# of islands function
int numIslands(char** grid, int gridSize, int* gridColSize) {
    if (!grid || gridSize == 0) return 0;
    int count = 0;

    //traverses the islands
    for (int r = 0; r < gridSize; r++) {
        for (int c = 0; c < gridColSize[r]; c++) {
            if (grid[r][c] == '1') {
                dfs(grid, gridSize, gridColSize, r, c); 
                count++;  
            }
        }
    }
    return count;
}

int main() {
    //input grid
    char* gridData[] = {
        "11110",
        "11010",
        "11000",
        "00000"
    };
    int gridSize = 4;  
    int gridColSize[] = {5, 5, 5, 5};  

    //allocate memory for grid
    char** grid = (char**)malloc(gridSize * sizeof(char*));
    
    for (int i = 0; i < gridSize; i++) {
        grid[i] = (char*)malloc((gridColSize[i] + 1) * sizeof(char));  
        for (int j = 0; j < gridColSize[i]; j++) {
            grid[i][j] = gridData[i][j];
        }
        grid[i][gridColSize[i]] = '\0';  
    }

    //counts # of islands
    int result = numIslands(grid, gridSize, gridColSize);

    printf("Output: %d\n", result);

    //frees allocated memory
    for (int i = 0; i < gridSize; i++) {
        free(grid[i]);
    }
    free(grid);

    return 0;
}
