//Selection sort
#include<stdio.h>
#define N 10
void selectionSort(int arr[], int n){
    int minIndex;
    for(int i = 0; i < n - 1; i++){
        minIndex = i;
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        if(minIndex != i){
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
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
    selectionSort(arr, size);
    printf("Array after sorting: ");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}