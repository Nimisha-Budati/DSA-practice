//searching an element in matrix
#include<stdio.h>
#define N 10
int main(){
    int rows,cols,a[N][N],i,j,key;
    printf("Enter noof rows: ");
    scanf("%d",&rows);
    printf("Enter noof cols: ");
    scanf("%d",&cols);
    printf("Enter (%d x %d) elements of matrix 1:\n",rows,cols);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter an element to search: ");
    scanf("%d",&key);
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            if(a[i][j]==key){
                printf("Element %d found at %d row, %d column\n",key,i+1,j+1);
                return 0;
            }
        }
    }
    printf("Element %d not found\n",key);
    return 0;
}