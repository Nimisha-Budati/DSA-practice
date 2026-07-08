//countingSort
#include<stdio.h>
#define N 20
void countingSort(int arr[],int size){
    int count[N]={0};
    int b[N];
    int max=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    for(int i=0;i<size;i++){
        count[arr[i]]++;
    }
    for(int i=1;i<=max;i++){
        count[i]+=count[i-1];
    }
    for(int i=size-1;i>=0;i--){
        b[count[arr[i]]-1]=arr[i];
        count[arr[i]]--;
    }
    for(int i=0;i<size;i++){
        arr[i]=b[i];
    }
}
int main(){
    int arr[N], size;
    printf("Enter size: ");
    scanf("%d", &size);
    printf("Enter %d elements: ", size);
    for(int i=0;i<size;i++){
        scanf("%d", &arr[i]);
    }
    printf("Array before sorting: ");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    countingSort(arr, size);
    printf("Array after sorting: ");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}