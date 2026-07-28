//counting vowels, consonants, digits,special characters and spaces
#include<stdio.h>
#include<string.h>
#define N 10
int main(){
    char string[3*N];
    int vowels=0,consonants=0,digits=0,spaces=0,special_chars=0;
    printf("Enter string: ");
    fgets(string,sizeof(string),stdin);
    string[strcspn(string,"\n")]='\0';
    int i=0;
    char cha='\0';
    while(string[i]!='\0'){
        cha=string[i];
        if(cha>='0'&&cha<='9'){
            digits++;
        }
        else if(cha=='A' || cha=='E' || cha=='I' || cha=='O' || cha=='U' || cha=='a' || cha=='e' || cha=='i' || cha=='o' || cha=='u'){
            vowels++;
        }
        else if((cha>='A' && cha<='Z')||(cha>='a' && cha<='z')){
            consonants++;
        }
        else if(cha==' '){
            spaces++;
        }
        else{
            special_chars++;
        }
        i++;
    }
    printf("Vowels= %d\nConsonants= %d\nDigits= %d\nSpaces= %d\nSpecial Characters= %d\n",vowels,consonants,digits,spaces,special_chars);
    return 0;
}