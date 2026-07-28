//Copying string
#include<stdio.h>
#include<string.h>
#define N 10
int main(){
    char string1[N],copy1[N],copy2[N];
    printf("Enter string1: ");
    scanf("%s",string1);
    strcpy(copy1,string1);
    printf("Copy of string %s using strcpy fun: %s\n",string1,copy1);
    int length = strlen(string1);
    for(int i=0;i<length;i++){
        copy2[i]=string1[i];
    }
    copy2[length]='\0';
    printf("Length of string %s without strcpy fun: %s\n",string1,copy2);
    return 0;
}