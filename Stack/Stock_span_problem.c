//Given the stock prices for N days, find the span for each day.
//What is Span?
//The span is the number of consecutive days (including today) for which the stock price was less than or equal to today's price.
#include<stdio.h>
#define N 100
int stack[N];
int top=-1;
void push(int index) {
    stack[++top]=index;
}
void pop(){
    if(top!=-1)
        top--;
}
int peek(){
    return stack[top];
}
int isEmpty(){
    return top==-1;
}
int main() {
    int price[N],span[N],n;
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter %d stock prices: ",n);
    for(int i=0;i<n;i++)
        scanf("%d",&price[i]);
    span[0]=1;
    push(0);
    for(int i=1;i<n;i++){
        while(!isEmpty() && price[peek()]<=price[i]){
            pop();
        }
        if(isEmpty())
            span[i]=i+1;
        else
            span[i]=i-peek();
        push(i);
    }
    printf("Span: ");
    for(int i=0;i<n;i++)
        printf("%d ",span[i]);
    return 0;
}