//Prefix evaluation using stack
#include<stdio.h>
#include<math.h>
#include<ctype.h>
#include<string.h>
#define N 100
int stack[N], top=-1;
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
    char prefix[N], temp[N];
    int i,a,b;
    printf("Enter prefix expression: ");
    fgets(prefix,sizeof(prefix),stdin);
    int len=strlen(prefix);
    for(i=0;i<len;i++)
        temp[i]=prefix[len-i-1];
    temp[len]='\0';
    i=0;
    while(temp[i]!='\0'){
        if(temp[i]==' ' || temp[i]=='\n'){
            i++;
            continue;
        }
        if(isdigit(temp[i])){
            int num=0;
            int place=1;
            while(isdigit(temp[i])){
                num=(temp[i]-'0')*place + num;
                place*=10;
                i++;
            }
            push(num);
            continue;
        }
        else{
            a=pop();
            b=pop();
            switch(temp[i]){
                case '+': push(a+b); break;
                case '-': push(a-b); break;
                case '*': push(a*b); break;
                case '/': push(a/b); break;
                case '%': push(a%b); break;
                case '^': push((int)pow(a,b)); break;
                default:
                    printf("Invalid operator\n");
                    return 0;
            }
        }
        i++;
    }
    printf("Result = %d\n",pop());
    return 0;
}