//Removing duplicate characters
#include<stdio.h>
#include<string.h>
#define N 10
int main(){
    char string[5*N],final_str[5*N];
    printf("Enter string: ");
    fgets(string,sizeof(string),stdin);
    string[strcspn(string,"\n")]='\0';
    int i=0;
    int flag[256]={0};
    i=0;
    int j=0;
    while(string[i]!='\0'){
        if(flag[(unsigned char)string[i]]==0){
            final_str[j++]=string[i];
            flag[(unsigned char)string[i]]=1;
        }
        i++;
    }
    final_str[j]='\0';
    printf("String after removing duplicates: %s\n", final_str);
    return 0;
}