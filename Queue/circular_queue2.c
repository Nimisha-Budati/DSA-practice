//Implementation of circular queue using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL,*rear=NULL;
void enqueue(int x){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    newnode->data=x;
    newnode->next=NULL;
    if(front==NULL&&rear==NULL){
        front=rear=newnode;
        newnode->next=front;
    }
    else{
        rear->next=newnode;
        rear=newnode;
        rear->next=front;
    }
    printf("Enqueued %d into circular queue\n",x);
}
void dequeue(){
    struct node *temp=front;
    if(front==NULL&&rear==NULL){
        printf("Circular queue is empty\n");
        return;
    }
    else if(front->next==front){
        printf("Dequeued %d from circular queue\n",temp->data);
        front=rear=NULL;
        free(temp);
    }
    else{
        printf("Dequeued %d from circular queue\n",temp->data);
        front=front->next;
        rear->next=front;
        free(temp);
    }
}
void peek(){
    if(front==NULL&&rear==NULL){
        printf("Circular queue is empty\n");
        return;
    }
    else{
        printf("Front element: %d\n",front->data);
    }
}
void display(){
    struct node *temp=front;
    if(front==NULL&&rear==NULL){
        printf("Circular queue is empty\n");
        return;
    }
    else{
        printf("Traversal: ");
        while(temp->next!=front){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("%d\n",temp->data);
    }
}
int isEmpty(){
    if(front==NULL&&rear==NULL){
        return 1;
    }
    return 0;
}
int main(){
    int choice,x;
    do{
        printf("====Menu====\n");
        printf("0.Exit\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.isEmpty\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0: printf("Exiting...\n"); break;
            case 1:
                printf("Enter element: ");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2: dequeue(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: if(isEmpty()){
                        printf("Queue is empty\n");
                    }else{
                        printf("Queue is not empty\n");
                    } 
                    break;
            default: printf("Invalid choice\n");
        }
    }while(choice!=0);
    struct node *temp,*current;
    temp=front;
    if(temp!=NULL){
        while(temp->next!=front){
            current=temp;
            temp=temp->next;
            free(current);
        }
        free(temp);
    }
    return 0;   
}