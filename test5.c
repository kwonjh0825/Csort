#include <stdio.h>
#include <stdbool.h>

#define PATHWAY_COLOUR 0
#define WALL_COLOUR 1
#define BLOCKED_COLOUR 2
#define PATH_COLOUR 3
int n;
int maze[16][16];


bool go_right(int x, int y){
    
    if(x<0 || y<0 || x>=n || y>=n)
        return false;
    if(maze[x][y]!=PATHWAY_COLOUR)
        return false;
    if(x==n-1 && y==n-1)
        return true;
    
    if(maze[x][y+1]==PATHWAY_COLOUR && y+1<n) {
        maze[x][y]=PATH_COLOUR;
        return go_right(x,y+1);
    }
    else if (maze[x+1][y]==PATHWAY_COLOUR && x+1<n) {
        maze[x][y]=PATH_COLOUR;
        return go_right(x+1,y);
    }
    return false;
}
bool go_down(int x, int y){
    if(x<0 || y<0 || x>=n || y>=n)
        return false;
    if(maze[x][y]!=PATHWAY_COLOUR)
        return false;
    if(x==n-1 && y==n-1)
        return true;

    if(maze[x+1][y]==PATHWAY_COLOUR && x+1<n){
        maze[x][y]=PATH_COLOUR;
        return go_down(x+1,y);
    }
    else if(maze[x][y+1]==PATHWAY_COLOUR && y+1<n){
        maze[x][y]=PATH_COLOUR;
        return go_down(x,y+1);
    }
    return false;
}
bool car(int x, int y)
{
    if(go_right(x,y))
        return true;
    else if(go_down(x,y))
        return true;
    else return false;
}
int main()
{
    scanf("%d", &n);
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            scanf("%d",&maze[i][j]);
        }
    }
    
    if(car(0,0)){
        printf("Yes");
    }
    else printf("No");
}
