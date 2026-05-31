#ifndef ARRAY_H
#define ARRAY_H
#include "common.h"

/* --- 1D Array --- */
void  initArray(int arr[], int* size);

//helper procedure
void  printArray(int arr[], int size);

//Basic operation
int   insertAt(int *arr, int* size, int index, int value);
int   deleteAt(int arr[], int* size, int index);
int   linearSearch(int arr[], int size, int value);
int   binarySearch(int arr[], int size, int value);

//sorting & reverse
void  bubbleSort(int arr[], int size);
void  selectionSort(int arr[], int size);
void  reverseArray(int arr[], int size);

//mathemathical operation
int   findMax(int arr[], int size);
int   findMin(int arr[], int size);
int   sumArray(int arr[], int size);
double averageArray(int arr[], int size);


/* --- 2D Matrix --- */
//matrix operation
void  initMatrix(int m[][MAX_COLS], int* rows, int* cols);
void  printMatrix(int m[][MAX_COLS], int rows, int cols);
void  transposeMatrix(int m[][MAX_COLS], int rows, int cols, int out[][MAX_COLS]);
int sumDiagonal(int m[][MAX_COLS], int n);
void  addMatrices(int a[][MAX_COLS], int b[][MAX_COLS], int r[][MAX_COLS], int rows, int cols);
int isSymmetric(int m[][MAX_COLS], int n);
void sortRows(int m[][MAX_COLS], int rows, int cols);

/* --- Dynamic Array --- */
int*  createDynamicArray(int capacity);
void  fillArray(int* arr, int size);
void  freeArray(int* arr);

#endif
