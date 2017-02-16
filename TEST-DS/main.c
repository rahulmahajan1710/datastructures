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
            prev = current;
            current = next;
        }
        head = prev;
    }
}


struct ListNode * getTail(struct ListNode *cur){
    while (cur!=NULL && cur->next!=NULL) {
        cur = cur->next;
    }
    return cur;
}

struct ListNode *partitionList(struct ListNode *head, struct ListNode *end, struct ListNode **newHead, struct ListNode **newTail){
    struct ListNode *pivot = end;
    struct ListNode *prev = NULL , *cur = head, *tail = pivot;
    
    while (cur!= pivot) {
        if (cur->data < pivot->data) {
            if ((*newHead)==NULL) {
                (*newHead) = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        else{
            if (prev) {
                prev->next = cur->next;
            }
            struct ListNode *tmp = cur->next;
            cur->next = NULL;
            tail->next = cur;
            tail = cur;
            cur = tmp;
        }
    }
    if ((*newHead)==NULL) {
        (*newHead) = pivot;
    }
    
    (*newTail) = tail;
    return pivot;
}

struct ListNode * quickSortRec(struct ListNode *head, struct ListNode *end){
    if (!head && head==end) {
        return head;
    }
    struct ListNode *newHead= NULL, *newTail = NULL;
    struct ListNode *pivot = partitionList(head, end, &newHead, &newTail);
    
    if (newHead != pivot) {
        struct ListNode *tmp = newHead;
        while (tmp->next!=NULL) {
            tmp = tmp->next;
        }
        tmp->next = NULL;
        newHead = quickSortRec(newHead, tmp);
        tmp = getTail(newHead);
        tmp->next = pivot;
    }
    pivot->next = quickSortRec(pivot->next, newTail);
    return newHead;
}

//here the sorting happens exclusive of the end node
struct ListNode *quickSortRecur(struct ListNode *head, struct ListNode *end)
{
    // base condition
    if (!head || head == end)
        return head;
    
    struct ListNode *newHead = NULL, *newEnd = NULL;
    
    // Partition the list, newHead and newEnd will be updated
    // by the partition function
    struct ListNode *pivot = partitionList(head, end, &newHead, &newEnd);
    
    // If pivot is the smallest element - no need to recur for
    // the left part.
    if (newHead != pivot)
    {
        // Set the node before the pivot node as NULL
        struct ListNode *tmp = newHead;
        while (tmp->next != pivot)
            tmp = tmp->next;
        tmp->next = NULL;
        
        // Recur for the list before pivot
        newHead = quickSortRecur(newHead, tmp);
        
        // Change next of last node of the left half to pivot
        tmp = getTail(newHead);
        tmp->next =  pivot;
    }
    
    // Recur for the list after the pivot element
    pivot->next = quickSortRecur(pivot->next, newEnd);
    
    return newHead;
}

void quickSortList(struct ListNode **head){
    (*head) = quickSortRec(*head, getTail(*head));
    return;
}

//Simple Sorting of linked List-------//
void sortLinkedList(struct ListNode **headRef){
    if ((*headRef)==NULL) {
        return;
    }
    struct ListNode *temp = *headRef , *count = NULL;
    for (; temp->next != NULL; temp=temp->next) {
        for (count = temp->next; count!=NULL; count = count->next) {
            if (temp->data > count->data) {
                int t = temp->data;
                temp->data = count->data;
                count->data = t;
            }
        }
    }
}

void sortList(){
    if (!isListEmpty()) {
        sortLinkedList(&head);
        // quickSortList(&head);
    }
}


#pragma mark- Quick Sort Array

void swap(int *a, int *b){
    int t =*a;
    *a = *b;
    *b = t;
}

void printArray(int arr[], int size){
    for (int i=0; i<size; i++) {
        printf("%d--",arr[i]);
    }
}

int partition(int arr[], int start, int end){
    int pivot = arr[end];
    int pIndex = start;
    for (int i= start; i<end; i++) {
        if (pivot>=arr[i]) {
            swap(&arr[pIndex], &arr[i]);
            pIndex++;
        }
    }
    swap(&arr[pIndex], &arr[end]);
    return pIndex;
}

void quickSort(int arr[], int start, int end){
    if (start<end) {
        int partIndex = partition(arr, start, end);
        quickSort(arr, start, partIndex-1);
        quickSort(arr, partIndex+1, end);
    }
}

void getMiddle(struct ListNode *headRef){
    if (!isListEmpty()) {
        struct ListNode *slowPtr = head , *fastPtr =head;
        while (fastPtr!=NULL && fastPtr->next!=NULL) {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        printf("The Middle Node data is: %d",slowPtr->data);
    }
}

void deleteLinkedList(struct ListNode **headRef){
    if (!isListEmpty()) {
        struct ListNode *current = *headRef, *next =NULL;
        while (current!=NULL) {
            next = current->next;
            free(current);
            current = next;
        }
        *headRef = NULL;
    }
}

void detectLoopInList(struct ListNode *headRef){
    if (!isListEmpty()) {
        struct ListNode *sp = headRef, *fp = headRef;
        while (sp && fp && fp->next!=NULL) {
            sp= sp->next;
            fp = fp->next->next;
            if (sp == fp) {
                printf("Found Loop in List");
                break;
            }
        }
    }
}

/* Outer loop is used to pick the elements one by one and inner loop compares the picked element with rest of the elements.
 */
void removeDuplicates(struct ListNode *headRef){
    if (!isListEmpty()) {
        struct ListNode *ptr1=headRef , *ptr2= NULL, *dup= NULL;
        while (ptr1 != NULL && ptr1->next!=NULL) {
            ptr2 = ptr1;
            while (ptr2->next!=NULL) {
                if (ptr1->data == ptr2->next->data) {
                    dup = ptr2->next;
                    ptr2->next = ptr2->next->next;
                    free(dup);
                }
                else{
                    ptr2= ptr2->next;
                }
            }
            ptr1 = ptr1->next;
        }
    }
}

int main(int argc, const char * argv[]) {
    
    /*
     //Quick Sort Array---------------//
     int arr[] = {10, 80, 30, 90, 40, 50, 70};
     int size = sizeof(arr)/sizeof(arr[0]);
     quickSort(arr, 0, size-1 );
     printArray(arr, size);
     */
    
    //Linked List Operations------------------------//
    
    int choice = 0 ,num;
    while (1){
        printf("\nList Operations\n");
        printf("===============\n");
        printf("1.  Create List\n");
        printf("2.  Insert Node\n");
        printf("3.  Display\n");
        printf("4.  Insert at Position\n");
        printf("5.  Delete\n");
        printf("6.  Reverse List\n");
        printf("7.  Sort List\n");
        printf("8.  Find Middle.\n");
        printf("9.  Delete/ Clean Linked List.\n");
        printf("10. Detect Loop in List.\n");
        printf("11. Remove Duplicates.\n");
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
                case 8:{
                    getMiddle(head);
                }
                    break;
                case 9:
                    deleteLinkedList(&head);
                    break;
                    
                case 10:{
                    //head->next->next->next = head;     //Creating  loop for testing----//
                    detectLoopInList(head);
                }
                    break;
                case 11:
                    removeDuplicates(head);
                    break;
                    
                default:
                    break;
            }
        }
    }
    //----------------------------------------------//
    
    return 0;
}
