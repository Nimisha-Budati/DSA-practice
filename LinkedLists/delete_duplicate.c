//Deleting duplicates in a sorted linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
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
void createNode(){
    struct node *newnode,*temp;
    int value;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d",&value);
    newnode->data=value;
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
void createLL(int size){
    for(int i=0;i<size;i++){
        createNode();
    }
}
int main(){
    int size;
    printf("Enter size of Linked List: ");
    scanf("%d",&size);
    printf("Enter elements of List in sorted order:\n");
    createLL(size);
    printf("Linked list before removing duplicates: ");
    traversal();
    struct node *temp=head,*delete=NULL;
    while(temp!=NULL && temp->next!=NULL){
        if(temp->data==temp->next->data){
            delete=temp->next;
            temp->next=temp->next->next;
            free(delete);
        }
        else{
            temp=temp->next;
        }
    }
    printf("Linked list after removing duplicates: ");
    traversal();
    temp=head;
    while(temp!=NULL){
        struct node *nextnode=temp->next;
        free(temp);
        temp=nextnode;
    }
    return 0;
}