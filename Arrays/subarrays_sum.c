// sum of each subarray
#include<stdio.h>
#define N 10
int main() {
    int arr[N],n;
    printf("Enter size <= %d: ",N);
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Subarrays:\n");
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            printf("Subarray: ");
            int sum=0;
            for(int k=i;k<=j;k++) {
                printf("%d ",arr[k]);
                sum+=arr[k];
            }
            printf("    Sum = %d",sum);
            printf("\n");
        }
    }
    return 0;
}