//Rotate right by one position
#include<stdio.h>
#define N 10
int main(){
    int n;
    int arr[N];
    printf("Enter size: ");
    scanf("%d",&n);
    printf("Enter elements:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    int temp=arr[n-1];
    for(int i=n-1;i>0;i--){
        arr[i]=arr[i-1];
    }
    arr[0]=temp;
    printf("Array after rotation:\n");
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}