//counting vowels, consonants, digits,special characters and spaces
#include<stdio.h>
#include<string.h>
#define N 10
int main(){
    char string[3*N];
    int words=0;
    printf("Enter string: ");
    fgets(string,sizeof(string),stdin);
    int i=0;
    while(string[i]!='\0'){
        if (string[i]!=' '&&(i==0||string[i-1]==' ')){
            words++;
        }
        i++;
    }
    printf("No of words= %d\n",words);
    return 0;
}