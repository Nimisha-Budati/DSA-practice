//Infix to Prefix Conversion using Stack
#include<stdio.h>
#include<string.h>
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
    if(top==-1)
        return -1;
    return stack[top--];
}
char peek(){
    if(top==-1)
        return -1;
    return stack[top];
}
int precedence(char ch){
    if(ch=='^')
        return 3;
    if(ch=='*' || ch=='/' || ch=='%')
        return 2;
    if(ch=='+' || ch=='-')
        return 1;
    return 0;
}
void reverse(char exp[]){
    int i=0;
    int j=strlen(exp)-1;
    char temp;
    while(i<j){
        temp=exp[i];
        exp[i]=exp[j];
        exp[j]=temp;
        i++;
        j--;
    }
}
int main(){
    char infix[100],prefix[100];
    int i,j=0;
    printf("Enter infix expression: ");
    scanf("%s",infix);
    reverse(infix);
    for(i=0;infix[i]!='\0';i++){
        if(infix[i]=='(')
            infix[i]=')';
        else if(infix[i]==')')
            infix[i]='(';
    }
    for(i=0;infix[i]!='\0';i++){
        if(isalnum(infix[i])){
            prefix[j++]=infix[i];
        }
        else if(infix[i]=='('){
            push(infix[i]);
        }
        else if(infix[i]==')'){
            while(peek()!='('){
                prefix[j++]=pop();
            }
            pop();
        }
        else{
            while(top!=-1 && precedence(peek()) > precedence(infix[i]))
            {
                prefix[j++]=pop();
            }
            push(infix[i]);
        }
    }
    while(top!=-1){
        prefix[j++]=pop();
    }
    prefix[j]='\0';
    reverse(prefix);
    printf("Prefix expression: %s\n",prefix);
    return 0;
}