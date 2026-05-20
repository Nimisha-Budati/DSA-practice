//Infix to Postfix Conversion using Stack
#include<stdio.h>
#include<ctype.h>
#define N 100
char stack[N];
int top=-1;
void push(char x){
    if(top==N-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=x;
}
char pop(){
    if(top==-1){
        return -1;
    }
    return stack[top--];
}
char peek(){
    if(top==-1){
        return -1;
    }
    return stack[top];
}
int precedence(char ch){
    if(ch=='^')
        return 3;
    else if(ch=='*' || ch=='/' || ch=='%')
        return 2;
    else if(ch=='+' || ch=='-')
        return 1;
    return 0;
}
int main(){
    char infix[100], postfix[100];
    int i=0,j=0;
    printf("Enter infix expression: ");
    scanf("%s",infix);
    while(infix[i]!='\0'){
        if(isalnum(infix[i])){
            postfix[j++]=infix[i];
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }
        else if(infix[i]==')'){
            while(peek()!='('){
                postfix[j++]=pop();
            }
            pop(); 
        }
        else{
            while(top!=-1&&precedence(peek())>=precedence(infix[i])){
                postfix[j++]=pop();
            }
            push(infix[i]);
        }
        i++;
    }
    while(top!=-1){
        postfix[j++]=pop();
    }
    postfix[j]='\0';
    printf("Postfix expression: %s",postfix);
    printf("\n");
    return 0;
}