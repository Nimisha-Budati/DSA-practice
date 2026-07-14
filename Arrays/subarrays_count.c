//count noof subarrays
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
    int count_0=0,count_1=0;
    for(int i=0;i<n;i++) {
        for(int j=i;j<n;j++) {
            count_0++;
        }
    }
    count_1=(n*(n+1))/2;
    printf("Noof subarrays using loops: %d\n",count_0);
    printf("Noof subarrays using formula: %d\n",count_1);
    return 0;
}