#include "../include/linked_list.h"
#include<stdio.h>
#include<stdlib.h>

/* Initialize my single linked list */
void initList(List* L){

    L -> head = NULL;
    L -> size = 0;

}
/* insertation at the beginning of the list */
int insertBeginning(List* L, int value){

    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));

    if(new_node == NULL)
       retrn -1;

    new_node->data = value;
    new_node->next = L->head;
    L->head = new_node;
    L->size++;

    return 0;
}
