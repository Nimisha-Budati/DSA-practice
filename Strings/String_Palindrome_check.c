//palindrome check
#include<stdio.h>
#include<string.h>
#define N 10
int main(){
    char string[N],reverse[N];
    printf("Enter string: ");
    scanf("%s",string);
    int i=0,j=strlen(string)-1;
    while(i<=j){
        if(string[i]!=string[j]){
            printf("%s is not a palindrome\n",string);
            return 0;
        }
        i++;
        j--;
    }
    printf("%s is a palindrome\n",string);
    return 0;
}