//max sum using kadanes algorithm
// Maximum subarray sum using Kadane's Algorithm
#include<stdio.h>
#define N 10
int main() {
    int arr[N],n;
    printf("Enter size <= %d: ", N);
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int current_sum=arr[0];
    int max_sum=arr[0];
    for(int i=1;i<n;i++){
        if(current_sum+arr[i]>arr[i]){
            current_sum=current_sum+arr[i];
        }
        else{
            current_sum=arr[i];
        }
        if(current_sum>max_sum){
            max_sum=current_sum;
        }
    }
    printf("Maximum sum = %d\n",max_sum);
    return 0;
}