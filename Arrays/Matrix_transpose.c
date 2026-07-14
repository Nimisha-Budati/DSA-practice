//Matrix transpose
#include<stdio.h>
#define N 10
int main(){
    int rows,cols,a[N][N],i,j,transpose[N][N];
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
    for(i=0;i<rows;i++){
        for(j=0;j<cols;j++){
            transpose[j][i]=a[i][j];
        }
    }
    printf("Transpose matrix:\n");
    for(i=0;i<cols;i++){
        for(j=0;j<rows;j++){
            printf("%d ",transpose[i][j]);
        }
        printf("\n");
    }
    return 0;
}