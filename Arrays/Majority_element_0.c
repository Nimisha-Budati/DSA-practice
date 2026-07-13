// Majority element: element that appears more than n/2 times, where n is the size of the array (supports negative elements)
#include<stdio.h>
#define N 20
int main() {
    int arr[N];
    int size;
    printf("Enter size: ");
    scanf("%d",&size);
    printf("Enter %d elements: ",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    int max=arr[0],min=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]<min){
            min=arr[i];
        }
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int range=max-min+1;
    int count[range];
    for(int i=0;i<range;i++){
        count[i]=0;
    }
    for(int i=0;i<size;i++){
        count[arr[i]-min]++;
    }
    printf("Majority element: ");
    int found=0;
    for(int i=0;i<range;i++){
        if(count[i] > size/2){
            printf("%d",i+min);
            found=1;
        }
    }
    if(!found){
        printf("No Majority Element");
    }
    printf("\n");
    return 0;
}