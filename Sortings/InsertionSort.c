//insertion sort
#include<stdio.h>
#define N 10
void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
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
    insertionSort(arr, size);
    printf("Array after sorting: ");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}