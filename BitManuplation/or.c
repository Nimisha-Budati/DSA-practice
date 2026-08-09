/*Use of OR
OR is commonly used to set a bit to 1.*/
#include<stdio.h>
int main(){
    int a=2,b=5;
    printf("2 | 5: %d\n",a|b);
    printf("Set bit 1 of 5 to 1: ");
    printf("%d\n",b|(1<<1));
    return 0;
}