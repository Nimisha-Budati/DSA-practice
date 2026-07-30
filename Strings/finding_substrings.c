//finding all substrings of a string
#include<stdio.h>
#include<string.h>
#define N 10
int main(){
    char str[N];
    printf("Enter string: ");
    scanf("%s",str);
    int len=strlen(str);
    int i,j,k;
    printf("substrings of %s:\n",str);
    for(i=0;i<len;i++){
        printf("%c\n",str[i]);
        for(j=i+1;j<len;j++){
            for(k=i;k<=j;k++){
                printf("%c",str[k]);
            }
            printf("\n");
        }
    }
    return 0;
}