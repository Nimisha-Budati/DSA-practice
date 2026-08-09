/*
Left Shift << ⭐
Left shift moves bits toward the left.
*/
#include<stdio.h>
int main(){
    int a=5;
    printf("5 << 1: %d\n",a<<1);
    return 0;
}
/*
For positive integers:
n << 1 = n × 2
n << 2 = n × 4
n << 3 = n × 8
*/
/*
1 << i
It creates a number where only the i-th bit is 1.
For example:
1 << 0
0001
1 << 1
0010
1 << 2
0100
is used whenever we want to work with the i-th bit.
*/