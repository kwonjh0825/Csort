#include <stdio.h>


void findNumberOfMazePath(int x, int y, int length) {
    int len = length;
    if (x == N-1 && y == N-1) {
        if (len <= K) {
            path_count++;
        }
        // path_count++;
    }
    maze[x][y] = PATH_COLOUR;
    if (x >= 1 && x < N) {
        if (maze[x-1][y] == PATHWAY_COLOUR) {
            len = 1 + length;
            findNumberOfMazePath(x-1, y, len);
        }
    }
    if (x >= 0 && x < N) {
        if (maze[x+1][y] == PATHWAY_COLOUR) {
            len = 1 + length;
            findNumberOfMazePath(x+1, y, len);
        }
    }
    if (y >= 0 && y < N) {
        if (maze[x][y+1] == PATHWAY_COLOUR) {
            len = 1 + length;
            findNumberOfMazePath(x, y+1, len);
        }
    }
    if (y >= 1 && y < N) {
        if (maze[x][y-1] == PATHWAY_COLOUR) {
            len = 1 + length;
            findNumberOfMazePath(x, y-1, len);
        }
    }
    maze[x][y] = PATHWAY_COLOUR;
}