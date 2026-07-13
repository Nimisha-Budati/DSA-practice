/*prefix sum 
Ex: arr=[1,2,3] prefix=[1,3,6]*/
#include<stdio.h>
#define N 10
int main(){
    int arr[N],n;
    printf("Enter size <= %d: ",N);
    scanf("%d",&n);
    printf("Enter %d elements: ",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int prefix[n];
    for(int i=0;i<n;i++){
        prefix[i]=0;
        for(int j=i;j>=0;j--)
            prefix[i]+=arr[j];
    }
    printf("Prefix sum: ");
    for(int i=0;i<n;i++){
        printf("%d ",prefix[i]);
    }
    printf("\n");
    return 0;
}