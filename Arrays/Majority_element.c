//Majority element: element which appears more that n/2 times where n is the size of the array (only for positive elements)
#include<stdio.h>
#define N 20
int main() {
    int arr[N];
    int count[N]={0};
    int size;
    int max=0;
    printf("Enter size: ");
    scanf("%d",&size);
    printf("Enter %d elements: ",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
        if(arr[i]>max){
            max=arr[i];
        }
    }
    for(int i=0;i<size;i++){
        count[arr[i]]++;
    }
    printf("Majority element: ");
    int found=0;
    for(int i=0;i<=max;i++){
        if(count[i] > size/2){
            printf("%d",i);
            found=1;
        }
    }
    if(!found){
        printf("No Majority Element");
    }
    printf("\n");
    return 0;
}