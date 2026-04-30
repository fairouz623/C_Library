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
int deleteAt(int *arr[], int *size, int index, int value){
    if( index < 0 || index > *size )
       return -1;
    if(*size >= MAX_1D)
       return -1;
    int i;
    for(i = index+1 ; i < *size ; i++)
        arr[i] = arr[i-1];
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
void bubbleSort(int arr[], int size){
    int temp;
    int i,j;
    for(i=0;i<size;i++){
        for(j=i;j<size;j++){
            if (arr[j]>arr[j+1])  
                temp=arr[i];
                arr[i]=arr[i+1];
                arr[i+1]=temp;
                size--;
    }
}
}
void selectionSort(int arr[], int size){

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
    if ( size = 0)
        return 0;
    if (n = 0)
       return total;
    else 
       return sumArray(n-1,total+n);

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
