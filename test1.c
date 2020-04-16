#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STRING_SIZE 1000
void getNumber(char *ptr, int i, int *arr) {
    if (ptr != NULL) {
        arr[i] = atoi(ptr);
        // 문자열에서 공백 기준으로 잘라낸 것을 int형 배열에 삽입한다.
        ptr = strtok(NULL, " ");
        // 문자형 배열에서 공백 기준으로 자른다
        i++;
        getNumber(ptr, i, arr);
    }
    return;
}
int aa(int *Arr, int n, int x, int y, int z, int k)
{
    if(z>n)
        return 0;
    else {
        if(Arr[x]+Arr[y]+Arr[z]==k){
            z++;
            return 1+aa(Arr,n,x,y,z,k);
        }
        else {
            z++;
            return aa(Arr,n,x,y,z,k);
        }
    }
}
int bb(int *Arr, int n, int x, int y, int k)
{
    if(y>n)
        return 0;
    else{
        int z=y+1;
        int tmp=aa(Arr,n,x,y,z,k);
        y++;
        return tmp + bb(Arr,n,x,y,k);
    }   
}
int cc(int *Arr, int n, int x, int k)
{
    if(x>n)
        return 0;
    else{
        int y=x+1;
        int tmp=bb(Arr,n,x,y,k);
        x++;
        return tmp+cc(Arr,n,x,k);
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    //배열의 크기 n을 입력 받는다
    int NArr[n];
    //크기가 n인 int형 배열을 생성한다. 
    

    char CArr[1000];
    //배열을 문자로 입력받기 위해 문자형 배열을 선언
    char *tmp;
    getchar();
    fgets(CArr, STRING_SIZE, stdin);
    //CArr에 배열을 문자로 입력받는다.
    tmp=strtok(CArr," ");
    //입력받은 문자열을 공백(spacebar) 기준으로 잘라낸다
    getNumber(tmp, 0, NArr);
    int k;
   
    scanf("%d",&k);
    
    int count = cc(NArr, n, 0, k);

    printf("%d", count);
    return 0;
}