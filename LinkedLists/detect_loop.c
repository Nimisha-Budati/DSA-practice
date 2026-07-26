// Detecting loop in linked list using Floyd's Cycle Detection
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
void createNode(){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
    }
    else{
        temp=head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void detectLoop(){
    if(head==NULL){
        printf("Linked List is empty\n");
        return;
    }
    struct node *slow=head;
    struct node *fast=head;
    while(fast!=NULL&&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            printf("Loop exists!\n");
            return;
        }
    }
    printf("Loop does not exist!\n");
}
int main(){
    int choice;
    do{
        printf("\n===== MENU =====\n");
        printf("0. Exit\n");
        printf("1. Create New Node\n");
        printf("2. Create Loop and Detect\n");
        printf("3. Detect Loop\n");
        printf("Enter choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 0:
                printf("Exiting program...\n");
                break;
            case 1:
                createNode();
                break;
            case 2:
            {
                if(head == NULL||head->next == NULL){
                    printf("Need at least 2 nodes to create a loop.\n");
                    break;
                }
                struct node *temp=head;
                while(temp->next!=NULL){
                    temp=temp->next;
                }
                temp->next=head->next;   
                detectLoop();
                break;
            }
            case 3:
                detectLoop();
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice != 0);
    return 0;
}
// Memory is not freed because a loop may exist.
// The operating system reclaims memory when the program exits.