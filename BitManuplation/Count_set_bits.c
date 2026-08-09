//Count noof set bits
#include<stdio.h>
int main(){
    int a=8;
    int count=0;
    while(a>0){
        if(a&1){
            count++;
        }
        a=a>>1;
    }
    printf("Noof set bits in 8: %d\n",count);
    return 0;
}