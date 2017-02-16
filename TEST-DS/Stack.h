//
//  Stack.h
//  TEST-DS
//
//  Created by rahul mahajan on 16/02/17.
//  Copyright © 2017 rahul mahajan. All rights reserved.
//

struct Stack {
    int top;
    unsigned capacity;
    int *array;
};

typedef struct Stack Stack;

void stackOperations();

Stack * createStack(unsigned capacity);
void push(Stack *stack, int item);
int pop(Stack *stack);
int isStackEmpty(Stack *stack);
void displayStack(Stack *stack);
