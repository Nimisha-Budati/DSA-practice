//Added delection from beginning,end and from a position in a doubly linked list
//insertion at beginning,end and at a position in a doubly linked list
//creation aand traversal of a doublyy linked list
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
    printf("Node created successfully\n");
}
void insertion_at_beginning(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=head;
    if(head!=NULL){
        head->prev=newnode;
    }
    head=newnode;
    count++;
    printf("Node inserted successfully at beginning\n");
}
void insertion_at_end(){
    struct node *newnode,*temp;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    newnode->prev=NULL;
    newnode->next=NULL;
    if(head==NULL){
        head=newnode;
        count++;
        printf("Node inserted successfully at end\n");
        return;
    }
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newnode;
    newnode->prev=temp;
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
    printf("Enter value: ");
    scanf("%d",&newnode->data);
    temp=head;
    for(i=1;i<pos-1;i++){
        temp=temp->next;
    }
    newnode->next=temp->next;
    newnode->prev=temp;
    temp->next->prev=newnode;
    temp->next=newnode;
    count++;
    printf("Node inserted successfully at position\n");
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
    printf("Node deleted successfully from beginning\n");
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
        printf("Node deleted successfully from end\n");
        return;
    }
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
    count--;
    printf("Node deleted successfully from end\n");
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
    printf("Node deleted successfully from position\n");
}
void length(){
    struct node *temp;
    int len=0;
    temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    printf("length of the linked list: %d\n",len);
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
        printf("6.Delete from Beginning\n");
        printf("7.Delete from End\n");
        printf("8.Delete from Position\n");
        printf("9.Length of the linked list\n");
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
            case 6:
                deletion_from_beginning();
                break;
            case 7:
                deletion_from_end();
                break;
            case 8:
                deletion_from_position();
                break;
            case 9:
                length();
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