//Sum of all elements in a Queue using enqueue and dequeue operations
#include<stdio.h>
#define N 5
int queue[N];
int front=-1,rear=-1;
void enqueue(int x){
    if(rear==N-1){
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1)
        front=0;
    queue[++rear]=x;
}
int dequeue(){
    if(front==-1){
        return -1;
    }
    int item=queue[front];
    if(front==rear)
        front=rear=-1;
    else
        front++;
    return item;
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
void sumQueue(){
    if(front==-1){
        printf("Queue is empty\n");
        return;
    }
    int size=rear-front+1;
    int sum=0;
    for(int i=0;i<size;i++){
        int x=dequeue();
        sum+=x;
        enqueue(x);
    }
    printf("Sum = %d\n",sum);
}
int main(){
    int n,x;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        printf("Enter element: ");
        scanf("%d",&x);
        enqueue(x);
    }
    printf("\nBefore:\n");
    display();
    sumQueue();
    printf("After:\n");
    display();
    return 0;
}