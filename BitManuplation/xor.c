/*XOR- gives 1 when two bits are diffrent
a ^ 0 = a
a ^ a = 0
a ^ b ^ b = a*/
/*XOR and finding a unique element- suppose an array contains duplicae elements except one element we can use xor to find that element*/
#include<stdio.h>
int main(){
    int a=2,b=5;
    printf("2 ^ 5: %d\n",a^b);
    printf("2 ^ 0: %d\n",a^0);
    printf("2 ^ 2: %d\n",a^a);
    printf("2 ^ 5 ^ 5: %d\n",a^b^b);
    int arr[]={1,2,3,1,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans^arr[i];
    }
    printf("Array: ");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Non duplicate element: %d\n",ans);
    return 0;
}