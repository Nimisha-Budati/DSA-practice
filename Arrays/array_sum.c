//Find missing number in an array
#include<stdio.h>
int main(){
    int n,sum=0,total,missing;
    printf("Enter value of N: ");
    scanf("%d",&n);
    int arr[n-1];
    printf("Enter %d elements:\n",n-1);
    for(int i=0;i<n-1;i++){
        scanf("%d",&arr[i]);
        sum += arr[i];
    }
    total = n*(n+1)/2;
    missing = total - sum;
    printf("Missing number = %d\n",missing);
    return 0;
}