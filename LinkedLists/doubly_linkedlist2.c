//Added deletion from beginning,end and from a position in a doubly linked list
//insertion at beginning,end and at a position in a doubly linked list
//creation and traversal of a doubly linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
int count=0;
struct node *head=NULL,*temp=NULL;
void traversal(){
    if(head==NULL){
        printf("Doubly Linked List is empty\n");
        return;
    }
    struct node *temp=head;
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
        head=temp=newnode;
    }
    else{
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
    }
    count++;
}
void insertion_at_beginning(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=head;
    if(head!=NULL){
        head->prev=newnode;
    }
    head=newnode;
    count++;
    printf("Inserted at beginning\n");
}
void insertion_at_end(){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        count++;
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
    count++;
    printf("Inserted at end\n");
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
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    temp=head;
    for(i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    if(temp->next!=NULL){
        temp->next->prev=newnode;
    }
    temp->next=newnode;
    count++;
    printf("Inserted at position %d\n",pos);
}
void deletion_from_beginning(){
    struct node *temp;
    if(head==NULL){
        printf("Linked List is empty\n");
        return;
    }
    temp=head;
    if(head->next==NULL){
        head=NULL;
    }
    else{
        head=head->next;
        head->prev=NULL;
    }
    free(temp);
    count--;
    printf("Deleted from beginning\n");
}
void deletion_from_end(){
    struct node *temp;
    if(head==NULL){
        printf("Linked List is empty\n");
        return;
    }
    temp=head;
    if(head->next==NULL){
        head=NULL;
        free(temp);
        count--;
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    count--;
    printf("Deleted from end\n");
}
void deletion_from_position(){
    struct node *temp;
    int pos,i;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<1 || pos>count){
        printf("Invalid position\n");
        return;
    }
    if(pos==1){
        deletion_from_beginning();
        return;
    }
    temp=head;
    for(i=1;i<pos;i++){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    if(temp->next!=NULL){
        temp->next->prev=temp->prev;
    }
    free(temp);
    count--;
    printf("Deleted from position %d\n",pos);
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
        printf("2.Insert at Beginning\n");
        printf("3.Insert at End\n");
        printf("4.Insert at Position\n");
        printf("5.Delete from Beginning\n");
        printf("6.Delete from End\n");
        printf("7.Delete from Position\n");
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
                insertion_at_beginning();
                break;
            case 3:
                insertion_at_end();
                break;
            case 4:
                insertion_at_position();
                break;
            case 5:
                deletion_from_beginning();
                break;
            case 6:
                deletion_from_end();
                break;
            case 7:
                deletion_from_position();
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