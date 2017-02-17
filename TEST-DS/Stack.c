//
//  Stack.c
//  TEST-DS
//
//  Created by rahul mahajan on 16/02/17.
//  Copyright © 2017 rahul mahajan. All rights reserved.
//

#include "Stack.h"


Stack * createStack(unsigned capacity){
    Stack *st = (Stack*)malloc(sizeof(Stack));
    st->top = -1;
    st->capacity = capacity;
    st->array = (int*)malloc(sizeof(int) * capacity);
    return st;
}

int isFull(Stack *stack){
    return stack->top == stack->capacity-1 ;
}

int isStackEmpty(Stack *stack){
    return stack->top == -1 ;
}

void push(Stack *stack, int item){
    if (isFull(stack)) {
        return;
    }
    stack->array[++stack->top] = item;
}

int pop(Stack *stack){
    if (isStackEmpty(stack)) {
        return INT_MIN;
    }
    return stack->array[stack->top--];
}

void displayStack(Stack *stack){
    if (isStackEmpty(stack)) {
        return;
    }
    int top = stack->top;
    while (top>=0) {
        printf("%d<--",stack->array[top]);
        top--;
    }
}

void stackOperations(){
    Stack *stack = NULL;
    int choice = 0 ,num;
    while (1){
        printf("\n Stack Operations\n");
        printf("===============\n");
        printf("1.  Create Stack\n");
        printf("2.  Push\n");
        printf("3.  Pop\n");
        printf("4.  Display\n");
        printf("5.  Top.\n");
        printf("0.  Exit.\n");
        printf("\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        if (choice==0) {
            printf("Exiting Program...");
            break;
        }
        else{
            switch (choice) {
                case 1:{
                    printf("Enter nodes to push in stack:");
                    scanf("%d",&num);
                    stack =  createStack(num);
                    int item = 0;
                    while(num>0){
                        printf("Enter Item:");
                        scanf("%d",&item);
                        push(stack, item);
                        num--;
                    }
                }
                    break;
                    
                case 2:{
                    printf("Enter Item :");
                    scanf("%d",&num);
                    push(stack, num);
                }
                    break;
                    
                case 3:{
                    int popItem = pop(stack);
                    if (popItem) {
                        printf("Popped Item : %d",popItem);
                    }
                }
                    break;
                    
                case 4:{
                    displayStack(stack);
                }
                    break;
                    
                case 5:{
                    if (!isStackEmpty(stack)) {
                        printf("Top Element is %d",stack->array[stack->top]);
                    }
                }
                    break;
            }
        }
    }
    
}

