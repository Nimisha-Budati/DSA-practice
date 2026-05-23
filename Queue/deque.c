//Implementation of deque using circular array
#include<stdio.h>
#define N 5
int deque[N];
int f=-1,R=-1;
void enqueuefront(int x){
    if((f==0&&R==N-1)||(f==R+1)){
        printf("Deque is full\n");
        return;
    }
    else if(f==-1&&R==-1){
        f=R=0;
        deque[f]=x;
    }
    else if(f==0){
        f=N-1;
        deque[f]=x;
    }
    else{
        f--;
        deque[f]=x;
    }
    printf("Enqueued %d at front in deque\n",x);
}
void enqueuerear(int x){
    if((f==0&&R==N-1)||(f==R+1)){
        printf("Deque is full\n");
        return;
    }
    else if(f==-1&&R==-1){
        f=R=0;
        deque[R]=x;
    }
    else if(R==N-1){
        R=0;
        deque[R]=x;
    }
    else{
        R++;
        deque[R]=x;
    }
    printf("Enqueued %d at rear in deque\n",x);
}
void dequeuefront(){
    int item;
    if(f==-1&&R==-1){
        printf("Deque is empty\n");
        return;
    }
    else if(f==R){
        item=deque[f];
        f=R=-1;
    }
    else if(f==N-1){
        item=deque[f];
        f=0;
    }
    else{
        item=deque[f];
        f++;
    }
    printf("Dequeued %d from front in deque\n",item);
}
void dequeuerear(){
    int item;
    if(f==-1&&R==-1){
        printf("Deque is empty\n");
        return;
    }
    else if(f==R){
        item=deque[R];
        f=R=-1;
    }
    else if(R==0){
        item=deque[R];
        R=N-1;
    }
    else{
        item=deque[R];
        R--;
    }
    printf("Dequeued %d from rear in deque\n",item);
}
void display(){
    int i=f;
    if(f==-1&&R==-1){
        printf("Deque is empty\n");
        return;
    }
    printf("Traversal: ");
    while(i!=R){
        printf("%d ",deque[i]);
        i=(i+1)%N;
    }
    printf("%d\n",deque[R]);
}
void getfront(){
    if(f==-1&&R==-1){
        printf("Deque is empty\n");
    }
    else{
        printf("Front element: %d\n",deque[f]);
    }
}
void getrear(){
    if(f==-1&&R==-1){
        printf("Deque is empty\n");
    }
    else{
        printf("Rear element: %d\n",deque[R]);
    }
}
int isFull(){
    if((f==0&&R==N-1)||(f==R+1))
        return 1;
    return 0;
}
int isEmpty(){
    if(f==-1&&R==-1)
        return 1;
    return 0;
}
int main(){
    int choice,x;
    do{
        printf("====MENU====\n");
        printf("0.Exit\n");
        printf("1.Insert at front\n");
        printf("2.Insert at rear\n");
        printf("3.Delete from front\n");
        printf("4.Delete from rear\n");
        printf("5.getfront\n");
        printf("6.getrear\n");
        printf("7.isFull\n");
        printf("8.isEmpty\n");
        printf("9.Display\n");
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 0: printf("Exiting....\n"); break;
            case 1:
                printf("Enter element: ");
                scanf("%d",&x);
                enqueuefront(x);
                break;
            case 2:
                printf("Enter element: ");
                scanf("%d",&x);
                enqueuerear(x);
                break;
            case 3:
                dequeuefront();
                break;
            case 4:
                dequeuerear();
                break;
            case 5:
                getfront();
                break;
            case 6:
                getrear();
                break;
            case 7:
                if(isFull()){
                    printf("Deque is full\n");
                }
                else{
                    printf("Deque is not full\n");
                }
                break;
            case 8:
                if(isEmpty()){
                    printf("Deque is empty\n");
                }
                else{
                    printf("Deque is not empty\n");
                }
                break;
            case 9: display();  break;
            default: printf("Invalid choice\n");
        }
    }while(choice!=0);
    return 0;
}