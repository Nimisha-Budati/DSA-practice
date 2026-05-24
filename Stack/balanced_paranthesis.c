//Checking balanced parentheses using stack
#include<stdio.h>
#define N 100
char stack[N];
int top=-1;
void push(char x){
    stack[++top]=x;
}
char pop(){
    return stack[top--];
}
int isEmpty(){
    return top==-1;
}
int main(){
    char exp[N];
    int i=0,flag=1;
    printf("Enter expression: ");
    scanf("%s",exp);
    while(exp[i]!='\0'){
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(exp[i]);
        }
        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty()){
                flag=0;
                break;
            }
            char x=pop();
            if((exp[i]==')' && x!='(') ||
               (exp[i]=='}' && x!='{') ||
               (exp[i]==']' && x!='['))
            {
                flag=0;
                break;
            }
        }
        i++;
    }
    if(!isEmpty())
        flag=0;
    if(flag)
        printf("Balanced\n");
    else
        printf("Not Balanced\n");
    return 0;
}