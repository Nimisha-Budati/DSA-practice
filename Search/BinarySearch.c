//Binary Search
#include<stdio.h>
#define N 50
int arr[N];
int binarySearch(int key,int size){
    int left=0,right=size-1,mid;
    while(left<=right){
        mid=(left+right)/2;
        if(key==arr[mid]){
            return mid;
        }
        else if(key<arr[mid]){
            right=mid-1;
        }
        else{
            left=mid+1;
        }
    }
    return -1;
}
void createArray(int size){
    printf("Enter %d elements in sorted way: ", size);
    for(int i = 0; i < size; i++){
        scanf("%d", &arr[i]);
    }
}
int main(){
    int size,choice,index,key;
    printf("Enter size: ");
    scanf("%d",&size);
    createArray(size);
    do{
        printf("Enter key: ");
        scanf("%d",&key);
        index=binarySearch(key,size);
        if(index!=-1){
            printf("%d found at index %d\n",key,index);
        }
        else{
            printf("%d not found\n",key);
        }
        printf("Enter choice(0-exit, 1-continue): ");
        scanf("%d",&choice);
    }while(choice!=0);
    return 0;
}