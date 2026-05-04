#include<stdio.h>
#define N 10
int arr[N],size,i;
void traversal(){
    if(size==0){
        printf("Array is empty\n");
        return;
    }
    for(i=0;i<size;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void insertion(int num,int pos){
    if(size==N){
        printf("Array is full, cannot insert\n");
        return;
    }
    if(pos<=0||pos>size+1){
        printf("Invalid position %d\n",pos);
        return;
    }
    printf("Insertion:\n");
    printf("Array before insertion: ");
    traversal();
    for(i=size-1;i>=pos-1;i--){
        arr[i+1]=arr[i];
    }
    arr[pos-1]=num;
    size++;
    printf("Array after insertion: ");
    traversal();
}
void deletion(int pos){
    int item;
    if(size==0){
        printf("Array is empty, cannot delete\n");
        return;
    }
    if(pos<=0||pos>size){
        printf("Invalid position %d\n",pos);
        return;
    }
    printf("Deletion:\n");
    printf("Array before deletion: ");
    traversal();
    item=arr[pos-1];
    for(i=pos-1;i<size-1;i++){
        arr[i]=arr[i+1];
    }
    size--;
    printf("Array after deletion: ");
    traversal();
    printf("Deleted element: %d\n",item);
}
int main(){
    int choice,num,pos;
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
    do{
        printf("\nEnter choice:\n");
        printf("1 - Traversal\n2 - Insertion\n3 - Deletion\n0 - Exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Traversal: ");
                traversal();
                break;
            case 2:
                printf("Enter number to insert: ");
                scanf("%d",&num);
                printf("Enter position where to insert: ");
                scanf("%d",&pos);
                insertion(num,pos);
                break;
            case 3:
                printf("Enter position where to delete: ");
                scanf("%d",&pos);
                deletion(pos);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice %d\n",choice);
        }
    }while(choice!=0);
    return 0;
}