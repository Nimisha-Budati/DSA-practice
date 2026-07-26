//Merge Two Sorted Linked Lists
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
void createNode(struct node **head){
    struct node *newnode,*temp;
    newnode = (struct node *)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    printf("Enter data: ");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
    if(*head==NULL){
        *head=newnode;
    }
    else{
        temp=*head;
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void createLL(struct node **head,int size){
    for(int i=0;i<size;i++){
        createNode(head);
    }
}
void traversal(struct node *head){
    if(head==NULL){
        printf("Linked List is empty\n");
        return;
    }
    while(head!=NULL){
        printf("%d -> ",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
struct node* merge(struct node *head1, struct node *head2){
    if(head1==NULL)
        return head2;
    if(head2==NULL)
        return head1;
    struct node *head=NULL;
    struct node *tail=NULL;
    if(head1->data <= head2->data){
        head=head1;
        head1=head1->next;
    }
    else{
        head=head2;
        head2=head2->next;
    }
    tail=head;
    while(head1!=NULL && head2!=NULL){
        if(head1->data <= head2->data){
            tail->next=head1;
            tail=head1;
            head1=head1->next;
        }
        else{
            tail->next=head2;
            tail=head2;
            head2=head2->next;
        }
    }
    if(head1!=NULL)
        tail->next=head1;
    else
        tail->next=head2;
    return head;
}
int main(){
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *merged=NULL;
    int size1,size2;
    printf("Enter size of Linked List 1: ");
    scanf("%d",&size1);
    printf("Enter elements of List 1 in sorted order:\n");
    createLL(&head1,size1);
    printf("Enter size of Linked List 2: ");
    scanf("%d",&size2);
    printf("Enter elements of List 2 in sorted order:\n");
    createLL(&head2,size2);
    printf("\nLinked List 1:\n");
    traversal(head1);
    printf("Linked List 2:\n");
    traversal(head2);
    merged=merge(head1,head2);
    printf("Merged Linked List:\n");
    traversal(merged);
    while(merged != NULL){
        struct node *nextnode=merged->next;
        free(merged);
        merged=nextnode;
    }
    return 0;
}