//maximum sum of 3 consecutive elements
#include<stdio.h>
#define N 10
int main(){
    int arr[N];
    int size;
    printf("Enter size: ");
    scanf("%d",&size);
    if(size < 3){
        printf("At least 3 elements are required.\n");
        return 0;
    }
    printf("Enter %d elements: ",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int max_sum=arr[0]+arr[1]+arr[2];
    int max=max_sum;
    for(int i=0;i<size-3;i++){
        max_sum=max_sum-arr[i]+arr[i+3];
        if(max_sum>max){
            max=max_sum;
        }
    }
    printf("Maximum sum of 3 consecutive elements: %d\n",max);
    return 0;
}