#include"../include/stack.h"
#include<stdio.h>
#include<stdlib.h>

void initStack(Stack *S)
{
    S->top = NULL;
}

int push(Stack *S, int value)
{
    if (S == NULL)
    {
        return -1;
    }
    Node *newNode =(Node*)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return -1;
    }
    newNode->data = value;
    newNode->next = S->top; // new node points to old top

    S->top = newNode;       // new node becomes top
    
    return 0;
}

int pop(Stack *S){

    if (S == NULL || S->top == NULL)

        return -1;

    Node *tmp = S->top;

    int val = tmp->data;

    S->top = S->top->next; // move top down

    free(tmp);

    return val;
}
/* return the top value */
int peek(Stack* S)
{
    /* Check if stack is empty */
    if (S->top == NULL)
    {
        return -1; // Sentinel value
    }

    return S->top->data;
}
/* check if the stack empty or no */
int isEmpty(Stack* S)
{
    return (S->top == NULL);
}