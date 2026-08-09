//longest substring with atmost k distinct elements
#include<stdio.h>
#include<string.h>
int main(){
    char s[]="eceba";
    int k=2;
    int freq[256]={0};
    int left=0;
    int distinct=0;
    int max=0;
    int start=0;
    for(int right=0;right<strlen(s);right++){
        freq[(unsigned char)s[right]]++;
        if(freq[(unsigned char)s[right]]==1)
            distinct++;
        while(distinct>k){
            freq[(unsigned char)s[left]]--;
            if(freq[(unsigned char)s[left]]==0)
                distinct--;
            left++;
        }
        int len=right-left+1;
        if(len>max){
            max=len;
            start=left;
        }
    }
    printf("Longest substring: ");
    for(int i=start;i<start+max;i++){
        printf("%c",s[i]);
    }
    printf("\nLength: %d",max);
    return 0;
}