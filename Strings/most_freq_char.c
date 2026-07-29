//Finding most frequent character
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
    int max=frequency[(unsigned char)string[0]];
    char max_char=string[0];
    i=1;
    while(string[i]!='\0'){
        if(frequency[(unsigned char)string[i]]>max){
            max=frequency[string[i]];
            max_char=string[i];
        }
        i++;
    }
    printf("Most frequent char: %c\n",max_char);
    return 0;
}