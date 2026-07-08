//radixSort
#include<stdio.h>
#define N 20
void radixSort(int arr[], int size){
    int count[10];
    int b[N];
    int max=arr[0];
    for(int i=1;i<size;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    int place=1;
    int i;
    while(max/place>0){
        for(i=0;i<10;i++){
            count[i]=0;
        }    
        for(i=0;i<size;i++){
            count[(arr[i]/place)%10]++;
        }
        for(i=1;i<10;i++){
            count[i]+=count[i-1];
        }
        for(i=size-1;i>=0;i--){
            b[count[(arr[i]/place)%10]-1]=arr[i];
            count[(arr[i]/place)%10]--;
        }
        for(i=0;i<size;i++){
            arr[i]=b[i];
        }
        place*=10;
    }
}
int main()
{
    int arr[N], size;
    printf("Enter size: ");
    scanf("%d",&size);
    printf("Enter %d elements: ",size);
    for(int i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    printf("Array before sorting: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    radixSort(arr,size);
    printf("Array after sorting: ");
    for(int i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    return 0;
}