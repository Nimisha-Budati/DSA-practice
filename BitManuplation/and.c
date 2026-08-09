/*Important use of AND
Check whether a number is odd or even
Even numbers → last bit 0
Odd numbers  → last bit 1
*/
#include<stdio.h>
int main(){
    int a=2,b=5;
    printf("2 & 5: %d\n",a&b);
    printf("check 2 is odd or even: ");
    if(a&1){
        printf("Odd\n");
    }
    else{
        printf("Even\n");
    }
    printf("Check 5 is even or odd: ");
     if(b&1){
        printf("Odd\n");
    }
    else{
        printf("Even\n");
    }
    return 0;
}