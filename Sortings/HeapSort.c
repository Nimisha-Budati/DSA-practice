//heapsort
#include<stdio.h>
#define N 10
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        int temp=arr[i];
        arr[i]=arr[largest];
        arr[largest]=temp;
        heapify(arr,n,largest);
    }
}
void heapSort(int arr[],int n){
    int i,temp;
    for(i=n/2-1;i>=0;i--){
        heapify(arr,n,i);
    }
    for(i=n-1;i>0;i--){
        temp=arr[0];
        arr[0]=arr[i];
        arr[i]=temp;
        heapify(arr,i,0);
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
    heapSort(arr, size);
    printf("Array after sorting: ");
    for(int i=0;i<size;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}