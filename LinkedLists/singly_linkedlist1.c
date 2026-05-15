//Added insertion in a singly linked list
//Creation aand traversal of a singly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
int count;
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
    count++;
    printf("Node created successfully\n");
}
void insertion_at_beginning(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
     if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data to insert: ");
    scanf("%d",&newnode->data);
    newnode->next=head;
    head=newnode;
    count++;
    printf("Node inserted successfully at beginning\n");
    return;
}
void insertion_at_end(){
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newnode->next=NULL;
    printf("Enter data to insert: ");
    scanf("%d",&newnode->data);
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
    count++;
    printf("Node inserted successfully at end\n");
    return;
}
void insertion_at_position(){
    struct node *temp,*newnode;
    int pos,i;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter position where to insert: ");
    scanf("%d",&pos);
     if(pos<1 || pos>count+1){
        printf("Invalid position\n");
        free(newnode);
        return;
    }
    printf("Enter data to insert: ");
    scanf("%d",&newnode->data);
    if(pos==1){
        newnode->next=head;
        head=newnode;
    }
    else{
        temp=head;
        for(i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    count++;
    printf("Node inserted successfully at position %d\n",pos);
    return;
}
int main(){
    int choice;
    do{
        printf("\n===== MENU =====\n");
        printf("0.Exit\n");
        printf("1.Traversal\n");
        printf("2.Create New Node\n");
        printf("3.Insert at Beginning\n");
        printf("4.Insert at End\n");
        printf("5.Insert at Position\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("Exiting program...\n");
                break;
            case 1:
                traversal();
                break;
            case 2:
                createNode();
                break;
            case 3:
                insertion_at_beginning();
                break;
            case 4:
                insertion_at_end();
                break;
            case 5:
                insertion_at_position();
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