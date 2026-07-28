//converting string from upper case to lower case
#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define N 10
int main(){
    char string[N];
    printf("Enter string: ");
    scanf("%s",string);
    char str[N];
    strcpy(str,string);
    int i=0;
    while(str[i]!='\0'){
        str[i]=tolower(str[i]);
        i++;
    }
    printf("Converting string %s from upper case to lower case using tolower(): %s\n",string,str);
    i=0;
    while(string[i]!='\0') {
        if(string[i]>='A'&&string[i]<='Z'){
            string[i]=string[i]+32;
        }
        i++;
    }
    printf("Converting string to lower case without using tolower(): %s\n",string);
    return 0;
}