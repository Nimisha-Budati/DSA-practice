#include<stdio.h>
#include<stdlib.h>
#define N 10
int main(){
    int arr[N],size,i;
    int *p=arr;
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
    //prints base address of array
    printf("Array base address using p: %p\n",p);
    printf("Array base address using arr: %p\n",arr);
    printf("Array base address using &arr: %p\n",&arr);
    //printing array elements
    printf("Array element using *(p+i): ");
    for(i=0;i<size;i++){
        printf("%d ",*(p+i));
    }
    printf("\n");
    printf("Array element using *(arr+i): ");
    for(i=0;i<size;i++){
        printf("%d ",*(arr+i));
    }
    printf("\n");
    printf("Array element using arr[i]: ");
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
    printf("Array element using i[arr]: ");
    for(i=0;i<size;i++){
        printf("%d ",i[arr]);
    }
    printf("\n");
    printf("Array element using i[p]: ");
    for(i=0;i<size;i++){
        printf("%d ",i[p]);
    }
    printf("\n");
    return 0;
}