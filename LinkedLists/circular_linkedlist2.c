//Added deletion from beginning,end and at a position in a circular linked list
//insertion from beginning,end and at a position in a circular linked list
//Creation and traversal of a circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*temp=NULL;
int count;
void traversal(){
    struct node *temp=head;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    printf("Traversal of a circular linked list: ");
    do{
        printf("%d -> ",temp->data);
        temp=temp->next;
    }while(temp!=head);
    printf("%d\n",head->data);
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
    newnode->next=NULL;
    if(head==NULL){
        head=temp=newnode;
        temp->next=newnode;
    }
    else{
        temp->next=newnode;
        temp=newnode;
        newnode->next=head;
    }
    count++;
    printf("Node created successfully...\n");
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
        head=newnode;
        head->next=head;
    }
    else{
        struct node *temp=head;
        while(temp->next!=head){
            temp=temp->next;
        }
        newnode->next=head;
        temp->next=newnode;
        head=newnode;
    }
    count++;
    printf("Node inserted successfully at beginning..\n");
}
void insertion_at_end(){
    struct node *newnode,*curr;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    if(head==NULL){
        head=temp=newnode;
        head->next=head;
    }
    else{
        curr=head;
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=newnode;
        newnode->next=head;
        temp=newnode;   
    }
    count++;
    printf("Node inserted successfully at end..\n");
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
    else if(pos==1){
        insertion_at_beginning();
        return;
    }
    else if(pos==count+1){
        insertion_at_end();
        return;
    }
    else{
        newnode=(struct node*)malloc(sizeof(struct node));
        if(newnode==NULL){
            printf("Memory allocation failed...\n");
            return;
        }
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->next=NULL;
        temp=head;
        for(i=1;i<pos-1;i++){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
        count++;
        printf("Node inserted successfully at position %d\n",pos);
    }
}
void deletion_from_beginning(){
    struct node *curr=head;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    else if(head==head->next){
        curr=head;
        head=NULL;
        temp=NULL;      // global tail reset
        free(curr);
    }
    else{
        while(curr->next!=head){
            curr=curr->next;
        }
        curr->next=head->next;
        curr=head;
        head=head->next;
        free(curr);
    }
    count--;
    printf("Node deleted successfully from beginning...\n");
}
void deletion_from_end(){
    struct node *curr=head,*prev=NULL;
    if(head==NULL){
        printf("List is empty\n");
        return;
    }
    else if(head==head->next){
        curr=head;
        head=NULL;
        temp=NULL;
        free(curr);
    }
    else{
        while(curr->next!=head){
            prev=curr;
            curr=curr->next;
        }
        prev->next=head;
        temp=prev;
        free(curr);
    }
    count--;
    printf("Node deleted successfully from end...\n");
}
void deletion_from_position(){
    struct node *temp=head,*prev;
    int pos,i;
    printf("Enter position: ");
    scanf("%d",&pos);
    if(pos<1 || pos>count){
        printf("Invalid position\n");
        return;
    }
    else if(pos==1){
        deletion_from_beginning();
        return;
    }
    else if(pos==count){
        deletion_from_end();
        return;
    }
    else{
        for(i=1;i<pos;i++){
            prev=temp;
            temp=temp->next;
        }
        prev->next=temp->next;
        free(temp);
        count--;
        printf("Node deleted successfully from position %d\n",pos);
    }
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
            case 6:
                deletion_from_beginning();
                break;
            case 7:
                deletion_from_end();
                break;
            case 8:
                deletion_from_position();
                break;
            default:printf("Invalid choice..\n");
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