//Implementation of circular queue using Array
#include<stdio.h>
#define N 5
int queue[N];
int front=-1,rear=-1;
void enqueue(int x){
    if(front==(rear+1)%N){
        printf("Queue Overflow\n");
        return;
    }
    else if(front==-1&&rear==-1){
        front=rear=0;
        queue[rear]=x;
    }
    else{
        rear=(rear+1)%N;
        queue[rear]=x;
    }
    printf("Enqueued %d into circular queue\n",x);
}
void dequeue(){
    if(front==-1&&rear==-1){
        printf("Queue underflow\n");
        return;
    }
    else if(front==rear){
        printf("Dequeued %d from circular queue\n",queue[front]);
        front=rear=-1;
    }
    else{
        printf("Dequeued %d from circular queue\n",queue[front]);
        front=(front+1)%N;
    }
}
void peek(){
    if(front==-1&&rear==-1){
        printf("Circular Queue is empty\n");
        return;
    }
    else{
        printf("Front element= %d\n",queue[front]);
    }
}
void display(){
    int i=front;
    if(front==-1&&rear==-1){
        printf("Circular Queue is empty\n");
        return;
    }
    else{
        printf("Traversal: ");
        while(i!=rear){
            printf("%d ",queue[i]);
            i=(i+1)%N;
        }
        printf("%d\n",queue[rear]);
    }
}
int isEmpty(){
    if(front==-1&&rear==-1){
        return 1;
    }
    return 0;
}
int isFull(){
    if(front==(rear+1)%N)
        return 1;
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
        printf("6.isFull\n");
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
            case 6: if(isFull()){
                        printf("Queue is full\n");
                    }else{
                        printf("Queue is not full\n");
                    } 
                    break;
            default: printf("Invalid choice\n");
        }
    }while(choice!=0);
    return 0;   
}
