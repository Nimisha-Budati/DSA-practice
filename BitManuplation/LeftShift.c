/*
Left Shift << ⭐
Left shift moves bits toward the left.
*/
#include<stdio.h>
int main(){
    int a=5;
    printf("5 << 1: %d\n",a<<1);
    printf("1<<3: %d\n",1<<3);
    printf("Check whether the ith bit set or not(set-1):\n");
    printf("For 5 2nd bit is set or not? ");
    if(a & (1 << 2))
        printf("Set\n");
    else
        printf("Not Set\n");
    printf("Set the ith bit:\n");
    printf("Set bit 1 of 5 as 1: ");
    printf("%d\n",a|(1<<1));
    printf("Clear the ith bit:\n");
    printf("Clear bit 2 of 5: ");
    printf("%d\n",a&~(1<<2));
    printf("Toggle the ith bit:\n");
    printf("Toggle bit 3 of 5: ");
    printf("%d\n",a^(1<<3));
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


/*
Set the i-th bit ⭐⭐⭐
Set means:
0 → 1
Use:
n = n | (1 << i);
or:
n |= (1 << i);
*/

/*
Clear the i-th bit ⭐⭐⭐
Clear means:
1 → 0
Use:
n = n & ~(1 << i);
Example
n = 7
0111
Clear bit 1.
First:
1 << 1 = 0010
NOT:
~0010
Then AND with n.
Conceptually:
0111
AND
1101
----
0101
Result:
5
So:
n = n & ~(1 << i);
*/

/*
Toggle the i-th bit ⭐⭐⭐
Toggle means:
0 → 1
1 → 0
Use XOR:
n = n ^ (1 << i);
Example
n = 5
0101
Toggle bit 1:
1 << 1 = 0010
XOR:
  0101
^ 0010
------
  0111
Result:
7
If we toggle bit 1 again:
0111
^0010
-----
0101
Back to:5
*/


/*
Operation	Formula
Check bit	n & (1 << i)
Set bit	    n | (1 << i)
Clear bit	n & ~(1 << i)
Toggle bit	n ^ (1 << i)
*/