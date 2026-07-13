//pair sum using two pointers, finding two elements whose sum equals to target
#include<stdio.h>
#define N 10
int main(){
    int arr[N],n,target;
    printf("Enter size <= %d: ",N);
    scanf("%d",&n);
    printf("Enter %d elements in sorted order: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter target: ");
    scanf("%d",&target);
    int left=0;
    int right=n-1;
    while(left<right){
        int sum=arr[left]+arr[right];
        if(sum==target){
            printf("%d + %d = %d\n", arr[left], arr[right], sum);
            return 0;
        }
        else if(sum<target){
            left++;
        }
        else{
            right--;
        }
    }
    printf("No two elements sum to %d\n",target);
    return 0;
}