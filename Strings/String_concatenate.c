//string concatenate
#include<stdio.h>
#include<string.h>
#define N 10
int main(){
    char string1[N],string2[N],concatenate1[2*N],concatenate2[2*N];
    printf("Enter string1: ");
    scanf("%s",string1);
    printf("Enter string2: ");
    scanf("%s",string2);
    strcpy(concatenate1,string1);
    strcat(concatenate1,string2);
    int i=0;
    while(string1[i]!='\0'){
        concatenate2[i]=string1[i];
        i++;
    }
    int j=0;
    while(string2[j]!='\0'){
        concatenate2[i]=string2[j];
        i++;
        j++;
    }
    concatenate2[i] = '\0';
    printf("Concatenating %s and %s using strcat fun: %s\n",string1,string2,concatenate1);
    printf("Concatenating %s and %s without using strcat fun: %s\n",string1,string2,concatenate2);
    return 0;
}