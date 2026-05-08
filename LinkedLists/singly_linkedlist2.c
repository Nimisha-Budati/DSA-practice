//Added delection from a singly linked list
//insertion in a singly linked list
//creation aand traversal of a singly linked list
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
void deletion_from_beginning(){
    struct node *temp;
    if(head==NULL){
        printf("Linked List is empty\n");
        return;
    }
    temp=head;
    head=head->next;
    free(temp);
    printf("Node deleted successfully from beginning\n");
    count--;
    return;
}
void deletion_from_end(){
    struct node *temp,*prev;
    if(head==NULL){
        printf("Linked List is empty\n");
        return;
    }
    if(head->next==NULL){
        free(head);
        head=NULL;
    }
    else{
        temp=head;
        prev=NULL;
        while(temp->next!=NULL){
            prev=temp;
            temp=temp->next;
        }

        prev->next=NULL;
        free(temp);
    }
    count--;
    printf("Node deleted successfully from end\n");
    return;
}
void deletion_from_position(){
    struct node *temp,*prev;
    int pos,i;
    if(head==NULL){
        printf("Linked List is empty\n");
        return;
    }
    printf("Enter position where to delete: ");
    scanf("%d",&pos);
    if(pos<1 || pos>count){
        printf("Invalid position\n");
        return;
    }
    if(pos==1){
        temp=head;
        head=head->next;
        free(temp);
    }
    else{
        temp=head;
        for(i=1;i<pos;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
    }
    count--;
    printf("Node deleted successfully from position %d\n",pos);
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