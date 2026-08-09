//Smallest Subarray With Sum ≥ Target
#include<stdio.h>
int main(){
    int arr[]={1,3,5,7,8};
    int n=sizeof(arr)/sizeof(arr[0]);
    int target=10;
    int sum=0,left=0,min=n+1,start=0,len=0;
    for(int right=0;right<n;right++){
        sum=sum+arr[right];
        while(sum>=target){
            len=right-left+1;
            if(len<min){
                min=len;
                start=left;
            }
            sum=sum-arr[left];
            left++;
        }
    }
    if(min==n+1){
        printf("No subarray found\n");
    }
    else{
        printf("Minimum length: %d",min);
        printf("\nSubarray: ");
        for(int i=start;i<start+min;i++){
            printf("%d ",arr[i]);
        }
        printf("\n");
    }
    return 0;
}