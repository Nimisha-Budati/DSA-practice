//Reversing a string using stack
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
int main(){
    char exp[N],i=0;
    printf("Enter exp: ");
    scanf("%s",exp);
    while(exp[i]!='\0'){
        push(exp[i]);
        i++;
    }
    printf("Reversed string: ");
    while(top!=-1){
        printf("%c",pop());
    }
    printf("\n");
    return 0;
}