//finding length of a string
#include<stdio.h>
#include<string.h>
#define N 10
int len(char string[]){
    int count=0;
    int i=0;
    while(string[i]!='\0'){
        count++;
        i++;
    }
    return count;
}
int main(){
    char string1[N],string2[5*N];
    printf("Enter string1: ");
    scanf("%s",string1);
    getchar();
    printf("Enter string2: ");
    fgets(string2,sizeof(string2),stdin);
    string2[strcspn(string2,"\n")]='\0';
    printf("Length of string 1 %s using strlen fun: %ld\n",string1,strlen(string1));
    printf("Length of string 1 %s without strlen fun: %d\n",string1,len(string1));
    printf("Length of string 2 %s using strlen fun: %ld\n",string2,strlen(string2));
    printf("Length of string 2 %s without strlen fun: %d\n",string2,len(string2));
    return 0;
}