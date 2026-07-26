//finding middle element in linked list
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
void traversal(){
    if(head==NULL){
        printf("Linked List is empty\n");
        return;
    }
    struct node *temp=head;
    while(temp!=NULL){
        printf("%d -> ",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
void mid(){
    if(head==NULL){
        printf("Linked List is empty\n");
        return;
    }
    struct node *slow=head,*fast=head;
    traversal();
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    printf("middle element: %d\n",slow->data);
}
int main(){
    int choice;
    do{
        printf("\n===== MENU =====\n");
        printf("0.Exit\n");
        printf("1.Create New Node\n");
        printf("2.Find middle element\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("Exiting program...\n");
                break;
            case 1:
                createNode();
                break;
            case 2:
                mid();
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=0);
    struct node *temp=head;
    while(temp!=NULL){
        struct node *nextnode=temp->next;
        free(temp);
        temp=nextnode;
    }
    return 0;
}