//Added insertion at beginning,end and at a position in a doubly linked list using tail pointer
//Creation and traversal of a doubly linked list using tail pointer also
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;
int count=0;
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
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=head;
    if(head==NULL){
        head=tail=newnode;
    }
    else{
        head->prev=newnode;
        head=newnode;
    }
    count++;
    printf("Node inserted successfully at beginning\n");
}
void insertion_at_end(){
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
        newnode->prev=tail;
        tail->next=newnode;
        tail=newnode;
    }
    count++;
    printf("Node inserted successfully at end\n");
}
void insertion_at_position(){
    struct node *newnode,*temp;
    int pos,i;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<1 || pos>count+1){
        printf("Invalid position\n");
        return;
    }
    if(pos==1){
        insertion_at_beginning();
        return;
    }
    if(pos==count+1){
        insertion_at_end();
        return;
    }
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    temp=head;
    for(i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
    count++;
    printf("Node inserted successfully at position %d\n",pos);
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
                printf("Exiting.....\n");
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