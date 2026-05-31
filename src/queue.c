#include"../include/queue.h"
#include<stdio.h>
#include<stdlib.h>

/* initilization yhe queue */
void initQueue(Queue* Q)
{
    Q->front = NULL;
    Q->rear = NULL;
}
/* insert value in the rear */
int enqueue(Queue* Q, int value)
{
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return -1; // Allocation failed
    }

    newNode->data = value;
    newNode->next = NULL;

    /* If queue is empty */
    if (Q->front == NULL)
    {
        Q->front = newNode;
        Q->rear = newNode;
    }
    else
    {
        Q->rear->next = newNode;
        Q->rear = newNode;
    }

    return 0; // Success
}
/* delet a value from the front of a queue */
int dequeue(Queue* Q)
{
    /* Check if queue is empty */
    if (Q->front == NULL)
    {
        return -1;
    }

    int value = Q->front->data;

    Node* temp = Q->front;

    /* Move front to next node */
    Q->front = Q->front->next;

    /* If queue becomes empty */
    if (Q->front == NULL)
    {
        Q->rear = NULL;
    }

    free(temp);

    return value;
}