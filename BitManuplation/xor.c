/*XOR- gives 1 when two bits are diffrent
a ^ 0 = a
a ^ a = 0
a ^ b ^ b = a*/
#include<stdio.h>
int main(){
    int a=2,b=5;
    printf("2 ^ 5: %d\n",a^b);
    printf("2 ^ 0: %d\n",a^0);
    printf("2 ^ 2: %d\n",a^a);
    printf("2 ^ 5 ^ 5: %d\n",a^b^b);
    return 0;
}