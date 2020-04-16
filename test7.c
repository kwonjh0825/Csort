#include <stdio.h>
#include <Stdlib.h>
#include <time.h>

int main()
{
    srand((unsigned)time(NULL));
    for(int i=0;i<20;i++){
        printf("%d ", 1+rand()%10);
    }
    return 0;
}