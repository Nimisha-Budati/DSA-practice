//Reversing string
//finding length of a string
#include<stdio.h>
#include<string.h>
#define N 10
int main(){
    char string[N],reverse[N];
    printf("Enter string: ");
    scanf("%s",string);
    int j=0;
    for(int i=strlen(string)-1;i>=0;i--){
        reverse[j++]=string[i];
    }
    reverse[j]='\0';
    printf("Reverse of %s is %s\n",string,reverse);
    return 0;
}