//Reverse Queue using Stack
#include<stdio.h>
#define N 5
int queue[N];
int front=-1,rear=-1;
int stack[N];
int top=-1;
void enqueue(int x){
    if(rear==N-1){
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1)
        front=0;
    queue[++rear]=x;
    printf("Enqueued %d\n",x);
}
int dequeue(){
    if(front==-1 || front>rear){
        return -1;
    }
    int item=queue[front++];
    if(front>rear){
        front=rear=-1;
    }
    return item;
}
void push(int x){
    stack[++top]=x;
}
int pop(){
    return stack[top--];
}
void reverse(){
    if(front==-1){
        printf("Queue is empty\n");
        return;
    }
    while(front!=-1){
        push(dequeue());
    }
    while(top!=-1){
        enqueue(pop());
    }
    printf("Queue reversed successfully\n");
}
void display(){
    if(front==-1){
        printf("Queue is empty\n");
        return;
    }
    printf("Queue: ");
    for(int i=front;i<=rear;i++){
        printf("%d ",queue[i]);
    }
    printf("\n");
}
int main(){
    int choice,x;
    do{
        printf("\n==== MENU ====\n");
        printf("0.Exit\n");
        printf("1.Enqueue\n");
        printf("2.Dequeue\n");
        printf("3.Reverse Queue\n");
        printf("4.Display\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                printf("Enter element: ");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                x=dequeue();
                if(x==-1)
                    printf("Queue is empty\n");
                else
                    printf("Dequeued %d\n",x);
                break;
            case 3:
                reverse();
                break;
            case 4:
                display();
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=0);
    return 0;
}