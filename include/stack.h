#ifndef STACK_H
#define STACK_H
#include"common.h"

void initStack(Stack* S);
int push(Stack* S, int value);
int pop(Stack* S);

#endif