//Implementation of Queue using Two Stacks
#include<stdio.h>
#define N 5
int s1[N],s2[N];
int top1=-1,top2=-1;
int count=0;
void enqueue(int x);
void push1(int data);
void push2(int data);
void dequeue();
int pop1();
int pop2();
void display();
void peek();
int isEmpty();
int isFull();
void enqueue(int x){
    if(top1==N-1){
        printf("Queue is full\n");
    }
    else{
        push1(x);
        count++;
        printf("Enqueued %d into queue\n",x);
    }
}
void push1(int data){
    s1[++top1]=data;
}
void push2(int data){
    s2[++top2]=data;
}
int pop1(){
    return s1[top1--];
}
int pop2(){
    return s2[top2--];
}
void dequeue(){
    int item,i;
    if(top1==-1){
        printf("Queue is empty\n");
        return;
    }
    for(i=0;i<count;i++){
        push2(pop1());
    }
    item=pop2();
    count--;
    printf("Dequeued %d from queue\n",item);
    for(i=0;i<count;i++){
        push1(pop2());
    }
}
void peek(){
    if(top1==-1){
        printf("Queue is empty\n");
        return;
    }
    printf("Front element: %d\n",s1[0]);
}
void display(){
    if(top1==-1){
        printf("Queue is empty\n");
        return;
    }
    printf("Traversal: ");
    for(int i=0;i<=top1;i++){
        printf("%d ",s1[i]);
    }
    printf("\n");
}
int isEmpty(){
    return(top1==-1);
}
int isFull(){
    return(top1==N-1);
}
int main(){
    int choice,x;
    do{
        printf("\n==== MENU ====\n");
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
            case 0:
                printf("Exiting...\n");
                break;
            case 1:
                printf("Enter element: ");
                scanf("%d",&x);
                enqueue(x);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                if(isEmpty())
                    printf("Queue is empty\n");
                else
                    printf("Queue is not empty\n");
                break;
            case 6:
                if(isFull())
                    printf("Queue is full\n");
                else
                    printf("Queue is not full\n");
                break;
            default:
                printf("Invalid choice\n");
        }
    }while(choice!=0);
    return 0;
}