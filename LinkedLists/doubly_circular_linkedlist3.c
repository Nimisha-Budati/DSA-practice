//Added length function to find lenght of a doubly circular linked list
//deletion from beginning,end and from a position in a doubly circular linked list using head and tail pointers
//insertion at beginning,end and at a position in a doubly circular linked list using head and tail pointers
//Creation and traversal of circular doubly linked list using head and tail
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;
int count=0;
void createNode(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    if(head==NULL){
        head=tail=newnode;
        newnode->next=head;
        newnode->prev=tail;
    }
    else{
        newnode->prev=tail;
        newnode->next=head;
        tail->next=newnode;
        head->prev=newnode;
        tail=newnode;
    }
    count++;
    printf("Node created successfully\n");
}
void traversal(){
    struct node *temp=head;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    do{
        printf("%d <-> ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("(head)\n");
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
    if(head==NULL){
        head=tail=newnode;
        newnode->next=head;
        newnode->prev=tail;
    }
    else{
        newnode->next=head;
        head->prev=newnode;
        tail->next=newnode;
        newnode->prev=tail;
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
    if(head==NULL){
        head=tail=newnode;
        newnode->next=head;
        newnode->prev=tail;
    }
    else{
        tail->next=newnode;
        newnode->prev=tail;
        newnode->next=head;
        head->prev=newnode;
        tail=newnode;
    }
    count++;
    printf("Node inserted successfully at the end\n");
}
void insertion_at_position(){
    int pos,i;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<1||pos>count+1){
        printf("Invalid position\n");
        return;
    }
    else if(pos==1){
        insertion_at_beginning();
    }
    else if(pos==count+1){
        insertion_at_end();
    }
    else{
        struct node *newnode;
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL){
            printf("Memory allocation failed\n");
            return;
        }
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        struct node *temp;
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
}
void deletion_from_beginning(){
    struct node *temp=head;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    else if(head->next==head){
        head=tail=NULL;
        free(temp);
    }
    else{
        tail->next=head->next;
        head=head->next;
        head->prev=tail;
        free(temp);
    }
    count--;
    printf("Node deleted successfully from the beginning\n");
}
void deletion_from_end(){
    struct node *temp=tail;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    else if(head->next==head){
        head=tail=NULL;
        free(temp);
    }
    else{
        head->prev=tail->prev;
        tail=tail->prev;
        tail->next=head;
        free(temp);
    }
    count--;
    printf("Node deleted successfully from the end\n");
}
void deletion_from_position(){
    int pos,i;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<1||pos>count){
        printf("Invalid position\n");
        return;
    }
    else if(pos==1){
        deletion_from_beginning();
    }
    else if(pos==count){
        deletion_from_end();
    }
    else{
        struct node *temp=head;
        for(i=1;i<pos;i++){
            temp=temp->next;
        }
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        count--;
        printf("Node deleted successfully from position %d\n",pos);
    }
}
void length(){
    struct node *temp=head;
    int length=0;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    do{
        length++;
        temp=temp->next;
    }while(temp!=head);
    printf("Length of the linked list: %d\n",length);
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
        printf("8.Length of the list\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0: printf("Exiting.....\n"); break;
            case 1: traversal(); break;
            case 2: insertion_at_beginning(); break;
            case 3: insertion_at_end(); break;
            case 4: insertion_at_position(); break;
            case 5: deletion_from_beginning(); break;
            case 6: deletion_from_end(); break;
            case 7: deletion_from_position(); break;
            case 8: length(); break;
            default:
                printf("Invalid choice..\n");
        }
    }while(choice!=0);
    if(head!=NULL){
        struct node *temp=head->next,*next;
        while(temp!=head){
            next=temp->next;
            free(temp);
            temp=next;
        }
        free(head);
    }
    return 0;
}