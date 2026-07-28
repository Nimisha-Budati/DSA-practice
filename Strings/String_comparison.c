//String comparison
#include<stdio.h>
#include<string.h>
#define N 10
int main(){
    char string1[N],string2[N];
    printf("Enter string1: ");
    scanf("%s",string1);
    printf("Enter string2: ");
    scanf("%s",string2);
    printf("Comparing %s and %s using strcmp fun: %d\n",string1,string2,strcmp(string1,string2)==0);
    int i=0;
    while(string1[i]!='\0' && string2[i]!='\0'){
        if(string1[i]!=string2[i]){
            printf("Comparing %s and %s without using strcmp fun: %d\n",string1,string2,0);
            return 0;
        }
        i++;
    }
    if (string1[i]=='\0' && string2[i]=='\0')
        printf("Comparing %s and %s without using strcmp fun: %d\n",string1,string2,1);
    else
        printf("Comparing %s and %s without using strcmp fun: %d\n",string1,string2,0);
    return 0;
}