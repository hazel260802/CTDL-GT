#include<stdlib.h>
#include<stdio.h>
#define H 100
int A[H],TA[H];
void selectionSort(int a[],int n){
    //index tu 1 den n
    for(int k=1;k<=n;k++){
        int min=k;
        for(int j=k+1;j<=n;j++){
            if(a[min]>a[j])min=j;
        }
        int tmp=a[min];
        a[min]=a[k];
        a[k]=tmp;
    }
}
void insertionSort(int a[],int n){
    //index tu 1 den n
    for(int k=1;k<=n;k++){
        int last=a[k];
        int j=k;
        while(j>1&&a[j-1]>last){
            a[j]=a[j-1];
            j--;
        }
        a[j]=last;
    }
}
void bubbleSort(int a[],int n){
    //index tu 1 den n
    int swapped;
    do{
        swapped=0;
        for (int i = 0; i < n; i++)
        {
            if(a[i]>a[i+1]){
                int tmp=a[i];
                a[i]=a[i+1];
                a[i+1]=tmp;
                swapped=1;
            }
        }
    }while(swapped==1);
}
//MergeSort
void merge(int A[], int L, int M, int R) {
    // tron 2 day da sap A[L..M] va A[M+1..R]
    int i = L; 
    int j = M+1;
    for(int k = L; k <= R; k++){
        if(i > M){ 
            TA[k] = A[j]; 
            j++;
        }
        else if(j > R){
            TA[k] = A[i]; 
            i++;
        }
        else{
            if(A[i] < A[j]){
                TA[k] = A[i]; 
                i++;
            }
            else {
                TA[k] = A[j]; 
                j++;
                }
            }
        }
    for(int k = L; k <= R; k++) A[k] = TA[k];
}
void mergeSort(int A[], int L, int R) {
    if(L < R){
        int M = (L+R)/2;
        mergeSort(A,L,M);
        mergeSort(A,M+1,R);
        merge(A,L,M,R);
    }
}

//QuickSort
void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
} 

int partition(int A[], int L, int R, int indexPivot) {
    int pivot = A[indexPivot];
    swap(&A[indexPivot], &A[R]);
    int storeIndex = L;
    for(int i = L; i <= R-1; i++){
        if(A[i] < pivot){
            swap(&A[storeIndex], &A[i]);
            storeIndex++;
        }
    }
    swap(&A[storeIndex],&A[R]);
    return storeIndex;
}
void quickSort(int A[], int L, int R) {
    if(L < R){
        int index = (L + R)/2;
        index = partition(A, L, R, index);
        if(L < index)quickSort(A, L, index-1);
        if(index < R)quickSort(A, index+1, R);
    }
}
//Vun lại đống
void heapify(int A[], int i, int N){
    int L = 2*i;
    int R = 2*i+1;
    int max = i;
    if(L <= N && A[L] > A[i])max = L;
    if(R <= N && A[R] > A[max])max = R;
    if(max != i){ 
        swap(&A[i],&A[max]);
        heapify(A,max,N);
    }
}
// Sắp xếp vun đống
void buildHeap(int A[], int N) {
    for(int i = N/2; i >= 1; i--)heapify(A,i,N);
}
void heapSort(int A[], int N) {
    // index tu 1 -> N
    buildHeap(A,N);
    for(int i = N; i > 1; i--) {
        swap(&A[1],&A[i]);
        heapify(A, 1, i-1); 
    }
}
void output(int A[], int size){
    int i;
    for(i = 0; i < size; i++)printf("%d ", A[i]);
    printf("\n");
}
int main() {
    int arr[] = {12, 11, 13, 5, 6, 7};
    int arr_size = sizeof(arr)/sizeof(arr[0]);
 
    printf("Given array is \n");
    output(arr, arr_size);
    
    printf("\nSorted array by merge sort is \n"); 
    mergeSort(arr, 0, arr_size - 1);
    output(arr, arr_size);
    return 0;
}
//gcc -o prog Sort.c 
// ./prog