#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void selectionsort(int a[], int t)
{
    int temp=0;
    int max_index=0;
    for(int i=t-1; i>1; i--) {
        int max=0;
        for(int j=0;j<=i;j++) {
           if(a[j]>max) {
               max=a[j];
               max_index=j;
           }
        }
        temp=a[i];
        a[i]=a[max_index];
        a[max_index]=temp; 
         
    }
}

void bubblesort(int a[],int t)
{
    int temp=0;
    for(int i=t-1;i>0;i--) {
        for(int j=0;j<i;j++) {
            if(a[j]>a[j+1]) {
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }        
    }
}

void insertionsort(int a[], int t)
{
    for(int i=1;i<t;i++) {
        int temp=a[i];
        int j=0;
        for(j=i-1; j>=0 && a[j]>temp; j--) {
            a[j+1]=a[j];
        }
        a[j+1]=temp;
    }
}

void merge(int data[], int p, int q, int r) {
	int i=p, j=q+1, k=p;
	int tmp[1000000];
	while(i<=q && j<=r) {
		if (data[i]<=data[j])
			tmp[k++]=data[i++];
		else
			tmp[k++]=data[j++];
	}
	while (i<=q)
		tmp[k++]=data[i++];
	while(j<=r)
		tmp[k++]=data[j++];
	for(int i=p; i<=r; i++)
		data[i]=tmp[i];
}

void mergesort(int a[], int p, int r)
{
    if(p<r) {
        int q=(p+r)/2;
        mergesort(a,p,q);
        mergesort(a,q+1,r);
        merge(a,p,q,r);
    }
}

int partitionlast(int a[], int p, int r)
{
    int pivot=a[r];
    int i=p-1;
    int temp;
    for(int j=p; j<r; j++){
        if(a[j]<=pivot) {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;
}

int partitionmedian(int a[], int p, int r)
{
    int q=(p+r)/2;
    int pivot_index = a[p]>a[q]? (a[p]>a[r]? (a[q]>a[r]? r: q):p):(a[q]>a[r]?(a[p]>a[r]? p: q): r);
    
    int i=p-1;
    int temp;
    
    temp=a[r];
    a[r]=a[pivot_index];
    a[pivot_index]=temp;
    
    int pivot=a[r];
    for(int j=p; j<r; j++){
        if(a[j]<=pivot) {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;
}

int partitionrandom(int a[], int p, int r)
{
    srand(time(NULL));
    int pivot_index = p + rand()%(r-p+1);
    int i=p-1;
    int temp;
    temp=a[r];
    a[r]=a[pivot_index];
    a[pivot_index]=temp;
    int pivot=a[r];
    for(int j=p; j<r; j++){
        if(a[j]<=pivot) {
            i++;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp=a[i+1];
    a[i+1]=a[r];
    a[r]=temp;
    return i+1;
}

void quicksortlast(int a[], int p, int r)
{
    if(p<r) {
        int q=partitionlast(a, p, r);
        quicksortlast(a, p, q-1);
        quicksortlast(a, q+1, r);
    }
}

void quicksortmedian(int a[], int p, int r)
{
    if(p<r) {
        int q=partitionmedian(a, p, r);
        quicksortmedian(a, p, q-1);
        quicksortmedian(a, q+1, r);
    }
}

void quicksortrandom(int a[], int p, int r)
{
    if(p<r) {
        int q=partitionrandom(a, p, r);
        quicksortrandom(a, p, q-1);
        quicksortrandom(a, q+1, r);
    }
}

void maxheapify(int a[], int i, int heapsize)
{
    int leftchild=2*i;
    int k;
    int temp;

    if(leftchild+1>=heapsize)
        return;
    if(a[leftchild]>a[leftchild+1]) {
        k=leftchild;
    }
    else k=leftchild+1;
    
    if(a[i]>=a[k]) {
        return;
    }
    temp=a[i];
    a[i]=a[k];
    a[k]=temp;
    maxheapify(a,k,heapsize);
}

void buildmaxheap(int a[], int heapsize)
{
    for(int i=(heapsize/2)-1; i>=0; i--){
        maxheapify(a, i, heapsize);
    }
}

void heapsort(int a[], int heapsize)
{
    int temp;

    buildmaxheap(a,heapsize);
    for(int i=heapsize-1; i>0; i--) {
        temp=a[0];
        a[0]=a[i];
        a[i]=temp;

        heapsize--;
        maxheapify(a,0,heapsize);
    }
}

int main()
{
    int arr1[1000];
    for(int i=0; i<1000; i++){
        arr1[i]=1000-i;
    }
    
    int arr2[1000];
    srand((unsigned)time(NULL));
    for(int i=0;i<1000;i++) {
        arr2[i]=rand()%1000;
    }
    
    int arr3[10000];
    for(int i=0; i<10000; i++){
        arr3[i]=10000-i;
    }
    
    int arr4[10000];
    srand((unsigned)time(NULL));
    for(int i=0;i<10000;i++) {
        arr4[i]=rand()%10000;
    }
    
    int arr5[1000000];
    for(int i=0; i<1000000; i++) {
        arr5[i]=1000000-i;
    }
    
    int arr6[1000000];
    srand((unsigned)time(NULL));
    for(int i=0;i<1000000;i++) {
        arr6[i]=rand()%1000000;
    }
    
    for(int i=0;i<10000;i++) {
        printf("%d ", arr3[i]);
    }
    return 0;
}