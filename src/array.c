#include "../include/array.h"      // It represent the path towards my header (library)
#include <stdio.h>
#include <stdlib.h>

/* Initialize: set size to 0 — array is logically empty */ 
void initArray(int arr[], int* size) {
    *size = 0;
}

/* Print in [a, b, c] format */
void printArray(int arr[], int size) {
    printf("[");
    int i;
    for (i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i < size - 1) printf(", ");
    }
    printf("]\n");
}

/* Insert value at index — shift elements right first */
int insertAt(int *arr, int* size, int index, int value) {
    if (index < 0 || index > *size) return -1;  // invalid index
    if (*size >= MAX_1D) return -1;             // array full
    int i;
    for (i = *size; i > index; i--)
        arr[i] = arr[i - 1];

    arr[index] = value;
    (*size)++;
    return 0;
}
/* delet value at index - shift element left first */
int deleteAt(int arr[], int *size, int index){
    if( index < 0 || index >= *size )

       return -1;

    int i;

    for(i = index+1 ; i < *size-1 ; i++){

        arr[i] = arr[i+1];
    }
    (*size)--;

    return 0;
}
/* search a value at index - cel by cel */
int linearSearch(int arr[], int size, int value){
    int i;

    for(i = 0 ; i < size-1 ; i++)
       if (arr[i] == value)
          return i;
        else 
          return -1;
     
}
/* search a value at index - in a sorted array */
int binarySearch(int arr[], int size, int value){

    int i=0;
    int low,high,mid;

    if (size<=0 || size > MAX_1D)
       return -1;
    low=0;
    high=size-1;

    while(low <= high){
     mid = (low + high)/2;
     if(arr[mid] == value)
        return mid;
        else if (arr[mid] > value)
             high = mid-1;
            else 
              low = mid+1;
    }
    return -1;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int swapped = 0;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = 1;
            }
        }
        if (!swapped) break; // Optimization step
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}


void insertionSort(int arr[], int size){

}
void mergeSort(int arr[], int left, int right){

}
void quickSort(int arr[], int low, int high){

}
int findMax(int arr[], int size){
    int i;
    int max = arr[0];
    int min = arr[0];
    for (i=1;i<size;i++)
        if(arr[i]>max)
           max=arr[i];
        if(arr[i]<min)
           min=arr[i];
    
    return max,min;
        
}
int sumArray(int arr[], int size){
    int n,total;
    if ( size <= 0)
        return 0;
    if (n = 0)
       return total;
    else 
       return arr[size-1]+sumArray(arr, size-1);

}
double averageArray(int arr[], int size){

}
/* reverse of an array 1D without another arry */
void reverseArray(int arr[], int size){

    int i,temp;

    for (i=0;i<(size/2);i++){
        temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}
/* */
void rotateLeft(int arr[], int size, int k){

}
void mergeSortedArrays(int a[], int na, int b[], int nb, int out[]){
    
}
void printMatrix(int m[][MAX_COLS], int rows, int cols)
{
    if (m == NULL || rows <= 0 || cols <= 0)
    {
        return;
    }
    for (int i = 0; i < rows; i++)
    {
        printf("["); // instead of doing another loop one could call the printArray function inside
        for (int j = 0; j < cols; j++)
        {
            printf("%4d", m[i][j]);
        }
        printf("]\n");
    }
}
void addMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int rows, int cols)
{
    if (a == NULL || b == NULL || r == NULL || a == r || b == r)
    {
        return;
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            r[i][j] = a[i][j] + b[i][j];
        }
    }
}
int sumDiagonal(int m[][MAX_COLS], int n)
{
    if (m == NULL || n <= 0 || n > MAX_ROWS)
    {
        return 0;
    }
    return m[n - 1][n - 1] + sumDiagonal(m, n - 1);
}

/* */
int* createDynamicArray(int capacity)
{
    int *arr = (int*) malloc(capacity * sizeof(int));

    if (arr == NULL){
        printf("ERROR");
        return NULL;
    }else{
        return arr;
    }

}

/* */
void fillArray(int* arr, int size)
{
     int i;
      for(i = 0; i < size; i++){

            scanf("%d", &arr[i]);
      }
}

/* */
int* resizeArray(int* arr, int newCapacity)
{
     int *NewArr = (int*) realloc(arr, newCapacity * sizeof(int));

     if(NewArr == NULL){
            free(arr);

     }
     return 1;
}

/* */
void freeArray(int* arr)
{
     free(arr);
     arr = NULL;
}