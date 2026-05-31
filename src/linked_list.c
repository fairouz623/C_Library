#include "../include/linked_list.h"
#include<stdio.h>
#include<stdlib.h>

/* Initialize my single linked list */
void initList(List* L){

    L -> head = NULL;
    L -> size = 0;

}
/* insertation the value-- at the beginning of the list */
int insertBeginning(List* L, int value)
{
    //declaration of the value that insert
    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return -1; // Allocation failed
    }

    newNode->data = value;
    newNode->next = L->head;

    L->head = newNode;//change the head pointer to point in newnode
    L->size++;//increment of the size after adding node

    return 0; // Success
}
/* insertation of the value-- at the end of the list */
int insertEnd(List* L, int value)
{
    /* If the list is empty */
    if (L->head == NULL)
    {
        return -1;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));

    if (newNode == NULL)
    {
        return -1; // Allocation failed
    }

    newNode->data = value;
    newNode->next = NULL;

    Node* current = L->head;

    /* Find the last node */
    while (current->next != NULL)
    {
        current = current->next;
    }

    /* Link new node at the end */
    current->next = newNode;

    L->size++;// increment the size after adding node

    return 0; // Success
}
/* insert at position-- in linked list */
int insertAtPosition(List* L, int pos, int value)
{
    //Invalid position 
    if (pos <= 0 || pos > L->size)
    {
        return -1;
    }

    Node* newNode = (Node*)malloc(sizeof(Node));

    //check if ther is a memory space
    if (newNode == NULL)
    {
        return -1; // Allocation failed
    }

    newNode->data = value;

    Node* current = L->head;

    /* Move to node at position pos - 1 */
    for (int i = 0; i < pos - 1; i++)
    {
        current = current->next;
    }

    /* Insert new node */
    newNode->next = current->next;
    current->next = newNode;

    L->size++;

    return 0; // Success
}

/* traverse the list till find the value and print its address*/
Node* searchValue(List* L, int value){

    //initialize a temporary pointer to traversz the list starting from the head node
    Node* temp = L->head;

    //check if the list pointer is NULL or if the list is completly empty
    if(L == NULL || L->head == NULL){
        return NULL;
    }

    //loop through the nodes until the end of the list (null)
    while (temp != NULL){
        if (temp->data == value){
            return temp;
        }
        temp = temp->next;
    }

    //return null if the value was not found after checking the entire list
    return NULL;
}
/* print the all values of the list */
void displayList(List* L)
{
    //pointer to traverse the list safely
    Node* temp = L->head;

    //saftey check :
    if(temp == NULL || L == NULL){
        printf("the list is empty\n");
        return;
    }

    //iterate through each node and print its data sequentially
    while (temp != NULL){

        printf("[%d]->",temp->data);
        temp = temp->next;

    }

    //explicitly indicare the logical end of the single linked list 
    printf("NULL\n"); 
}

/* Reverse the direction of the stocks*/
void reverseList(List* L){

    //we need 3 pointers to do the reverse
    Node* previous = NULL;//
    Node* current = L->head;//
    Node* next = NULL;//pointer that protcte list from lose

    while (current != NULL){
        next = current->next;
        current->next = previous;
        previous = current;
        current = next;
    }

    L->head = previous;

}


