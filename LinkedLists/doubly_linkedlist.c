//creation and traversal of a doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL,*temp=NULL;
void traversal(){
    if(head==NULL){
        printf("Doubly Linked List is empty\n");
        return;
    }
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d <-> ",ptr->data);
        ptr=ptr->next;
    }
    printf("NULL\n");
}
void createNode(){
    struct node *newnode;
    int value;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d",&value);
    newnode->data=value;
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
    printf("Node created successfully\n");
}
int main(){
    int choice,n,i;
    printf("Enter number of nodes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        createNode();
    }
    do{
        printf("\n===== MENU =====\n");
        printf("0.Exit\n");
        printf("1.Traversal\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("Exiting program...\n");
                break;
            case 1:
                traversal();
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=0);
    struct node *ptr=head;
    while(ptr!=NULL){
        struct node *nextnode=ptr->next;
        free(ptr);
        ptr=nextnode;
    }
    return 0;
}