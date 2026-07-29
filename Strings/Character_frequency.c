//Character frequency
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
    for(int i=0;i<256;i++){
        if(frequency[i]>0 && i!='\0'){
            printf("%c : %d\n",i,frequency[i]);
        }
    }
    return 0;
}