#include <stdio.h>
#include <Stdlib.h>
#include <string.h>

#define PATHWAY_COLOUR 0
#define WALL_COLOUR 1
#define BLOCKED_COLOUR 2
#define PATH_COLOUR 3
int count=0;
void pathcount(int (*maze)[16], int k, int x, int y, int n,int length)
{   
    int len=length;
    if(x==n-1 && y==n-1 && len<=k){
        count++;
    }
    maze[x][y]=PATH_COLOUR;
    if(x>=0 && x< n){
        if(maze[x+1][y]==PATHWAY_COLOUR){
            len=length+1;
            pathcount(maze,k,x+1,y,n,len);
        }
    }
    if(x>=1 && x< n){
        if(maze[x-1][y]==PATHWAY_COLOUR){
            len=length+1;
            pathcount(maze,k,x-1,y,n,len);
        }
    }
    if(y>=0 && y< n){
        if(maze[x][y+1]==PATHWAY_COLOUR){
            len=length+1;
            pathcount(maze,k,x,y+1,n,len);
        }
    }
    if(y>=1 && y< n){
        if(maze[x][y-1]==PATHWAY_COLOUR){
            len=length+1;
            pathcount(maze,k,x,y-1,n,len);
        }
    }
    maze[x][y]=PATHWAY_COLOUR;
}

int main(){
    int n;
    scanf("%d",&n);
    
    int maze1[16][16];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++)
            scanf("%d",&maze1[i][j]);
    }
    int k;
    scanf("%d",&k);
    pathcount(maze1,k,0,0,n,0);
    printf("%d",count);
    return 0;
}