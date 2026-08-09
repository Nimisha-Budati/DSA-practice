//remove the lowest set bit
#include<stdio.h>
int main(){
    int a=12;
    printf("12 in binary form 1100.\n");
    printf("So 12 after removing lowest significant bit is 11 i.e, 1000.\n");
    printf("12 -> %d\n",a&(a-1));
    return 0;
}