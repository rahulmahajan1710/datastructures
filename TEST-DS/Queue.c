//
//  Queue.c
//  TEST-DS
//
//  Created by rahul mahajan on 16/02/17.
//  Copyright © 2017 rahul mahajan. All rights reserved.
//



#include "Queue.h"


struct Queue {
    int front, rear, size;
    unsigned capacity;
    int *array;
};

typedef struct Queue Queue;

Queue * createQueue(unsigned capacity){
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->capacity = capacity;
    q->array = (int*)malloc(capacity * sizeof(int));
    q->front = q->size = 0;
    q->rear = capacity-1;
    return q;
}

int isQueueFull(Queue *queue){
    return queue->size == queue->capacity;
}

int isQueueEmpty(Queue *queue){
    return queue->size == 0;
}

void enqueue(Queue *queue, int item){
    if (isQueueFull(queue)) {
        printf("Queue is Full");
        return ;
    }
    queue->rear = (queue->rear + 1) % (queue->capacity);
    queue->array[queue->rear] = item;
    queue->size++;
}

int dequeue(Queue *queue){
    if (isQueueEmpty(queue)) {
        printf("Queue is Empty...");
        return INT_MIN;
    }
    int item = queue->array[queue->front];
    queue->front = (queue->front + 1) % queue->capacity;
    queue->size--;
    return item;
}

int queueFront(Queue *queue){
    if (isQueueEmpty(queue)) {
        return INT_MIN;
    }
    return queue->array[queue->front];
}

int queueRear(Queue *queue){
    if (isQueueEmpty(queue)) {
        return INT_MIN;
    }
    return queue->array[queue->rear];
}

void displayQueue(Queue *queue){
    if (isQueueEmpty(queue)) {
        printf("Queue is Empty...");
        return;
    }
    for (int i=queue->front; i<=queue->rear; i++) {
        printf("%d--",queue->array[i]);
    }
}

void queueOperations(){
    int choice = 0 ,num;
    Queue *queue = NULL;
    while (1){
        printf("\nQueue Operations\n");
        printf("===============\n");
        printf("1.  Create Queue.\n");
        printf("2.  Enqueue.\n");
        printf("3.  Dequeue\n");
        printf("4.  Display\n");
        printf("5.  Front\n");
        printf("6.  Rear\n");
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
                    printf("Enter Queue Capacity:");
                    scanf("%d",&num);
                    queue = createQueue(num);
                    int data = 0;
                    while (num>0) {
                        printf("ENter Item Data:");
                        scanf("%d", &data);
                        enqueue(queue, data);
                        num--;
                    }
                }
                    break;
                    
                case 2:{
                    printf("Enter Item:");
                    scanf("%d", &num);
                    enqueue(queue, num);
                }
                    break;
                case 3:{
                    dequeue(queue);
                }
                    break;
                    
                case 4:{
                    displayQueue(queue);
                }
                    break;
                    
                case 5:{
                    int item = queueFront(queue);
                    if (item) {
                        printf("Queue Front is %d",item);
                    }
                }
                    break;
                case 6:{
                    int item= queueRear(queue);
                    if (item) {
                        printf("Queue Rear is %d",item);
                    }
                }
                    break;
            }
        }
    }

}
