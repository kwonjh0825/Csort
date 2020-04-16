#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int countr(int n, int *Arr, int i, int k)
{
    if(i>n)
        return 1;
    else if(Arr[i]<k)
    {
        i++;
        return 1 + countr(n, Arr, i,k);
    }
    else 
    {
        i++;
        return countr(n, Arr, i, k);
    }
}
void printrank(int n, int *arr, int j)
{
    if(j>=n)
        return;
    int count=countr(n, arr, 0, arr[j]);
    printf("%d ", count);
    j++;
    printrank(n, arr, j);
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
    
    printrank(n, NArr, 0);
    
    return 0;
}