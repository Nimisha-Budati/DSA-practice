//Postfix evaluation using stack
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#define N 100
int stack[N],top=-1;
void push(int x){
    if(top==N-1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top]=x;
}
int pop(){
    if(top==-1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}
int main(){
    int a,b,i=0;
    char postfix[N];
    printf("Enter postfix expression: ");
    fgets(postfix,sizeof(postfix),stdin);
    while(postfix[i]!='\0'){
        if(postfix[i]==' ' || postfix[i]=='\n'){
            i++;
            continue;
        }
        if(isdigit(postfix[i])){
            int num=0;
            while(isdigit(postfix[i])){
                num=num*10+(postfix[i]-'0');
                i++;
            }
            push(num);
            continue;
        }
        else{
            b=pop();
            a=pop();
            switch(postfix[i]){
                case '+': push(a+b); break;
                case '-': push(a-b); break;
                case '*': push(a*b); break;
                case '/': push(a/b); break;
                case '%': push(a%b); break;
                case '^': push((int)pow(a,b)); break;
                default:
                    printf("Invalid operator\n");
            }
            i++;
        }
    }
    printf("Result = %d\n",pop());
    return 0;
}