//converting string from lower case to upper case
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
        str[i]=toupper(str[i]);
        i++;
    }
    printf("Converting string %s from lower case to upper case using toupper(): %s\n",string,str);
    i=0;
    while(string[i]!='\0') {
        if(string[i]>='a'&&string[i]<='z'){
            string[i]=string[i]-32;
        }
        i++;
    }
    printf("Converting string to upper case without using toupper(): %s\n",string);
    return 0;
}