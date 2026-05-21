//Implementation of stack using arrays
#include<stdio.h>
#define N 5
int stack[N];
int top=-1;
void push();
void pop();
void peek();
void display();
int isEmpty();
int isFull();
void push(){
    int x;
    if(isFull()){
        printf("Stack overflow\n");
    }
    else{
        printf("Enter data: ");
        scanf("%d",&x);
        top++;
        stack[top]=x;
        printf("Pushed the element: %d\n",x);
    }
}
void pop(){
    int item;
    if(isEmpty()){
        printf("Stack underflow\n");
    }
    else{
        item=stack[top];
        top--;
        printf("Popped the element: %d\n",item);
    }
}
void peek(){
    if(isEmpty()){
        printf("Stack underflow\n");
    }
    else{
        printf("Top element is: %d\n",stack[top]);
    }
}
void display(){
    if(isEmpty()){
        printf("Stack is empty\n");
        return;
    }
    printf("Traversal: ");
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}
int isEmpty(){
    if(top==-1)
        return 1;
    return 0;
}
int isFull(){
    if(top==N-1)
        return 1;
    return 0;
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
        printf("6.isFull\n");
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
                    } 
                    break;
            case 6: if(isFull()){
                        printf("Stack is full\n");
                    }else{
                        printf("Stack is not full\n");
                    } 
                    break;
            default: printf("Invalid choice\n");
        }
    }while(choice!=0);
    return 0;
}