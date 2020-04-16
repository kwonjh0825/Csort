#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void) {
    int NArr[10] = {9,1,8,2,6,7,5,4,3,10};
    int count = 0;
    int k=16;
    int n=10;

    for(int x=0;x<n;x++){
        for(int y=x+1;y<n;y++){
            for(int z=y+1;z<n;z++){
                if(NArr[x]+NArr[y]+NArr[z]==k)
                    count++;
            }
        }
    }
    printf("%d\n", count);

    return 0;
}