#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

void merge(int a[], int p, int q, int r) {
	int i=p, j=q+1, k=p;
	int tmp[100000];
	while(i<=q && j<=r) {
		if (a[i]<=a[j])
			tmp[k++]=a[i++];
		else
			tmp[k++]=a[j++];
	}
	while (i<=q)
		tmp[k++]=a[i++];
	while(j<=r)
		tmp[k++]=a[j++];
	for(int t=p; t<=r; t++)
		a[t]=tmp[t];
}

void mergesort(int a[], int p, int r)
{
    int q;
    if(p<r) {
        q=(p+r)/2;
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

int compare (const void *first, const void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else 
        return 0;
}

int main()
{
    int arr1[1000];
    srand((unsigned)time(NULL));
    for(int i=0;i<1000;i++) {
        arr1[i]=rand()%1000+1;
    }

    int arr2[1000];
    for(int i=0; i<1000; i++){
        arr2[i]=1000-i;
    }
        
    int arr3[10000];
    for(int i=0;i<10000;i++) {
        arr3[i]=rand()%10000+1;
    }

    int arr4[10000];
    for(int i=0; i<10000; i++){
        arr4[i]=10000-i;
    }
    
    int arr5[100000];
    for(int i=0;i<100000;i++) {
        arr5[i]=rand()%100000+1;
    }
    
    int arr6[100000];
    for(int i=0; i<100000; i++) {
        arr6[i]=100000-i;
    }
        
    printf("\t Random1000  Reverse1000  Random10000  Reverse10000  Random100000  Reverse100000\n");
    printf("Bubble       ");
    
    clock_t start, end;
    
    int a1[1000];
    memcpy(a1, arr1, sizeof(a1));
    float d1;
    start=clock();
    bubblesort(a1, 1000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf(" %.3f ", d1);
    
    int a2[1000];
    memcpy(a2, arr2, sizeof(a2));
    start=clock();
    bubblesort(a2, 1000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);
    
    int a3[10000];
    memcpy(a3, arr3, sizeof(a3));
    start=clock();
    bubblesort(a3, 10000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t%.3f ", d1);
    
    int a4[10000];
    memcpy(a4, arr4, sizeof(a4));
    start=clock();
    bubblesort(a4, 10000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t      %.3f ", d1);
    
    int a5[100000];
    memcpy(a5, arr5, sizeof(a5));
    start=clock();
    bubblesort(a5, 100000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);
    
    int a6[100000];
    memcpy(a6, arr6, sizeof(a6));
    start=clock();
    bubblesort(a6, 100000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t  %.3f ", d1);
    
    
    printf("\nselection");
    memcpy(a1, arr1, sizeof(a1));
    start=clock();
    selectionsort(a1, 1000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("     %.3f ", d1);

    memcpy(a2, arr2, sizeof(a2));
    start=clock();
    selectionsort(a2, 1000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);
    
    memcpy(a3, arr3, sizeof(a3));
    start=clock();
    selectionsort(a3, 10000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t%.3f ", d1);
    
    memcpy(a4, arr4, sizeof(a4));
    start=clock();
    selectionsort(a4, 10000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t      %.3f ", d1);
    
    memcpy(a5, arr5, sizeof(a5));
    start=clock();
    selectionsort(a5, 100000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t    %.3f ", d1);

    memcpy(a6, arr6, sizeof(a6));
    start=clock();
    selectionsort(a6, 100000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);

    
    printf("\nInsertion");
    memcpy(a1, arr1, sizeof(a1));
    start=clock();
    insertionsort(a1, 1000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("     %.3f ", d1);
    
    memcpy(a2, arr2, sizeof(a2));
    start=clock();
    insertionsort(a2, 1000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);
    
    memcpy(a3, arr3, sizeof(a3));
    start=clock();
    insertionsort(a3, 10000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t%.3f ", d1);
    
    memcpy(a4, arr4, sizeof(a4));
    start=clock();
    insertionsort(a4, 10000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t      %.3f ", d1);
    
    memcpy(a5, arr5, sizeof(a5));
    start=clock();
    insertionsort(a5, 100000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t    %.3f ", d1);

    memcpy(a6, arr6, sizeof(a6));
    start=clock();
    insertionsort(a6, 100000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);
    
    
    printf("\nMerge");
    memcpy(a1, arr1, sizeof(a1));
    start=clock();
    mergesort(a1, 0, 999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("     %.3f ", d1);
    
    memcpy(a2, arr2, sizeof(a2));
    start=clock();
    mergesort(a2, 0, 999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);
    
    memcpy(a3, arr3, sizeof(a3));
    start=clock();
    mergesort(a3, 0, 9999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t%.3f ", d1);
    
    memcpy(a4, arr4, sizeof(a4));
    start=clock();
    mergesort(a4, 0, 9999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t      %.3f ", d1);
    
    memcpy(a5, arr5, sizeof(a5));
    start=clock();
    mergesort(a5, 0, 99999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t    %.3f ", d1);

    memcpy(a6, arr6, sizeof(a6));
    start=clock();
    mergesort(a6, 0, 99999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);            
    

    printf("\nQuick1");
    memcpy(a1, arr1, sizeof(a1));
    start=clock();
    quicksortlast(a1, 0, 999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("        %.3f ", d1);
    
    memcpy(a2, arr2, sizeof(a2));
    start=clock();
    quicksortlast(a2, 0, 999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);
    
    memcpy(a3, arr3, sizeof(a3));
    start=clock();
    quicksortlast(a3, 0, 9999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t%.3f ", d1);
    
    memcpy(a4, arr4, sizeof(a4));
    start=clock();
    quicksortlast(a4, 0, 9999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t      %.3f ", d1);
    
    memcpy(a5, arr5, sizeof(a5));
    start=clock();
    quicksortlast(a5, 0, 99999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t    %.3f ", d1);

    memcpy(a6, arr6, sizeof(a6));
    start=clock();
    quicksortlast(a6, 0, 99999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);

    memcpy(a1, arr1, sizeof(a1));
    start=clock();
    quicksortlast(a1, 0, 999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("        %.3f ", d1);
    
    memcpy(a2, arr2, sizeof(a2));
    start=clock();
    quicksortlast(a2, 0, 999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);
    
    memcpy(a3, arr3, sizeof(a3));
    start=clock();
    quicksortlast(a3, 0, 9999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t%.3f ", d1);
    
    memcpy(a4, arr4, sizeof(a4));
    start=clock();
    quicksortlast(a4, 0, 9999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t      %.3f ", d1);
    
    memcpy(a5, arr5, sizeof(a5));
    start=clock();
    quicksortlast(a5, 0, 99999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t    %.3f ", d1);

    memcpy(a6, arr6, sizeof(a6));
    start=clock();
    quicksortlast(a6, 0, 99999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);

    
    printf("\nQuick2");
    memcpy(a1, arr1, sizeof(a1));
    start=clock();
    quicksortmedian(a1, 0, 999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("        %.3f ", d1);
    
    memcpy(a2, arr2, sizeof(a2));
    start=clock();
    quicksortmedian(a2, 0, 999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);
    
    memcpy(a3, arr3, sizeof(a3));
    start=clock();
    quicksortmedian(a3, 0, 9999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t%.3f ", d1);
    
    memcpy(a4, arr4, sizeof(a4));
    start=clock();
    quicksortmedian(a4, 0, 9999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t      %.3f ", d1);
    
    memcpy(a5, arr5, sizeof(a5));
    start=clock();
    quicksortmedian(a5, 0, 99999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t    %.3f ", d1);

    memcpy(a6, arr6, sizeof(a6));
    start=clock();
    quicksortmedian(a6, 0, 99999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);

    
    printf("\nQuick3");
    memcpy(a1, arr1, sizeof(a1));
    start=clock();
    quicksortrandom(a1, 0, 999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("        %.3f ", d1);
    
    memcpy(a2, arr2, sizeof(a2));
    start=clock();
    quicksortrandom(a2, 0, 999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);
    
    memcpy(a3, arr3, sizeof(a3));
    start=clock();
    quicksortrandom(a3, 0, 9999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t%.3f ", d1);
    
    memcpy(a4, arr4, sizeof(a4));
    start=clock();
    quicksortrandom(a4, 0, 9999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t      %.3f ", d1);
    
    memcpy(a5, arr5, sizeof(a5));
    start=clock();
    quicksortrandom(a5, 0, 99999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t    %.3f ", d1);

    memcpy(a6, arr6, sizeof(a6));
    start=clock();
    quicksortrandom(a6, 0, 99999);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);


    printf("\nHeap");
    memcpy(a1, arr1, sizeof(a1));
    start=clock();
    heapsort(a1, 1000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("        %.3f ", d1);
    
    memcpy(a2, arr2, sizeof(a2));
    start=clock();
    heapsort(a2, 1000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);
    
    memcpy(a3, arr3, sizeof(a3));
    start=clock();
    heapsort(a3, 10000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t%.3f ", d1);
    
    memcpy(a4, arr4, sizeof(a4));
    start=clock();
    heapsort(a4, 10000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t      %.3f ", d1);
    
    memcpy(a5, arr5, sizeof(a5));
    start=clock();
    heapsort(a5, 100000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t    %.3f ", d1);

    memcpy(a6, arr6, sizeof(a6));
    start=clock();
    heapsort(a6, 100000);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);


    printf("\nC Lib");
    memcpy(a1, arr1, sizeof(a1));
    start=clock();
    qsort(a6,sizeof(a6)/sizeof(int),sizeof(int),compare);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("        %.3f ", d1);
    
    memcpy(a2, arr2, sizeof(a2));
    start=clock();
    qsort(a2,sizeof(a2)/sizeof(int),sizeof(int),compare);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);
    
    memcpy(a3, arr3, sizeof(a3));
    start=clock();
    qsort(a3,sizeof(a3)/sizeof(int),sizeof(int),compare);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t%.3f ", d1);
    
    memcpy(a4, arr4, sizeof(a4));
    start=clock();
    qsort(a4,sizeof(a4)/sizeof(int),sizeof(int),compare);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t      %.3f ", d1);
    
    memcpy(a5, arr5, sizeof(a5));
    start=clock();
    qsort(a5,sizeof(a5)/sizeof(int),sizeof(int),compare);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t    %.3f ", d1);

    memcpy(a6, arr6, sizeof(a6));
    start=clock();
    qsort(a6, sizeof(a6)/sizeof(int), sizeof(int), compare);
    end=clock();
    d1=(float)(end-start)/CLOCKS_PER_SEC;
    printf("\t   %.3f ", d1);
    return 0;
}