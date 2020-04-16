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
int nearest(int *Arr, int b_index, int e_index)
{
    int m_index=(b_index+e_index)/2;
    if(b_index==e_index-1){
        if(abs(Arr[b_index])<abs(Arr[e_index]))
            return Arr[b_index];
        else
            return Arr[e_index];
    }
    
    else {
        if(abs(Arr[m_index])>abs(Arr[m_index+1])) 
        return nearest(Arr,m_index+1,e_index);
        else if(abs(Arr[m_index])<abs(Arr[m_index+1]))
            return nearest(Arr,b_index,m_index-1);
    }
}
void kkkk(int *Arr1,int *Arr2, int n, int i, int k)
{
    if(i>n)
        return;
    else {
        Arr2[i]=Arr1[i]-k;
        i++;
        kkkk(Arr1, Arr2, n, i, k);
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
    int DifArr[n];
    kkkk(NArr,DifArr,n,0,k);
    
    
    int near=nearest(DifArr,0,n-1);
    getchar();


    printf("%d", near+k);

    return 0;
}