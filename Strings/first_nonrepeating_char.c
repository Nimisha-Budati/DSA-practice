//Finding first non repeating chracter
#include<stdio.h>
#include<string.h>
#define N 10
int main(){
    char string[5*N];
    int frequency[256]={0};
    printf("Enter string: ");
    fgets(string,sizeof(string),stdin);
    string[strcspn(string,"\n")]='\0';
    int i=0;
    while(string[i]!='\0'){
        frequency[(unsigned char)string[i]]++;
        i++;
    }
    i=0;
    while(string[i]!='\0'){
        if(frequency[string[i]]==1){
            printf("First non-repeating char: %c",string[i]);
            return 0;
        }
        i++;
    }
    printf("no nonrepeating characters\n");
    return 0;
}