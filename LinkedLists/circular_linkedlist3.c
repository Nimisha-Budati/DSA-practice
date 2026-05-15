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

        temp->next=newnode;
        newnode->next=head;
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
    struct node *temp=head;

    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    else if(head==head->next){
        temp=head;
        head=NULL;
        free(temp);
    }

    else{
        while(temp->next!=head){
            temp=temp->next;
        }

        temp->next=head->next;
        temp=head;
        head=head->next;

        free(temp);
    }

    count--;

    printf("Node deleted successfully from beginning...\n");
}

void deletion_from_end(){
    struct node *temp=head,*prev;

    if(head==NULL){
        printf("List is empty\n");
        return;
    }

    else if(head==head->next){
        temp=head;
        head=NULL;
        free(temp);
    }

    else{
        while(temp->next!=head){
            prev=temp;
            temp=temp->next;
        }

        prev->next=head;
        free(temp);
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

            case 0: printf("Exiting.....\n"); break;
            case 1: traversal(); break;
            case 2: insertion_at_beginning(); break;
            case 3: insertion_at_end(); break;
            case 4: insertion_at_position(); break;
            case 5: deletion_from_beginning(); break;
            case 6: deletion_from_end(); break;
            case 7: deletion_from_position(); break;

            default:
                printf("Invalid choice..\n");
        }

    }while(choice!=0);

    return 0;
}