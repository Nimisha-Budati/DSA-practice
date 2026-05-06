//finding sum and maximum of an array using pointers
#include<stdio.h>
#define N 10
void maximum(int arr[],int size){
    if(size==0){
        printf("Array is empty\n");
        return;
    }
    int *p=arr;
    int max=*p;
    for(int i=0;i<size;i++){
        if(*(p+i)>max){
            max=*(p+i);
        }
    }
    printf("Maximum element= %d\n",max);
    return;
}
void sum(int arr[],int size){
    int *p=arr;
    int sum=0;
    for(int i=0;i<size;i++){
        sum+=*(p+i);
    }
    printf("Sum= %d\n",sum);
    return;
}
int main(){
    int arr[N],size,i;
    printf("Enter size of array: ");
    scanf("%d",&size);
    if(size>N||size<0){
        printf("Invalid size! Max allowed is %d\n",N);
        return 0;
    }
    printf("Enter elements of array: ");
    for(i=0;i<size;i++){
        scanf("%d",&arr[i]);
    }
    sum(arr,size);
    maximum(arr,size);
}