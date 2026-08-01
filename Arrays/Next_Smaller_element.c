//finding next smaller element
#include<stdio.h>
#define N 10
int main(){
    int arr[N];
    int size;
    printf("Enter size: ");
    scanf("%d",&size);
    if(size>N){
        printf("Array size excceds\n");
        return 0;
    }
    printf("Enter %d elements of array: ",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int found=0;
    for(int i=0;i<size;i++){
        found=0;
        for(int j=i+1;j<size;j++){
            if(arr[j]<arr[i]){
                printf("%d ",arr[j]);
                found=1;
                break;
            }
        }
        if(!found){
            printf("-1 ");
        }
    }
    printf("\n");
    return 0;
}