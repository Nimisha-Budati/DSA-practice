//Anagram check(means thwo strings have same characters with equal frequencies but oredr may vary)
#include<stdio.h>
#include<string.h>
#define N 10
int main(){
    char string1[5*N],string2[5*N];
    int freq1[256]={0},freq2[256]={0};
    printf("Enter string1: ");
    fgets(string1,sizeof(string1),stdin);
    string1[strcspn(string1,"\n")]='\0';
    printf("Enter string2: ");
    fgets(string2,sizeof(string2),stdin);
    string2[strcspn(string2,"\n")]='\0';
    if (strlen(string1)!=strlen(string2)) {
        printf("%s and %s are not anagrams\n",string1,string2);
        return 0;
    }
    int i=0;
    while(string1[i]!='\0'){
        freq1[(unsigned char)string1[i]]++;
        i++;
    }
    i=0;
    while(string2[i]!='\0'){
        freq2[(unsigned char)string2[i]]++;
        i++;
    }
    for(int i=0;i<256;i++){
        if(freq1[i]!=freq2[i]){
            printf("%s and %s are not anagrams\n",string1,string2);
            return 0;
        }
    }
    printf("%s and %s are anagrams\n",string1,string2);
    return 0;
}