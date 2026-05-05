#include<stdio.h>
int main(){
    int arr[2][3];
    for(int i=0;i<2;i++){
        for(int j=0;i<3;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    printf("2D array Traversal: ");
    for(int i=0;i<2;i++){
        for(int j=0;i<3;j++){
            printf("%d ",arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}