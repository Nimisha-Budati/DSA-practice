//Linear Search
#include<stdio.h>
#define N 50
int arr[N];
int linearSearch(int key,int size){
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}
void createArray(int size){
    printf("Enter %d elements: ", size);
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
        index=linearSearch(key,size);
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