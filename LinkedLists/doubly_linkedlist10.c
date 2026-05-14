//Creation and traversal of a doubly linked list using tail pointer also
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;
void traversal(){
    struct node *temp;
    temp=head;
    while(temp!=NULL){
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void createNode(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
    printf("Node created successfully\n");
}
int main(){
    int choice;
    do{
        printf("\n===== MENU =====\n");
        printf("0.Exit\n");
        printf("1.Traversal\n");
        printf("2.Create New Node\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("Exiting.....\n");
                break;
            case 1:
                traversal();
                break;
            case 2:
                createNode();
                break;
            default:
                printf("Invalid choice...\n");
                break;
        }
    }while(choice!=0);
    struct node *temp,*next;
    temp=head;
    while(temp!=NULL){
        next=temp->next;
        free(temp);
        temp=next;
    }
    return 0;
}