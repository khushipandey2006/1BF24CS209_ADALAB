#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int Partition(int arr[], int lo, int hi){
    int pivot=arr[hi];
    int i=lo-1;
    for(int j=lo;j<=hi-1;j++){
        if(arr[j]<=pivot){
            i++;
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[i+1],&arr[hi]);
    return i+1;
}

void QuickSort(int arr[], int lo, int hi){
    if(lo<hi){
        int p=Partition(arr,lo,hi);
        QuickSort(arr,lo,p-1);
        QuickSort(arr,p+1,hi);
    }
}

int main() {
    int n;
    printf("Enter no. of elements: ");
    scanf("%d",&n);
    int arr[n];
    /*printf("Enter elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
    QuickSort(arr,0,n-1);
    printf("\nSorted Array is:\n");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);
    printf("\n");
    return 0;*/
    //srand(time(NULL));
    for (int i = 0; i < n; i++)
        arr[i] = rand();

    clock_t start = clock();
    QuickSort(arr, 0, n - 1);
    clock_t end = clock();

    double time=((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nTime taken: %f seconds\n",time);
    return 0;
}



