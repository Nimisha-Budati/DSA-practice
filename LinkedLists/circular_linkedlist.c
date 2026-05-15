//Creation and traversal of a circular linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL,*temp=NULL;
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
    printf("Node created successfully...\n");
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
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("Exiting.....\n");
                break;
            case 1:
                traversal();
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