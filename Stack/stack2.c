//Implementation of stack using linked list
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};
void push();
void pop();
void peek();
void display();
int isEmpty();
void length();
struct node *top=NULL;
void push(){
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL){
        printf("Memory allocation failed\n");
        return;
    }
    else{
        printf("Enter data: ");
        scanf("%d",&newnode->data);
        newnode->link=NULL;
        if(isEmpty()){
            top=newnode;
        }
        else{
            newnode->link=top;
            top=newnode;
        }

        printf("Pushed the node: %d\n",newnode->data);
    }
}
void pop(){
    int item;
    if(isEmpty()){
        printf("Stack underflow\n");
        return;
    }
    else{
        struct node *temp=top;
        item=top->data;
        top=top->link;
        free(temp);
        printf("Popped the node: %d\n",item);
    }
}
void peek(){
    if(isEmpty()){
        printf("Stack underflow\n");
    }
    else{
        printf("Top element: %d\n",top->data);
    }
}
void display(){
    if(isEmpty()){
        printf("Stack is empty\n");
    }
    else{
        struct node *temp=top;
        printf("Traversal: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->link;
        }
        printf("\n");
    }
}
int isEmpty(){
    if(top==NULL){
        return 1;
    }
    return 0;
}
void length(){
    int length=0;
    struct node *temp=top;
    if(isEmpty()){
        printf("Stack is empty...size = 0\n");
        return;
    }
    while(temp!=NULL){
        length++;
        temp=temp->link;
    }
    printf("Size of stack: %d\n",length);
}
int main(){
    int choice;
    do{
        printf("====Menu====\n");
        printf("0.Exit\n");
        printf("1.Push\n");
        printf("2.Pop\n");
        printf("3.Peek\n");
        printf("4.Display\n");
        printf("5.isEmpty\n");
        printf("6.Length\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0: printf("Exiting...\n"); break;
            case 1: push(); break;
            case 2: pop(); break;
            case 3: peek(); break;
            case 4: display(); break;
            case 5: if(isEmpty()){
                        printf("Stack is empty\n");
                    }else{
                        printf("Stack is not empty\n");
                    } break;
            case 6: length();break;
            default: printf("Invalid choice\n");
        }
    }while(choice!=0);
    struct node *current,*temp;
    temp=top;
    while(temp!=NULL){
        current=temp;
        temp=temp->link;
        free(current);
    }
    return 0;
}