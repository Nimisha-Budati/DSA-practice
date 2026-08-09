//Check whether the number is power of 2 or not
#include<stdio.h>
int main(){
    int a=8;
    if(a>0 && (a & (a-1))==0){
        printf("%d is Power of 2\n",a);
    }
    else{
        printf("%d is not a power of 2\n",a);
    }
    int b=7;
    if(b>0 && (b & (b-1))==0){
        printf("%d is Power of 2\n",b);
    }
    else{
        printf("%d is not a power of 2\n",b);
    }
    return 0;
}
/*
Numbers that are powers of 2:
1
2
4
8
16
32
64
...
Their binary representation contains exactly one 1.
1  = 0001
2  = 0010
4  = 0100
8  = 1000
16 = 10000

-------------------
| n & (n - 1) = 0 |
-------------------
*/