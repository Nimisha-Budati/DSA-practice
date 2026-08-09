//find max substring without repeating characters
#include<stdio.h>
#include<string.h>
int main(){
    char s[]="abcdabc";
    int seen[256]={0};
    int left=0,max=0,len=0,start=0;
    for(int right=0;right<strlen(s);right++){
        while(seen[(unsigned char)s[right]]==1){
            seen[(unsigned char)s[left]]=0;
            left++;
        }
        seen[(unsigned char)s[right]]=1;
        len=right-left+1;
        if(len>max){
            max=len;
            start=left;
        }
    }
    printf("Max substring without repeating chars: ");
    for(int i=start;i<start+max;i++){
        printf("%c",s[i]);
    }
    printf(" with length %d\n",max);
    return 0;
}