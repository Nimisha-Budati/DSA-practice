//Creation and traversal of circular doubly linked list using head and tail
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};
struct node *head=NULL,*tail=NULL;
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
int main(){
    int choice,n,i;
    printf("Enter size: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        createNode();
    }
    do{
        printf("\n=====MENU=====\n");
        printf("0.Exit\n");
        printf("1.Traversal\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("Exiting....\n");
                break;
            case 1:
                traversal();
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=0);
    struct node *temp,*curr;
    if(head!=NULL){
        temp=head->next;
        while(temp!=head){
            curr=temp;
            temp=temp->next;
            free(curr);
        }
        free(head);
    }
    return 0;
}