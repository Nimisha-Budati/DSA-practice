//Toggle case
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
        if(str[i]>='A'&&str[i]<='Z'){
            str[i]=tolower(str[i]);
        }
        else if (str[i]>='a' && str[i]<='z') {
            str[i]=toupper(str[i]);
        }
        i++;
    }
    printf("Toggle %s using tolower() and toupper(): %s\n",string,str);
    i=0;
    while(string[i]!='\0') {
        if(string[i]>='A'&&string[i]<='Z'){
            string[i]=string[i]+32;
        }
        else if (string[i]>='a' && string[i]<='z') {
            string[i]=string[i]-32;
        }
        i++;
    }
    printf("Toggle string without using tolower() and toupper(): %s\n",string);
    return 0;
}