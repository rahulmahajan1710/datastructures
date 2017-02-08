//
//  main.c
//  TEST-DS
//
//  Created by rahul mahajan on 08/02/17.
//  Copyright © 2017 rahul mahajan. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>


#pragma mark- Linked List

struct ListNode{
    int data;
    struct ListNode *next;
}*head;


_Bool isListEmpty(){
    if (head==NULL) {
        return 1;
    }
    return 0;
}

void insertNode(int nData){
    struct ListNode *temp;
    temp = (struct ListNode*)malloc(sizeof(struct ListNode));
    temp->data = nData;
    temp->next = NULL;
    if (head==NULL) {
        head = temp;
    }
    else{
        struct ListNode *tempHead = head;
        while (tempHead->next!=NULL) {
            tempHead = tempHead->next;
        }
        tempHead->next = temp;
    }
}

void createList(){
    int noOfNodes = 0;
    printf("Enter number of nodes to insert:");
    scanf("%d",&noOfNodes);
    if (head!=NULL) {
        
    }
    while (noOfNodes>0) {
        printf("enter Node Data:");
        int data = 0;
        if(scanf("%d",&data)<=0){
            printf("Invalid data.\n");
        }
        else{
            insertNode(data);
            noOfNodes--;
        }
    }
}

void displayList(){
    struct ListNode *temp = head;
    if (temp==NULL) {
        return;
    }
    else{
        while (temp!=NULL) {
            printf("%d-->",temp->data);
            temp = temp->next;
        }
        if (temp==NULL) {
            printf("NULL");
        }
    }
     printf("\n\n");
}

void insertAt(int position,int data){
    int i;
    struct ListNode *temp, *left = NULL, *right;
    right = head;
    if (head==NULL) {
        return;
    }
    else{
        temp = (struct ListNode*)malloc(sizeof(struct ListNode));
        temp->data = data;
        if (position==1) {
            temp->next = right;
            head = temp;
        }
        else{
            for (i=1; i<position && right!=NULL; i++) {
                left = right;
                right = right->next;
            }
            left->next = temp;
            left = temp;
            left->next = right;
        }
    }
}

void deleteNode(int data){
    struct ListNode *prev = NULL,*temp;
    temp = head;
    while (temp!=NULL) {
        if (temp->data==data){
            if (temp==head) {
                head = temp->next;
            }
            else{
                prev->next = temp->next;
            }
            free(temp);
            temp = NULL;
        }
        else{
            prev = temp;
            temp = temp->next;
        }
    }
}

void reverseList(){
    if (!isListEmpty()) {
    struct ListNode *prev=NULL, *current = head , *next = NULL;
    
    while (current!=NULL){
        next = current->next;
        current->next= prev;
        prev =current;
        current = next;
    }
    head = prev;
    }
}

void sortList(){
    if (!isListEmpty()) {
        
    }
}



int main(int argc, const char * argv[]) {
    
    //Linked List Operations------------------------//

    int choice = 0 ,num;
    while (1){
        printf("\nList Operations\n");
        printf("===============\n");
        printf("1.Create List\n");
        printf("2.Insert Node\n");
        printf("3.Display\n");
        printf("4.Insert at Position\n");
        printf("5.Delete\n");
        printf("6.Reverse List\n");
        printf("7.Sort List\n");
        printf("0.Exit\n");
        printf("\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        if (choice==0) {
            printf("Exiting Program...");
            break;
        }
        else{
            switch (choice) {
                case 1:
                    createList();
                    break;
                
                case 2:{
                    printf("Enter Node Data:");
                    scanf("%d",&num);
                    insertNode(num);
                }
                    break;
                
                case 3:{
                    displayList();
                }
                    break;
                
                case 4:{
                    int position, data;
                    printf("Enter Position:");
                    scanf("%d",&position);
                    printf("Enter Node Data:");
                    scanf("%d",&data);
                    insertAt(position, data);
                }
                    break;
                    
                case 5:{
                    if (head==NULL) {
                        printf("List is empty...");
                    }
                    else{
                        printf("Enter data to delete:");
                        scanf("%d",&num);
                        deleteNode(num);
                    }
                }
                    break;
                    
                    
                case 6:{
                    reverseList();
                }
                    break;
                    
                case 7:{
                    sortList();
                }
                    break;
                
                default:
                    break;
            }
        }
    }
    //----------------------------------------------//
    
    return 0;
}
